<?php
#######################################################################
#
# getPlan.php - print out XML document with tarif plan info for customer
#
# Parameters:
#  id  -  select plan attributes by id, if NULL return list of all available plans 
#  date - timestamp to return valid plans attr from this date:time [TODO]
#######################################################################

require_once $_SERVER['ATS0'] . '/classes/DB.php';
require_once $_SERVER['ATS0'] . '/classes/Session.php';
require_once $_SERVER['ATS0'] . '/classes/GMatrix.php';

$ss = Session::getInstance();

# -- initialize parameters -----------------------------------------
$plan_id = isset($_GET['plan_id'] )? $_GET['plan_id'] : null;
$plan = null;

# -- grid interface parameters --
$currPage = isset($_GET['page'] )? $_GET['page'] : '1';
$rows = isset($_GET['rows'] )? $_GET['rows'] : '10';
$sidx = isset($_GET['sidx'] )? $_GET['sidx'] : 'dir';
$sord = isset($_GET['sord'] )? $_GET['sord'] : 'ASC';

if (isset($plan_id)) {

    if ($ss->user->isPlanAuth($plan_id)) {
	$query = 'SELECT count(*) as totalrecords FROM plan_attrs';
	$query.= ' WHERE plan_attrs.id = ' . $plan_id;
	list($tmp) = DB::select($query);
	$totalRecords = isset($tmp['totalrecords']) ? $tmp['totalrecords'] : 0;
	$totalPages = ($rows > 0) ? ceil($totalRecords/$rows) : 1;
	$offset = ($rows*$currPage - $rows) > 0 ? $rows*$currPage - $rows : 0;
	$query  = 'SELECT id as plan_id,dir,dir_name,valid,cost FROM plan_attrs';
        $query .= ' WHERE plan_attrs.id = ' . $plan_id . ' ORDER BY ' . $sidx . ' ' . $sord;
	$query .= ' LIMIT ' . $rows . ' OFFSET ' . $offset;
	$plan = new GMatrix('Plan','PlanAttr',DB::select($query));
    }

} else {
    # -- Get PlanList object for current user --
    $plan = $ss->user->plan;
}


# -- print out XML doc --
header("content-type: text/xml; charset=utf-8");
$xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n";
$xml.= "<common>\r\n";

if (isset($plan_id)) {
    $xml.= "<currentpage>$currPage</currentpage>\r\n";
    $xml.= "<totalpages>$totalPages</totalpages>\r\n";
    $xml.= "<totalrecords>$totalRecords</totalrecords>\r\n";
}

$xml.= isset($plan) ? $plan->toXML() : '';
$xml.= "</common>\r\n";
echo $xml;
?>
