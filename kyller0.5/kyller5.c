#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_AUTHOR("Rhma");
MODULE_DESCRIPTION("Kyller0.5 exploit module, a different approach");
MODULE_VERSION("0.5");
MODULE_LICENSE("GPL");

#define NOINLINE __attribute__((noinline)) //let's try this method

//we are taking a differnet approach...
//we will do an infinite recursion so as to cause a double fault
//i understand the concepts of CPU exception since ive made them before for my OS
//we will trigger as many recursions as possible to trigger a page fault, then when the kernel
//says like okay i dont got no resources anymore it raises the exception #PF the another one will run
//and haha 2 fault = double faults...definiately panic! kyller0.5 is not failing

static void recurse(void) NOINLINE;

static void recurse(void) NOINLINE
{
	recurse(); //recursion infintely...
}

static int __init boom(void)
{
	printk(KERN_INFO "Kyller0.5 in action, ultimate recursion!\n");
	recurse();
	return 0;
}

//who knows if this would be possible..but i doubt
//the recursions might happen so quickly, and system might even get buggy just liek a fork bomb
static void __exit outboom(void)
{
	printk(KERN_INFO "Will this even be reachable? lets find out, I AM EXIT!\n");
}

module_init(boom);
module_exit(outboom);
