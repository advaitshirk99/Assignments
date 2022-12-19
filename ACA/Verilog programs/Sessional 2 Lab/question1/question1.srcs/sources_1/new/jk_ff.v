`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 15.12.2022 15:04:54
// Design Name: 
// Module Name: jk_ff
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


module jk_ff(
    input J, K, CLK, RESET,
    output Q, Qb);
    reg Q, Qb;
    
    always @(posedge CLK or RESET)
    begin 
        if(!RESET)
        begin
        case({J, K})
            2'b00: Q = Q;
            2'b01: Q = 1'b0;
            2'b10: Q = 1'b1;
            2'b11: Q = ~Q;
        endcase
        end
        else
           Q = 1'b0;
        Qb = ~Q;
    end
endmodule
