----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:14:17 03/05/2019 
-- Design Name: 
-- Module Name:    spi_slave - Behavioral 
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

entity spi_slave is
	generic ( W : integer);
    Port ( SPI_CLK : in  STD_LOGIC;
           MISO : out  STD_LOGIC;
           MOSI : in  STD_LOGIC;
           CS : in  STD_LOGIC;
			  BUF_OUT : out STD_LOGIC_VECTOR (W-1 downto 0) := (others => '0');
			  BUF_IN : in STD_LOGIC_VECTOR (W-1 downto 0);
           CLK : in  STD_LOGIC;
			  COMPLETE : out STD_LOGIC);
end spi_slave;

architecture Behavioral of spi_slave is
	signal miso_buffer : STD_LOGIC_VECTOR (W-1 downto 0);
	signal mosi_buffer : STD_LOGIC_VECTOR (W-1 downto 0);
	signal next_complete : STD_LOGIC;
	signal spiSR : STD_LOGIC_VECTOR (1 downto 0);
begin

	MISO <= 'Z' when CS = '1' else
				miso_buffer(W-1) when CS = '0';

	process(CLK)
	begin
		if rising_edge(CLK) then
			spiSR <= spiSR(0) & SPI_CLK;
			if CS = '1' then
				-- reset state machine
				miso_buffer <= BUF_IN;
				mosi_buffer <= (W-1 downto 1 => '0') & '1';
				--MISO <= 'Z';
				COMPLETE <= '0';
				next_complete <= '0';
				spiSR <= "00";
			else
				--MISO <= miso_buffer(W-1);
				if spiSR = "01" then
					-- rising edge
					if mosi_buffer(W-1) = '1' then
						-- this was the last bit
						next_complete <= '1';
						BUF_OUT <= mosi_buffer(W-2 downto 0) & MOSI;
						mosi_buffer <= (W-1 downto 1 => '0') & '1';
					else
						mosi_buffer <= mosi_buffer(W-2 downto 0) & MOSI;
					end if;
				end if;
				if spiSR = "10" then
					-- falling edge
					if mosi_buffer = (W-2 downto 0 => '0') & '1' then
						miso_buffer <= BUF_IN;
					else
						miso_buffer <= miso_buffer(W-2 downto 0) & '0';
					end if;
				end if;
				if next_complete = '1' then
					next_complete <= '0';
					COMPLETE <= '1';
				else
					COMPLETE <= '0';
				end if;
			end if;
		end if;
	end process;

end Behavioral;

