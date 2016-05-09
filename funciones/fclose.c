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
Name
	fclose - close a stream

Synopsis

	#include <stdio.h>
	int fclose(FILE *fp);

Description

	The fclose() function will flushes the stream pointed to by fp (writing any buffered output data using fflush(3)) and 
	closes the underlying file descriptor.

Return Value
	Upon successful completion 0 is returned. Otherwise, EOF is returned and errno is set to indicate the error. In 
	either case any further access (including another call to fclose()) to the stream results in undefined behavior.

Errors

	EBADF
	The file descriptor underlying fp is not valid.
	The fclose() function may also fail and set errno for any of the errors specified for the routines close(2), write(2) 
	or fflush(3).

Conforming to

	C89, C99.
Notes

	Note that fclose() only flushes the user space buffers provided by the C library. To ensure that the data is physically 
	stored on disk the kernel buffers must be flushed too, for example, with sync(2) or fsync(2).
*/

#include "stdio.h"

int _fclose(FILE *fp);

int	fclose(FILE *fp)
{
	return _fclose(fp);
}

