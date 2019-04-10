# Kobold Reorganization
This directory represents a reorganization of the kobold project which has expanded to include many obsolete scripts.
It should only include scripts the scripts we would include if we were to open source the project.
Experimental efforts should be run in directories labelled "experiment\_" and moved to proper directories when the code is stable.

I am assuming this process is being performed on a macOS device. Many steps can be replicated in Linux, but eventually you will need to run Xcode, which definitely requires macOS.

## Extract data for iOS firmware version.
Use iExtractor to extract the file system, sandbox profiles, etc. from the iOS version you want to investigate.
Take the output results of iExtractor and store them in `kobold_reorg/data_from_iextractor/` by creating a symbolic link.
For example:

`ln -sfn iExtractor_Results/out/iPhone_4.0_64bit_11.1.2_15B202 kobold_reorg/data_from_iextractor/`

## Compile SBPL Sandbox Profiles into Prolog Facts.
Use SandScout to compile the sandbox profiles produced by iExtractor into Prolog facts that can be used by iOracle.
Unfortunately our SandScout automation scripts make a lot of assumptions about directories, so we need to give exact paths. 
For Example:

```
gitHome=`git rev-parse --show-toplevel`
cd $gitHome/sandscout
myiOSData=$gitHome/reorg_kobold/data_from_iextractor/iPhone_4.0_64bit_11.1.2_15B202
./processAllProfiles.sh $myiOSData/reversed_profiles $myiOSData/individual_profiles_prolog $myiOSData/consolidated_sb_facts.pl
```

TODO: The cascades server is currently down, so I will need to wait before transplanting some other sandbox profiles. I can work on extracting mach ports from caches in the meantime.

Profiles may have issues. Run the command below to fix profiles:

```
for i in *.sb; do sed -i '/([0-9a-f][0-9a-f] /d' "$i"; done
```

## Unpack the filesystem extracted with iExtractor
Make a directory to store the unpacked file system.
Then unpack the tar file that iExtractor produced.

```
cd data_from_iextractor/iPhone_4.0_64bit_11.1.2_15B202/
mkdir filesystem
tar -xzf fs.tar.gz -C filesystem/
```

## Extract mach port to executable mapping from cached configuration files.
Copy the cached config files into a directory for processing:

```
cd data_from_iextractor/iPhone_4.0_64bit_11.1.2_15B202/
mkdir machport_to_exec_mapping_dir
ln filesystem/System/Library/Caches/com.apple.xpcd/xpcd_cache.dylib ./machport_to_exec_mapping_dir/
```

Use jtool to list the libraries in the xpcd\_cache.dylib file (note the .dylib extension).
There should be a section named `__TEXT.__xpcd_cache`, which we can extract with jtool.
Note that jtool will extract the section into whatever your current directory is.
The resulting file is actually a plist, which we need to convert into human readable format with plutil.
The example uses the temporary symlink mapping\_dir to keep our filepaths managable.

```
cd reorg_kobold/external_tools/jtool
ln -s ../../data_from_iextractor/iPhone_4.0_64bit_11.1.2_15B202/machport_to_exec_mapping_dir mapping_dir
./jtool -l mapping_dir/xpcd_cache.dylib
./jtool -e __TEXT.__xpcd_cache mapping_dir/xpcd_cache.dylib
mv ./xpcd_cache.dylib.__TEXT.__xpcd_cache mapping_dir/xpcd_cache.plist
plutil -convert xml1 mapping_dir/xpcd_cache.plist
rm mapping_dir
```

Next we want to extract the machport to executable mapping from the now human readable (xml format) plist.
We use `lazy_cache_plist_parser.py` to build a csv mapping of ports (or service names) to executables based on the plist.

```
cd reorg_kobold/kobold_scripts
ln -s ../data_from_iextractor/iPhone_4.0_64bit_11.1.2_15B202/machport_to_exec_mapping_dir mapping_dir
./lazy_cache_plist_parser.py mapping_dir/xpcd_cache.plist | sort | uniq > data/port_to_exec_mapping.csv
```

## Identify mach-o executables likely to contain NSXPC methods
Set up a symlink to the iOS filesystem for convenience.
Use our script to identify the file type for every file in the iOS file system.
Note: this process could take about an hour.
Then grep the results for files of the mach-o executable type.
Then the script should search each mach-o executable file for the symbol *NSXPC*.

```
ln -sfn ../data_from_iextractor/iPhone_4.0_64bit_11.1.2_15B202/filesystem/ .
./fileTypeExtractor.sh filesystem/ > ./data/file_types.out
grep 'Mach-O.*executable' ./data/file_types.out | sed 's;^.*filePath("//;;' | sed 's;")).$;;' > ./data/executable_list.out
./symbolExtractor.sh filesystem < data/executable_list.out > nsxpc_executables_list.out
```

## Use classdump to extract NSXPC methods for executables likely to contain them.
class-dump can list the methods implemented in an executable, but we only want methods that are for NSXPC services.
We use `class-dump_automater.sh` to apply class-dump and parse-protocol-names.py to executables.
The resulting file will be a pickled dictionary that maps executables to the NSXPC methods they implement.
```
./class-dump_automater.sh ./filesystem < ./data/nsxpc_executables_list.out
mv ./protocols.pk ./data/
```

## List the ports accessible to a sandboxed third party application.

TODO: Can not do this for iOS 11.1.2 until Razvan updates SandBlaster.
Could use transplanted data for iOS 11 temporarily or just make a note in the paper.

## Generate invocations to run in iOS app

TODO: I really need to finish documenting the previous step first, but as a test run I can do this step in parallel.

Using the following files in the data directory, `map_potential_methods_to_mach-ports.py` can generate the code we want to run in the iOS app.
```
port_to_exec_mapping.csv
sandbox_accessible_services.txt
protocols.pk
```

The python script will automatically search the data/ directory for these files.
It will also generate an pickle dictionary output file at ./data/invocationDictionary.pk which is needed to make a header file.
Store the resulting objc invocations in a file called View Controller.m.
We will move this file into an Xcode project later.

```
python map_potential_methods_to_mach-ports.py > ./data/ViewController.m
```

## Create a header file for the iOS app

The script that creates a header for the app relies on the dictionary file output by `map_potential_methods_to_mach-ports.py`.
The Xcode iOS app is expecting a header file named `fake_header.h`.

```
python auto_generate_header.py > data/fake_header.h
```

## Build an Xcode iOS project and insert the header and viewcontroller files
Start a single view iOS app project in Xcode.
Xcode should create a directory for the project.
Copy the header and viewcontroller files created by Kobold into this directory.
Hint: There should be an almost empty `ViewController.m` file in the Xcode project directory by default.
```
data/ViewController.m some_xcode_project/some_xcode_project/ViewController.m
data/fake_header.h some_xcode_project/some_xcode_project/fake_header.h
```

## Edit NSXPC headers to allow direct invocation of NSXPC services
The following instructions are written by Jordan Beichler:
"""
In order to compile this application the following change must be made to a header file within Xcode. In the file "/Applications/Xcode.app/Contents/Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS12.0.sdk/System/Library/Frameworks/Foundation.framework/Headers/NSXPCConnection.h", all references to the tag IOS\_PROHIBITED should be removed. There should be 3 different references with the method declarations beginning with "initWith".
"""
