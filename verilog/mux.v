module mux(A,B,select[0:2], out);
	input A,B,select;
	output out;
	always @(A or B or select)
	begin
		if(select)
			out = B;
		else
			out = A:
	end
endmodule


module alu(control, a,b,clk,shift);
