#include <SDL2/SDL.h>
#include <iostream>
#include "Vvga_top.h"     // The Verilated hardware header
#include "verilated.h"

// Standard VGA resolution
const int WIDTH = 640;
const int HEIGHT = 480;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    
    // Instantiate the Verilog top module
    Vvga_top* top = new Vvga_top;

    // Initialize SDL2 Video
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("FPGA Hardware Pong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

    // Pixel buffer to hold the screen data
    uint32_t* pixels = new uint32_t[WIDTH * HEIGHT];

    // Hardware Reset Sequence
    top->rst = 1;
    top->clk = 0;
    top->eval();
    top->rst = 0;

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // 1. Tick the Hardware Clock
        top->clk = !top->clk;
        top->eval();

        // 2. Capture Pixels on the Positive Edge
        if (top->clk) {
            if (top->video_on) {
                uint32_t color = 0xFF000000; 
                if (top->rgb & 0b100) color |= 0x00FF0000; 
                if (top->rgb & 0b010) color |= 0x0000FF00; 
                if (top->rgb & 0b001) color |= 0x000000FF; 

                if (top->pixel_x < WIDTH && top->pixel_y < HEIGHT) {
                    pixels[top->pixel_y * WIDTH + top->pixel_x] = color;
                }
            }

            // 3. Exactly once per frame (60 Hz)
            if (top->pixel_x == 0 && top->pixel_y == 480) {
                // Render the screen
                SDL_UpdateTexture(texture, NULL, pixels, WIDTH * sizeof(uint32_t));
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, texture, NULL, NULL);
                SDL_RenderPresent(renderer);

                // POLL EVENTS HERE: Only 60 times a second!
                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) quit = true;
                }
                const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
                top->btn_up = currentKeyStates[SDL_SCANCODE_UP];
                top->btn_down = currentKeyStates[SDL_SCANCODE_DOWN];
            }
        }
    }

    // Cleanup
    delete[] pixels;
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    delete top;

    return 0;
}