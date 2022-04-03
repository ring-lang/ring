echo off
setlocal enableextensions enabledelayedexpansion
call locatevc.bat %1 %2

cls
cl %ringcflags% ring.c  ^
ring_string.c ring_list.c ring_item.c ring_items.c ring_hashtable.c ring_general.c ring_state.c ring_scanner.c ring_parser.c ring_hashlib.c ring_vmgc.c ^
ring_stmt.c ring_expr.c ring_codegen.c ring_vm.c ring_vmexpr.c ring_vmvars.c ^
ring_vmlists.c ring_vmfuncs.c ring_api.c ring_vmoop.c ring_vmcui.c ^
ring_vmtrycatch.c ring_vmstrindex.c ring_vmjump.c ring_vmduprange.c ^
ring_vmperformance.c ring_vmexit.c ring_vmstackvars.c ring_vmstate.c ring_generallib_extension.c ring_math_extension.c ring_file_extension.c ring_os_extension.c ring_list_extension.c ring_refmeta_extension.c ^
ring_ext.c ring_dll_extension.c ring_objfile.c -I"..\include" /link /SUBSYSTEM:CONSOLE,"%ringsubsystem%" /OUT:..\..\bin\ring.exe 

del *.obj

endlocal
