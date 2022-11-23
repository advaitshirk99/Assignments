`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 23.11.2022 11:05:09
// Design Name: 
// Module Name: FA_4bit_tb
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


module FA_4bit_tb();
    reg [3:0]x;
    reg [3:0]y;
    reg cin;
    wire [3:0]cout;
    wire [3:0]sum;
    
FA_4bit fulladder_4bit(x, y, cin, cout, sum);
initial 
begin

x = 4'b0000; y = 4'b0000; cin = 1'b0;
#20 x = 4'b0001; y = 4'b0000; cin = 1'b1;
#20 x = 4'b0010; y = 4'b0001; cin = 1'b0;
#20 x = 4'b0100; y = 4'b0010; cin = 1'b1;
#20 x = 4'b1000; y = 4'b0100; cin = 1'b0;
#20 x = 4'b1010; y = 4'b1000; cin = 1'b1;

end
endmodule
