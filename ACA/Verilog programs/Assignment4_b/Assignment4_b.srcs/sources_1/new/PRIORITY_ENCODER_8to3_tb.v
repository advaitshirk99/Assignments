`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 18.10.2022 14:49:41
// Design Name: 
// Module Name: PRIORITY_ENCODER_8to3_tb
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


module PRIORITY_ENCODER_8to3_tb();
reg [7:0]y;
wire [2:0]a, valid;

PRIORITY_ENCODER_8to3 pe_8to3(.y(y), .a(a), .valid(valid));
initial 
begin

y[7]=1'b0; y[6]=1'b0; y[5]=1'b0; y[4]=1'b0; y[3]=1'b0; y[2]=1'b0; y[1]=1'b0; y[0]=1'b0;
#20 y[7]=1'b0; y[6]=1'b0; y[5]=1'b0; y[4]=1'b0; y[3]=1'b0; y[2]=1'b0; y[1]=1'b0; y[0]=1'b1;
#20 y[7]=1'b0; y[6]=1'b0; y[5]=1'b0; y[4]=1'b0; y[3]=1'b0; y[2]=1'b0; y[1]=1'b1; y[0]=1'b0;
#20 y[7]=1'b0; y[6]=1'b0; y[5]=1'b0; y[4]=1'b0; y[3]=1'b0; y[2]=1'b1; y[1]=1'b0; y[0]=1'b0;
#20 y[7]=1'b0; y[6]=1'b0; y[5]=1'b0; y[4]=1'b0; y[3]=1'b1; y[2]=1'b0; y[1]=1'b0; y[0]=1'b0;
#20 y[7]=1'b0; y[6]=1'b0; y[5]=1'b0; y[4]=1'b1; y[3]=1'b0; y[2]=1'b0; y[1]=1'b0; y[0]=1'b0;
#20 y[7]=1'b0; y[6]=1'b0; y[5]=1'b1; y[4]=1'b0; y[3]=1'b0; y[2]=1'b0; y[1]=1'b0; y[0]=1'b0;
#20 y[7]=1'b0; y[6]=1'b1; y[5]=1'b0; y[4]=1'b0; y[3]=1'b0; y[2]=1'b0; y[1]=1'b0; y[0]=1'b0;
#20 y[7]=1'b1; y[6]=1'b0; y[5]=1'b0; y[4]=1'b0; y[3]=1'b0; y[2]=1'b0; y[1]=1'b0; y[0]=1'b0;

end
endmodule
