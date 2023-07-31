#include<linux/init.h>
#include<linux/modules.h>




static int mychar_init(void)
{

}

static void mychar_exit(void)
{

}

MODULE_AUTHOR("Rashmi");
MODULE_LICENSE("GPL");

module_init(mychar_init);
module_exit(mychar_exit);
