#!/usr/bin/python

#This script extracts meta-data from the cache of configuration plists that launchd uses to coordinate IPC (mostly for XPC).

import os
import sys
import plistlib

def parseAppExtensions(appExt_Dict):
  for appex_dict in appExt_Dict.values():
    execPath_String = str(appex_dict['_executablePath'])
    serviceId_String = str(appex_dict['_serviceIdentifier'])
    #TODO Do any of service identifiers match with mach port names that third party apps are allowed to access?
    #print "ipcConfig(type('AppExensions'),executablePath('"+execPath_String+"'),serviceIdentifier('"+serviceId_String+"'),roleAccount(''),allowedClients([]))."
    print serviceId_String +','+ execPath_String[1:]

  
def parseLaunchDaemons(launchDaemons_Dict):
  #There are some other access control relevant values in these plists, but we shouldn't need these for Sigil.
  #For sigil, we are mostly using these plists to map executable paths to the mach services they provide.
  for plist_Dict in launchDaemons_Dict.values():
    #TODO figure out the executable path
    #this default value should be overridden if a valid path is found
    if 'Program' in plist_Dict:
      execPath_String = plist_Dict['Program']
    elif 'ProgramArguments' in plist_Dict:
      execPath_String = plist_Dict['ProgramArguments'][0]
    else:
      #The com.apple.jetsamproperties plist entries seem to be strange cases that don't seem to represent an executable hosting a service.
      #Two of these non-standard plists appear. We can just ignore them for now. I don't think they are relevant to Sigil.
      #print "ERROR: no executable path found in plist: "+str(plist_Dict)
      continue
    if 'MachServices' in plist_Dict:
      for machService_String in plist_Dict['MachServices']:
        #print "ipcConfig(type('LaunchDaemons'),executablePath('"+execPath_String+"'),serviceIdentifier('"+machService_String+"'),roleAccount(''),allowedClients([]))."
        print machService_String + "," + execPath_String[1:]


def parseLibraryTree(libraryTree_Dict):
  for framework_Dict in libraryTree_Dict["_imagePathToInfo"].values():
    for bundle_Dict in framework_Dict["_serviceBundles"]:
      execPath_String = bundle_Dict['_executablePath']
      serviceId_String = bundle_Dict['_serviceIdentifier']
      infoPlist_Dict = bundle_Dict['_infoPlist']
      XPC_Dict = infoPlist_Dict['XPCService']
      roleAccount = ""
      if '_RoleAccount' in XPC_Dict:
        roleAccount = XPC_Dict['_RoleAccount']
      allowedClients = []
      if '_AllowedClients' in XPC_Dict:
        allowedClients = XPC_Dict['_AllowedClients']
      #print "ipcConfig(type('SystemLibraryTreeState'),executablePath('"+execPath_String+"'),serviceIdentifier('"+serviceId_String+"'),roleAccount('"+roleAccount+"'),allowedClients("+str(allowedClients)+"))."
    print serviceId_String +','+ execPath_String[1:]


#Usage
if len(sys.argv) < 2:
  print "Usage: parse_IPC_cache_Plist.py xpcd_cache.plist"
  exit()

#arguments
inputFile = sys.argv[1]

pl = plistlib.readPlist(inputFile)
#just name the key you want to look up, and the associated value is returned.

appExt = pl['AppExtensions']
launchDaemons = pl['LaunchDaemons']
#these seem to be xpc services that are included as parts of frameworks.
libraryTree = pl['SystemLibraryTreeState']

parseAppExtensions(appExt)
parseLaunchDaemons(launchDaemons)
parseLibraryTree(libraryTree)
