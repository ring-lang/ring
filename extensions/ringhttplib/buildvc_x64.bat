cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /EHsc /c ring_httplib.cpp -I"..\..\language\include"
link ring_httplib.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_httplib.dll 
del ring_httplib.obj
endlocal
