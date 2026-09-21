# 1. Change directory to the build folder to keep generated files contained
cd ../build

# 2. Create and map the logical 'work' library
vlib work
vmap work work

# 3. Compile the RTL and Testbench files
vlog ../rtl/vga_sync.v
vlog ../tb/vga_sync_tb.v

# 4. Load the simulation without optimization that might hide signals
vsim -voptargs=+acc work.vga_sync_tb

# 5. Add all testbench signals to the wave viewer
add wave -position insertpoint sim:/vga_sync_tb/*

# 6. Run the simulation for 17 milliseconds (slightly more than one 60Hz frame)
run 17ms

# 7. Zoom out the waveform view to see the full frame
wave zoom full