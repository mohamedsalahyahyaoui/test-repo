## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = test

test_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h\
	verif.c verif.h \
	crudparent.c crud.h \
	crudmaitresse.c crud.h \
	crudenfant.c  crud.h\
	crudbracelet.c  crud.h\
	crudclasse.c crud.h\
	combo.c	combo.h


test_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

