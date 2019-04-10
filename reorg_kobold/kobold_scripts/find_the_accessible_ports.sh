./runProlog.sh getThirdPartyPorts_unprivileged_try_regex mach_ports_entitlement_queries.pl | grep '^Port' | sed 's/^.*:\ //' > data/unprivileged_ports.out

./runProlog.sh getThirdPartyPorts_pub_try_regex mach_ports_entitlement_queries.pl | grep '^Port' | sed 's/^.*:\ //' > data/pub_ports.out

./runProlog.sh getThirdPartyPorts_pub_and_semiprivate_try_regex mach_ports_entitlement_queries.pl | grep '^Port' | sed 's/^.*:\ //' > data/pub_and_semiprivate_ports.out
