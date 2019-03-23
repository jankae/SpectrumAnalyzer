----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:04:42 03/22/2019 
-- Design Name: 
-- Module Name:    display - Behavioral 
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

entity display is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           DATA : in  STD_LOGIC_VECTOR (15 downto 0);
           DIGITS : out  STD_LOGIC_VECTOR (3 downto 0);
           SEGMENTS : out  STD_LOGIC_VECTOR (7 downto 0));
end display;

architecture Behavioral of display is
	signal digit : integer range 0 to 3;
	signal nibble : STD_LOGIC_VECTOR (3 downto 0);
	signal clk_counter : integer range 0 to 25000;
begin

	process(CLK)
	begin
		if rising_edge(CLK) then
			if(RESET = '1') then
				clk_counter <= 0;
				digit <= 0;
				DIGITS <= (others => '0');
				SEGMENTS <= (others => '1');
			else
				if clk_counter < 25000 then
					clk_counter <= clk_counter + 1;
				else
					clk_counter <= 0;
					if digit < 3 then
						digit <= digit + 1;
					else
						digit <= 0;
					end if;
				end if;
				case(digit) is
					when 0 => nibble <= DATA(3 downto 0);
												DIGITS <= not "1000";
					when 1 => nibble <= DATA(7 downto 4);
												DIGITS <= not "0100";
					when 2 => nibble <= DATA(11 downto 8);
												DIGITS <= not "0010";
					when 3 => nibble <= DATA(15 downto 12);
												DIGITS <= not "0001";
				end case;
				case(nibble) is
					when "0000" => SEGMENTS <= "11111100";
					when "0001" => SEGMENTS <= "01100000";
					when "0010" => SEGMENTS <= "11011010";
					when "0011" => SEGMENTS <= "11110010";
					when "0100" => SEGMENTS <= "01100110";
					when "0101" => SEGMENTS <= "10110110";
					when "0110" => SEGMENTS <= "10111110";
					when "0111" => SEGMENTS <= "11100000";
					when "1000" => SEGMENTS <= "11111110";
					when "1001" => SEGMENTS <= "11110110";
					when "1010" => SEGMENTS <= "11101110";
					when "1011" => SEGMENTS <= "00111110";
					when "1100" => SEGMENTS <= "10011100";
					when "1101" => SEGMENTS <= "01111010";
					when "1110" => SEGMENTS <= "10011110";
					when "1111" => SEGMENTS <= "10001110";
					when others => SEGMENTS <= "00000000";
				end case;
			end if;
		end if;
	end process;

end Behavioral;

