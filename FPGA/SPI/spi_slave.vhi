
-- VHDL Instantiation Created from source file spi_slave.vhd -- 21:33:27 03/22/2019
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT spi_slave
	PORT(
		SPI_CLK : IN std_logic;
		MOSI : IN std_logic;
		CS : IN std_logic;
		BUF_IN : IN std_logic;
		CLK : IN std_logic;          
		MISO : OUT std_logic;
		BUF_OUT : OUT std_logic;
		COMPLETE : OUT std_logic
		);
	END COMPONENT;

	Inst_spi_slave: spi_slave PORT MAP(
		SPI_CLK => ,
		MISO => ,
		MOSI => ,
		CS => ,
		BUF_OUT => ,
		BUF_IN => ,
		CLK => ,
		COMPLETE => 
	);


