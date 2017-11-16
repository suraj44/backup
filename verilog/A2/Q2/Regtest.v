//TESTBENCH for register file
//Suraj Singh 16CO146
//Tarun Anand 16CO147

module Registertest;
    reg[4:0] r1=0,r2=0,wreg;
    reg[31:0] wdata;
    reg write;
    wire[31:0] o1,o2;
    Registerfile M(o1,o2,r1,r2,wreg,wdata,write);
	initial
	begin
		$dumpfile("Register gtkwave.vcd");
		$dumpvars(0,Registertest);
	end
    always begin
  
        write = 1;
        wreg = 15;
        wdata = 120;
        #10;
	write=1;
	wreg=17;
	wdata = 2;
	#10;
	write=1;
	wreg=7;
	wdata=3;
	#1;
	write=0;
	wreg = 10;
	wdata=7;
	#10;
	r1=15;
	r2=7;
	write=1;
	#10;
	wreg=20;
	wdata = 132;
	#10;
	r1=20;
	r2=15;
	#10;
	wreg=15;
	wdata=72;
        $finish;
     end
     initial begin
        $monitor(" The value read by register 1 at location%d is%d, by register 2 at location%d is%d, write status is%d, value being written is%d ",r1,o1,r2,o2,write,wreg);
    end
endmodule
