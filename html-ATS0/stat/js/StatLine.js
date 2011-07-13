//---- class StatLine ---------------------------------------------------

function StatLine(el) {
    this.attr = [];
    this.value = [];

// ------------- Constructor ------------------------

    var node = el.firstChild;
    var i = 0;
    
    while (node != null) {
	if (node.nodeType == 1) {
	    this.attr[i] = node.nodeName;
	    this.value[i] = (node.firstChild != null) ? node.firstChild.nodeValue : 'xx';
	    ++i;
	}
	node = node.nextSibling;
    }

}//StatLine
