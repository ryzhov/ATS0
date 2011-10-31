<?php
require_once CLASS_PATH . '/Module.php';
require_once CLASS_PATH . '/DOMDoc.php';

class BaseModule extends Module {

    public function getContent() {
	$doc = new DOMDoc('1.0', 'UTF-8');
	$doc->load($this->folder . '/content.xml');
	if ($doc === FALSE) {
	    trigger_error('unable load: ' . $this->folder . '/content.xml',  E_USER_ERROR);
	    throw(new Exception('unable load: ' . $this->folder . '/content.xml'));
	}

	$copy_year = $doc->getElementById('copy_year');
	$copy_year->nodeValue = Date::request_ts('Y');

	$bottom_link = $doc->getElementById('bottom_link');
	$bottom_link->setAttribute('href', '/');
	$bottom_link->nodeValue = DOMAIN;
	
	$ss = Session::getInstance();
	$username = $doc->getElementById('username');
	$username->nodeValue = $ss->user->attr['username'];
	
	return $doc->documentElement;
    }
}

?>
