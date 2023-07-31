#include <linux/init.h> 
#include <linux/module.h>
#include <linux/kernel.h> /* Contains printk() defination */
#include <linux/slab.h> /* Contains defination of kmalloc() */
#include <linux/fs.h> 
#include <linux/errno.h> /* Conatins error codes */
#include <linux/types.h> 
#include <linux/proc_fs.h>
#include <linux/fcntl.h> 
#include <linux/uaccess.h> /* For copying the data from kernel to user and viceversa */

MODULE_AUTHOR("Rashmi Gajghate");
MODULE_DESCRIPTION("Kernel module for allocating single block");
MODULE_LICENSE("Dual BSD/GPL");

/* Declaration of functions */
int mem_block_open(struct inode *inode, struct file *filp);
int mem_block_release(struct inode *inode, struct file *filp);
ssize_t mem_block_read(struct file *filp, char *buf, size_t count, loff_t *f_pos);
ssize_t mem_block_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos);
static void mem_block_exit(void);
static int mem_block_init(void);

/* Structure that declares the usual file */
struct file_operations mem_block_fops = {
	.read = mem_block_read,
	.write =  mem_block_write,
	.open = mem_block_open,
	.release = mem_block_release
};

char *mem_block_buffer;  /* Buffer to store data */

/* Opening the device */
int mem_block_open(struct inode *inode, struct file *filp)
{
	printk(KERN_DEBUG "%s:%s:%d\n",__FILE__,__func__,__LINE__);
  	return 0;
}

/* reading the device */
ssize_t mem_block_read(struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_INFO "%s:%s:%d,count:%d,*f_pos:%d\n",__FILE__,__func__,__LINE__,count,*f_pos);
	copy_to_user(buf,mem_block_buffer,1); /* Copying data from kernel buffer to user buffer */
	if (*f_pos == 0) {
		*f_pos+=1;
		printk("\n");
		return 1;
	} 
	else {
    		return 0; /* End of file */
 	 }
}

/* writing to a device */
ssize_t mem_block_write( struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_INFO "%s:%s:%d count:%d *f_pos:%d\n",__FILE__,__func__,__LINE__,count,*f_pos);
	copy_from_user(mem_block_buffer,buf,1);  /* Copying data from user buffer to kernel buffer */
	printk("\n");
	return 1;
}

/* Close the device */ 
int mem_block_release(struct inode *inode, struct file *filp) {
	printk(KERN_INFO "%s:%s:%d\n\n",__FILE__,__func__,__LINE__);
	return 0;
}

/* Function for inserting module */
static int mem_block_init(void) 
{
	int result;
	result = register_chrdev(60, "mem_block", &mem_block_fops);  /* Registering device */
	if (result < 0) {
		printk("Major number already occupied\n"); /* Error handling for major number */
		return result;
  	}

	mem_block_buffer = kmalloc(1, GFP_KERNEL); /*Allocating memory to the buffer */
	if (!mem_block_buffer) {    /* Error handling for memory allocation */
		result = -ENOMEM;
		goto fail;
	} 
	memset(mem_block_buffer, 0, 1); /* Setting memory size for buffer */
	printk("Inserting mem_block module\n\n");
	return 0;
	fail:
	mem_block_exit();
	return result;
}

/* Function for removing module */
static void mem_block_exit(void) 
{						
	unregister_chrdev(60, "mem_block");  /* Unregistering device */
	if (mem_block_buffer){
		kfree(mem_block_buffer);  /*Freeing the buffer memory */
	}
	printk("Removing mem_block module\n\n");
}


/* Declaration of the init and exit functions */
module_init(mem_block_init);
module_exit(mem_block_exit);
