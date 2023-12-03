#!/bin/bash

nums=(5 4 3 2 10)

echo "The given array is: ${nums[@]}"

l=${#nums[@]}

for((i=0;i<l-1;i++));do
        for((j=0;j<l-i-1;j++));do
                if [ ${nums[j]} -gt ${nums[j+1]} ]; then
                        temp=${nums[j]}
                        nums[j]=${nums[j+1]}
                        nums[j+1]=${temp}
                fi
        done
done
echo "sorted ${nums[@]}"
