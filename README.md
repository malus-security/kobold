# Kobold

Kobold is a framework to study NSXPC-based system services using a combination of static and dynamic analysis. Using Kobold, we discovered multiple NSXPC services with confused deputy vulnerabilities and daemon crashes. Our findings include the ability to activate the microphone, disable access to all websites, and leak private data stored in iOS File Providers.

The [Kobold paper](https://www.computer.org/csdl/proceedings-article/sp/2020/349700a399/1j2LfJ3e3ra) (`Kobold: Evaluating Decentralized Access Control for Remote NSXPC Methods on iOS`), presented at IEEE S&P 2020, details the architecture and implementation of Kobold and our findings.

Kobold is open source software released under the 3-clause BSD license.

Authors:
  * Luke Deshotels, North Carolina State University, Samsung Research America
  * Costin Carabaș, University POLITEHNICA of Bucharest
  * Jordan Beichler, North Carolina State University
  * Răzvan Deaconescu, University POLITEHNICA of Bucharest
  * William Enck, North Carolina State University
