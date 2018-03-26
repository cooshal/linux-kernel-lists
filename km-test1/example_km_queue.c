#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>

/* include slab.h for printk() */
#include <linux/slab.h>
#include <linux/list.h>

#include "../common/sycon.h"

extern struct example_list global_list;

static int int_count;

/**
 * Module Initialiation Block. 
 * This function is called when the module is loaded
 * Here, a few components will be initialized.
 */
static int __init
init_km_list(void)
{

	struct example_list *ex_list_temp;
	struct list_head *pos;

	printk("[MODULE 2]: traversing the list using list_for_each()\n");
	list_for_each(pos, &global_list.list){
		 ex_list_temp= list_entry(pos, struct example_list, list);
		 printk("in= %d in= %d\n", ex_list_temp->in, ex_list_temp->in);

	}

	printk(KERN_INFO "Module 2 inserted\n");
	return 0;
}

/**
 * called when the module is unloaded
 */
static void __exit
exit_module(void)
{
	printk(KERN_INFO "Unloading debuging module.\n");
}

module_init(init_km_list);
module_exit(exit_module);
MODULE_DESCRIPTION("Kernel Module for Synchronous Network Communication");
MODULE_AUTHOR("Kushal Gautam");
MODULE_LICENSE("GPL");