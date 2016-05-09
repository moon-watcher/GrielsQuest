/*
 * This file is part of minilib c project
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 *
 ****************************************************
 *
 * File: test_string.c
 * Use : test bench for string functions
 *
 ****************************************************
 *
 * S. DI MERCURIO: 01-10-10 : first release
 *
 */

#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"

volatile int res;
volatile long resl;
char *buffer[10];
char *ptr;
div_t div_res;
ldiv_t ldiv_res;

int test_string (void)
{
/* standard ISO C 99 */

	res = abs(100);
	//assert(buffer, 1, stdin);
	res = atoi("20");
	resl = atol("20");
	ptr = (char*)calloc(10,10);
	div_res = div(10, 10);
	ldiv_res = ldiv(10,10);
	ptr = (char*)malloc(100);
	srand (10);
	res = rand ();
	resl = strtol("100", &ptr, 10);

	exit(1);
	return res;
}
