#ifndef fisHFILE
#ifdef __cplusplus
extern "C" {
#endif
#ifdef SHORT_EXT
#define fisOpen  fisO0
#define fisClose fisC0
#define fisRwind fisR0
#define fisError fisE0
#endif
#ifdef ANSI
FILE *   CCONV  fisOpen(  char *fn, int opt );
void     CCONV  fisClose( FILE *fp );
void     CCONV  fisRwind( FILE *fp );
msg_CODE CCONV  fisError( void );
#else
FILE *   CCONV  fisOpen( );
void     CCONV  fisClose( );
void     CCONV  fisRwind( );
msg_CODE CCONV  fisError( );
#endif
#define fisOLD       0
#define fisNEW       1
#define fisAPPND     2
#define fisCOND      4
#define fisSCRAT     8
#define fisDUMMY    16
#define fisREAD     32
#define fisWRITE    64
#define fisBIN     128
#define fisINPUT  (fisOLD)
#define fisOUTPT  (fisNEW|fisCOND)
#ifdef __cplusplus
}
#endif
#define fisHFILE 1
#endif
