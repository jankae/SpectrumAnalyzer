
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name ADC -dir "/home/jan/Projekte/RFStuff/FPGA/ADC/planAhead_run_2" -part xc6slx9tqg144-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "IF_analysis.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {ipcore_dir/PLL.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {ipcore_dir/spi.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {ipcore_dir/WindowingMult.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
add_files [list {ipcore_dir/WindowingMult.ngc}]
set hdlfile [add_files [list {spi.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {SingleBinFFT.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
add_files [list {ipcore_dir/spi.ngc}]
set hdlfile [add_files [list {ADCSynchronizer.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {IF_analysis.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set_property top IF_analysis $srcset
add_files [list {IF_analysis.ucf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/WindowingMult.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/spi.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/mult.ncf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc6slx9tqg144-3
