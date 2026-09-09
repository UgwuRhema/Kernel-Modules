#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/preempt.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rhma");
MODULE_DESCRIPTION("Kyller0.2 atomic fault test module");

static int __init panic_init(void)
{
    pr_info("panic_module: Entering atomic context...\n");

    /* The kernel killed kyller 0.1 the last time so now after this function the kernel can no longer schedule or kill tasks */
    preempt_disable();

	//and we will now carry out our exploit again!
    *(volatile int *)0 = 0xDEADBEEF;

    preempt_enable();
    return 0;
}

static void __exit panic_exit(void)
{
}

module_init(panic_init);
module_exit(panic_exit);
