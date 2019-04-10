#we'll want a good regular expression to remove the variable types.
#it seems that name of the function does not include the variable types or names.
#for example:
# - (void)startMonitoringScenarioTriggerOfType:(unsigned long long)arg1 forClient:(byref id <CLRoutineMonitorClientProtocol>)arg2;
# startMonitoringScenarioTriggerOfType:forClient:
#perhaps duplicates will be possible, but we can add a sanity check to see if that happens and deal with it later.

import idaapi
import idc
import idautils
import os
import pickle
import re

#TODO I should extract the relevant methods from our dictionary and parse out the name likely to appear in the IDA disassembly.
#functionName = "startMonitoringScenarioTriggerOfType:forClient:"
#functionName =  "- (void)startMonitoringScenarioTriggerOfType:(unsigned long long)arg1 forClient:(byref id <CLRoutineMonitorClientProtocol>)arg2;"

#Given a full method declaration, parse out a string that will match IDA's function naming convention

#This function appears more than once.
#I guess the same selector is used by multiple objects.
#We can state this limitation in the paper. It shouldn't be a big deal.
functionName =  "- (void)startUpdatingLocation;"
#drop the semicolon
functionName = functionName[:-1]
funNameComponentList = []
if ":" in functionName:
  funNameComponentList = functionName.split(":")[:-1]
  funNameComponentList = [comp + ":" for comp in funNameComponentList]

else:
  funNameComponentList = [functionName]
  
idaFunName = ""
for component in funNameComponentList:
  regexResult = re.match('.*[)\ ](.*)$',component)
  idaFunName += regexResult.group(1)

print idaFunName

for nName in idautils.Names():
  name = nName[1]
  if idaFunName in name:
    nameAddress = nName[0]
    if idc.get_segm_name(nameAddress) == "__text":
      print "address of function is: ",
      print str(hex(nameAddress))[:-1]

#pickle.dump(executableDict, open("/home/ladeshot/iOracle/kobold/automated_debugger/daemon_protocol_addresses", "wb"))
