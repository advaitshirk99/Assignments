`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.10.2022 13:46:51
// Design Name: 
// Module Name: DEMUX_1to2_tb
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

module DEMUX_1to2_tb();

reg a, s0;
wire y0, y1;

demux_1to2 demux_1to2_tb(a, s0, y0, y1);

initial 
begin

a= 1'b0; s0=1'b0;
#20 a= 1'b0; s0=1'b1;
#20 a= 1'b1; s0=1'b0;
#20 a= 1'b1; s0=1'b1;

end
endmodule
