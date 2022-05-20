FOR  WINDOWS INSTALLATION

i suppose you have in C:\ring

download  this 
https://github.com/brechtsanders/winlibs_mingw/releases/download/11.2.0-13.0.0-9.0.0-ucrt-r2/winlibs-i686-posix-dwarf-gcc-11.2.0-mingw-w64ucrt-9.0.0-r2.zip 


This is runtime without installation. Unzip, within extracted
directory, move mingw32 directory to C\:mingw32, and then execute in
the DOS prompt

SET PATH=C:\mingw32\bin

This will set path to gcc so that you can compile 32 bit libraries/executables

Download: http://gnuwin32.sourceforge.net/packages/regex.htm

Developer files & Binaries

Unzip Developer files, move extracted directory to stringregexp
extension directory, rename regex-xxx to regex

Unzip Binaries files, copy regex2.dll to ring/bin folder!

Download: http://gnuwin32.sourceforge.net/packages/pcre.htm

Developer files & Binaries

Unzip Developer files, move extracted directory to stringregexp
extension directory, rename pcre-xxx to pcre

Unzip Binaries files, copy pcre3.dll to ring/bin folder!

Now compile extension

gcc -c -O2 -fpic stringregexp.c -I"../../language/include"
-I"regex/include" -I"pcre/include"

gcc -shared -o stringregexp.dll stringregexp.o -L../../lib -lring
-L"regex/lib" -lregex -L"pcre/lib" -lpcre

Enjoy!
