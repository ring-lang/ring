cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat
cl /c  ring_pdfgen.c lib/pdfgen.c -I"..\..\language\include" -I"..\libdepwin\pdfgen\src"
link ring_pdfgen.obj  ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_pdfgen.dll 
del ring_pdfgen.obj
endlocal
