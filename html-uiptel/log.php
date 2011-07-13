<?php
$lines = 700;
$cmd = "tail -n $lines asterisk.log";
$handle = popen($cmd, "r");

header("content-type: text/html; charset=utf-8");
echo "<pre>";

if ($handle) {
    for($i=0; $i < $lines; ++$i) {
	$line = fgets($handle);
	echo $line;
    }
    fclose($handle);
}

echo "</pre>";


?>
