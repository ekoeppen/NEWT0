proj = ../..
srcdir = $(proj)/src
build = $(proj)/build
parser = $(srcdir)/parser
core = $(srcdir)/newt_core

prefix = /usr/local
exec_prefix = ${prefix}
sitedir = ${prefix}/lib/newt0
libffidir = @libffidir@

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

NEWTLIBNAME	= NewtObjC
NEWTEXLIB	= $(build)/$(NEWTLIBNAME).$(DLEXT)

LIBOBJ		= \
	$(NEWTLIBNAME).o \
	AppKitFunctions.o \
	FoundationFunctions.o \
	ObjCObjects.o \
	TNewtObjCRef.o \
	Utils.o

CFLAGS		+= -Wall -O2 -pipe -fPIC

%.o: %.m
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all: $(build) $(NEWTEXLIB)

$(build):
	mkdir -p $(build)

$(NEWTEXLIB): $(LIBOBJ)
	$(LDSHARED) $(LIBOBJ) $(LDIMPORT) -framework Cocoa -o $@

install::
	install -d -m 755 $(DESTDIR)$(sitedir)
	install -m 644 $(NEWTEXLIB) $(DESTDIR)$(sitedir)

clean:
	rm -rf $(NEWTEXLIB) $(LIBOBJ)

test:
	$(NEWT) -C tests test_newtobjc.newt
