#!/bin/bash

read -p "input two number " val1 val2

num=`expr $val1 + $val2`
echo $num

num=`expr $val1 - $val2`
echo $num

num=`expr $val1 \* $val2` #*需要转义
echo $num

num=`expr $val1 / $val2` 
echo $num

num=`expr $val1 % $val2`
echo $num
