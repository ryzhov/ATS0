function validateDigit(e) {
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
}
