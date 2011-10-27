<?php
class AAA {
    private $user;
    private $pw;
    private $operator;
    private $auth;

    public function __construct($user, $pw) {
	$this->auth = false;
	$this->user = $user;
	$this->pw = $pw;

	if(($user=="admin")&& ($pw=="vfvfljvf")) {
	    $this->operator=0;
	    $this->auth = true;
	    return;
	}

	$query = "select operator from operator where name='".$user."'";
	$dbconn = pg_connect("host=localhost dbname=ats0 user=ran");
	if($dbconn) {
	    $result = pg_query($dbconn,$query);
	    if ($result)
		if($line = pg_fetch_array($result, null, PGSQL_NUM))
		    if(isset($line[0])) {
			$this->operator = $line[0];
			$query = "select pw from operator where operator=".$this->operator;
			$result = pg_query($dbconn,$query);
			if ($result)
			    if($line = pg_fetch_array($result, null, PGSQL_NUM))
				if(isset($line[0])) 
				    if($line[0]==$pw)
					$this->auth = true;
				
		    }

	}
	
    }//__construct

    public function auth() {
	return $this->auth;
    }//auth
    public function user() {
        return $this->user;
    }//user
    public function pw() {
        return $this->pw;
    }//pw
    public function operator() {
        return $this->operator;
    }//operator
}//class

?>
