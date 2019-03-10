--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:33:40 03/09/2019
-- Design Name:   
-- Module Name:   /home/jan/Projekte/RFStuff/FPGA/ADC/ADCSync_test.vhd
-- Project Name:  ADC
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ADCSynchronizer
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
use ieee.numeric_std.all;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ADCSync_test IS
END ADCSync_test;
 
ARCHITECTURE behavior OF ADCSync_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ADCSynchronizer
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         ADC_CLK : IN  std_logic;
         ADC_DATA : IN  std_logic_vector(13 downto 0);
         DATA_OUT : OUT  std_logic_vector(13 downto 0);
         NEW_SAMPLE : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '1';
   signal ADC_CLK : std_logic := '0';
   signal ADC_DATA : std_logic_vector(13 downto 0) := (others => '0');

 	--Outputs
   signal DATA_OUT : std_logic_vector(13 downto 0);
   signal NEW_SAMPLE : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
   constant ADC_CLK_period : time := 40 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ADCSynchronizer PORT MAP (
          CLK => CLK,
          RESET => RESET,
          ADC_CLK => ADC_CLK,
          ADC_DATA => ADC_DATA,
          DATA_OUT => DATA_OUT,
          NEW_SAMPLE => NEW_SAMPLE
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
		wait for 2.7ns;
		ADC_DATA <= std_logic_vector(unsigned(ADC_DATA) + 1);
		wait for ADC_CLK_period/2 - 2.7ns;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_period*10;

      -- insert stimulus here 
		RESET <= '0';
		

      wait;
   end process;

END;
