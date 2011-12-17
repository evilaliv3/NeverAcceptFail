/*
 *   NEVER_ACCEPT_FAIL is a C Macro developed with aim to improve
 *   software security in critical circumstances.
 *   The Macro it's proposed as a POC (proof of concept), for situations
 *   where the computer programmer is completely self confident about the
 *   return value of a function an so wants to give a last resort
 *   in cases where the result doesn't match the expectations.
 *
 *   Copyright (C) 2010 evilaliv3 <giovanni.pellerano@evilaliv3.org>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *   Typical usage:
 *
 *       uint32_t critical_function(const char* par) {
 *           printf("hello world");
 *           return 1;
 *       }
 *
 *       NEVER_ACCEPT_FAIL(critical_function, 1, "poc example");
 *
 */

#ifndef NEVER_ACCEPT_FAIL_H
#define NEVER_ACCEPT_FAIL_H

#include <stdint.h>
#include <stdarg.h>
#include <time.h>

#define NSECS_PER_SEC 1000000000

#define NEVER_ACCEPT_FAIL(fun, test, ...)                                \
{                                                                        \
    struct timespec next;                                                \
    clock_gettime(CLOCK_REALTIME, &next);                                \
    uint32_t nsec = 1000;                                                \
    while(1) {                                                           \
        if((fun)(__VA_ARGS__) == (test))                                 \
            break;                                                       \
        else {                                                           \
            timespec_add_ns(&next, nsec);                                \
            clock_nanosleep(CLOCK_REALTIME, TIMER_ABSTIME, &next, NULL); \
        }                                                                \
        if( nsec <= NSECS_PER_SEC/2) nsec<<2;                            \
    }                                                                    \
}

#endif /* NEVER_ACCEPT_FAIL_H */
