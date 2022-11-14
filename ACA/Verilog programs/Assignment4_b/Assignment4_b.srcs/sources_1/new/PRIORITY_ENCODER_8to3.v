`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 18.10.2022 14:45:06
// Design Name: 
// Module Name: PRIORITY_ENCODER_8to3
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


module PRIORITY_ENCODER_8to3(
    input [7:0]y,
    output [2:0]a, valid);

assign a[2] = y[7] | y[6] | y[5] | y[4];
assign a[1] = y[7] | y[6] | y[3] | y[2];
assign a[0] = y[7] | y[5] | y[3] | y[1];
assign valid = y[0] | y[1] | y[2] | y[3] | y[4] | y[5] | y[6] | y[7];

endmodule
