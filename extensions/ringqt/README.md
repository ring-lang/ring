RingQt Extension
================

The folder "Classes" contains configuration files that define each Qt class.

The folder "Events" contains ring files that define each Qt class signals and slots.

The folder "Cpp" contains the generated code (Don't modify it directly) by the code generator.

The folder "Docs" contains scripts that generate the documentation of this extension.

How to study this extension
===========================

(1) Start by looking at the classes/qt.cf file.

(2) Then look at events/qtevents.ring 

How to build this extension using Qt 5.15.0
===========================================

(1) Run the code generator : gencode_nobluetooth.bat

(2) Build the extension : buildvc_nobluetooth.bat

Runtime Files
=============

The ring/bin folder must contains the Qt runtime files

To copy Qt runtime files to ring/bin folder use the next batch files

File: ring/extensions/ringqt/binupdate/installqt515.bat (For Qt 5.15.0)