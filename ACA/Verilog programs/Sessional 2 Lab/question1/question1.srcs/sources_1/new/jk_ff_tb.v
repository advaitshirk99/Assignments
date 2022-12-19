`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 15.12.2022 15:13:36
// Design Name: 
// Module Name: jk_ff_tb
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


module jk_ff_tb();
    reg J, K, CLK, RESET;
    wire Q, Qb;
   
    jk_ff jkff1(J, K, CLK, RESET, Q, Qb);
    initial 
    begin   
        CLK = 1'b0;
        forever #10 CLK = ~CLK;
    end
    initial 
    begin
        J = 1'b1; K = 1'b0; RESET = 1'b1;
        #10 RESET = 1'b0;
        #10 J = 1'b0; K = 1'b0;
        #10 J = 1'b0; K = 1'b1;
        #10 J = 1'b1; K = 1'b0;
        #10 J = 1'b1; K = 1'b1; 
    end    
endmodule
    
