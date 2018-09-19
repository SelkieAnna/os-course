#!/bin/bash

while :
do
	if ln ex2.txt ex2.lock; then
		NUM=$(tail -n 1 ex2.txt | tr -dc '0-9')
		NEXT_NUM=$((NUM + 1))
		sed -i '$ a\'$NEXT_NUM'' ex2.txt
		#tail -n 1 ex2.txt
		rm ex2.lock
	fi
done
