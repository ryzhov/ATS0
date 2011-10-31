<?php
require_once CLASS_PATH . '/DB.php';
require_once CLASS_PATH . '/GRow.php';
require_once CLASS_PATH . '/GMatrix.php';

class User {

    private static $instance = null;
    public $attr = null;
    public $plan = null;


    private function __construct($user_id) {
	$row = DB::select('SELECT * FROM customer WHERE id = ' . $user_id);
	if (!isset($row[0])) {
	    trigger_error('user_id=' . $user_id . ' not found in table customer', E_USER_ERROR);
	}
	$this->attr = new GRow('UserAttr',$row[0]);
	$this->plan = new GMatrix('PlanList','PlanListItem',
	    DB::select('SELECT plan_id,name||\' (\'||currency||\')\' as name FROM customer_plans WHERE customer_id = ' . $user_id)
	);
    }
    
    private function __clone() {
	trigger_error('Clone objects of this type protected', E_USER_ERROR);
    }

    public static function getInstance($user_id) {
	return (self::$instance === null) ?
	    self::$instance = new self($user_id) :  self::$instance;
    }

    public function isPlanAuth($plan_id) {
	$plan_auth = false;

	foreach ($this->plan as $item) {
	    if ($item['plan_id'] === $plan_id) {
		$plan_auth = true;
		break;
	    }
	}

	return $plan_auth;
    }

    public function __destruct() {
	self::$instance = null;
	$this->attr = null;
	$this->plan = null;
    }
}
?>
