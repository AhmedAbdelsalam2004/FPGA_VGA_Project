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

  integer file;
  
  initial begin
    file = $fopen("frame.ppm", "w");
    // Write the PPM header: format P3, 640x480 resolution, 255 max color value
    $fwrite(file, "P3\n640 480\n255\n");
  end

  always @(posedge clk) begin
    // Probe the internal video_on signal using your specific instance name 'vga'
    if (vga.video_on) begin
        // rgb is available locally in the testbench
        $fwrite(file, "%d %d %d\n", rgb[2]*255, rgb[1]*255, rgb[0]*255);
    end
  end

endmodule