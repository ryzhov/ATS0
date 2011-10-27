<?php
class Operator {
    public $op,$name;
    public $ip = array();
    public $plan = array();
    
    public function __construct($op, $name) {
	$this->op = $op;
	$this->name= $name;
    }//__construct

    public function __toString() {
	$str =  "<Operator>\n";
	$str .= "<op>".$this->op."</op>\n";
	$str .= "<name>".$this->name."</name>\n";
	for($i=0;$i<count($this->ip);++$i) {
	    $str .= "<ip>".$this->ip[$i]."</ip>\n";
	}
        for($i=0;$i<count($this->plan);++$i) {
            $str .= $this->plan[$i]->__toString();
        }
	$str .= "</Operator>\n";
	return $str;
    }//__toString
	
}//class Operator

class Plan {
    public $dir,$dirName,$zone,$costIn,$costOut;

    public function __construct($line) {
	$this->dir = $line[0];
#	$this->dirName = str_replace("&","&amp;",substr($line[1],0,53));
	$this->dirName = htmlentities($line[1],ENT_QUOTES,'UTF-8');
	$this->zone = $line[2];
	$this->costIn = $line[3];
	$this->costOut = $line[4];
    }//__construct
    
    public function __toString() {
	$str = "<Plan>\n";
	$str.= "<dir>".$this->dir."</dir>\n";
	$str.= "<dirName>".$this->dirName."</dirName>\n";
	$str.= "<zone>".$this->zone."</zone>\n";
	$str.= "<costIn>".$this->costIn."</costIn>\n";
	$str.= "<costOut>".$this->costOut."</costOut>\n";
	$str.= "</Plan>\n";
	return $str;
    }//__toString()

}//class Plan


header("content-type: text/xml; charset=utf-8");
$dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
$query = "SELECT operator,name FROM operator ORDER BY operator";
$result = pg_query($dbconn,$query);

$oper = array();
$n=0;

if ($result) {
    while ($line = pg_fetch_array($result, null, PGSQL_NUM)) {
	$oper[$n] = new Operator($line[0],$line[1]);
	$n++;
    }
}

//Fill oper objects for ip and plan values from DB
for($i=0;$i<$n;++$i) {
    $query = "SELECT ip FROM operator_ip WHERE operator=".$oper[$i]->op." ORDER BY ip";
    $result = pg_query($dbconn,$query);
    if ($result) {
	$j=0;
	while ($line = pg_fetch_array($result, null, PGSQL_NUM)) {
	    $oper[$i]->ip[$j] = $line[0];
	    ++$j;
	}
    }
    $query = "SELECT dir,dir_name,zone,cost_in[1],cost_out[1] FROM plan ";
    $query.= "INNER JOIN direction USING(dir) WHERE operator=".$oper[$i]->op." ORDER BY dir";
    $result = pg_query($dbconn,$query);
    if ($result) {
	$j=0;
	while ($line = pg_fetch_array($result, null, PGSQL_NUM)) {
	    $oper[$i]->plan[$j] = new Plan($line);
	    ++$j;
	}
    }
}//for
pg_close($dbconn);

// Print all oper objects
echo "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<common>\n";
for($i=0;$i<$n;++$i) {
    echo $oper[$i];
}//for 

echo "</common>\n";

?>
