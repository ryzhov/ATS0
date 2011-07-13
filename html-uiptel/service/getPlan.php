<?php
require_once '../config.php';
require_once CLASS_PATH . '/Session.php';
require_once CLASS_PATH . '/DOMDoc.php';

$ss = Session::getInstance();
$doc = new DOMDoc('1.0', 'UTF-8');
$doc->load('plan_attr.html');

# -- init params --
$plan_id = isset($_GET['plan_id']) ? $_GET['plan_id'] : null;
$phone = isset($_GET['phone']) ? $_GET['phone'] : null;

if (isset($plan_id) and isset($phone)) {
    if ($ss->user->isPlanAuth($plan_id)) {
	$q = "SELECT (getcost).dir, (getcost).dir_name, (getcost).cost  from (SELECT getcost($plan_id,'$phone')) r";
	$row = DB::select($q);
	if (isset($row[0])) {
	    $row = $row[0];
	    $plan_attr_dir = $doc->getElementById('plan_attr_dir');
	    $plan_attr_dir->nodeValue = $row['dir'] . " " . $row['dir_name'];
	    $plan_attr_cost = $doc->getElementById('plan_attr_cost');
	    $plan_attr_cost->nodeValue = $row['cost'];
	}

    }
}


echo $doc->saveHTML();
?>
