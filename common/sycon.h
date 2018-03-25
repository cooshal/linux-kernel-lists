/*
 * sycon.h
 *
 *  Created on: Mar 24, 2018
 *      Author: Cooshal
 */

#ifndef INCLUDE_LINUX_SYCON_H_
#define INCLUDE_LINUX_SYCON_H_


/**
 * define an example structure.
 * the idea is that the structure should have a list
 */
struct example_list{
	int in;
	int out;

	struct list_head list;
};

#endif /* INCLUDE_LINUX_SYCON_H_ */
