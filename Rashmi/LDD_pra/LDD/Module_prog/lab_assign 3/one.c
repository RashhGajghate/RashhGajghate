#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_AUTHOR("RASHH_ME");
MODULE_DESCRIPTION("Hello world template module");
MODULE_LICENSE("GPLV2");

int var=5;
EXPORT_SYMBOL(var);
static int one_init(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

static void one_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(one_init);
module_exit(one_exit);
