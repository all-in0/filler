#!/bin/bash

delay=0.1

while read -r line; do
	echo "$line" | grep 'Plateau' > /dev/null
	if [[ $? == 0 ]]; then
		sleep $delay
		clear
	fi
	echo "$line"
done < /dev/stdin
