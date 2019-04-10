#!/bin/bash

if [[ $# -eq 0 ]] ; then
    echo "Usage: ./run_multiple_times.sh 10 ../../../../iOracle_demos/ios-command-line-tool/build/Release-iphoneos/ios-command-line-tool ../xml_entitlements/_output_for_all_ents.xml 172.19.10.122"
    exit 0
fi

loops=$1
binary=$2
ent_file=$3
ip_addr=$4
timestamp=`date +%d-%m-%Y_%H:%M`

mkdir results/$timestamp
for i in `seq 1 $1`;
do
    ./all.sh $binary $ent_file root@$ip_addr
    output_name=run_${i}.out
    mv run.out results/$timestamp/$output_name
    ./get_stats.sh results/$timestamp/$output_name > results/${timestamp}/run_${i}_stats.out
done

