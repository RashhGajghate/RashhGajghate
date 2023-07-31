#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>

MODULE_AUTHOR("RASHH_ME");
MODULE_DESCRIPTION("Hello world template module");
MODULE_LICENSE("GPLV2");

int var=10;
module_param(var,int,0644);

static int modparam_init(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	printk("var:%d\n",var);
	return 0;
}

static void modparam_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(modparam_init);
module_exit(modparam_exit);
