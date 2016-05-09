/*
 * Copyright (c) 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that the above copyright notice and this paragraph are
 * duplicated in all such forms and that any documentation,
 * advertising materials, and other materials related to such
 * distribution and use acknowledge that the software was developed
 * by the University of California, Berkeley.  The name of the
 * University may not be used to endorse or promote products derived
 * from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
FUNCTION
<<fgets>>---get character string from a file or stream

INDEX
	fgets
INDEX
	_fgets_r

ANSI_SYNOPSIS
        #include <stdio.h>
	char *fgets(char *<[buf]>, int <[n]>, FILE *<[fp]>);

        #include <stdio.h>
	char *_fgets_r(struct _reent *<[ptr]>, char *<[buf]>, int <[n]>, FILE *<[fp]>);

TRAD_SYNOPSIS
	#include <stdio.h>
	char *fgets(<[buf]>,<[n]>,<[fp]>)
        char *<[buf]>;
	int <[n]>;
	FILE *<[fp]>;

	#include <stdio.h>
	char *_fgets_r(<[ptr]>, <[buf]>,<[n]>,<[fp]>)
	struct _reent *<[ptr]>;
        char *<[buf]>;
	int <[n]>;
	FILE *<[fp]>;

DESCRIPTION
	Reads at most <[n-1]> characters from <[fp]> until a newline
	is found. The characters including to the newline are stored
	in <[buf]>. The buffer is terminated with a 0.

	The <<_fgets_r>> function is simply the reentrant version of
	<<fgets>> and is passed an additional reentrancy structure
	pointer: <[ptr]>.

RETURNS
	<<fgets>> returns the buffer passed to it, with the data
	filled in. If end of file occurs with some data already
	accumulated, the data is returned with no other indication. If
	no data are read, NULL is returned instead.

PORTABILITY
	<<fgets>> should replace all uses of <<gets>>. Note however
	that <<fgets>> returns all of the data, while <<gets>> removes
	the trailing newline (with no indication that it has done so.)

Supporting OS subroutines required: <<close>>, <<fstat>>, <<isatty>>,
<<lseek>>, <<read>>, <<sbrk>>, <<write>>.
*/

#include "stdio.h"

/*
 * Read at most n-1 characters from the given file.
 * Stop when a newline has been read, or the count runs out.
 * Return first argument, or NULL if no characters were read.
 */

char *fgets(char *buf, int n, FILE *fp)
{
  	int index;
	char c;

	index =0;
	do
	{
		if (fp->_read((char*) &c, 1)>0)
		{
			buf[index++]=c;
		}
	} while ((index<n) && (c!='\n'));

	buf[index] = 0x0; // Add zero to the end of the string
	 
  	return buf;
}

