#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rhema");
MODULE_DESCRIPTION("Just a minimal kernel module to get going");
MODULE_VERSION("1.0");

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello World from kernel Space!\n");
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye World from kernel Space!\n");
}

module_init(hello_init);
module_exit(hello_exit);
