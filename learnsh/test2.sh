#!/bin/bash
#name age
#alice 21
#ryan 30
while read -a line; do
    echo ${#line[@]}
    for ((i = 0; i < "${#line[@]}"; ++i)); do
        echo ${line[$i]}
        b[$i]="${b[$i]} ${line[$i]}"
    done
done < file.txt
for ((i = 0; i < ${#b[@]}; ++i)); do
    echo ${b[i]}
done
