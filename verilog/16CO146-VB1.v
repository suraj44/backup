module othertoBCD(a,b,c,d,w,x,y,z);
	
	
	input a,b,c,d;
	output reg w,x,y,z;
	reg tmp;
	
	always @(a or b or c or d)
	begin

	z = (d);
	y = c&(!d) | (!c)&(d);
	tmp = c | d;
	x = (b)&(!tmp) | (!b)&tmp;
	w = ((a) ||  (b&&(c||d)));
	end

endmodule