#ifndef objHFILE
#ifdef __cplusplus
extern "C" {
#endif
typedef struct
   {
     pointer    pdata;
     int        accnt;
   }
                obj;
#define objData(po) ((po)->pdata) 
#ifdef SHORT_EXT
#define objCr   objC0
#define objCra  objC1
#define objMk   objM0
#define objMka  objM1
#define objMkd  objM2
#define objMkda objM3
#define objUnmk objU0
#define objAcc  objA0
#define objDea  objD0
#define objDeac objD1
#define objDeat objD2
#define objSub  objS0
#define objSubd objS1
#define objSps  objS2
#endif
#ifdef ANSI
obj *   CCONV objCr(   memlen  nbytes );
obj *   CCONV objCra(  memlen  nbytes );
obj *   CCONV objMk(   pointer pmem );
obj *   CCONV objMkd(  pointer pmem );
obj *   CCONV objMka(  pointer pmem );
obj *   CCONV objMkda( pointer pmem );
pointer CCONV objUnmk( obj *pobj );
obj *   CCONV objAcc(  obj *pobj );
obj *   CCONV objDea(  obj *pobj );
obj *   CCONV objDeac( obj *pobj, void CCONV (*fdea)( int, pointer ),
                                  void CCONV (*fdel)( int, pointer ) );
obj *   CCONV objDeat( obj *pobj );
obj *   CCONV objSub(  obj *pobj, pointer pmem );
obj *   CCONV objSubd( obj *pobj, pointer pmem );
void    CCONV objSps(  long siz );
#else
obj *   CCONV objCr();
obj *   CCONV objCra();
obj *   CCONV objMk();
obj *   CCONV objMka();
obj *   CCONV objMkd();
obj *   CCONV objMkda();
pointer CCONV objUnmk();
obj *   CCONV objAcc();
obj *   CCONV objDea();
obj *   CCONV objDeac();
obj *   CCONV objDeat();
obj *   CCONV objSub();
obj *   CCONV objSubd();
void    CCONV objSps();
#endif
#ifdef ANSI
#define objNDELH ((void CCONV (*)( int, pointer ))NULL)
#else
#define objNDELH ((void CCONV (*)())NULL)
#endif
#ifdef __cplusplus
}
#endif
#define objHFILE 1
#endif
