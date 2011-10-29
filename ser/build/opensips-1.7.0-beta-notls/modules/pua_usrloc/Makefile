# $Id: Makefile 6253 2009-10-12 19:00:53Z bogdan_iancu $
#
# PUBLISH
#
# 
# WARNING: do not run this directly, it should be run by the master Makefile

include ../../Makefile.defs
auto_gen=
NAME=pua_usrloc.so

DEFS+=-I$(SYSBASE)/include/libxml2 -I$(LOCALBASE)/include/libxml2 \
      -I$(LOCALBASE)/include
LIBS=-L$(SYSBASE)/include/lib  -L$(LOCALBASE)/lib -lxml2

include ../../Makefile.modules
