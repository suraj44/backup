//TESTBENCH for a n bit Adder
//16CO146 Suraj Singh
//16CO147 Tarun Anand
//Date: 08/10/2017
//testbench has to change depending on the 'n' chosen
module nbitAdder_t;
	reg [7:0] a,b;
	wire [7:0] sum,diff,tempo;
	nbitAdder M1(a,b,sum,diff,tempo);
	initial 
	begin
		$dumpfile("A5.vcd");
		$dumpvars(0, nbitAdder_t);
		a = 8'b00000010;
		b = 8'b00000010;
		#10;
        a = 8'b00100001;
		b = 8'b00001010;
		#10;
        a = 8'b00110001;
		b = 8'b10111110;
		#10;
		$finish;
	end
    initial
    begin

        $monitor("%d The operands are %d and %d. Their sum is %d and their difference is %d, tempo is %d\n",diff[7], a,b,sum,diff,(tempo));
    end
endmodule
