dnl $Id$
dnl config.m4 for extension helpers

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(helpers, for helpers support,
dnl Make sure that the comment is aligned:
dnl [  --with-helpers             Include helpers support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(helpers, whether to enable helpers support,
Make sure that the comment is aligned:
[  --enable-helpers           Enable helpers support])

if test "$PHP_HELPERS" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-helpers -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/helpers.h"  # you most likely want to change this
  dnl if test -r $PHP_HELPERS/$SEARCH_FOR; then # path given as parameter
  dnl   HELPERS_DIR=$PHP_HELPERS
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for helpers files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       HELPERS_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$HELPERS_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the helpers distribution])
  dnl fi

  dnl # --with-helpers -> add include path
  dnl PHP_ADD_INCLUDE($HELPERS_DIR/include)

  dnl # --with-helpers -> check for lib and symbol presence
  dnl LIBNAME=helpers # you may want to change this
  dnl LIBSYMBOL=helpers # you most likely want to change this

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $HELPERS_DIR/$PHP_LIBDIR, HELPERS_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_HELPERSLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong helpers lib version or lib not found])
  dnl ],[
  dnl   -L$HELPERS_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(HELPERS_SHARED_LIBADD)

  PHP_NEW_EXTENSION(helpers, helpers.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
