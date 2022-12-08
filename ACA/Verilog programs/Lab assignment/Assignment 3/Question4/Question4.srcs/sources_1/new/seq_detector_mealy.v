`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.11.2022 12:48:50
// Design Name: 
// Module Name: seq_detector_mealy
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


module sequence_detector_mealy(
    input clk, reset, x,
    output reg z);
    parameter s0 = 0 , s1 = 1, s2 = 2, s3 = 3;
    reg [1:0] PS, NS;
    //Present state
    always @(posedge clk or reset)
    begin
        if (reset)
            PS <= s0;
        else
            PS <= NS;
    end
    //Output state
    always @ (posedge clk or reset)
    begin
        if(reset)
            z = 1'b0;
        else if ((PS == s3) && x)
            z = 1'b1;
        else 
            z = 1'b0; 
    end
    //Next state 
    always @ (*)
    begin
        case(PS)
        s0: NS = x ? s1 : s0;
        s1: NS = x ? s1 : s2;
        s2: NS = x ? s3 : s0;
        s3: NS = x ? s1 : s2;
        endcase
    end
endmodule
