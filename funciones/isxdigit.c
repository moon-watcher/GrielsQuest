/*
FUNCTION
<<isxdigit>>---hexadecimal digit predicate

INDEX
isxdigit

ANSI_SYNOPSIS
#include <ctype.h>
int isxdigit(int <[c]>);

TRAD_SYNOPSIS
#include <ctype.h>
int isxdigit(<[c]>);

DESCRIPTION
<<isxdigit>> is a macro which classifies ASCII integer values by table
lookup.  It is a predicate returning non-zero for hexadecimal digits, and 0 for
other characters.  It is defined only when <<isascii>>(<[c]>) is true
or <[c]> is EOF.

You can use a compiled subroutine instead of the macro definition by
undefining the macro using `<<#undef isxdigit>>'.

RETURNS
<<isxdigit>> returns non-zero if <[c]> is an hexadecimal digit (<<0>>--<<9>>, <<A>>--<<F>>, <<a>>--<<f>>).

PORTABILITY
<<isxdigit>> is ANSI C.

No supporting OS subroutines are required.
*/

#include "ctype.h"

#undef isxdigit
int isxdigit (int c)
{
	return(((c>='0') && (c<='9')) || ((c>='A') && (c<='F')) || ((c>='a') && (c<='f')) );
}
