cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c  ring_libui.c -I "..\..\extensions\libdepwin\libuishared_x64" -I"..\..\language\include"
link  ring_libui.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libuishared_x64\libui.lib User32.lib kernel32.lib gdi32.lib uxtheme.lib msimg32.lib comdlg32.lib d2d1.lib dwrite.lib comctl32.lib ole32.lib oleaut32.lib oleacc.lib windowscodecs.lib /DLL /OUT:..\..\bin\ring_libui.dll 

del ring_libui.obj
endlocal


