<?php
header("content-type: text/xml");

$ip=(empty($_GET['ip']))?"":$_GET['ip'];
$op=(empty($_GET['op']))?"":$_GET['op'];


echo <<<HTML
<?xml version="1.0" encoding="utf-8"?>
<common>

HTML;
if(($op!="")&&(ip2long($ip)!==FALSE)) {
    $dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
    $query = "INSERT INTO operator_ip VALUES ('".$ip."',".$op.")";
    if (pg_affected_rows(pg_query($dbconn,$query))) {
	echo "<ip>".$ip."</ip>\n";
    }
    pg_close($dbconn);
}

echo "</common>\n";
HTML;
?>
