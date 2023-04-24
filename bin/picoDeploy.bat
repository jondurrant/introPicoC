@echo off

set elf=%1
set interface=cmsis-dap.cfg 

openscad -s “c:\Program Files\Raspberry Pi\Pico SDK v1.5.0\openocd\scripts” -f  interface\%interface%  -f target\rp2040.cfg -c "adapter speed 5000" -c "program %elf% verify reset exit"
