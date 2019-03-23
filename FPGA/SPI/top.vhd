----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:17:27 03/22/2019 
-- Design Name: 
-- Module Name:    top - Behavioral 
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

entity top is
    Port ( CLK : in  STD_LOGIC;
           SEGMENTS : out  STD_LOGIC_VECTOR (7 downto 0);
           DIGITS : out  STD_LOGIC_VECTOR (3 downto 0);
			  SPI_CLK : in  STD_LOGIC;
           MOSI : in  STD_LOGIC;
           MISO : out  STD_LOGIC;
           CS : in  STD_LOGIC;
			  LED1 : out STD_LOGIC;
			  LED2 : out STD_LOGIC);
end top;

architecture Behavioral of top is
	COMPONENT display
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		DATA : IN std_logic_vector(15 downto 0);          
		DIGITS : OUT std_logic_vector(3 downto 0);
		SEGMENTS : OUT std_logic_vector(7 downto 0)
		);
	END COMPONENT;
	COMPONENT spi_slave
	generic (W : integer);
	PORT(
		SPI_CLK : IN std_logic;
		MOSI : IN std_logic;
		CS : IN std_logic;
		BUF_IN : IN std_logic_vector (W-1 downto 0);
		CLK : IN std_logic;          
		MISO : OUT std_logic;
		BUF_OUT : OUT std_logic_vector (W-1 downto 0);
		COMPLETE : OUT std_logic;
		RISING_TOGGLE : inout STD_LOGIC;
		FALLING_TOGGLE : inout STD_LOGIC
		);
	END COMPONENT;
	
	signal display_data : STD_LOGIC_VECTOR (15 downto 0);
	signal spi_data : STD_LOGIC_VECTOR (15 downto 0);
	signal spi_complete : STD_LOGIC;
	signal toggle1 : STD_LOGIC;
	signal toggle2 : STD_LOGIC;
begin
	Inst_display: display PORT MAP(
		CLK => CLK,
		RESET => '0',
		DATA => display_data,
		DIGITS => DIGITS,
		SEGMENTS => SEGMENTS
	);
	Inst_spi_slave: spi_slave
	GENERIC MAP (W => 16)
	PORT MAP(
		SPI_CLK => SPI_CLK,
		MISO => MISO,
		MOSI => MOSI,
		CS => CS,
		BUF_OUT => spi_data,
		BUF_IN => x"F0A5",
		CLK => CLK,
		COMPLETE => spi_complete,
		RISING_TOGGLE => toggle1,
		FALLING_TOGGLE => toggle2
	);
	
	LED1 <= toggle1;
	LED2 <= toggle2;
	
	process(CLK)
	begin
		if rising_edge(CLK) then
			if spi_complete = '1' then
				display_data <= spi_data;
			end if;
		end if;
	end process;

end Behavioral;

