//Verilog code of a Full Adder using Half Adder
//16CO146 Suraj Singh
//16CO147 Tarun Anand
//Date: 07/10/2017


module fulladder(a,b,cin, sum,cout);
	input a;
	input b;
	input cin;
	output sum;
	output cout;
	wire tmp1, tmp2,tmp3;
	assign cout = tmp2 | tmp3;
	halfadder M1(a,b,tmp1,tmp2);  //tmp1 will take the value of a+b and tmp2 will take the value of the carry out from (a+b)
	halfadder M2(tmp1,cin, sum,tmp3); 
endmodule

