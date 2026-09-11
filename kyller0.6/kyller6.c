#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_AUTHOR("Rhma");
MODULE_DESCRIPTION("Same approach as kyller0.5 but different method");
MODULE_VERSION("0.6");
MODULE_LICENSE("GPL");

static noinline void overflow(int digit)
{
	volatile char dummy[512]; //I dont know, this is code i just snagged of somewhere
	//it said its consume stack frame space, i'll look into that
	dummy[0] = digit;
	void (*ov)(int) = &overflow;
	ov(digit + 1);

	//this is to prevent GCC from turning a call function into a jmp, because of Tail Call Optimization
	//giving it work prevents this
	asm volatile("" : : "r"(dummy[0])); //inline assembly
}

static int __init kyller6_begin(void)
{
	void (*ov)(int) = &overflow;
	ov(1);
	return 0;
}
//this should definitely not be able to occur or even reachable
static void __exit kyller6_remove(void)
{
}

module_init(kyller6_begin);
module_exit(kyller6_remove);

