#ifndef memHFILE
#ifdef __cplusplus
extern "C" {
#endif
#define  INCLUDE INC_STRING
#include "syslib.h"
#include "chc.h"
#ifdef SHORT_EXT
#define   memAlloc  memAl
#define   memRaloc  memRa
#define   memFree   memFr
#define   memErrmd  memEr
#define   memCopy   memCo
#define   memMvpad  memMv
#define   memXlte   memXl
#define   memFind   memFi
#define   memComp   memCp
#define   memCompu  memCu
#define   memCompc  memCc
#define   memSpan   memSp
#define   memScan   memSc
#define   memSkip   memSk
#define   memStn    memSn
#define   memMove   memMo
#define   memLoc    memLo
#define   memFill   memFl
#define   memTest   memTe
#define   memUpper  memUp
#define   memLower  memLw
#define   stnCopy   stnCo
#define   stnXlte   stnXl
#define   stnCompu  stnCu
#define   stnCompc  stnCc
#define   stnSpan   stnSp
#define   stnScan   stnSc
#define   stnSkip   stnSk
#define   stnLen    stnLn
#define   stnMove   stnMo
#define   stnLoc    stnLo
#define   stnFind   stnFi
#define   stnTest   stnTe
#define   stnUpper  stnUp
#define   stnLower  stnLw
#endif
#ifdef ANSI
void    CCONV memErrmd( int     emd );
pointer CCONV memAlloc( memlen  nbytes );
pointer CCONV memRaloc( pointer pmem, memlen nbytes );
void    CCONV memFree(  pointer pmem );
pointer CCONV memCopy(  pointer ps, pointer pt, memlen  l );
void    CCONV memMvpad( pointer ps, memlen  ls,
                        pointer pt, memlen  lt, int c );
pointer CCONV memXlte(  pointer ps, pointer pt, memlen l, pointer px );
pointer CCONV memFind(  pointer ps, memlen  ls, pointer pf, memlen lf );
int     CCONV memComp(  pointer p1, memlen  l1, pointer p2, memlen l2 );
int     CCONV memCompu( pointer p1, memlen  l1, pointer p2, memlen l2 );
int     CCONV memCompc( pointer p1, memlen  l1,
                        pointer p2, memlen  l2, const char_u *co );
pointer CCONV memSpan(  pointer ps, memlen  ls, pointer pc, memlen lc );
pointer CCONV memScan(  pointer ps, memlen  ls, pointer pc, memlen lc );
pointer CCONV memSkip(  pointer ps, memlen  l,  int c );
pointer CCONV memExam(  pointer ps, memlen  l,  int c );
pointer CCONV memVeri(  pointer ps, memlen  l,  int c );
#else
void    CCONV memErrmd();
pointer CCONV memAlloc();
pointer CCONV memRaloc();
void    CCONV memFree();
pointer CCONV memCopy();
void    CCONV memMvpad();
pointer CCONV memXlte();
pointer CCONV memFind();
int     CCONV memComp();
int     CCONV memCompu();
int     CCONV memCompc();
pointer CCONV memSpan();
pointer CCONV memScan();
pointer CCONV memSkip();
pointer CCONV memExam();
pointer CCONV memVeri();
#endif
#define   memStn(ps,l)        (*((char *)(ps)+(l)) = '\0')
#define   memMove(ps,pt,l)    memmove(pt,ps,l)
#define   memLoc(ps,l,c)      memchr(ps,c,l)
#define   memFill(pt,l,c)     memset(pt,c,l)
#define   memTest(p1,p2,l)    (memcmp(p1,p2,l)!=0)
#define   memUpper(ps,pt,l)   memXlte((ps),(pt),(l),(pointer)chc_pupr)
#define   memLower(ps,pt,l)   memXlte((ps),(pt),(l),(pointer)chc_plor)
#ifdef ANSI
char *  CCONV stnCopy(  char   *ps, char   *pt );
char *  CCONV stnXlte(  char   *ps, char   *pt, char   *px );
int     CCONV stnCompu( pointer p1, pointer p2 );
int     CCONV stnCompc( pointer p1, pointer p2, const char_u *co );
char *  CCONV stnSpan(  char   *ps, char   *pc );
char *  CCONV stnSkip(  char   *ps, int     c );
char *  CCONV stnExam(  char   *ps, int     c );
char *  CCONV stnVeri(  char   *ps, int     c );
#else
char *  CCONV stnCopy();
char *  CCONV stnXlte();
int     CCONV stnCompu();
int     CCONV stnCompc();
char *  CCONV stnSpan();
char *  CCONV stnSkip();
char *  CCONV stnExam();
char *  CCONV stnVeri();
#endif
#define   stnLen(s)           strlen(s)
#define   stnMove(ps,pt)      strcpy(pt,ps)
#define   stnLoc(ps,c)        strchr(ps,c)
#define   stnScan(p1,p2)      strpbrk(p1,p2)
#define   stnTest(p1,p2)      (strcmp(p1,p2)!=0)
#define   stnUpper(ps,pt)     stnXlte((ps),(pt),(pointer)chc_pupr)
#define   stnLower(ps,pt)     stnXlte((ps),(pt),(pointer)chc_plor)
#if (GENSYS==OPENVMS || SYSTEM==WANGVS)
#ifdef ANSI
char     *stnFind( char *ps, char *pf );
#else
char     *stnFind();
#endif
#else
#define   stnFind(p1,p2)      strstr(p1,p2)
#endif
#define   memsiz(x)  ((memlen)sizeof(x))
#define   memAlobj(typ)   ((typ *) memAlloc( memsiz(typ) ))
#define   memRlobj(typ,p) ((typ *) memRaloc( (pointer)(p),memsiz(typ) )) 
#define   MEMVAR   1
#define memvarsize(typ,vt,n) \
        ((memlen)((long)memsiz(typ)+(long)memsiz(vt)*((long)n-MEMVAR)))
#define   memAlvar(typ,vt,n)   ((typ *)memAlloc(memvarsize(typ,vt,n)))
#define   memRlvar(typ,vt,n,p) ((typ *)memRaloc((pointer)(p),\
                                                memvarsize(typ,vt,n)))
#define   memFrobj(p)    (memFree((pointer)p))
#ifdef ANSI
int CCONV memHpchk( FILE *fout );
int CCONV memHpdmp( FILE *fout );
int CCONV memHpfil( FILE *fout, int fill_char );
#else
int CCONV memHpchk();
int CCONV memHpdmp();
int CCONV memHpfil();
#endif
#ifdef __cplusplus
}
#endif
#define memHFILE 1
#endif
