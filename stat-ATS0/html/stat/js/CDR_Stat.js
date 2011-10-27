//----- class CDR_Stat  --------------------------------------------

function load() {
    var xml,el;
    var i;

    xml = sendSync1("xml/loadStat.php?period="+this.period+"&cdr_table="+this.cdr_table);
     
    el = xml.getElementsByTagName('Stat')[0];
    if (el!=null) {
	this.stat = new StatLine(el);
    }

    el = xml.getElementsByTagName('CDRListItem');
    this.cdr = [];
    for(i=0; i< el.length; i++) {
	this.cdr[i] = new CDR(el[i]);
    }
    return true;
}//load

function initPage() {
    var dl;

    // -- clear Stat Line on page --
    dl=document.getElementById("stat");
    while (dl.lastChild != null) dl.removeChild(dl.lastChild);
    
    // -- clear CDR Table on page --
    dl=document.getElementById("cdr_log");
    while (dl.lastChild != null) dl.removeChild(dl.lastChild);
    dl.appendChild(document.createTextNode("CDR loading ..."));

}//initPage

function doPage() {
    var dl;
    var value, attr;
    var tmpTR, tmpTD, tmpSPAN;
    
    // do Stat line if it is received
    if (this.stat!=null) {
	dl = document.getElementById('stat');
	for (var i = 0; i < this.stat.attr.length; ++i) {
	    tmpSPAN = document.createElement("span");
	    tmpSPAN.appendChild(document.createTextNode(this.stat.attr[i]));
	    tmpSPAN.setAttribute("class","stat");
	    dl.appendChild(tmpSPAN);
	    tmpSPAN = document.createElement("span");
	    tmpSPAN.appendChild(document.createTextNode(this.stat.value[i]));
	    tmpSPAN.setAttribute("class","stat");
	    dl.appendChild(tmpSPAN);
	}
    }

    // clear TABLE id="cdr_log"
    dl=document.getElementById("cdr_log");
    while (dl.lastChild != null) dl.removeChild(dl.lastChild);

    // create CDR header
    if (this.cdr.length > 0) {
	attr = this.cdr[0].attr; 
	tmpTR = document.createElement("tr");
	tmpTR.setAttribute("id","header");
	for (i=0; i < attr.length; ++i) {
	    tmpTD = document.createElement("td");
	    tmpTD.setAttribute("class",attr[i]);
	    tmpTD.appendChild(document.createTextNode(attr[i]));
	    tmpTR.appendChild(tmpTD);
	}
	dl.appendChild(tmpTR);
    }

    // create CDR log
    for (i = 0; i < this.cdr.length; ++i) {
	tmpTR = document.createElement("tr");
        tmpTR.setAttribute("class","cdr");
	for (j = 0; j < this.cdr[i].attr.length; ++j) {
	    value=this.cdr[i].value[j];
	    attr=this.cdr[i].attr[j];

	    tmpTD = document.createElement("td");
	    tmpTD.setAttribute("class",attr);
	    tmpTD.appendChild(document.createTextNode(value));
	    tmpTR.appendChild(tmpTD);
	}//for j
	dl.appendChild(tmpTR);
    }//for i

    return true;
}//doPage

// -- Constructor ---------------------------------------
function CDR_Stat(period,cdr_table) {
    // ------------- properties -------------------------
    this.cdr; 			// array of cdr's
    this.stat;			// statistic object
    this.param = ["today","yesterday","month"];
    this.period = period;
    this.cdr_table = (cdr_table!=null) ? cdr_table : 'ast';

    // ------------- methods ----------------------------
    this.load = load;
    this.initPage = initPage;
    this.doPage = doPage;

    // ------------- local vars -------------------------
    var e;

    // -- highlight selected menu on user page ----------
    for (var i in this.param) {
	e = document.getElementById(this.param[i]);
	e.setAttribute("class","unselected");
    }
    e = document.getElementById(this.period);
    e.setAttribute("class","selected");
}//CDR_Stat
