--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:26:49 03/13/2019
-- Design Name:   
-- Module Name:   /home/jan/Projekte/RFStuff/FPGA/ADC/IF_analysis_test.vhd
-- Project Name:  ADC
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: IF_analysis
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY IF_analysis_test IS
END IF_analysis_test;
 
ARCHITECTURE behavior OF IF_analysis_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT IF_analysis
    PORT(
         CLK : IN  std_logic;
         SPI_CLK : IN  std_logic;
         MOSI : IN  std_logic;
         MISO : OUT  std_logic;
         CS : IN  std_logic;
         ADC_IN : IN  std_logic_vector(13 downto 0);
         ADC_CLK : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal SPI_CLK : std_logic := '0';
   signal MOSI : std_logic := '0';
   signal CS : std_logic := '1';
   signal ADC_IN : std_logic_vector(13 downto 0) := (others => '0');
   signal ADC_CLK : std_logic := '0';

 	--Outputs
   signal MISO : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 20.833333333 ns;
   constant SPI_CLK_period : time := 100 ns;
   constant ADC_CLK_period : time := 40 ns;
 
BEGIN


	-- Instantiate the Unit Under Test (UUT)
   uut: IF_analysis PORT MAP (
          CLK => CLK,
          SPI_CLK => SPI_CLK,
          MOSI => MOSI,
          MISO => MISO,
          CS => CS,
          ADC_IN => ADC_IN,
          ADC_CLK => ADC_CLK
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
  
   ADC_CLK_process :process
   begin
		ADC_CLK <= '0';
		wait for ADC_CLK_period/2;
		ADC_CLK <= '1';
		wait for ADC_CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
		procedure SPI(addr, data : std_logic_vector(15 downto 0)) is
		begin
			CS <= '0';
				for k in 15 downto 0 loop
				MOSI <= addr(k);
				wait for SPI_CLK_period/2;
				SPI_CLK <= '1';
				wait for SPI_CLK_period/2;
				SPI_CLK <= '0';
			end loop;
			for k in 15 downto 0 loop
				MOSI <= data(k);
				wait for SPI_CLK_period/2;
				SPI_CLK <= '1';
				wait for SPI_CLK_period/2;
				SPI_CLK <= '0';
			end loop;
			CS <= '1';
		end procedure SPI;
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_period*10;
		ADC_IN <= "01000000000000";

      -- insert stimulus here
		-- increment window address every 2 sample
		SPI(x"8001", x"0001");
		wait for SPI_CLK_period*2;
		SPI(x"0001", x"0000");
		wait for SPI_CLK_period*2;
		-- 4 FFT points
		SPI(x"8002", x"0004");
		wait for SPI_CLK_period*2;
		SPI(x"8003", x"0000");
		wait for SPI_CLK_period*2;
		-- start FFT
		SPI(x"8000", x"0001");
		wait for SPI_CLK_period*2;
		
      wait;
   end process;

END;
