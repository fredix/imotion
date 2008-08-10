## Process this file with automake to generate a Makefile.in
## To build all programs with GTK+ uncomment these lines.
##AM_CPPFLAGS = @GTK_CFLAGS@
##AM_LDADD = @GTK_LIBS@

AM_CPPFLAGS = -DGNOMELOCALE_DIR=\""$(datadir)/locale/"\" \
              -DG_LOG_DOMAIN=\"Geekast\" \
              -I$(top_srcdir) \
              $(GNOME_CFLAGS) $(GLADE_CFLAGS)


LIBS = $(GNOME_LIBS) $(GLADE_LIBS)


bin_PROGRAMS = geekast
geekast_SOURCES = ui.c main.c callback.c

## Only our GUI program uses GTK+ at the moment.
#geekast_CPPFLAGS = @GNOME_CFLAGS@ @GNOME_LIBS@ @GLADE_CFLAGS@ @GLADE_LIBS@

CLEANFILES = *~
