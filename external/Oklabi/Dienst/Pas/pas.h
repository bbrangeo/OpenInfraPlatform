#ifndef pasHFILE
#ifdef __cplusplus
extern "C" {
#endif
#include "obj.h"
#include "mem.h"
#if defined(SYSPAGESIZE) && (SYSPAGESIZE>=512)
#define pasPSIZ   SYSPAGESIZE
#else
#define pasPSIZ   2048
#endif
#ifdef SHORT_EXT
#define   pasOfi   pasO0
#define   pasCfi   pasC0
#define   pasUps   pasU0
#define   pasAae   pasA0
#define   pasAo    pasA1
#define   pasAn    pasA2
#define   pasA     pasA3
#define   pasD     pasD0
#define   pasL     pasL0
#define   pasU     pasU0
#define   pasFae   pasF0
#define   pasSae   pasS0
#define   pasQae   pasQ0
#define   pasQfn   pasQ1
#define   pasQfa   pasQ2
#define   pasQfp   pasQ3
#define   pasWsl   pasW0
#define   pasWps   pasW1
#endif
#define pasWRITE  1
#define pasCREATE 2
#define pasDELETE 4
typedef enum
   {
     pasOLDRO = 0,
     pasOLD  = pasWRITE,
     pasNEW  = pasWRITE | pasCREATE,
     pasTEMP = pasWRITE | pasCREATE | pasDELETE
   }
     pas_OTY;
typedef enum
   {
     pasMRU = 4,
     pasLRU = 3,
     pasUSE = 2,
     pasDEL = 1
   }
     pas_DISP;
typedef struct pas_FILE *
     pas_FID;
typedef unsigned long
     pas_PN;
typedef unsigned short
     pas_AN;
typedef struct pas_LINK
   {
     struct pas_LINK *fwd;
     struct pas_LINK *bck;
   }
     pas_LINK;
typedef struct pas_FRM
   {
      struct pas_FRH   *phd;
      TALIGN            data;
   } pas_FRM;
typedef union
   {
     memory            frame[pasPSIZ];
     pas_FRM           pfr;
   } 
     pas_FR;
typedef struct pas_FRH
   {
     pas_LINK          lnk;
     struct pas_FRH   *pqt;
     void            (*ruex)(void*);
     pas_PN            pnr;
     pas_FID           fid;
     pas_FR           *ppg;
     pointer           ctx;
     unsigned short    acnt;
     unsigned short    lcnt;
     char_u            cbts;
#define                  pasMODIF  1
#define                  pasUNLOA  2
#define                  pasDELET  4
     char_u            disp;
   }
     pas_FRH;
#define pasDATA  offsetof(struct pas_FRM,data)
#define pasHDR(pa) (((struct pas_FRM *)((memory *)(pa)-pasDATA))->phd)
#define pasDSIZ  (pasPSIZ-pasDATA)
#ifdef ANSI
boolean   pasOfi( const char *fname, pas_OTY otype, pas_FID *fid );
boolean   pasCfi( pas_FID fid );
boolean   pasUps( pas_FID fid, pointer mtc, boolean mde );
boolean   pasAae( pas_FID fid, pas_AN *aen );
boolean   pasFae( pas_FID fid, pas_AN  aen );
boolean   pasSae( pas_FID fid, pas_AN  aen, memlen lae, pointer pae );
boolean   pasQae( pas_FID fid, pas_AN  aen, memlen lae, pointer pae );
boolean   pasAo(  pas_FID fid, pas_PN  pnr, pointer *pfa );
boolean   pasAn(  pas_FID fid, pas_PN *pnr, pointer *pfa );
boolean   pasA(   pointer pfa );
boolean   pasD(   pointer pfa, pas_DISP disp );
boolean   pasL(   pointer pfa );
boolean   pasU(   pointer pfa );
obj      *pasQfn( pas_FID fid );
pas_OTY   pasQfa( pas_FID fid );
boolean   pasQfp( pas_FID fid, pas_PN  pnr, pointer *pfa );
void      pasWsl( unsigned lim );
void      pasWps( double *hr, unsigned *np );
#else
boolean   pasOfi( );
boolean   pasCfi( );
boolean   pasUps( );
boolean   pasAae( );
boolean   pasFae( );
boolean   pasSae( );
boolean   pasQae( );
boolean   pasAo( );
boolean   pasAn( );
boolean   pasA( );
boolean   pasD( );
boolean   pasL( );
boolean   pasU( );
obj      *pasQfn();
pas_OTY   pasQfa();
boolean   pasQfp();
void      pasWsl();
void      pasWps();
#endif
#define pasSrx(pfa,ru)   (pasHDR(pfa)->ruex = (ru))
#define pasSwt(pfa)      (pasHDR(pfa)->cbts |= pasMODIF)
#define pasSuc(pfa,id)   (pasHDR(pfa)->ctx = addr(id))
#define pasSds(pfa)      ((int)(pasHDR(pfa)->cbts |= pasDELET))
#define pasCds(pfa)      ((int)(pasHDR(pfa)->cbts &= ~pasDELET))
#define pasQrx(pfa)      (pasHDR(pfa)->ruex)
#define pasQwt(pfa)      ((int)(pasHDR(pfa)->cbts & pasMODIF))
#define pasQfi(pfa)      (pasHDR(pfa)->fid)
#define pasQpn(pfa)      (pasHDR(pfa)->pnr)
#define pasQuc(pfa)      (pasHDR(pfa)->ctx)
#define pasQul(pfa)      ((int)(pasHDR(pfa)->cbts & pasUNLOA))
#define pasQds(pfa)      ((int)(pasHDR(pfa)->cbts & pasDELET))
#define  pasANCBTR   2
#define  pasANCRES   3
#define  pasANCRNK   4
#define  pasANCSTG   5
#define  pasANCSDS   9
#ifdef __cplusplus
}
#endif
#define pasHFILE 1
#endif
