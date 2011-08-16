#!/usr/bin/perl -w
#### /usr/local/etc/opensips/perlfunctions.pl
#
#
use IO::Socket;
use OpenSIPS qw ( log );
use OpenSIPS::Constants;
use strict;

#### {"user_id":1212,"auth_key":"ashgfasgfaisygfasiygf"}
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
	    select($rout = $rin, undef, undef, 0.4); #TIMEOUT 0.4 sec
	    
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

sub authorize {
    my $m = shift;
    my $auth = $m->getHeader("Authorization");
    my $authType;
    my $res = 'defined';
    my %params;

    log(L_INFO, "authorize::".$m->getMethod());
    
    
    if (defined($auth)) {

	if ($auth =~ /^(\w+)\s+(.*)$/) {
	    $authType = $1;
	    %params = map { if (/^(\w+)="?([^"]+)"?$/) {($1,$2)} } split /,\s*/, $2;
	}
	
	log(L_INFO,"authType[$authType]");

	my ($str,$key);
	foreach $key (sort keys %params) {
	    $str .= "$key($params{$key}) ";
	}
	log(L_INFO,$str);

	if ($authType eq 'Digest') {
	    if ($params{'username'} && $params{'response'}) {
		my %rsp = &auth_vokr($params{'username'}, $params{'response'});
		log(L_INFO,"$params{'username'}:$params{'response'} -> $rsp{'status'}:$rsp{'msg'}");
	    } else {
		log(L_INFO,"unsufisient credentials");
	    }
	}


    } else {
	$res = 'undefined';

    }
    
    log(L_INFO, "authorize::res=".$res);
    OpenSIPS::AVP::add('auth', $res);
    return 1;
}#authorize
