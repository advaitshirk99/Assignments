`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 23.11.2022 19:12:50
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
reg [2:0]x;
wire [7:0]out;

DECODER_3to8 decode(x, out);
initial 
begin
x = 3'b000; 
#20 x = 3'b001; 
#20 x = 3'b010;
#20 x = 3'b011;
#20 x = 3'b100;
#20 x = 3'b101;
#20 x = 3'b110;
#20 x = 3'b111;
end
endmodule
