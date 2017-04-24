Ring Syntax highlighter for notepad++
Author : Abdulrahman
URL : https://github.com/AbdelrahmanGIT/Ring_for_NotePad_plus_plus
--------------
This is a simple ring language syntax highlighter for notepad++
if you don't know what ring languge is refer to : http://ring-lang.net/

Screenshot
======
![Ring syntax highlighter in action](http://i.imgur.com/DqZyyXg.png)
Feauters
======
- Automatically activates on files with the `.ring` extension
- Folding for `if but else ok` statments and `{ }`


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
===
1. Open notepad++ if it's not already opend
2. Open the "Run" menu
3. Choose `Run...`
4. On the run dialog Put this command(Chnage `RING_BIN_FOLDER` to point to ring folder): 
 
`cmd /K cd /D "RING_BIN_FOLDER" && run.bat "$(FULL_CURRENT_PATH)""`

i.e if ring.exe is in c:\ring\bin\ my command would be:
`cmd /K cd /D "c:\ring\bin\" && run.bat "$(FULL_CURRENT_PATH)"`
