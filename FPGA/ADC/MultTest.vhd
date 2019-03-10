--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:53:51 03/03/2019
-- Design Name:   
-- Module Name:   /home/jan/Projekte/RFStuff/FPGA/1-example_led_3/MultTest.vhd
-- Project Name:  top
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: mult
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
 
ENTITY MultTest IS
END MultTest;
 
ARCHITECTURE behavior OF MultTest IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mult
    PORT(
         ar : IN  std_logic_vector(31 downto 0);
         ai : IN  std_logic_vector(31 downto 0);
         br : IN  std_logic_vector(31 downto 0);
         bi : IN  std_logic_vector(31 downto 0);
         clk : IN  std_logic;
         pr : OUT  std_logic_vector(31 downto 0);
         pi : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal ar : std_logic_vector(31 downto 0) := (others => '0');
   signal ai : std_logic_vector(31 downto 0) := (others => '0');
   signal br : std_logic_vector(31 downto 0) := (others => '0');
   signal bi : std_logic_vector(31 downto 0) := (others => '0');
   signal clk : std_logic := '0';

 	--Outputs
   signal pr : std_logic_vector(31 downto 0);
   signal pi : std_logic_vector(31 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mult PORT MAP (
          ar => ar,
          ai => ai,
          br => br,
          bi => bi,
          clk => clk,
          pr => pr,
          pi => pi
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;

      -- insert stimulus here
		ar <= "01000000000000000000000000000000";
		ai <= "00000000000000000000000000000000";
		br <= "01000000000000000000000000000000";
		bi <= "00000000000000000000000000000000";
		
		wait for clk_period*20;
		ar <= "01111111111111111111111111111111";
		ai <= "00000000000000000000000000000000";
		br <= "01111111111111111111111111111111";
		bi <= "00000000000000000000000000000000";
		wait for clk_period;
		ar <= "10000000000000000000000000000000";
		ai <= "00000000000000000000000000000000";
		br <= "10000000000000000000000000000000";
		bi <= "00000000000000000000000000000000";
		wait for clk_period;
		ar <= "11111111111111111111111111111111";
		ai <= "00000000000000000000000000000000";
		br <= "10000000000000000000000000000000";
		bi <= "00000000000000000000000000000000";
		wait for clk_period;
		ar <= "01111111111111111111111111111111";
		ai <= "00000000000000000000000000000000";
		br <= "01000000000000000000000000000000";
		bi <= "00000000000000000000000000000000";

		wait for clk_period*30;
      wait;
   end process;

END;
