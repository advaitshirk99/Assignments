`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 15.12.2022 16:00:05
// Design Name: 
// Module Name: moore_1100detector
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


module moore_1100detector(
    input CLK, RESET, D,
    output reg OUT);
    
    parameter S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4;
    reg [2:0] PS, NS;
    
    always @(posedge CLK or RESET)
    begin
        if (RESET)
            PS <= S0;
        else
            PS <= NS;
    end
    always @ (*)
    begin
        case(PS)
        S0: begin NS = D ? S1:S0; end
        S1: begin NS = D ? S2:S0; end
        S2: begin NS = D ? S2:S3; end
        S3: begin NS = D ? S1:S4; end
        S4: begin NS = D ? S1:S0; end        
        endcase
    end
    
    always@ (*)
    begin
        case(PS)
        S0: begin OUT = 1'b0; end
        S1: begin OUT = 1'b0; end
        S2: begin OUT = 1'b0; end
        S3: begin OUT = 1'b0; end
        S4: begin OUT = 1'b1; end        
        endcase
    end
endmodule
