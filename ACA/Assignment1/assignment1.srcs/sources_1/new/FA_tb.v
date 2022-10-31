`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.10.2022 10:28:35
// Design Name: 
// Module Name: FA_tb
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


module FA_tb();
    reg [3:0]A;
    reg [3:0]B;
    reg Cin;
    wire [3:0]Sum;
    wire Cout;
    
FA_4bit FullAdder_4BIT(A, B, Cin, Sum, Cout);
initial 
begin

A = 4'b0000; B = 4'b0000; Cin = 1'b0;
#20 A = 4'b0001; B = 4'b0000; Cin = 1'b1;
#20 A = 4'b0010; B = 4'b0001; Cin = 1'b0;
#20 A = 4'b0100; B = 4'b0010; Cin = 1'b1;
#20 A = 4'b1000; B = 4'b0100; Cin = 1'b0;
#20 A = 4'b1010; B = 4'b1000; Cin = 1'b1;

end
endmodule