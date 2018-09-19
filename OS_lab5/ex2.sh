#!/bin/bash
for i in {1..3000}
do
	while true; 
	do 
		if `ln ex2.txt ex2.txt.lock`; then
			a=$(tail -n 1 "ex2.txt")
			echo "$(($a + 1))" >> "ex2.txt"
			rm ex2.txt.lock
			break
		fi
	done
done
