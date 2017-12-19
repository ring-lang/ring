cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_libsdl.c -I"..\..\libdepwin\libsdl\sdl2_vc\include" -I"..\..\libdepwin\libsdl\sdl2_image\include" -I"..\..\libdepwin\libsdl\sdl2_ttf\include" -I"..\..\libdepwin\libsdl\sdl2_mixer\include" -I"..\..\libdepwin\libsdl\sdl2_net\include" -I"sdl2_gfx" -I"..\..\include"
link /DEBUG ring_libsdl.obj  ..\..\lib\ring.lib ..\..\libdepwin\libsdl\sdl2_vc\lib\x86\sdl2.lib ..\..\libdepwin\libsdl\sdl2_image\lib\x86\sdl2_image.lib ..\..\libdepwin\libsdl\sdl2_ttf\lib\x86\sdl2_ttf.lib ..\..\libdepwin\libsdl\sdl2_mixer\lib\x86\sdl2_mixer.lib ..\..\libdepwin\libsdl\sdl2_net\lib\x86\sdl2_net.lib ..\..\libdepwin\libsdl\sdl2_vc\lib\x86\sdl2main.lib /DLL /OUT:..\..\bin\ring_sdl.dll /SUBSYSTEM:WINDOWS,"5.01" /NODEFAULTLIB:msvcrt.lib
del ring_libsdl.obj