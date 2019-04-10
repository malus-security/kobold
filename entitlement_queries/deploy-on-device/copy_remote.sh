#!/bin/bash

if test $# -ne 3; then
    echo "Usage: $0 <source> <SSH_URL> <destination>" 1>&2
    exit 1
fi

src="$1"
ssh_url="$2"
dest="$3"

if test ! -f "$src"; then
    echo "Error: First argument ($src) is not a file." 1>&2
    exit 1
fi

scp "$src" "$ssh_url":"$dest"
