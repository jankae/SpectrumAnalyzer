
-- VHDL Instantiation Created from source file spi_mem.vhd -- 21:35:38 03/06/2019
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT spi_mem
	PORT(
		clk : IN std_logic;
		SPI_CLK : IN std_logic;
		MOSI : IN std_logic;
		CS : IN std_logic;          
		MISO : OUT std_logic
		);
	END COMPONENT;

	Inst_spi_mem: spi_mem PORT MAP(
		clk => ,
		SPI_CLK => ,
		MISO => ,
		MOSI => ,
		CS => 
	);


