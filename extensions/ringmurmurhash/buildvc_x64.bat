cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat x64
cl /c /DEBUG ring_murmurhash.c libmurmurhash/MurmurHash1.c ^
    libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c ^
     -I"../../language/include" -I"libmurmurhash/"
link /DEBUG *.obj ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_murmurhash.dll 
del *.obj
endlocal
