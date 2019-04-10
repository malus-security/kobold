#!/usr/bin/python

#
# Find XPC protocol names and exposed methods by parsing class-dump output
# on executable files.
#
# class-dump output is to be piped to the standard input of the program.
# The program is provided the executable file path as argument.
# Parsed information is stored in Python pickle format in the file designated
# by the CONFIG_FILE name.
#
# Sample use (with class-dump):
#  ./class-dump ~/Projects/store/out/iPhone_4.0_64bit_11.1.2_15B202/fs/usr/libexec/rapportd  | ./parse-protocol-names.py /usr/libexec/rapportd
#

import re
import sys
import pickle


CONFIG_FILE = "protocols.pk"

STATE_NONE = 0
STATE_INTERFACE = 1
STATE_PROTOCOL = 2

def usage():
    print >>sys.stderr, "Usage: {} executable_filename".format(sys.argv[0])


def main():
    if len(sys.argv) != 2:
        usage()
        sys.exit(1)

    exec_file = sys.argv[1]

    try:
        with open(CONFIG_FILE, "rb") as f:
            try:
                dictionary = pickle.load(f)
            except (pickle.PickleError, EOFError):
                dictionary = {}
    except (IOError):
        dictionary = {}

    dictionary[exec_file] = {}

    # Read input file.
    inputText = sys.stdin.read().strip(); # .replace("\n","").replace("@end","@end\n")
    #print inputText

    # Find the names of the XPC protocols based on pattern of using NSXPCConnection.
    state = STATE_NONE
    nsxpc_protocols = set()
    nsxpc_present = False
    for line in inputText.split('\n'):
        if re.match('^@interface +.+ *: *.+ +\<.+\>$', line):
            nsxpc_present = False
            state = STATE_INTERFACE
            parts = re.split('[\<\>]+', line)
            protocols = re.split('[, ]+', parts[1])
            continue
        if re.match('^@end$', line):
            if state == STATE_INTERFACE:
                if nsxpc_present == True:
                    nsxpc_protocols.update(protocols)
                    nsxpc_present = False
            state = STATE_NONE
            continue
        if state == STATE_INTERFACE:
            if re.match('^ *NSXPCListener .*;$', line) or re.match('^ *NSXPCConnection .*;$', line):
                nsxpc_present = True
            continue

    state = STATE_NONE
    content = ""
    current_protocol = None
    for line in inputText.split('\n'):
        if re.match('^@protocol +.*$', line) or re.match('^@protocol +.* +\<.*\>$', line):
            protocol = re.split(' +', line)[1]
            if protocol in nsxpc_protocols:
                state = STATE_PROTOCOL
                current_protocol = protocol
                content = line + '\n'
            continue
        if re.match('^@end$', line):
            if state == STATE_PROTOCOL:
                content += (line + '\n')
                dictionary[exec_file][current_protocol] = content
                content = ""
                current_protocol = None
            state = STATE_NONE
            continue
        if state == STATE_PROTOCOL:
            content += (line + '\n')

    with open(CONFIG_FILE, "wb") as f:
        pickle.dump(dictionary, f)

if __name__ == "__main__":
    sys.exit(main())
