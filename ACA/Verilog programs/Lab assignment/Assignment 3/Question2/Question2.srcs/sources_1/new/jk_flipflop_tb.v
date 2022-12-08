`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.11.2022 08:21:23
// Design Name: 
// Module Name: jk_flipflop_tb
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


module jk_FF_tb();
    reg j, k, clk, reset;
    wire q, qb;
    
    jk_FF jkff(j, k, reset, clk, q, qb);
    
    initial 
    begin   
    
        clk = 1'b0;
        forever #10 clk = ~clk;
        
    end
    
    initial 
    begin
    
        j = 1'b1; k = 1'b0; reset = 1'b1;
        #10 reset = 1'b0;
        #10 j = 1'b0; k = 1'b0;
        #10 j = 1'b0; k = 1'b1;
        #10 j = 1'b1; k = 1'b1; 
        
    end    
endmodule
