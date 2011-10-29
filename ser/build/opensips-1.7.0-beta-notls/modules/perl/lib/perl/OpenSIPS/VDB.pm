#
# $Id: VDB.pm 5901 2009-07-21 07:45:05Z bogdan_iancu $
#
# Perl module for OpenSIPS
#
# Copyright (C) 2006 Collax GmbH
#                    (Bastian Friedrich <bastian.friedrich@collax.com>)
#
# This file is part of opensips, a free SIP server.
#
# opensips is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version
#
# opensips is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#

=head1 OpenSIPS::VDB

This package is an (abstract) base class for all virtual databases. Derived
packages can be configured to be used by OpenSIPS as a database.

The base class itself should NOT be used in this context, as it does not
provide any functionality.

=cut

package OpenSIPS::VDB;

use OpenSIPS;
use OpenSIPS::Constants;

use OpenSIPS::VDB::Column;
use OpenSIPS::VDB::Pair;
use OpenSIPS::VDB::ReqCond;
use OpenSIPS::VDB::Result;
use OpenSIPS::VDB::Value;
use OpenSIPS::VDB::VTab;

use UNIVERSAL qw ( can );

our @ISA = qw ( OpenSIPS::Utils::Debug );

sub new {
	my $class = shift;

	my $self = {
		tablename => undef,
		vtabs => {}
	};

	bless $self, $class;

	return $self;
}

sub use_table {
	my $self = shift;
	my $v = shift;
	
	$self->{tablename} = $v;

	if ($v eq "version") {
		# "version" table is handled individually. Don't initialize VTabs.
		return 0;
	}

	if ($self->{vtabs}->{$v}) {
		return 0;
	}

	if ($v =~ m/^((.*)::)?([\w_][\d\w_]*)$/) {
		my $pkg;
		if (!$2) {
			$pkg = "main";
		} else {
			$pkg = $2;
		}

		OpenSIPS::log(L_DBG, "perlvdb:VDB: Setting VTab: v is $v (pkg is $pkg, func/method is $3)\n");

		if (can($pkg, $3)) {
			$self->{vtabs}->{$v} = new OpenSIPS::VDB::VTab( func => $pkg . "::" . $3);
		} elsif (can($v, "init")) {
			$v->init();
			$self->{vtabs}->{$v} = new OpenSIPS::VDB::VTab( obj => $v );
		} elsif (can($v, "new")) {
			my $obj = $v->new();
			$self->{vtabs}->{$v} = new OpenSIPS::VDB::VTab( obj => $obj );
		} else {
			OpenSIPS::log(L_ERR, "perlvdb:VDB: Invalid virtual table.\n");
			return -1;
		}
	} else {
		OpenSIPS::log(L_ERR, "perlvdb:VDB: Invalid virtual table.\n");
		return -1;
	}
}

sub _insert {
	my $self = shift;
	return $self->insert(@_);
}

sub _replace {
	my $self = shift;
	return $self->replace(@_);
}

sub _delete {
	my $self = shift;
	return $self->delete(@_);
}

sub _update {
	my $self = shift;
	return $self->update(@_);
}

sub _query {
	my $self = shift;
	return $self->query(@_);
}



sub insert {
	OpenSIPS::log(L_INFO, "perlvdb:Insert not implemented in base class.\n");
	return -1;
}

sub replace {
	OpenSIPS::log(L_INFO, "perlvdb:Replace not implemented in base class.\n");
	return -1;
}

sub delete {
	OpenSIPS::log(L_INFO, "perlvdb:Delete not implemented in base class.\n");
	return -1;
}

sub update {
	OpenSIPS::log(L_INFO, "perlvdb:Update not implemented in base class.\n");
	return -1;
}

sub query {
	OpenSIPS::log(L_INFO, "perlvdb:Query not implemented in base class.\n");
	return -1;
}

1;
