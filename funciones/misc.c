/*
 * Copyright 2012 - INSA Toulouse, France.
 * Written by S. DI MERCURIO
 *
 */

#include "stdio.h"

int _read_dummy (char *c, int len);
int _write_dummy (char *c, int len);

_FILE_INIT (_dummy_file, _read_dummy, _write_dummy, 0, 0);

/* Definition of standard files */
FILE	*stdin=&_dummy_file;
FILE	*stdout=&_dummy_file;
FILE	*stderr=&_dummy_file;

int _read_dummy (char *c, int len)
{
	return len;
}

int _write_dummy (char *c, int len)
{
	return len;
}