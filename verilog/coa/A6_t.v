//TESTBENCH for implementing a 2 node point to point interconnection network

module A6test();
	reg clk;
	reg [3:0] i1,i2;
	wire [3:0] o1,o2;
    reg [3:0] rand;
    
	A M1(clk,i1,o1);
	B M2(clk, i2,o2);
	integer i;
	initial
		begin
			$dumpfile("A6.vcd");
			$dumpvars(0,A6test);
			clk=0;
			
			for(i=1;i<10;i=i+1) begin
			    rand = $urandom & 15;
				#rand
				clk=~clk;
				#rand
				clk=~clk;
					i1 = o2; //I'm linking the two modules here. Is that okay?
					i2 = o1;
					$display("A sent %4b and received %4b\n", o1, i1);
					$display("B sent %4b and received %4b\n", o2, i2);
					$display("Time elapsed   %tns\n\n",$realtime);
			end
			
	end
endmodule
