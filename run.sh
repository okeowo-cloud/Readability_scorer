#!/usr/bin/env bash

if [ "$#" -eq 1 ]; then
	./Build/Readability_scorer $1
else
	./Build/Readability_scorer example.txt
fi
