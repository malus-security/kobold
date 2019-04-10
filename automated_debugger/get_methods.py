import pickle

with open('./mystery_protocols_iPhone_4.0_64bit_11.1.2_15B202_2018-07-09.pk', 'rb') as handle:
  class_dump_results = pickle.load(handle)

#at this point, only executable using sandbox accessible mach-ports should be in the dictionary
for executable in executableDictionary:
  if class_dump_results[executable] != {}:
    executableDictionary[executable]["protocols"] = {}
    protsDict = executableDictionary[executable]["protocols"]
    for protocol in class_dump_results[executable]:
      protsDict[protocol] = []
      raw_header = class_dump_results[executable][protocol]
      for line in raw_header.split('\n'):
	if ((line.startswith("-") or line.startswith("+")) and line.endswith(";")):
	  protsDict[protocol].append(line)
