<?php

require_once '../config.php';
require_once CLASS_PATH . '/Session.php';
require_once CLASS_PATH . '/DOMDoc.php';

$ss = Session::getInstance();
$doc = new DOMDoc('1.0', 'UTF-8');
$doc->load('voip.html');
$planList = $doc->getElementById('PlanList');

foreach ($ss->user->plan as $plan) {
    $option = $planList->appendChild($doc->createElement('option'));
    $option->setAttribute('value', $plan['plan_id']);
    $option->nodeValue = $plan['name'];
}

echo $doc->saveHTML();
?>
