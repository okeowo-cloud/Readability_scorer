#!/usr/bin/env bash

if [ "$#" -eq 1 ]; then
	./Build/readability_scorer $1
else
	./Build/readability_scorer example.txt
fi
