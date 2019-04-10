executable=$1

rm -r ./stack_traces/*
mkdir ./stack_traces

find ./iPhone5s_crash_logs -name "$executable*2018-07*ips" | while read line; do
    suffix=$(basename "$line")
    cat $line | sed -n -e '/Thread.*Crashed/,/^$/ p' | sed -e '1d;$d' | grep -v '\?\?\?' | sed 's/0x.*+//' > stack_traces/$suffix
done

    md5 stack_traces/* | sed 's/.*=//' | sort | uniq | wc -l
    md5 stack_traces/* 
    cat stack_traces/* | sort -V | uniq 

