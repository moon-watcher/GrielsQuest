#ifndef _CTYPE_H_
#define _CTYPE_H_

#include "ansi.h"

_BEGIN_STD_C

int _EXFUN(isalnum, (int __c));
int _EXFUN(isalpha, (int __c));
int _EXFUN(iscntrl, (int __c));
int _EXFUN(isdigit, (int __c));
int _EXFUN(isgraph, (int __c));
int _EXFUN(islower, (int __c));
int _EXFUN(isprint, (int __c));
int _EXFUN(ispunct, (int __c));
int _EXFUN(isspace, (int __c));
int _EXFUN(isupper, (int __c));
int _EXFUN(isxdigit,(int __c));
int _EXFUN(tolower, (int __c));
int _EXFUN(toupper, (int __c));

#if !defined(__STRICT_ANSI__) || defined(__cplusplus) || __STDC_VERSION__ >= 199901L
	int _EXFUN(isblank, (int __c));
#endif

#ifndef __STRICT_ANSI__
	int _EXFUN(isascii, (int __c));
	int _EXFUN(toascii, (int __c));
	#define _tolower(__c) ((unsigned char)(__c) - 'A' + 'a')
	#define _toupper(__c) ((unsigned char)(__c) - 'a' + 'A')
#endif

#define	_U	01
#define	_L	02
#define	_N	04
#define	_S	010
#define _P	020
#define _C	040
#define _X	0100
#define	_B	0200

#ifndef __STRICT_ANSI__
	#define isascii(__c)	((unsigned)(__c)<=0177)
	#define toascii(__c)	((__c)&0177)
#endif

_END_STD_C

#endif /* _CTYPE_H_ */
