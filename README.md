# Basic Example of lists in Kernel Module (Linux)
This is a very basic example of the use of lists in Linux Kernel modules

# General Information

Please note that this repository is meant to be a simple demo. DO NOT expect it to do some fancy stuffs.

This example should give you a Hello World of the Kernel Module in Linux as well as a very basic example of lists in the kernel module. For further descriptions on these topics, please go through the official docs.

# Usage

## Build It !

- to build this Kernel module simple type `make`
- to clean the built files, `make clean`

## install the Kernel module
after the build is successful, a .ko file will be generated (demo_km.ko). To change settings for the name of .ko file, please take a look at Makefile.

to install the module, type 

`sudo insmod demo_km.ko`

it might be possible that you will receive some errors during the insertion. But, if everything is configured properly, there shouldn't be any errors.

Also note that, if the kernel module is already installed with that name, it will result in an error.

Thus, in that case remove the Kernel Module first.

## Verifying the installation

this can be verified by typing `lsmod | grep 'demo_km'`. If it displays `demo_km`, this installation is successful.

Also, if you notice the kernel module, it has several printk() statements. thus this printed lines will be visible in dmesg.

to see it, type: `dmesg -w` or simple `dmesg`

## Removing the Kernel Module

`$ sudo rmmod demo_km`