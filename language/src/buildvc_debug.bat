echo off
setlocal enableextensions enabledelayedexpansion
call locatevc.bat %1 %2

cls 
 
cl /DEBUG /Z7 /c %ringcflags% ring.c  ^
rstring.c rlist.c ritem.c ritems.c rhtable.c general.c state.c scanner.c parser.c hashlib.c vmgc.c ^
stmt.c expr.c codegen.c vm.c vmerror.c vmeval.c vmthreads.c vmexpr.c vmvars.c ^
vmlists.c vmfuncs.c ringapi.c vmoop.c vmcui.c ^
vmtry.c vmstr.c vmjump.c vmrange.c ^
vmperf.c vmexit.c vmstack.c vmstate.c genlib_e.c math_e.c file_e.c os_e.c list_e.c meta_e.c ^
ext.c dll_e.c objfile.c -I"..\include" 
  

link %ringldflags% /DLL /OUT:..\..\lib\ring.dll /SUBSYSTEM:CONSOLE,"%ringsubsystem%"  rstring.obj ^
rlist.obj ritem.obj ritems.obj rhtable.obj general.obj state.obj scanner.obj parser.obj hashlib.obj vmgc.obj ^
stmt.obj expr.obj codegen.obj vm.obj vmerror.obj vmeval.obj vmthreads.obj vmexpr.obj vmvars.obj ^
vmlists.obj vmfuncs.obj ringapi.obj vmoop.obj vmcui.obj ^
vmtry.obj vmstr.obj vmjump.obj vmrange.obj ^
vmperf.obj vmexit.obj vmstack.obj vmstate.obj genlib_e.obj math_e.obj file_e.obj os_e.obj list_e.obj meta_e.obj ^
ext.obj dll_e.obj objfile.obj 

lib  /OUT:..\..\lib\ringstatic.lib rstring.obj ^
rlist.obj ritem.obj ritems.obj rhtable.obj general.obj state.obj scanner.obj parser.obj hashlib.obj vmgc.obj ^
stmt.obj expr.obj codegen.obj vm.obj vmerror.obj vmeval.obj vmthreads.obj vmexpr.obj vmvars.obj ^
vmlists.obj vmfuncs.obj ringapi.obj vmoop.obj vmcui.obj ^
vmtry.obj vmstr.obj vmjump.obj vmrange.obj ^
vmperf.obj vmexit.obj vmstack.obj vmstate.obj genlib_e.obj math_e.obj file_e.obj os_e.obj list_e.obj meta_e.obj ^
ext.obj dll_e.obj objfile.obj 


copy ..\..\lib\ring.dll ..\..\bin\

cl /DEBUG /Z7 %ringcflags% ring.c ..\..\lib\ring.lib -I"..\include" /link /SUBSYSTEM:CONSOLE,"%ringsubsystem%" /STACK:8388608 /OUT:..\..\bin\ring.exe 

del *.obj

endlocal
