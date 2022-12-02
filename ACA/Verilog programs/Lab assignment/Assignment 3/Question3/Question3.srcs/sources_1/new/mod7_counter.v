`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.11.2022 11:45:04
// Design Name: 
// Module Name: mod7_counter
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module MOD7_counter(
    input clk, reset,
    output reg [2:0]f);
    
    always @ (posedge clk or reset)
    begin
    
        if(!reset)
        begin
            if (f == 3'd0)
                f <= 3'd1;
            else if (f == 3'd1)
                f <= 3'd2;
            else if (f == 3'd2)
                f <= 3'd3;
            else if (f == 3'd3)
                f <= 3'd4;
            else if (f == 3'd4)
                f <= 3'd5;
            else if (f == 3'd5)
                f <= 3'd6;
            else if (f == 3'd6)
                f <= 3'd7;
            else if (f == 3'd7)
                f <= 3'd0;          
        end
        else
            f <= 3'd0;
            
    end
endmodule
