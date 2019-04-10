#!/bin/bash

if [ "$1" == "-h" ] || [ "$#" -ne 3 ]; then
  echo "Error: Invalid Arguments"
  echo "This script takes 3 arguments and its purpose is to run an ida analysis on several executables saving the results in databases named after hashed file paths."
  echo "Usage: $0 pathToExtractediOSFileSystem filePathsToExecutables directoryForResults"
  exit 0
fi

pathToExtractediOSFileSystem=$1
filePathsToExecutables=$2
directoryForResults=$3
mappingFile="$directoryForResults/hashedPathToFilePathMapping.csv"

#this helps us process the list of inputs by separating each line for the for loop
IFS=$'\n'

filelines=`cat $filePathsToExecutables`

rm $mappingFile

for line in $filelines ; 
do
    #the path to the extracted file system is concatenated with the path that existed on the iOS device
    #for example assume an executable was stored at /myPrograms/coolProgram on the iPhone.
    #The root of the filesystem extracted from iOS is stored at /myFiles/iOSXFileSystem on a PC
    #Then we would want the filePath variable to be /myFiles/iOSXFileSystem/myPrograms/coolProgram to find the executable on the PC
    filePath="$pathToExtractediOSFileSystem$line"

    hashedPath=`echo $line | md5sum | sed 's/\ .*//g'`
    #it's probably safer to separate by comma since the file paths might include spaces
    echo "$hashedPath,$line" >> $mappingFile
    #the third argument is the location to move the executables to and store the ida databases in
    cp $filePath $directoryForResults/$hashedPath
    #this is the line that actually runs IDA
    #the -B option is for batch analysis, so IDA will run its default analysis and close itself when finished.
    #the -o option lets us specify the file path of the database produced by analysis
    #In this case, $directoryForResults/$hashedPath is the path to the executable we want to run analysis on.
    idat64 -B -o$directoryForResults/$hashedPath.i64 $directoryForResults/$hashedPath
done

