#!/bin/bash

k=$1
a=$#

x1=NaN
y1=NaN
x2=NaN
y2=NaN

function inferieur() {
    exec < cosTable.txt
    IFS="!"

    read z0 cosz0
    read z1 cosz1
    tmp1=$z1
    while [[ $k > $z1 ]]
    do
	tmp1=$z1
	tmp2=$cosz1
	read z1 cosz1
    done
    echo $tmp1
    echo $tmp2
}

function superieur() {
    exec < cosTable.txt
    IFS="!"
    
    read z0 cosz0
    read z2 cosz2
    while [[ $k > $z2 ]]
    do
	read z2 cosz2
    done
    echo $z2
    echo $cosz2
}
	
function findInTable() {
    if [ -e cosTable.txt ] && [ $a == 1 ]
    then
	echo $(superieur)
	echo $(inferieur)
	return 0
    else
	return 1
    fi
}

findInTable

echo "$?"

