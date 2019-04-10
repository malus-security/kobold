# Executive Summary

This report represents the high level status of the Kobold paper with a planned submission for Fall Usenix 2019.
A variant of the Kobold paper will also be used in Luke's dissertation with a similar deadline of mid November.
Luke can update this page after significant updates or upon request.

## Conference Details
- *Deadline:* Thursday, November 15, 2018, 5:00 pm PST
- *Page Limit:* 13 pages not counting references and appendix
- *Format:* New Usenix format for 2019

## Experiment Status
Previously, we had a disorganized code base and poorly logged experiments.
It was difficult to determine which iOS version each data file originated from, and which scripts or data were obsolete.

Now we have a [documented][reorg_repo] and repeatable process for running kobold on arbitrary versions of iOS.
The process has been followed for iOS 11.1.2 generating about 1000 additional invocations to analyze.
In addition to running all experiments on the same version, the latest results also use entitlements when determining sandbox accessible mach-ports.
Several bugs were fixed during this process.
None of these updates should affect the integrity of our previous findings.
The following subsections will discuss current issues we should solve or wishlist before submission.

### Analysis of new invocations and public entitlements
We need to repeat the dynamic tests with the latest invocation code.
I should be able to do these experiments on Nov. 3rd without much trouble.
There are now too many invocations to process without running out of memory on the iOS device.
We can split the invocations across two apps to solve this problem.
Luke plans to also run these invocations with all public entitlements enabled.

### Unreversed Sandbox Filters for iOS 11
There are 12 sandbox filters in iOS 11 that SandBlaster cannot reverse engineer.
Unfortunately many of these filters are related to mach-lookup rules and fixing them is non-trivial.
Luke recommends we write around this issue in the paper and treat it as a reasonable limitation.

### (Automated / Grey Box) Debugger
Luke has constructed proof of concept IDA scripts and lldb instrumentation, but estimates that at least one week of work remains.
The refined kobold experiment process solves some of the issues blocking progress on this feature.
Luke thinks we should write a draft of the paper without this feature and return to it if time remains after writing.

### Testing Semi-Private Entitlements
Costin and Razvan will need to report on these experiments.
They have created an infrastructure for the experiments.
However, they have not yet detected significant differences when running with and without entitlements.
They need to repeat their experiments after using the refined Kobold experiment process.

### Using valid variable initializations for some ata types.
Luke or Costin could build a somewhat systematic approach for variable initialization for a small subset of data types (e.g., dictionaries, file handles).
This feature would remove some of the manual steps used to find certain vulnerabilities making the paper slightly more technical.
We would need to add a table to the paper listing the data types we tested and the initialization values for each.

## Paper Status
- The tables in the paper need to be updated with the latest results.
- The format needs to be updated for Usenix 2019
- Limitations need to be updated (add sandbox issue, remove adhoc mix of iOS versions)
- Disclosure process and Apple's responses should be added

## Apple Disclosure Status
Jordan has confirmed all vulnerabilities on iOS 12 and disclosed proof of concept applications to Apple.
He even isolated a subset of 12 invocations that can be used for the entitlement check bypass issue.
We still need to disclose our findings related to daemon crashes.
All of the relevant crash logs have been archived and Jordan will send them as well as relevant PoC apps soon.

Apple has been much more responsive for Kobold than they were for iOracle.
Some of the issues were categorized as non-security issues (e.g., disable text replacement) and others are being investigated by the security team.
Apple is very interested in our publication date and wants to review a copy of the paper.
I would like to send them a watermarked draft after our submission.
We can address their feedback in the camera ready draft or a later submission.

## Luke's Dissertation Status
Luke has addressed the formatting errors in his dissertation and updated the iOracle chapter so that it represents the published (AsiaCCS) version of the paper.
Luke would like to submit his dissertation by Nov. 11 or earlier due to potential delays in the grad department review process.

[reorg_repo]:https://github.com/malus-security/iOracle/tree/master/reorg_kobold
