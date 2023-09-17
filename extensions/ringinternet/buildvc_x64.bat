cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /c  ring_internet_x64.c -I"..\..\extensions\libdepwin\libcurl_x64\include" -I"..\..\language\include"
link ring_internet_x64.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libcurl_x64\lib\libcurl_a.lib Ws2_32.Lib Wldap32.Lib Crypt32.Lib  Advapi32.lib  User32.lib  Normaliz.lib /DLL /OUT:..\..\bin\ring_internet.dll  
del ring_internet.obj
endlocal
