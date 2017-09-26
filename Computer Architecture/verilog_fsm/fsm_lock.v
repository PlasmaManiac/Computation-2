`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:46:12 02/21/2016 
// Design Name: 
// Module Name:    fsm_lock 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module fsm_lock(
    input wire clk,
    input wire reset_in,
    input wire b0_in,
    input wire b1_in,
    output reg out,
    output reg[3:0] hex_display
	 );
	 
	 
	 localparam STATE_Initial = 3'd0,
					STATE_1		  = 3'd1,
					STATE_2		  = 3'd2,
					STATE_3		  = 3'd3,
					STATE_4		  = 3'd4,
					STATE_5		  = 3'd5,
	STATE_6_Placeholder		  = 3'd6,
	STATE_7_Placeholder		  = 3'd7;
	
	reg[2:0] CurrentState;
	reg[2:0] NextState;
	
	always@(posedge clk) begin
		if(reset_in) CurrentState <= STATE_Initial;
		else CurrentState <= NextState;
	end
	
	
	always@( * ) begin
		NextState = CurrentState;
		case(CurrentState)
			STATE_Initial: begin
				if(b0_in) NextState = STATE_1;
				out = 0;
				hex_display = 4'b0000;
			end
			
			STATE_1: begin
					if (b0_in) NextState = STATE_1;
					if (b1_in) NextState = STATE_2;
					out = 0;
					hex_display = 4'b0001;
			end
			
			STATE_2: begin
					if (b0_in) NextState = STATE_1;
					if (b1_in) NextState = STATE_3;
					out = 0;
					hex_display = 4'b0010;
			end
			STATE_3: begin
					if (b0_in) NextState = STATE_4;
					if (b1_in) NextState = STATE_Initial;
					out = 0;
					hex_display = 4'b0011;
			end
			STATE_4: begin
					if (b0_in) NextState = STATE_1;
					if (b1_in) NextState = STATE_5;
					out = 0;
					hex_display = 4'b0100;
			end
			STATE_5: begin
					if (b0_in) NextState = STATE_1;
					if (b1_in) NextState = STATE_Initial;
					out = 1;
					hex_display = 4'b0101;
			end
		endcase
	end
	
	
endmodule
