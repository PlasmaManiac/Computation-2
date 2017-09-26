// Verilog test fixture created from schematic C:\Users\s144192\Dropbox\Courses\Year 2\Quartile 3\Computation 2\Computer Architecture\FullAdder\fulladd.sch - Sun Feb 21 18:33:38 2016

`timescale 1ns / 1ps

module fulladd_fulladd_sch_tb();

// Inputs
   reg c;
   reg b;
   reg a;

// Output

// Bidirs

// Instantiate the UUT
   fulladd UUT (
		.c(c), 
		.b(b), 
		.a(a)
   );
// Initialize Inputs
       initial begin
		c = 0;
		b = 0;
		a = 0;
   end
	always #50
	begin
	a = ~a;
	end
	always@(posedge a)
	begin
	b = ~b;
	end
	always@(posedge b) 
	begin
	c = ~c;
	end
endmodule
