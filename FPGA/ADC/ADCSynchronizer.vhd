----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:24:12 03/09/2019 
-- Design Name: 
-- Module Name:    ADCSynchronizer - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ADCSynchronizer is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           ADC_CLK : in  STD_LOGIC;
           ADC_DATA : in  STD_LOGIC_VECTOR (13 downto 0);
           DATA_OUT : out  STD_LOGIC_VECTOR (13 downto 0);
           NEW_SAMPLE : out  STD_LOGIC);
end ADCSynchronizer;

architecture Behavioral of ADCSynchronizer is
	signal last_clk : STD_LOGIC;
	signal new_clk : STD_LOGIC;
	signal xfer_pipe : STD_LOGIC;
begin

	process(CLK)
	begin
		if rising_edge(CLK) then
			if RESET = '1' then
				DATA_OUT <= (others => '0');
				last_clk <= '0';
				new_clk <= '0';
				xfer_pipe <= '0';
				NEW_SAMPLE <= '0';
			else
				-- synchronize ADC CLK into main clk domain
				new_clk <= xfer_pipe;
				xfer_pipe <= ADC_CLK;
				-- edge detection
				last_clk <= new_clk;
				if new_clk = '1' and last_clk  = '0' then
					DATA_OUT <= ADC_DATA;
					NEW_SAMPLE <= '1';
				else
					NEW_SAMPLE <= '0';
				end if;
			end if;
		end if;
	end process;

end Behavioral;

