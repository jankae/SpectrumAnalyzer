----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:03:00 03/03/2019 
-- Design Name: 
-- Module Name:    vga - Behavioral 
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

entity vga is
    Port ( CLK : in  STD_LOGIC;
           LED1, LED2, LED3, LED4 : inout  STD_LOGIC;
           V_SYNC : out  STD_LOGIC;
           H_SYNC : out  STD_LOGIC;
           V_R : out  STD_LOGIC_VECTOR (4 downto 0);
           V_G : out  STD_LOGIC_VECTOR (5 downto 0);
           V_B : out  STD_LOGIC_VECTOR (4 downto 0));
end vga;



architecture rtl of vga is

  component PLL
  port (RESET, CLK_IN1 : in std_logic;
			CLK_OUT1, LOCKED : out std_logic);
  end component;

	signal clk_out : std_logic;
	signal h_cnt : integer range 0 to 1056 := 0;
	signal v_cnt : integer range 0 to 627 := 0;
	signal locked : std_logic;
begin
	PLL1: PLL port map('0', CLK, clk_out, locked);
	
	LED2 <= '1';
	LED3 <= '1';
	LED4 <= not locked;

	process(h_cnt)
	begin
		case h_cnt is
			when 0 to 127 => H_SYNC <= '1';
			when others => H_SYNC <= '0';
		end case;
	end process;
	
	process(v_cnt)
	begin
		case v_cnt is
			when 0 to 3 => V_SYNC <= '1';
			when others => V_SYNC <= '0';
		end case;
	end process;
	
	process(v_cnt, h_cnt)
	begin
		case h_cnt is
			when 216 to 1015 =>
				case v_cnt is
					when 0 to 200 =>
						V_R <= "11111";
						V_G <= "000000";
						V_B <= "00000";
					when 201 to 400 =>
						V_R <= "00000";
						V_G <= "111111";
						V_B <= "00000";
					when others =>
						V_R <= "00000";
						V_G <= "000000";
						V_B <= "11111";
				end case;
			when others =>
				V_R <= "00000";
				V_G <= "000000";
				V_B <= "00000";
		end case;
	end process;

	process(clk_out)
	begin
		if rising_edge(clk_out) then
			if h_cnt < 1055 then
				h_cnt <= h_cnt + 1;
			else
				h_cnt <= 0;
				if v_cnt < 627 then
					v_cnt <= v_cnt + 1;
				else
					v_cnt <= 0;
					LED1 <= not LED1;
				end if;
			end if;
		end if;
	end process;

end rtl;

