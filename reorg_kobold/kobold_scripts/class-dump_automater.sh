#!/bin/bash

# run class-dump on the executables listed in the input file.

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
    ../external_tools/class-dump "$filePath" | ./parse-protocol-names.py "$line"
done
