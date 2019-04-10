#!/bin/bash

if test $# -ne 1; then
  echo "Usage: $0 /path/to/directory/of/.ipa/files/" 1>&2
  exit 1
fi

#the find command also has a printf option and provides much of the same data as stat
IFS=$'\n'

echoerr() { echo "$@" 1>&2; }

for filePath in $1/*.ipa; 
do
  #I need to get the basepath to help with naming conventions.
  base=`basename $filePath`
  #rm -rf ./temporaryUnpackingArea
  rm -rf ./stagingArea/$base
  #mkdir ./temporaryUnpackingArea
  mkdir ./stagingArea/$base
  unzip -q $filePath -d ./stagingArea/$base
  #some apps have meaningless files with the .app extension that seem to all contain %'s in the filepath.
  #perhaps this has something to do with the ascii representation of the unicode name.
  rm -rf ./stagingArea/$base/Payload/*%*.app
  entitlements=`codesign -d --entitlements :- ./stagingArea/$base/Payload/*.app 2>&1`
  entitlements=`echo $entitlements | sed 's;^.*<dict>;;' | sed 's;</dict>.*$;;' | sed 's;<key>;\\\n<key>;g'`
  #-z checks to see if the string is empty.

  if [ ! -z "$entitlements" ]; then
    entlines=`printf $entitlements`
    for ent in $entlines;
    do
      keyCheck=`echo $ent | grep '<key>'`
      if [ ! -z "$keyCheck" ]; then
	entKey=`echo $ent | sed 's/^.*<key>\ *//' | sed 's;\ *</key>.*;;'`
	entValRaw=`echo $ent | sed 's;.*</key>;;' | sed 's;[\ 	]*;;g'`
	entValWithStrings=`echo $entValRaw | sed 's;<string>;string(";g' | sed 's;</string>;");g' |  sed 's;")string;"),string;g'`
	entValWithInts=`echo $entValWithStrings | sed 's;<integer>;intValue(";g' | sed 's;</integer>;");g' |  sed 's;")intValue;"),intValue;g'`
	entValWithBrackets=`echo $entValWithInts | sed 's;<array>;[;g' | sed 's;</array>;];g'`
	entValProcessBools=`echo $entValWithBrackets | sed 's;<true/>;bool("true");g' | sed 's;<false/>;bool("false");g'` 
	entVal=`echo $entValProcessBools`
	echo "appStoreEntitlement(itemId(\"internalNotApplicable\"),artistName(\"internal\"),bundleId(\"internal.not.applicable\"),collection(\"fall2017\"),entitlement(key(\"$entKey\"),value($entVal)))."
      fi
    done
  fi

  rm -rf ./stagingArea/$base

done
