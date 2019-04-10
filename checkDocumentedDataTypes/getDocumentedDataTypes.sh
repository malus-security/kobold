#!/bin/bash


# This script check if objc documentation exists on Apple site:
# https://developer.apple.com/documentation/foundation/nsdata?language=objc

while IFS='' read -r line || [[ -n "$line" ]]; do
    curl -s --head https://developer.apple.com/documentation/foundation/$line?language=objc | head -n 1 | grep "HTTP/1.[01] [23].." > /dev/null
    if [ $? -eq 0 ]; then
        echo $line
    fi
done < "dataTypes.txt"
