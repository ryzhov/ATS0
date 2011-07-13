<?php
header("content-type: text/xml; charset=utf-8");

$dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
$query = "SELECT dir,dir_name FROM direction ORDER BY dir";
$result = pg_query($dbconn,$query);
pg_close($dbconn);


echo <<<HTML
<?xml version="1.0" encoding="utf-8"?>
<common>

HTML;

if ($result) {
    while ($line = pg_fetch_array($result, null, PGSQL_NUM)) {
	echo "<Direction>\n";
	echo "<dir>".$line[0]."</dir>\n";
	echo "<dirName>".str_replace("&","&amp;",$line[1])."</dirName>\n";
	echo "</Direction>\n";
    }
}

echo <<<HTML
</common>
HTML;
?>
