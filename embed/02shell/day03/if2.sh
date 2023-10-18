#!/bin/bash

read -p "input one num " val
if test $val -eq 0
then
	echo "val=0"
elif test $val -gt 0
then
	echo "val>0"
else
	echo "val<0"
fi
