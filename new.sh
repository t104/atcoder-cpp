#!/bin/bash

FOLDER=$1

files=(
    "a"
    "b"
    "c"
    "d"
    "e"
    "f"
)

mkdir ./$FOLDER
for file in "${files[@]}"
do
    touch ./$FOLDER/$file.cpp
done
