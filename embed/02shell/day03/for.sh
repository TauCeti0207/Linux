#!/bin/bash

#for val in 1 2 3 4 5
for ((val = 1; val <= 5; val = $val + 1))
do
	echo "val = $val"
done

for file in `ls`
do
	echo "-----------$file"
done
