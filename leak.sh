#! /bin/bash

name=$1

if [ -z $name ]; then
	echo "Name of program to check leaks"
	exit
fi

while true
do
	leaks $name
done
