#!/bin/sh
openocd -s ${HOME}/pico/openocd/tcl/ -f interface/raspberrypi-swd.cfg -f target/rp2040.cfg
