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
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/wait.h>
#include <linux/gpio.h>
#include <linux/uaccess.h>

#define NAME "Myswitch"
//#define MAJOR 60
int data_present=0;
int gpio_in=26;

static int gpio_irq = 0;
wait_queue_head_t my_queue;
DECLARE_WAIT_QUEUE_HEAD(my_queue);

dev_t temp;
ssize_t switch_read(struct file *, char __user *, size_t, loff_t *);
//ssize_t switch_write(struct file *, const char __user *, size_t, loff_t *);
int switch_open(struct inode *, struct file *);
int switch_close(struct inode *, struct file *);

struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = switch_read,
	//.write = switch_write,
	.open = switch_open,
	.release = switch_close
};

//Interrupt handler
irqreturn_t handler_irq_gpio(int irq, void * ident)
{
  data_present = 1;
  wake_up(&my_queue);
  return IRQ_HANDLED;
}


/*Device methods */
ssize_t switch_read(struct file *filp, char __user *usr, size_t size, loff_t *off)
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

/*ssize_t switch_write(struct file *filp, const char __user *usr, size_t len, loff_t *off)
{
	printk("Trying to write into the device\n");
	data_present=1;
	wake_up(&my_queue);
	return len; //-EPERM;
}*/

int switch_open(struct inode *ino, struct file *filp)
{
	printk("device opened\n");
	return 0;
}

int switch_close(struct inode *ino, struct file *filp)
{
	printk("device closed\n");
	return 0;
}

int switch_init(void)
{
	int err;
	int result;
        result = register_chrdev(120, NAME, &fops);
	if(result < 0)
	{
		printk("Device could not be registered\n");
		return -EPERM;
	}
	printk("Driver registered with major %d\n", MAJOR(temp));
	
        gpio_irq = gpio_to_irq(gpio_in);
	printk("interrupt request number:%d",gpio_irq);

	/*if ((err = gpio_request(gpio_out, THIS_MODULE->name)) != 0)
   	 return err;
        if ((err = gpio_direction_output(gpio_out, 0)) != 0) {
   	 gpio_free(gpio_out);
   	 return err;
 	 }*/

	if ((err = gpio_request(gpio_in, THIS_MODULE->name)) != 0) {
       	 //gpio_free(gpio_out);
   	 return err;
        }
        if ((err = gpio_direction_input(gpio_in)) != 0) {
   	 gpio_free(gpio_in);
   	 //gpio_free(gpio_out);
   	 return err;
        }
	
	if ((err = request_irq(gpio_irq, handler_irq_gpio, IRQF_SHARED, THIS_MODULE->name, THIS_MODULE->name)) != 0) {
   	 gpio_free(gpio_in);
   	//gpio_free(gpio_out);
    	 return err;
 	 }
	irq_set_irq_type(gpio_irq, IRQF_TRIGGER_FALLING);
	return 0;
}


void switch_exit(void)
{
	//data_present = 0;
	unregister_chrdev(120, NAME);
	printk("simple_switch unregistered\n");
 
	free_irq(gpio_irq, THIS_MODULE->name);
 	gpio_free(gpio_in);
	//gpio_free(gpio_out);
}

module_init(switch_init);
module_exit(switch_exit);

MODULE_LICENSE("GPL");
