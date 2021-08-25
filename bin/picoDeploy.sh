#!/bin/bash

echo Using openocd to deply ${1}
cd ${HOME}/pico/openocd/tcl
openocd -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg -c "program ${1} verify reset exit"
echo Deployed
arm-none-eabi-size ${1}

