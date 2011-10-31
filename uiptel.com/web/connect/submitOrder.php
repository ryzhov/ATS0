<?php
require_once '../config.php';
require_once CLASS_PATH . '/Session.php';
require_once CLASS_PATH . '/DOMDoc.php';

$ss = Session::getInstance();
$doc = new DOMDoc('1.0', 'UTF-8');
$doc->load('response.html');

# -- init params --
$username = isset($_POST['username']) ? $_POST['username'] : null;
$content = isset($_POST['content']) ? $_POST['content'] : null;
$phone = isset($_POST['phone']) ? $_POST['phone'] : null;
$sender_ip = isset($_SERVER['REMOTE_ADDR']) ? $_SERVER['REMOTE_ADDR'] : null;

$order_response = $doc->getElementById('order_response');

try {
    if (!isset($username)) throw new Exception('Название организации или Имя частного лица не указано!');
    if (!isset($content))throw new Exception('Заявка не заполнена!'); 
    if (!isset($phone)) throw new Exception('Контактный телефон не указан!');
    if (!isset($sender_ip)) throw new Exception('IP-адрес отправителя не определен');
    
    $q = "INSERT INTO orders(sender_ip,username,content,phone)";
    $q.= " VALUES('$sender_ip','$username','$content','$phone') RETURNING id, start_ts";
    
    $row = DB::select($q);
    if (isset($row[0]) and isset($row[0]['id'])) {
	$row = $row[0];
	$mes = "Заявка принята, ";
	$mes.= "администратор свяжется с Вами по указанному телефону: " . $phone . ", ";
	$mes.= "не позднее следующего рабочего дня, благодарим за обращение.";
	$order_response->nodeValue = $mes;

	# -- notify Admins --
	$subj = 'new order from ' . $sender_ip . ' at ' . $row['start_ts'] . ' UTC from ' . DOMAIN;
	$mes = 'username: ' . $username . "\r\n";
	$mes.= 'content: ' . $content . "\r\n";
	$mes.= 'phone: ' . $phone . "\r\n";
	mail(ADMIN_EMAIL, $subj, $mes);
    } else {
	throw new Exception('Входящий номер заявки не определен');
    }
} catch (Exception $ex) {
    $order_response->nodeValue = "Произошла ошибка: " . $ex->getMessage();
}




echo $doc->saveHTML();
?>
