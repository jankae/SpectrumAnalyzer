
-- VHDL Instantiation Created from source file ADCSynchronizer.vhd -- 19:44:23 03/12/2019
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

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

	Inst_ADCSynchronizer: ADCSynchronizer PORT MAP(
		CLK => ,
		RESET => ,
		ADC_CLK => ,
		ADC_DATA => ,
		DATA_OUT => ,
		NEW_SAMPLE => 
	);


