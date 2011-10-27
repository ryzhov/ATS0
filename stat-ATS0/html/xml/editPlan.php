<?php
#######################################################################
#
# editPlan.php - edit Plan attributes for Admins only.
#
# Parameters:
#  id  -  select plan by id to operate on
#######################################################################

require_once $_SERVER['ATS0'] . '/classes/DB.php';
require_once $_SERVER['ATS0'] . '/classes/Session.php';
require_once $_SERVER['ATS0'] . '/classes/GMatrix.php';

$ss = Session::getInstance();

# -- initialize parameters -----------------------------------------
$plan_id = isset($_GET['plan_id'] ) ? $_GET['plan_id'] : null;
$oper = isset($_POST['oper']) ? $_POST['oper'] : null;
$dir  = isset($_POST['dir']) ? $_POST['dir'] : null;
$valid  = isset($_POST['valid']) ? $_POST['valid'] : '1970-01-01 00:00:00';
$valid = ($valid === '') ? '1970-01-01 00:00:00' : $valid;
$cost = isset($_POST['cost']) ? $_POST['cost'] : '0.0';
$rsp = null;
$query = null;

if ($ss->isAdmin() && isset($plan_id) && isset($dir)) {
    switch ($oper) {
    case 'del':
	$query  = 'DELETE FROM plan_attr WHERE id=' . $plan_id . ' AND';
	$query .= ' dir=\'' . $dir . '\' AND valid=\'' . $valid . '\'';

	break;
    case 'add':
	$query  = 'INSERT INTO plan_attr VALUES(' . $plan_id . ',\'' . $dir;
	$query .= '\',\'' . $valid . '\',' . $cost . ')';
	break;
    }
    if (isset($query)) {
	$num = DB::query($query);
	$rsp = new GMatrix('PlanEdit','PlanEditItem',
	    array(array('affected_rows' => $num)));
    }
}


# -- print out XML doc --
header("content-type: text/xml; charset=utf-8");
$xml = '<?xml version="1.0" encoding="utf-8"?>' . "\r\n";
$xml.= "<common>\r\n";
$xml.= isset($rsp) ? $rsp->toXML() : '';
$xml.= "</common>\r\n";
echo $xml;
?>
