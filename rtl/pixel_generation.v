module pixel_generation (
    input wire clk,
    input wire rst,
    input wire video_on,
    input wire btn_up,
    input wire btn_down,
    input wire [9:0] pixel_x,
    input wire [9:0] pixel_y,
    output reg [2:0] rgb
);

reg [9:0] pos_x;
reg [9:0] pos_y;

reg y_dir;
reg x_dir;
parameter BOX_SIZE = 32;

reg [9:0] paddle_y;
parameter PADDLE_X = 600;
parameter PADDLE_W = 8;
parameter PADDLE_H = 64;

wire frame_tick;

assign frame_tick = (pixel_x == 0 && pixel_y == 480);

always @(posedge clk) begin
    if (rst) begin
        pos_x <= 320;
        pos_y <= 240;
        y_dir <= 0;
        x_dir <= 0;
        paddle_y <= 200;
    end

    else begin
        if(frame_tick == 1) begin
            if(pos_x + BOX_SIZE == PADDLE_X && pos_y + BOX_SIZE >= paddle_y && pos_y <= paddle_y + PADDLE_H) begin
                x_dir <= 0;
            end
            else if(pos_x == 0) begin
                x_dir <= 1;
            end
            else if(pos_x + BOX_SIZE == 639) begin
                // pos_x <= 320;
                // pos_y <= 240;
                x_dir <= 0; // Temporary
            end
            if(pos_y + BOX_SIZE == 479) begin
                y_dir <= 0;
            end
            else if(pos_y == 0) begin
                y_dir <= 1;
            end

            pos_x <= (x_dir) ? pos_x + 1 : pos_x - 1;
            pos_y <= (y_dir) ? pos_y + 1 : pos_y - 1;

            if (btn_up && paddle_y > 0) begin
                paddle_y <= paddle_y - 1;
            end
            if (btn_down && paddle_y < (479 - PADDLE_H)) begin
                paddle_y <= paddle_y + 1;
            end
        end
    end
end

always @(*) begin
    if(~video_on) begin
        rgb = 3'b000;
    end
    else begin
        if (pixel_x >= PADDLE_X && pixel_x <= PADDLE_X + PADDLE_W && pixel_y >= paddle_y && pixel_y < paddle_y + PADDLE_H) begin
            rgb = 3'b111;
        end

        else if(pixel_x >= pos_x && pixel_x < pos_x + BOX_SIZE && pixel_y >= pos_y && pixel_y < pos_y + BOX_SIZE) begin
            
            rgb = 3'b010;
            
        end
        else begin
            rgb = 3'b001;
        end
    end
end
    
endmodule
