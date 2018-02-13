CFLAGS=-Wall -Wextra -pedantic
CFLAGS+=-O3
#CFLAGS+=-g
#CFLAGS+=-g -pg
CPPFLAGS=-MP -MMD
LDFLAGS=
CC=gcc
SRC=$(wildcard *.c)
EXEC=

all:
	make $(EXEC)
	rm -rf *.d

$(EXEC): $(SRC:%.c=%.o)
# This will implicity make all the .c files with *FLAGS and with
# dependencies generated automatically by CPPFLAGS, included below (.d files)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

-include $(SRC:%.c=%.d)

clean:
	rm -rf *.o *.d *.out* $(EXEC) tags

# This rebuilds everything if the Makefile was modified
# http://stackoverflow.com/questions/3871444/making-all-rules-depend-on-the-makefile-itself/3892826#3892826
-include .dummy
.dummy: Makefile
	touch $@
	$(MAKE) -s clean

# TODO: create a test target: automate memcheck, massif & gprof
