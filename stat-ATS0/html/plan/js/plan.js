
function plan() {
    var lastsel = 0;
    //
    // -- bind handler to SELECT change event --
    //
    $('#PlanList').bind('change', changePlan);
    
    //
    // -- make table for plan attributes --
    //
    var id = $('#PlanList option:selected').attr('value');
    
    $("#plan_attr").jqGrid({
	url: '/xml/getPlan.php?plan_id=' + id,
	editurl: '/xml/editPlan.php?plan_id=' + id,
	caption: 'Plan Attributes',
	datatype: 'xml',
	viewrecords: true,
	altRows: true,
	height: '100%',
	mtype: 'GET',
	colNames: ['Plan_id', 'Dir','Dir Name', 'Valid From','Cost'],
	colModel: [ 
		{
			hidden: true, name:'plan_id', index:'plan_id', width:50,
			sortable:false, xmlmap:'plan_id',editable:false, 
			editoptions:{readonly:true,size:10}
		},

		{
			name:'dir', index:'dir', width:120, xmlmap:'dir',
			editable:true, edittype:'select', 
			editoptions: {
				dataUrl: '/xml/getDirSelect.php' 
			}
		},

		{
			name:'dir_name', index:'dir_name', width:390, sortable:false,
			xmlmap:'dir_name'
		},

		{
			name: 'valid', index: 'valid', width: 180, align: 'right',
			xmlmap: 'valid', editable: true, editoptions: {size:20},
			editrules: {required: false, date: true},
			formoptions: {elmsuffix: ' date in format "Y-m-d", default: 1970-01-01'}
		},
		
		{
			name:'cost', index:'cost', width:80, align:'right', xmlmap:'cost',
			editable:true, editoptions:{size:10},
			editrules: {required: true, number: true}
		}
	],
	pager: '#pager',
	rowNum: 15,
	rowList: [15,40,100,500],
	sortname: 'dir',
	sortorder: 'asc',
	viewrecords: true,
	xmlReader: { 
		root:"Plan",
		row:"PlanAttr",
		page:"common>currentpage",
		total:"common>totalpages",
		records:"common>totalrecords",
		repeatitems:false }
	
	});

    	//
	// -- make Navigator panel for Plan table --
	//
	$("#plan_attr").jqGrid(
		'navGrid',
		'#pager',
		{
			addtext: 'Add', addtitle: 'Add Plan Record',
			deltext: 'Delete', deltitle: 'Delete Plan Record',
			refreshtext: 'Reload', refreshtitle: 'Reload Plan Records',
			edit: false, search: false
		},
		{},
		// add options
		{
			modal: true, top: 180, left: 130, width: 750
		},
		// del options
		{
			modal: true, top: 180, left: 130, onclickSubmit: delSubmit
		},
		{}
	);
	
}//plan


function delSubmit() {
    var id = jQuery("#plan_attr").jqGrid('getGridParam','selrow');
    
    if (id) {
	var ret = jQuery("#plan_attr").jqGrid('getRowData',id);
    }
    
    return { dir:ret.dir, valid:ret.valid };
}//delSubmit

function changePlan(event) {
    var planId = $(event.target).attr('value');
    
    $('#plan_attr').jqGrid(
	    'setGridParam',
	    {
		url: '/xml/getPlan.php?plan_id=' + planId,
		editurl: '/xml/editPlan.php?plan_id=' + planId,

	    }
	    ).trigger('reloadGrid');

}//changePlan
