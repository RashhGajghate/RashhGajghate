#!/bin/bash

if [ -d /sys/class/gpio/gpio10 ] ; then
	echo " gpio10 dir exist"
else
	echo 10 > /sys/class/gpio/export
	echo out > /sys/class/gpio/gpio10/direction
fi
x=10
while [ "$x" -ne 0 ]
do
	echo 1 > /sys/class/gpio/gpio10/value
	sleep 1
	echo 0 > /sys/class/gpio/gpio10/value
	sleep 1
	x=$(($x-1))
done
