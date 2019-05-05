----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:32:20 03/12/2019 
-- Design Name: 
-- Module Name:    IF_analysis - Behavioral 
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

entity IF_analysis is
    Port ( CLK : in  STD_LOGIC;
           SPI_CLK : in  STD_LOGIC;
           MOSI : in  STD_LOGIC;
           MISO : out  STD_LOGIC;
           CS : in  STD_LOGIC;
           ADC_IN : in  STD_LOGIC_VECTOR (13 downto 0);
           ADC_CLK : in  STD_LOGIC;
			  LED1 : out STD_LOGIC;
			  LED2 : out STD_LOGIC;
			  LED3 : inout STD_LOGIC;
			  LED4 : out STD_LOGIC);
end IF_analysis;

architecture Behavioral of IF_analysis is
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
		 addra : IN STD_LOGIC_VECTOR(12 DOWNTO 0);
		 dina : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		 clkb : IN STD_LOGIC;
		 enb : IN STD_LOGIC;
		 addrb : IN STD_LOGIC_VECTOR(12 DOWNTO 0);
		 doutb : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	);
	END COMPONENT;
	
	COMPONENT SingleBinFFT
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		NEW_SAMPLE : IN std_logic;
		DATA : IN std_logic_vector(13 downto 0);
		NPOINTS : IN std_logic_vector(31 downto 0);
		WINDOW_COEFF : IN std_logic_vector(15 downto 0);
		WINDOW_INC_DENOM : IN std_logic_vector(15 downto 0);    
		WINDOW_ADDRESS : INOUT std_logic_vector(15 downto 0);      
		BUSY : OUT std_logic;
		OUT_REAL : OUT std_logic_vector(63 downto 0);
		OUT_IMAG : OUT std_logic_vector(63 downto 0)
		);
	END COMPONENT;
	
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
	
	signal clk_100 : std_logic;
	
	signal first : std_logic := '0';
	signal write_not_read : std_logic := '0';
	signal mem_address : std_logic_vector(14 downto 0) := (others => '0');
	signal mem_in : std_logic_vector(15 downto 0) := (others => '0');
	signal mem_write : std_logic_vector(0 downto 0) := (others => '0');
	
	signal spi_out : std_logic_vector(15 downto 0);
	signal spi_in : std_logic_vector(15 downto 0);
	signal spi_complete : std_logic := '0';
	
	signal window_coeff : std_logic_vector(15 downto 0);
	signal window_inc : std_logic_vector(15 downto 0);
	signal window_address : std_logic_vector(15 downto 0);
	signal fft_points : std_logic_vector(31 downto 0);
	
	signal out_real : std_logic_vector(63 downto 0);
	signal out_imag : std_logic_vector(63 downto 0);
	
	signal fft_active : std_logic := '0';
	signal fft_busy : std_logic;
	
	signal adc_data : std_logic_vector(13 downto 0);
	signal adc_new : std_logic;
	
	signal adc_timeout : unsigned(0 to 100);
begin

	LED1 <= not fft_active;
	LED2 <= not fft_busy;
	
	your_instance_name : PLL
	port map(-- Clock in ports
		CLK_IN1 => CLK,
		-- Clock out ports
		CLK_OUT1 => clk_100,
		-- Status and control signals
		RESET  => '0',
		LOCKED => LED4
	);
--	clk_100 <= CLK;

	ADC_input : ADCSynchronizer
	PORT MAP(
		CLK => clk_100,
		RESET => '0',
		ADC_CLK => ADC_CLK,
		ADC_DATA => ADC_IN,
		DATA_OUT => adc_data,
		NEW_SAMPLE => adc_new
	);
	
	FFT: SingleBinFFT PORT MAP(
		CLK => clk_100,
		RESET => fft_active,
		NEW_SAMPLE => adc_new,
		DATA => adc_data,
		NPOINTS => fft_points,
		WINDOW_COEFF => window_coeff,
		WINDOW_ADDRESS => window_address,
		WINDOW_INC_DENOM => window_inc,
		BUSY => fft_busy,
		OUT_REAL => out_real,
		OUT_IMAG => out_imag
	);
	
	SPI_interface : spi_slave 
	GENERIC MAP(W => 16)
	PORT MAP(
		SPI_CLK => SPI_CLK,
		MISO => MISO,
		MOSI => MOSI,
		CS => CS,
		BUF_OUT => spi_out,
		BUF_IN => spi_in,
		CLK => clk_100,
		COMPLETE => spi_complete
	);

	memory : spi
   PORT MAP (
		clka => clk_100,
		wea => mem_write,
		addra => mem_address(12 downto 0),
		dina => mem_in,
		clkb => clk_100,
		enb => '1',
		addrb => window_address(12 downto 0),
		doutb => window_coeff
  );


 	process(clk_100)
	begin
		if rising_edge(clk_100) then
			if adc_new = '1' then
				LED3 <= '0';
				adc_timeout <= (others => '0');
			else
				if adc_timeout < 100 then
					adc_timeout <= adc_timeout + 1;
				else
					LED3 <= '1';
				end if;
			end if;
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
							if mem_address(14) = '1' then
								-- it is a write to the window memory
								mem_in <= spi_out;
								mem_write <= "1";
							else
								if mem_address = "000000000000000" then
									-- write to the status word
									fft_active <= spi_out(0);
								elsif mem_address = "000000000000001" then
									-- write window increment
									window_inc <= spi_out;
								elsif mem_address = "000000000000010" then
									-- write number of points low word
									fft_points <= fft_points(31 downto 16) & spi_out;
								elsif mem_address = "000000000000011" then
									-- write number of points high word
									fft_points <= spi_out & fft_points(15 downto 0);
								end if;
							end if;
						end if;
						if write_not_read = '0' or mem_address(14) = '0' then
							-- increment address immediately if not accessing block RAM
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
			-- assign spi_in dependent on mem_address
			case mem_address is
				when "000000000000000" => spi_in <= "00000000000000" & fft_busy & fft_active;
				when "000000000000001" => spi_in <= window_inc;
				when "000000000000010" => spi_in <= fft_points(15 downto 0);
				when "000000000000011" => spi_in <= fft_points(31 downto 16);
				when "000000000000100" => spi_in <= out_real(15 downto 0);
				when "000000000000101" => spi_in <= out_real(31 downto 16);
				when "000000000000110" => spi_in <= out_real(47 downto 32);
				when "000000000000111" => spi_in <= out_real(63 downto 48);
				when "000000000001000" => spi_in <= out_imag(15 downto 0);
				when "000000000001001" => spi_in <= out_imag(31 downto 16);
				when "000000000001010" => spi_in <= out_imag(47 downto 32);
				when "000000000001011" => spi_in <= out_imag(63 downto 48);
				when others => spi_in <= (others => '0');
			end case;
		end if;
	end process;


end Behavioral;

