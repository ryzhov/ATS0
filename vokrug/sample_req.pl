#!/usr/bin/perl
#
# -- Send sample authorization request --

use strict;
my $req = '{"user_id":1212,"auth_key":"ashgfasgfaisygfasiygf"}';

use IO::Socket; 
my $sock = new IO::Socket::INET ( 
    PeerAddr => 'vokrug.ru', 
    PeerPort => '7000', 
    Proto => 'tcp', 
); 

die "Could not create socket: $!\n" unless $sock; 
print $sock $req;
print "Send req [" . $req . "]\n";

while(<$sock>) { 
    print "Recv line [" . $_ . "]\n"; 
}

close($sock);
