echo off
rem call vc.bat
call "C:\Program Files\Microsoft Visual Studio 12.0\VC\vcvarsall.bat" x86

cls
rem /DEBUG
cl  /c /Ox  /Z7 ring.c  ^
ring_string.c ring_list.c ring_item.c ring_items.c ring_hashtable.c ring_state.c ring_scanner.c ring_parser.c ring_hashlib.c ring_vmgc.c ^
ring_stmt.c ring_expr.c ring_codegen.c ring_vm.c ring_vmexpr.c ring_vmvars.c ^
ring_vmlists.c ring_vmfuncs.c ring_api.c ring_vmoop.c ring_vmcui.c ^
ring_vmtrycatch.c ring_vmstrindex.c ring_vmjump.c ring_vmduprange.c ^
ring_vmperformance.c ring_vmexit.c ring_vmstackvars.c ring_vmstate.c ring_vmmath.c ring_vmfile.c ring_vmos.c ring_vmlistfuncs.c ring_vmrefmeta.c ^
..\extensions\ringodbc\ring_vmodbc.c ..\extensions\ringmysql\ring_vmmysql.c ..\extensions\ringopenssl\ring_vmopenssl.c ..\extensions\ringcurl\ring_vmcurl.c ring_ext.c ring_vmdll.c ..\extensions\ringsqlite\ring_vmsqlite.c ..\extensions\ringsqlite\sqlite3.c ring_objfile.c -I"..\include" ^
 -I"..\libdepwin\libcurl\include" -I"..\libdepwin\OPENSSL\include" -I"..\libdepwin\MySQL\include" 

link /DLL /DEBUG /OUT:..\lib\ring.dll /SUBSYSTEM:CONSOLE,"5.01"  ring_string.obj ^
ring_list.obj ring_item.obj ring_items.obj ring_hashtable.obj ring_state.obj ring_scanner.obj ring_parser.obj ring_hashlib.obj ring_vmgc.obj ^
ring_stmt.obj ring_expr.obj ring_codegen.obj ring_vm.obj ring_vmexpr.obj ring_vmvars.obj ^
ring_vmlists.obj ring_vmfuncs.obj ring_api.obj ring_vmoop.obj ring_vmcui.obj ^
ring_vmtrycatch.obj ring_vmstrindex.obj ring_vmjump.obj ring_vmduprange.obj ^
ring_vmperformance.obj ring_vmexit.obj ring_vmstackvars.obj ring_vmstate.obj ring_vmmath.obj ring_vmfile.obj ring_vmos.obj ring_vmlistfuncs.obj ring_vmrefmeta.obj ^
ring_vmodbc.obj ring_vmmysql.obj ring_vmopenssl.obj ring_vmcurl.obj ring_ext.obj ring_vmdll.obj ring_vmsqlite.obj sqlite3.obj ring_objfile.obj ..\libdepwin\libcurl\lib\libcurl.lib "..\libdepwin\MySQL\lib\libmysql.lib" ..\libdepwin\OpenSSL\lib\libeay32.lib odbc32.lib

copy ..\lib\ring.dll ..\bin\

cl /DEBUG ring.c ..\lib\ring.lib -I"..\include" /link /SUBSYSTEM:CONSOLE,"5.01" /OUT:..\bin\ring.exe 

del *.obj

