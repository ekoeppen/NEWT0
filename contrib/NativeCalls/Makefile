proj = ../..
srcdir = $(proj)/src
build = $(proj)/build
parser = $(srcdir)/parser
core = $(srcdir)/newt_core

prefix = /usr/local
exec_prefix = ${prefix}
sitedir = ${prefix}/lib/newt0

CC = gcc
AR = /usr/bin/ar
RANLIB = ranlib
YACC = bison -y -d
LEX = flex
DEFS = -DHAVE_CONFIG_H
LIBS = 
DLEXT = so
EXEEXT = 
LDIMPORT = 
LDFLAGS = $(DEBUG) -O2 -rdynamic 
LDSHARED = $(CC) -shared

DEBUG = # -g
INCS = -I$(srcdir) -I$(core)/incs
EXTLIBS = 

NEWTLIBNAME	= NativeCalls
NEWTEXLIB	= $(build)/$(NEWTLIBNAME).$(DLEXT)

LIBOBJ		= $(build)/$(NEWTLIBNAME).o
CFLAGS		+= -Wall -DDYLIBSUFFIX='"$(DLEXT)"' -O2 -pipe -fPIC

.c.o:
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


all: $(build) $(NEWTEXLIB)

$(build):
	mkdir -p $(build)

$(NEWTEXLIB): $(LIBOBJ)
	$(LDSHARED) $< $(LDIMPORT) -lffi -o $@

$(LIBOBJ): $(NEWTLIBNAME).c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

install::
	install -d -m 755 $(DESTDIR)$(sitedir)
	install -m 644 $(NEWTEXLIB) $(DESTDIR)$(sitedir)

clean:
	rm -rf $(NEWTEXLIB)
	rm -rf $(LIBOBJ)

test:
	$(NEWT) -C tests test_nativecalls.newt
