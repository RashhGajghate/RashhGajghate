obj-m := q1.o

all:
	make -C /lib/modules/`uname -r`/build M=`pwd` modules
clean :
	make -C /lib/modules/`uname -r`/build M=`pwd` clean
install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_intall

