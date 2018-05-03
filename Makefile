#CC=clang
#CCX=
CFLAGS=-Wall -Wextra -pedantic -std=c99
#CFLAGS+=-O0
CFLAGS+=-g -Og
#CFLAGS+=-pg
#CXXFLAGS=$(CFLAGS)
CPPFLAGS=
LDFLAGS=
LDLIBS=
SRCDIR=../src
SRC!=find $(SRCDIR) -type f -name "*.c" | cut -d"/" -f2-

# Define executables and their link dependencies here
EXECS = exec1 exec2
exec1_DEPS = file1.c
exec1_LIBS = m
exec2_DEPS =
exec1_LIBS =

###############################################################################
# No more user editing is needed below
###############################################################################
OBJDIR=.obj

define EXEC_templ =
$(1): $$(addprefix $$(OBJDIR)/,$$($(1)_DEPS:%.c=%.o))
	$(CC) -o $$@ $$(LDFLAGS) $$(LDLIBS) $$($(1)_LIBS:%=-l%) $$^
endef

$(foreach exec,$(EXECS),$(eval $(call EXEC_templ,$(exec))))

-include $(addprefix $(OBJDIR)/, $(SRC:.c=.d))
$(OBJDIR)/%.d: %.c
	@mkdir -p `dirname $@`
	$(CC) $(CPPFLAGS) -MM -MF $@ $^

$(OBJDIR)/%.o: %.c
	$(CC) -c -o $@ $(CPPFLAGS) $(CFLAGS) $<

.PHONY=clean all
.DEFAULT_GOAL=all
all: $(EXECS)

clean:
	@rm -rf $(OBJDIR) $(EXECS)

# This rebuilds everything if the Makefile was modified
# http://stackoverflow.com/questions/3871444/making-all-rules-depend-on-the-makefile-itself/3892826#3892826
-include .dummy
.dummy: Makefile
	@touch $@
	@$(MAKE) -s clean
