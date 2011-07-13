<?php
class Module {
    private $name; 
    private $select;
    private $menu;
    private $base;

    public $folder;
    public $jsFiles = array();
    public $cssFiles = array();
    public $layoutFile;
    public $php_layout;
    
   
    public function __construct($folder) {
	$this->folder = $folder;
	$this->name = 'noname';
	$this->menu = '';
	$this->select = false;
	$this->base = false;

	# -- make jsFiles array --
	$this->makeFilesArr($this->jsFiles, $this->folder.'/js', '/\.js$/');
	
	# -- make cssFiles array --
	$this->makeFilesArr($this->cssFiles, $this->folder.'/css', '/\.css$/');
	
	# -- make layoutFile var --
	$this->layoutFile = $this->folder.'/layout.html';

	# -- recognize property.xml file --
	$file = $this->folder.'/property.xml';
	if (is_readable($file) && is_file($file)) {
	    $doc = new DOMDocument();
	    if ($doc->load($file)) {
		$this->php_layout = $this->getElementValue($doc,'php_layout');
		$this->php_layout = isset($this->php_layout) ? $this->folder.'/'.$this->php_layout : null;
		$this->name = $this->getElementValue($doc,'name');
		if (Session::isAuth()) {
		    $this->menu = $this->getElementValue($doc,'menu_user');
		} else {
		    $this->menu = $this->getElementValue($doc,'menu_guest');
		}
		$this->base = ($this->getElementValue($doc,'base') == 'enable') ? true : false;
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

    public function getFolder() {
	return $this->forder;
    }

    public function getName() {
	return $this->name;
    }

    public function doSelect() {
	$this->select = true;
    }

    public function isSelected() {
	return $this->select;
    }

    public function isBase() {
	return $this->base;
    }

}
?>
