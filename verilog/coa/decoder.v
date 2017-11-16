//Behavioural modeling of a 4:16 Decoder
//16CO146 Suraj Singh
//16CO147 Tarun Anand
//Date: 07/10/2017

module decoder(enable,in,out);
	input enable; 
	input [3:0] in;
	
	output reg [15:0] out;
	always@(in or enable) 
	begin
		out = 0;
		if (enable)
		begin
			case(in)
				4'd0: out= 16'h1;
				4'd1: out= 16'h2;
				4'd2: out= 16'h4;
				4'd3: out= 16'h8;
				4'd4: out= 16'h10;
				4'd5: out= 16'h20;
				4'd6: out= 16'h40;
				4'd7: out= 16'h80;
				4'd8: out= 16'h100;
				4'd9: out= 16'h200;
				4'd10: out= 16'h400;
				4'd11: out= 16'h800;
				4'd12: out= 16'h1000;
				4'd13: out= 16'h2000;
				4'd14: out= 16'h4000;
				4'd15: out= 16'h8000;
			endcase
		end
	end
endmodule
			