echo off
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64

cl /c /DEBUG /EHsc creg_registry.cpp ring_wincreg.cpp -I"..\..\language\include"

link /DEBUG creg_registry.obj advapi32.lib shlwapi.lib ring_wincreg.obj  ..\..\lib\ring.lib  /DLL /OUT:ring_wincreg.dll

mt.exe -manifest ring_wincreg.dll.manifest -outputresource:ring_wincreg.dll;2

copy ring_wincreg.dll ..\..\bin\ring_wincreg.dll

del *.obj
del ring_wincreg.ilk
del ring_wincreg.exp
del ring_wincreg.pdb
del ring_wincreg.dll
del ring_wincreg.lib

endlocal
