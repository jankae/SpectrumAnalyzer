----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:16:08 03/20/2019 
-- Design Name: 
-- Module Name:    ADC_prescaler - Behavioral 
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
use IEEE.numeric_std.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ADC_prescaler is
    Port ( CLK : in  STD_LOGIC;
           ADC_CLK : in  STD_LOGIC;
           ADC_IN : in  STD_LOGIC_VECTOR (13 downto 0);
           LED : out  STD_LOGIC);
end ADC_prescaler;

architecture Behavioral of ADC_prescaler is
	component PLL
	port(-- Clock in ports
		CLK_IN1           : in     std_logic;
		-- Clock out ports
		CLK_OUT1          : out    std_logic;
		-- Status and control signals
		RESET             : in     std_logic;
		LOCKED            : out    std_logic
	);
	end component;
		COMPONENT ADCSynchronizer
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		ADC_CLK : IN std_logic;
		ADC_DATA : IN std_logic_vector(13 downto 0);          
		DATA_OUT : OUT std_logic_vector(13 downto 0);
		NEW_SAMPLE : OUT std_logic
		);
	END COMPONENT;
	signal new_sample : STD_LOGIC;
	signal counter : integer range 0 to 25;
	signal led_buf : STD_LOGIC;
	signal clk_100 : STD_LOGIC;
	signal locked : STD_LOGIC;
begin
	your_instance_name : PLL
	port map(-- Clock in ports
		CLK_IN1 => CLK,
		-- Clock out ports
		CLK_OUT1 => clk_100,
		-- Status and control signals
		RESET  => '0',
		LOCKED => locked
	);
	ADC_input : ADCSynchronizer
	PORT MAP(
		CLK => clk_100,
		RESET => '0',
		ADC_CLK => ADC_CLK,
		ADC_DATA => ADC_IN,
		DATA_OUT => open,
		NEW_SAMPLE => new_sample
	);
	LED <= led_buf;
 	process(clk_100)
	begin
		if rising_edge(clk_100) then
			if locked = '0' then 
				counter <= 0;
				led_buf <= '0';
			elsif new_sample = '1' then
				if counter = 24 then
					counter <= 0;
					led_buf<= not led_buf;
				else
					counter <= counter + 1;
				end if;
			end if;
		end if;
	end process;

end Behavioral;

