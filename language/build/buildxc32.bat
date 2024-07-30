rem Building Ring using Microchip C compiler for 32-bit PIC Microcontrollers
rem This will produce ring.elf then ring.hex file 
rem Ref: https://www.microchip.com/en-us/products/microcontrollers-and-microprocessors/32-bit-mcus

cd ..\src

xc32-gcc -O2 -mprocessor=32CZ8110CA90208 -o ring.elf -Wl,--defsym=_min_heap_size=0xF000 -mmalloc-variant=binned ring.c general.c state.c ext.c hashlib.c rhtable.c vmgc.c rstring.c rlist.c ritem.c ritems.c scanner.c parser.c stmt.c expr.c codegen.c vm.c vmerror.c vmeval.c vmthread.c vmexpr.c vmvars.c vmlists.c vmfuncs.c ringapi.c vmoop.c  vmtry.c vmstr.c vmjump.c vmrange.c   vmperf.c vmexit.c vmstack.c vmstate.c objfile.c genlib_e.c list_e.c math_e.c meta_e.c file_e.c vminfo_e.c os_e.c -I ../include -lm  

xc32-bin2hex ring.elf
 
dir *.hex