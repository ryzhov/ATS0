<?php

require_once $_SERVER['ATS0'] . '/classes/Row.php';

class GRow extends Row {

    private $name = null;

    public function __construct($name, array $row ) {
	parent::__construct($row);
	$this->name = $name;
    }

    public function getName() {
	return $this->name;
    }

}//class CDR

?>
