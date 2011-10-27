CREATE OR REPLACE FUNCTION getcostoutx(integer,text) RETURNS numeric
    LANGUAGE plperl STABLE
    AS $_$
use strict;
my ($op,$dir) = @_;
my $cost_out = 0;

while(length($dir)>0) {
    my $query = "SELECT cost_out[1] FROM plan WHERE operator=$op AND dir='$dir'";
    my $rv = spi_exec_query($query, 1);
    if (defined($rv->{rows}[0]->{cost_out})) {
	$cost_out = $rv->{rows}[0]->{cost_out};
	last;
    }
    $dir = substr($dir,0,length($dir)-1);
}


return $cost_out;
$_$;
