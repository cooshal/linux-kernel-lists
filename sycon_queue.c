#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>

/* include slab.h for printk() */
#include <linux/slab.h>

#include <linux/list.h>


/**
 * define an example structure.
 * the idea is that the structure should have a list
 */
struct example_list{
	int in;
	int out;

	struct list_head list;
};

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
	unsigned int i;

	struct example_list stats_list;
	INIT_LIST_HEAD(&stats_list.list);

	printk(KERN_INFO "Initializing List");

	for(i=5; i!=0; --i){
		ex_list_temp= (struct example_list *) kmalloc(sizeof(struct example_list), GFP_ATOMIC);
		
		ex_list_temp->in = i + 1;
		ex_list_temp->in = i + 2;

		list_add(&(ex_list_temp->list), &(stats_list.list));
	}


	printk("traversing the list using list_for_each()\n");
	list_for_each(pos, &stats_list.list){
		 ex_list_temp= list_entry(pos, struct example_list, list);
		 printk("in= %d in= %d\n", ex_list_temp->in, ex_list_temp->in);

	}

	printk(KERN_INFO "Module inserted\n");
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