#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Someone");
MODULE_LICENSE("GPL");
MODULE_VERSION("1.0.0");
MODULE_DESCRIPTION("Just a module");

static int __init start(void)
{
	printk(KERN_INFO "Custom module loaded here!\n");
	return 0;
}

static void __exit stop(void)
{
	printk(KERN_INFO "Custom module unloaded here!\n");
}

module_init(start);
module_exit(stop);
