`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04.10.2022 10:33:01
// Design Name: 
// Module Name: FA_4bit
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


module FA_4bit(
    input [3:0]A,
    input [3:0]B,
    input Cin,
    output [3:0]Sum,
    output Cout
    );
    
    wire w1, w2, w3;
    FA_GateFlow fa1 (A[0], B[0], Cin, Sum[0], w1);
    FA_GateFlow fa2 (A[1], B[1], w1, Sum[1], w2);
    FA_DataFlow fa3 (A[2], B[2], w2, Sum[2], w3);
    FA_DataFlow fa4 (A[3], B[3], w2, Sum[3], Cout);
    
endmodule

module FA_GateFlow(
    input A,
    input B,
    input Cin,
    output Sum,
    output Cout
    );
    
   wire w1, w2, w3;
   xor(w1, A, B);
   xor(Sum, w1, Cin);
   and(w2, Cin, w1);
   and(w3, A, B);
   or(Cout, w2, w3);
   
endmodule

module FA_DataFlow(
    input A,
    input B,
    input Cin,
    output Sum,
    output Cout
    );
    
    assign Sum = A ^ B ^ Cin;
    assign Cout = (A || B) && (B || Cin) && (Cin || A);
   
endmodule
