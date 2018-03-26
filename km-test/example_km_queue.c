#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>

/* include slab.h for printk() */
#include <linux/slab.h>

#include <linux/list.h>

#include "../common/sycon.h"

struct example_list global_list;
EXPORT_SYMBOL(global_list);

/**
 * Module Initialiation Block. 
 * This function is called when the module is loaded
 * Here, a few components will be initialized.
 */
static int __init
init_km_list(void)
{

	struct example_list *ex_list_temp;
	struct list_head;
	unsigned int i;

	// struct example_list global_list;
	INIT_LIST_HEAD(&global_list.list);

	printk(KERN_INFO "Initializing List");

	printk("%llu; Current TS\n", rdtsc());

	for(i = 5; i != 0; --i){
		ex_list_temp= (struct example_list *) kmalloc(sizeof(struct example_list), GFP_ATOMIC);
		
		ex_list_temp->in = i + 1;
		ex_list_temp->out = i + 2;

		list_add(&(ex_list_temp->list), &(global_list.list));
	}

	printk(KERN_INFO "[MODULE 1]: Module inserted\n");
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