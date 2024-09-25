@echo off

set elf=%1
set interface=cmsis-dap.cfg 

openocd -s "c:\Program Files\Raspberry Pi\Pico SDK v2.0.0\openocd\scripts" -f  interface\%interface%  -f target\rp2350.cfg -c "adapter speed 5000" 
