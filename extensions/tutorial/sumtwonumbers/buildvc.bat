cls
call ../../../src/locatevc.bat
cl /c /DEBUG mylib.c -I"..\..\..\include"
link /DEBUG mylib.obj  ..\..\..\lib\ring.lib /DLL /OUT:mylib.dll /SUBSYSTEM:CONSOLE,"5.01" 
del mylib.obj