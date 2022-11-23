`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.10.2022 13:46:51
// Design Name: 
// Module Name: DEMUX_2to4_tb
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

module demux_2to4_tb();

reg a, s0, s1;
wire y0, y1, y2, y3;

demux_2to4 demux_2to4_tb(a, s0, s1, y0, y1, y2, y3);

initial 
begin

a= 1'b0; s0=1'b0; s1=1'b0; 
#20 a= 1'b0; s0=1'b0; s1=1'b1;
#20 a= 1'b0; s0=1'b1; s1=1'b0;
#20 a= 1'b0; s0=1'b1; s1=1'b1;
#20 a= 1'b1; s0=1'b0; s1=1'b0;
#20 a= 1'b1; s0=1'b0; s1=1'b1;
#20 a= 1'b1; s0=1'b1; s1=1'b0;
#20 a= 1'b1; s0=1'b1; s1=1'b1;

end
endmodule
