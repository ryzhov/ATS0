<?php
#######################################################################
#
# loadStat.php - print out XML document with Stat Line and CDR log data
#
# Parameters:
#  peer  - peer condition for data select, 
# 	if 0(Zero) all CDRs will be selected, value area is infinity
#  period  - condition for data select, value area: {today,yesterday,month}
#  cdr_table - source of CDR, value area: {ast,gk}
#######################################################################

require_once $_SERVER['ATS0'] . '/classes/DB.php';
require_once $_SERVER['ATS0'] . '/classes/GRow.php';
require_once $_SERVER['ATS0'] . '/classes/GMatrix.php';

#------------ initialize parameters -------------------------------
$period = isset($_GET['period'])?$_GET['period']:'today';
$operator = isset($_GET['operator'])?$_GET['operator']:'0';
$cdr_table = isset($_GET['cdr_table'])?$_GET['cdr_table']:'gk';

#------------ make a query for select appropriate data ------------
if ($cdr_table == 'gk') {
    $query = "SELECT id,setup_time,connect_time,caller_ip,callee_ip,calling,called";
	$query.= ",getDir(called) as dir, getDirName(called) as dirName";
	$query.= ",disc_cause, getDiscName(disc_cause),duration";
	$query.= ",getCostIn(getOp(caller_ip),getDir(called),duration)";
	$query.= ",getCostOut(getOp(callee_ip),getDir(called),duration) FROM call WHERE ";
	switch ($perion) {
	case "month":
	    $query .= "setup_time >=date_trunc('month',current_date-interval '1 day')";
	    $query .= " and setup_time<current_date and connect_time is not null";
	    break;
	case "yesterday":
	    $query .= "setup_time >=(current_date-interval '1 day')";
	    $query .= " and setup_time<current_date and connect_time is not null"; 
	    break;
	case "today":
	    $query .= "setup_time >= current_date";
	    break;
	}

	if ($operator != '0') {
	    $subq = "select ip from operator_ip where operator=".$operator;
	    $result = pg_query($dbconn,$subq);
	    if ($result) {
		$query .= " and (";
		while ($line = pg_fetch_array($result, null, PGSQL_NUM)) {
		    $query .= "caller_ip='".$line[0]."' or ";
		}
		$query .= " false)";
	    }
	}
	$query .= " ORDER BY setup_time DESC";

} else { // make query for asterisk table

    $query = "SELECT id,calldate,dcontext,src,clid,dst";
    $query.= ",(getDirX(dst)).dir, (getDirX(dst)).dirName";
    $query.= ",channel,dstchannel";
    $query.= ",lastapp,lastdata,duration,billsec,disposition";
    $query.= " FROM ast_cdr WHERE ";
    
    switch ($period) {
	case "month":
	    $query .= "calldate >=date_trunc('month',current_date-interval '1 day')";
	    $query .= " and calldate < current_date";
	    break;
	case "yesterday":
	    $query .= "calldate >= (current_date-interval '1 day')";
	    $query .= " and calldate < current_date"; 
	    break;
	case "today":
	    $query .= "calldate >= current_date";
	    break;
	}
    $query.= " ORDER BY calldate DESC";	

}

#-- make objects Stat and CDR_Log -------------------------
$cdrLog = new GMatrix('CDRList','CDRListItem',DB::select($query));

#-- print out XML doc 
header("content-type: text/xml; charset=utf-8");
$xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n\r";
$xml.= "<common>\n\r";
$xml.= $cdrLog->toXML();
$xml.= "</common>\n\r";
echo $xml;
?>
