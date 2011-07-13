<?php
require_once CLASS_PATH . '/Matrix.php';
require_once CLASS_PATH . '/GRow.php';

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
