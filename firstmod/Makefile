obj-m += firstmod.o

KDIR := ../break_/linux 
PWD := $(shell os_pwd || pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
