<?php
header("content-type: text/xml");

$op=$_GET['op'];
$dir=$_GET['dir'];
$zone=$_GET['zone'];
$costIn=$_GET['costIn'];
$costOut=$_GET['costOut'];


echo <<<HTML
<?xml version="1.0" encoding="utf-8"?>
<common>

HTML;

if((is_numeric($dir))&&(is_numeric($costIn))&&(is_numeric($costOut))) {
    $dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
    $query = "INSERT INTO plan VALUES (".intval($op).",'".$dir."',".intval($zone).",'{".$costIn."}','{".$costOut."}')";
    if (pg_affected_rows(pg_query($dbconn,$query))) {
	echo "<Plan>".$dir."</Plan>\n";
    }
    pg_close($dbconn);
}
else {
    echo "<Else>\n";
    echo "<op>".is_int((int)$op)."</op>\n";
    echo "<dir>".is_numeric($dir)."</dir>\n";
    echo "<zone>".is_int($zone)."</zone>\n";
    echo "<costIn>".$costIn."</costIn>\n";
    echo "<costOut>".$costOut."</costOut>\n";
    echo "</Else>\n";
}

echo "</common>\n";
?>
