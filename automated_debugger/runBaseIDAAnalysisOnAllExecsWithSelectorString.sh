#!/bin/bash

#TODO use idaBatchAnalysis to process the following list of executables and store them somewhere reasonable like the bigdata partition.
grep 'initWithMachService' /media/bigdata/from-ncsu-to-upb/firmware_processing_results_with_dev_after_post_process/10.1/all_facts.pl | sed 's/.*filePath("//' | sed 's/").*//' | sort | uniq > temp/executablesWithMachServiceSelector.out

./idaBatchAnalysis.sh /media/bigdata/from-ncsu-to-upb/firmware_processing_results_with_dev_after_post_process/10.1/fileSystem ./temp/executablesWithMachServiceSelector.out /media/bigdata/from-ncsu-to-upb/firmware_processing_results_with_dev_after_post_process/10.1/serviceProvider_analysis_string_based


