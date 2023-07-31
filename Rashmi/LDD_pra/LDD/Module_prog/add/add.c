#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_AUTHOR("RASHH_ME");
MODULE_DESCRIPTION("Hello world template module");
MODULE_LICENSE("GPLV2");

int add(int x,int y)
{
	return x+y;
}

EXPORT_SYMBOL(add);

static int add_init(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

static void add_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(add_init);
module_exit(add_exit);
