# File: drivers/net/Makefile
#
# Makefile for the Linux network (ethercard) device drivers.
#

# This will go away in some future future: hidden configuration files
# are difficult for users to deal with.
include CONFIG

NETDRV_OBJS := net.a(Space.o) net.a(auto_irq.o) net.a(net_init.o)
CFLAGS := $(CFLAGS) -I../../net/inet
CPP := $(CPP) -I../../net/inet

# The point of the makefile...
all: net.a

Space.o: Space.c ../../include/linux/autoconf.h
	$(CC) $(CFLAGS) $(OPTS) $(DL_OPTS) -c $< -o $@

net_init.o: ../../include/linux/autoconf.h

ifdef CONFIG_NE2000
NETDRV_OBJS := $(NETDRV_OBJS) net.a(ne.o)
CONFIG_8390 = CONFIG_8390
ne.o:	ne.c CONFIG
	$(CC) $(CPPFLAGS) $(CFLAGS) $(NE_OPTS) -c $<
endif

ifdef CONFIG_8390
NETDRV_OBJS := $(NETDRV_OBJS) net.a(8390.o)
endif

net.a: $(NETDRV_OBJS)
	ranlib net.a

clean:
	rm -f core *.o *.a *.s

dep:
	$(CPP) -M *.c > .depend

tar:


# include a dependency file if one exists

ifeq (.depend,$(wildcard .depend))
include .depend
endif
