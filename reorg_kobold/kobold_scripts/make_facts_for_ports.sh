cat data/port_to_exec_mapping.csv | sed 's/^/portToExec("/' | sed 's/,/","/' | sed 's/$/")./'
