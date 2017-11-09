dnl Ring 1.5.4

dnl initializing the autoconf tool
AC_INIT([ring], [1.5.4])

dnl Set the main m4 macros directory
AC_CONFIG_MACRO_DIRS([build/m4])

dnl Set the auxility directory
AC_CONFIG_AUX_DIR([build/aux])

dnl make sure that this main file is exists before compiling
AC_CONFIG_SRCDIR([src/ring.c])

AM_PROG_AR

dnl init LT to be able to compile specific files as shared libraries
LT_INIT

dnl temporary way to set libdir to specific directory
dnl WARNING, setting this "standard" variable will make
dnl the user can not change the library directory, this
dnl should be fixed.
libdir=/usr/local/lib/ring


AC_ARG_ENABLE([mysql],
    AS_HELP_STRING([--enable-mysql], [Enable Mysql extension])
)

AS_IF([test "ring_$enable_mysql" == "ring_yes"], [
    dnl compile mysql extension!
    RING_INCLUDE_EXTENSION([mysql])
])


dnl path the main options to Makefile.am
AM_INIT_AUTOMAKE([-Wall foreign subdir-objects])

dnl specify and create the Makefile
AC_CONFIG_FILES([Makefile])

dnl find the probe compiler
AC_PROG_CC

dnl output the final files
AC_OUTPUT
