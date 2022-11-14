`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 18.10.2022 13:47:34
// Design Name: 
// Module Name: DECODER_3to8_tb
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


module DECODER_3to8_tb();
    reg a,b,c;
    wire d0, d1, d2, d3, d4, d5, d6, d7;
    
DECODER_3to8 decoder(a, b, c, d0, d1, d2, d3, d4, d5, d6, d7);
initial
begin

a=1'b0; b=1'b0; c=1'b0;
#20 a=1'b0; b=1'b0; c=1'b1;
#20 a=1'b0; b=1'b1; c=1'b0;
#20 a=1'b0; b=1'b1; c=1'b1;
#20 a=1'b1; b=1'b0; c=1'b0;
#20 a=1'b1; b=1'b0; c=1'b1;
#20 a=1'b1; b=1'b1; c=1'b0;
#20 a=1'b1; b=1'b1; c=1'b1;

end
endmodule
