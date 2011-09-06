<?php
require_once $_SERVER['ATS0'] . '/config.php';
require_once $_SERVER['ATS0'] . '/classes/User.php';
require_once $_SERVER['ATS0'] . '/classes/Date.php';

class Session implements ArrayAccess {
    private static $instance = null;
    private $cookie = null;
    public $user = null;
    
    private function __construct() {
	$this->cookie['lifetime'] = 3600*24*7; // one week
	$this->cookie['path'] = '/';
	$this->cookie['domain'] = '.'.DOMAIN;

	session_name(SESS_NAME);
	session_set_cookie_params($this->cookie['lifetime'],$this->cookie['path'],$this->cookie['domain']);
	session_start();

	if (!isset($_SESSION['start_ts'])) {

	    $ts = new Date();

	    # -- Initialize new Session -- 
	    $_SESSION['start_ts'] = $ts->getTs();
	    $_SESSION['start_ts_str'] = $ts->getDate();
	    $_SESSION['auth_state'] = 'guest';
	    $_SESSION['user_id'] = GUEST_USER_ID; 
	}

	# -- Initialize new User object --
	$this->user = User::getInstance($_SESSION['user_id']);
    }

    private function __clone() {
	trigger_error('Clone objects of this type protected', E_USER_ERROR);
    }

    public static function getInstance() {
	return (self::$instance === null) ?
	    self::$instance = new self() :  self::$instance;
    }

    public function startUserSession($row) {
	$login_key = $_SESSION['login_key'];

	# Unset all session variable
	$_SESSION = array();

	# Destroy session
	session_destroy();

	# New session name
	session_name(SESS_NAME);

	# New session id
	session_id($login_key);

	# Start Session
	session_start();

	$ts = new Date();

	# Initialize session 
	$_SESSION['start_ts'] = $ts->getTs();
	$_SESSION['start_ts_str'] = $ts->getDate();
	$_SESSION['auth_state'] = 'user';
	$_SESSION['user_id'] = $row['id'];
	$_SESSION['login_key'] = $login_key;

	# Destroy old User object
	$this->user->__destruct();

	# Initialize new User object
	$this->user = User::getInstance($_SESSION['user_id']);

    }# startUserSession

    public function endUserSession() {

	if ($_SESSION['auth_state'] === 'user') {

	    # Destroy session completely
	    $this->destroy();

	    # Destroy old User object
	    $this->user->__destruct();
	    $this->user = null;

	} else {

	    throw new Exception('User session not exist, auth_state=' . $_SESSION['auth_state']);

	}
    }

    public static function isAuth() {
	return isset($_SESSION['auth_state']) ? $_SESSION['auth_state']=== 'user' : false;
    }
    
    public function isAdmin() {
	return isset($this->user->attr['credentials']) ? $this->user->attr['credentials'] === '0' : false;
    }

    public function destroy() {
	# Generate new session id.
	session_regenerate_id();
	
	# Unset all of the session variables.
	$_SESSION = array();

	# Also delete the session cookie.
	if (isset($_COOKIE[session_name()])) {
	    setcookie(session_name(), '', time()-86400, '/');
	}

    }# destroy

    public function startDate() {
	return date("G:i d F Y T",$_SESSION['start_ts']);
    }

    # --- interface ArrayAccess ---
    public function offsetSet($offset, $value) {
	if ($offset == "") {
	    $_SESSION[] = $value;
	} else {
	    $_SESSION[$offset] = $value;
	}
    }

    public function offsetGet($offset) {
	return isset($_SESSION[$offset]) ? $_SESSION[$offset] : null;
    }
    
    public function offsetUnset($offset) {
	unset($_SESSION[$offset]);
    }
    
    public function offsetExists($offset) {
	return isset($_SESSION[$offset]);
    }
}
?>
