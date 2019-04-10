#!/bin/bash

if test $# -ne 1; then
    echo "Usage: $0 <path-to-file>" 1>&2
    exit 1
fi

f="$1"

if test ! -f "$f"; then
    echo "Error: First argument must be a file." 1>&2
    exit 1
fi

about_to_run_no=$(grep 'about to run id' "$f" | wc -l)
invocation_no=$(grep 'Invocation has a completion handler' $f | wc -l)
terminated_no=$(grep 'Connection Terminated' "$f" | wc -l)
completion_no=$(grep 'Completion message' "$f" | wc -l)
invalidated_no=$(grep 'Connection Invalidated' "$f" | wc -l)

cat <<END
about_to_run_no ("about to run id"): $about_to_run_no
invocation_no ("Invocation has a completion handler"): $invocation_no
terminated_no ("Connection Terminated"): $terminated_no
completion_no ("Completion message"): $completion_no
invalidated_no ("Connection Invalidated"): $invalidated_no
END
