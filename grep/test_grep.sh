#!/bin/bash

# Define the flags to test
flags=(-e -i -c -l -n -h -v -o -f)

arguments=(hello seven abc p.txt)

# Define the test files
files=(test1.txt test2.txt)

# Test each flag with each file
for flag in "${flags[@]}"; do
    for file in "${files[@]}"; do
        for argument in "${arguments[@]}"; do  # Add a do statement here
            echo "$flag $argument $file..."

            # Run s21_grep and grep with the same flag and file, and save the output
            s21_output=$(./s21_grep "$flag" "$argument" "$file")
            grep_output=$(grep "$flag" "$argument" "$file")

            # Compare the output
            if [ "$s21_output" == "$grep_output" ]; then
                echo "Test passed Test passed Test passed Test passed Test passed Test passed Test passed."
            else
                echo "Test FAIL FAIL FAIL FAIL FAIL FAIL FAIL FAIL FAILFAIL FAIL FAIL FAIL FAIL FAIL."
            fi
        done  # Close the for loop with a done statement
    done
done
