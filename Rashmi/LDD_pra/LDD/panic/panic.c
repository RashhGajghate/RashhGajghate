#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/sched.h>

MODULE_AUTHOR("Kishore Kumar");
MODULE_DESCRIPTION("panic usage");
MODULE_LICENSE("GPLV2");

int *ptr=NULL,a;
static int panic_init(void)
{
	a=*ptr;
	printk("PID:%d Process Name:%s\n",current->pid,current->comm);
	printk(KERN_DEBUG "%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

static void panic_exit(void)
{
	printk("PID:%d Process Name:%s\n",current->pid,current->comm);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(panic_init);
module_exit(panic_exit);
