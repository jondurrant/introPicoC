#!/bin/sh

if [ X${PICO_SWD} == X ]
then
	echo "PICO_SWD is not defined. Defaulting to RPI"
    export PICO_SWD="RPI"
fi

elf=`realpath src/*.elf`
if [ X${1} != X ]
then
   elf=`realpath ${1}`
fi

echo "Using openocd interface ${PICO_SWD} to debug ${elf}"

interface=cmsis-dap.cfg
speed=5000
target=rp2350.cfg
if [ ${PICO_SWD} == "RPI" ]
then
	speed=1000
    #interface=raspberrypi-swd.cfg
    interface=raspberrypi-native.cfg
fi
if [ ${PICO_SWD} == "PICOPROBE" ]
then
    interface=picoprobe.cfg
fi
if [ ${PICO_SWD} == "DEBUGPROBE" ]
then
    interface=cmsis-dap.cfg
fi


${HOME}/pico/openocd/src/openocd -s ${HOME}/pico/openocd/tcl/ -f interface/${interface} -f target/${target} -c "adapter speed ${speed}"
