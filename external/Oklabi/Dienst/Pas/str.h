#ifndef strHFILE
#ifdef __cplusplus
extern "C" {
#endif
#include "obj.h"
#define strData(po) ((char *)objData(po))
#ifdef SHORT_EXT
#define strMk     strM0
#define strCr     strC0
#define strCrc    strC1
#define strCrnul  strC2
#define strCrsub  strC3
#define strCrint  strC4
#define strCrlng  strC5
#define strLeng   strL0
#define strConc   strC9
#define strFind   strF0
#define strFindc  strF1
#define strSubsn  strS0
#define strPrint  strP0
#endif
#ifdef ANSI
obj  * CCONV strMk(    char *ps );
obj  * CCONV strCr( const char *ps );
obj  * CCONV strCrc(   char  c );
obj  * CCONV strCrnul( void );
obj  * CCONV strCrsub( obj  *pso, unsigned i, memlen l );
obj  * CCONV strCrint( int   iv );
obj  * CCONV strCrlng( long  lv );
memlen CCONV strLeng(  obj  *pso );
obj  * CCONV strConc(  obj  *ps1, obj  *ps2 );
char * CCONV strFind(  obj  *pso, char *ps );
char * CCONV strFindc( obj  *pso, char  c );
obj  * CCONV strSubsn( obj  *pso, char  ai, char at, int nobj,
                       obj  *apobj[] );
void   CCONV strPrint( FILE *fil, obj  *pso );
#else
obj  * CCONV strMk();
obj  * CCONV strCr();
obj  * CCONV strCrc();
obj  * CCONV strCrnul();
obj  * CCONV strCrsub();
obj  * CCONV strCrint();
obj  * CCONV strCrlng();
memlen CCONV strLeng();
obj  * CCONV strConc();
char * CCONV strFind();
char * CCONV strFindc();
obj  * CCONV strSubsn();
void   CCONV strPrint();
#endif
#ifdef __cplusplus
}
#endif
#define strHFILE 1
#endif
