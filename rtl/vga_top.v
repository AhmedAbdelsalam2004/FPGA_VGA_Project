module vga_top (
    input wire clk,
    input wire rst,
    input wire btn_up,
    input wire btn_down,
    output wire hsync,
    output wire vsync,
    output wire [2:0] rgb
);

output wire video_on;
output wire [9:0] pixel_x;
output wire [9:0] pixel_y;

vga_sync vga(
      .clk(clk), 
      .rst(rst), 
      .hsync(hsync), 
      .vsync(vsync), 
      .video_on(video_on), 
      .pixel_x(pixel_x), 
      .pixel_y(pixel_y)
);

pixel_generation pixel(
      .clk(clk), 
      .rst(rst), 
      .video_on(video_on),
      .btn_up(btn_up),
      .btn_down(btn_down), 
      .pixel_x(pixel_x), 
      .pixel_y(pixel_y),
      .rgb(rgb)
  );
    
endmodule