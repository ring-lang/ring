clear
gcc -O2 ring.c ring_general.c ring_state.c ring_ext.c ring_hashlib.c ring_hashtable.c ring_vmgc.c ring_vmos.c ring_string.c ring_list.c ring_item.c ring_items.c ring_scanner.c ring_parser.c ring_stmt.c ring_expr.c ring_codegen.c ring_vm.c ring_vmexpr.c ring_vmvars.c ring_vmlists.c ring_vmfuncs.c ring_api.c ring_vmoop.c ring_vmcui.c ring_vmtrycatch.c ring_vmstrindex.c ring_vmjump.c ring_vmduprange.c ring_vmlistfuncs.c ring_vmrefmeta.c ring_vmperformance.c ring_vmexit.c ring_vmstackvars.c ring_vmstate.c ring_vmmath.c ring_vmfile.c ring_vmdll.c ring_objfile.c -I $PWD/../include -o $PWD/../../bin/ring -lm -ldl

cd ../../bin
sudo ./install.sh
cd ../language/src
