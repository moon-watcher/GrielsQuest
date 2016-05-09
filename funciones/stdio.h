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
 *
 *	@(#)stdio.h	5.3 (Berkeley) 3/15/86
 */

/*
 * NB: to fit things in six character monocase externals, the
 * stdio code uses the prefix `__s' for stdio objects, typically
 * followed by a three-character attempt at a mnemonic.
 */

#ifndef _STDIO_H_
#define	_STDIO_H_

#include "ansi.h"
#include "types.h"
#include "errno.h"

#include "reent.h"

_BEGIN_STD_C

#define	_FSTDIO			/* ``function stdio'' */

/*
 * Definition of _FILE and FILE structure.
 */

struct __FILE
{
	int (* _read) (char *c, int len);
	int (* _write) (char *c, int len);

	int r_buf_size;
	int w_buf_size;
};

typedef struct __FILE FILE;

/* macro for initializing a FILE structure */
#define _FILE_INIT(filename, read_func, write_func, read_buffer_size, write_buffer_size)\
FILE filename={ \
	read_func,		\
	write_func,		\
	0,0}

#define	__SLBF	0x0001		/* line buffered */
#define	__SNBF	0x0002		/* unbuffered */
#define	__SRD	0x0004		/* OK to read */
#define	__SWR	0x0008		/* OK to write */
	/* RD and WR are never simultaneously asserted */
#define	__SRW	0x0010		/* open for reading & writing */
#define	__SEOF	0x0020		/* found EOF */
#define	__SERR	0x0040		/* found error */
#define	__SMBF	0x0080		/* _buf is from malloc */
#define	__SAPP	0x0100		/* fdopen()ed in append mode - so must  write to end */
#define	__SSTR	0x0200		/* this is an sprintf/snprintf string */
#define	__SOPT	0x0400		/* do fseek() optimisation */
#define	__SNPT	0x0800		/* do not do fseek() optimisation */
#define	__SOFF	0x1000		/* set iff _offset is in fact correct */
#define	__SORD	0x2000		/* true => stream orientation (byte/wide) decided */

#define __SCLE  0x4000        /* convert line endings CR/LF <-> NL */

#define	__SL64	0x8000		/* is 64-bit offset large file */

/* _flags2 flags */
#define	__SWID	0x2000		/* true => stream orientation wide, false => byte, only valid if __SORD in _flags is true */

#ifndef NULL
#define	NULL	0
#endif

#define	EOF	(-1)

#ifndef SEEK_SET
#define	SEEK_SET	0	/* set file offset to offset */
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1	/* set file offset to current plus offset */
#endif
#ifndef SEEK_END
#define	SEEK_END	2	/* set file offset to EOF plus offset */
#endif

#define	TMP_MAX		26

/* Define standard in, out and error files */
extern FILE	*stdin;
extern FILE	*stdout;
extern FILE	*stderr;

/*
 * Functions defined in ANSI C standard.
 */

#ifndef __VALIST
	#ifdef __GNUC__
		#define __VALIST __gnuc_va_list
	#else
		#define __VALIST char*
	#endif
#endif

#ifndef va_list
	#ifdef __GNUC__
		#define va_list 	__builtin_va_list
		#define va_start  	__builtin_va_start
		#define va_end	  	__builtin_va_end
		#define va_arg	  	__builtin_va_arg
	#else
		#define va_list 	
		#define va_start  	
		#define va_end	  	
		#define va_arg	  	
	#endif
#endif

#ifdef getc
	#undef getc
#endif

#ifdef getchar
	#undef getchar
#endif

#ifdef putc 
	#undef putc
#endif

#ifdef putchar
	#undef putchar
#endif

int	fclose(FILE *);
int	fflush(FILE *);
void setbuffer (FILE *, char *, size_t);
int	fprintf (FILE *, const char *, ...) _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
int	fscanf (FILE *, const char *, ...) _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
int	printf (const char *, ...)	_ATTRIBUTE ((__format__ (__printf__, 1, 2)));
int	scanf (const char *, ...) _ATTRIBUTE ((__format__ (__scanf__, 1, 2)));
int	sscanf (const char *, const char *, ...) _ATTRIBUTE ((__format__ (__scanf__, 2, 3)));
int	fgetc (FILE *);
char *fgets (char *, int, FILE *);
int	fputc (int, FILE *);
int	fputs (const char *, FILE *);
int	getc (FILE *);
int	getchar (void);
char * gets (char *);
int	putc (int, FILE *);
int	putchar (int);
int	puts (const char *);

FILE *fopen (const char *_name, const char *_type);
int	sprintf (char *, const char *, ...) _ATTRIBUTE ((__format__ (__printf__, 2, 3)));
int fgetlen (FILE *);

_END_STD_C

#endif /* _STDIO_H_ */
