<?php
#######################################################################
#
# getBill.php - print out XML document with Bill info for customer
#
# Parameters:
#  src  - src as local identificator of customer for data select, 
#  year  - year condition for data select,  {2009,2010,2011,2012, ...}
#  month - month condition for data select, {1,2,3, ...,12}
#######################################################################

require_once $_SERVER['ATS0'] . '/classes/DB.php';
require_once $_SERVER['ATS0'] . '/classes/Bill.php';


# -- initialize parameters -----------------------------------------
$src = isset($_GET['src'])?$_GET['src']:NULL;
$year = isset($_GET['year'])?$_GET['year']:date('Y');
$month = isset($_GET['month'])?$_GET['month']:date('n');

# -- make a query for select appropriate data ----------------------
$query = "SELECT id,calldate,src,dst,(getDirX(dst)).dir as dir,";
$query.= " (getDirX(dst)).dirName as dirName,";
$query.= " billsec,getcostoutx(1,(getDirX(dst)).dir) as plan,";
$query.= " (getcostoutx(1,(getDirX(dst)).dir)*billsec/60)::numeric(10,6) as cost";
$query.= " FROM ast_cdr";
$query.= " WHERE disposition = 'ANSWERED'";
$query.= " AND EXTRACT(MONTH FROM calldate) = ".$month;
$query.= " AND EXTRACT(YEAR FROM calldate) = ".$year;
if (isset($src) and strlen($src)) {
    $query.= " AND src = '$src'";
}
$query.= " ORDER BY calldate ASC";


# -- make object Bill ----------------------------------------------
$bill = new Bill('Bill','BillItem', DB::select($query));

#-- print out XML doc 
header("content-type: text/xml; charset=utf-8");
$xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n";
$xml.= "<common>\r\n";
$xml.= $bill->toXML();
$xml.= "</common>\r\n";
echo $xml;
?>
