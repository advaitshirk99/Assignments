`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.11.2022 11:57:27
// Design Name: 
// Module Name: mod7_counter_tb
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


module MOD7_counter_tb();
    reg clk, reset;
    wire [2:0]f;
    
    MOD7_counter m1 (clk, reset, f);
    initial 
    begin
    
        clk = 0;
        forever #10 clk = ~clk;
        
    end
    
    initial
    begin
    
        reset = 1'b0;
        #30 reset = 1'b1;
        #40 reset = 1'b0;
        #10 reset = 1'b1;
        #5 reset = 1'b0;
        
    end
endmodule
