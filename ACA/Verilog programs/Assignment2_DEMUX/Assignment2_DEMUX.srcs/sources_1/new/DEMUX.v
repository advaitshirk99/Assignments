`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.10.2022 12:08:56
// Design Name: 
// Module Name: DEMUX
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


module demux_1to2(
    input a, s0,
    output y0, y1);

assign y0 = (~(s0) & a);
assign y1 = (s0 & a);

endmodule

module demux_2to4(
    input a, s0, s1,
    output y0, y1, y2, y3);

assign y0 = (~s1)&(~s0)&a;
assign y1 = (~s1)&(s0)&a;
assign y2 = (s1)&(~s0)&a;
assign y3 = (s1)&(s0)&a;

endmodule
    