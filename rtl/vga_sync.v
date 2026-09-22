module vga_sync (
    input wire clk,
    input wire rst,
    output wire hsync,
    output wire vsync,
    output wire video_on,
    output reg [9:0] pixel_x,
    output reg [9:0] pixel_y
);

    always @(posedge clk) begin

        if(rst) begin
            pixel_x <= 0;
            pixel_y <= 0;
        end

        else begin

            if (pixel_x == 799) begin
                pixel_x <= 0;
                if (pixel_y == 524) begin
                    pixel_y <= 0;
                end
                else begin
                    pixel_y <= pixel_y + 1;    
                end  
            end

            else begin
                pixel_x <= pixel_x + 1;
            end

            
        end
    end

    assign video_on = (pixel_x < 640) && (pixel_y < 480);
    assign hsync = ~((pixel_x >= 656) && (pixel_x <= 751));
    assign vsync = ~((pixel_y >= 490) && (pixel_y <= 491));

endmodule
