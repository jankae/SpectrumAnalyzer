
-- VHDL Instantiation Created from source file SingleBinFFT.vhd -- 13:28:29 03/10/2019
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT SingleBinFFT
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		NEW_SAMPLE : IN std_logic;
		DATA : IN std_logic_vector(13 downto 0);
		NPOINTS : IN std_logic_vector(31 downto 0);
		WINDOW_COEFF : IN std_logic_vector(15 downto 0);
		WINDOW_INC_NUM : IN std_logic_vector(15 downto 0);
		WINDOW_INC_DENOM : IN std_logic_vector(15 downto 0);          
		WINDOW_ADDRESS : OUT std_logic_vector(15 downto 0);
		BUSY : OUT std_logic;
		OUT_REAL : OUT std_logic_vector(63 downto 0);
		OUT_IMAG : OUT std_logic_vector(63 downto 0)
		);
	END COMPONENT;

	Inst_SingleBinFFT: SingleBinFFT PORT MAP(
		CLK => ,
		RESET => ,
		NEW_SAMPLE => ,
		DATA => ,
		NPOINTS => ,
		WINDOW_COEFF => ,
		WINDOW_ADDRESS => ,
		WINDOW_INC_NUM => ,
		WINDOW_INC_DENOM => ,
		BUSY => ,
		OUT_REAL => ,
		OUT_IMAG => 
	);


