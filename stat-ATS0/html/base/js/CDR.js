//---- class CDR  ---------------------------------------------------
function getAttr(attr) {
    var key = undefined;
    for (var i = 0; i < this.attr.length; ++i) {
	if (this.attr[i] == attr) {
	    key = i;
	    break;
	}
    }
    return (key == undefined) ? null : this.value[key];
}//getAttr

// -- Constructior ----------------------------------
function CDR(el) {
// ------------- properties -------------------------
    this.attr = [];
    this.value = [];
// ------------- methods ----------------------------

    this.getAttr = getAttr;


// ------------- Constructor ------------------------
    var node = el.firstChild;
    var i = 0;

    while (node != null) {
	if (node.nodeType == 1) {
	    this.attr[i] = node.nodeName;
	    this.value[i] = (node.firstChild != null) ? node.firstChild.nodeValue : '';
	    ++i;
	}
	node = node.nextSibling;
    }


}//CDR
