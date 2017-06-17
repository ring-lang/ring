cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_internet.c -I"..\..\libdepwin\libcurl\include" -I"..\..\include"
link /DEBUG ring_internet.obj  ..\..\lib\ring.lib ..\..\libdepwin\libcurl\lib\libcurl.lib /DLL /OUT:..\..\bin\ring_internet.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_internet.obj