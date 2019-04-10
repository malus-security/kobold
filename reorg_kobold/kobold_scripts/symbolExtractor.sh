#!/bin/bash

# run nm on the executables listed in the input file. 
# output paths to executables containing symbols with NSXPC as a substring.

if test $# -ne 1; then
    echo "Usage: $0 /path/to/root/filesystem/ < list/of/executables" 1>&2
    exit 1
fi

rootfs_path="$1/"
rootfs_path=${rootfs_path//\/\//\/}

IFS=$'\n'

echoerr() { echo "$@" 1>&2; }

while read line; do
    filePath="$rootfs_path$line"
    #echo $filePath
    if nm "$filePath" | grep -q 'NSXPC'
    then
      echo $line
    fi
done
