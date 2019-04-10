#!/usr/bin/python

import sqlite3
import re

location = 'entitlements.db'
ent_table_name = 'entitlements'
key_table_name = 'keys'

def init():
    global conn
    global c
    conn = sqlite3.connect(location)
    c = conn.cursor()
    create_database()

def create_database():
    sql = 'create table if not exists ' + ent_table_name + ' (key, value)'
    c.execute(sql)
    sql = 'create unique index ent_key_value on ' + ent_table_name + ' (key, value)'
    c.execute(sql)
    sql = 'create table if not exists ' + key_table_name + ' (key)'
    c.execute(sql)
    sql = 'create unique index ent_key on ' + key_table_name + ' (key)'
    c.execute(sql)
    conn.commit()

def clean():
    os.system('rm -rf ' + location)
def insert_ent(key, value=None):
    if value:
        sql = "insert or replace into " + ent_table_name + " (key, value) values ('%s', '%s')" % (key, value)
    else:
        sql = "insert or replace into " + key_table_name + " (key) values ('%s')" % (key)
    c.execute(sql)
    conn.commit()
    #print 'Inserted ', key, ' #### ',value


def create_tables():
    ent_file = open ("entitlementFactsWithPublic.pl", "r")

    for line in ent_file:
        if 'artistName("Apple")' in line:
            continue
        key = re.search('.*key\("(.*)"\),value.*',line).group(1)
        value = re.search('.*,value\((.*)\)\)\)\.',line).group(1)
        if value == "[]":
            continue
        insert_ent(key, value)
        insert_ent(key)


init()
create_tables()
#clean()
