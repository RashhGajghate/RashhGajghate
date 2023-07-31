#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_AUTHOR("RASHH_ME");
MODULE_DESCRIPTION("Hello world template module");
MODULE_LICENSE("GPLV2");

int add(int , int);
static int avg_init(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	printk("avg result:%d\n",add(10,2)/2);
	return 0;
}

static void avg_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(avg_init);
module_exit(avg_exit);
