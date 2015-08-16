#ifndef chcHFILE
#ifdef __cplusplus
extern "C" {
#endif
typedef struct
   {
     char_u     upr[MAXCHU+2];
     char_u     lor[MAXCHU+2];
     short      typ[MAXCHU+2];
     char_u     col[MAXCHU+2];
   } chc_TABLE;
#if (SYSTEM==MSVCWNT || SYSTEM==MSVCW32S)
extern const char_u    DLLIMPORT  *chc_pupr;
extern const char_u    DLLIMPORT  *chc_plor;
extern const short     DLLIMPORT  *chc_ptyp;
extern const char_u    DLLIMPORT  *chc_pcol;
#else
extern const char_u  * DLLIMPORT   chc_pupr;
extern const char_u  * DLLIMPORT   chc_plor;
extern const short   * DLLIMPORT   chc_ptyp;
extern const char_u  * DLLIMPORT   chc_pcol;
#endif
#ifdef SHORT_EXT
#define chc_pupr   chcUP
#define chc_plor   chcLO
#define chc_ptyp   chcTY
#define chc_pcol   chcCO
#endif
#define chcUPPER    1
#define chcLOWER    2
#define chcHXDIG    4
#define chcDIGIT    8
#define chcPUNCT   16
#define chcSPACE   32
#define chcWHITE   64
#define chcCNTRL  128
#define chcXTUPP  256
#define chcXTLOW  512
#define chcXTCNT 1024
#define chcXTPRI 2048
#define chcALPHA (chcUPPER|chcLOWER)
#define chcALNUM (chcUPPER|chcLOWER|chcDIGIT)
#define chcGRAPH (chcUPPER|chcLOWER|chcDIGIT|chcPUNCT)
#define chcPRINT (chcUPPER|chcLOWER|chcDIGIT|chcPUNCT|chcSPACE)
#define chcXTALP (chcXTUPP|chcXTLOW)
#define chcXTGRA (chcXTUPP|chcXTLOW|chcXTPRI)
#ifdef  isalnum
#undef  isalnum
#endif
#define isalnum(c)  (chc_ptyp[(int)(c)] & chcALNUM)
#ifdef  isalpha
#undef  isalpha
#endif
#define isalpha(c)  (chc_ptyp[(int)(c)] & chcALPHA)
#ifdef  iscntrl
#undef  iscntrl
#endif
#define iscntrl(c)  (chc_ptyp[(int)(c)] & (chcCNTRL|chcWHITE))
#ifdef  isdigit
#undef  isdigit
#endif
#define isdigit(c)  (chc_ptyp[(int)(c)] & chcDIGIT)
#ifdef  isgraph
#undef  isgraph
#endif
#define isgraph(c)  (chc_ptyp[(int)(c)] & chcGRAPH)
#ifdef  islower
#undef  islower
#endif
#define islower(c)  (chc_ptyp[(int)(c)] & chcLOWER)
#ifdef  isprint
#undef  isprint
#endif
#define isprint(c)  (chc_ptyp[(int)(c)] & chcPRINT)
#ifdef  ispunct
#undef  ispunct
#endif
#define ispunct(c)  (chc_ptyp[(int)(c)] & chcPUNCT)
#ifdef  isspace
#undef  isspace
#endif
#define isspace(c)  (chc_ptyp[(int)(c)] & (chcWHITE|chcSPACE))
#ifdef  isupper
#undef  isupper
#endif
#define isupper(c)  (chc_ptyp[(int)(c)] & chcUPPER)
#ifdef  isxdigit
#undef  isxdigit
#endif
#define isxdigit(c) (chc_ptyp[(int)(c)] & chcHXDIG)
#ifdef  tolower
#undef  tolower
#endif
#define tolower(c)  (chc_plor[(int)(c)])
#ifdef  toupper
#undef  toupper
#endif
#define toupper(c)  (chc_pupr[(int)(c)])
#ifdef  isAlnum
#undef  isAlnum
#endif
#define isAlnum(c)  (chc_ptyp[(int)(c)] & (chcALNUM|chcXTALP))
#ifdef  isAlpha
#undef  isAlpha
#endif
#define isAlpha(c)  (chc_ptyp[(int)(c)] & (chcALPHA|chcXTALP))
#ifdef  isCntrl
#undef  isCntrl
#endif
#define isCntrl(c)  (chc_ptyp[(int)(c)] & (chcCNTRL|chcWHITE|chcXTCNT))
#ifdef  isGraph
#undef  isGraph
#endif
#define isGraph(c)  (chc_ptyp[(int)(c)] & (chcGRAPH|chcXTGRA))
#ifdef  isLower
#undef  isLower
#endif
#define isLower(c)  (chc_ptyp[(int)(c)] & (chcLOWER|chcXTLOW))
#ifdef  isPrint
#undef  isPrint
#endif
#define isPrint(c)  (chc_ptyp[(int)(c)] & (chcPRINT|chcXTGRA))
#ifdef  isUpper
#undef  isUpper
#endif
#define isUpper(c)  (chc_ptyp[(int)(c)] & (chcUPPER|chcXTUPP))
#ifdef __cplusplus
}
#endif
#define chcHFILE 1
#endif
