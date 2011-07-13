<?php

$m=$_GET['month'];
$y=$_GET['year'];
$o=$_GET['operator'];
$m = (strlen($m)==1)?'0'.$m:$m;
$filename = 'stat_operator_'.$o.'-'.$y.'-'.$m; 

header("Content-type: application/txt");
header("Content-Disposition: attachment; filename=".$filename);

$qcdr = "SELECT calling,setup_time,called,getDir(called),";
$qcdr.= "duration,getCostIn(getOp(caller_ip),getDir(called),duration)";
$qcdr.= " FROM call";
$qcdr.= " WHERE EXTRACT(MONTH FROM setup_time)=".$m;
$qcdr.= " AND EXTRACT(YEAR FROM setup_time)=".$y;
$qcdr.= " AND getOp(caller_ip)=".$o;
$qcdr.= " AND setup_time<current_date";
$qcdr.= " AND connect_time is not null";
$qcdr.= " ORDER BY setup_time";

$qc = "SELECT sum(getCostIn(getOp(caller_ip),getDir(called),duration)),sum(duration)";
$qc.= " FROM call";
$qc.= " WHERE EXTRACT(MONTH FROM setup_time)=".$m;
$qc.= " AND EXTRACT(YEAR FROM setup_time)=".$y;
$qc.= " AND getOp(caller_ip)=".$o;
$qc.= " AND setup_time<current_date";
$qc.= " AND connect_time is not null";

$dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
if ($dbconn) {
    $result = pg_query($qcdr);
    if ($result) {
	while ($l = pg_fetch_array($result, null, PGSQL_NUM)) {
	    printf( "%14s %20s %14s %6s %6s %8s\n", $l[0],$l[1],$l[2],$l[3],$l[4],$l[5]);
	}
    }
    $result = pg_query($qc);
    if ($result) {
	$l = pg_fetch_array($result, null, PGSQL_NUM);
	printf("Total cost: %16s\r\n",$l[0]);
	printf("Total seconds: %16s\r\n",$l[1]);
    }
    pg_close($dbconn);
}


?>
