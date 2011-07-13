
function init() {
    var el = document.getElementById("year");
    var tmp;

    tmp = document.createElement("option");
    tmp.setAttribute("value", this.year);
    tmp.appendChild(document.createTextNode(this.year));
    el.appendChild(tmp);
    tmp = document.createElement("option");
    tmp.setAttribute("value", this.year-1);
    tmp.appendChild(document.createTextNode(this.year-1));
    el.appendChild(tmp);

    el = document.getElementById("month");
    for (var i=1; i<=12; ++i) {
	tmp = document.createElement("option");
	tmp.setAttribute("value", i);
	if (this.month==i) {
	    tmp.setAttribute("selected", "true");
	}
	tmp.appendChild(document.createTextNode(i));
	el.appendChild(tmp);
    }
}// init

function submit() {
    this.src = document.getElementById("src").value;
    var xml = sendSync1("xml/getBill.php?src="+this.src+"&year="+this.year+"&month="+this.month);
    var el = xml.getElementsByTagName('BillItem');

    this.cdr = [];
    for (var i=0; i< el.length; i++) {
	this.cdr[i] = new CDR(el[i]);
    }

    el = xml.getElementsByTagName('Cost')[0];
    var tmp = (el.firstChild != null) ? el.firstChild.nodeValue : 'undef';
    el = document.getElementById('cost');
    el.innerHTML = 'Total cost: ' + tmp;
    
    el = xml.getElementsByTagName('BillSec')[0];
    tmp = (el.firstChild != null) ? el.firstChild.nodeValue : 'undef';
    el = document.getElementById('billsec');
    el.innerHTML = 'Total billsec: ' + tmp;


    this.createTable();

    //alert("src:"+this.src+" year:"+this.year+" month:"+this.month);
}// submit

function createTable() {
    var el;
    var value, attr;
    var tmpTR, tmpTD, tmpSPAN;

    // clear TABLE
    el=document.getElementById("bill");
    while (el.lastChild != null) el.removeChild(el.lastChild);

    // create TABLE header
    if (this.cdr.length > 0) {
	attr = this.cdr[0].attr;
	tmpTR = document.createElement("tr");
	tmpTR.setAttribute("id","header");
	for (var i=0; i < attr.length; ++i) {
	    tmpTD = document.createElement("td");
	    tmpTD.setAttribute("class",attr[i]);
	    tmpTD.appendChild(document.createTextNode(attr[i]));
	    tmpTR.appendChild(tmpTD);
	}
	el.appendChild(tmpTR);
    }

    //create TABLE Rows
    for (var i=0; i < this.cdr.length; ++i) {
	tmpTR = document.createElement("tr");
	tmpTR.setAttribute("class","cdr");
	for (var j=0; j < this.cdr[i].attr.length; ++j) {
	    value=this.cdr[i].value[j];
	    attr=this.cdr[i].attr[j];
	    tmpTD = document.createElement("td");
	    tmpTD.setAttribute("class",attr);
	    tmpTD.appendChild(document.createTextNode(value));
	    tmpTR.appendChild(tmpTD);
	}//for j
	el.appendChild(tmpTR);
    }//for i
}// createTable

function yearChange(el) {
    this.year = el.options[el.selectedIndex].getAttribute("value");
}

function monthChange(el) {
    this.month = el.options[el.selectedIndex].getAttribute("value");
}

// -- Constructor ---------------------------------------
function BillManager() {

    var now = new Date();
    // ------------- properties -------------------------
    this.year = now.getFullYear();
    this.month = now.getMonth()+1;
    this.src;
    this.cdr;

    // ------------- methods ----------------------------
    this.init = init;
    this.submit = submit;
    this.yearChange = yearChange;
    this.monthChange = monthChange;
    this.createTable = createTable;
}
