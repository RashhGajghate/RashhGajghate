obj-m := gpio-thread.o 
obj-m += gpio-switch.o 

all:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/${USER}/KM_GITHUB/beagleboneblack-kernel M=`pwd` modules
clean:
	make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -C /home/${USER}/KM_GITHUB/beagleboneblack-kernel M=`pwd` clean

