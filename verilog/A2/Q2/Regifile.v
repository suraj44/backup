


module Registerfile(rd1,rd2,rno1,rno2,wreg,wdata,write);
  input [4:0]rno1;
  input [4:0]rno2;
  input [4:0]wreg;
  input [31:0]wdata;
  input write;
  output [31:0]rd1;
  output [31:0]rd2;

  wire[31:0]enabl;
  wire[31:0]writewire;
  wire[31:0][31:0]rout;

  mux m1(rd1,rno1,rout);
  mux m2(rd2,rno2,rout);
  dec M1(writewire,wreg);
  genvar i;
  generate
  for(i=0;i<32;i=i+1)
  begin
    and(enabl[i],write,writewire[i]);
    register r(wdata,enabl[i],rout[i]);
  end
  endgenerate
endmodule



module srff(Q,R,S,clk);
	input [31:0]S;																//Setting up 32 -bit latch
	input [31:0]R;
	output reg [31:0]Q;
	integer qprev[31:0];
	input clk;
	integer j[31:0];
	integer i;
	integer t;
	initial
	begin
		for(i=0;i<32;i=i+1)
			qprev[i]=0;
	end
	always @(  clk==1)
	begin
		for(i=0;i<32;i=i+1)
		begin

		 if(!S[i]&&!R[i])
			begin
				Q[i]=qprev[i];
			end
			else if(S[i]&&!R[i])
			begin
				Q[i]=1;
			end
			else if(!S[i]&&R[i])													//Settin cases
			begin
				Q[i]=0;
			end
			else if(S[i]&&R[i])
			begin
				Q[i]=1'bx;
			end
			qprev[i]=Q[i];
		end
	end
	initial
		begin
			if(j[i]==0)																		//Setting Qn-1 for each bit
			begin
				Q[i]=1;
				j[i]=1;
			end
		end
endmodule


module register(D,clk,Q);										//Module register
	input [31:0]D;
	input clk;
	output [31:0]Q;
	Dflipflop M1(D,clk,Q);										//Calling D flipflop
endmodule


module Dflipflop(D,clk,Q);
	input [31:0]D;
	input clk;
	output [31:0]Q;
	wire [31:0]J;
	Dlatch M1(D,~clk,J);												//Calling D latch
	Dlatch M2(J,clk,Q);
endmodule

module Dlatch(D,clk,Q);
	input [31:0]D;
	input clk;
	output  [31:0]Q;
	srff M2(Q,~D,D,clk);												//Calling S-R flipflop
endmodule

module mux( out,sel,ip);
  output reg[31:0] out;
  input[4:0] sel ;
  input[31:0][31:0]ip ;
    always@(ip or sel) begin
        out <= ip[sel];
    end
endmodule

module dec(out,in);
  output reg[31:0] out;
  input[4:0] in;
    always@(in) begin
        out = 0;
        out[in] = 1'b1;
    end
endmodule
