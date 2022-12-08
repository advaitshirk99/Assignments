`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 24.11.2022 18:15:14
// Design Name: 
// Module Name: d_flipflop
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


module d_FF(
    input d, clk, reset,
    output reg q, reg qb);
    
    always @ (posedge clk or reset)
    begin
    
        if(!reset)
          assign q = d;
        else
          assign q = 1'b0;
        assign qb = ~q;  
             
    end
endmodule
