AM_CPPFLAGS = \
	-I$(top_srcdir)/src/libstrongswan \
	-I$(top_srcdir)/src/libcharon

AM_CFLAGS = \
	$(PLUGIN_CFLAGS)

if MONOLITHIC
noinst_LTLIBRARIES = libstrongswan-s2b-3gpp.la
else
plugin_LTLIBRARIES = libstrongswan-s2b-3gpp.la
endif

libstrongswan_s2b_3gpp_la_SOURCES = \
	s2b_3gpp_plugin.h s2b_3gpp_plugin.c \
	s2b_3gpp_provider.h s2b_3gpp_provider.c

libstrongswan_s2b_3gpp_la_LDFLAGS = -module -avoid-version