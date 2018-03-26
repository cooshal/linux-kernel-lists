CONFIG_MODULE_SIG=n

obj-m += demo_km.o 
demo_km-objs := example_km_queue.o

MY_CFLAGS += -g
ccflags-y += ${MY_CFLAGS}
CC += ${MY_CFLAGS}

all:
	echo $(shell uname -r)
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
debug:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules 
    EXTRA_CFLAGS="$(MY_CFLAGS)"
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
