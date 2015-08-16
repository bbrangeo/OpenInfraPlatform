#ifndef ANSI
#define ANSI
#endif
#ifndef SYSTEM
#ifdef WIN32
#define SYSTEM MSVCWNT
#define NO_ERRORWND
#endif
#ifdef CYGWIN
#define SYSTEM CYGWIN
#endif
#ifdef GENERIC_LINUX
#define SYSTEM GENERIC_LINUX
#endif
#endif
