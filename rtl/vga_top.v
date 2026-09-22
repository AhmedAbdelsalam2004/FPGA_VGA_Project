module vga_top (
    input wire clk,
    input wire rst,
    output wire hsync,
    output wire vsync,
    output wire [2:0] rgb
);

wire video_on;
wire [9:0] pixel_x;
wire [9:0] pixel_y;

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
      .pixel_x(pixel_x), 
      .pixel_y(pixel_y),
      .rgb(rgb)
  );
    
endmodule