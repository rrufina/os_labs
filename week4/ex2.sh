#!/bin/bash
gcc ex2.c -o ex2
./ex2 &
for i in 1 2 3 4 5
do
	pstree $!
	sleep 5
done