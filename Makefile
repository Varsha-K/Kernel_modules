# Cross compilation Makefile for ARM
KERN_SRC=/home/varsha/Downloads/RTOS/Lab_3/linux-4.15.7/
obj-m += hello_world_module.o
obj-m += command_line_greet.o

all: 
	make -C $(KERN_SRC) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-  M=$(PWD) modules

clean:
	make -C $(KERN_SRC) ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-  M=$(PWD) clean




