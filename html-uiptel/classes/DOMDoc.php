<?php
class DOMDoc extends DOMDocument {
    function getElementById($id) {
	$xpath = new DOMXPath($this);
	return $xpath->query("//*[@id='$id']")->item(0);
    }
}
?>
