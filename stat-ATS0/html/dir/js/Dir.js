//------ dir.js -------------------------------------------------------------
var delDir = [];
var n = 0;

//---------------------------------------------------------------------------
function listDirectionListener() {
    var xmlDoc = null;

    if (this.readyState == 4) {
	if (this.status == 200) {
	    if (this.responseXML != null) {
		xmlDoc=this.responseXML.documentElement;
		doList(xmlDoc);
	    }
	    else {
		alert("response XML document empty");
	    }
	}
	else
	    alert("Error code " + this.status + " received: " + this.statusText);
    }
}//listDirectionListener

function doList(xmlDoc) {
    var exml = xmlDoc.getElementsByTagName('Direction');
    var edoc = document.getElementById("content");

    while (true) {
	if (edoc.lastChild != null)
	    edoc.removeChild(edoc.lastChild);
	else
	    break;
    }
    for(i=0;i<exml.length;++i) {
	    dir = exml[i].getElementsByTagName('dir')[0].firstChild.nodeValue;
	    dirName = exml[i].getElementsByTagName('dirName')[0].firstChild.nodeValue;

	    //--- Create new node in html ---
	    divRecord = document.createElement("div");
	    divRecord.setAttribute("class","record");
	    spanDir = document.createElement("span");
	    spanDir.setAttribute("class","direction");
	    spanDirName = document.createElement("span");
	    spanDirName.setAttribute("class","dirName");
	    inputDir = document.createElement("input");
	    inputDir.setAttribute("class","direction");
	    inputDir.setAttribute("type","checkbox");
	    inputDir.setAttribute("id","d"+dir);
	    inputDir.setAttribute("onchange","onChangeBox(this)");
	    
	    spanDir.appendChild(document.createTextNode(dir));
	    spanDirName.appendChild(document.createTextNode(dirName));
	    
	    divRecord.appendChild(inputDir);
	    divRecord.appendChild(spanDir);
	    divRecord.appendChild(spanDirName);
	    edoc.appendChild(divRecord);
    }//for
    return;
}//doList


function listDirection(dirFilter) {
    var req = "xml/listDir.php?dir="+dirFilter;
    sendReq(req,listDirectionListener);
    return;
}//listDirections

function addDirection() {
    var dir=document.getElementById("dir_input");
    var dirName=document.getElementById("dir_name_input");
    var req="xml/addDir.php?dir="+dir.value+"&dir_name="+dirName.value;
    var xmlDoc=null;

    if ((dir.value!="") && (dirName.value!="")) {
	dir.value="";
	dirName.value="";
	xmlDoc = sendSync(req);
	if (xmlDoc!=null) {
	    listDirection();
	    alert("Add dir "+xmlDoc.getElementsByTagName('dir')[0].firstChild.nodeValue);
	}
	else {
	    alert("Fill in empty field");
	}
    }
}//addDirection

function delDirection() {
    var req="xml/delDir.php?dirs=";
    var msg="";
    var i;
    var xmlDoc=null;
    
    for (i=0; i<n; i++) {
	if( delDir[i]=="x") 
	    continue;
	msg += delDir[i]+":";
    }
    if (msg!="") {
	xmlDoc = sendSync(req+msg);
	if (xmlDoc!=null) {
	    listDirection();
	    var element = xmlDoc.getElementsByTagName('dir')[0];
	    msg="";
	    while (element!=null) {
		if(element.nodeName=="dir") {
		    msg += element.firstChild.nodeValue+":";
		}
		element = element.nextSibling;
	    }
	    alert("deleted dirs:"+msg);
	}
    }
}//delDirection

function onChangeBox(obj) {
    var id = obj.getAttribute("id");
    for (i=0; i<n; i++)
	if (delDir[i] == id) {
	    delDir[i]="x";
	    return;
	}
    delDir[n] = id;
    ++n;
}//onChangeBox
