#!/usr/bin/python

import sqlite3
import re
import os

location = 'fuzzing.db'
table_appOutput = 'appOutput'
table_runs = 'runs'
table_devices = 'devices'

def init():
    #clean()
    global conn
    global c
    conn = sqlite3.connect(location)
    c = conn.cursor()
    create_database()

def create_database():
    # Table for fuzzing app output
    sql = 'create table if not exists ' + table_appOutput + ' ( \
            id INTEGER NOT NULL, \
            method TEXT NOT NULL, \
            machPort TEXT NOT NULL, \
            hasCompletion INTEGER DEFAULT 0, \
            connectionInvalidated INTEGER DEFAULT 0, \
            connectionTerminated INTEGER DEFAULT 0, \
            runID INTEGER)'
    c.execute(sql)
    sql = 'create unique index if not exists u_id on ' + table_appOutput + ' (id, runID)'
    c.execute(sql)

    # Table for runs
    sql = 'create table if not exists ' + table_runs + ' ( \
            id INTEGER PRIMARY KEY AUTOINCREMENT, \
            ent_file TEXT, \
            app_output_file TEXT, \
            crash_reporter_file TEXT, \
            filemon_file TEXT, \
            timestamp TEXT, \
            deviceID INTEGER)'
    c.execute(sql)

    # Table for Device characteristics
    sql = 'create table if not exists ' + table_devices + ' ( \
            id PRIMARY KEY, \
            name TEXT, \
            os TEXT, \
            device_version TEXT, \
            device_model TEXT, \
            code TEXT, \
            serial TEXT)'
    c.execute(sql)
    conn.commit()

def clean():
    os.system('rm -rf ' + location)

def insert_log(m_id, method, machPort, hasCompletion, connectionInvalidated, connectionTerminated, runID):
    sql = "insert into " + table_appOutput + " \
                (id, method, machPort, hasCompletion, connectionInvalidated, connectionTerminated, runID) values \
                (%d, '%s', '%s', %d, %d, %d, %d)" % \
                (m_id, method, machPort, hasCompletion, connectionInvalidated, connectionTerminated, runID)
    c.execute(sql)
    conn.commit()

def insert_run(ent_file, app_output_file, crash_reporter_file, filemon_file, timestamp, deviceID):
    sql = "insert into " + table_runs + " \
                (ent_file, app_output_file, crash_reporter_file, filemon_file, timestamp, deviceID) values\
                ('%s', '%s', '%s', '%s', '%s', %d)" % \
                (ent_file, app_output_file, crash_reporter_file, filemon_file, timestamp, deviceID)
    c.execute(sql)
    conn.commit()

def add_log(log_name, runID):
    curr_dir = os.path.dirname(__file__)
    log = os.path.join(curr_dir, log_name)
    log_file = open(log, "r")

    for m_id in range(1,2020):
        methodName, machPort, connectionTerminated, connectionInvalidated, hasCompletion = ["", "", 0, 0, 0]
        for line in open(log, "r"):
            if "id " + str(m_id) + ": " not in line:
                continue
            if "MachPort" in line:
                search = re.search('.*MachPort: (.*) Method: (.*)', line)
                machPort = search.group(1)
                methodName = search.group(2)
                continue
            if "Connection Terminated" in line:
                connectionTerminated = 1
                continue
            if "Connection Invalidated" in line:
                connectionInvalidated = 1
                continue
            if "Invocation has a completion handler" in line:
                hasCompletion = 1
                continue
        insert_log(m_id, methodName, machPort, hasCompletion,
                connectionInvalidated, connectionTerminated, runID)

def get_next_runID():
    sql = "select MAX(runID) from appOutput;"
    c.execute(sql)
    runID = c.fetchall()[0][0]
    if runID == None:
            return 0

    return int(runID)+1


def get_runID():
    sql = "select MAX(runID) from appOutput;"
    c.execute(sql)
    runID = c.fetchall()[0][0]
    if runID == None:
            return int(0)

    return int(runID)

init()
