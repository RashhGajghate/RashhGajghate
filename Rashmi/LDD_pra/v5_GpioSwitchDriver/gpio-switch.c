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
#include <linux/gpio-switch.h>
static int gpio_irq = 0;
//Interrupt handler
irqreturn_t handler_irq_gpio(int irq, void * ident)
{
  data_present = 1;
  wake_up(&my_queue);
  return IRQ_HANDLED;
}


int gpio_switch_init(void)
{
	int err;
        gpio_irq = gpio_to_irq(gpio_in);
	printk("interrupt request number:%d",gpio_irq);

	if ((err = request_irq(gpio_irq, handler_irq_gpio, IRQF_SHARED, THIS_MODULE->name, THIS_MODULE->name)) != 0) {
    	 return err;
        }
	irq_set_irq_type(gpio_irq, IRQF_TRIGGER_FALLING);
	return 0;
}


void gpio_switch_exit(void)
{
	free_irq(gpio_irq, THIS_MODULE->name);
}

module_init(gpio_switch_init);
module_exit(gpio_switch_exit);

MODULE_LICENSE("GPL");
