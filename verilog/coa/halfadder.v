//Behavioural Modelling of a Half Adder
//16CO146 Suraj Singh
//16CO147 Tarun Anand
//Date: 07/10/2017

module halfadder(a,b,sum,carry);
	input a;  
	input b;
	output reg sum; 
	output reg carry;

	always @ (a or b) //always block will activate whenevebr a or b change
	begin 
		sum = a^b; //whenever one of the operands is 1 and the other is 0, the sum is 1. Hence, XOR function is used.
		
		carry = a&b; //Only when both operands are 1 is the carry 1. Hence the AND function is used.
	end
endmodule
