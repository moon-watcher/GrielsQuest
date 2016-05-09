/*
 * Missing definition for minilib C library
 *
 * This code is distributed under BSD licence. A LICENCE.TXT file should be provided
 * with this code. Please see LICENCE.txt file for questions aout redistribution, contribution
 * or copyright.
 *
 * Authors: S. Di Mercurio and P. Acco (INSA - GEI, toulouse, france)
 */

#ifndef __MISSING_DEFS__
#define __MISSING_DEFS__

#if !defined(__AVR__)

/* Definition of FILE struct */
struct __FILE
{
	int _file; // only field required for our lib C */
};

#else

#undef _file
#define _file len

#endif /* !defined (__AVR__) */



#endif /* __MISSING_DEFS__ */
