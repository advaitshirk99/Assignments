`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 14.12.2022 19:26:21
// Design Name: 
// Module Name: testbench
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


module testbench();
 reg clk, reset, x;
    wire z;
    
    seqdetector_10110_mealy sdml1(clk, reset, x, z);
    
    initial
    begin
        clk = 1'b1;
        forever #5 clk = ~clk;
    end
    
    initial
    begin
        reset = 1'b1;
        #10 reset = 1'b0;
        x = 1'b0;
        #10 x = 1'b1; #10 x = 1'b0; #10 x = 1'b1; #10 x = 1'b1; #10 x = 1'b0;
        #10 x = 1'b1; #10 x = 1'b1; #10 x = 1'b0; #10 x = 1'b0; #10 x = 1'b1;
        #10 x = 1'b1; #10 x = 1'b0; #10 x = 1'b1; #10 x = 1'b1; #10 x = 1'b1;
        #10 x = 1'b0; #10 x = 1'b1; #10 x = 1'b1; #10 x = 1'b0; #10 x = 1'b1;
    end
endmodule
