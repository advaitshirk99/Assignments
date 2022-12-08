`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 28.11.2022 13:36:31
// Design Name: 
// Module Name: seq_detector_moore
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


module sequence_detector_moore(
    input clk, reset, x,
    output reg z);
    parameter s0 = 0, s1 = 1, s2 = 2, s3 = 3, s4 = 4;
    reg [2:0] NS, PS;
    //Present state assignment
    always @(posedge clk or reset)
    begin
        if (reset)
            PS <= s0;
        else
            PS <= NS;
    end
    //Next state and Output assignment 
    always @ (*)
    begin
        case(PS)
        s0: begin NS = x ? s1 : s0; z = 1'b0; end
        s1: begin NS = x ? s1 : s2; z = 1'b0; end
        s2: begin NS = x ? s3 : s0; z = 1'b0; end
        s3: begin NS = x ? s4 : s2; z = 1'b0; end
        s4: begin NS = x ? s1 : s2; z = 1'b1; end
        endcase
    end
endmodule
