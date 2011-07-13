<?php
header("content-type: text/xml");

$dir=(empty($_GET['dir']))?"":$_GET['dir'];
$dir_name=(empty($_GET['dir_name']))?"":$_GET['dir_name'];

if((!empty($dir))&&(!empty($dir_name))&&ctype_digit($dir)) {
	$dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
	$query = "INSERT INTO direction (dir,dir_name) VALUES ('".$dir."','".$dir_name."')";
	pg_query($query);
	$query = "SELECT dir,dir_name FROM direction WHERE dir='".$dir."'";
	$result = pg_query($query);
	$line = pg_fetch_array($result, null, PGSQL_NUM);
	pg_close($dbconn);
}
else {
    $line[1]=$line[0]="undefined";
}



echo <<<HTML
<?xml version="1.0" encoding="utf-8"?>
<common>
<dir>{$line[0]}</dir>
<dirName>{$line[1]}</dirName>
</common>

HTML;

?>
