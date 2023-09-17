cls
setlocal enableextensions enabledelayedexpansion
call ../../language/src/locatevc.bat x64
cl /c /DEBUG ring_vmopenssl.c -I"..\..\language\include" -I"..\..\extensions\libdepwin\OPENSSL_x64\include"
link /DEBUG ring_vmopenssl.obj  ..\..\lib\ring.lib ..\..\extensions\libdepwin\OpenSSL_x64\lib\libcrypto.lib Advapi32.lib User32.lib Crypt32.lib Ws2_32.lib /DLL /OUT:..\..\bin\ring_openssl.dll 
del ring_vmopenssl.obj
endlocal