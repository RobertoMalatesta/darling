/* Modified for Darling by Lubos Dolezel (2015) */
/*
 * Copyright (c) 2000 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 * Copyright (c) 1989, 1993
 *	The Regents of the University of California.  All rights reserved.
 * (c) UNIX System Laboratories, Inc.
 * All or some portions of this file are derived from material licensed
 * to the University of California by American Telephone and Telegraph
 * Co. or Unix System Laboratories, Inc. and are reproduced herein with
 * the permission of UNIX System Laboratories, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)time.h	8.3 (Berkeley) 1/21/94
 */

#ifndef _TIME_H_
#define	_TIME_H_

#include <_types.h>

#define __need_struct_timespec
//#include <_structs.h>
#include "../../kernel-include/sys/_structs.h"

#ifndef NULL
#define NULL __DARWIN_NULL
#endif /* ! NULL */

#ifndef	_CLOCK_T
#define _CLOCK_T
typedef	__darwin_clock_t	clock_t;
#endif

#ifndef	_SIZE_T
#define	_SIZE_T
typedef	__darwin_size_t		size_t;
#endif

#ifndef	_TIME_T
#define	_TIME_T
typedef	__darwin_time_t		time_t;
#endif

struct tm {
	int	tm_sec;		/* seconds after the minute [0-60] */
	int	tm_min;		/* minutes after the hour [0-59] */
	int	tm_hour;	/* hours since midnight [0-23] */
	int	tm_mday;	/* day of the month [1-31] */
	int	tm_mon;		/* months since January [0-11] */
	int	tm_year;	/* years since 1900 */
	int	tm_wday;	/* days since Sunday [0-6] */
	int	tm_yday;	/* days since January 1 [0-365] */
	int	tm_isdst;	/* Daylight Savings Time flag */
	long	tm_gmtoff;	/* offset from CUT in seconds */
	char	*tm_zone;	/* timezone abbreviation */
};

#if __DARWIN_UNIX03
#define CLOCKS_PER_SEC  1000000	/* [XSI] */
#else /* !__DARWIN_UNIX03 */
#include <machine/_limits.h>	/* Include file containing CLK_TCK. */

#define CLOCKS_PER_SEC  (__DARWIN_CLK_TCK)
#endif /* __DARWIN_UNIX03 */

#ifndef _ANSI_SOURCE
extern char *tzname[];
#endif

extern int getdate_err;
#if __DARWIN_UNIX03
//Begin-Libc
#ifndef LIBC_ALIAS_TIMEZONE
//End-Libc
extern long timezone __DARWIN_ALIAS(timezone);
//Begin-Libc
#else /* LIBC_ALIAS_TIMEZONE */
extern long timezone LIBC_ALIAS(timezone);
#endif /* !LIBC_ALIAS_TIMEZONE */
//End-Libc
#endif /* __DARWIN_UNIX03 */
extern int daylight;

__BEGIN_DECLS
char *asctime(const struct tm *);
//Begin-Libc
#ifndef LIBC_ALIAS_CLOCK
//End-Libc
clock_t clock(void) __DARWIN_ALIAS(clock);
//Begin-Libc
#else /* LIBC_ALIAS_CLOCK */
clock_t clock(void) LIBC_ALIAS(clock);
#endif /* !LIBC_ALIAS_CLOCK */
//End-Libc
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *getdate(const char *);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
//Begin-Libc
#ifndef LIBC_ALIAS_MKTIME
//End-Libc
time_t mktime(struct tm *) __DARWIN_ALIAS(mktime);
//Begin-Libc
#else /* LIBC_ALIAS_MKTIME */
time_t mktime(struct tm *) LIBC_ALIAS(mktime);
#endif /* !LIBC_ALIAS_MKTIME */
//End-Libc
//Begin-Libc
#ifndef LIBC_ALIAS_STRFTIME
//End-Libc
size_t strftime(char * __restrict, size_t, const char * __restrict, const struct tm * __restrict) __DARWIN_ALIAS(strftime);
//Begin-Libc
#else /* LIBC_ALIAS_STRFTIME */
size_t strftime(char * __restrict, size_t, const char * __restrict, const struct tm * __restrict) LIBC_ALIAS(strftime);
#endif /* !LIBC_ALIAS_STRFTIME */
//End-Libc
//Begin-Libc
#ifndef LIBC_ALIAS_STRPTIME
//End-Libc
char *strptime(const char * __restrict, const char * __restrict, struct tm * __restrict) __DARWIN_ALIAS(strptime);
//Begin-Libc
#else /* LIBC_ALIAS_STRPTIME */
char *strptime(const char * __restrict, const char * __restrict, struct tm * __restrict) LIBC_ALIAS(strptime);
#endif /* !LIBC_ALIAS_STRPTIME */
//End-Libc
time_t time(time_t *);

#ifndef _ANSI_SOURCE
void tzset(void);
#endif /* not ANSI */

/* [TSF] Thread safe functions */
char *asctime_r(const struct tm * __restrict, char * __restrict);
char *ctime_r(const time_t *, char *);
struct tm *gmtime_r(const time_t * __restrict, struct tm * __restrict);
struct tm *localtime_r(const time_t * __restrict, struct tm * __restrict);

#if !defined(_ANSI_SOURCE) && (!defined(_POSIX_C_SOURCE) || defined(_DARWIN_C_SOURCE))
time_t posix2time(time_t);
#if !__DARWIN_UNIX03
char *timezone(int, int);
#endif /* !__DARWIN_UNIX03 */
void tzsetwall(void);
time_t time2posix(time_t);
time_t timelocal(struct tm * const);
time_t timegm(struct tm * const);
#endif /* neither ANSI nor POSIX */

#if !defined(_ANSI_SOURCE)
//Begin-Libc
#ifndef LIBC_ALIAS_NANOSLEEP
//End-Libc
int nanosleep(const struct timespec *, struct timespec *) __DARWIN_ALIAS_C(nanosleep);
//Begin-Libc
#else /* LIBC_ALIAS_NANOSLEEP */
int nanosleep(const struct timespec *, struct timespec *) LIBC_ALIAS_C(nanosleep);
#endif /* !LIBC_ALIAS_NANOSLEEP */
//End-Libc
#endif
__END_DECLS

#ifdef _USE_EXTENDED_LOCALES_
#include <xlocale/_time.h>
#endif /* _USE_EXTENDED_LOCALES_ */

#endif /* !_TIME_H_ */
