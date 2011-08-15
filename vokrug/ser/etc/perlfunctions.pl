#### /usr/local/etc/opensips/perlfunctions.pl
#
#
use IO::Socket;
use OpenSIPS qw ( log );
use OpenSIPS::Constants;
use strict;


sub sendSipMessage {
    my $ip = shift;
    my $port = shift;
    my $msg = shift;
    my $sock = new IO::Socket::INET (
	PeerAddr  => $ip,
	PeerPort  => $port,
	Proto     => 'udp',
	LocalPort => '5060',
	ReuseAddr => '1' );
    
    return unless $sock;
    print $sock $msg;
    close($sock);
}# sendSipMessage

#### {"user_id":1212,"auth_key":"ashgfasgfaisygfasiygf"}
sub auth_vokr {
    my $req = '{"user_id":' . $_[0] . ',"auth_key":"' . $_[1] . '"}';
    
    my $sock = new IO::Socket::INET (
	PeerAddr => 'vokrug.ru',
	PeerPort => '7000',
	Proto => 'tcp',
    );


    if ($sock) {
	print $sock $req;
	log(L_INFO,"req [" . $req . "]");
	#log(L_INFO, "recv [" . <$sock> . "]");
    } else {
	log(L_INFO,"Error open socket");
    }

    close($sock);
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
	    %params = map { if (/^(\w+)="?([^"]+)"?$/) {($1,$2)} } split /,/, $2;
	}
	
	log(L_INFO,"authType[$authType]");

	if ($authType eq 'Digest') {
	    #&auth_vokr($params{'username'}, $params{'response'});
	}


    } else {
	$res = 'undefined';

    }
    
    log(L_INFO, "authorize::res=".$res);
    OpenSIPS::AVP::add('auth', $res);
    return 1;
}#authorize
