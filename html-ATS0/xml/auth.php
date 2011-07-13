<?php
###################################################################################
# auth.php do user authentication tasks (login,logout,getkey)
#
# Parameters:
# do -	command that will be done (login,logout,getkey)
# 
# if do=login, 
# user -	User name
# digest -	User password digest 
#
###################################################################################

require_once $_SERVER['ATS0'] . '/classes/DB.php';
require_once $_SERVER['ATS0'] . '/classes/Session.php';

$ss = Session::getInstance();

$do = isset($_GET['do']) ? $_GET['do'] : 'getkey';
$status = 'ok';
$message = '';

header("content-type: text/xml; charset=utf-8");
$xml  = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n";
$xml .= "<auth>\r\n";
$xml .= "<do>".$do."</do>\r\n";

switch($do) {

case 'getkey':
    $key = strtoupper(sha1(uniqid(rand()) . $ss['start_ts']));
    $ss['login_key'] = $key;
    $xml .= "<key>".$key."</key>\r\n";
    $message = 'Login key successfully issued.';
    break;

case 'login':
    $user = isset($_GET['user']) ? $_GET['user'] : '';
    $digest = isset($_GET['digest']) ? strtoupper($_GET['digest']) : '';
    
    try {
	if (is_null($ss['login_key']))
	    throw new Exception('Login key not assigned.');
	if (strlen($user) == 0)
	    throw new Exception('User name not assigned.');
	if (strlen($digest) == 0)
	    throw new Exception('Digest not assigned.');

	$row = DB::select("SELECT * FROM customer WHERE username='$user'");
	
	if (!isset($row[0]))
	    throw new Exception('Incorrect user/password.');

	$row = $row[0];

	$tmp = strtoupper(sha1($ss['login_key'] . $row['pass'] . $ss['login_key']));

	if ($tmp !== $digest)
	    throw new Exception('Incorrect user/password.');

	$ss->startUserSession($row);
	$message = 'User successfully logged in.';


    } catch (Exception $ex) {
	$key = strtoupper(sha1(uniqid(rand()) . $ss['start_ts']));
	$ss['login_key'] = $key;
	$xml .= "<key>".$key."</key>\r\n";
	$status = 'error';
	$message = $ex->getMessage();
    }

    break;

case 'logout':
    try {
	$ss->endUserSession();
	$message = 'User successfully logged out.';

    } catch (Exception $ex) {
	unset($ss['login_key']);
	$status = 'error';
	$message = $ex->getMessage();
    }

    break;

default:
    $status = 'error';
    $message = 'Unknown command.';
}

$xml .= "<status>" . $status . "</status>\r\n";
$xml .= "<message>" . $message . "</message>\r\n";
$xml .= "</auth>\r\n";
echo $xml;
?>
