----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:11:29 03/10/2019 
-- Design Name: 
-- Module Name:    SingleBinFFT - Behavioral 
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
use ieee.numeric_std.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity SingleBinFFT is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           NEW_SAMPLE : in  STD_LOGIC;
           DATA : in  STD_LOGIC_VECTOR (13 downto 0);
           NPOINTS : in  STD_LOGIC_VECTOR (31 downto 0);
           WINDOW_COEFF : in  STD_LOGIC_VECTOR (15 downto 0);
           WINDOW_ADDRESS : inout  STD_LOGIC_VECTOR (15 downto 0);
           WINDOW_INC_DENOM : in  STD_LOGIC_VECTOR (15 downto 0);
           BUSY : out  STD_LOGIC;
           OUT_REAL : out  STD_LOGIC_VECTOR (63 downto 0);
           OUT_IMAG : out  STD_LOGIC_VECTOR (63 downto 0));
end SingleBinFFT;

architecture Behavioral of SingleBinFFT is
	signal window_address_cnt : unsigned(15 downto 0);
	signal sum_real : signed(63 downto 0);
	signal sum_imag : signed(63 downto 0);
	signal pnt_cnt : unsigned(31 downto 0);
	signal pipe_level : unsigned(0 downto 0);
	
	signal mult_a : STD_LOGIC_VECTOR(13 downto 0);
	signal mult_b : STD_LOGIC_VECTOR(15 downto 0);
	signal windowed_data : STD_LOGIC_VECTOR(29 downto 0);
	
	COMPONENT WindowingMult
	  PORT (
		 clk : IN STD_LOGIC;
		 a : IN STD_LOGIC_VECTOR(13 DOWNTO 0);
		 b : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		 sclr : IN STD_LOGIC;
		 p : OUT STD_LOGIC_VECTOR(29 DOWNTO 0)
	  );
	END COMPONENT;
begin
	windowing_mult : WindowingMult
	  PORT MAP (
		 clk => CLK,
		 a => mult_a,
		 b => mult_b,
		 sclr => RESET,
		 p => windowed_data
	  );

	process(clk)
	begin
		if rising_edge(clk) then
			if RESET = '1' then
				pnt_cnt <= to_unsigned(0, 32);
				OUT_REAL <= (others => '0');
				OUT_IMAG <= (others => '0');
				window_address_cnt <= to_unsigned(0, 16);
				WINDOW_ADDRESS <= (others => '0');
				BUSY <= '0';
				mult_a <= (others => '0');
				mult_b <= (others => '0');
				pipe_level<= to_unsigned(0, 1);
				sum_real <= to_signed(0, 64);
				sum_imag <= to_signed(0, 64);
			else
				if pnt_cnt < unsigned(NPOINTS) then 
					BUSY <= '1';
				if NEW_SAMPLE = '1' then
					mult_a <= DATA;
					mult_b <= WINDOW_COEFF;
					-- advance window address
					if window_address_cnt < unsigned(WINDOW_INC_DENOM) then
						window_address_cnt <= window_address_cnt + 1;
					else
						window_address_cnt <= to_unsigned(0, 16);
						WINDOW_ADDRESS <= std_logic_vector( unsigned(WINDOW_ADDRESS) + 1 );
					end if;
					if pipe_level > 0 then
						-- advance complex vector and add input data
						sum_imag <= -sum_real;
						sum_real <= sum_imag + signed(windowed_data);
						pnt_cnt <= pnt_cnt + 1;
					else
						-- multiplier has no valid output yet
						pipe_level <= pipe_level + 1;
					end if;
				end if;
				else 
					BUSY <= '0';
					OUT_REAL <= std_logic_vector(sum_real);
					OUT_IMAG <= std_logic_vector(sum_imag);
				end if;
			end if;
		end if;
	end process;

end Behavioral;

