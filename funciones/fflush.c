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
NAME

	fflush - flush a stream

SYNOPSIS

	#include <stdio.h>

	int fflush(FILE *stream);

DESCRIPTION

	[CX]  The functionality described on this reference page is aligned with the ISO C standard. Any conflict between the requirements described here and the ISO C standard is unintentional. This volume of IEEE Std 1003.1-2001 defers to the ISO C standard. 
	If stream points to an output stream or an update stream in which the most recent operation was not input, fflush() shall cause any unwritten data for that stream to be written to the file, [CX]   and the st_ctime and st_mtime fields of the underlying file shall be marked for update. 
	
	If stream is a null pointer, fflush() shall perform this flushing action on all streams for which the behavior is defined above.

RETURN VALUE

	Upon successful completion, fflush() shall return 0; otherwise, it shall set the error indicator for the stream, return EOF, [CX]   and set errno to indicate the error. 

ERRORS

	The fflush() function shall fail if:
	
	[EAGAIN]
	[CX]  The O_NONBLOCK flag is set for the file descriptor underlying stream and the thread would be delayed in the write operation. 
	[EBADF]
	[CX]  The file descriptor underlying stream is not valid. 
	[EFBIG]
	[CX]  An attempt was made to write a file that exceeds the maximum file size. 
	[EFBIG]
	[XSI]  An attempt was made to write a file that exceeds the process' file size limit. 
	[EFBIG]
	[CX]  The file is a regular file and an attempt was made to write at or beyond the offset maximum associated with the corresponding stream. 
	[EINTR]
	[CX]  The fflush() function was interrupted by a signal. 
	[EIO]
	[CX]  The process is a member of a background process group attempting to write to its controlling terminal, TOSTOP is set, the process is neither ignoring nor blocking SIGTTOU, and the process group of the process is orphaned. This error may also be returned under implementation-defined conditions. 
	[ENOSPC]
	[CX]  There was no free space remaining on the device containing the file. 
	[EPIPE]
	[CX]  An attempt is made to write to a pipe or FIFO that is not open for reading by any process. A SIGPIPE signal shall also be sent to the thread. 
	The fflush() function may fail if:
	
	[ENXIO]
	[CX]  A request was made of a nonexistent device, or the request was outside the capabilities of the device. 
*/

#include "stdio.h"

int	fflush(FILE *fp)
{
	fp->r_len=0;
	fp->w_len=0;

	fp->r_ptr_in=fp->r_buf;
	fp->r_ptr_out=fp->r_buf;

	fp->w_ptr_in=fp->w_buf;
	fp->w_ptr_out=fp->w_buf;

	return 0;
}

