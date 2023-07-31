#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>

int value=0;
int data_present = 0;
int gpio_in = 26;
wait_queue_head_t my_queue;
DECLARE_WAIT_QUEUE_HEAD(my_queue);
 
EXPORT_SYMBOL(value);
EXPORT_SYMBOL(data_present);
EXPORT_SYMBOL(my_queue);
EXPORT_SYMBOL(gpio_in);

static struct task_struct *my_thread;
   
//char *argv[] = { "/bin/ls", "-l", NULL };
char *argv[] = { "/home/km/blink.sh", NULL };
static char *envp[] = {
	"HOME=/",
        "TERM=linux",
        "PATH=/sbin:/usr/sbin:/bin:/usr/bin",
        NULL
};

static int my_thread_func(void *data)
{
	int ret;
	do {
		if(data_present == 0)
		{
			printk("Process %d (%s) Going to Sleep\n",current->pid,current->comm);	
			if(wait_event_interruptible(my_
			
			queue,(data_present==1)))
			{
				// error
				printk(KERN_ERR "Signal Occurs\n");
			}
			else
			{
				//success
				printk(KERN_INFO "Process awaken - Now Data is available\n");
				ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
				printk("ret:%d\n",ret);
				data_present=0;
			}
		}

	}  while (!kthread_should_stop ());   //Its return type is bool and it will return false till the module get removed
								  //so false getting complemented and loop becoming true and running continously 
	return 0;
}

static int __init my_module_init(void)
{
    printk("init\n");
    my_thread = kthread_run(my_thread_func, NULL, "my_thread");

    return 0;
}

static void __exit my_module_exit(void)
{
   //int err;
   data_present=1;
   wake_up_interruptible(&my_queue);
   kthread_stop(my_thread);
}

module_init(my_module_init);
module_exit(my_module_exit);
MODULE_LICENSE("GPL");
