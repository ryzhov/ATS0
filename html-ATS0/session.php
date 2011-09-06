<?php

require_once $_SERVER['ATS0'] . '/classes/Session.php';

$ss = Session::getInstance();

foreach($_SESSION as $key => $val) {
    echo "<div>key=$key val=";
    var_dump($val);
    echo "</div>\n";
}

?>
