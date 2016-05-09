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
	fopen - open a stream

SYNOPSIS
	#include <stdio.h>

	FILE *fopen(const char *restrict filename, const char *restrict mode);

DESCRIPTION

	[CX]  The functionality described on this reference page is aligned with the ISO C standard. Any conflict between the requirements described here and the ISO C standard is unintentional. This volume of IEEE Std 1003.1-2001 defers to the ISO C standard. 
	The fopen() function shall open the file whose pathname is the string pointed to by filename, and associates a stream with it.

	The mode argument points to a string. If the string is one of the following, the file shall be opened in the indicated mode. Otherwise, the behavior is undefined.

	r or rb
	Open file for reading.
	w or wb
	Truncate to zero length or create file for writing.
	a or ab
	Append; open or create file for writing at end-of-file.
	r+ or rb+ or r+b
	Open file for update (reading and writing).
	w+ or wb+ or w+b
	Truncate to zero length or create file for update.
	a+ or ab+ or a+b
	Append; open or create file for update, writing at end-of-file.
	[CX]  The character 'b' shall have no effect, but is allowed for ISO C standard conformance.  Opening a file with read mode (r as the first character in the mode argument) shall fail if the file does not exist or cannot be read.
	
	Opening a file with append mode (a as the first character in the mode argument) shall cause all subsequent writes to the file to be forced to the then current end-of-file, regardless of intervening calls to fseek().
	
	When a file is opened with update mode ( '+' as the second or third character in the mode argument), both input and output may be performed on the associated stream. However, the application shall ensure that output is not directly followed by input without an intervening call to fflush() or to a file positioning function ( fseek(), fsetpos(), or rewind()), and input is not directly followed by output without an intervening call to a file positioning function, unless the input operation encounters end-of-file.
	
	When opened, a stream is fully buffered if and only if it can be determined not to refer to an interactive device. The error and end-of-file indicators for the stream shall be cleared.
	
	[CX]  If mode is w, wb, a, ab, w+, wb+, w+b, a+, ab+, or a+b, and the file did not previously exist, upon successful completion, the fopen() function shall mark for update the st_atime, st_ctime, and st_mtime fields of the file and the st_ctime and st_mtime fields of the parent directory.
	
	If mode is w, wb, w+, wb+, or w+b, and the file did previously exist, upon successful completion, fopen() shall mark for update the st_ctime and st_mtime fields of the file. The fopen() function shall allocate a file descriptor as open() does. 
	
	After a successful call to the fopen() function, the orientation of the stream shall be cleared, [XSI]   the encoding rule shall be cleared,  and the associated mbstate_t object shall be set to describe an initial conversion state.
	
	[CX]  The largest value that can be represented correctly in an object of type off_t shall be established as the offset maximum in the open file description. 

RETURN VALUE

	Upon successful completion, fopen() shall return a pointer to the object controlling the stream. Otherwise, a null pointer shall be returned, [CX]   and errno shall be set to indicate the error. 

ERRORS

	The fopen() function shall fail if:
	
	[EACCES]
	[CX]  Search permission is denied on a component of the path prefix, or the file exists and the permissions specified by mode are denied, or the file does not exist and write permission is denied for the parent directory of the file to be created. 
	[EINTR]
	[CX]  A signal was caught during fopen(). 
	[EISDIR]
	[CX]  The named file is a directory and mode requires write access. 
	[ELOOP]
	[CX]  A loop exists in symbolic links encountered during resolution of the path argument. 
	[EMFILE]
	[CX]  {OPEN_MAX} file descriptors are currently open in the calling process. 
	[ENAMETOOLONG]
	[CX] 
	The length of the filename argument exceeds {PATH_MAX} or a pathname component is longer than {NAME_MAX}. 
	[ENFILE]
	[CX]  The maximum allowable number of files is currently open in the system. 
	[ENOENT]
	[CX]  A component of filename does not name an existing file or filename is an empty string. 
	[ENOSPC]
	[CX]  The directory or file system that would contain the new file cannot be expanded, the file does not exist, and the file was to be created. 
	[ENOTDIR]
	[CX]  A component of the path prefix is not a directory. 
	[ENXIO]
	[CX]  The named file is a character special or block special file, and the device associated with this special file does not exist. 
	[EOVERFLOW]
	[CX]  The named file is a regular file and the size of the file cannot be represented correctly in an object of type off_t. 
	[EROFS]
	[CX]  The named file resides on a read-only file system and mode requires write access. 
	The fopen() function may fail if:
	
	[EINVAL]
	[CX]  The value of the mode argument is not valid. 
	[ELOOP]
	[CX]  More than {SYMLOOP_MAX} symbolic links were encountered during resolution of the path argument. 
	[EMFILE]
	[CX]  {FOPEN_MAX} streams are currently open in the calling process. 
	[EMFILE]
	[CX]  {STREAM_MAX} streams are currently open in the calling process. 
	[ENAMETOOLONG]
	[CX] 
	Pathname resolution of a symbolic link produced an intermediate result whose length exceeds {PATH_MAX}. 
	[ENOMEM]
	[CX]  Insufficient storage space is available. 
	[ETXTBSY]
	[CX]  The file is a pure procedure (shared text) file that is being executed and mode requires write access. 

*/

#include "stdio.h"

FILE *_fopen (const char *_name, const char *_type);

FILE *fopen (const char *_name, const char *_type)
{
	return _fopen (_name, _type);
}

