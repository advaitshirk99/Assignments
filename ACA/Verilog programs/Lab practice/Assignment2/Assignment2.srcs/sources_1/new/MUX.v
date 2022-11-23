`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.10.2022 11:21:15
// Design Name: 
// Module Name: MUX
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

module dataflow_MUX(
    input x, y, s0,
    output f);

assign f = (((~s0)&x)| (s0)&y);
endmodule

module gateflow_MUX(
    input x, y, s0, 
    output f);
wire w1, w2, w3;

not(w1, s0);
and(w2, w1, x);
and(w3, s0, y);
or(f, w2, w3); 
endmodule