cls
call ..\..\..\language\build\locatevc.bat x64         
cl /c %ringcflags% mylibMandel.c -I"..\..\..\language\include"
link %ringldflags% mylibMandel.obj ..\..\..\lib\ring.lib /DLL /OUT:mylibMandel.dll
del mylibMandel.obj
