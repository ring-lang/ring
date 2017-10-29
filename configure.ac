dnl Ring 1.5.4

dnl initializing the autoconf tool
AC_INIT([ring], [1.5.4])

dnl make sure that this main file is exists before compiling
AC_CONFIG_SRCDIR([src/ring.c])

AM_PROG_AR

dnl init LT to be able to compile specific files as shared libraries
LT_INIT

dnl path the main options to Makefile.am
AM_INIT_AUTOMAKE([-Wall foreign subdir-objects])

dnl specify and create the Makefile
AC_CONFIG_FILES([Makefile])

dnl find the probe compiler
AC_PROG_CC

dnl output the final files
AC_OUTPUT
