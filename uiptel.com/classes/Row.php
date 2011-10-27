<?php
#########################################################################
#
# Abstarct Class Row - it is container for single row of data
#
# #######################################################################

abstract class Row implements Iterator,Countable,ArrayAccess {
    private $attr = array();
    private $key  = array();
    private $pos = 0;

    public function __construct(array $row) {
	$this->pos = 0; 
	foreach ( $row as $index => $value) {
	    $this->attr[$index] = $value;
	    $this->key[] = $index;
	}
    }//__construct
    

    abstract public function getName();


    # - implement Iterator -
    #
    public function rewind() {
        $this->pos = 0;
    }//rewind

    public function current() {
        return $this->attr[$this->key[$this->pos]];
    }//current

    public function key() {
        return $this->key[$this->pos];
    }//key	

    public function next() {
	++$this->pos;
    }//next
    
    public function valid() {
	//return isset($this->attr[$this->key[$this->pos]]);
	return isset($this->key[$this->pos]);
    }//valid 


    # -- implement Countable --
    #
    public function count() {
	return count($this->key);
    }

    # -- implement ArrayAccess --
    #
    public function offsetSet($offset, $value) {

	if (array_key_exists($offset,$this->attr)) {
	    $this->attr[$offset] = $value;
	} 

    }

    public function offsetGet($offset) {
	return isset($this->attr[$offset]) ? $this->attr[$offset] : null;
    }

    public function offsetUnset($offset) {
	unset($this->attr[$offset]);
    }

    public function offsetExists($offset) {
	return isset($this->attr[$offset]);
    }

    public function toXML() {
	$name = $this->getName();
	$xml = '<'.$name.'>' . "\r\n";
	foreach ($this as $attr => $value) {
	    $xml .= '<'.$attr.'>'.htmlentities($value, ENT_QUOTES,'UTF-8');
	    $xml .= '</'.$attr.'>' . "\r\n";
	}
	$xml .= '</'.$name.'>';
	return $xml;
    }//toXML


}//abstract class Row
?>
