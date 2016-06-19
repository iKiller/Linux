# From leetcode.com 
# No193. Valid Phone Numbers
#!/bin/bash
while IFS='' read -r line || [[ -n $line ]]
do
    if [[ "$line" =~ ^[0-9]{3}-[0-9]{3}-[0-9]{4}$|^\([0-9]{3}\)\ [0-9]{3}-[0-9]{4}$ ]]
    then
        echo "$line"
    fi
done < $1
