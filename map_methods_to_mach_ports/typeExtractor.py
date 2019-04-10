import re

def handleBlockArgument(blockParameter):
  argsToReturn = []
  pattern = re.compile("(.*)\ \(\^\)\((.*)\)")
  match = pattern.match(blockParameter)
  argsToReturn.append(match.group(1))
  #print argsToReturn
  if ", " in match.group(2):
    argsToReturn += match.group(2).split(", ")
  else:
    argsToReturn.append(match.group(2))
  return argsToReturn

def getReturnType(declaration):
	pattern = re.compile(".*?\(([^)]*)")
	match = pattern.match(declaration)
	return_type = match.group(1)
	return return_type

def getParameterTypes(method):
  argsToReturn = []
  raw_arguments = method.split(':')[1:]
  for argument in raw_arguments:
    pattern = re.compile("\((.*)\)")
    match = pattern.match(argument)
    arg_type = match.group(1)

    if "(^)" in arg_type:
      argsToReturn += handleBlockArgument(arg_type)
    else:
      argsToReturn.append(arg_type)
  return argsToReturn

def addToDictionary(typeDictionary, returnType):
	if returnType in typeDictionary:
		typeDictionary[returnType] = typeDictionary[returnType] + 1
	else:
		typeDictionary[returnType] = 1
		
#read in methods
raw_prot_lines = open("xpc_11.1.2.h").read().strip().split("\n")

#parse one method per line and ignore anything else
methods = []
for line in raw_prot_lines:
  if ((line.startswith("-") or line.startswith("+")) and line.endswith(";")):
    methods.append(line)

typeDictionary = {}
for method in methods:
  parameterTypes = []
  parameterTypes.append(getReturnType(method))
  #I should probably only add types from methods without problematic arguments
  parameterTypes += getParameterTypes(method)
  for pType in parameterTypes:
    addToDictionary(typeDictionary, pType)
  #print parameterTypes
  #print method

#I should learn how this works later. It came from here:
#	https://www.saltycrane.com/blog/2007/09/how-to-sort-python-dictionary-by-keys/
sortedDict = sorted(typeDictionary.iteritems(), key=lambda (k,v): (v,k))
sortedDict.reverse() 
#print sortedDict
for entry in sortedDict:
  print entry

#use regular expressions to extract types including completion handlers
#count number of times each type appears
#be able to filter out methods with problematic types and repeat counts
#make initializers for each type, prioritizing those that appear most often.
