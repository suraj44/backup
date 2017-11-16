//Verilog code for an n-bit adder/subtractor
//16CO146 Suraj Singh 
//16CO147 Tarun Anand
//Date: 08/10/2017

module nbitAdder(i1,i2,ans,diff,tempo);
parameter n=8;
    input [n-1:0] i1,i2;
    output [n-1:0] ans,diff;
    output [n-1:0] tempo;

    //wire [n-1:0] tmp1;
    wire [n-1:0] carry1,borrow,temp;
    genvar i;
    generate
    integer l;


   for(i=0;i<n;i=i+1)
     begin

   if(i==0) 
        fulladder M4(i1[i],i2[i],0,ans[i],carry1[i]); //carry in for the first bit is 0
   else
        fulladder M3(i1[i],i2[i],carry1[i-1],ans[i],carry1[i]);
    
   end
   endgenerate
   genvar j;
   generate

   for(j=0;j<n;j=j+1)
     begin

   if(j==0) 
        fulladder M5(i1[j],(~i2[j]),0,diff[j],borrow[j]); //carry in for the first bit is 1
   else if (j==(n-1))
        fulladder M6((~i1[j]),(i2[j]),borrow[j-1],(diff[j]),borrow[j]); //the MSB of the difference must be inverted
   else
        fulladder M6(i1[j],(~i2[j]),borrow[j-1],diff[j],borrow[j]);
   end

    

   endgenerate
  
endmodule 


module fulladder(a,b,cin, sum,cout);
	input a;
	input b;
	input cin;
	output sum;
	output cout;
	wire tmp1, tmp2,tmp3;
	assign cout = tmp2 | tmp3;
	halfadder M1(a,b,tmp1,tmp2);
	halfadder M2(tmp1,cin, sum,tmp3);
endmodule

module halfadder(p,q,sum2,crry);
	input p;
	input q;
	output reg sum2;
	output reg crry;

	always @ (p or q)
	begin 
		sum2 = p^q;
		crry = p&q;
	end
endmodule
