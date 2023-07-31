/***************************************************************************
 *      Organisation    : Kernel Masters, KPHB, Hyderabad, India.          *
 *      facebook page   : www.facebook.com/kernelmasters                   *
 *      Website         : www.kernelmasters.org                            *
 *  Conducting Workshops on - Embedded Linux & Device Drivers Training.    *
 *  -------------------------------------------------------------------    *
 *  Tel : 91-9949062828, Email : kernelmasters@gmail.com                   *    
 *                                                                         *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation. No warranty is attached; we cannot take *
 *   responsibility for errors or fitness for use.                         *
 ***************************************************************************/
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <linux/uaccess.h>

static int gpio_in = 11; // Par defaut : broche 10
module_param(gpio_in, int, 0644);

static dev_t          gpioinput_dev;
static struct cdev    gpioinput_cdev;
static struct class * gpioinput_class = NULL;

static int gpioinput_read(struct file * filp, char * buffer, size_t length, loff_t * offset);

static struct file_operations fops_gpioinput = {
    .owner   =  THIS_MODULE,
    .read    =  gpioinput_read,
  };

static int gpioinput_init (void)
{
  int err;

  if ((err = gpio_request(gpio_in, THIS_MODULE->name)) != 0) {
    return err;
  }

  if ((err = gpio_direction_input(gpio_in)) != 0) {
    gpio_free(gpio_in);
    return err;
  }

  if ((err = alloc_chrdev_region(& gpioinput_dev, 0, 1, THIS_MODULE->name)) < 0) {
    gpio_free(gpio_in);
    return err;
  }

  gpioinput_class = class_create(THIS_MODULE, "class_gpioinput");
  if (IS_ERR(gpioinput_class)) {
    unregister_chrdev_region(gpioinput_dev, 1);
    gpio_free(gpio_in);
    return -EINVAL;
  }

  device_create(gpioinput_class, NULL, gpioinput_dev, NULL, THIS_MODULE->name);
  cdev_init(& gpioinput_cdev, & fops_gpioinput);

  if ((err = cdev_add(& gpioinput_cdev, gpioinput_dev, 1)) != 0) {
    device_destroy(gpioinput_class, gpioinput_dev);
    class_destroy(gpioinput_class);
    unregister_chrdev_region(gpioinput_dev, 1);
    gpio_free(gpio_in);
    return err;
  }
  return 0;
}

static void gpioinput_exit (void)
{
	cdev_del(& gpioinput_cdev);
	device_destroy(gpioinput_class, gpioinput_dev);
	class_destroy(gpioinput_class);
	unregister_chrdev_region(gpioinput_dev, 1);
	gpio_free(gpio_in);
}

static int gpioinput_read(struct file * filp, char * buffer, size_t length, loff_t * offset)
{
	char buff[32];
	int ret;

	snprintf(buff, 32, "%d", gpio_get_value(gpio_in));
	ret = strlen(buff) + 1;
	if (ret > length)
		return -ENOMEM;
	if (copy_to_user(buffer, buff, ret) != 0)
		return -EFAULT;
	return ret;
}

module_init(gpioinput_init);
module_exit(gpioinput_exit);
MODULE_LICENSE("GPL");
