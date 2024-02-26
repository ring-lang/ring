cd ..\src
 
gcc -O3 ring.c general.c state.c ext.c hashlib.c rhtable.c vmgc.c os_e.c rstring.c rlist.c ritem.c ritems.c scanner.c parser.c stmt.c expr.c codegen.c vm.c vmerror.c vmeval.c vmthreads.c vmexpr.c vmvars.c vmlists.c vmfuncs.c ringapi.c vmoop.c vmcui.c vmtry.c vmstr.c vmjump.c vmrange.c list_e.c meta_e.c vmperf.c vmexit.c vmstack.c vmstate.c genlib_e.c math_e.c file_e.c dll_e.c objfile.c -I ../include -o ../../bin/ring -lm 

 
