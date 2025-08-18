cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c %ringcflags% ring_vmopenssl.c -I"..\..\language\include" -I"..\..\extensions\libdepwin\OPENSSL\include"
link %ringldflags% ring_vmopenssl.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\OpenSSL\lib\libeay32.lib /DLL /OUT:..\..\bin\ring_openssl.dll /SUBSYSTEM:CONSOLE,"5.01" 
del ring_vmopenssl.obj
endlocal