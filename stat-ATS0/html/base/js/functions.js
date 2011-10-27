
function getHTTPObject() { 
    if (typeof XMLHttpRequest != 'undefined') { 
	return new XMLHttpRequest(); 
    } 
    try { 
	return new ActiveXObject("Msxml2.XMLHTTP"); 
    } 
    catch (e) { 
	try { 
	    return new ActiveXObject("Microsoft.XMLHTTP"); 
	} 
	catch (e) {
	} 
    } 
    return null;
}//getHTTPObject

function sendReq(uri,listener) {
    var xhr = getHTTPObject();

    if (xhr == null ) {
	throw("your browser does not support AJAX");
    } 
    xhr.open("GET",uri,true);
    xhr.setRequestHeader("cache-control", "no-cache");
    xhr.setRequestHeader("pragma", "no-cache");
    xhr.onreadystatechange = listener;
    xhr.send(null);
    return true;
}//sendReq

function sendSync1(uri) {
    var xh = getHTTPObject();

    if (xh == null ) {
	throw("your browser does not support AJAX");
    }

    xh.open("GET",uri,false);
    xh.setRequestHeader("cache-control", "no-cache");
    xh.setRequestHeader("pragma", "no-cache");
    xh.send(null);
    if (xh.status == 200) {
	if (xh.responseXML != null) {
	    return xh.responseXML.documentElement;
	}
	else {
	    throw("response XML document empty");
	}
    }
    else {
	throw("Error code " + xh.status + " received: " + xh.statusText);
    }
    return null;
}//sendSync1

function numsOnly(e) {
    if (window.event) {
	if ((e.keyCode>47) && (e.keyCode<58))
	    return true;
        if ((e.keyCode==27) || (e.keyCode==13))
            return true;
    }
    else {
	if (e.keyCode) {
	    if ((e.keyCode==35) ||
	    (e.keyCode==36) ||
	    (e.keyCode==37) ||
	    (e.keyCode==38) ||
	    (e.keyCode==39) ||
	    (e.keyCode==40) ||
	    (e.keyCode==13) ||
	    (e.keyCode==8)  ||
	    (e.keyCode==9)  ||
	    (e.keyCode==27) ||
	    (e.keyCode==46)) {
		return true;
	    }
	}
	else {
	    if ((e.charCode>47) && (e.charCode<58)) {
		return true;
	    }
	}
    }
    return false;
}//numsOnly

function realOnly(e) {
    if (window.event) {
	if ((e.keyCode>47) && (e.keyCode<58))
	    return true;
        if ((e.keyCode==27) || (e.keyCode==13))
            return true;
    }
    else {
	if (e.keyCode) {
	    if ((e.keyCode==35) ||
	    (e.keyCode==36) ||
	    (e.keyCode==37) ||
	    (e.keyCode==38) ||
	    (e.keyCode==39) ||
	    (e.keyCode==40) ||
	    (e.keyCode==13) ||
	    (e.keyCode==8)  ||
	    (e.keyCode==9)  ||
	    (e.keyCode==27) ||
	    (e.keyCode==46)) {
		return true;
	    }
	}
	else {
	    if ((e.charCode>47) && (e.charCode<58)) {
		return true;
	    }
	    if (e.charCode == 46)
		return true;
	}
    }
    return false;
}//realOnly

