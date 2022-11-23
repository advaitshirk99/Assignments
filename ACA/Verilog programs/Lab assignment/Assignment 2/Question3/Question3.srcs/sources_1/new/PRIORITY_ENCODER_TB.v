`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 23.11.2022 18:50:44
// Design Name: 
// Module Name: PRIORITY_ENCODER_TB
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


module PRIORITY_ENCODER_TB();
reg [3:0]x;
wire [1:0]out;

PRIORITY_ENCODER p_encoder(x, out);
initial
begin
x = 4'b0000;
#10 x = 4'b1000;
#10 x = 4'b0100;
#10 x = 4'b0010;
#10 x = 4'b0001;
#10 x = 4'b1010;
#10 x = 4'b1111;
end 
endmodule
