`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.11.2022 13:20:11
// Design Name: 
// Module Name: seq_detector_mealy_tb
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


module seq_detector_mealy_tb();
    reg clk, reset, x;
    wire z;
    sequence_detector_mealy sdm(clk, reset, x, z);
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
