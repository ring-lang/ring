cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /EHsc /c ring_httplib.cpp -I"..\..\language\include"
link ring_httplib.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_httplib.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_httplib.obj
endlocal
