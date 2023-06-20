cls
call ..\..\..\language\src\locatevc.bat          
cl /c /DEBUG mylibMandel.c -I"..\..\..\language\include"
link /DEBUG mylibMandel.obj ..\..\..\lib\ring.lib /DLL /OUT:mylibMandel.dll /SUBSYSTEM:CONSOLE,"5.01"
del mylibMandel.obj
pause
