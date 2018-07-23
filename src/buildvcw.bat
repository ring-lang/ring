echo off
call locatevc.bat

cls
rem  /DEBUG /Z7  
cl /c /Ox ringw.c  ^
ring_string.c ring_list.c ring_item.c ring_items.c ring_hashtable.c ring_state.c ring_scanner.c ring_parser.c ring_hashlib.c ring_vmgc.c ^
ring_stmt.c ring_expr.c ring_codegen.c ring_vm.c ring_vmexpr.c ring_vmvars.c ^
ring_vmlists.c ring_vmfuncs.c ring_api.c ring_vmoop.c ring_vmcui.c ^
ring_vmtrycatch.c ring_vmstrindex.c ring_vmjump.c ring_vmduprange.c ^
ring_vmperformance.c ring_vmexit.c ring_vmstackvars.c ring_vmstate.c ring_vmmath.c ring_vmfile.c ring_vmos.c ring_vmlistfuncs.c ring_vmrefmeta.c ^
ring_ext.c ring_vmdll.c ring_objfile.c -I"..\include"  

link /DLL /OUT:..\lib\ring.dll /SUBSYSTEM:CONSOLE,"5.01"  ring_string.obj ^
ring_list.obj ring_item.obj ring_items.obj ring_hashtable.obj ring_state.obj ring_scanner.obj ring_parser.obj ring_hashlib.obj ring_vmgc.obj ^
ring_stmt.obj ring_expr.obj ring_codegen.obj ring_vm.obj ring_vmexpr.obj ring_vmvars.obj ^
ring_vmlists.obj ring_vmfuncs.obj ring_api.obj ring_vmoop.obj ring_vmcui.obj ^
ring_vmtrycatch.obj ring_vmstrindex.obj ring_vmjump.obj ring_vmduprange.obj ^
ring_vmperformance.obj ring_vmexit.obj ring_vmstackvars.obj ring_vmstate.obj ring_vmmath.obj ring_vmfile.obj ring_vmos.obj ring_vmlistfuncs.obj ring_vmrefmeta.obj ^
ring_ext.obj ring_vmdll.obj ring_objfile.obj

copy ..\lib\ring.dll ..\bin\
rem  /DEBUG /Z7  
cl ringw.c ..\lib\ring.lib -I"..\include"  advapi32.lib shell32.lib /link /SUBSYSTEM:WINDOWS,"5.01" /OUT:..\bin\ringw.exe

del *.obj

