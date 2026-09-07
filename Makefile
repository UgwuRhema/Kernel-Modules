obj-m += hello.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell os_pwd || pwd)

default:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
