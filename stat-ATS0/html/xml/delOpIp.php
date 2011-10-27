<?php
header("content-type: text/xml");

$ips=(empty($_GET['ips']))?"":$_GET['ips'];
$ipx=array();
$n=0;


while(($pos1=strpos($ips,"d"))!==false) {
    $pos2 = strpos($ips,":");
    if($pos2>$pos1) {
	$ipx[$n] = substr($ips,$pos1+1,$pos2-$pos1-1);
	++$n;
    }
    $ips = substr($ips, $pos2+1, strlen($ips)-$pos2-1);
}

echo <<<HTML
<?xml version="1.0" encoding="utf-8"?>
<common>
HTML;

if ($n > 0) {
    $dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
    for( $i=0; $i<$n; ++$i) {
	$query = "DELETE FROM operator_ip WHERE ip='".$ipx[$i]."'";
	if (pg_affected_rows(pg_query($dbconn,$query))) {
	    
echo <<<HTML

<ip>{$ipx[$i]}</ip>

HTML;
	}
    }
    pg_close($dbconn);
}

echo <<<HTML

</common>
HTML;
?>
