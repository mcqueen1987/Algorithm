Q: print all possible combinations of characters in a string

input string "abc"
output array ["abc","acb","bac","bca","cab","cba"]

 ---------------------------- code ----------------------------
<?php

/**
* input $str -- original string; $ret -- result array()
* $str = "a b c";
* $ret = ["abc","acb","bac","bca","cab","cba"];
*/
function premutation($arr){
	if(count($arr)<2){
		return $arr;
	}else{
		$ret = array();
		foreach ($arr as $key => $value) {
			$newRet = $arr;
			unset($newRet[$key]);
			$tmpRet = premutation($newRet);
			foreach($tmpRet as $k=>$v){
				$ret[] = $value.$v;
			}
		}
		return $ret;
	}
}

$str = "a b c";
$ret = premutation(explode(' ', $str));
echo json_encode($ret);
?>

