cls
call ../../language/src/locatevc.bat
cl /c /DEBUG ring_murmurhash.c libmurmurhash/MurmurHash1.c ^
    libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c ^
     -I"../../include" -I"libmurmurhash/"
link /DEBUG *.obj ..\..\lib\ring.lib /DLL /OUT:..\..\bin\ring_murmurhash.dll /SUBSYSTEM:CONSOLE,"5.01" 
del *.obj