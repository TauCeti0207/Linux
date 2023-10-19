#!/bin/bash

NUM=0
#while [ $NUM -lt 10 ]
while (($NUM < 10))
do
	echo "********"
	NUM=`expr $NUM + 1`
done
