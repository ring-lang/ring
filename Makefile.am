

lib_LTLIBRARIES = libring.la
libring_la_SOURCES = include/ring.h src/ring_state.c src/ring_ext.c \
    src/ring_hashlib.c src/ring_hashtable.c src/ring_vmgc.c \
    src/ring_vmos.c src/ring_string.c src/ring_list.c src/ring_item.c \
    src/ring_items.c src/ring_scanner.c src/ring_parser.c \
    src/ring_stmt.c src/ring_expr.c src/ring_codegen.c \
    src/ring_vm.c src/ring_vmexpr.c src/ring_vmvars.c src/ring_vmlists.c \
    src/ring_vmfuncs.c src/ring_api.c src/ring_vmoop.c src/ring_vmcui.c \
    src/ring_vmtrycatch.c src/ring_vmstrindex.c src/ring_vmjump.c \
    src/ring_vmduprange.c src/ring_vmlistfuncs.c \
    src/ring_vmrefmeta.c src/ring_vmperformance.c src/ring_vmexit.c \
    src/ring_vmstackvars.c src/ring_vmstate.c src/ring_vmmath.c \
    src/ring_vmfile.c src/ring_vmdll.c src/ring_objfile.c
libring_la_CFLAGS = -I$(top_srcdir)/include -lm -ldl
libring_la_LDFLAGS = -R /usr/local/lib/ring/

bin_PROGRAMS = ring
ring_SOURCES = src/ring.c
ring_CFLAGS = -L$(top_srcdir)/lib -lring  -I$(top_srcdir)/include
ring_LDFLAGS = -R /usr/local/lib/ring/
