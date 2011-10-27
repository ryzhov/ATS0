<?php
header("content-type: text/xml");

$dirs=(empty($_GET['dirs']))?"":$_GET['dirs'];
$dirx=array();
$n=0;


while(($pos1=strpos($dirs,"d"))!==false) {
    $pos2 = strpos($dirs,":");
    if($pos2>$pos1) {
	$dirx[$n] = substr($dirs,$pos1+1,$pos2-$pos1-1);
	++$n;
    }
    $dirs = substr($dirs, $pos2+1, strlen($dirs)-$pos2-1);
}

echo <<<HTML
<?xml version="1.0" encoding="utf-8"?>
<common>
HTML;

if ($n > 0) {
    $dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
    for( $i=0; $i<$n; ++$i) {
	$query = "DELETE FROM direction WHERE dir='".$dirx[$i]."'";
	if (pg_affected_rows(pg_query($dbconn,$query))) {
	    
echo <<<HTML

<dir>{$dirx[$i]}</dir>

HTML;
	}
    }
    pg_close($dbconn);
}

echo <<<HTML

</common>
HTML;
?>
