#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rhma");
MODULE_DESCRIPTION("Kyller1 module for testing exploits on kernel");
MODULE_VERSION("0.1");

static int __init buggy_init(void)
{
    int *ptr = NULL;

	printk(KERN_INFO "Testing kyller1 module buggy module");

	//as you can see, this is a null pointer write
	//this should...trigger a page fault, let's see
    *ptr = 0xDEADBEEF;

    return 0;
}

static void __exit buggy_exit(void)
{
    pr_info("buggy_module: Unloading module\n");
}

module_init(buggy_init);
module_exit(buggy_exit);
