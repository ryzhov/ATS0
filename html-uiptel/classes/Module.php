<?php
require_once CLASS_PATH . '/Session.php';
require_once CLASS_PATH . '/DOMDoc.php';

abstract class Module {
    protected $folder;
    private $name; 
    private $selected;
    private $required;
    private $menu;

    public $jsFiles = array();
    public $cssFiles = array();
    
   
    public function __construct($folder) {
	$this->folder = $folder;
	$this->name = 'noname';
	$this->menu = null;
	$this->selected = false;
	$this->required = false;

	# -- make jsFiles array --
	$this->makeFilesArr($this->jsFiles, $this->folder.'/js', '/\.js$/');
	
	# -- make cssFiles array --
	$this->makeFilesArr($this->cssFiles, $this->folder.'/css', '/\.css$/');

	# -- recognize property.xml file --
	$file = $this->folder.'/property.xml';
	if (is_readable($file) && is_file($file)) {
	    $doc = new DOMDocument();
	    if ($doc->load($file)) {
		if (Session::isAuth()) {
		    $doc = $doc->getElementsByTagName('user')->item(0);
		} else {
		    $doc = $doc->getElementsByTagName('guest')->item(0);
		}
		
		$this->menu = $this->getElementValue($doc,'menu');
		$this->name = $this->getElementValue($doc,'name');
		$this->required = ($this->getElementValue($doc,'required') == 'enable') ? true : false;
	    }
	}
    }#__construct

    private function getElementValue($doc,$tag) {
	$node = $doc->getElementsByTagName($tag)->item(0);
	return isset($node) ? $node->nodeValue : null;
    }

    private function makeFilesArr(&$ar, $folder, $mask) {
	if (is_dir($folder)) {
	    $dirs = scandir($folder);
	    if (false !== $dirs) {
		foreach($dirs as $file) {
		    if (($file === '..') || ($file === '.')) continue;

		    $file = $folder.'/'.$file;
		    if (is_readable($file) && is_file($file) && preg_match($mask,$file)) {
			$ar[] = $file;
		    } else {
			if (is_dir($file)) {
			    $this->makeFilesArr($ar, $file, $mask);
			}
		    }
		}
	    }
	}
    }#makeFilesArr

    public function getMenu() {
	return $this->menu;
    }

    public function getName() {
	return $this->name;
    }

    public function select($flag = true) {
	$this->selected = $flag;
	if ($this->selected) {
	    $this->required = true;
	}
    }

    public function selected() {
	return $this->selected;
    }

    public function required() {
	return $this->required;
    }

    public function getContent() {
	$doc = new DOMDoc('1.0', 'UTF-8');
	$file = $this->folder . '/content.xml';

	if (is_readable($file) && is_file($file)) {
	    $doc->load($file);
	} else {
	    $doc = FALSE;
	}

	if ($doc === FALSE) {
	    $doc = null;
	} else {
	    $doc = $doc->documentElement;
	}

	return $doc;
    }
}
?>
