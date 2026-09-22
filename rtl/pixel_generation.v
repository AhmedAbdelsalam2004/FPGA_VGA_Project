module pixel_generation (
    input wire clk,
    input wire rst,
    input wire video_on,
    input wire [9:0] pixel_x,
    input wire [9:0] pixel_y,
    output reg [2:0] rgb
);

reg [9:0] pos_x;
reg [9:0] pos_y;

reg y_dir;
reg x_dir;
parameter BOX_SIZE = 32;

wire frame_tick;

assign frame_tick = (pixel_x == 0 && pixel_y == 480);

always @(posedge clk) begin
    if (rst) begin
        pos_x <= 320;
        pos_y <= 240;
        y_dir <= 0;
        x_dir <= 0;
    end

    else begin
        if(frame_tick == 1) begin
            if(pos_x + BOX_SIZE == 639) begin
                x_dir <= 0;
            end
            else if(pos_x == 0) begin
                x_dir <= 1;
            end
            if(pos_y + BOX_SIZE == 479) begin
                y_dir <= 0;
            end
            else if(pos_y == 0) begin
                y_dir <= 1;
            end

            pos_x <= (x_dir) ? pos_x + 1 : pos_x - 1;
            pos_y <= (y_dir) ? pos_y + 1 : pos_y - 1;
        end
    end
end

always @(*) begin
    if(~video_on) begin
        rgb = 3'b000;
    end
    else begin
        if(pixel_x >= pos_x && pixel_x < pos_x + BOX_SIZE && pixel_y >= pos_y && pixel_y < pos_y + BOX_SIZE) begin
            
            rgb = 3'b010;
            
        end
        else begin
            rgb = 3'b001;
        end
    end
end
    
endmodule