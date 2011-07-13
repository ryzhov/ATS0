<?php
#########################################################################
#
# Abstarct Class Matrix - it is a container
#
#########################################################################

abstract class Matrix implements Iterator,Countable,ArrayAccess {
    protected $objs = array();
    protected $pos = 0;


    abstract public function getName();


    public function toXML() {
	$name = $this->getName();
	$xml = '<'.$name.' amount="' . count($this) . '">' . "\r\n";

	foreach ($this as $obj) {
	    $xml .= $obj->toXML() . "\r\n";
	}
	$xml .= '</'.$name.'>';

	return $xml;
    }//toXML

    public function toSelect($val,$opt) {
	$name = $this->getName();
	
	$xml = '<select id="'.$name.'">' . "\r\n";

	foreach ($this as $row) {
	    $xml .= '<option value="' . $row[$val] . '">';
	    $xml .= htmlentities($row[$opt], ENT_QUOTES,'UTF-8');
	    $xml .= '</option>' . "\r\n";
	}

	$xml .= '</select>';

	return $xml;
    }//toXML


  
    // --- interface Iterator ---
    public function rewind() {
	$this->pos = 0;
    }//rewind

    public function current() {
	return $this->objs[$this->pos];
    }//current

    public function key() {
	return $this->pos;
    }//key

    public function next() {
	++$this->pos;
    }//next

    public function valid() {
	return isset($this->objs[$this->pos]);
    }//valid


    // --- interface Countable ---
    public function count() {
	return count($this->objs);
    }//count

    // --- interface ArrayAccess ---
    public function offsetSet($offset, $value) {
	if ($value instanceof Row) {
	    if ($offset == "") 
		$this->objs[] = $value;
	    else 
		$this->objs[$offset] = $value;
	} else {
	    throw new Exception("Value have to be a instance of the Row object");
	}
    }//offsetSet

    public function offsetGet($offset) {
	return isset($this->objs[$offset]) ? $this->objs[$offset] : null;
    }//offsetGet

    public function offsetUnset($offset) {
	unset($this->objs[$offset]);
    }//offsetUnset

    public function offsetExists($offset) {
	return isset($this->objs[$offset]);
    }//offsetExists

}//class Matrix
?>
