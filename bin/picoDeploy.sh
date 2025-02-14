#!/bin/bash

if [ X${PICO_SWD} == X ]
then
	echo "PICO_SWD is not. Defaulting to DEBUGPROBE"
    export PICO_SWD="DEBUGPROBE"
fi

if [[ $# -gt 0 ]]
then
   elf=`realpath ${1}`
   echo Case 1
else
   if [ -f src/*.elf ]
   then
      elf=`realpath src/*.elf`
      echo Case 2
   fi
   if [ -f *.elf ]
   then
      elf=`realpath *.elf`
      echo Case 3
   fi
fi

echo "Using openocd interface ${PICO_SWD} to flash ${elf}"

interface=cmsis-dap.cfg
speed=5000
target=rp2040.cfg
if [ ${PICO_SWD} == "RPI" ]
then
    speed=1000
#    interface=raspberrypi-swd.cfg
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
checkrp2350=`picotool info ${elf} | grep RP2350 | wc -l`
if [ ${checkrp2350} -gt 0 ]
then
    target=rp2350.cfg
fi


${HOME}/pico/openocd/src/openocd -s ${HOME}/pico/openocd/tcl/ -f interface/${interface} -f target/${target} -c "adapter speed ${speed}" -c "program ${elf} verify reset exit"
echo Deployed
arm-none-eabi-size ${elf}
