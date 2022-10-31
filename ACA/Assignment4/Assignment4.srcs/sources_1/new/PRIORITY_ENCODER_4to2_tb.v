`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 18.10.2022 14:15:52
// Design Name: 
// Module Name: PRIORITY_ENCODER_4to2_tb
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


module PRIORITY_ENCODER_4to2_tb();
reg [3:0]y;
wire [1:0]a, valid;

PRIORITY_ENCODER_4to2 pe_4to2(.y(y), .a(a), .valid(valid));
initial 
begin

y[3]= 1'b0; y[2]= 1'b0; y[1]= 1'b0; y[0]= 1'b0;
#20 y[3]= 1'b0; y[2]= 1'b0; y[1]= 1'b0; y[0]= 1'b1;
#20 y[3]= 1'b0; y[2]= 1'b0; y[1]= 1'b1; y[0]= 1'b0;
#20 y[3]= 1'b0; y[2]= 1'b1; y[1]= 1'b0; y[0]= 1'b0;
#20 y[3]= 1'b1; y[2]= 1'b0; y[1]= 1'b0; y[0]= 1'b0;

end
endmodule
