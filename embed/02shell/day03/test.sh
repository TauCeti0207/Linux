#!/bin/bash

test "hello" = "hello"
echo $? #返回结果0代表正常，非0代表不正常 也就是0代表相等

test -z "hello"
echo $? #输出上一个命令的执行结果 hello长度不为0 返回1

test -d test.sh #测试一个文件是否为目录 如果是则返回0
echo "test -d test.sh $?"
