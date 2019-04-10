:-[data/consolidated_sb_facts].
:-[sandboxAllowRules].
:-[data/entitlementFactsWithPublic].
:-[data/port_to_exec_mapping].

unprivileged_model(entitlements([]),extensions([]),home("/private/var/mobile"),profile("container")).

%note that the get-task-allow entitlement is set to false.
%we need to state this in the paper, if it isn't there already
public_model(entitlements(EntSet),extensions([]),home("/private/var/mobile"),profile("container")):-
  findall(Entitlement,appStoreEntitlement(_,artistName("internal"),_,_,Entitlement),EntList),
  list_to_set(EntList,EntSet),
  length(EntSet,Len),
  writeln(Len).

semiprivate_model(entitlements(EntSet),extensions([]),home("/private/var/mobile"),profile("container")):-
  findall(Entitlement,appStoreEntitlement(_,artistName("thirdPartyDeveloper"),_,_,Entitlement),EntList),
  findall(Entitlement,appStoreEntitlement(_,artistName("internal"),_,_,Entitlement),EntList2),
  append(EntList,EntList2,PublicAndSemiprivateEntList),
  list_to_set(PublicAndSemiprivateEntList,EntSet),
  list_to_set(EntList,JustSemiprivateSet),
  length(EntSet,BothLen),
  writeln(BothLen),
  length(JustSemiprivateSet,SemiLen),
  writeln(SemiLen).

accessibleMachPorts(Ent,Ext,Home,Prof):-
  relevantRule(Ent,Ext,Home,Prof,operation("mach-lookup"),subject(machService(Port)),decision("allow"),filters(Filters)),
  %write("Entitlements: "),writeln(Ent),
  write("Port: "),writeln(Port),
  write("Filters: "),writeln(Filters),
  fail.

accessibleMachPorts_try_to_match_regex(Ent,Ext,Home,Prof):-
  portToExec(Port,_), 
  relevantRule(Ent,Ext,Home,Prof,operation("mach-lookup"),subject(machService(Port)),decision("allow"),filters(Filters)),
  write("Port: "),writeln(Port),
  write("Filters: "),writeln(Filters),
  fail.
 
  
getThirdPartyPorts_unprivileged:-
  unprivileged_model(Ent,Ext,Home,Prof),
  accessibleMachPorts(Ent,Ext,Home,Prof).

getThirdPartyPorts_unprivileged_try_regex:-
  unprivileged_model(Ent,Ext,Home,Prof),
  accessibleMachPorts_try_to_match_regex(Ent,Ext,Home,Prof).

getThirdPartyPorts_pub_and_semiprivate:-
  semiprivate_model(Ent,Ext,Home,Prof),
  accessibleMachPorts(Ent,Ext,Home,Prof).

getThirdPartyPorts_pub_and_semiprivate_try_regex:-
  semiprivate_model(Ent,Ext,Home,Prof),
  accessibleMachPorts_try_to_match_regex(Ent,Ext,Home,Prof).

getThirdPartyPorts_pub_try_regex:-
  public_model(Ent,Ext,Home,Prof),
  accessibleMachPorts_try_to_match_regex(Ent,Ext,Home,Prof).


test_ent_filter:-
  semiprivate_model(Ent,Ext,Home,Prof),
  relevantRule(Ent,Ext,Home,Prof,operation("mach-lookup"),subject(machService("com.apple.siri.vocabularyupdates")),decision("allow"),filters(Filters)),
  writeln(Filters).
test_ent_filter2:-
  unprivileged_model(Ent,Ext,Home,Prof),
  relevantRule(Ent,Ext,Home,Prof,operation("mach-lookup"),subject(machService("com.apple.siri.vocabularyupdates")),decision("allow"),filters(Filters)),
  writeln(Filters).

