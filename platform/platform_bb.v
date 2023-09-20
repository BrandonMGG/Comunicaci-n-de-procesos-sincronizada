
module platform (
	clk_clk,
	reset_reset_n,
	sevseg0_external_connection_export,
	sevseg_0_external_connection_export,
	sevseg_1_external_connection_export,
	sevseg_2_external_connection_export,
	sevseg_3_external_connection_export,
	sevseg_4_external_connection_export,
	button_0_external_connection_export,
	button_1_external_connection_export,
	button_2_external_connection_export,
	button_3_external_connection_export,
	button_4_external_connection_export);	

	input		clk_clk;
	input		reset_reset_n;
	output	[6:0]	sevseg0_external_connection_export;
	output	[6:0]	sevseg_0_external_connection_export;
	output	[6:0]	sevseg_1_external_connection_export;
	output	[6:0]	sevseg_2_external_connection_export;
	output	[6:0]	sevseg_3_external_connection_export;
	output	[6:0]	sevseg_4_external_connection_export;
	input		button_0_external_connection_export;
	input		button_1_external_connection_export;
	input		button_2_external_connection_export;
	input		button_3_external_connection_export;
	input		button_4_external_connection_export;
endmodule
