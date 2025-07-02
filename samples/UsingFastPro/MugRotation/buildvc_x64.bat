cls    
call ..\..\..\language\build\locatevc.bat x64    
cl /c /DEBUG mylibCalcMug.c -I "..\..\..\language\include"
link /DEBUG mylibCalcMug.obj ..\..\..\lib\ring.lib /DLL /OUT:mylibCalcMug.dll
del mylibCalcMug.obj
pause