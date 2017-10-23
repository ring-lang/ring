cls
call ../../src/locatevc.bat
cl /c /DEBUG ring_vmopenssl.c -I"..\..\include" -I"..\..\libdepwin\OPENSSL\include"
link /DEBUG ring_vmopenssl.obj  ..\..\lib\ring.lib ..\..\libdepwin\OpenSSL\lib\libeay32.lib /DLL /OUT:..\..\bin\ring_openssl.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_vmopenssl.obj