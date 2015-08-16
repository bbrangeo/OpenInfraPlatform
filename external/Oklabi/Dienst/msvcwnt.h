/*+============= THIS FILE CONTAINS SYSTEM DEPENDENT CODE ==============

  System Dependent Definitions                                 msvcwnt.h

  for C SYSTEM (80x86 MS-Windows NT with Microsoft Visual C++)

  COPYRIGHT (C) 1995 interactive instruments GmbH Bonn

-*/

/*      system family                                                 */
#define GENSYS  MSWIN

/*      addressing structure                                          */
#define ADDRESS LINEAR


/*      character set                                                 */
#define CHARSET  ASCII
#define CHARS_EX ECMA_94
#define UNCHAR   '\377'


/*      integer arithmetic                                            */
#define ARITH   TWOCOM
#define CHASIG


/*      memory structure                                              */
#define MEMORY  (BINSIZ|BININT)

#define CHRINT  4         /* chars per int */

#define BITINT  32        /* bits per int   */
#define BITSHO  16        /* bits per short */
#define BITLNG  32        /* bits per long  */

#define ALICHA  0         /* align for char   */
#define ALISHO  1         /* align for short  */
#define ALIINT  1         /* align for int    */
#define ALILNG  1         /* align for long   */
#define ALIFLO  1         /* align for float  */
#define ALIDOU  1         /* align for double */
#define ALILDB  1         /* align for long double */

#define TALIGN  int       /* most restrictive alignment type */
#define ALITOP  1


/*     define size of system's memory pages                           */
#define SYSPAGESIZE   4096


/*      compiler and library facilities                               */
