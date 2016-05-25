<?php
$input = fopen('input.txt', 'r') or die('Unable to open input file');
$output = fopen('output.txt', 'a') or die('Unable to open output file');
ftruncate($output, 0);
$info = explode(' ',fgets($input));
$max = $info[0];
$linesCount = $info[1];
$id = array();
for($i = 0; $i < $max; $i++){
  $id[] = $i;
}
for($i = 0; $i < $linesCount; $i++){
  $data = explode(' ', fgets($input));
  switch($data[0]){
  case 1:
    for($j = 0; $j < count($id); $j++){
      if($id[$j] == $data[2] - 1)
        $id[$j] = $id[$data[1] - 1];
    }
  break;
  case 2:
    $id[$data[1] - 1] = $id[$data[2] - 1];
  break;
  case 3:
    $count = 0;
    $num = 0;
    for($j = 0; $j < count($id); $j++){
      if($id[$j] == $id[$data[1] - 1]){
        $count++;
        $num += $j + 1;
      }
    }
    fwrite($output, $count . " " . $num . "\r\n");
  }
}
fclose($input);
fclose($output);
?>
