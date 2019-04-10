#!/bin/bash

OIFS="$IFS"
IFS=$'\n'
set -f          # disable globbing

if [ "$1" == "-h" ] || [ "$#" -ne 4 ]; then
  echo "Error: Invalid Arguments"
  echo "This script takes 4 arguments and its purpose is to run an idascript on several disassembled executables."
  echo "Usage: ./$0 mappingOfNamesAndPaths idapythonScript directoryHoldingIDADatabases/ pathToOutputFile"
  exit 0
fi

mappingOfNamesAndPaths=$1
idapythonScript=$2
directoryHoldingIDADatabases=$3 
pathToOutputFile=$4

#deletes the file to be used as output in case it exists already and contains old results
rm $pathToOutputFile

#for line in `cat $mappingOfNamesAndPaths`
for line in $(cat "$mappingOfNamesAndPaths")
do 
  #get name and path of executable to run script on
  name=`echo $line | sed 's/,.*//g'`
  path=`echo $line | sed 's/.*,//g'`

  #run the ida script
  #I should have another mode in case the binary is 32 bit
  #however the only 32 bit binaries i need to handle now are the dyld_shared_cache and the kernel which can be handled individually.
  #I could also reanalyze these using idaq64, but it would take too long, and I don't know if it would break anything...
  #spaces in the path variable were causing trouble since a file path with spaces might look like multiple arguments.
  #I dealt with this by putting escaped double quotes around the variable which seems to help.
  idat64 -A -S"$idapythonScript $path $pathToOutputFile" $directoryHoldingIDADatabases$name.i64
  idat64 -S"$idapythonScript $path $pathToOutputFile" $directoryHoldingIDADatabases$name.i64
done
