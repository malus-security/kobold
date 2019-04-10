#!/bin/bash

# UPB devices
echo 'insert into devices(name, device_version, device_model, os, code, serial, jailbroken) values("Malus Security iPhone 6s", "iPhone 6S", "A1688", "10.2 (14C92)", "MKQPB2B/A", "C7JQRG4EGRYC", 1);' | sqlite3 fuzzing.db
echo 'insert into devices(name, device_version, device_model, os, code, serial, jailbroken) values("RD iPhone SE", "iPhone SE", "A1723", "11.1.2 (15B202)", "MLLN2CS/A", "F17S3QX6H2XJ", 1);' | sqlite3 fuzzing.db
echo 'insert into devices(name, device_version, device_model, os, code, serial, jailbroken) values("Costin iPhone 6", "iPhone 6", "A1586", "11.0.3 (15A432)", "MG4F2RM/A", "C7KPKHMVG5MR", 0);' | sqlite3 fuzzing.db
echo 'insert into devices(name, device_version, device_model, os, code, serial, jailbroken) values("Malus Security iPhone SE", "iPhone SE", "A1723", "9.3.2 (13F69)", "MLLN2CS/A", "F17S3QX6H2XJ", 1);' | sqlite3 fuzzing.db
