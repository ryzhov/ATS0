function connect() {
    $('input#phone').keypress(validateDigit);
}

function submitOrder() {
    var username = $('input#username').attr('value');
    var content = $('textarea#content').val();
    var phone = $('input#phone').attr('value');

    try {
	if (username.length == 0) { 
	    throw ("Название организации или Имя частного лица не указано!");
	}
	if (content.length == 0) { 
	    throw ("Заявка не заполнена!");
	}
	if (phone.length == 0) { 
	    throw ("Контактный телефон не указан!");
	}
	
	$.post('/connect/submitOrder.php',
	    {username: username, content: content, phone: phone},
	    function(rsp) {
	    	$("table#connect_order_form").remove();
		$("div#connect").append(rsp);
	    },
	    'html'
	);
    } catch (ex) {
	$('td#message_cell').html(ex);
    }
    return false;
}

$(document).ready(connect);
