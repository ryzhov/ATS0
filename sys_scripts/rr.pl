#!/usr/bin/perl
#
# -- manage default route script --

use strict;


sub set_status {
     my ($isp) = @_;
     my ($addr);
     my @test_addr = ('74.125.87.99','77.88.21.11');
#     my @test_addr = ('google.com','yandex.ru');
     my $ping_cmd = 'ping -c 1 -w 3 -I ';
     my $result;

     $ping_cmd .= $isp->{'ip'};

     foreach $addr (@test_addr) {
	 $result = `$ping_cmd $addr`;
	 if ($result =~ /1 received/) {
	     $isp->{'status'} = 1;
	     last;
	 }
     }
}

sub print_peer {
    my ($isp) = @_;
    my $key;
    my $value;

    print " -- $isp->{'name'} peer --\n";
    foreach $key (sort keys %$isp) {
	next if $key eq 'name';
	$value = $isp->{$key};
	print "$key => $value\n";
    }
}

my %s = ('ip' => '193.109.166.214', 
	'gw' => '193.109.166.209',
	'dev' => 'eth1',
	'inuse' => 0, 
	'status' => 0,
    	'name' => 'STELS');

my %m = ('ip' => '193.108.39.66',
	'gw' => '193.108.39.65',
	'dev' => 'eth1',
	'inuse' => 0,
	'status' => 0,
    	'name' => 'MATRIX');

my $ip_cmd = '/sbin/ip';
my $r_list_cmd = "$ip_cmd route list 0/0 table main";
my $r_repl_cmd = undef;
my $result = `$r_list_cmd`;
my $now = localtime;

print " -- ROUTE IS @ [$now] -- \n$result";
$s{'inuse'} = 1 if ($result =~ /$s{'gw'}/);
$m{'inuse'} = 1 if ($result =~ /$m{'gw'}/);

set_status(\%s);
set_status(\%m);
print_peer(\%s);
print_peer(\%m);

if ($s{'status'} and !$m{'status'} and $m{'inuse'}) {
    $r_repl_cmd = "$ip_cmd route replace default scope global via $s{'gw'} dev $s{'dev'} src $s{'ip'}";
}
if ($m{'status'} and !$s{'status'} and $s{'inuse'}) {
    $r_repl_cmd = "$ip_cmd route replace default scope global via $m{'gw'} dev $m{'dev'} src $m{'ip'}";
}
if ($s{'status'} and $m{'status'} and ($s{'inuse'} xor $m{'inuse'})) {
    $r_repl_cmd = "$ip_cmd route replace default scope global";
    $r_repl_cmd .= " nexthop via $s{'gw'} dev $s{'dev'} weight 1";
    $r_repl_cmd .= " nexthop via $m{'gw'} dev $m{'dev'} weight 1";
}

if (defined($r_repl_cmd)) {
    `$r_repl_cmd`;
    print " -- ROUTE CHANGED -- \n";
} else {
    print " -- ROUTE VALID -- \n";
}

$result = `$r_list_cmd`;
print "$result";
