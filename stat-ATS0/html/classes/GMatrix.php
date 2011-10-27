<?php
require_once $_SERVER['ATS0'] . '/classes/Matrix.php';
require_once $_SERVER['ATS0'] . '/classes/GRow.php';

class GMatrix extends Matrix {

    private $name = null;

    public function __construct($matrixName, $itemName, array $ar) {
	$this->name = $matrixName;
	
	foreach ($ar as $row) {
	    $this[] = new GRow($itemName,$row);
	}
    }
    
    public function getName() {
	return $this->name;
    }

}
?>
