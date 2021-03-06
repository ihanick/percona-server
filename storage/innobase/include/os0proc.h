/*****************************************************************************

Copyright (c) 1995, 2009, Oracle and/or its affiliates. All Rights Reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License, version 2.0,
as published by the Free Software Foundation.

This program is also distributed with certain software (including
but not limited to OpenSSL) that is licensed under separate terms,
as designated in a particular file or component or in included license
documentation.  The authors of MySQL hereby grant you an additional
permission to link the program and your derivative works with the
separately licensed software that they have included with MySQL.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License, version 2.0, for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA

*****************************************************************************/

/**************************************************//**
@file include/os0proc.h
The interface to the operating system
process control primitives

Created 9/30/1995 Heikki Tuuri
*******************************************************/

#ifndef os0proc_h
#define os0proc_h

#include "univ.i"

#ifdef UNIV_LINUX
#include <sys/ipc.h>
#include <sys/shm.h>
#endif

typedef void*			os_process_t;
typedef unsigned long int	os_process_id_t;

extern ibool os_use_large_pages;
/* Large page size. This may be a boot-time option on some platforms */
extern ulint os_large_page_size;

/****************************************************************//**
Converts the current process id to a number. It is not guaranteed that the
number is unique. In Linux returns the 'process number' of the current
thread. That number is the same as one sees in 'top', for example. In Linux
the thread id is not the same as one sees in 'top'.
@return	process id as a number */
UNIV_INTERN
ulint
os_proc_get_number(void);
/*====================*/
/****************************************************************//**
Allocates large pages memory.
@return	allocated memory */
UNIV_INTERN
void*
os_mem_alloc_large(
/*===============*/
	ulint*	n,			/*!< in/out: number of bytes */
	bool	populate);		/*!< in: virtual page preallocation */
/****************************************************************//**
Frees large pages memory. */
UNIV_INTERN
void
os_mem_free_large(
/*==============*/
	void	*ptr,			/*!< in: pointer returned by
					os_mem_alloc_large() */
	ulint	size);			/*!< in: size returned by
					os_mem_alloc_large() */

#ifndef UNIV_NONINL
#include "os0proc.ic"
#endif

#endif
