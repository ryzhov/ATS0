function service() {
    $('a.service_menu_item').bind('click', clickHandler);
}// service

function clickHandler() {
    var id = $(this).attr('id');

    $('a.service_menu_item').removeClass('service_menu_item_selected');
    $(this).addClass('service_menu_item_selected');

    switch (id) {
	case 'service_voip':
	     $.get('/service/voip.php',
		     {},
		     function(rsp) {
			    $("#service_content").html(rsp);
		     },
		     'html'
		     );
	     break;
	case 'service_solution':
	     $.get('/service/solution.html',
		     {},
		     function(rsp) {
			    $("#service_content").html(rsp);
		     },
		     'html'
		     );
	     break;
    }
    return false;
}//clickHandler

function getPlanHandler() {
    var plan_id = $('select#PlanList').attr('value');
    var phone = $('input#PhoneNumber').attr('value');

    $.get('/service/getPlan.php?plan_id=' + plan_id + '&phone=' + phone,
	    {},
	    function(rsp) {
	    	$("table#plan_attr").remove();
	    	$("#voip_plan_form").append(rsp);
	    },
	    'html'
	 );


    return false;
}


$(document).ready(service);
