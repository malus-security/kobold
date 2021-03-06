#Input 
#Xcode logs output by autogenerated method invocations

#Requirements
#Infer which invocation numbers failed/succeeded
#Infer apparent entitlement requirements based on error message from completion handlers
#Detect which invocation numbers should have had completion handlers
#Map new information to mach-port and method declaration

import pickle
import re

#TODO: this code needs to get a lot smarter as we collect more entitlement samples
def lookForEntReqs(id, thisInvocation, knownEntKeyList):
  errorString = "NSError * var"
  
  for line in thisInvocation["logLines"]:
    if errorString in line:
      if "entitlement" in line:
        #We can use a corpus of known entitlement keys and search for those values in the error message
        for key in knownEntKeyList:
          if key in line:
            thisInvocation["entitlementRequirement"].add(key)
            
        #If the word entitlement is in the error message, but we don't find a key then something went wrong.
        if len(thisInvocation["entitlementRequirement"]) == 0:
          print "ERROR: No known entitlement key found in message that mentions the word 'entitlement'. Likely false negative."
        #If we find more than one key in the error message, then something went wrong.
        if len(thisInvocation["entitlementRequirement"]) > 1:
          print "ERROR: More than one known entitlement key was detected in the same message. Likely false positive."

        #this is some old code that assumed entitlement keys would be surrounded by fancy quotes, but that is not always the case.
        """
          fancyQuoteSlices= line.split('\xe2\x80\x9c')[1:] 
          for slice in fancyQuoteSlices:
            thisInvocation["entitlementRequirement"].add(slice.split('\xe2\x80\x9d')[0])
        """
        

def parseRelevantLogs(id, thisInvocation, logLines):
  #logLines = raw_xcode_logs.split("\n")
  for line in logLines:
    idTag = "id "+id+": "
    if idTag in line:
      #break off the text before the id tag
      #TODO this system will miss array output that uses multiple lines.
      thisInvocation["logLines"].append(line.split(idTag)[-1])

def checkForCompletionStatus(id, thisInvocation):
  completionString = "Completion message"
  if completionString in thisInvocation["logLines"]:
    thisInvocation["valid"] = True
    

raw_xcode_logs = open("input_data/xcode_results.txt","rb").read().strip().split("\n")
sanitized_logs = []
for log in raw_xcode_logs:
  if re.match('^[0-9][0-9][0-9][0-9]\-.*$', log):
    sanitized_logs.append(log)
  else:
    sanitized_logs[-1] += " " + log


#TODO I need to know how many invocations to search for.
# Perhaps it would be easier to deal with this if I could import a pickle file with data from map_potential_methods_to_mach-ports.py
with open('./input_data/invocationDictionary.pk', 'rb') as handle:
    invocationDictionary = pickle.load(handle)
#print invocationDictionary

knownEntKeyList = open('./input_data/ent_key_corpus.txt', 'rb').read().strip().split('\n')

for id in invocationDictionary:
  thisInvocation = invocationDictionary[id]
  id = str(id)
  thisProtocol = thisInvocation["protocol"]
  thisMethod = thisInvocation["method"]
  thisMachPort = thisInvocation["mach-port"]
  thisInvocation["valid"] = False
  thisInvocation["entitlementRequirement"] = set()
  thisInvocation["logLines"] = []
  #The invocation is the correct combination of accessible mach-port and remote method
  #Note that a valid invocation could still be inaccessible due to decentralized checks

  #run various tests to see if the connection should be considered valid or not
  
  
  parseRelevantLogs(id, thisInvocation, sanitized_logs)

  #block based tests
  hasBlockString = "Invocation has a completion handler"
  if hasBlockString in thisInvocation["logLines"]:
    checkForCompletionStatus(id, thisInvocation)
    lookForEntReqs(id, thisInvocation, knownEntKeyList)

  
  #if thisInvocation["valid"] and len(thisInvocation["entitlementRequirement"]) == 0:
  if thisInvocation["valid"]:
    print id
    #print "  "+thisProtocol
    print "  "+thisMethod
    print "  "+thisMachPort
    #print "  "+str(thisInvocation["valid"])
    print "  "+str(thisInvocation["entitlementRequirement"])
    for line in thisInvocation["logLines"]:
      print "****"+line
      #for line in thisInvocation["logLines"]:
      #  print "  "+line
