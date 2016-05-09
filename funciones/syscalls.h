/*
 * System call prototype for minilib C library
 *
 * This code is distributed under BSD licence. A LICENCE.TXT file should be provided
 * with this code. Please see LICENCE.txt file for questions aout redistribution, contribution
 * or copyright.
 *
 * Authors: S. Di Mercurio and P. Acco (INSA - GEI, toulouse, france)
 */

#ifndef __SYSCALLS_H__
#define __SYSCALLS_H__

void _exit(int exit_code);
int _kill(int pid, int sig);
int _open(const char *name, int flags, int mode);
int _read(int file, char *ptr, int len);
int _write(int file, char *ptr, int len);
void *_malloc(size_t nbytes);
void _free(void *aptr); 

#endif /* __SYSCALLS_H__ */

