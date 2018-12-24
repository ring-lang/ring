Ring Programming Language Tests (Old System)
============================================

=================
Folder Structure
=================

In this folder we have the scripts that are used to test the Ring Compiler and Virtual Machine

Scripts are inside the "scripts" folder

The output folder contains the correct/expected output from executing the scripts

=====================
How to run the tests?
=====================

To run tests just execute the file run_tests.bat

=====================
How to add new tests?
=====================

To add new script to tests:-

* Add the file to the scripts folder.
* Modify the scripts_list.bat to execute the file during testing.
* Run refresh_tests.bat to modify the correct/expected output.