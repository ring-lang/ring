RingQt Extension
================

The folder "Classes" contains configuration files that define each Qt class.

The folder "Events" contains ring files that define each Qt class singals and slots.

The folder "Cpp" contains the generated code (Don't modify it directly) by the code generator.

The folder "Docs" contains scripts that generate the documentation of this extension.

How to study this extension
===========================

(1) Start by looking at the classes/qt.cf file.

(2) Then look at events/qtevents.ring 


How to build this extension
===========================

(1) Run the code generator (gencode.bat or gencode.sh)

(2) Build the extension (buildmingw32.bat or buildgcc.sh or buildclang.sh)


Note: gencode.bat & buildmingw32.bat (Tested using Qt 5.5.1)


How to build this extension using Qt 5.12.6
===========================================

(1) Run the code generator : gencodeqt512.bat

(2) Build the extension : buildqt512.bat


Project Files
=============

(1) ring_qt.pro  (Qt 5.5.1)

(2) ring_qt512.pro (Qt 5.12.6)

