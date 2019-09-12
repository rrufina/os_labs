#!/bin/bash
# you should run the script with ./ex1.sh
for ((i = 0; i < 10; i++));
do
gcc ex1.c -o ex1;
./ex1;
done
