
# PlanAhead Launch Script for Post-Synthesis floorplanning, created by Project Navigator

create_project -name ADC -dir "/home/jan/Projekte/RFStuff/FPGA/ADC/planAhead_run_3" -part xc6slx9tqg144-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "/home/jan/Projekte/RFStuff/FPGA/ADC/IF_analysis.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {/home/jan/Projekte/RFStuff/FPGA/ADC} {ipcore_dir} }
add_files [list {ipcore_dir/WindowingMult.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/spi.ncf}] -fileset [get_property constrset [current_run]]
add_files [list {ipcore_dir/mult.ncf}] -fileset [get_property constrset [current_run]]
set_property target_constrs_file "IF_analysis.ucf" [current_fileset -constrset]
add_files [list {IF_analysis.ucf}] -fileset [get_property constrset [current_run]]
link_design
