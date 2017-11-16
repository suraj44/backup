module othertoBCD(a,b,c,d,w,x,y,z);

	input a,b,c,d;
	output w,x,y,z;n
	wire tmp;
	assign  z = (d);
	assign	y = c&(~d) | (~c)&(d);
	assign tmp = c | d;
	assign x = (b)&(~tmp) | (~b)&tmp;
	assign w = ((a) &  (b|((~c)&(~d))));

endmodule
