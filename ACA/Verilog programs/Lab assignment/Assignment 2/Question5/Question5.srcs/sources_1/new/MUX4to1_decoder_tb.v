`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 23.11.2022 19:38:02
// Design Name: 
// Module Name: MUX4to1_decoder_tb
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


module MUX4to1_decoder_tb();
reg [1:0]x;
reg [3:0]in;
wire out;
MUX4to1_decoder M1(x, in, out);
initial 
begin
in = 4'b0001; x = 2'b00; 
#10 in = 4'b0010; x = 2'b01; 
#10 in = 4'b0100; x = 2'b10; 
#10 in = 4'b1000; x = 2'b11; 
end
endmodule
