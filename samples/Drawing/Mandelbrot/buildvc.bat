cls
call ..\..\..\language\build\locatevc.bat          
cl /c %ringcflags% mylibMandel.c -I"..\..\..\language\include"
link %ringldflags% mylibMandel.obj ..\..\..\lib\ring.lib /DLL /OUT:mylibMandel.dll /SUBSYSTEM:CONSOLE,"5.01"
del mylibMandel.obj