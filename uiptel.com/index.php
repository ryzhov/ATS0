<?php
require_once './config.php';
require_once CLASS_PATH . '/Date.php';
require_once CLASS_PATH . '/Session.php';
require_once CLASS_PATH . '/DOMDoc.php';
require_once CLASS_PATH . '/BaseModule.php';
require_once CLASS_PATH . '/CompanyModule.php';
require_once CLASS_PATH . '/ServiceModule.php';
require_once CLASS_PATH . '/ConnectModule.php';
require_once CLASS_PATH . '/BillModule.php';
require_once CLASS_PATH . '/ContactModule.php';

$ss = Session::getInstance();
Date::init();
$doc = new DOMDoc('1.0', 'UTF-8');
$doc->formatOutput = true;
$doc->preserveWhiteSpace = true;

$doc->load('template.xml');
$head = $doc->getElementsByTagName('head')->item(0);
$body = $doc->getElementsByTagName('body')->item(0);

$ma = array( 
    'base'	=> new BaseModule('./base'), 
    'company'	=> new CompanyModule('./company'),
    'service'	=> new ServiceModule('./service'),
    'connect'	=> new ConnectModule('./connect'),
    'bill'	=> new BillModule('./bill'),
    'contact'	=> new ContactModule('./contact')
);

# -- make module selection accordinly to user option --
if (isset($_GET['op']) && isset($ma[$_GET['op']])) {
    $option = $_GET['op'];
} else {
    $option = 'company';
}

$ma[$option]->select();


# -- Include CSS files into $doc from required modules --
foreach ($ma as $mod) {
    if ($mod->required()) {
	foreach ($mod->cssFiles as $file) {
	    $link = $head->appendChild($doc->createElement('link'));
	    $link->setAttribute('type', 'text/css');
	    $link->setAttribute('rel', 'stylesheet');
	    $link->setAttribute('href', $file);
	}
    }
}

# -- Include JS files into $doc from required modules --
foreach ($ma as $mod) {
    if ($mod->required()) {
	foreach ($mod->jsFiles as $file) {
	    $link = $head->appendChild($doc->createElement('script'));
	    $link->setAttribute('type', 'text/javascript');
	    $link->setAttribute('src', $file);
	}
    }
}
# -- Make title of document --
$title = $head->appendChild($doc->createElement('title'));
$title->appendChild($doc->createTextNode(DOMAIN . ' - ' . $ma[$option]->getMenu()));

# -- Make base document structure --
$body->appendChild($doc->importNode($ma['base']->getContent(), true));

# -- Make main menu --
$left = $doc->getElementById('left');
$center = $doc->getElementById('center');

if(isset($left)) {
    foreach ($ma as $op => $mod) {
	$menu = $mod->getMenu();
	if (isset($menu)) {
	    $div = $left->appendChild($doc->createElement('div'));
	    $div->setAttribute('class', 'menuItem');
	    $a = $div->appendChild($doc->createElement('a'));
	    $a->setAttribute('href', '?op='.$op);
	    if ($mod->selected()) {
		$a->setAttribute('class', 'selected');
		$content  = $mod->getContent();
		if (isset($content)) {
		    $center->nodeValue = null;
		    $center->appendChild($doc->importNode($content, true));
		}
	    } else {
		$a->setAttribute('class', 'unselected');
	    }
	    $a->appendChild($doc->createTextNode($menu));
	}
    }
}

echo $doc->saveHTML();
?>
