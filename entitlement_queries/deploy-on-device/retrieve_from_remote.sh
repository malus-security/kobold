#!/bin/bash

if test $# -ne 3; then
    echo "Usage: $0 <SSH_URL> <destination> <source>" 1>&2
    exit 1
fi

ssh_url="$1"
dest="$2"
src="$3"

scp "$ssh_url":"$dest" "$src"
