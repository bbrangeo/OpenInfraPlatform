/*+============= THIS FILE CONTAINS SYSTEM DEPENDENT CODE ==============

  System Dependent Definitions                                  system.h

  COPYRIGHT (C) 1985-1999 interactive instruments GmbH Bonn

-*/
/*+---------------------------------------------------------------------
SYSTEM INCLUDE FILE ------------------------------------------ ERROR LOG

28.04.99  PORT TO ALPHA/XP OPENVMS

-*/

#ifndef SYSTEM

/***********************************************************************

   system.h defines a number of implementation-dependent constants,
   types, and macros. To help with the definition, each implementation
   is defined by its own .h file (e.g. vaxvms.h). A specific implemen-
   tation is selected by changing preprocessor constant SYSTEM in file
   systype.h. The following is a list of currently available implemen-
   tations.

*/

/* platform + development environment                                 */

#define OPENVMS   100
#define VAXVMS    101
#define AXPVMS    102

#define WANGVS    200

#define MS_DOS    300
#define MSVCD16   301
#define MSVCD32   302
#define WATCD16   311
#define WATCD32   312 

#define MSWIN     400
#define MSVCW16   401
#define MSVCW32S  402
#define WATCW16   411
#define WATCW32S  412

#define MSWINNT   500
#define MSVCWNT   501
#define WATCWNT   511

#define IBMOS2    600
#define WATCOS2   611

#define MACOS7    700

#define UNIX      800
#define ULTRIX    801
#define OSFONE    802


/*
   An implementation is defined by setting a number of preprocessor
   symbols in its .h file. The next sections describe the available
   features and the associated symbols in detail.

   SHORT_EXT is a preprocessor symbol that forces the generation
             of short names for external symbols (5 characters)
             when defined;

   ADDRESS   defines the addressing structure of the machine:
                LINEAR   address space is linear
                         i.e. contiguous, unsegmented, all
                         objects addressed uniformly
                SEGMENTED address space is segmented
*/
#define LINEAR    1
#define SEGMENTED 2

/*
   CHARSET   defines the character set available on a system:
                CONDIGIT   contiguous ascending digit codes
                CONALPHA   contiguous ascending alpha codes
                ASCII      system uses ASCII  character set
                EBCDIC     system uses EBCDIC character set
*/
#define CONDIGIT   64
#define CONALPHA  128

#define ASCII       (1|CONDIGIT|CONALPHA)
#define EBCDIC      (2|CONDIGIT)

/*
   CHARS_EX  defines the extension character set available on
             a system. Currently defined are:
             ISOLATIN    ISO Latin 1
             ECMA_94     ECMA-94 Latin (subset of ISO_LATIN)
             DECMULTI    DEC Multinational
             PC_437      IBM-PC (HP PC-8) character set
             PC_850      IBM-PC Multilingual (code page 850)
             ROMAN_8     Hewlett-Packard Roman-8 character set
             WANG_VS     WANG-VS extension character set
             WISCII      WANG PC interchange
             MACCHSET    Macintosh character set
*/

#define ISOLATIN  1
#define ECMA_94   2
#define DECMULTI  3
#define PC_437    4
#define PC_850    5
#define ROMAN_8   6
#define WANG_VS   7
#define WISCII    8
#define MACCHSET  9

/*

   UNCHAR   is a pseudo-character to introduce non-string data
            transported within strings;

   ARITH    defines the integer arithmetic type of the system:
               TWOCOM    2's complement
               ONECOM    1's complement
               SGNMAG    sign/magnitude
*/
#define TWOCOM 0
#define ONECOM 1
#define SGNMAG 2

/*
   CHASIG   if defined, char arithmetic is signed;

   MEMORY   defines the memory structure of the machine:
               BINSIZ    length of sizeof unit in bits is power of 2
               BININT    length of integer in bits is power of two
*/
#define BINSIZ 1
#define BININT 2

/*
   ANSI      if defined, means implementation is conforming to (propo-
             sed) ANSI C Standard. If this symbol is defined, none of
             the constants below need be defined, they are derived from
             the ANSI .h files.

   LIBRARY   defines structure of library:
               INC_MATH    math.h   present
               INC_STRING  string.h present
               INC_SIGNAL  signal.h present
               INC_VARARG  stdarg.h present
               INC_SETJMP  setjmp.h present
               INC_TIME    time.h   present
               INC_ASSERT  assert.h present
               INC_ERRNO   errno.h  present
               INC_ALL     all of above
               STD_LIB     stddef,stdio,ctype,stdlib.h present
*/
#define INC_MATH      1
#define INC_STRING    2
#define INC_SIGNAL    4
#define INC_VARARG    8
#define INC_SETJMP   16
#define INC_TIME     32
#define INC_ASSERT   64
#define INC_ERRNO   128

#define INC_ALL     255
#define STD_LIB   16384

/*
   COMPFAC   is a symbol defining available compiler facilities:
                sysBOOL     boolean data may be represented as enum
                sysCONST    const type qualifier supported
                sysENUMS    enumerated data types supported
                sysLODBL    compiler supports long double data type
                sysSIGND    compiler recognizes "signed" keyword
                sysSTRUC    structure passing, return and assignement
                            supported
                sysUCHAR    unsigned character supported
                sysVOID     (void *) supported
                sysVOLA     volatile type qualifier supported
             Facilities are defined by or'ing the applicable symbols
             of above list.
*/
#define sysENUMS     1
#define sysUCHAR     2
#define sysCONST     4
#define sysVOLA      8
#define sysVOID     16
#define sysSTRUC    32
#define sysBOOL     64
#define sysSIGND   128
#define sysLODBL   256

/*
   TALIGN    most restrictive alignment type;
   ALITOP    alignment exponent of this type;

   ALICHA    alignment exponent for character data types;
   BITCHA    number of bits per character (need not be specified if
             ANSI implementation);
   MAXCHA    maximum and
   MINCHA    minimum representable number in type "char";
             if the minimum corresponds to the setting in ARITH, it
             need not be specified (see below)
   MAXCHS    maximum and
   MINCHS    minimum representable number in type "signed char";
             if the minimum corresponds to the setting in ARITH, it
             need not be specified (see below)
   MAXCHU    maximum representable number in type "unsigned char";

   ALIINT    alignment exponent for int data types;
   CHRINT    number of characters per integer;
   BITINT    number of bits per integer/unsigned;
   MAXINT    maximum and
   MININT    minimum representable number in type "int";
             if the minimum corresponds to the setting in ARITH, it
             need not be specified (see below)
   MAXINU    maximum representable number in type "unsigned";

   ALISHO    alignment exponent for short data types;
   BITSHO    number of bits per (unsigned) short;
   MAXSHO    maximum and
   MINSHO    minimum representable number in type "short";
             if the minimum corresponds to the setting in ARITH, it
             need not be specified (see below)
   MAXSHU    maximum representable number in type "unsigned short";

   ALILNG    alignment exponent for long data types;
   BITLNG    number of bits per (unsigned) long;
   MAXLNG    maximum and
   MINLNG    minimum representable number in type "long";
             if the minimum corresponds to the setting in ARITH, it
             need not be specified (see below)
   MAXLNU    maximum representable number in type "unsigned long";

   ALIFLO    alignment exponent for float data type;
   MAXFLO    maximum and
   MINFLO    minimum positive number of type "float";

   PREFLO    precision of type "float" in significant decimal digits;

   EPSFLO    smallest number of type "float" such that 1.0 + EPSFLO
             is not equal to 1.0;

   MAXEFLO   maximum and
   MINEFLO   minimum exponent to power of ten allowed in
             "float" numbers;

   ALIDOU    alignment exponent for double data type;
   MAXDOU    maximum and
   MINDOU    minimum positive number of type "double";

   PREDOU    precision of type "double" in significant decimal digits;

   EPSDOU    smallest number of type "double" such that 1.0 + EPSDOU
             is not equal to 1.0

   MAXEDOU   maximum and
   MINEDOU   minimum exponent to power of ten allowed in
             "double" numbers;

   ALILDB    alignment exponent for long double data type;

------------------------------------------------------------------------
*/

/* Now find out what kind of system we are                            */
#include "systype.h"

/*======================================================================

   Get implementation definition file

------------------------------------------------------------------------
        VAX OpenVMS
*/
#if (SYSTEM==VAXVMS)
#include "vaxvms.h"
#endif

/*----------------------------------------------------------------------
        Alpha OpenVMS
*/
#if (SYSTEM==AXPVMS)
#include "axpvms.h"
#endif

/*----------------------------------------------------------------------
        WANG-VS with WANG C
*/
#if (SYSTEM==WANGVS)
#include "wangvs.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-DOS with MicroSoft Visual C 16 bit Large Model
*/
#if (SYSTEM==MSVCD16)
#include "msvcd16.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-DOS Extended with MicroSoft Visual C 32 bit Flat 
*/
#if (SYSTEM==MSVCD32)
#include "msvcd32.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-DOS Extended with WATCOM C 16 bit Large Model 
*/
#if (SYSTEM==WATCD16)
#include "watcd16.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-DOS Extended with WATCOM C 32 bit Flat
*/
#if (SYSTEM==WATCD32)
#include "watcd32.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-Windows NT with MS Visual C++ NT
*/
#if (SYSTEM==MSVCWNT)
#include "msvcwnt.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-Windows 3.1 / Win32S with MS Visual C++
*/
#if (SYSTEM==MSVCW32S)
#include "msvcw32s.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-Windows 3.1 / Win16 with MS Visual C++
*/
#if (SYSTEM==MSVCW16)
#include "msvcw16.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-Windows 3.1 / Win16 with WATCOM C/C++
*/
#if (SYSTEM==WATCW16)
#include "watcw16.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-Windows 3.1 / Win32s with WATCOM C/C++
*/
#if (SYSTEM==WATCW32S)
#include "watcw32s.h"
#endif

/*----------------------------------------------------------------------
        80x86 MS-Windows NT with WATCOM C/C++
*/
#if (SYSTEM==WATCWNT)
#include "watcwnt.h"
#endif

/*----------------------------------------------------------------------
        Macintosh OS 7 with Symantec Think C++ or Metrowerks CodeWarrior
*/
#if (SYSTEM==MACOS7)
#include "macos7.h"
#endif

/*----------------------------------------------------------------------
        Linux/CYGWIN with GCC
*/
#if (SYSTEM==CYGWIN || SYSTEM==GENERIC_LINUX)
#include "gcc.h"
#endif

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   Inclusion of optional facilities

-*/

#ifdef ANSI

#define  COMPFAC (sysENUMS|sysUCHAR|sysCONST|sysVOLA|sysVOID|sysSTRUC|sysBOOL|sysSIGND|sysLODBL)

#include <limits.h>
#include <float.h>

#define  LIBRARY (INC_ALL|STD_LIB)

#endif


/* include all standard headers if present                            */

#if (LIBRARY&STD_LIB)

#include <stddef.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#define  ABS

#endif


/*+=====================================================================

   ANSI derived definitions

-*/

#ifdef ANSI

#define   BITCHA  (CHAR_BIT)
#define   MAXCHA  (CHAR_MAX)
#define   MINCHA  (CHAR_MIN)
#define   MAXCHS  (SCHAR_MAX)
#define   MINCHS  (SCHAR_MIN)
#define   MAXCHU  (UCHAR_MAX)
#ifndef MAXINT
//#define   MAXINT  (INT_MAX)
#endif
#ifndef MININT
//#define   MININT  (INT_MIN)
#endif
#define   MAXINU  (UINT_MAX)
#define   MAXSHO  (SHRT_MAX)
#define   MINSHO  (SHRT_MIN)
#define   MAXSHU  (USHRT_MAX)
#define   MAXLNG  (LONG_MAX)
#define   MINLNG  (LONG_MIN)
#define   MAXLNU  (ULONG_MAX)

#define   MAXFLO  (FLT_MAX)
#define   MINFLO  (FLT_MIN)
#define   PREFLO  (FLT_DIG)
#define   EPSFLO  (FLT_EPSILON)
#define   MAXEFLO (FLT_MAX_10_EXP)
#define   MINEFLO (FLT_MIN_10_EXP)
#define   MAXDOU  (DBL_MAX)
#define   MINDOU  (DBL_MIN)
#define   PREDOU  (DBL_DIG)
#define   EPSDOU  (DBL_EPSILON)
#define   MAXEDOU (DBL_MAX_10_EXP)
#define   MINEDOU (DBL_MIN_10_EXP)

/* the terminal bell                                                  */
#ifndef BELL
#define   BELL    '\a'
#endif

#endif

#ifndef BELL
#if (CHARSET==ASCII)
#define BELL '\7'
#endif
#endif


/*+=====================================================================

   System-independently derived definitions

------------------------------------------------------------------------

   Determine low bounds for integer types and bounds for char if not
   done by ANSI or the implementation .h file.

-*/

#if (ARITH==TWOCOM)

#ifndef MINCHS
#define MINCHS (-MAXCHS-1)
#endif
#ifndef MININT
//#define MININT (-MAXINT-1)
#endif
#ifndef MINSHO
#define MINSHO (-MAXSHO-1)
#endif
#ifndef MINLNG
#define MINLNG (-MAXLNG-1L)
#endif

#endif


#if (ARITH==ONECOM)

#ifndef MINCHS
#define MINCHS (-MAXCHS)
#endif
#ifndef MININT
#define MININT (-MAXINT)
#endif
#ifndef MINSHO
#define MINSHO (-MAXSHO)
#endif
#ifndef MINLNG
#define MINLNG (-MAXLNG)
#endif

#endif


/*      character type minimum and maximum */

#ifdef  CHASIG

#ifndef MINCHA
#define MINCHA  MINCHS
#endif
#ifndef MAXCHA
#define MAXCHA  MAXCHS
#endif

#else

#ifndef MINCHA
#define MINCHA  0
#endif
#ifndef MAXCHA
#define MAXCHA  MAXCHU
#endif

#endif


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   Constants and macros for bitmaps realized as arrays of unsigned's
   Type definition for bitmaps

-*/

#if (MEMORY&BININT)

/* BABW      bits needed to address bits of an unsigned               */

#ifndef BABW

#if (BITINT==16)
#define BABW  4
#endif
#if (BITINT==32)
#define BABW  5
#endif
#if (BITINT==64)
#define BABW  6
#endif
#if (BITINT==128)
#define BABW  7
#endif

#endif

/*
   Bit-addressing macros

   wba(b)        word number corresponding to bit number b
   bba(b)        bit-in-word corresponding to bit number b
*/

#define wba(b)   ((b)>>BABW)
#define bba(b)   ((b)&~(~0<<BABW))

#else

#define wba(b)   ((b)/BITINT)
#define bba(b)   ((b)%BITINT)

#endif

#ifndef ANSI
#define U1      ((unsigned)1)
#define BMFULL (~(unsigned)0)
#else
#define U1       1U
#define BMFULL (~0U)
#endif

/*
   Bitmap sizing macro

   intpbf(nb)    number of unsigned's needed for nb bits
*/

#define intpbf(nb)  wba((nb)+BITINT-1)

/*
   Bitmap manipulation macros

   setbit(p,b)   set    bit b in bitmap addressed by p
   clrbit(p,b)   clear  bit b in bitmap addressed by p
   xorbit(p,b)   toggle bit b in bitmap addressed by p
   bitset(p,b)   test   bit b in bitmap addressed by p
*/

#define setbit(p,b)  ((p)[wba(b)]|=  U1<<bba(b)) 
#define clrbit(p,b)  ((p)[wba(b)]&=~(U1<<bba(b)))
#define xorbit(p,b)  ((p)[wba(b)]^=  U1<<bba(b))
#define bitset(p,b) (((p)[wba(b)]>>bba(b))&U1)

/*
   Bitmap type and alignment

   bitmap    typedef for one element of a bitmap array
   ALIBITMAP alignment exponent for bitmaps
*/
typedef unsigned  bitmap;
#define ALIBITMAP ALIINT


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   Type and synonyms for boolean data

-*/

#if (COMPFAC&sysBOOL && !defined(BOOLINT))

#undef   FALSE
#undef   TRUE
enum bools
       {
         FALSE = 0,  TRUE = 1,
         NO    = 0,  YES  = 1,
         OFF   = 0,  ON   = 1,
         CLEAR = 0,  SET  = 1,
         FAIL  = 0,  SUCC = 1
       };

#if (GENSYS!=MSWINNT || (!defined(II_USEMFC)&&!defined(II_DEFBOOL)))
#ifndef CYGWIN
typedef enum bools boolean;
#endif
//typedef enum bools bool;
#endif

#else

#ifdef  BOOLINT
#undef  BOOLINT
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define ON  TRUE
#define OFF FALSE

#define YES TRUE
#define NO  FALSE

#define SET   TRUE
#define CLEAR FALSE

#define SUCC TRUE
#define FAIL FALSE

typedef int boolean;
#ifndef __cplusplus
typedef int bool;
#endif

#endif


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   Computational macros

   min(a,b)    type-independent minimum of a and b
   max(a,b)    type-independent maximum of a and b
   absval(a)   type-independent absolute value of a
   sgnxfr(a,b) type-independent transfer of sign: a*sign(b)

   abs(a)      synonym for absval, if no standard library

-*/

#ifndef GENERIC_LINUX

#ifndef min
#define min(a,b) ((a)<(b)?(a):(b))
#endif

#ifndef max
#define max(a,b) ((a)>(b)?(a):(b))
#endif

#endif

#ifndef abs
#ifndef ABS
#define abs(x)   ((x)<0?-(x):(x))
#endif
#endif
#undef  ABS

#ifndef absval
#define absval(x)   ((x)<0?-(x):(x))
#endif

#ifndef sgnxfr
#define sgnxfr(a,b) ((b)<0?-(a):(a))
#endif


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   Single digit to character and back conversions

-*/

#if (CHARSET&CONDIGIT)

#define digint(c) ((int) ((c)-'0'))
#define intdig(i) ((char)((i)+'0'))

#endif


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   Computation of alignment

-*/

/* round sizeof(typ) to next higher multiple of most restrictive
   alignment type                                                     */
/*#define alignlen(typ) ( ((sizeof(typ)+sizeof(TALIGN)-1) \
                        / sizeof(TALIGN)) * sizeof(TALIGN) )          */

/* round any length or offset l to next boundary for
   alignment exponent a                                               */
/*#define align(l,a)    (((l)-1+(1<<(a))) & ((~0)<<(a)))              */


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   Addressing types and macros

-*/

typedef char        memory;          /* type for unstructured memory  */

#ifdef  ANSI

typedef size_t      memlen;          /* amount of memory type */
typedef ptrdiff_t   memoff;          /* signed type for pointer diff */

#else

typedef unsigned    memlen;          /* amount of memory type */
typedef int         memoff;          /* signed type for pointer diff */

#endif


#if (!(COMPFAC&sysVOID))
#define void        char
#endif

#define notype      void             /* empty set type                */
/* intended is ... typedef void notype;  which does not work          */
typedef notype *    pointer;         /* address type                  */

#define addr(p)  ((pointer)(p))


#ifndef NULL
#define NULL     ((pointer)0)
#endif

#ifndef offsetof

#if  (ADDRESS&LINEAR)
#define offsetof(typ,id) ((memlen)(&((typ *)NULL)->id))
#endif

#endif

#if (!(COMPFAC&sysCONST))
#define const
#endif

#if (!(COMPFAC&sysVOLA))
#define volatile
#endif

#if (!(COMPFAC&sysSIGND))
#define signed
#endif


#if (COMPFAC&sysLODBL)
typedef long double   ldouble;
#else
typedef double        ldouble;
#endif


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

   Message system interface

-*/

typedef short    msg_CODE;    /* error codes */
typedef notype  *msg_FAC;     /* facility id */


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

  Various shorthands

-*/

#define forever for (;;)

#if (COMPFAC&sysUCHAR)
typedef unsigned char char_u;
#endif

/**********************************************************************/

/*
  Use global data in DLL's (MS Windows environments only)

  Define the preprocessor symbol USEDLLDATA to let the 
  compiler treat the exported data objects of various
  facilities as being contained in a DLL.
  The specifications below are only valid in MS Visual C
  and Watcom C environments. Else the preprocessor symbols
  DLLEXPORT and DLLIMPORT are defined but empty.
*/

#define DLLEXPORT
#define DLLIMPORT
#define CCONV
#define CCONVEXP

#if (defined(USEDLLDATA) && (GENSYS==MSWIN || GENSYS==MSWINNT))

#undef DLLEXPORT
#undef DLLIMPORT

#if (SYSTEM==MSVCWNT || SYSTEM==MSVCW32S)
#define DLLEXPORT   __declspec(dllexport)
#define DLLIMPORT   __declspec(dllimport)
#endif

#if (SYSTEM==MSVCW16)
#define DLLEXPORT   __far
#define DLLIMPORT   __far
#endif

#if (SYSTEM==WATCWNT || SYSTEM==WATCW32S || SYSTEM==WATCW16)
#define DLLEXPORT   __export __far
#define DLLIMPORT   __far

#undef  CCONV
#undef  CCONVEXP
#define CCONV       __cdecl
#define CCONVEXP    __cdecl __export
#endif

#endif

/*
  Undefine Compiler facilities
*/
#undef sysCOMPFAC
#undef sysENUMS
#undef sysUCHAR
#undef sysCONST
#undef sysVOLA
#undef sysVOID
#undef sysSTRUC
#undef sysBOOL
#undef sysSIGND
#undef sysLODBL

/*
  For MS Windows flavors, include API definitions
*/
#if (GENSYS==MSWIN || (GENSYS==MSWINNT && !defined(II_USEMFC)))
#ifndef boolean
#define boolean WINBOOL
#include <windows.h>
#undef boolean
#endif
#elif (SYSTEM!=LINUX)
#include <windows.h>
#endif

#endif
