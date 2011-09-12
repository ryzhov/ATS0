# $Id: Makefile 6390 2009-12-10 14:09:58Z bogdan_iancu $
#
# WARNING: do not run this directly, it should be run by the master Makefile

include ../../Makefile.defs
auto_gen=
NAME=db_unixodbc.so

# sql.h locations (freebsd,openbsd  solaris)
DEFS += -I$(LOCALBASE)/include -I$(LOCALBASE)/include/odbc

# libodbc locations on RH/Suse, Solaris /OpenBSD, FreeBSD
# (Debian does the right thing and puts it in /usr/lib)
LIBS= -L$(LOCALBASE)/lib -lodbc

include ../../Makefile.modules
