cls
setlocal enableextensions enabledelayedexpansion
call ../../language/build/locatevc.bat auto %1
cl /c %ringcflags% ring_murmurhash.c libmurmurhash/MurmurHash1.c ^
    libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c ^
     -I"../../language/include" -I"libmurmurhash/"
link %ringldflags% *.obj ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_murmurhash.dll /SUBSYSTEM:CONSOLE,"5.01" 
del *.obj
endlocal
