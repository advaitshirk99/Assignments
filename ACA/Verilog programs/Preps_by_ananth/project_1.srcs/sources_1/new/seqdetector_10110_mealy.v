`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 14.12.2022 18:30:42
// Design Name: 
// Module Name: seqdetector_10110_mealy
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


module seqdetector_10110_mealy(input clk,
    input reset,
    input x,
    output reg z
    );
    parameter s0 = 0, s1 = 1, s2 = 2, s3 = 3, s4 = 4;
    reg [2:0] PS, NS;
    
    //present state assignment
    always @ (posedge clk or posedge reset)
    begin
        if (reset)
            PS <= s0;
        else
            PS <= NS;
    end
    
    //output assignment
    always @ (posedge clk or posedge reset)
    begin
        if(reset)
            z = 1'b0;
        else if((PS == s4) && (x == 0))
            z = 1'b1;
        else 
            z = 1'b0;
    end
    
    //next state generation
    always @(*)
    begin
        case(PS)
        s0: NS = x ? s1 : s0;
        s1: NS = x ? s1 : s2;
        s2: NS = x ? s3 : s0;
        s3: NS = x ? s4 : s2;
        s4: NS = x ? s1 : s2;
        endcase
    end  
endmodule
