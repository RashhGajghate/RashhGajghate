#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/sched.h>
#include <linux/jiffies.h>

static struct task_struct *my_thread;

//char *argv[] = { "/bin/ls", "-l", NULL };
char *argv[] = { "/home/desd/write", NULL };
static char *envp[] = {
	"HOME=/",
        "TERM=linux",
        "PATH=/sbin:/usr/sbin:/bin:/usr/bin",
        NULL
};

static int my_thread_func(void *data)
{
 int ret;
	ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
	printk("ret:%d\n",ret);
    
    do {
        printk (KERN_INFO "my_sender_thread sent a message at jiffies=%ld\n",
                jiffies);
        set_current_state(TASK_INTERRUPTIBLE);
        schedule_timeout(msecs_to_jiffies(1000));//1 sec delay
   } while (!kthread_should_stop ());
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
   kthread_stop(my_thread);
}

module_init(my_module_init);
module_exit(my_module_exit);
MODULE_LICENSE("GPL");
