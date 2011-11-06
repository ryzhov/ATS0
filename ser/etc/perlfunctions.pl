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
    my $req = shift;
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
    my $contact = $m->getHeader("Contact");
    my $authType;
    my $res = 'vokrug';
    my %params;

    
    if (defined($auth)) {

	if ($auth =~ /^(\w+)\s+(.*)$/) {
	    $authType = $1;
	    %params = map { if (/^(\w+)="?([^"]+)"?$/) {($1,$2)} } split /,\s*/, $2;
	}
	
	my ($str,$key);
	foreach $key (sort keys %params) {
	    $str .= "$key($params{$key}) ";
	}
	log(L_INFO, $contact . ' ' . $authType . ' ' . $str);

	if ($contact =~ /.*vokrug_token=?([^;]*)/) {
	    my $auth_key = $1;
	    if ($params{'username'} && $auth_key) {
		my $req = '{"user_id":"'.$params{'username'}.'","auth_key":"'.$auth_key.'"}';
		my %rsp = &auth_vokr($req);
		log(L_INFO,"$req -> $rsp{'status'}:$rsp{'msg'}");
		#$res = 'fail' if ($rsp{'msg'} =~ /^{"result":0}$/);
	    } else {
		log(L_INFO,"vokrug_auth unsuf user($params{'username'}) key($auth_key)");
		#$res = 'digest';
	    }
	} else {
	    log(L_INFO,"general authentication");
	    $res = 'digest';
	}
    } else {
	log(L_INFO, $contact . ' auth undefined');
	$res = 'undefined';
    }
    
    #log(L_INFO, "res=".$res);
    OpenSIPS::AVP::add('auth', $res);
    return 1;
}#authorize
