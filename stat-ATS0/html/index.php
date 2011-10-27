<?php
require_once $_SERVER['ATS0'] . '/classes/DB.php';
require_once $_SERVER['ATS0'] . '/classes/Session.php';
require_once $_SERVER['ATS0'] . '/classes/Module.php';

$ss = Session::getInstance();

if ($ss->isAuth()) {
    $ma = array(
	'base' => new Module('./base'),
	'auth' => new Module('./auth'),
	'stat' => new Module('./stat'),
	'plan' => new Module('./plan'),
	'dir' => new Module('./dir'),
	'bill' => new Module('./bill')
    );
    # -- select module according to user select --
    $menu = isset($_GET['menu']) ? $_GET['menu'] : 'stat';
    $menu = isset($ma["$menu"]) ? $menu : 'stat';
} else {
    $ma = array(
	'base' => new Module('./base'),
	'auth' => new Module('./auth'),
	);
    # -- select module according to user select --
    $menu = isset($_GET['menu']) ? $_GET['menu'] : 'auth';
    $menu = isset($ma["$menu"]) ? $menu : 'auth';
}

$ma["$menu"]->doSelect();

# -- make html page begins --
$page = file_get_contents('header.html');

# -- js and css include here --
foreach ($ma as $m) {
    if ($m->isSelected() or $m->isBase()) {
	foreach ($m->cssFiles as $cssFile) {
	    $page .= '<link href="'.$cssFile.'" rel="stylesheet" type="text/css"/>'."\r\n";
	}
    }
}
foreach ($ma as $m) {
    if ($m->isSelected() or $m->isBase()) {
	foreach ($m->jsFiles as $jsFile) {
	    $page .= '<script type="text/javascript" src="'.$jsFile.'"></script>'."\r\n";
	}
    }
}

$page.= "</head>\r\n<body>\r\n";
$page.= '<div id="menu">'."\r\n";

# -- user info print out --
$page.= '<span class="date">'.$ss->startDate(). "</span>\r\n";
$page.= '<span id="username">[' . $ss->user->attr['username'] . ']';
$page.= $ss->isAdmin() ? '#' : '$';
$page.= '</span>';

# -- make menu line --
foreach ($ma as $index => $m) {
    if (strlen($m->getMenu()) != 0) {
	$page.= '<span id="menu_'.$index.'"><a href="?menu='.$index.'" class="';
	$page.= $m->isSelected() ? 'selected' : 'unselected';
	$page.= '">'.$m->getMenu()."</a></span>\r\n";
    }
}

$page.= '</div>';

# -- include modules layout --
if (isset($ma["$menu"]->php_layout)) {
    require_once $ma["$menu"]->php_layout;
} else {
    $page.= file_get_contents($ma["$menu"]->layoutFile);
}
$page.= "</body>\r\n</html>\r\n";

# -- print out whole page --
echo $page;
?>
