CREATE OR REPLACE FUNCTION getcost(plan_id integer, dst text) RETURNS costset
    LANGUAGE plperl STABLE
    AS $_$
use strict;
my ($plan_id, $dst) = @_;
my ($dir,$dirName,$cost,$rv,$query,$mlen,$mvalid);
my $costset;

$query = "SELECT max(length(dir)) as mlen  FROM plan_attr WHERE position(dir in '$dst')=1 AND id=$plan_id";
$rv = spi_exec_query($query, 1);
$mlen = $rv->{rows}[0]->{mlen} if defined($rv->{rows}[0]->{mlen});

if ($mlen>0) {
    $query = "SELECT max(valid) as mvalid FROM plan_attr WHERE position(dir in '$dst')=1 AND id=$plan_id AND length(dir)=$mlen";
    $rv = spi_exec_query($query, 1);
    $mvalid = $rv->{rows}[0]->{mvalid};
    $query = "SELECT plan_attr.dir,direction.dir_name,plan_attr.cost FROM plan_attr JOIN direction ON";
    $query.= " plan_attr.dir=direction.dir WHERE position(plan_attr.dir in '$dst')=1 AND id=$plan_id";
    $query.= " AND length(plan_attr.dir)=$mlen AND plan_attr.valid='$mvalid'";
    $rv = spi_exec_query($query, 1);
    $dir = $rv->{rows}[0]->{dir};
    $dirName = $rv->{rows}[0]->{dir_name};
    $cost = $rv->{rows}[0]->{cost};
} else {
    $dir = '-1';
    $dirName = 'unknown';
    $cost = 0.00;
}

$costset = {dir => $dir, dir_name => $dirName, cost => $cost};

return $costset;
$_$;
