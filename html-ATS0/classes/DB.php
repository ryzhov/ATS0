<?php
require_once $_SERVER['ATS0'] . '/config.php';
require_once $_SERVER['ATS0'] . '/classes/DBException.php';

class DB {

    private static $instance = null;
    private static $connection = null;
    
    private function __construct() {
    }

    private function __clone() {
	trigger_error('Clone objects of this type protected', E_USER_ERROR);
    }
    
    public static function getInstance() {
	return (self::$instance === null) ?
	    self::$instance = new self() :  self::$instance;
    }

    private static function connect() {
	if (!isset(self::$connection)) {
	    if ((self::$connection = pg_pconnect(DB_URL)) === FALSE) {
		self::$connection = null;
		throw new DBException(pg_last_error());
	    }
	}
    }

    public function __destruct() {
    }

    public static function select($query = "") {
	$list = array();

	if ($query !== "") {
	    self::connect();
	    if (($result = pg_query(self::$connection,$query)) === FALSE) {
		throw new DBException(pg_last_error(self::$connection) . "\n" . $query);
	    }
	    if (pg_num_fields($result)) {
		while ($row = pg_fetch_array($result, NULL, PGSQL_ASSOC)) {
		    $list[] = $row;
		}
	    }
	}

	return $list;

    }

    public static function query($query = "") {
	$affected_rows = 0;

	if ($query !== "") {
	    self::connect();
	    if (($result = pg_query(self::$connection,$query)) === FALSE) {
		throw new DBException(pg_last_error(self::$connection) . "\n" . $query);
	    }
	}

	$affected_rows = pg_affected_rows($result);
	return "$affected_rows";
    }
}

?>
