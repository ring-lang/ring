cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c /DEBUG ring_cjson.c lib/cJSON.c lib/cJSON_Utils.c -I"..\..\language\include"
link /DEBUG ring_cjson.obj cJSON.obj cJSON_Utils.obj ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_cjson.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_cjson.obj
endlocal
