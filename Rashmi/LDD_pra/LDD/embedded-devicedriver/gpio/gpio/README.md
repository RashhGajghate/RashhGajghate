### GPIO Framework in Kernel space (Experiment)

#### Prepare GPIO Initalization framework:

**case 1:** 

- Add printk's in init & exit functions and also add begin & end of probe function in  `drivers/gpio/gpio-omap.c`.
- Run `km-bbb-kernel-build.sh` script and generate images.
- Install kernel images in to target board using mmc (or) tftp (or) scp.
- Reboot target board and run dmesg command and verfiy printk results in kernel log. 
	
**Expected Results:**
- probe invokes 4 times becuase am3358 contains 4 gpio controllers.

**case 2:**

- Modify gpio1,2,3 compatiable name to `test-omap` in `arch/arm/boot/dts/am33xx.dtsi` file.
- Run below command to build device tree source code. 
  `$ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- dtbs`
- copy km-bbb-am335x.dtb file in to target board in /boot/dtbs/`uname -r`/
- Reboot target board and run dmesg and verify printk results in kernel log.

**Expected Results:**
- probe invokes only 1 time because am3358 soc contains 4 gpio controllers but in dtsi file name matches only GPIO0.

<img src="images/GPIO_Initalization_Framework2.jpg">

#### Prepare GPIO Operation framework:

- Enable printks in each and every function in `drivers/gpio/gpiolib.c` and `drivers/gpio/gpio-omap.c` files.
- Run `km-bbb-kernel-build.sh` script and generate images.
- Install kernel images in to target board using mmc (or) tftp (or) scp.
- Run `cat value` command in `/sys/class/gpio10` folder and run dmesg command and verfiy printk results in kernel log. 

<img src="images/GPIO_Operation_Framework2.jpg">
