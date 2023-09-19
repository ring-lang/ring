cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /c /DEBUG ring_libsdl.c -I"..\..\extensions\libdepwin\libsdl\sdl2_vc\include" -I"..\..\extensions\libdepwin\libsdl\sdl2_image\include" -I"..\..\extensions\libdepwin\libsdl\sdl2_ttf\include" -I"..\..\extensions\libdepwin\libsdl\sdl2_mixer\include" -I"..\..\extensions\libdepwin\libsdl\sdl2_net\include" -I"sdl2_gfx" -I"..\..\language\include"
link /DEBUG ring_libsdl.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\libsdl\sdl2_vc\lib\x64\sdl2.lib ..\..\extensions\libdepwin\libsdl\sdl2_image\lib\x64\sdl2_image.lib ..\..\extensions\libdepwin\libsdl\sdl2_ttf\lib\x64\sdl2_ttf.lib ..\..\extensions\libdepwin\libsdl\sdl2_mixer\lib\x64\sdl2_mixer.lib ..\..\extensions\libdepwin\libsdl\sdl2_net\lib\x64\sdl2_net.lib ..\..\extensions\libdepwin\libsdl\sdl2_vc\lib\x64\sdl2main.lib /DLL /OUT:..\..\bin\ring_sdl.dll /NODEFAULTLIB:msvcrt.lib
del ring_libsdl.obj
endlocal
