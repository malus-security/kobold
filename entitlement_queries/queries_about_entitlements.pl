:- 
  use_module(library(regex)).
  %[typeFacts].
  %[systemEntitlementFacts].

countEntitlements :-
  setof(Sig, Col^Val^(possessedEntitlement(collection(Col),signature(Sig),entitlement(key(Key),value(Val))), not(Sig =~ '^com.apple.*'/i)), Sigs), 
  length(Sigs, Len), 
  write(Key), write(";"), write(Len), write(";"), writeln(Sigs), 
  fail. 

publicEntitlement(EntKey) :-
  appStoreEntitlement(_,artistName("internal"),_,_,entitlement(key(EntKey),_)).

privateEntitlement(EntKey) :-
  %an Apple app has the entitlement
  appStoreEntitlement(_,artistName("Apple"),_,_,entitlement(key(EntKey),_)),
  %no non-Apple app has the entitlement
  not(appStoreEntitlement(_,artistName("thirdPartyDeveloper"),_,_,entitlement(key(EntKey),_))),
  not(appStoreEntitlement(_,artistName("internal"),_,_,entitlement(key(EntKey),_))).

semiPrivateEntitlement(EntKey) :-
  appStoreEntitlement(_,artistName("thirdPartyDeveloper"),_,_,entitlement(key(EntKey),_)),
  not(publicEntitlement(EntKey)),
  not(privateEntitlement(EntKey)).

listPublicEntitlements(EntList) :-
  %appStoreEntitlement(_,artistName("internal"),_,_,Ent),
  findall(Ent, appStoreEntitlement(_,artistName("internal"),_,_,Ent), EntList).

listSemiPrivateKeys(SemiPrivateKeyList) :-
  %appStoreEntitlement(_,artistName("internal"),_,_,Ent),
  findall(ThirdPartyEntString,
    (appStoreEntitlement(_,artistName("thirdPartyDeveloper"),_,_,entitlement(key(ThirdPartyEnt),_)),
    %converting to a string seems to make set operations work better
    atom_string(ThirdPartyEnt,ThirdPartyEntString)),
    ThirdPartyEntList),

  findall(InternalEntString,
    (appStoreEntitlement(_,artistName("internal"),_,_,entitlement(key(InternalEnt),_)),
    atom_string(InternalEnt,InternalEntString)),
    InternalEntList),

  list_to_set(ThirdPartyEntList,TPSet),
  list_to_set(InternalEntList,IntSet),

  subtract(TPSet, IntSet, SemiPrivateKeyList).
  %length(SemiPrivateKeyList, LenSPKeys),
  %writeln(LenSPKeys),
  %writeln(SemiPrivateKeyList).

%TODO: These findall and list_to_set operations should all be abstracted into smaller rules...

listSemiPrivateEnts(SemiPrivateEntList) :-
  listSemiPrivateKeys(SPKeys),
  findall(SemiPrivateEnt,
    (appStoreEntitlement(_,artistName("thirdPartyDeveloper"),_,_,SemiPrivateEnt),
    SemiPrivateEnt = entitlement(key(Key),_),
    member(Key, SPKeys)),
    SemiPrivateEntList).
  %write(SemiPrivateEntList),
  %fail.


servicesAccessibleWithSemiPrivateEntitlements :-
  listSemiPrivateEnts(SPEntList),
  findall(MachServiceSPEntString,
    (relevantRule(entitlements(SPEntList),extensions([]),home("/private/var/mobile"),profile("container"),
      operation("mach-lookup"),
      %this should actually say object, but I used the wrong variable in the rule.
      subject(machService(MachServiceSPEnt)),
      %atoms and unbound variables cause trouble in set operations, so we convert atoms to strings and ignore unbound variables.
      %one reason a variable might be unbound is a regular expression base filter without a set of services to compare to.
      decision(Decision),filters(Filters)), nonvar(MachServiceSPEnt), atom_string(MachServiceSPEnt, MachServiceSPEntString)),
    MachServicesSPEnt),

  writeln(MachServicesSPEnt),
    
  findall(MachServiceZeroEntString,
    (relevantRule(entitlements([]),extensions([]),home("/private/var/mobile"),profile("container"),
      operation("mach-lookup"),
      %this should actually say object, but I used the wrong variable in the rule.
      subject(machService(MachServiceZeroEnt)),
      decision(Decision),filters(Filters)), nonvar(MachServiceZeroEnt), atom_string(MachServiceZeroEnt, MachServiceZeroEntString)),
    MachServicesZeroEnt),
  
    list_to_set(MachServicesSPEnt,SPSet),
    list_to_set(MachServicesZeroEnt,ZeroSet),

    length(SPSet,SPLen),
    length(ZeroSet,ZeroLen),
    writeln(ZeroLen),
    writeln(SPLen),

    findall(Differ, (member(Differ,SPSet),not(member(Differ,ZeroSet))),DiffList),
    writeln(DiffList),
    fail.

servicesAccessibleWithPublicEntitlements :-
  listPublicEntitlements(EntList),
  findall(MachServicePublicEntString,
    (relevantRule(entitlements(EntList),extensions([]),home("/private/var/mobile"),profile("container"),
      operation("mach-lookup"),
      %this should actually say object, but I used the wrong variable in the rule.
      subject(machService(MachServicePublicEnt)),
      decision(Decision),filters(Filters)), nonvar(MachServicePublicEnt), atom_string(MachServicePublicEnt, MachServicePublicEntString)),
    MachServicesPublicEnt),
    
  findall(MachServiceZeroEntString,
    (relevantRule(entitlements([]),extensions([]),home("/private/var/mobile"),profile("container"),
      operation("mach-lookup"),
      %this should actually say object, but I used the wrong variable in the rule.
      subject(machService(MachServiceZeroEnt)),
      decision(Decision),filters(Filters)), nonvar(MachServiceZeroEnt), atom_string(MachServiceZeroEnt, MachServiceZeroEntString)),
    MachServicesZeroEnt),
  
    list_to_set(MachServicesPublicEnt,PubSet),
    list_to_set(MachServicesZeroEnt,ZeroSet),

    findall(Differ, (member(Differ,PubSet),not(member(Differ,ZeroSet))),DiffList),
    writeln(DiffList),
    fail.



%This is a preliminary number that doesn't consider local vs global service names and doesn't consider regex in sandbox filters
listServicesAvailableWithoutEntitlements :-
  relevantRule(
    entitlements([]),
    extensions([]),
    home("/private/var/mobile"),
    profile("container"),
    operation("mach-lookup"),
    %this should actually say object, but I used the wrong variable in the rule.
    subject(machService(MachService)),
    decision(Decision),
    filters(Filters)),
    writeln(MachService),
    fail.


%list all unique entitlement keys
getEntKeys :-
  setof(Key,
    FilePath^Value^(
      processEntitlement(FilePath,entitlement(key(Key),Value))
    ),
    KeyList),
  member(K,KeyList),
  writeln(K),
  fail.

findEntKeyReferences :-
  setof(Key,
    FilePath^Value^(
      processEntitlement(FilePath,entitlement(key(Key),Value))
    ),
    KeyList),
  member(K,KeyList),
  processString(filePath(Path),stringFromProgram(K)),
  write(Path),write(","),writeln(K),
  fail.

findKeyRefForSingleServiceProviders :-
  %set of processes with one service
  setof(Proc,
    Service^Conn^(
      dynamic_service_observation(scanned_proc(Proc),direction("receiving"),Service,Conn)
    ),
    %I don't think these cuts are really doing anything. 
    %I suppose that even without the cut Prolog won't backtrack these operations.
    ProcList),!,

  setof(Key,
    FilePath^Value^(
      processEntitlement(FilePath,entitlement(key(Key),Value))
    ),
    KeyList),!,

  member(P,ProcList),
  setof(Service,
    Conn^(
      dynamic_service_observation(scanned_proc(P),direction("receiving"),service(Service),Conn)
    ),
    ServiceList),
  length(ServiceList,ServiceCount),
  %I think this is what I want, but I can try == if this doesn't seem to be working. Test for correctness.
  ServiceCount=1,

  %I'm using findall because it can still return an empty list even if it fails.
  %This feature allows us to also output executables providing services, but not referencing any entitlements.
  findall(K,
    (member(K,KeyList),
    processString(filePath(P),stringFromProgram(K))),
    KList),

  %ServiceList should only contain one service.
  %KList can contain 0 or more entitlement keys (something is probably wrong if none of the KLists are empty).
  %The commas in KList could cause trouble for other scripts that use this output (it is not a well formatted CSV), but we can modify it as needed.
  write(P),write(","),write(ServiceList),write(","),writeln(KList),
  fail.

%same as findKeyRefForSingleServiceProviders, but requiring 0 ent references instead of requiring 1 provided service
listProvidersWithoutChecks :-
  setof(Proc,
    Service^Conn^(
      dynamic_service_observation(scanned_proc(Proc),direction("receiving"),Service,Conn)
    ),
    %I don't think these cuts are really doing anything. 
    %I suppose that even without the cut Prolog won't backtrack these operations.
    ProcList),!,

  setof(Key,
    FilePath^Value^(
      processEntitlement(FilePath,entitlement(key(Key),Value))
    ),
    KeyList),!,

  member(P,ProcList),
  setof(Service,
    Conn^(
      dynamic_service_observation(scanned_proc(P),direction("receiving"),service(Service),Conn)
    ),
    ServiceList),

  %I'm using findall because it can still return an empty list even if it fails.
  %This feature allows us to also output executables providing services, but not referencing any entitlements.
  findall(K,
    (member(K,KeyList),
    processString(filePath(P),stringFromProgram(K))),
    KList),

  %For now, I only want to see providers and services that do not reference any entitlement keys
  length(KList,KCount),
  KCount=0,

  %KList should contain 0.
  write(P),write(","),write(ServiceList),write(","),writeln(KList),
  fail.

%I should be able to list semiPrivateEntitlement keys by getting lists of all internal keys and all third party keys and then doing a diff.
%This should be much faster than using negation, and I see no reason to consider private entitlements at all.

%TODO to show entitlements, I should use setof to make a list and then use that list as a parameter to the relevantRule abstraction.


  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%END of Sigil Code. The rest is just for reference.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%show all files that are Mach-O executables
getProgramFacts :- 
  file(fileType(Y),filePath(X)),
  Y =~ 'Mach-O.*executable',
  write('process(filepath("'),write(X),write('")).\n'),
  fail.

%show just the file paths
justPaths:- 
  %file(filePath(X),fileType(Y)),
  file(fileType(Y),filePath(X)),
  Y =~ 'Mach-O.*executable',
  writeln(X),
  fail.

%show just the file paths
justApplePaths:- 
  processSignature(filePath(X),_),
  writeln(X),
  fail.


%outputs all unique entitlement keys required by rules in the container profile.
%TODO: this does not consider negated entitlements (e.g., require-not(require-entitlement(X)))
%TODO: for now this works with container, but eventually it should work on a larger collection of sandbox rules
uniqueRequiredEntitlements:- 
  [container],
  setof(Ent,
    %this syntax tells prolog not to consider Operation, Filters, or Values when determining if the match is unique
    %I only want unique entitlement keys, so I did not tell prolog to ignore Ent when determining uniqueness.
    Operation^Filters^Value^(
      allow(Operation,Filters),
      member(require-entitlement(Ent,Value),Filters)
    ),
    Out),
  member(B,Out),
  writeln(B),
  fail.

pathsToEntCheckers:-
  [stringsFromPrograms],
  setof(Path,processString(filePath(Path),stringFromProgram("_SecTaskCopyValueForEntitlement")),Out),
  member(X,Out),
  writeln(X),
  fail.


%output csv for path and bundle id
identifiers:- 
  [appleProcessIdentifierFacts],
  process(filepath(X),identifier(Y)),
  write(X),write(","),writeln(Y),
  fail.


%show all entitlements detected
%setof returns a list of unique items that match X.
%I'm not sure what Y's role is in setof.
uniqueEntitlements:- setof(X,A^Y^process(Y,entitlement(key(X),A)),Out),
member(Z,Out), writeln(Z),
fail.

uniqueUsers:- 
  [fileMetaDataFacts],
  setof(X,Y^file(Y,ownerUserName(X)),Out),
  member(Z,Out), writeln(Z),
  fail.

processUsers:- 
  [fileMetaDataFacts],
  [appleProcessIdentifierFacts],
  file(filepath(X),_,_,_,_,_,permissionBits(A),_,ownerUserName(B),_),
  process(filepath(X),identifier(Z)),
  write("processUser(filepath(\""),write(X),
  write("\"),identifier(\""),write(Z),
  write("\"),user(\""),write(B),
  write("\"),permissionBits("),write(A),
  writeln("))."),
  fail.

%interesting negation example. Which apple processes are owned by groups other than wheel and admin?
%file(X,ownerGroupName(Y)), process(X,_),not(Y = "wheel"),not(Y = "admin").

%:- ignore(getProgramFacts),halt.
%:- ignore(justPaths),halt.
%:- ignore(uniqueEntitlements),halt.
%:- ignore(processUsers),halt.
%:- ignore(uniqueUsers),halt.

%this just uses the graph path rules created below.
testPath:-
  [edges],
  %path(start,end,maxLength,result)
  path(1,3,4,Path),
  writeln(Path),
  fail.

%this makes all edges bidirectional.
%should edge direction matter for iOracle?
connected(X,Y) :- edge(X,Y) ; edge(Y,X).

%this code is based on the tutorial at
% https://www.cpp.edu/~jrfisher/www/prolog_tutorial/2_15.html
path(A,B,C,Path) :-
    travel(A,B,[A],Q), 
    %the next two lines limit the maximum size of the path
    length(Q,L),
    L =< C,
    reverse(Q,Path).

travel(A,B,P,[B|P]) :- 
  connected(A,B).
travel(A,B,Visited,Path) :-
  connected(A,C),           
  %the next two lines prevent cycles or infinite loops
  C \== B,
  \+member(C,Visited),
  travel(C,B,[C|Visited],Path).

%find all references to known entitlements. These imply that a given process may check for a certain entitlement.
%TODO This query doesn't consider kernel or dyld_shared_cache
%later we should try to determine which entitlement values a process may check for.
%ideally we could pair the entitlement keys and values together (e.g., this value is referenced and only appears alongside this key)
%this is a task that could be assigned to a Master's student.
entitlementReferences:-
  [allEntitlementsFacts],
  [stringsFromPrograms],
  %I need to define a set of entitlements. The way I'm doing this now is creating a lot of duplicates and being very inefficient
  %it won't work if you try a _ instead of using Z
  setof(X,Y^Z^process(Z,entitlement(key(X),Y)),Out),
  member(A,Out),
  processString(filePath(B),stringFromProgram(A)),
  write("entitlementReference(filePath(\""),write(B),write("\"),entitlementKey(\""),write(A),writeln("\"))."),
  fail.

%same as entitlement references but works on dyld_shared_cache segments
dyldEntitlementReferences:-
  [allEntitlementsFacts],
  [dyldStrings],
  %I need to define a set of entitlements. The way I'm doing this now is creating a lot of duplicates and being very inefficient
  %it won't work if you try a _ instead of using Z
  setof(X,Y^Z^process(Z,entitlement(key(X),Y)),Out),
  member(A,Out),
  dyldString(segment(B),stringFromProgram(A)),
  write("dyldEntitlementReference(segment(\""),write(B),write("\"),entitlementKey(\""),write(A),writeln("\"))."),
  fail.

%same as entitlement references but works on kernel segments
kernelEntitlementReferences:-
  [allEntitlementsFacts],
  [kernelStrings],
  %I need to define a set of entitlements. The way I'm doing this now is creating a lot of duplicates and being very inefficient
  %it won't work if you try a _ instead of using Z
  setof(X,Y^Z^process(Z,entitlement(key(X),Y)),Out),
  member(A,Out),
  kernelString(segment(B),stringFromProgram(A)),
  write("kernelEntitlementReference(segment(\""),write(B),write("\"),entitlementKey(\""),write(A),writeln("\"))."),
  fail.

%TODO the format of entitlements has changed, so some old queries might not work until we update them.
containerEnt:-
  processEntitlement(filePath(Path),entitlement(key("com.apple.private.security.container-required"),_)),
  write("usesSandbox(processPath(\""),write(Path),writeln("\"),profile(\"container\"),mechanism(entitlementKey(\"com.apple.private.security.container-required\")))."),
  fail.

seatbeltEnt:-
  processEntitlement(filePath(Path),entitlement(key("seatbelt-profiles"),value([string(Value)]))),
  %the container2 profile does not exist and is always overridden by the container profile
  Value \= "container2",
  write("usesSandbox(processPath(\""),write(Path),write("\"),profile(\""),write(Value),writeln("\"),mechanism(entitlementKey(\"seatbelt-profiles\")))."),
  fail.

%this will change depending on the iOS version
%I think it's the same for iOS 8 and 9, but for 7 this path won't be accurate.
%TODO for now we don't care much about third party apps, but we may need to fix this later.
pathBasedProfile:-
  setof(Path,
  (
  processSignature(filePath(Path),_),
  (
      Path =~ '.*/mobile/Containers/Bundle.*'
    ;
      Path =~ '^/private/var/mobile/Applications/.*'
  )
  ),Pathset),
  member(X,Pathset),
  write("usesSandbox(processPath(\""),write(X),writeln("\"),profile(\"container\"),mechanism(pathBased))."),
  fail.

%getting the profiles this way seems to have gained one more fact. Maybe there is an executable with multiple mechanisms?
getProfilesFromEntitlementsAndPaths:-
  %[systemEntitlementFacts],
  %[appleProgramSignatures],
  %I should double check why this works, but it seems to give me what I expect by trying to satisfy both queries in every possible way.
  %the ; represents an OR operation, but because we are pushing to failure, maybe this is what I want according to DeMorgen's law.
  (seatbeltEnt; containerEnt; pathBasedProfile).

getSelfAssigningProcessesWithSymbols:-
  %[externalSymbols],
  setof(Path,
  (
      processSymbol(filePath(Path),symbol("_sandbox_init"))
    ;
      processSymbol(filePath(Path),symbol("_sandbox_init_with_parameters"))
    ;
      processSymbol(filePath(Path),symbol("_sandbox_apply_container"))
  ),Out),
  member(X,Out),
  writeln(X),
  fail.

getDirectFileAccessCallersWithSymbols:-
  %[externalSymbols],
  setof(Path,
  (
      processSymbol(filePath(Path),symbol("_chmod"))
    ;
      processSymbol(filePath(Path),symbol("_chown"))
    %;
    %  processSymbol(filePath(Path),symbol("_rename"))
    %;
    %  processSymbol(filePath(Path),symbol("_open"))
  ),Out),
  member(X,Out),
  writeln(X),
  fail.



%ignore any profile with a parenthesis in it
%consider running a bash script to remove duplicate rules.
%I should write a bash script that automates the entire process of figuring out which sandboxes are selfApplied, finding the self-applied profiles used, and deduplicating.
parseSelfAppliedProfiles:-
  %[selfApplySandbox],
  functionCalled(filePath(X),_,parameter(Z)),
  %we got at least one sandbox initialization that used a self defined profile.
  %this is worth mentioning in the paper, but it needs to be removed from these results.
  %manual analysis suggests that this self defined profile is not normally used.
  Z =~ '^[^()]+$',
  write("usesSandbox(processPath(\""),write(X),
  write("\"),profile(\""),write(Z),
  writeln("\"),mechanism(selfApplied))."),
  fail.

getMetaDataTypes:-
  setof(X,Y^fileType(type(X),filePath(Y)),XList),
  writeln(XList).

getVnodeTypes:-
  fileType(Type,filePath(File)),
  processTypes(Type,File),
  fail.

processTypes(type("d"),File):-
  write("vnodeType(file(\""),write(File),write("\"),type("),
  write("directory"),
  writeln(")).").

processTypes(type("l"),File):-
  write("vnodeType(file(\""),write(File),write("\"),type("),
  write("symlink"),
  writeln(")).").

processTypes(type("b"),File):-
  write("vnodeType(file(\""),write(File),write("\"),type("),
  write("block-device"),
  writeln(")).").

processTypes(type("c"),File):-
  write("vnodeType(file(\""),write(File),write("\"),type("),
  write("character-device"),
  writeln("))."),
  %for now we will assume that all character devices are also tty devices
  %tty doesn't seem to be an official vnode type anyway...
  % https://www.freebsd.org/cgi/man.cgi?query=vnode
  write("vnodeType(file(\""),write(File),write("\"),type("),
  write("tty"),
  writeln(")).").

processTypes(type("f"),File):-
  write("vnodeType(file(\""),write(File),write("\"),type("),
  write("regular-file"),
  writeln(")).").

%is there a vnode type for sockets?
%yes, there seems to be, but maybe Apple doesn't care about them, so we don't know how it would be called in SBPL.
%how do we determine which files are tty types?




