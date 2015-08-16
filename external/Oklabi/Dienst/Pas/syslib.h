#if (INCLUDE&INC_MATH)
#ifndef  MATH_H
#if (LIBRARY&INC_MATH)
#include <math.h>
#ifndef PI
#define PI   3.141592653589793
#endif
#if (SYSTEM==WANGVS)
#undef  abs
#undef  fabs
#define abs(a)  absval(a)
#define fabs(a) absval(a)
#endif
#endif
#define  MATH_H
#endif
#endif
#if (INCLUDE&INC_STRING)
#ifndef  STRING_H
#if (LIBRARY&INC_STRING)
#include <string.h>
#if (SYSTEM==WANGVS)
#include <memory.h>
#define memmove(a,b,c) memcpy(a,b,c)
#endif
#endif
#define  STRING_H
#endif
#endif
#if (INCLUDE&INC_VARARG)
#ifndef  VARARG_H
#if (LIBRARY&INC_VARARG)
#include <stdarg.h>
#endif
#define  VARARG_H
#endif
#endif
#if (INCLUDE&INC_SIGNAL)
#ifndef  SIGNAL_H
#if (LIBRARY&INC_SIGNAL)
#include <signal.h>
#endif
#define  SIGNAL_H
#endif
#endif
#if (INCLUDE&INC_SETJMP)
#ifndef  SETJMP_H
#if (LIBRARY&INC_SETJMP)
#include <setjmp.h>
#endif
#define  SETJMP_H
#endif
#endif
#if (INCLUDE&INC_TIME)
#ifndef  TIME_H
#if (LIBRARY&INC_TIME)
#include <time.h>
#if (SYSTEM==WANGVS)
typedef long time_t;
#endif
#endif
#define  TIME_H
#endif
#endif
#if (INCLUDE&INC_ASSERT)
#ifndef  ASSERT_H
#if (LIBRARY&INC_ASSERT)
#include <assert.h>
#endif
#define  ASSERT_H
#endif
#endif
#if (INCLUDE&INC_ERRNO)
#ifndef  ERRNO_H
#if (LIBRARY&INC_ERRNO)
#include <errno.h>
#endif
#define  ERRNO_H
#endif
#endif
#undef INCLUDE
