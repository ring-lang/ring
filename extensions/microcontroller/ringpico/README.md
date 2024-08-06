Ring Programming Language for Raspberry Pi Pico
===============================================

In this folder we have the RingPico extension for using Ring on Raspberry Pi Pico

This is a project folder that contains (Ring Compiler/VM, RingPico extension and Samples)

Install
=======

* Install Ring 1.21 (Required to compile the Ring program in the Building step)

* Install Pico-SDK from: https://github.com/raspberrypi/pico-setup-windows

* Update config.bat to point to the Pico-SDK folder on your computer

Programming
===========

* Samples exist in the (projects) folder
* You can create a sub folder for your project in the (projects) folder
* You can update the (main.ring) file to load your project

Building
========

* Just run the build.bat file

Deployment
==========

* Connect Raspberry Pi Pico to your computer while pressing on the BOOTSEL button.

* Keep pressing the BOOTSEL button until you see the File Explorer window.

* Run the deploy.bat file which will copy ringpico.uf2 to the device

Contributors
============

* Mahmoud Fayed
* Ahmad Fayed