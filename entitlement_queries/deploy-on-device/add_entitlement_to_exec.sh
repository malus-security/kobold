#!/bin/bash

# Sample run
# ./add_entitlement_to_exec.sh  ~/Projects/ios-security-research/ios-command-line-tool.git/ios-command-line-tool-raw spi.xml my

if test $# -ne 3; then
    echo "Usage: $0 <in_exec_file> <ent_file> <out_exec_file>" 1>&2
    exit 1
fi

in_exec_file="$1"
ent_file="$2"
out_exec_file="$3"

if test ! -f "$in_exec_file"; then
    echo "Error: First argument ($in_exec_file) is not a file." 1>&2
    exit 1
fi

if test ! -f "$ent_file"; then
    echo "Error: Second argument ($ent_file) is not a file." 1>&2
    exit 1
fi

JTOOL="/Users/razvan/bin/jtool"

#$JTOOL -arch arm64 -e arch "$in_exec_file"
#JDEBUG=1 $JTOOL -arch arm64 --sign --ent "$ent_file" --inplace "$in_exec_file".arch_arm64
cp "$in_exec_file" "$out_exec_file"
# XXX: Replace the parameter to the -fs option with the output from the `security find-identity` command.
codesign -fs 1DE40E91CD6E0B8F17834E3BDECCC7279C715324 --entitlements "$ent_file" "$out_exec_file"
