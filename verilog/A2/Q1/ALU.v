//Implementing a 1 bit ALU in Verilog
//Suraj Singh 16CO146
//Tarun Anand 16CO147
//Date: 25/10/17

//All the control inputs to the ALU have been specified in the array "control"
//Bits 4 and 3 denote the operation input which controls which function of the ALU is processed 
//Bits 2 denotes Ainvert and Binvert combined 
//Bit 1 represents carry in 
//Bit 0 represents shift left




module ALU(A, B , control, shiftout, out,overflow,iszero,greaterthan);
	input A;
	input B;
	input [4:0] control; 
	output reg out,overflow,iszero,greaterthan;
    output reg [1:0] shiftout;


	always@(control or A or B)
	begin
	case(control[4:3]) //bits 5 and 4 account for which operation
		0: //if operation is 0, then the adder is invoked. it takes A, B and carry in as input
		begin
			out = A^B^control[1];
			overflow = (A^B)&control[1] + A&B;
		end

		1: //if operation is 1, then the subtractor is invoked. it takes A, B and carry(borrow) in as input
		begin
			out = A^B^control[1];
			overflow = (!A)&control[1] + (!(A^B))&control[1];
		end

		2: //if operation is 2, then the AND operation is invoked. If Ainvert and Binvert are 1, then output of ALU is A NAND B. Else, A AND B
		begin
			if(control[2])
				out = (!A) & (!B);
			else
				out = A&B;
		end

		3: //if operation is 3, then the OR operation is invoked. If Ainvert and Binvert are 1, then the ouput of the ALU is A NOR B. Else, A OR B
		begin
			if(control[2])
				out = (!A) | (!B);
			else
				out = A|B;
		end

		default out = 0;
	endcase
    // for the shift left operation 
		if(control[0])
			shiftout  = out<<1;
		else
			shiftout = out;
        if(out==0)  //flag to indicate whetehr the output is zero or not
            iszero =1;
        else
            iszero = 0;

        if(A>B)  //flag to indicate if the first input (A) is greater than the second input (B) or
            greaterthan =1;
        else
            greaterthan = 0;

    end

endmodule 
