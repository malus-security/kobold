#!/bin/bash

# This script creates a new app with different parameters for XPC methods

PROJECT_SOURCE=CallingMethodsApp
NEW_PROJECT=$1

cp -r $PROJECT_SOURCE $NEW_PROJECT
python ../map_methods_to_mach_ports/fuzzingSimpleArgs.py > "$NEW_PROJECT/CallingMethodsApp/ViewController.m"
