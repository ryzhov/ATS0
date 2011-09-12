#!/usr/bin/perl -w

use strict;
use IO::Socket;

sub auth_vokr {
    my $req = '{"user_id":' . $_[0] . ',"auth_key":"' . $_[1] . '"}';
    my %rsp = ('status' => 'PENDING', 'msg' => undef);
    
    my $sock = new IO::Socket::INET (
	PeerAddr => 'vokrug.ru',
	PeerPort => '7000',
	Proto => 'tcp',
	Timeout => 2,
    );


    if ($sock) {
	if ($sock->send($req, 0)) {
	    my ($rout,$rin) = ('',''); 
	    vec($rin, fileno($sock), 1) = 1;
	    select($rout = $rin, undef, undef, 1); #TIMEOUT 1 sec
	    
	    if (vec($rout, fileno($sock), 1)) {
		$sock->recv($rsp{'msg'},32, MSG_DONTWAIT);
		$rsp{'status'} = 'OK';
	    } else {
		$rsp{'status'} = 'TIMEOUT';
		$rsp{'msg'} = 'No answer';
	    }
	} else {
	    $rsp{'status'} = 'ERROR';
	    $rsp{'msg'} = "Can't send: $!";
	}
	close($sock);
    } else {
	$rsp{'status'} = 'ERROR';
	$rsp{'msg'} = "Couldn't connect: $@";
    }
    
    return %rsp;
}# auth_vokr


my %rsp = &auth_vokr('1111t', '64598731654648797461684');
print $rsp{'status'} . ':' .  $rsp{'msg'} . "\n";
