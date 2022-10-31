`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 18.10.2022 14:13:35
// Design Name: 
// Module Name: PRIORITY_ENCODER_4to2
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


module PRIORITY_ENCODER_4to2(
    input [3:0]y,
    output [1:0]a, valid);
    
assign a[1] = y[3] + y[2];
assign a[0] = y[3] + ((~y[2])&y[1]);
assign valid = y[3] | y[2] | y[1] | y[0];

endmodule
