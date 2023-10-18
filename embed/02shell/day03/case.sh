#! /bin/bash 


read -p "input a score " val
if [ $val -lt 0 ] || [ $val -gt 100 ]
then
	echo "input error"
	exit 0
fi

val=`expr $val / 10`

case $val in
	8|9|10)
		echo "A"
		;;
	6|7)
		echo "B"
		;;
	*)
		echo "C"
		;;
esac
