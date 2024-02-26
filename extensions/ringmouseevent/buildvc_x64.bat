cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c /DEBUG ringmouseevent.c -I"..\..\language\include"
link /DEBUG ringmouseevent.obj  ..\..\lib\ring.lib kernel32.lib user32.lib /DLL /OUT:ringmouseevent.dll  
del ringmouseevent.obj
endlocal
