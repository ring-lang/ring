cd ..\..\include

copy /Y ..\build\vmcgoto\rconfig_updated.h rconfig.h

cd ..\src

gcc -O3 -flto  ring.c general.c state.c ext.c hashlib.c rhtable.c vmgc.c os_e.c rstring.c rlist.c ritem.c ritems.c scanner.c parser.c stmt.c expr.c codegen.c vm.c vmerror.c vmeval.c vmthread.c vmexpr.c vmvars.c vmlists.c vmfuncs.c ringapi.c vmoop.c  vmtry.c vmstr.c vmjump.c vmrange.c list_e.c meta_e.c vminfo_e.c vmperf.c vmexit.c vmstack.c vmstate.c genlib_e.c math_e.c file_e.c dll_e.c objfile.c ..\build\vmcgoto\vmcgoto.c -I ../include -o ../../bin/ring -lm 

gcc -O3 -flto -mwindows ringw.c general.c state.c ext.c hashlib.c rhtable.c vmgc.c os_e.c rstring.c rlist.c ritem.c ritems.c scanner.c parser.c stmt.c expr.c codegen.c vm.c vmerror.c vmeval.c vmthread.c vmexpr.c vmvars.c vmlists.c vmfuncs.c ringapi.c vmoop.c  vmtry.c vmstr.c vmjump.c vmrange.c list_e.c meta_e.c vminfo_e.c vmperf.c vmexit.c vmstack.c vmstate.c genlib_e.c math_e.c file_e.c dll_e.c objfile.c ..\build\vmcgoto\vmcgoto.c -I ../include -o ../../bin/ringw -lm 

cd ..\include

copy /Y ..\build\vmcgoto\rconfig_default.h rconfig.h
 
cd ..\build