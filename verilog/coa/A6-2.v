//Verilog code to implement a 2 node point to point interconnection network
//16CO146 Suraj Singh 
//16CO147 Tarun Anand
//Date: 08/10/2017

module A(clk,i1,i3,i4,i5,o1);
	input [7:0] i1,i3,i4,i5;
	input clk;
	output reg [7:0] o1;
	integer count1;
	always @(posedge clk)
		assign o1 = $urandom & 255; //generating a message in module A

	B M3(clk,o1,i1,i3,i4,i5); //passing outputs of B as inputs to A and output of A as input of B
		

endmodule






module B(clk,i2,o2,o3,o4,o5);
	input clk;
	input [7:0] i2;
	output reg [7:0] o2,o3,o4,o5;
	integer count;
	always @(posedge clk)
	begin
		assign o2 = $urandom & 255; //generating 4 messages whenever module B is called
		assign o3 = $urandom & 255;
		assign o4 = $urandom & 255;
		assign o5 = $urandom & 255;
	end
		//A M4(clk,i2,o2);
		
endmodule
