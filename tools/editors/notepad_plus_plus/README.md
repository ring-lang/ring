Ring Syntax highlighter for Notepad++
=====================================

Author : Abdulrahman

URL : https://github.com/AbdelrahmanGIT/Ring_for_NotePad_plus_plus

Screenshot
===========

![Ring syntax highlighter in action](http://i.imgur.com/DqZyyXg.png)

Features
========

- Automatically activates on files with the `.ring` extension

- Folding for `if but else ok` statements and `{ }`

Instructions
============

1. Clone this repository or download `Ring.xml` in the `syntax` folder
2. Open Notepad++
3. Open the "Language" menu
4. Select "Define your language..."
5. Click "Import..."
6. select `Ring.xml`
7. Select "OK" on the "Import successful" dialog and close the "User Defined Language" dialog/panel
8. You may need to restart notepad++
9. Enjoy :)

Run integration
===============

1. Open notepad++ if it's not already opened
2. Open the "Run" menu
3. Choose `Run...`
4. On the run dialog Put this command (Change `RING_BIN_FOLDER` to point to ring folder): 
 
`cmd /K cd /D "RING_BIN_FOLDER" && runring.bat "$(FULL_CURRENT_PATH)""`

i.e if ring.exe is in c:\ring\bin\ my command would be:
`cmd /K cd /D "c:\ring\bin\" && runring.bat "$(FULL_CURRENT_PATH)"`
