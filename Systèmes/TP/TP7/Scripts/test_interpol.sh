#!/bin/bash

function interpol() {
	x1=$1
	y1=$2
	x2=$3
	y2=$4
	a1=`echo "$y2 - $y1" | bc -l`
	a2=`echo "$x2 - $x1"  | bc -l`
	m=`echo "$a1 / $a2" | bc -l`
	p=`echo "$y1 - ($m*$x1)" | bc -l`
	a=$m
	b=$p
	echo "L'équation de la drotie est: $a""x+("$b")"
	
return 0
}

a=NaN
b=NaN
if [[ $# != 4 ]]
then
	return 1
else
	interpol $1 $2 $3 $4
fi
echo "$?"
