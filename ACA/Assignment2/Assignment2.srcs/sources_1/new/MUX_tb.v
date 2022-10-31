`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 17.10.2022 11:43:26
// Design Name: 
// Module Name: MUX_tb
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


module MUX_tb();
reg x, y, s0;
wire mux1, mux2;

    dataflow_MUX dataflow_mux(x, y, s0, mux1);
    gateflow_MUX gateflow_mux(x, y, s0, mux2);
    
    initial
    begin
    
    x=1'b0; y=1'b0; s0=1'b0;
#20    x=1'b0; y=1'b0; s0=1'b1;
#20    x=1'b0; y=1'b1; s0=1'b0;
#20    x=1'b0; y=1'b1; s0=1'b1;
#20    x=1'b1; y=1'b0; s0=1'b0;
#20    x=1'b1; y=1'b0; s0=1'b1;
#20    x=1'b1; y=1'b1; s0=1'b0;
#20    x=1'b1; y=1'b1; s0=1'b1;

end
endmodule
