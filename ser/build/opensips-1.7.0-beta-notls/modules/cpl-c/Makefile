# $Id: Makefile 5901 2009-07-21 07:45:05Z bogdan_iancu $
#
# WARNING: do not run this directly, it should be run by the master Makefile

include ../../Makefile.defs
auto_gen=
NAME=cpl-c.so

DEFS +=-I$(SYSBASE)/include/libxml2 -I$(LOCALBASE)/include/libxml2 \
		-I$(LOCALBASE)/include  # iconv.h

LIBS= -L$(LOCALBASE)/lib -lxml2

include ../../Makefile.modules
