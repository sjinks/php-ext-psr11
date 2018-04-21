PHP_ARG_ENABLE(psr11, whether to enable PSR-11 extension [ --enable-psr11  Enable PSR-11 extension])

if test "$PHP_PSR11" = "yes"; then
	AC_DEFINE([HAVE_PSR11], [1], [Whether PSR-11 extension is enabled])
	PHP_NEW_EXTENSION([psr11], [psr11.c], $ext_shared,, [-Wall -std=gnu99])
fi
