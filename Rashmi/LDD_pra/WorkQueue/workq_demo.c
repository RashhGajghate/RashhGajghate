/***************************************************************************
 *      Organisation    : Kernel Masters, KPHB, Hyderabad, India.          *
 *      facebook page   : www.facebook.com/kernelmasters                   *
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


#include <linux/init.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/jiffies.h>

static struct delayed_work ws;

static void wq_func(struct work_struct *work) // It is like Bootom Half Mechan.
{
	printk("We're here!\n");
}

static int workq_demo_init(void) // It is like Top Half
{
	INIT_DELAYED_WORK(&ws, wq_func); //WQ Initalization
	
	mod_delayed_work(system_wq, &ws, msecs_to_jiffies(100)); // Invoke WQ function after 100msec delay

	printk("WQ Installed.\n");
	return 0;
}

static void workq_demo_exit(void)
{
	flush_scheduled_work ();
	printk("WQ Removed.\n");
}

MODULE_LICENSE("GPL");

module_init(workq_demo_init);
module_exit(workq_demo_exit);

