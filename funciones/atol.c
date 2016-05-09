/*
NAME

     atol, atoll -- convert ASCII string to long or long long
     integer


LIBRARY

     Standard C Library (libc, -lc)


SYNOPSIS

     #include <stdlib.h>

     long
     atol(const char *str);

     long long
     atoll(const char *str);


DESCRIPTION

     The atol() function converts the initial portion of the string pointed to
     by str to long integer representation.

     It is equivalent to:

           strtol(str, (char **)NULL, 10);

     The atoll() function converts the initial portion of the string pointed
     to by str to long long integer representation.

     It is equivalent to:

           strtoll(str, (char **)NULL, 10);

     atol() and atoll() functions use the current locale.


ERRORS

     The functions atol() and atoll() need not affect the value of errno on an
     error.
*/

#include "stdlib.h"

long atol(const char *s)
{
  	return strtol (s, NULL, 10);
}

long long atoll(const char *s)
{
  	return (long long)strtol (s, NULL, 10);
}


