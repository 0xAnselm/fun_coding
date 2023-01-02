#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/fs.h>	/* Needed by all modules */

MODULE_LICENSE("GPL");
#define MYMAJOR 90

static int driver_open(struct inode *device_file, struct file *instance) {
    printk("dev_nr - open was called!\n");
    return 0;
}

static int driver_close(struct inode *device_file, struct file *instance) {
    printk("dev_nr - close was called!\n");
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = driver_open,
    .release = driver_close
};


static int __init myModuleInit(void)
{
    int retval;
	printk("Hello world 1.\n");
	retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);
    if (retval == 0) {
        printk("dev_nr - registered Dev number Major: %d, Minor: %d\n", MYMAJOR, 0);
    } else if(retval > 0) {
        printk("den_nr - registered Dev number Major: %d, Minor: %d\n", retval>>20, retval&0xfffff);
    } else {
        printk("Could not register device number!\n");
        return -1;
    }
    return 0;
}

static void __exit myModuleExit(void)
{
    unregister_chrdev(MYMAJOR, "my_dev_nr");
	printk("Goodbye world 1.\n");
}

module_init(myModuleInit);
module_exit(myModuleExit);