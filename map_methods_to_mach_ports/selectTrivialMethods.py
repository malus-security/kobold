#!/bin/python

import re

trivialMethods=""
with open("xpc_11.1.2.h") as f:
    nr_args = 0
    for line in f:
        line = line.rstrip()

        # Only considering the methods
        if not (line.startswith("-") and line.endswith(";")):
            continue
        method = line

        # Saving methods with no arguments.
        if not (":" in line):
            line = line.split('(', 1)[1].split(')')[0].replace("*","").strip()
            if ((line[0] >= 'a' and line[0] <= 'z') or (line in open('NSSecureCodingTypes.txt').read())):
                trivialMethods += method + "\n"
                continue

        # There are as many arguments as ":" characters
        methodArgs = line.split(":")
        compliant=True
        for num in range(1,len(methodArgs)):
            # Handling the completion methods 
            if methodArgs[num].startswith("(void (^)"):
                arg1 = methodArgs[num][:-len("(void (\^)")].split(')')[0]
                compliant = False
                break
                # TODO

            # Remove paranthesis, pointers and whitespaces
            arg =  methodArgs[num].split('(', 1)[1].split(')')[0].replace("*","").strip()

            # Select only the methods that contain arguments that start with a small letter or part of NSSecureCodingTypes
            if not ((arg[0] >= 'a' and arg[0] <= 'z') or (arg in open('NSSecureCodingTypes.txt').read())):
               #trivialMethods += method + "\n"
               compliant = False
        if compliant:
            trivialMethods += method + "\n"

print trivialMethods
