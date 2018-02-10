#!/bin/bash

echo "Donnez x"
read x

x1=$((bash test_findInTable.sh $x)| tr -d $'\r' | sed -n '1~2p' | cut -d' ' -f1 -s)
x2=$((bash test_findInTable.sh $x)| tr -d $'\r' | sed -n '2~1p' | cut -d' ' -f1 -s)
y1=$((bash test_findInTable.sh $x)| tr -d $'\r' | sed -n '1~2p' | cut -d' ' -f2 -s)
y2=$((bash test_findInTable.sh $x)| tr -d $'\r' | sed -n '2~1p' | cut -d' ' -f2 -s)

echo $(bash test_interpol.sh $x1 $x2 $y1 $y2)



