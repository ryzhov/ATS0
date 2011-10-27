<?php
#######################################################################
#
# getDir.php - print out Directions  as HTML SELECT TAG
#
# Parameters:
#######################################################################

require_once $_SERVER['ATS0'] . '/classes/DB.php';
require_once $_SERVER['ATS0'] . '/classes/GMatrix.php';

# -- make a query for select appropriate data ----------------------
$query = 'SELECT dir, dir||\': \'||dir_name as dir_name FROM direction ORDER BY dir';

# -- make Directions array --
$dirs = new GMatrix('DirList', 'DirListItem', DB::select($query));

#-- print out html doc --
header('content-type: text/html; charset=utf-8');
$xml = $dirs->toSelect('dir','dir_name');
echo $xml;
?>
