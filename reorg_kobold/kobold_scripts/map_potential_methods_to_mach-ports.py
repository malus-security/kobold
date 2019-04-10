#three input files, 1) mach-port to exec mapping, 2) protocol to exec mapping, 3) list of accessible mach-ports
#one output file, mapping of protocols that might be related to accessible mach-ports
#bonus output, mapping of specific methods to try for each accessible mach-port

import pickle
import re
import random
import sys

def generateMethodCall(method, variables, id):
  #[myConnection.remoteObjectProxy enumerateInstalledAppsWithOptions:dictTest completion:completionHandler];
  invocation = ""

  #set up return value for the call if it isn't void
  if "void" not in variables[0]["type"]:
    invocation += variables[0]["name"] +' = '

  invocation += '[myConnection_' +id+ '.remoteObjectProxy '

  #if there are colons, then there are parameters, and we need to use the right variable names
  if ':' in method:
    #strip away the irrelevant parts of the method declaration
    pattern = re.compile(".*?\)(.*);")
    match = pattern.match(method)
    methodStripped = match.group(1)

    methodSlices = methodStripped.split(":")
    #the first slice won't have any variables, so it's ok to just use it as is
    invocation += methodSlices[0] +':'

    #if there is only one argument, then this loop will simply be skipped
    argument_count = 1
    for slice in methodSlices[1:]:
      pattern = re.compile("(.*?arg[0-9]*)")
      match = pattern.match(slice)
      spotForVarName = match.group(1)
      variableNameForSlice = variables[argument_count]["name"]
      modifiedSlice = slice.replace(spotForVarName, variableNameForSlice, 1)
      argument_count += 1
      invocation += modifiedSlice
      if argument_count < len(variables):
        invocation += ":"

    #finish after the last slice
    invocation += '];\n'



  #if there are no colons, then there are not parameters, and no names need to be used
  else:
    pattern = re.compile(".*?\)(.*);")
    match = pattern.match(method)
    methodToInvoke = match.group(1)
    invocation += methodToInvoke + "];"

  return invocation



#return the strings to declare a block and the new var_id number
def handleBlockDeclaration(var_type, id, var_id):
  #example of a block declaration
  """
  //type definition. I really don't understand this syntax...
  typedef void (^objectOperationBlock)(NSError *error);

  //declare the block
  objectOperationBlock completionHandler = ^(NSError *error){
    //Generic message signalling completion of the method
    NSLog(@"Dosomething");
    //For each variable in the handler, try to log them.
    //We might run into trouble if any of these aren't NSObjects...
    NSLog(@"error: %@",error);};
  """
  block_arg_list = []
  for v_type in var_type:
    this_block_arg = {}
    this_block_arg["type"] = v_type
    #It shouldn't hurt anything if we create a name for a void type here.
    this_block_arg["name"] = "var_"+id+"_"+str(var_id)
    var_id += 1
    block_arg_list.append(this_block_arg)

  block_declaration = ""
  block_declaration += 'NSLog(@"id '+id+': Invocation has a completion handler");\n'

  #The first variable type in the var_type list should be the return type.
  #It will probably be void, but might not always be void...
  return_type = block_arg_list[0]["type"]
  #set up return type and type name
  #I need a handle on the block type name, so I can use it again.
  block_type = "objectOperationBlock_"+id+"_"+str(var_id)
  var_id += 1
  block_declaration += "typedef "+return_type+" (^"+block_type+")"
  #fill in the argument types and finish the statement with semicolon
  block_args = ""
  #TODO I shouldn't assign names if ther argument types are void.

  if block_arg_list[1]["type"] == "void":
    block_args += "("+block_arg_list[1]["type"]
  else:
    block_args += "("+block_arg_list[1]["type"]+" "+block_arg_list[1]["name"]
  for this_block_arg in block_arg_list[2:]:
    block_args += ", "+this_block_arg["type"]+" "+this_block_arg["name"]
  block_declaration += block_args
  block_declaration += ");\n"

  #declare the block
  #set up a name for the handler variable
  block_variable_name = "blockHandler_"+id+"_"+str(var_id)
  var_id += 1

  #create the block's heading
  block_declaration += block_type +" "+ block_variable_name + " = ^"
  block_declaration += block_args + "){\n"
  #generic completion message
  block_declaration += 'NSLog(@"id '+id+': Completion message");\n'

  try_catch_preamble = "@try {\n"
  try_catch_epilogue = """
   }
    @catch (NSException * e) {
        NSLog(@"id %s: Completion Handler Exception: %%@", e);
   }
  """ % id
  block_declaration += try_catch_preamble

  #I need to print each of the block variables (except for return type which I hope is void...)
  #TODO we should probably wrap each of these in error catching code so that execution doesn't get
  #TODO interrupted when one of our fake objects explodes...
  for this_block_arg in block_arg_list[1:]:
    #TODO we eventually want to print non-error results, but we are running into too many problems in early stages.
    #if this_block_arg["type"] != "void" and "Error" in this_block_arg["type"]:
    if this_block_arg["type"] == "_Bool":
      block_declaration += 'NSLog(@"id '+id+': COMPLETION HANDLER OUTPUT ' +this_block_arg["type"] + ' ' +this_block_arg["name"]+ ': %d",' +this_block_arg["name"]+ ');\n'
    elif this_block_arg["type"] == "int":
      block_declaration += 'NSLog(@"id '+id+': COMPLETION HANDLER OUTPUT ' +this_block_arg["type"] + ' ' +this_block_arg["name"]+ ': %d",' +this_block_arg["name"]+ ');\n'
    elif this_block_arg["type"] == "unsigned int":
      block_declaration += 'NSLog(@"id '+id+': COMPLETION HANDLER OUTPUT ' +this_block_arg["type"] + ' ' +this_block_arg["name"]+ ': %d",' +this_block_arg["name"]+ ');\n'
    elif this_block_arg["type"] == "double":
      block_declaration += 'NSLog(@"id '+id+': COMPLETION HANDLER OUTPUT ' +this_block_arg["type"] + ' ' +this_block_arg["name"]+ ': %f",' +this_block_arg["name"]+ ');\n'
    elif this_block_arg["type"] == "long long":
      block_declaration += 'NSLog(@"id '+id+': COMPLETION HANDLER OUTPUT ' +this_block_arg["type"] + ' ' +this_block_arg["name"]+ ': %lld",' +this_block_arg["name"]+ ');\n'
    elif this_block_arg["type"] == "unsigned long long":
      block_declaration += 'NSLog(@"id '+id+': COMPLETION HANDLER OUTPUT ' +this_block_arg["type"] + ' ' +this_block_arg["name"]+ ': %llu",' +this_block_arg["name"]+ ');\n'
    elif this_block_arg["type"] != "void":
      block_declaration += 'NSLog(@"id '+id+': COMPLETION HANDLER OUTPUT ' +this_block_arg["type"] + ' ' +this_block_arg["name"]+ ': %@",' +this_block_arg["name"]+ ');\n'
  block_declaration += try_catch_epilogue
  block_declaration += '};\n'


  #TODO I think I should also return the variable name for the block_handler, so that it can be used in the method invocation.
  return block_declaration,var_id,block_variable_name


def handleBlockArgument(blockParameter):
  argsToReturn = []
  pattern = re.compile("(.*)\ \(\^\)\((.*)\)")
  match = pattern.match(blockParameter)
  argsToReturn.append(match.group(1))
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
      argsToReturn.append(handleBlockArgument(arg_type))
    else:
      argsToReturn.append(arg_type)
  return argsToReturn

def autoCodeThisMethod(method, machPort, id):
  objcCode = ""
  id = str(id)
  #loadProtocol
  fake_protocol_name = "fakeProts"
  objcCode += "NSXPCInterface *myInterface_"+id+" = [NSXPCInterface interfaceWithProtocol: @protocol("+fake_protocol_name+")];\n"
  #initialize connection
  objcCode += 'NSXPCConnection *myConnection_'+id+' = [[NSXPCConnection alloc] initWithMachServiceName:@"'+machPort+'"options:0];\n'
  objcCode += 'myConnection_'+id+'.remoteObjectInterface = myInterface_'+id+';\n'
  objcCode += '[myConnection_'+id+' resume];\n'
  #handle error messages
  objcCode += 'myConnection_'+id+'.interruptionHandler = ^{NSLog(@"id '+id+': Connection Terminated");};\n'
  objcCode += 'myConnection_'+id+'.invalidationHandler = ^{NSLog(@"id '+id+': Connection Invalidated");};\n'


  #extract return and argument types
  varTypes = []
  varTypes.append(getReturnType(method))
  varTypes += getParameterTypes(method)
  var_id = 0
  var_declarations = ""
  variables = []
  for var in varTypes:
    thisVariable = {}
    thisVariable["type"]=var
    #for none block types, it should be sufficient to just declare a variable.
    if "list" in str(type(var)):
      #set up declaration for block

      block_declaration,var_id,thisVariable["name"] = handleBlockDeclaration(var, id, var_id)
      var_declarations += block_declaration
      #set up dictionary for this block with type and variable name
    elif "void" not in var:
      #declare simple variable
      var_declarations += var+' var_'+id+'_'+str(var_id)+';\n'
      thisVariable["name"] = 'var_'+id+'_'+str(var_id)
      var_id += 1
    variables.append(thisVariable)
  objcCode += var_declarations

  #set up try catch wrapper
  try_catch_preamble = "@try {\n"
  try_catch_epilogue = """
   }
    @catch (NSException * e) {
        NSLog(@"id %s: Invocation Exception: %%@", e);
   }
  """ % id

  objcCode += try_catch_preamble
  objcCode += generateMethodCall(method, variables, id)
  objcCode += try_catch_epilogue

  #declare method parameters by iterating through argument type list.
  #I don't think we actually need to initialize these parameters, I think they just need to be declared.
    #check for block parameters
    #set up blocks if necessary
  #invoke the method using initialized parameters
  return objcCode



def prettyPrint(executableDict):
  for executable in executableDict:
    print executable
    for machport in executableDict[executable]["mach-ports"]:
      print "  mach-port: " + machport
    if "protocols" in executableDict[executable]:
      protsDict = executableDict[executable]["protocols"]
      if len(protsDict) == 1:
        print "GOOD FOR TESTING"
      for protocol in protsDict:
        print "  protocol: " + protocol
        for method in protsDict[protocol]:
          print "    method: " + method

executableDictionary = {}

#map sandbox accessible mach-ports to executables
machPort_to_Exec_Mappings = open("data/port_to_exec_mapping.csv", "rb").read().strip().split("\n")
sandboxAccessibleMachPorts = open("./data/sandbox_accessible_services.txt", "rb").read().strip().split("\n")
#print machPort_to_Exec_Mappings
for mapping in machPort_to_Exec_Mappings:
  machPort, executable = mapping.split(",")
  if machPort in sandboxAccessibleMachPorts:
    #initialize an entry for the executable if there isn't one already
    if executable not in executableDictionary:
      executableDictionary[executable] = {}
      executableDictionary[executable]["mach-ports"] = []
    #TODO it should be possible for an executable to map to more than one accessible mach-port
    executableDictionary[executable]["mach-ports"].append(machPort)

#map protocols to executables
with open('./data/protocols.pk', 'rb') as handle:
    class_dump_results = pickle.load(handle)

#at this point, only executable using sandbox accessible mach-ports should be in the dictionary
for executable in executableDictionary:
  if executable in class_dump_results and class_dump_results[executable] != {}:
    executableDictionary[executable]["protocols"] = {}
    protsDict = executableDictionary[executable]["protocols"]
    for protocol in class_dump_results[executable]:
      protsDict[protocol] = []
      raw_header = class_dump_results[executable][protocol]
      for line in raw_header.split('\n'):
        if ((line.startswith("-") or line.startswith("+")) and line.endswith(";")):
          protsDict[protocol].append(line)

#for each executable in executableDict, search through the pickle dictionary for protocols.
#if any protocols are found, then add them to executable's dictionary.
# executable {mach-port: ..., protocols: {protocol: [methodDeclarationStrings]}}

#prettyPrint(executableDictionary)

#create preamble for ViewController.m file that creates generic app code before the invocations
preamble = """
//Autogenerated by map_potential_methods_to_mach-ports.py as part of The Kobold Framework
#import "ViewController.h"
#import "fake_header.h"

@interface ViewController ()

@end


@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
"""
print preamble

invocationDictionary = {}
id = 1

###################
#BEGIN TEST CODE
###################
#executable = "/System/Library/PrivateFrameworks/ManagedConfiguration.framework/Support/mdmd"
###################
#END TEST CODE
###################
total_invocations_generated = 0
total_methods = 0
total_completion_handlers = 0

# Shuffle methods
keys=executableDictionary.keys()
if len(sys.argv) > 1 and sys.argv[1] == "random":
    random.shuffle(keys)

for executable in keys:
  if "protocols" in executableDictionary[executable]:
    protsDict = executableDictionary[executable]["protocols"]
    for protocol in protsDict:
      for method in protsDict[protocol]:

        #TODO Deal with this hardcoding later...
        if method == "- (_Bool)listener:(NSXPCListener *)arg1 shouldAcceptNewConnection:(NSXPCConnection *)arg2;":
          continue
        if method == "- (void)clientXPCConnectionDidDisconnect:(NSObject *)arg1;":
          continue
        if method == "- (void)_URLSession:(NSURLSession *)arg1 needConnectedSocketToHost:(NSString *)arg2 port:(unsigned long long)arg3 completionHandler:(void (^)(int, struct))arg4;":
          continue
        #TODO Deal with this hardcoding later...
        if "byref" in method:
          continue
        #TODO Deal with this hardcoding later...
        if "AFTimeRange" in method:
          continue
        if "><" in method:
          continue
        ###################
        #BEGIN TEST CODE
        ###################
        #if id < 300 or id > 312 or id == 311:
        #  id += 1
        #  continue
        #if "key" not in executable:
        #  continue
        ###################
        #END TEST CODE
        ###################
        total_methods += 1
        if "(^)" in method:
          total_completion_handlers += 1
        for machport in executableDictionary[executable]["mach-ports"]:
          """
          if "replay" not in machport:
            id+=1
            continue
          if id in [572,574,576,578,963,1797,1807]:
            id+=1
            continue
          #if id < 100 or ( id > 200 and id < 600) or (id > 700 and id < 800) or ( id > 1000 and id < 1700) or id > 1798:
          if id < 100 or ( id > 200 and id < 600) or ( id > 1000 and id < 1700) or id > 1798:
            id+=1
            continue
          if id != 1798:
            id+=1
            continue
          """
          invocationDictionary[id] = {}
          invocationDictionary[id]["protocol"] = protocol
          invocationDictionary[id]["method"] = method
          invocationDictionary[id]["mach-port"] = machport
          objcCode = autoCodeThisMethod(method, machport, id)
          print "//////////////////////////////////////////////////"
          print "//BEGIN OBJC CODE FOR ID NUMBER " +str(id)
          print "//" + method
          print "//////////////////////////////////////////////////"
          print 'NSLog(@"id ' + str(id) + ': about to run''");'
          print 'NSLog(@"id ' + str(id) + ': MachPort: ' + machport + ' Method: '+ method.split(":")[0].split(")")[1] + '");'
          #print '[NSThread sleepForTimeInterval:0.1f];'
          print objcCode
          print "//////////////////////////////////////////////////"
          print "//END OBJC CODE FOR ID NUMBER " +str(id)
          print "//////////////////////////////////////////////////"
          id += 1
          total_invocations_generated += 1

with open('./data/invocationDictionary.pk', 'wb') as invDictHandle:
  pickle.dump(invocationDictionary, invDictHandle)

epilogue = """

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
"""
print epilogue
print "//total invocations generated: " + str(total_invocations_generated)
print "//total methods generated: " + str(total_methods)
print "//total completion handlers: " + str(total_completion_handlers)
