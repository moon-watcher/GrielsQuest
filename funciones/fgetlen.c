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
<<fgetlen>>---get length of received data for this stream

INDEX
	fgetlen

ANSI_SYNOPSIS
	#include <stdio.h>
	int fgetlen(FILE *<[fp]>);

DESCRIPTION
Use <<fgetlen>> to get the amount of received data from the file or stream
identified by <[fp]>.  

RETURNS
The amount of received data or -1 if there is no reception buffer

PORTABILITY
This function is not part of POSIX neither of ANSY

*/

#include "stdio.h"

int fgetlen(FILE *fp)
{
	if (fp->r_buf!=NULL) return fp->r_len;
	else return -1;
}

