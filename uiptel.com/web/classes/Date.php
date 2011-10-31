<?php

class Date {
    private static $request_ts = null;
    private $ts;

    public static function init() {
	self::$request_ts = $_SERVER['REQUEST_TIME'];
	date_default_timezone_set('UTC');
    }

    public function __construct($ts = null) {
	$this->ts = isset($ts) ? $ts : time();
	if (!isset(self::$request_ts)) {
	    self::init();
	}
    }

    public function getTs() {
	return $this->ts;
    }

    public function getDate($format = null) {
	return isset($format) ? date($format,$this->ts) : date('G:i d F Y T',$this->ts);
    }

    public static function request_ts($format = null) {
	return isset($format) ? date($format,self::$request_ts) : date('G:i d F Y T',self::$request_ts);
    }

    public static function set_timezone($tz = 'UTC') {
	if (!date_default_timezone_set($tz)) {
	     trigger_error('timezone unable set to: ' . $tz . ', default timezone: UTC remain', E_USER_ERROR);
	     date_default_timezone_set('UTC');
	}
    }

    public static function get_timezone() {
	return date_default_timezone_get();
    }

}
?>
