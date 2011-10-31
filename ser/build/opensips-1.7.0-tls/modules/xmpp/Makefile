# $Id: Makefile 5901 2009-07-21 07:45:05Z bogdan_iancu $
#
# xmpp module makefile
#
#
# WARNING: do not run this directly, it should be run by the master Makefile

include ../../Makefile.defs

auto_gen=
NAME=xmpp.so
LIBS=

# expat.h location
DEFS += -I$(LOCALBASE)/include
LIBS  = -L$(LOCALBASE)/lib -lexpat

include ../../Makefile.modules
