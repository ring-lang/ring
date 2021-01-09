echo off
call locatevc.bat

cls
rem  /DEBUG /Z7  
cl /c /O2 ringw.c  ^
ring_string.c ring_list.c ring_item.c ring_items.c ring_hashtable.c ring_general.c ring_state.c ring_scanner.c ring_parser.c ring_hashlib.c ring_vmgc.c ^
ring_stmt.c ring_expr.c ring_codegen.c ring_vm.c ring_vmexpr.c ring_vmvars.c ^
ring_vmlists.c ring_vmfuncs.c ring_api.c ring_vmoop.c ring_vmcui.c ^
ring_vmtrycatch.c ring_vmstrindex.c ring_vmjump.c ring_vmduprange.c ^
ring_vmperformance.c ring_vmexit.c ring_vmstackvars.c ring_vmstate.c ring_generallib_extension.c ring_math_extension.c ring_file_extension.c ring_os_extension.c ring_list_extension.c ring_refmeta_extension.c ^
ring_ext.c ring_dll_extension.c ring_objfile.c -I"..\include"  

link /DLL /OUT:..\..\lib\ring.dll /SUBSYSTEM:CONSOLE,"5.01"  ring_string.obj ^
ring_list.obj ring_item.obj ring_items.obj ring_hashtable.obj ring_general.obj ring_state.obj ring_scanner.obj ring_parser.obj ring_hashlib.obj ring_vmgc.obj ^
ring_stmt.obj ring_expr.obj ring_codegen.obj ring_vm.obj ring_vmexpr.obj ring_vmvars.obj ^
ring_vmlists.obj ring_vmfuncs.obj ring_api.obj ring_vmoop.obj ring_vmcui.obj ^
ring_vmtrycatch.obj ring_vmstrindex.obj ring_vmjump.obj ring_vmduprange.obj ^
ring_vmperformance.obj ring_vmexit.obj ring_vmstackvars.obj ring_vmstate.obj ring_generallib_extension.obj ring_math_extension.obj ring_file_extension.obj ring_os_extension.obj ring_list_extension.obj ring_refmeta_extension.obj ^
ring_ext.obj ring_dll_extension.obj ring_objfile.obj

copy ..\..\lib\ring.dll ..\..\bin\
rem  /DEBUG /Z7  
cl /O2 ringw.c ..\..\lib\ring.lib -I"..\include"  advapi32.lib shell32.lib /link /SUBSYSTEM:WINDOWS,"5.01" /OUT:..\..\bin\ringw.exe

del *.obj

