cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_libcurl.c -I"..\..\libdepwin\libcurl\include" -I"..\..\include"
link /DEBUG ring_libcurl.obj  ..\..\lib\ring.lib ..\..\libdepwin\libcurl\lib\libcurl.lib /DLL /OUT:..\..\bin\ring_libcurl.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_libcurl.obj