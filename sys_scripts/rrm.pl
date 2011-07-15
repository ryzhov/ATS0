#!/usr/bin/perl
#
# -- manage default route script --

use Mail::Mailer;
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

sub str_peer {
    my ($isp) = @_;
    my $key;
    my $value;
    my $str = " -- $isp->{'name'} peer --\n";

    foreach $key (sort keys %$isp) {
	next if $key eq 'name';
	$value = $isp->{$key};
	$str .= "$key => $value\n";
    }
    return $str;
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
my $mailer = Mail::Mailer->new();
my $mes = " -- ROUTE STATE @ [$now] -- \n";
my $subject = $mes;

$mes .= $result;

$s{'inuse'} = 1 if ($result =~ /$s{'gw'}/);
$m{'inuse'} = 1 if ($result =~ /$m{'gw'}/);

set_status(\%s);
set_status(\%m);
$mes .= str_peer(\%s);
$mes .= str_peer(\%m);

if ($s{'status'} and !$s{'inuse'} and !$m{'status'} and $m{'inuse'}) {
    $r_repl_cmd = "$ip_cmd route replace default scope global via $s{'gw'} dev $s{'dev'} src $s{'ip'}";
}

if (!$s{'status'} and $s{'inuse'} and $m{'status'} and !$m{'inuse'}) {
    $r_repl_cmd = "$ip_cmd route replace default scope global via $m{'gw'} dev $m{'dev'} src $m{'ip'}";
}

#if ($s{'status'} and $m{'status'} and ($s{'inuse'} xor $m{'inuse'})) {
#    $r_repl_cmd = "$ip_cmd route replace default scope global";
#    $r_repl_cmd .= " nexthop via $s{'gw'} dev $s{'dev'} weight 1";
#    $r_repl_cmd .= " nexthop via $m{'gw'} dev $m{'dev'} weight 1";
#}

if (defined($r_repl_cmd)) {
    `$r_repl_cmd`;
    $mes .= " -- ROUTE CHANGED -- \n";
} else {
    $mes .= " -- ROUTE VALID -- \n";
}

$mes .= `$r_list_cmd`;
print $mes;

# -- mail report if route was changed --
if (defined($r_repl_cmd)) {
    my $from_address = 'root';
    my $to_address = 'ran';

    $mailer->open({ From => $from_address, To => $to_address, Subject => $subject});
    print $mailer $mes;
    $mailer->close();
}
