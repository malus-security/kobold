#!/bin/bash

if test $# -ne 1; then
	echo "Usage: $0 /path/to/root/filesystem/" 1>&2
	exit 1
fi

rootfs_path="$1/"
rootfs_path=${rootfs_path//\/\//\/}

#the find command also has a printf option and provides much of the same data as stat
IFS=$'\n'

count=0
echoerr() { echo "$@" 1>&2; }
echoerr $count

for file in $(find "$rootfs_path" -type f);
do
	{
	  adjustedFilePath=${file##"$rootfs_path"}
	  #it should be ok to remove troublesome characters from file type output
	  
	  #parallelization experiment adding &
	  #fileType=`file -b -p $file | sed 's/"//g' | sed 's/\`//g' | sed "s/'//g" | sed 's/\\\//g'`
	  fileType=`file -b -p $file | sed 's/"//g' | sed 's/\`//g' | sed "s/'//g" | sed 's/\\\//g'` 
	  #echo $prefix,fileType\(\"$fileType\"\)\).
	  prefix=`echo file\(fileType\(\"$fileType\"\)`
	  #the following should add in the leading slash we want in the filepath
	  adjustedFilePath="/$adjustedFilePath"
	  echo $prefix,filePath\(\"$adjustedFilePath\"\)\).
	  count=$((count + 1))
	  if ! (($count % 1000)); then
		  echoerr $count
	  fi
	}
done
#parallelization experiment
wait
