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

countPrivateEnts :-
  privateEntitlement(EntKey),
  setof(Bid, Val^Col^AppId^appStoreEntitlement(itemId(AppId),artistName("Apple"),bundleId(Bid),Col,entitlement(key(EntKey),Val)),Bids),
  length(Bids, Len),
  %getExampleApp(Bids,Example),
  getValueType(EntKey, ValueType),
  write("Private;"), write(EntKey), write(";"), write(ValueType), write(";"), write(Len), write(";"), writeln(Bids), 
  fail.

countPublicEnts :-
  publicEntitlement(EntKey),
  (
    \+ appStoreEntitlement(_,artistName("thirdPartyDeveloper"),_,_,entitlement(key(EntKey),_)) -> Bids = []
    ;
    setof(Bid, Val^Col^AppId^appStoreEntitlement(itemId(AppId),artistName("thirdPartyDeveloper"),bundleId(Bid),Col,entitlement(key(EntKey),Val)),Bids)
  ),
  length(Bids, Len),
  getValueType(EntKey, ValueType),
  %getExampleApp(Bids,Example),
  write("Public;"), write(EntKey), write(";"), write(ValueType), write(";"), write(Len), write(";"), writeln(Bids), 
  fail.

countSemiPrivateEnts :-
  semiPrivateEntitlement(EntKey),
  setof(Bid, Val^Col^AppId^appStoreEntitlement(itemId(AppId),artistName("thirdPartyDeveloper"),bundleId(Bid),Col,entitlement(key(EntKey),Val)),Bids),
  length(Bids, Len),
  getValueType(EntKey, ValueType),
  %getExampleApp(Bids,Example),
  write("Semi-Private;"), write(EntKey), write(";"), write(ValueType), write(";"), write(Len), write(";"), writeln(Bids), 
  fail.

getValueType(EntKey, ValueType) :-
  appStoreEntitlement(_,_,_,_,entitlement(key(EntKey),value([string(_)|_]))),
  appStoreEntitlement(_,_,_,_,entitlement(key(EntKey),value(string(_)))),
  ValueType= "arrayOfStrings or string",!.

getValueType(EntKey, ValueType) :-
  appStoreEntitlement(_,_,_,_,entitlement(key(EntKey),value(bool(_)))),
  ValueType= "bool".

getValueType(EntKey, ValueType) :-
  appStoreEntitlement(_,_,_,_,entitlement(key(EntKey),value(string(_)))),
  ValueType= "string".

getValueType(EntKey, ValueType) :-
  appStoreEntitlement(_,_,_,_,entitlement(key(EntKey),value([string(_)|_]))),
  ValueType= "arrayOfStrings".

getExampleApp([],Example):-
  Example = "N/A".

getExampleApp([H|_],Example):-
  Example = H.
  
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
