
AC_DEFUN([_LIST_FULL_EXT_SOURCES], [
    dir="$1"
    ring_extension_source=`find $dir -name '*.c'`
    unset -v dir
])

dnl
dnl RING_INCLUDE_EXTENSION([ext_name], [ext_sources], [cflags], [ld_flags])
AC_DEFUN([RING_INCLUDE_EXTENSION], [
    ext_dir="ring$1"
    ext_name="$1"
    ext_sources="$2"
    ext_cflags="$3"
    ext_ldflags="$4"
    is_shared="$5"

    echo $ext_dir
    echo $ext_name
    echo $ext_sources
    echo $ext_cflags
    echo $ext_ldflags

    ext_path="$RINGEXT_DIR/$ext_dir/"

    _LIST_FULL_EXT_SOURCES($ext_path)

    echo $ring_extension_source

    sub_dirs="$sub_dirs $ext_path"

    echo $sub_dirs;

    AC_MSG_ERROR
    dnl cp build/Makefile.tmp extensions/$ext_dir/Makefile.am

    dnl flags="-I."

    dnl sed -i -- "s/{ext_name}/$1/g" extensions/$ext_dir/Makefile.am
    dnl sed -i -- "s/{ext_cflags}/$flags/g" extensions/$ext_dir/Makefile.am
])
