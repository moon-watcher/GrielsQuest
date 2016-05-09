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
 * File: test_ctype.c
 * Use : test bench for ctype functions
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

int test_ctype (void)
{
	res = isalpha('A');
	res = isalnum('A');
	res = isascii('A');
	res = isblank('A');
	res = iscntrl('A');
	res = isdigit('A');
	res = islower('A');
	res = isprint('A');
	res = ispunct('A');
	res = isspace('A');
	res = isupper('A');
	res = isxdigit('A');
	res = toascii('A');
	res = tolower('A');
	res = toupper('A');
	
	return res;
}
