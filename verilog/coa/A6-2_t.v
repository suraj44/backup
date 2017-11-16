//TESTBENCH for implementing a 2 node point to point interconnection network

module A6test();
	reg clk;
	reg [7:0] i1,i2,i3,i4,i5;
	wire [7:0] o1,o2,o3,o4,o5;
    reg [7:0] rand;
    
	A M1(clk,i1,i3,i4,i5,o1);
	B M2(clk, i2,o2,o3,o4,o5);
	integer i;
	initial
		begin
			$dumpfile("A6-2.vcd");
			$dumpvars(0,A6test);
			clk=0;
			
			for(i=1;i<10;i=i+1) begin
			    rand = $urandom & 15;
				#rand
				clk=~clk;
				#rand
				clk=~clk;
					i1 = o2; 
					i2 = o1;
					i3 = o3;
					i4 = o4;
					i5 = o5;
					$display("A sent %8b and received %8b, %8b, %8b, %8b\n", o1, i1,i3,i4,i5);
					$display("Time elapsed   %tns\n\n",$realtime);
			end
			
	end
endmodule
