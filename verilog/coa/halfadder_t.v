//TESTBENCH for a Half Adder
//16CO146 Suraj Singh
//16CO147 Tarun Anand
//Date: 07/10/2017

module halfadder_t;
	reg a,b;
	wire sum,carry;
	halfadder M1(a,b,sum,carry);
	initial 
	begin 
		$dumpfile("A3.vcd");
		$dumpvars(0, halfadder_t);
		a = 0;
		b = 0;
		#100;
		a = 0;
		b = 1;
		#100;
		a = 1;
		b = 0;
		#100;
		a = 1;
		b = 1;
		#100;
		$finish;
	end
    initial
    begin
        $monitor("For input operands %d and %d, sum is %d and carry is %d",a,b,sum,carry);
    end
endmodule
