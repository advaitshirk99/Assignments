`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 23.11.2022 10:54:37
// Design Name: 
// Module Name: FA_1bit
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


module FA_1bit(
    input x,
    input y,
    input cin,
    output cout,
    output sum);

assign {cout, sum} = x + y + cin;
endmodule

module FA_4bit(
    input [3:0]x,
    input [3:0]y,
    input cin,
    output [3:0]cout,
    output [3:0]sum);

    FA_1bit fa1 (x[0], y[0], cin, cout[0], sum[0]);
    FA_1bit fa2 (x[1], y[1], cin, cout[1], sum[1]);
    FA_1bit fa3 (x[2], y[2], cin, cout[2], sum[2]);
    FA_1bit fa4 (x[3], y[3], cin, cout[3], sum[3]);
    
endmodule