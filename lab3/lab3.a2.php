<?php
$input = fopen("input.txt", "r");
$output = fopen("output.txt", "a");
	
	function cmp($a, $b){
		if ($a[0] == $b[0])
			return 0;
		return ($a[0] < $b[0]) ? -1 : 1;
	}
	
while (($name = fgets($input)) !== false) {
	
	fwrite($output, $name);
	// get data
	$linesCount = fgets($input);
	$intervals = array();
	for ($i = 0; $i < $linesCount; $i++)
		$intervals[] = explode(" ", fgets($input));
	usort($intervals, "cmp");
	$length = 0;
	if($linesCount > 0){
		$length = $intervals[0][1] - $intervals[0][0];
		for ($i = 1; $i < $linesCount; $i++){
			if($intervals[$i][0] != $intervals[$i][1]){
				if($intervals[$i][0] == $intervals[$i-1][0] && $intervals[$i][1] > $intervals[$i - 1][1]){
					$length += ($intervals[$i][1] - $intervals[$i - 1][1]) - $intervals[$i][0];
				} else if($intervals[$i][0] > $intervals[$i-1][0] && $intervals[$i][0] < $intervals[$i - 1][1] && $intervals[$i][1] > $intervals[$i - 1][1]){
					$length += ($intervals[$i][1] - $intervals[$i][0]) - ($intervals[$i - 1][1] - $intervals[$i][0]);
				} else if($intervals[$i][0] > $intervals[$i - 1][1] && $intervals[$i][1] > $intervals[$i - 1][1]){
					$length += $intervals[$i][1] - $intervals[$i][0];
				}
			}
		}
	}
	fwrite($output, $length . "\r\n\r\n");
	fgets($input);

}


fclose($input);
fclose($output);
?>
