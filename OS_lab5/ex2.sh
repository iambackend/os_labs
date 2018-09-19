#!/bin/bash
for i in {1..1000}
do
	a=$(tail -n 1 "ex2.txt")
	echo "$(($a + 1))" >> "ex2.txt"
done
