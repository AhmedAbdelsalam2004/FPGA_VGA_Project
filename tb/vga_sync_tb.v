`timescale 1ns / 1ps

module vga_sync_tb;

  reg clk;
  reg rst;
  wire hsync;
  wire vsync;
  //wire video_on;
  //wire [9:0] pixel_x;
  //wire [9:0] pixel_y;
  wire [2:0] rgb;

  initial begin
    clk = 0;
    rst = 1;
    #100;
    rst = 0;
  end

  always #20 clk = ~clk;
  
  // vga_sync vga(
  //     .clk(clk), 
  //     .rst(rst), 
  //     .hsync(hsync), 
  //     .vsync(vsync), 
  //     .video_on(video_on), 
  //     .pixel_x(pixel_x), 
  //     .pixel_y(pixel_y)
  // );

   vga_top vga(
      .clk(clk), 
      .rst(rst), 
      .hsync(hsync), 
      .vsync(vsync), 
      .rgb(rgb)
  );

endmodule