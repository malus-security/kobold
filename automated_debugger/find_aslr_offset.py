#!/usr/bin/python

#bridge between lldb and python for non-trivial scripting
#this python script can be loaded in lldb by invoking 'lldb -s'
#	and passing a text file with the following command
#	command script import /path/to/this/file
import lldb

#define a custom lldb command.
def find_aslr(debugger, command, result, internal_dict):
  print >> result, "Hello, World!"

#anything here will execute as soon as this python module is imported
def __lldb_init_module(debugger, internal_dict):
  #passes this command to lldb without return object
  debugger.HandleCommand("command script add -f find_aslr_offset.find_aslr find_aslr")
  print "The 'find_aslr command has been installed."
  #set up command interpreter so that we can get results of commands
  ci = debugger.GetCommandInterpreter()
  #set up a return object to handle resuls of commands
  ro = lldb.SBCommandReturnObject()

  #figure out the name of the module we want to dump to find aslr offset
  ci.HandleCommand("image list", ro)
  image_list_lines = ro.GetOutput().strip().split("\n")
  target_line = image_list_lines[0]
  target_module = target_line.strip().split(" ")[-2]
  print target_module

  #find the relevant fields in the module's section dump
  #	to calculate the aslr offset
  ci.HandleCommand("image dump sections "+target_module, ro)
  section_dump_lines = ro.GetOutput().strip().split("\n")
  for line in section_dump_lines:
    print line
  zero_page_line = section_dump_lines[3]
  zero_end_address = zero_page_line.split("-")[1].split(")")[0]
  print "zero: "+zero_end_address
  text_section_line = section_dump_lines[4]
  text_start_address = text_section_line.split("[")[1].split("-")[0]
  print "text: "+text_start_address
  aslr_shift = int(text_start_address,0) - int(zero_end_address,0)
  print "aslr: "+str(hex(aslr_shift))

  #TODO Set up a breakpoint using the aslr shift and some constant value.
  #Set a condition on the breakpoint such that a record is logged to a file.
  #Continue with execution automatically after logging the event.
  


