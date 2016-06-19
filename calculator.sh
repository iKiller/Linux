#!/bin/bash
sum=0.0
i=0
read n
while true
do
    if [[ i -ne n ]]
    then
        read num
        sum=$(echo "$sum+$num" | bc)
        ((i++))
    else
        c=$(echo "scale=10;$sum/$n" | bc -l)
        printf "%.3f" $c
        break
    fi
done
