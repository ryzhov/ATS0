	$.get('/xml/getPlan.php', 
		{id: 2}, 
		function(response, st, xhr) {
			$('#plan_attr').html(response.documentElement);
		},
		'xml'
	);
	
$.get('/xml/getPlan.php', {},
	function (rsp) {
		var html='';
		$('PlanListItem', rsp.documentElement).each(
		function() {
			html+= '<option value="' + $(this).children("id").text();
			html+= '">' + $(this).children("name").text();
			html+= '</option>';
		});
		$('#plan_select').html(html);
	});
