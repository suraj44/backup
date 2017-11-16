//Testbench for a 4:16 Decoder
//16CO146 Suraj Singh
//16C0147 Tarun Anand

module decoder_t;
	reg enable;
	reg [3:0] in;
	wire [15:0] out;
	decoder M1(enable,in,out);
	initial
	begin	
		$dumpfile("A2decoder.vcd");
		$dumpvars(0, decoder_t);
		in= 4'd0;
		enable = 0;
		#100;
		in= 4'd1;
		#100;
		in= 4'd0;
		enable = 1;
		#100;
		in= 4'd1;
		#100;
		in= 4'd2;
		#100; 
		in= 4'd3;
		#100; 
		in= 4'd4;
		#100; 
		in= 4'd5;
		#100;			
		in= 4'd6;
		#100;
		in= 4'd7;
		#100;
		in= 4'd8;
		#100; 
		in= 4'd9;
		#100;
		in= 4'd10;
		#100; 
		in= 4'd11;
		#100; 
		in= 4'd12;
		#100; 
		in= 4'd13;
		#100; 
		in= 4'd14;
		#100; 
		in= 4'd15;
		#100; 
		$finish;
	end
endmodule