#!/bin/bash

if test $# -ne 3; then
    echo "Usage: $0 <in_exec_file> <ent_file> <SSH_URL>" 1>&2
    exit 1
fi

in_exec_file="$1"
ent_file="$2"
ssh_url="$3"

if test ! -f "$in_exec_file"; then
    echo "Error: First argument ($in_exec_file) is not a file." 1>&2
    exit 1
fi

if test ! -f "$ent_file"; then
    echo "Error: Second argument ($ent_file) is not a file." 1>&2
    exit 1
fi

./add_entitlement_to_exec.sh "$in_exec_file" "$ent_file" out.exec
./copy_remote.sh out.exec "$ssh_url" .
./run_remote.sh "$ssh_url" ./out.exec run.out
./retrieve_from_remote.sh "$ssh_url" "./run.out" .
