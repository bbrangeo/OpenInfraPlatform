#include "system.h"
#define  INCLUDE INC_SETJMP
#include "syslib.h"
#include "mem.h"
#include "obj.h"
#include "str.h"
#include "pas_msg.h"
#include "pas.h"
#include "pasmsg.h"
typedef
   pas_FRH *Ptt;
typedef struct axl
   {
     struct axl      *axl;
     pas_PN           pnr;
     pas_AN           aps;
     short            fac;
   } Anxle;
typedef struct pas_FILE
   {
     struct pas_FRH  *wip;
     pas_LINK         wbq;
     pas_LINK        *bfh;
     int              bfc;
     int              npg;
     Ptt             *ptt;
     int              ntt;
     int              ltt;
     pas_FRH         *pab;
     int              hbs;
     bitmap           map;
     Anxle           *axl;
     Anxle           *axe;
     pas_OTY          acc;
     obj             *nam;
     int              hpn;
     struct Sfb      *asf;
#if (SYSTEM==WANGVS)
     struct Sfb     **sfb ;
     short            nas ;
     short            nus ;
     long             npf ;
#else
     struct Sfb      *sfb;
#endif
   } Pfb;
typedef struct
   {
     pointer          adr;
     int              nfr;
   } Ppds;
#ifdef ANSI
void      pasiopen( Pfb *pfb );
void      pasiclse( Pfb *pfb );
void      pasiread( Pfb *pfb, int asy, pas_PN pn, pas_FR *ppf );
void      pasiwrte( Pfb *pfb, int asy, pas_PN pn, pas_FR *ppf );
void      pasiwait( Pfb *pfb );
pointer   pasigpag( int  nr,  int *na );
void      pasifpag( pointer p,int np );
#else
void      pasiopen();
void      pasiclse();
void      pasiread();
void      pasiwrte();
void      pasiwait();
pointer   pasigpag();
void      pasifpag();
#endif
typedef enum
   {
     INF = 1,
     WRN = 2,
     FTL = 3
   } Sevrty;
#ifdef ANSI
void      paserrm(  Sevrty sev, msg_CODE msgc );
void      paserrf(  Sevrty sev, msg_CODE msgc, Pfb *fid );
void      paserrf2( Sevrty sev, msg_CODE msgc, Pfb *fid, obj *str );
void      paserrs(  Sevrty sev, msg_CODE msgc, obj *str );
void      paserr(   Sevrty sev );
#else
void      paserrf2();
void      paserrf();
void      paserrm();
void      paserrs();
void      paserr();
#endif
