#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_AUTHOR("RASHH_ME");
MODULE_DESCRIPTION("Hello world template module");
MODULE_LICENSE("GPLV2");

extern int var;
static void two_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_exit(two_exit);
