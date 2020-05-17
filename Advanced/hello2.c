#include "hello1.h"

#include <linux/moduleparam.h>

static uint value = 1;
module_param(value, uint, 0444);
MODULE_PARM_DESC(value, "This parameter defines a number of output strings");

extern int print_hello(uint n);
extern void print_time(void);

static int __init hello2_init(void)
{
	return print_hello(value);
}
module_init(hello2_init);

static void __exit hello2_exit(void)
{
	print_time();

	pr_info("Good bye, world!!!\n");
}
module_exit(hello2_exit);
