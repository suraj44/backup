//TESTBENCH for 1 bit ALU
//Suraj Singh 16CO146
//Tarun Anand 16CO147
//Date: 25/10/17


//operation 0 indicates addition
//operation 0 indicates subtraction


module ALU_t;
	reg A;
	reg B;
	reg [4:0] control;
	wire out, overflow,iszero, greaterthan;
    wire [1:0] shiftout;

	ALU M1(A,B,control,shiftout,out,overflow,iszero,greaterthan);
	initial
	begin
		$dumpfile("ALU.vcd");
		$dumpvars(0, ALU_t);

        //bits 4 and 3 are 0, hence addition takes place. carry in is 0 and shift left is true (value of Ainvert Binvert won't even be considered for this operation)
		A = 1'b0;
		B = 1'b1;
		control = 5'b00001;
		#10
        //bits 4 and 3 indicate operation 2 which is AND. since Ainvert and Binvert is 1, NAND happens. Shift left is 0.
        A = 1'b1;
		B = 1'b1;
		control = 5'b10100;
		#10
        //addition with overflow, as carry in is 1
		A = 1'b0;
		B = 1'b1;
		control = 5'b00011;
        #10
        //AND operation
        A = 1'b1;
		B = 1'b0;
		control = 5'b10000;
        #10
        //AND operation
        A = 1'b1;
		B = 1'b1;
		control = 5'b10011;
        #10
        //OR operation
        A = 1'b0;
		B = 1'b1;
		control = 5'b11001;
        #10
        //NOR operation
        A = 1'b1;
		B = 1'b1;
		control = 5'b11010;
		//Subtraction without borrow
        #10
        A = 1'b1;
		B = 1'b0;
		control = 5'b01000;
		#10
		//Subtraction with borrow
		A = 1'b1;
		B = 1'b1;
		control = 5'b01010;
        #10
		$finish;
	end
	initial
		begin
			$monitor("A: %d B: %d Carryin/Borrowin: %d Control Signal: %d Shiftin: %d Output: %d Overflow: %d Shiftout: %2b IsZero? : %d A>B? : %d \n", A,B,control[1], control[4:3], control[0],out,overflow, shiftout, iszero, greaterthan);
		end

endmodule
