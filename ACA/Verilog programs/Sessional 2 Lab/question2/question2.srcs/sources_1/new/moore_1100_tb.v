`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 15.12.2022 16:23:28
// Design Name: 
// Module Name: moore_1100_tb
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


module moore_1100_tb();
    reg CLK, RESET, D;
    wire OUT;
    
    moore_1100detector m1100(CLK, RESET, D, OUT);
    initial
    begin
        CLK = 1'b1;
        forever #5 CLK = ~CLK;
    end
    initial
    begin
        RESET = 1'b1;
        #10 RESET = 1'b0;
        D = 1'b0;
        #10 D = 1'b1; #10 D = 1'b1; #10 D = 1'b0; #10 D = 1'b0; #10 D = 1'b0;
        #10 D = 1'b1; #10 D = 1'b1; #10 D = 1'b0; #10 D = 1'b0; #10 D = 1'b1;
        #10 D = 1'b1; #10 D = 1'b0; #10 D = 1'b1; #10 D = 1'b1; #10 D = 1'b1;
        #10 D = 1'b0; #10 D = 1'b0; #10 D = 1'b1; #10 D = 1'b0; #10 D = 1'b1;
    end
endmodule
