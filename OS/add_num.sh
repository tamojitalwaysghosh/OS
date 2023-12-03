#!/bin/bash

# Prompt the user to enter the first number
read -p "Enter the first number: " num1

# Prompt the user to enter the second number
read -p "Enter the second number: " num2

# Perform the addition
sum=$((num1 + num2))

# Display the result
echo "The sum of $num1 and $num2 is: $sum"
