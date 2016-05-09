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

	setbuffer - stream buffering operations

Synopsis

	#include <stdio.h>
		
	void setbuffer(FILE *stream, char *buf, size_t size);

Description
 
	The three types of buffering available are unbuffered, block buffered, and line buffered. When an output stream is unbuffered, information appears on the destination file or terminal as soon as written; when it is block buffered many characters are saved up and written as a block; when it is line buffered characters are saved up until a newline is output or input is read from any stream attached to a terminal device (typically stdin). The function fflush(3) may be used to force the block out early. (See fclose(3).) Normally all files are block buffered. When the first I/O operation occurs on a file, malloc(3) is called, and a buffer is obtained. If a stream refers to a terminal (as stdout normally does) it is line buffered. The standard error stream stderr is always unbuffered by default.
	
	The setvbuf() function may be used on any open stream to change its buffer. The mode argument must be one of the following three macros:
	
	_IONBF
	unbuffered
	
	_IOLBF
	
	line buffered
	
	_IOFBF
	
	fully buffered
	
	Except for unbuffered files, the buf argument should point to a buffer at least size bytes long; this buffer will be used instead of the current buffer. If the argument buf is NULL, only the mode is affected; a new buffer will be allocated on the next read or write operation. The setvbuf() function may only be used after opening a stream and before any other operations have been performed on it.
	The other three calls are, in effect, simply aliases for calls to setvbuf(). The setbuf() function is exactly equivalent to the call
	
	setvbuf(stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
	The setbuffer() function is the same, except that the size of the buffer is up to the caller, rather than being determined by the default BUFSIZ. The setlinebuf() function is exactly equivalent to the call:
	setvbuf(stream, (char *) NULL, _IOLBF, 0);
Return Value

	The function setvbuf() returns 0 on success. It returns nonzero on failure (mode is invalid or the request cannot be honored). It may set errno on failure.
	
	The other functions do not return a value.

Conforming To

	The setbuf() and setvbuf() functions conform to C89 and C99.
*/

#include "stdio.h"

void setbuffer(FILE *fp, char *buf, size_t size)
{
	fp->r_buf = buf;
	fp->r_buf_size = (int)size;

}

