#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Some Random Guy");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("The first custom loadable module");
MODULE_VERSION("1.0.0");

static int __init start(void)
{
	printk(KERN_INFO "The First Custom Module here!\n");
	return 0;
}

static void __exit stop(void)
{
	printk(KERN_INFO "The First Custom Module has now been removed!\n");
}

module_init(start);
module_exit(stop);
