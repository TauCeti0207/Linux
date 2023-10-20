#!/bin/bash

echo "input one num"
read val
echo $val

#echo "input year month day"#太麻烦了

read -p "input year month day " year month day #-p参数就可以
echo $year-$month-$day
