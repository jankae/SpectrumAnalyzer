----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:41:09 03/05/2019 
-- Design Name: 
-- Module Name:    spi_mem - Behavioral 
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

entity spi_mem is
    Port ( clk : in  STD_LOGIC;
           SPI_CLK : in  STD_LOGIC;
           MISO : inout  STD_LOGIC;
           MOSI : in  STD_LOGIC;
           CS : in  STD_LOGIC;
			  LED1 : INOUT STD_LOGIC;
			  LED2 : INOUT STD_LOGIC;
			  LED3 : INOUT STD_LOGIC;
			  LED4 : INOUT STD_LOGIC);
end spi_mem;

architecture Behavioral of spi_mem is
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
		COMPLETE : OUT std_logic
		);
	END COMPONENT;

	COMPONENT spi
  PORT (
    clka : IN STD_LOGIC;
    wea : IN STD_LOGIC_VECTOR(0 DOWNTO 0);
    addra : IN STD_LOGIC_VECTOR(9 DOWNTO 0);
    dina : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
    clkb : IN STD_LOGIC;
    enb : IN STD_LOGIC;
    addrb : IN STD_LOGIC_VECTOR(9 DOWNTO 0);
    doutb : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
  );
	END COMPONENT;
	
	signal first : std_logic := '0';
	signal write_not_read : std_logic := '0';
	signal mem_address : std_logic_vector(14 downto 0) := (others => '0');
	signal mem_in : std_logic_vector(15 downto 0) := (others => '0');
--	signal mem_out : std_logic_vector(15 downto 0);
	signal mem_write : std_logic_vector(0 downto 0) := (others => '0');
	signal spi_out : std_logic_vector(15 downto 0);
	signal spi_in : std_logic_vector(15 downto 0);
	signal spi_complete : std_logic := '0';
begin

	Inst_spi_slave: spi_slave 
	GENERIC MAP(W => 16)
	PORT MAP(
		SPI_CLK => SPI_CLK,
		MISO => MISO,
		MOSI => MOSI,
		CS => CS,
		BUF_OUT => spi_out,
		BUF_IN => spi_in,
		CLK => clk,
		COMPLETE => spi_complete
	);
	
	your_instance_name : spi
  PORT MAP (
    clka => clk,
    wea => mem_write,
    addra => mem_address(9 downto 0),
    dina => mem_in,
    clkb => clk,
    enb => '1',
    addrb => mem_address(9 downto 0),
    doutb => spi_in
  );
  
	LED1 <= SPI_CLK;
	LED2 <= CS;
	LED3 <= MOSI;
	LED4 <= MISO;
  
  	process(CLK)
	begin
		if rising_edge(CLK) then
			if CS = '1' then
				first <= '1';
				mem_address <= "000000000000000";
				mem_write <= "0";
				mem_in <= (others => '0');
			else
				if spi_complete = '1' then
					if first = '1' then
						write_not_read <= spi_out(15);
						mem_address <= spi_out(14 downto 0);
						first <= '0';
					else
						if write_not_read = '1' then
							mem_in <= spi_out;
							mem_write <= "1";
						else
							-- increment address immediately if reading
							mem_address <= std_logic_vector(unsigned(mem_address) + 1);
						end if;
					end if;
				end if;
				if mem_write = "1" then
					mem_write <= "0";
					-- increment address after write
					mem_address <= std_logic_vector(unsigned(mem_address) + 1);
				end if;
			end if;
		end if;
	end process;

end Behavioral;

