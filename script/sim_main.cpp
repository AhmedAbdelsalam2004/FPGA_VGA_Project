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
        // 1. Handle Keyboard Inputs
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = true;
        }
        
        const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
        top->btn_up = currentKeyStates[SDL_SCANCODE_UP];
        top->btn_down = currentKeyStates[SDL_SCANCODE_DOWN];

        // 2. Tick the Hardware Clock
        top->clk = !top->clk;
        top->eval();

        // 3. Capture Pixels on the Positive Edge
        if (top->clk) {
            // Only draw if we are in the visible screen area
            if (top->video_on) {
                // Map the 3-bit RGB from Verilog to a 32-bit ARGB color for the PC monitor
                uint32_t color = 0xFF000000; // Alpha channel max
                if (top->rgb & 0b100) color |= 0x00FF0000; // Red
                if (top->rgb & 0b010) color |= 0x0000FF00; // Green
                if (top->rgb & 0b001) color |= 0x000000FF; // Blue

                // Safety check to prevent buffer overflow
                if (top->pixel_x < WIDTH && top->pixel_y < HEIGHT) {
                    pixels[top->pixel_y * WIDTH + top->pixel_x] = color;
                }
            }

            // 4. Update the screen exactly when the frame finishes (VSYNC falling edge)
            // When pixel_x is 0 and pixel_y is 480, the visible frame is done
            if (top->pixel_x == 0 && top->pixel_y == 480) {
                SDL_UpdateTexture(texture, NULL, pixels, WIDTH * sizeof(uint32_t));
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, texture, NULL, NULL);
                SDL_RenderPresent(renderer);
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