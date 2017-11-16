//Suraj Singh 16CO146
//TESTBENCH for Gate modeling program for converting 84-2-1 to BCD
module othertoBCD_t;

  reg  a, b,c,d;
  wire  w,x,y,z;
  
  //'timescale 1ns/10ps'

  othertoBCD M1 (a,b,c,d,w,x,y,z);

  initial begin
  $dumpfile("FINAL.vcd");
  $dumpvars(0, othertoBCD_t);
    a = 1'b0;
    b = 1'b0;
    c = 1'b0;
    d = 1'b0;
    #100
    a = 1'b0;
    b = 1'b0;
    c = 1'b0;
    d = 1'b1;
    #100
    a = 1'b0;
    b = 1'b0;
    c = 1'b1;
    d = 1'b0;
    #100
    a = 1'b0;
    b = 1'b0;
    c = 1'b1;
    d = 1'b1;
    #100
    a = 1'b0;
    b = 1'b1;
    c = 1'b0;
    d = 1'b0;
    #100
    a = 1'b0;
    b = 1'b1;
    c = 1'b0;
    d = 1'b1;
    #100
    a = 1'b0;
    b = 1'b1;
    c = 1'b1;
    d = 1'b0;
    #100
    a = 1'b0;
    b = 1'b1;
    c = 1'b1;
    d = 1'b1;
    #100
    a = 1'b1;
    b = 1'b0;
    c = 1'b0;
    d = 1'b0;
    #100
    a = 1'b1;
    b = 1'b0;
    c = 1'b0;
    d = 1'b1;
    #100
    $finish;
  end
  //initial #600 finish
endmodule
