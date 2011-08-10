# $Id: Makefile 5901 2009-07-21 07:45:05Z bogdan_iancu $
#
# WARNING: do not run this directly, it should be run by the master Makefile

include ../../Makefile.defs
auto_gen=
NAME=db_unixodbc.so

# sql.h locations (freebsd,openbsd  solaris)
DEFS += -I$(LOCALBASE)/include

# libodbc locations on RH/Suse, Solaris /OpenBSD, FreeBSD
# (Debian does the right thing and puts it in /usr/lib)
LIBS= -L$(LOCALBASE)/lib -lodbc

include ../../Makefile.modules
