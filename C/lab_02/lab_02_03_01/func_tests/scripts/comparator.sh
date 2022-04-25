#!/bin/bash

ERROR_WRONG_FILES=1
ERROR_FILES_DONT_EXIST=2
ERROR_NOT_EQUAL_LEN=3
ERROR_NOT_EQUAL=4

if [ $# != 2 ]; then
    exit $ERROR_WRONG_FILES
fi
if ! [ -f "$1" ] || ! [ -f "$2" ]; then 
    exit $ERROR_FILES_DONT_EXIST
fi

mapfile -t text1 < <(grep -Eo '[-]{0,1}[0-9]+([.]{0,1}[0-9]+){0,1}' "$1")
mapfile -t text2 < <(grep -Eo '[-]{0,1}[0-9]+([.]{0,1}[0-9]+){0,1}' "$2")
if ! [ ${#text1[@]} -eq ${#text2[@]} ]; then
    exit $ERROR_NOT_EQUAL_LEN
fi
for i in "${!text1[@]}"; do
    if [ "$(echo "${text1[$i]} == ${text2[$i]}" | bc)" -eq 0 ]; then 
        exit $ERROR_NOT_EQUAL
    fi
done
