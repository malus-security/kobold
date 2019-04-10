import re
import sys

"""	Replace ViewController.m file from below and redirect it to a new
	ViewController.m file that will be fuzzed
"""

singleton=True
with open('/Users/costincarabas/facultate/doctorat/research/iOracle/kobold/my_experiments/luke/ViewController_first_half.m', 'rt') as sourceFile:
  for line in sourceFile:
    intVar = re.search('^(unsigned )?int var_.*_.*;$', line)
    longVar = re.search('^(unsigned )?(long )?long var_.*_.*;$', line)
    doubleVar = re.search('^(unsigned )?double var_.*_.*;$', line)
    stringVar = re.search('^NSString \* var_.*_.*;$', line)
    arrayVar = re.search('^NSArray \* var_.*_.*;$', line)
    boolVar = re.search('^_Bool var_.*_.*;$', line)
    errorVar = re.search('^NSError \* var_.*_.*;$', line)
    dataVar = re.search('^NSData \* var_.*_.*;$', line)
    dictVar = re.search('^NSDictionary \* var_.*_.*;$', line)
    nsUUIDVar = re.search('^NSUUID \* var_.*_.*;$', line)
    nsXPCConnectionVar = re.search('^NSXPCConnection \* var_.*_.*;$', line)
    nsURLVar = re.search('^NSURL \* var_.*_.*;$', line)
    nsNumberVar = re.search('^NSNumber \* var_.*_.*;$', line)
    nsSetVar = re.search('^NSSet \* var_.*_.*;$', line)
    nsFileHandle = re.search('^NSFileHandle \* var_.*_.*;$', line)



# [[NSMutableOrderedSet alloc] initWithArray: @[@"a", @"b", @"c", @"d", @42]]
    if intVar:
      print "%s = 1;" % intVar.group()[:-1]
    elif longVar:
      print "%s = 1;" % longVar.group()[:-1]
    elif doubleVar:
      print "%s = 1;" % doubleVar.group()[:-1]
    elif stringVar:
      print '%s = @"Simple Var";' % stringVar.group()[:-1]
    elif arrayVar:
      print '%s = [NSArray arrayWithObjects:@"key1",@"key2",@"key3"];' % arrayVar.group()[:-1]
    elif boolVar:
      print '%s = "True";' % boolVar.group()[:-1]
    elif errorVar:
      print '%s = nil;' % errorVar.group()[:-1]
    elif dataVar:
      if singleton:
        print 'void * bytes = malloc(1024);'
        singleton=False
      else:
        print 'bytes = malloc(1024);'
      print '%s = [NSData dataWithBytes:bytes length:1024];' % dataVar.group()[:-1]
      print 'free(bytes);'
    elif dictVar:
      print '%s = @{@"key1" : @"value1", @"key2" : @"value2", @"key3" : @"value3"};' % dictVar.group()[:-1]
    elif nsUUIDVar:
      print '%s = [[NSUUID alloc]initWithUUIDString:@"20B0DDE7-6087-4607-842A-E97C72E4D522"];' % nsUUIDVar.group()[:-1]
    elif nsXPCConnectionVar:
      print '%s = [[NSXPCConnection alloc] initWithMachServiceName:@"com.apple.locationd.spi"options:0];' % nsXPCConnectionVar.group()[:-1]
    elif nsURLVar:
      print '%s = [NSURL URLWithString:@"tel://1234567890x101"];' % nsURLVar.group()[:-1]
    elif nsNumberVar:
      print '%s = @42LL;' % nsNumberVar.group()[:-1]
    elif nsSetVar:
      print '%s = [[NSSet alloc] initWithArray: @[@"a", @"b", @"c", @"d", @42]];' % nsSetVar.group()[:-1]
    elif nsFileHandle:
      print '%s = [NSFileHandle fileHandleForWritingAtPath: filePath];\n  NSLog(@"filePath: %%@", filePath);' % nsFileHandle.group()[:-1]
    else:
      sys.stdout.write(line)
