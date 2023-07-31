#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_AUTHOR("RASHH_ME");
MODULE_DESCRIPTION("Hello world template module");
MODULE_LICENSE("GPLV2");

extern int var;
static int two_init(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	printk("var:%d\n",var);
	return 0;
}

static void two_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(two_init);
module_exit(two_exit);
