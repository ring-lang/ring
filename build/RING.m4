AC_DEFUN([RING_INCLUDE_EXTENSION], [
    ext_dir="ring$1"
    cp build/Makefile.tmp extensions/$ext_dir/Makefile.am

    flags="-I."

    sed -i -- "s/{ext_name}/$1/g" extensions/$ext_dir/Makefile.am
    sed -i -- "s/{ext_cflags}/$flags/g" extensions/$ext_dir/Makefile.am
])
