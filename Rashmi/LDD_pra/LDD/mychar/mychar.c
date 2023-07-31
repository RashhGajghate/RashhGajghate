#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/sched.h>
#include<linux/fs.h>

MODULE_AUTHOR("RASHH_ME");
MODULE_DESCRIPTION("NULL device");
MODULE_LICENSE("GPLV2");

int mychar_open(struct inode *, struct file *);
ssize_t mychar_read(struct file *, char __user *, size_t, loff_t *);
ssize_t mychar_write(struct file *, const char __user *, size_t, loff_t *);
int mychar_release(struct inode *, struct file *);

struct file_operations mychar_ops = {
	.open = mychar_open,
	.read = mychar_read,
	.write = mychar_write,
	.release = mychar_release,
};

int mychar_open(struct inode *ptr, struct file *flag)
{
	printk("PID:%d Process name:%s\n",current->pid,current->comm);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}
ssize_t mychar_read(struct file *fd, char __user *buff, size_t len, loff_t *offset)
{
	printk("PID:%d Process name:%s\n",current->pid,current->comm);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}
ssize_t mychar_write(struct file *fd, const char __user *buff, size_t len, loff_t *offset)
{
	printk("PID:%d Process name:%s\n",current->pid,current->comm);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	//printk("buf : %s \n",buff);
	return len;
}
int mychar_release(struct inode *ptr, struct file *fd)
{
	printk("PID:%d Process name:%s\n",current->pid,current->comm);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	return 0;
}

static int mychar_init(void)
{
	int ret;
	printk("PID:%d Process name:%s\n",current->pid,current->comm);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	ret = register_chrdev(60,"RASHH",&mychar_ops);
	if(ret < 0){
		printk(KERN_ERR "FAIL");
		return -1;
	}
	return 0;
}

static void mychar_exit(void)
{
	printk("PID:%d Process name:%s\n",current->pid,current->comm);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	unregister_chrdev(60,"RASHH");	
}

module_init(mychar_init);
module_exit(mychar_exit);
