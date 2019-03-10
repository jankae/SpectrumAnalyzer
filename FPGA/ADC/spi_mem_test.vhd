--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   21:36:09 03/06/2019
-- Design Name:   
-- Module Name:   /home/jan/Projekte/RFStuff/FPGA/1-example_led_3/spi_mem_test.vhd
-- Project Name:  top
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: spi_mem
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
 
ENTITY spi_mem_test IS
END spi_mem_test;
 
ARCHITECTURE behavior OF spi_mem_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT spi_mem
    PORT(
         clk : IN  std_logic;
         SPI_CLK : IN  std_logic;
         MISO : OUT  std_logic;
         MOSI : IN  std_logic;
         CS : IN  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal SPI_CLK : std_logic := '0';
   signal MOSI : std_logic := '0';
   signal CS : std_logic := '1';

 	--Outputs
   signal MISO : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
   constant SPI_CLK_period : time := 100 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: spi_mem PORT MAP (
          clk => clk,
          SPI_CLK => SPI_CLK,
          MISO => MISO,
          MOSI => MOSI,
          CS => CS
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 
   SPI_CLK_process :process
   begin
		SPI_CLK <= '0';
		wait for SPI_CLK_period/2;
		SPI_CLK <= '1';
		wait for SPI_CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;
		
		-- write 0x0F0F at address 0x000F
		CS <= '0';
		MOSI <= '1';
		wait for SPI_CLK_period;
		MOSI <= '0';
		wait for SPI_CLK_period*11;
		MOSI <= '1';
		wait for SPI_CLK_period*4;
		MOSI <= '0';
		wait for SPI_CLK_period*4;
		MOSI <= '1';
		wait for SPI_CLK_period*4;
		MOSI <= '0';
		wait for SPI_CLK_period*4;
		MOSI <= '1';
		wait for SPI_CLK_period*4;
		CS <= '1';
		
		wait for SPI_CLK_period*4;
		
		-- read address 0x000F
				CS <= '0';
		MOSI <= '0';
		wait for SPI_CLK_period;
		MOSI <= '0';
		wait for SPI_CLK_period*11;
		MOSI <= '0';
		wait for SPI_CLK_period*4;
		MOSI <= '0';
		wait for SPI_CLK_period*16;
		CS <= '1';

      -- insert stimulus here 

      wait;
   end process;

END;
