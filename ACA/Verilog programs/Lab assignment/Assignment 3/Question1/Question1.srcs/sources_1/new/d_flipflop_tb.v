`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 24.11.2022 18:26:27
// Design Name: 
// Module Name: d_flipflop_tb
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


module d_FF_tb();
    reg d, clk, reset;
    wire q, qb;
    
    d_FF dff1(d, clk, reset, q, qb);
    initial
    begin
    
        clk = 0;
        forever #10 clk = ~clk;
        
    end
    
    initial 
    begin
    
        reset = 1'b0; d = 1'b1; 
        #10 reset = 1'b1;  
        #50 reset = 1'b0; 
        #10 d = 1'b0;
        #10 d = 1'b1; 
        
    end
endmodule
