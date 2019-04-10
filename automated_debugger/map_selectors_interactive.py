targetReg = getRegisterNumber("X1")
errorMessage = ""
export_dict = pickle.load( open( "/home/ladeshot/iOracle/service_analysis_experiments/xpc_analysis/output/exports.p", "rb" ) )
#run this in a for loop and scan every objc_msgSend
#also parse the result such that an actual string is output.

#for these interactive tests, we will start with an empty dictionary.
#otherwise, we would load any existing dictionary for the executable first.

try:
  executableDict = pickle.load(open("/home/ladeshot/iOracle/service_analysis_experiments/xpc_analysis/output/executable_dict_test.p", "rb"))
except (OSError, IOError) as e:
  executableDict = {}

functionName = "_objc_msgSend"
for nName in idautils.Names():
  
  name = nName[1]
  if functionName == name:
    nameAddress = nName[0]
    #now that we have the address of the name we can look for a cross reference.
    for xref in idautils.XrefsTo(nameAddress, 0):
      ea = xref.frm
      minEa = idc.GetFunctionAttr(ea, idc.FUNCATTR_START)
      #We are definitely getting a lot of errors here, but I think we are still finding the selectors we need.

      selectorAddress = getRegisterValueAtAddress(ea,minEa,targetReg)

      selString = findStringAssociatedWithAddress(selectorAddress)
      if selString != "":
	if selString in executableDict:
	  executableDict[selString].append(ea)
	else:
	  executableDict[selString] = [ea]

pickle.dump(executableDict, open("/home/ladeshot/iOracle/service_analysis_experiments/xpc_analysis/output/executable_dict_test.p", "wb"))
