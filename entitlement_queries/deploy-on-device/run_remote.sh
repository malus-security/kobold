#!/bin/bash

if test $# -ne 3; then
    echo "Usage: $0 <SSH_URL> <path> <out>" 1>&2
    exit 1
fi

ssh_url="$1"
path="$2"
out="$3"

ssh "$ssh_url" "$path > $out 2>&1"
