`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 18.10.2022 13:43:14
// Design Name: 
// Module Name: DECODER_3to8
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


module DECODER_3to8(
    input a,
    input b,
    input c,
    output d0,
    output d1,
    output d2,
    output d3,
    output d4,
    output d5,
    output d6,
    output d7);
    
assign d0= (~a)&(~b)&(~c);
assign d1= (~a)&(~b)&(c);
assign d2= (~a)&(b)&(~c);
assign d3= (~a)&(~b)&(~c);
assign d4= (a)&(~b)&(~c);
assign d5= (a)&(~b)&(c);
assign d6= (a)&(b)&(~c);
assign d7= (a)&(b)&(c);

endmodule
