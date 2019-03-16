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
use IEEE.numeric_std.all;

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

	signal data_valid : STD_LOGIC_VECTOR(2 downto 0);
	signal data_synced : STD_LOGIC_VECTOR(2 downto 0);
	signal data : STD_LOGIC_VECTOR(W-1 downto 0);
	
	signal bit_cnt : STD_LOGIC_VECTOR(W-1 downto 0);
	signal cs_was_high : STD_LOGIC;
	signal cs_was_high_ack : STD_LOGIC;
begin

	process(CLK)
	begin
		if rising_edge(CLK) then
			if CS = '1' then
				cs_was_high <= '1';
			elsif cs_was_high_ack = '1' then
				cs_was_high <= '0';
			end if;
			data_valid(2 downto 1) <= data_valid(1 downto 0);
			if data_valid(2) = '1' then
				if data_synced(0) = '0' then
					BUF_OUT <= data;
					COMPLETE <= '1';
					data_synced(0) <= '1';
				else
					COMPLETE <= '0';
				end if;
			else
				COMPLETE <= '0';
				data_synced(0) <= '0';
			end if;
		end if;
	end process;

	MISO <= miso_buffer(W-1) when CS = '0' else 'Z';

	slave_in: process(SPI_CLK)
	begin
		if falling_edge(SPI_CLK) then
			data_synced(2 downto 1) <= data_synced(1 downto 0);
			if bit_cnt(W-1) = '1' then
				-- this was the last bit
				data_valid(0) <= '1';
				data <= mosi_buffer(W-2 downto 0) & MOSI;
			else
				if data_valid(0) = '1' and data_synced(2) = '1' then
					data_valid(0) <= '0';
				end if;
				mosi_buffer <= mosi_buffer(W-2 downto 0) & MOSI;
			end if;
		end if;
	end process;
	
	slave_out: process(SPI_CLK)
	begin
		if rising_edge(SPI_CLK) then
			if CS = '0' then 
				if cs_was_high = '1' then
					-- this is the first rising after CS low
					bit_cnt <= (W-1 downto 1 => '0') & '1';
					miso_buffer <= BUF_IN;
					cs_was_high_ack <= '1';
				else
					cs_was_high_ack <= '0';
					if bit_cnt(W-1) = '1' then
						bit_cnt <= (W-1 downto 1 => '0') & '1';
						miso_buffer <= BUF_IN;
					else
						bit_cnt <= bit_cnt(W-2 downto 0) & '0';
						miso_buffer <= miso_buffer(W-2 downto 0) & '0';
					end if;
				end if;
			end if;
		end if;
	end process;

end Behavioral;

