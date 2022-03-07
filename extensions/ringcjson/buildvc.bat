cls
call ../../language/src/locatevc.bat
cl /c /DEBUG ring_cjson.c lib/cJSON.c lib/cJSON_Utils.c -I"..\..\language\include"
link /DEBUG ring_cjson.obj cJSON.obj cJSON_Utils.obj ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_cjson.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_cjson.obj
