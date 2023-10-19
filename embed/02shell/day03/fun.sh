#!/bin/bash

fun()
{
	local	A=$1 #$1此时代表函数参数
	B=$2
	C=$3
	echo "hello world"
	NUM=`expr $A + $B + $C`
	echo "NUM=$NUM"
	return $NUM
}

fun 1 2 3
echo "\$?=$?" #打印上一个命令的运行结果

echo "A = $A"
echo "B = $B"
echo "C = $C" #函数参数作用域是全局的，当前文件都可以用
# 加上了local就变成局部变量
