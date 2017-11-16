//TESTBENCH for a Half Adder
//16CO146 Suraj Singh
//16CO147 Tarun Anand
//Date: 07/10/2017

module fulladder_t;
	reg a,b,cin;
	wire sum,cout;
	fulladder M1(a,b,cin,sum,cout);
	initial 
	begin 
		$dumpfile("A4.vcd");
		$dumpvars(0, fulladder_t);
		a = 0;
		b = 0;
		cin = 0;
		#100;
		a = 0;
		b = 0;
		cin = 1;
		#100;
		a = 0;
		b = 1;
		cin = 0;
		#100;
		a = 0;
		b = 1;
		cin = 1;
		#100;
		a = 1;
		b = 0;
		cin = 0;
		#100;
		a = 1;
		b = 0;
		cin = 1;
		#100;
		a = 1;
		b = 1;
		cin = 0;
		#100;
		a = 1;
		b = 1;
		cin = 1;
		#100;
		$finish;
	end
    initial 
    begin
    $monitor("For input operands %d and %d and carry in %d, sum is %d and carry is %d",a,b,cin,sum,cout);
    end
endmodule
