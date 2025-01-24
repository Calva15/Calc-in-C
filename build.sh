#!/bin/bash

# Navigate to the project directory
cd "$(dirname "$0")"

# Compile the program
gcc -g main.c -o calculator -lm

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful. You can run the program using ./calculator"
else
    echo "Build failed. Please check for errors."
fi