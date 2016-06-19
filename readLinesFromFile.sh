#!/bin/bash
k=0
while IFS='' read -r line || [[ -n "$line" ]] 
do
    ((k++))
    if [ $k -eq 10 ]
    then
        echo "Text read from file: $line"
    fi
done < "$1"
