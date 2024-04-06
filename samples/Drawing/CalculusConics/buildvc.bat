cls    

call ..\..\..\language\build\locatevc.bat    
cl /c /DEBUG mylibCalcTransform.c -I "..\..\..\language\include"
link  /DEBUG mylibCalcTransform.obj ..\..\..\lib\ring.lib /DLL /OUT:mylibCalcTransform.dll
del mylibCalcTransform.obj

