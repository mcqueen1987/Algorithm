
Q: Print out all the possible combinations of a string

input string "abc" 
output array ["c","b","bc","a","ac","ab","abc"]


--------------------- code -----------------------

<?php

/**
* input $str -- original string; $ret -- result array()
* $str = "abc";
* $ret = ["c","b","bc","a","ac","ab","abc"];
*/
function premutation($str="", &$ret=array()){
	if(strlen($str)<1){
		return false;
	}
	if(strlen($str) == 1){
		$ret[] = $str;
	}else{
		$firstCha = substr($str, 0, 1);
		$tmpArr = premutation(substr($str, 1), $ret);
		$ret[] = $firstCha;
		if(is_array($tmpArr) && !empty($tmpArr)){
			foreach ($tmpArr as $key => $value) {
				$ret[] = $firstCha.$value;
			}
		}
	}
	return $ret;
}

$str = "abc";
premutation($str);
echo json_encode($ret);

?>
