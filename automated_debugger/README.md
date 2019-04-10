Debugging:
  I used the following two links to help set up debugging on a jailbroken iOS 10.1 device.
  https://kov4l3nko.github.io/blog/2016-04-27-debugging-ios-binaries-with-lldb/
  https://blog.securityevaluators.com/debugging-ios-applications-a-guide-to-debug-other-developers-apps-c041311498eb

My current test set of daemons is from iOS 10.1, but I can easily change this by modifying the version number in:
runBaseIDAAnalysisOnAllExecsWithSelectorString.sh
We will eventually need to run our scripts on iOS 11 or whatever version we use class-dump on to extract our nsxpc protocols.

