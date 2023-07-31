/***************************************************************************
 *      Organisation    : Kernel Masters, KPHB, Hyderabad, India.          *
 *      facebook page	: www.facebook.com/kernelmasters                   *
 *                                                                         *
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

#include <linux/kernel.h> /* printk */
#include <linux/module.h>/* This Header contains the necessary stuff for the Module */
#include <linux/init.h> /* Required header for the Intialization and Cleanup Functionalities....  */
#include <linux/fs.h> /* struct file_operations, struct file and struct inode */
#include <linux/kdev_t.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
//#define NAME "Mygpio_dev"

int data_present=0;
int gpio_in=26;
wait_queue_head_t my_queue;
DECLARE_WAIT_QUEUE_HEAD(my_queue);

EXPORT_SYMBOL(data_present);
EXPORT_SYMBOL(my_queue);
EXPORT_SYMBOL(gpio_in);

struct cdev *my_cdev;
struct class *gpio_class;
dev_t temp;
ssize_t gpio_dev_read(struct file *, char __user *, size_t, loff_t *);
//ssize_t gpio_dev_write(struct file *, const char __user *, size_t, loff_t *);
int gpio_dev_open(struct inode *, struct file *);
int gpio_dev_close(struct inode *, struct file *);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = gpio_dev_read,
	//.write = gpio_dev_write,
	.open = gpio_dev_open,
	.release = gpio_dev_close
};

/*Device methods */
ssize_t gpio_dev_read(struct file *filp, char __user *usr, size_t size, loff_t *off)
{
	char buff[10];
	int len;
	printk("Reading from device\n");
	if(data_present == 0)
    {
        printk("Process %d (%s) Going to Sleep\n",current->pid,current->comm);  
        if(wait_event_interruptible(my_queue,(data_present==1)))
        {
        // error
        printk(KERN_ERR "Signal Occurs\n");
        }
        else
        {
        //success
        printk(KERN_INFO "Process awaken - Now Data is available\n");
        snprintf(buff, 32, "%d", gpio_get_value(gpio_in));
        len = strlen(buff) + 1;
        if (len > size)
                return -ENOMEM;
        if (copy_to_user(usr,buff, len) != 0)
                return -EFAULT;
        return len;
        }
    }
    else // data_present=1
    {
        data_present = 0;
        printk(KERN_INFO "EOF\n");
        return 0; //-EPERM;
    }
	return 0;
}

/*ssize_t gpio_dev_write(struct file *filp, const char __user *usr, size_t len, loff_t *off)
{
	printk("Trying to write into the device\n");
	data_present=1;
	wake_up(&my_queue);
	return len; //-EPERM;
}*/

int gpio_dev_open(struct inode *ino, struct file *filp)
{
	printk("device opened\n");
	return 0;
}

int gpio_dev_close(struct inode *ino, struct file *filp)
{
	printk("device closed\n");
	return 0;
}

int gpio_dev_init(void)
{
	int err;
	int result;
	
	if ((err = gpio_request(gpio_in, THIS_MODULE->name
	
	
	)) != 0) {
   	 return err;
        }
        if ((err = gpio_direction_input(gpio_in)) != 0) {
   	 gpio_free(gpio_in);
   	 return err;
        }

        //result = register_chrdev(120, NAME, &fops);
	result = alloc_chrdev_region(&temp, 0, 1, THIS_MODULE->name);
	if(result < 0)
	{
		gpio_free(gpio_in);
		printk("Device could not be registered\n");
		return -EPERM;
	}
	printk("Driver registered with major %d\n", MAJOR(temp));
	
	gpio_class = class_create(THIS_MODULE,"class_gpio");
	if(IS_ERR(gpio_class)){
		unregister_chrdev_region(temp, 1);
		gpio_free(gpio_in);
		return -EINVAL	;
	}
	
	device_create(gpio_class, NULL, temp, NULL, THIS_MODULE->name);
	
	cdev_init(my_cdev,&fops);
	
	//my_cdev = cdev_alloc();//allocate memory to Char Device structure
	//my_cdev->ops = &fops;//link our file operations to the char device

	result=cdev_add(my_cdev,temp,1);//Notify the kernel abt the new device
	if(result < 0)
	{
		device_destroy(gpio_class,temp);
		class_destroy(gpio_class);
		unregister_chrdev_region(temp, 1);
		gpio_free(gpio_in);
		printk(KERN_ALERT "\nThe Char Devide has not been created......\n");
		return (-1);
	}
	
	
	return 0;	
}

void gpio_dev_exit(void)
{
	//data_present = 0;
	unregister_chrdev_region(temp, 1);
	printk("simple_gpio_dev unregistered\n");
 
}

module_init(gpio_dev_init);
module_exit(gpio_dev_exit);

MODULE_LICENSE("GPL");

