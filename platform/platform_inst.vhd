	component platform is
		port (
			clk_clk                             : in  std_logic                    := 'X'; -- clk
			reset_reset_n                       : in  std_logic                    := 'X'; -- reset_n
			sevseg0_external_connection_export  : out std_logic_vector(6 downto 0);        -- export
			sevseg_0_external_connection_export : out std_logic_vector(6 downto 0);        -- export
			sevseg_1_external_connection_export : out std_logic_vector(6 downto 0);        -- export
			sevseg_2_external_connection_export : out std_logic_vector(6 downto 0);        -- export
			sevseg_3_external_connection_export : out std_logic_vector(6 downto 0);        -- export
			sevseg_4_external_connection_export : out std_logic_vector(6 downto 0);        -- export
			button_0_external_connection_export : in  std_logic                    := 'X'; -- export
			button_1_external_connection_export : in  std_logic                    := 'X'; -- export
			button_2_external_connection_export : in  std_logic                    := 'X'; -- export
			button_3_external_connection_export : in  std_logic                    := 'X'; -- export
			button_4_external_connection_export : in  std_logic                    := 'X'  -- export
		);
	end component platform;

	u0 : component platform
		port map (
			clk_clk                             => CONNECTED_TO_clk_clk,                             --                          clk.clk
			reset_reset_n                       => CONNECTED_TO_reset_reset_n,                       --                        reset.reset_n
			sevseg0_external_connection_export  => CONNECTED_TO_sevseg0_external_connection_export,  --  sevseg0_external_connection.export
			sevseg_0_external_connection_export => CONNECTED_TO_sevseg_0_external_connection_export, -- sevseg_0_external_connection.export
			sevseg_1_external_connection_export => CONNECTED_TO_sevseg_1_external_connection_export, -- sevseg_1_external_connection.export
			sevseg_2_external_connection_export => CONNECTED_TO_sevseg_2_external_connection_export, -- sevseg_2_external_connection.export
			sevseg_3_external_connection_export => CONNECTED_TO_sevseg_3_external_connection_export, -- sevseg_3_external_connection.export
			sevseg_4_external_connection_export => CONNECTED_TO_sevseg_4_external_connection_export, -- sevseg_4_external_connection.export
			button_0_external_connection_export => CONNECTED_TO_button_0_external_connection_export, -- button_0_external_connection.export
			button_1_external_connection_export => CONNECTED_TO_button_1_external_connection_export, -- button_1_external_connection.export
			button_2_external_connection_export => CONNECTED_TO_button_2_external_connection_export, -- button_2_external_connection.export
			button_3_external_connection_export => CONNECTED_TO_button_3_external_connection_export, -- button_3_external_connection.export
			button_4_external_connection_export => CONNECTED_TO_button_4_external_connection_export  -- button_4_external_connection.export
		);

