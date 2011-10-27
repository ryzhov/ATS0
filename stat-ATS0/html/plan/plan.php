<?php

$page .= $ss->user->plan->toSelect('plan_id','name');
$page .= file_get_contents($ma["$menu"]->folder . '/plan.html');
?>
