#!/usr/bin/python

import sqlite3
import random
import os


location = 'entitlements.db'
ent_table_name = 'entitlements'
key_table_name = 'keys'
output_folder_name = 'xml_entitlements/'
all_ents_xml = "_output_for_all_ents.xml"

def init():
    global conn
    global c
    conn = sqlite3.connect(location)
    conn.row_factory = lambda c, row: row[0]
    c = conn.cursor()

def clean():
    os.system('rm -rf ' + output_folder_name + ' ' + all_ents_xml)

def get_keys():
    sql = "select key from " + key_table_name
    c.execute(sql)
    return c.fetchall()

def get_values(key):
    sql = "select value from " + ent_table_name + " where key = '%s'" % (key)
    c.execute(sql)
    return c.fetchall()

def get_first_value(key):
    return get_values(key)[0]

def get_random_value(key):
    return random.choice(get_values(key))

def transform_value_to_XML(value):
    # Handle Bool values
    if value.startswith("bool"):
        return '<' + value.split('"')[1] + '/>'
    # Handle String values
    elif value.startswith("string"):
        return '<string>' + value.split('"')[1] + '</string>'
    # Handle Array values
    elif value.startswith("[string"):
        ret = "<array>"
        for val in value[1:-1].split(","):
            ret += "\n        <string>%s</string>" % val.split('"')[1]
        ret +="\n    </array>"
        return ret

def generate_XML_for_one(key):
    value = transform_value_to_XML(get_first_value(key))
    xml="""<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
    <key>%s</key>
    %s
</dict>
</plist>""" % (key, value)
    return xml

def generate_XML_for_all_ents():
    for key in get_keys():
        with open(os.path.join(output_folder_name, key+'.xml'), 'a') as the_file:
            the_file.write(generate_XML_for_one(key))

def generate_XML_with_all_ents():
    xml="""<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>"""
    for key in get_keys():
        value = transform_value_to_XML(get_first_value(key))
        xml += """
    <key>%s</key>
    %s""" % (key, value)
    xml += """
</dict>
</plist>"""
    with open(os.path.join(output_folder_name, all_ents_xml), 'a') as the_file:
        the_file.write(xml)

def generate_XML_with_partial_ents():
    xml="""<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>"""

    for key in get_keys():
        value = transform_value_to_XML(get_first_value(key))
        xml += """
    <key>%s</key>
    %s""" % (key, value)
        xml_with_final = xml + """
</dict>
</plist>"""
        with open(os.path.join(output_folder_name, key+'.xml'), 'a') as the_file:
            the_file.write(xml_with_final)



init()
if not os.path.exists(output_folder_name):
    os.makedirs(output_folder_name)


generate_XML_for_all_ents()
generate_XML_with_all_ents()
#generate_XML_with_partial_ents()
#clean()
