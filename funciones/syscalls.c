/*
 * Todo: faire un commentaire d'introduction
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "missing_defs.h"

#ifdef __GNUC__
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <reent.h>

	struct _reent *_impure_ptr __ATTRIBUTE_IMPURE_PTR__;
#else
	#define ENOMEM -2
	#define EAGAIN -3
	#define EINVAL -4
	#define EMLINK -5
	#define ENOENT -6
	#define ECHILD -7
	
	#define S_IFCHR 0x12
	#define caddr_t int	
	
	struct stat
	{
		int st_mode;	
	}; 

	struct tms
	{
		int a;
	};
#endif /* __GNUC__ */

#undef errno
int errno;
	   
/*
 * _exit
 *   Exit a program without cleaning up files. If your system doesn't provide this, it is best to avoid linking with subroutines that require it (exit, system).
 */
void _exit(int exit_code)
{
	/* Nothing to do */
	for (;;);
}

/*
 * _kill
 * Send a signal. Minimal implementation:
 */
int _kill(int pid, int sig) 
{
	errno = EINVAL;
	return -1;
}

/*
 * _open
 * Open a file. Minimal implementation:
 */
int _open(const char *name, int flags, int mode) 
{
	return -1;
}

/*
 * _read
 * Read from a file. Minimal implementation:
 */
int _read(int file, char *ptr, int len) 
{
int todo;
char *loc_ptr;

	loc_ptr = ptr;

	for (todo = 0; todo < len; todo++) 
	{
  		//*loc_ptr = fgetc (&__stdout);
		loc_ptr++;
	}	
	
	return len;
}

/*
 *	_write
 *  Write to a file. libc subroutines will use this system routine for output to all files, including stdout—so if you need to generate any output, for example to a serial port for debugging, you should make your minimal write capable of doing this. The following minimal implementation is an incomplete example; it relies on a outbyte subroutine (not shown; typically, you must write this in assembler from examples provided by your hardware manufacturer) to actually perform the output.
 */
int _write(int file, char *ptr, int len) 
{
volatile int todo;

	for (todo = 0; todo < len; todo++) 
	{
  		//fputc (*ptr++, &__stdout);
	}

	return len;
}

/*
 * _malloc
 * Allocate memory. Minimal implementation:
 */
void *_malloc(size_t nbytes) 
{
	return NULL;
}

/*
 * _free
 * Release memory. Minimal implementation:
 */
void _free(void *aptr) 
{
}

