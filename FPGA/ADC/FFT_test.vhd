--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:53:01 03/10/2019
-- Design Name:   
-- Module Name:   /home/jan/Projekte/RFStuff/FPGA/ADC/FFT_test.vhd
-- Project Name:  ADC
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: SingleBinFFT
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
 
ENTITY FFT_test IS
END FFT_test;
 
ARCHITECTURE behavior OF FFT_test IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT SingleBinFFT
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         NEW_SAMPLE : IN  std_logic;
         DATA : IN  std_logic_vector(13 downto 0);
         NPOINTS : IN  std_logic_vector(31 downto 0);
         WINDOW_COEFF : IN  std_logic_vector(15 downto 0);
         WINDOW_ADDRESS : INOUT  std_logic_vector(15 downto 0);
         WINDOW_INC_DENOM : IN  std_logic_vector(15 downto 0);
         BUSY : OUT  std_logic;
         OUT_REAL : OUT  std_logic_vector(63 downto 0);
         OUT_IMAG : OUT  std_logic_vector(63 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '1';
   signal NEW_SAMPLE : std_logic := '0';
   signal DATA : std_logic_vector(13 downto 0) := (others => '0');
   signal NPOINTS : std_logic_vector(31 downto 0) := (others => '0');
   signal WINDOW_COEFF : std_logic_vector(15 downto 0) := (others => '0');
   signal WINDOW_INC_DENOM : std_logic_vector(15 downto 0) := (others => '0');

	--BiDirs
   signal WINDOW_ADDRESS : std_logic_vector(15 downto 0);

 	--Outputs
   signal BUSY : std_logic;
   signal OUT_REAL : std_logic_vector(63 downto 0);
   signal OUT_IMAG : std_logic_vector(63 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: SingleBinFFT PORT MAP (
          CLK => CLK,
          RESET => RESET,
          NEW_SAMPLE => NEW_SAMPLE,
          DATA => DATA,
          NPOINTS => NPOINTS,
          WINDOW_COEFF => WINDOW_COEFF,
          WINDOW_ADDRESS => WINDOW_ADDRESS,
          WINDOW_INC_DENOM => WINDOW_INC_DENOM,
          BUSY => BUSY,
          OUT_REAL => OUT_REAL,
          OUT_IMAG => OUT_IMAG
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_period*10;

      -- insert stimulus here 
		NPOINTS <= std_logic_vector(to_unsigned(4, 32));
		WINDOW_INC_DENOM <= std_logic_vector(to_unsigned(0, 16));
		WINDOW_COEFF <= "1000000000000000";
		DATA <= "00000000000001";
		wait for CLK_period*4;
		RESET <= '0';
		
		wait for CLK_period*4;
		NEW_SAMPLE <= '1';
		wait for CLK_period;
		NEW_SAMPLE <= '0';
		DATA <= DATA(12 downto 0) & '0';
		wait for CLK_period*3;
		NEW_SAMPLE <= '1';
		wait for CLK_period;
		NEW_SAMPLE <= '0';
		DATA <= DATA(12 downto 0) & '0';
		wait for CLK_period*3;
		NEW_SAMPLE <= '1';
		wait for CLK_period;
		NEW_SAMPLE <= '0';
		DATA <= DATA(12 downto 0) & '0';
		wait for CLK_period*3;
		NEW_SAMPLE <= '1';
		wait for CLK_period;
		NEW_SAMPLE <= '0';
		DATA <= DATA(12 downto 0) & '0';
		wait for CLK_period*3;
		NEW_SAMPLE <= '1';
		wait for CLK_period;
		NEW_SAMPLE <= '0';
		DATA <= DATA(12 downto 0) & '0';
		wait for CLK_period*3;
		NEW_SAMPLE <= '1';
		wait for CLK_period;
		NEW_SAMPLE <= '0';
		DATA <= DATA(12 downto 0) & '0';
		
      wait;
   end process;

END;
