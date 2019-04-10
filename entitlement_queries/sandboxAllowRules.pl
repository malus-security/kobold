:-
  use_module(library(regex)).

getAttributes(process(Process),entitlements(Ent),extensions(Ext),user(User),home(Home),profile(Profile)):-
  %processProfile(filePath(Process),profile(Profile)),
  usesSandbox(processPath(Process),profile(Profile),_),
  (
    (processOwnership(uid(User),_,comm(Process)))
    ;
    %this is a hack, but it seems reasonable.
    %if we don't know the process owner from dynamic analysis, just assume user mobile (501)
    (not(processOwnership(uid(User),_,comm(Process))), User="501")
  ),
  findall(X,sandbox_extension(process(Process),X),Ext),
  findall(Y,processEntitlement(filePath(Process),Y),Ent),
  %home(user(User),filePath(Home)).
  user(_,_,userID(User),_,_,homeDirectory(Home),_).

relevantRule(entitlements(Ent),extensions(Ext),home(Home),profile(Profile),operation(Op),subject(Subject),decision(Decision),filters(Filters)):-
  profileRule(profile(Profile),decision(Decision),operation(Op),filters(Filters)),
  satisfyFilters(filters(Filters),entitlements(Ent),extensions(Ext),home(Home),subject(Subject)).

%RECURSION FOR SATISFYING ALL FILTERS
satisfyFilters(filters([]),entitlements(Ent),extensions(Ext),home(Home),subject(Subject)).

satisfyFilters(filters([Head|Tail]),entitlements(Ent),extensions(Ext),home(Home),subject(Subject)):-
  satisfyFilters(filters(Head),entitlements(Ent),extensions(Ext),home(Home),subject(Subject)),
  satisfyFilters(filters(Tail),entitlements(Ent),extensions(Ext),home(Home),subject(Subject)).

%EXTENSIONS FILE TYPE FILTER
satisfyFilters(filters(extension(ExtClass)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))):-
  member(extension(class(ExtClass),type("file"),value(ExtValue)),Ext),
  satisfyFilters(filters(subpath(ExtValue)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))).


%EXTENSIONS MACH TYPE FILTER
satisfyFilters(filters(extension(ExtClass)),entitlements(Ent),extensions(Ext),home(Home),subject(machService(MachName))):-
  %the extension value must be literally the same as the name of the mach service in question
  member(extension(class(ExtClass),type("mach"),value(MachName)),Ext).

%ENTITLEMENTS FILTER
%the required sandbox extension must be among those possessed by the process.
satisfyFilters(filters(require-entitlement(Key,ValueList)),entitlements(Ent),extensions(Ext),home(Home),subject(Subject)):-
  %get the entitlement from the filter to match the format in our facts
  (
    %value list could be empty or could contain a single string. I haven't seen any other configurations in SBPL
    %however, there are more complex entitlements, so we should we should keep in mind that this might be oversimplified.
    (ValueList = [],Value = bool("true"));
    (ValueList = [entitlement-value(ValueString)],Value = string(ValueString))
  ),
  member(entitlement(key(Key),value(Value)),Ent).

%LITERALS FILTER
%since the filepath of the subject and the literal must match exactly, this should be sufficient.
satisfyFilters(filters(literal(Literal)),entitlements(Ent),extensions(Ext),home(Home),subject(file(Literal))).

%REGEX FILTER
satisfyFilters(filters(regex(Regex)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))):-
  (
    (var(SubjectString))
    ;
    (nonvar(SubjectString),SubjectString =~ Regex)
  ).

%SUBPATH FILTER
satisfyFilters(filters(subpath(Subpath)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))):-
  %There is probably a simpler solution, but I just reused this code from sandscout.
  (
    (var(SubjectString))
    ;
    (nonvar(SubjectString),stringSubPath(Subpath,SubjectString))
  ).
  %stringSubPath(Subpath,SubjectString).

%PREFIX FILTER
%satisfyFilters(filters(prefix(variable("HOME"),path(PostPath))),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))):-
%  %since the filepath of the subject and the literal must match exactly, this should be sufficient.
%  string_concat(Home, PostPath, SubPathString),
%  satisfyFilters(filters(subpath(SubPathString)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))).

satisfyFilters(filters(literal-prefix(variable(Var),path(PostPath))),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))):-
  %since the filepath of the subject and the literal must match exactly, this should be sufficient.
  (Var="HOME";Var="FRONT_USER_HOME"),
  string_concat(Home, PostPath, ResultString),
  satisfyFilters(filters(literal(ResultString)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))).

satisfyFilters(filters(subpath-prefix(variable(Var),path(PostPath))),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))):-
  %since the filepath of the subject and the literal must match exactly, this should be sufficient.
  (Var="HOME";Var="FRONT_USER_HOME"),
  string_concat(Home, PostPath, ResultString),
  satisfyFilters(filters(subpath(ResultString)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))).

satisfyFilters(filters(regex-prefix(variable(Var),path(PostPath))),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))):-
  %since the filepath of the subject and the literal must match exactly, this should be sufficient.
  (Var="HOME";Var="FRONT_USER_HOME"),
  string_concat(Home, PostPath, ResultString),
  satisfyFilters(filters(regex(ResultString)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))).
 
%VNODE FILTER
satisfyFilters(filters(vnode-type(Vnode)),entitlements(Ent),extensions(Ext),home(Home),subject(file(SubjectString))):-
  %since the filepath of the subject and the literal must match exactly, this should be sufficient.
  vnodeType(file(SubjectString),type(Vnode)).

satisfyFilters(filters(require-not(ReqNotFilter)),entitlements(Ent),extensions(Ext),home(Home),subject(Subject)):-
  %this should only be satisfied if the satisfyFilters goal cannot be proven.
  %I need to make sure it is not satisfied by any single elements in the list that happen to not match.
  \+ (satisfyFilters(filters(ReqNotFilter),entitlements(Ent),extensions(Ext),home(Home),subject(Subject))).

%MACH SERVICE FILTERS
satisfyFilters(filters(global-name(MachName)),entitlements(Ent),extensions(Ext),home(Home),subject(machService(MachName))).
satisfyFilters(filters(local-name(MachName)),entitlements(Ent),extensions(Ext),home(Home),subject(machService(MachName))).
satisfyFilters(filters(global-name-regex(Regex)),entitlements(Ent),extensions(Ext),home(Home),subject(machService(SubjectString))):-
  (
    (var(SubjectString))
    ;
    (nonvar(SubjectString),SubjectString =~ Regex)
  ).
  %SubjectString =~ Regex.
satisfyFilters(filters(local-name-regex(Regex)),entitlements(Ent),extensions(Ext),home(Home),subject(machService(SubjectString))):-
  (
    (var(SubjectString))
    ;
    (nonvar(SubjectString),SubjectString =~ Regex)
  ).
  %SubjectString =~ Regex.
 
  
stringSubPath(SubPathString,FilePathString):-
  atom_codes(SubPathString,SBList),
  atom_codes(FilePathString,FPList),
  spath(SBList,FPList),!.

spath([],_).

spath([SPHead|SPTail],[FPHead|FPTail]):-
  SPHead = FPHead,
  spath(SPTail,FPTail).

%these are not necessarily abstraction supporting rules, but they are good example queries, and we might reference their results in the paper.
%these are good for determining which privileges a sandboxed process could grant itself if under full control of the attacker.
self_grantable_extensions:-
  profileRule(profile(Profile),decision("allow"),operation(Op),filters(Filters)),member(extension-class(Ext),Filters),profileRule(profile(Profile),decision("allow"),operation(Op2),filters(Filters2)),member(extension(Ext),Filters2),
  write("Profile: "),writeln(Profile),
  write("Extension: "),writeln(Ext),
  write("Operation1: "),writeln(Op),
  write("Filters1: "),writeln(Filters),
  write("Operation2: "),writeln(Op2),
  write("Filters2: "),writeln(Filters2),
  writeln(""),
  fail.

self_grantable_unrestricted_extensions:-
  profileRule(profile(Profile),decision("allow"),operation(Op),filters([extension-class(Ext)])),profileRule(profile(Profile),decision("allow"),operation(Op2),filters(Filters2)),member(extension(Ext),Filters2),
  write("Profile: "),writeln(Profile),
  write("Extension: "),writeln(Ext),
  write("Operation1: "),writeln(Op),
  write("Operation2: "),writeln(Op2),
  write("Filters: "),writeln(Filters2),
  writeln(""),
  fail.

% Check if process is allowed by sandbox profile to access subject.
sandboxAllow(process(Process),Subject,operation(Op)):-
  getAttributes(process(Process),entitlements(Ent),extensions(Ext),user(User),home(Home),profile(Profile)),
  relevantRule(entitlements(Ent),extensions(Ext),home(Home),profile(Profile),operation(Op),subject(Subject),decision("allow"),filters(Filters)).
