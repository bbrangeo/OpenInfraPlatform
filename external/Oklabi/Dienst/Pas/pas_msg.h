#ifndef msgHFILE
#ifdef __cplusplus
extern "C" {
#endif
#include "obj.h"
#define NORMAL   ((msg_CODE)0)
#define msgINFO  0
#define msgWARN  1
#define msgERROR 2
#define msgFATAL 3
#ifdef SHORT_EXT
#define msgPut   msgP0
#define msgPut1  msgP1
#define msgPut2  msgP2
#define msgPutn  msgP3
#define msgOff   msgO0
#define msgOn    msgO1
#define msgInarg msgI0
#define msgDisp  msgD0
#define msgBeep  msgB0
#define msgLog   msgL0
#endif
#ifdef ANSI
typedef   void CCONV (*msg_LOGF)( char *msg );
void  CCONV msgPut(   msg_FAC fac, msg_CODE erc );
void  CCONV msgPut1(  msg_FAC fac, msg_CODE erc, obj *pobj );
void  CCONV msgPut2(  msg_FAC fac, msg_CODE erc, obj *pobj1, obj *pobj2 );
void  CCONV msgPutn(  msg_FAC fac, msg_CODE erc, int  nobj,  obj *apobj[] );
obj * CCONV msgInarg( msg_FAC fac, msg_CODE erc );
void  CCONV msgOff(   int sev );
void  CCONV msgOn(    void );
void  CCONV msgDisp(  void );
void  CCONV msgBeep(  void );
#ifdef II_DEFBOOL
void  CCONV msgLog(   msg_LOGF lgf, int mod );
#else
void  CCONV msgLog(   msg_LOGF lgf, boolean mod );
#endif
#else
typedef   void CCONV (*msg_LOGF)();
void  CCONV msgPut();
void  CCONV msgPut1();
void  CCONV msgPut2();
void  CCONV msgPutn();
void  CCONV msgOff();
void  CCONV msgOn();
obj * CCONV msgInarg();
void  CCONV msgDisp();
void  CCONV msgBeep();
void  CCONV msgLog();
#endif
#ifdef __cplusplus
}
#endif
#define msgHFILE 1
#endif
