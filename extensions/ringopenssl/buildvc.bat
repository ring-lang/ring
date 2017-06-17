cls
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86
cl /c /DEBUG ring_vmopenssl.c -I"..\..\include" -I"..\..\libdepwin\OPENSSL\include"
link /DEBUG ring_vmopenssl.obj  ..\..\lib\ring.lib ..\..\libdepwin\OpenSSL\lib\libeay32.lib /DLL /OUT:..\..\bin\ring_openssl.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_vmopenssl.obj