#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Rashmi Gajghate");
MODULE_DESCRIPTION("Null module template");
MODULE_LICENSE("GPL");

/* Function for inserting module */
static int temp_init(void)
{
	printk("'Hello World !'"); /* Printing while inserting module */
	printk(KERN_DEBUG "%s:%s:%d\n\n",__FILE__,__func__,__LINE__);  /* Kernel debug log level 7 which generally use for debugging */
	return 0;
}

/* Function for removing module */
static void temp_exit(void)
{
	printk("'Goodbye World !'");  /* Printing while removing module */
	printk(KERN_DEBUG "%s:%s:%d\n\n",__FILE__,__func__,__LINE__); /* Kernel debug log level 7 which generally use for debugging */
	return;
}

/* Declaration of the init and exit functions */
module_init(temp_init);
module_exit(temp_exit);
