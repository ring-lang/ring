cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto x64
cl /c %ringcflags% ring_cjson.c lib/cJSON.c lib/cJSON_Utils.c -I"..\..\language\include"
link %ringldflags% ring_cjson.obj cJSON.obj cJSON_Utils.obj ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_cjson.dll 
del ring_cjson.obj
endlocal
