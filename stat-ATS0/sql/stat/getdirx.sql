CREATE OR REPLACE FUNCTION getdirx(text) RETURNS dirset
    LANGUAGE plperl STABLE
    AS $_$
use strict;
my ($dst) = @_;
my $mlen = 0;
my ($dir,$dirName,$rv,$query);
my $diref;

if ($dst =~ /^\*\d+/) {
    $dst = substr $dst,1,length($dst)-1;
}
if ($dst =~ /^0[1-9]\d*/) {
    $diref = {dir => '0', dirname => 'local Donetsk'};
}
if ($dst =~ /^00[1-9]\d*/) {
    $diref = {dir => '00', dirname => 'local Ukraine'};
}
if ($dst =~ /^1\d\d\d#?$/) {
    $diref = {dir => '1xxx', dirname => 'VN Office'};
}
if ($dst =~ /^22\d\d#?$/) {
    $diref = {dir => '22xx', dirname => 'Donetsk Office'};
}
if ($dst =~ /^23\d\d#?$/) {
    $diref = {dir => '23xx', dirname => 'Donetsk Users'};
}
if ($dst =~ /^29\d\d#?$/) {
    $diref = {dir => '29xx', dirname => 'Donetsk Groups'};
}

unless (defined($diref)) {
  $query = "SELECT max(length(dir)) as mlen  FROM direction WHERE position(dir in '$dst')=1";
  $rv = spi_exec_query($query, 1);
  $mlen = $rv->{rows}[0]->{mlen} if defined($rv->{rows}[0]->{mlen});

  if ($mlen>0) {
    $query = "SELECT dir,dir_name FROM direction WHERE position(dir in '$dst')=1 AND length(dir)=$mlen";
    $rv = spi_exec_query($query, 1);
    if (defined($rv->{rows}[0]->{dir})) {
	$dir = $rv->{rows}[0]->{dir};
	$dirName = $rv->{rows}[0]->{dir_name};
    } else {
        $dir = -1;
	$dirName = 'unknown';
    }
  } else {
    $dir = '-1';
    $dirName = 'unknown';
  }
  $diref = {dir => $dir, dirname => $dirName};
}

return $diref;
$_$;
