cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_libsdl.c -I"..\..\libdepwin\sdl2vc\include" -I"..\..\libdepwin\sdl2_image\include" -I"..\..\libdepwin\sdl2_ttf\include" -I"..\..\libdepwin\sdl2_mixer\include" -I"..\..\include"
link /DEBUG ring_libsdl.obj  ..\..\lib\ring.lib ..\..\libdepwin\sdl2vc\lib\x86\sdl2.lib ..\..\libdepwin\sdl2_image\lib\x86\sdl2_image.lib ..\..\libdepwin\sdl2_ttf\lib\x86\sdl2_ttf.lib ..\..\libdepwin\sdl2_mixer\lib\x86\sdl_mixer.lib ..\..\libdepwin\sdl2vc\lib\x86\sdl2main.lib /DLL /OUT:..\..\bin\ring_sdl.dll /SUBSYSTEM:WINDOWS,"5.01" /NODEFAULTLIB:msvcrt.lib
del ring_libsdl.obj
copy libsdl.ring ..\..\bin
copy sdl.rh ..\..\bin
