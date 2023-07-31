#include<linux/module.h>
#include<linux/init.h>

MODULE_AUTHOR("Rashmi");
MODULE_LICENSE("GPL");


static int hello_init(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

static void hello_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return;
}

module_init(hello_init);
module_exit(hello_exit);
