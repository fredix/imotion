AC_PREREQ(2.60)
AC_INIT([geekast], [0.1.3], [fredix@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([1.9.6 -Wall -Werror dist-bzip2])

AC_PROG_CC
# Compiling sources with per-target flags requires AM_PROG_CC_C_O
AM_PROG_CC_C_O
AC_PROG_INSTALL
AC_PROG_LIBTOOL




GNOME_MODULES="libgnomeui-2.0 >= 2.0.0"
PKG_CHECK_MODULES(GNOME, $GNOME_MODULES)
AC_SUBST(GNOME_CFLAGS)
AC_SUBST(GNOME_LIBS)


GLADE_MODULES="libglade-2.0 >= 2.0.0"
PKG_CHECK_MODULES(GLADE, $GLADE_MODULES)
AC_SUBST(GLADE_CFLAGS)
AC_SUBST(GLADE_LIBS)



AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
        Makefile
        src/Makefile
        tests/Makefile
])
AC_OUTPUT