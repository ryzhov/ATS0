<?php
require_once $_SERVER['ATS0'] . '/classes/GMatrix.php';

class Bill extends GMatrix {
    
    public function toXML() {
	$xml = parent::toXML();
	$cost = 0;
	$billsec = 0;

	foreach($this as $row) {
	    $cost += $row['cost'];
	    $billsec += $row['billsec'];
	}

	$xml .= '<Cost>' . round($cost,2) . '</Cost>' . "\r\n";
	$xml .= '<BillSec>' . $billsec . '</BillSec>' . "\r\n";

	return $xml;
    }//toXML
}
?>
