Entitlements data are gathered from "entitlementFactsWithPublic.pl" and added into a sqlite
database (you must have sqlite installed). Queries are made from that database and
entitlements XML files are created. The steps to do that are:

1. Run createEntitlementsDatabase.py. This will generate a sqlite database named "kobold".
This name can be changed in the script. The database contains two tabels: "entitlements" and "keys":


2. You can query the database like this:
mihai.carabas@mobilework:~/Desktop/iOracle/kobold/entitlement_queries$ sqlite3 kobold ".schema entitlements"
CREATE TABLE entitlements (key, value);
CREATE UNIQUE INDEX ent_key_value on entitlements (key, value);       <-- pair key-value is unique

mihai.carabas@mobilework:~/Desktop/iOracle/kobold/entitlement_queries$ sqlite3 kobold ".schema keys"
CREATE TABLE keys (key);
CREATE UNIQUE INDEX ent_key on keys (key);      <-- key is unique

mihai.carabas@mobilework:~/Desktop/iOracle/kobold/entitlement_queries$ sqlite3 kobold "select key from keys" | grep com.apple.developer.team-identifier
com.apple.developer.team-identifier


3. Run createXMLEntitlements.py. This will create a folder (named xml_entitlements; can be changed from the script)
that contains XML files like this:
    - xml_entitlements/_output_for_all_ents.xml  <- is an XML file with all the entitlements (1 key - 1 value).
    - xml_entitlements/*.xml  <- an XML file for each entitlement (1 key - 1 value)
