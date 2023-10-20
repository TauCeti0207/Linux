#!/bin/bash

NUM=0
#while [ $NUM -lt 10 ]
while (($NUM < 10))
do
	if [ $NUM -eq 3 ]
	then
		NUM=`expr $NUM + 1`
		continue
	fi
	echo "********$NUM"
	NUM=`expr $NUM + 1`
done
