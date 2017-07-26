# Makefile for sample_d2s viewer demo
#
# This code is part of the Diderot Project (http://diderot-language.cs.uchicago.edu)
#
# COPYRIGHT (c) 2015 The University of Chicago
# All rights reserved.
#

SHELL =		/bin/sh

CC =		clang
CPPFLAGS =	-I../util -I/opt/local -I/usr/local/ -I/usr/local/ -I/Users/chariseechiw/firedrake/vedat/
CFLAGS =	-O3
FRAMEWORKS =	-framework Cocoa -framework OpenGL -framework IOKit -framework CoreFoundation -framework CoreVideo
LDFLAGS =	-L/opt/local/lib -L/usr/local/lib -L/usr/local/ -lteem  -lpng $(FRAMEWORKS) -dynamiclib

DIDEROTC =		/Users/chariseechiw/diderot/femprime/bin/diderotc 
DIDEROTC_FLAGS =	--namespace=sample_d2s --target=pthread

UTIL_SRCS =		../../util/util.c



sample_d2s.o:	sample_d2s.diderot
	$(DIDEROTC) $(DIDEROTC_FLAGS)  --namespace=sample_d2s  sample_d2s.diderot

clean:
	rm -rf libsample_d2s.dylib sample_d2s.o  sample_d2s.h

dist-clean:	clean
	rm -f Makefile
