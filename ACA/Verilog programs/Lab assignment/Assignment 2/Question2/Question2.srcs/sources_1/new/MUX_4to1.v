`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 23.11.2022 14:08:02
// Design Name: 
// Module Name: MUX_4to1
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


module MUX_4to1(
    input [3:0]a,
    input [1:0]s,
    output reg out
    );

always @ (a or s)
begin

case (s)
2'b00 : out <= a[0];
2'b01 : out <= a[1];
2'b10 : out <= a[2];
2'b11 : out <= a[3];

endcase
end
endmodule

module MUX_16to1(
    input [15:0]a,
    input [3:0]s,
    output out
);

wire [3:0]out_w;
MUX_4to1 mux1(a[3:0], s[1:0], out_w[0]);
MUX_4to1 mux2(a[7:4], s[1:0], out_w[1]);
MUX_4to1 mux3(a[11:8], s[1:0], out_w[2]);
MUX_4to1 mux4(a[15:12], s[1:0], out_w[3]);
MUX_4to1 mux5(a[15:0], s[3:2], out);

endmodule