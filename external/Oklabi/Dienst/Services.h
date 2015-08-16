/*****************************************************************************
* $Id: Services.h 2014-01-27 15:00:00 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2014, Bundesanstalt für Straßenwesen
*
* Erstellt durch interactive instruments GmbH, Bonn
*
* Die Nutzungsbestimmungen für die Software und die zugehörigen Bestandteile
* sind unter folgender Adresse einsehbar:
*    http://www.okstra.de/oklabi/Lizenz/Nutzung.txt
* 
* Der Hinweis auf das Copyright und die Lizenzbestimmungen ist in allen
* Kopien der Software oder wesentlichen Bestandteilen daraus aufzunehmen.
*
* Die Erklärungen zum Gewährleistungsausschluß und zur Haftungsbegrenzung 
* befinden sich bei den Nutzungsbestimmungen.
* 
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#ifndef SERVICES_H
#define SERVICES_H

#if defined(GENERIC_LINUX) || defined(CYGWIN)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#ifdef __cplusplus
#ifndef CYGWIN
#define CHAR char
#define BOOL bool
#define FALSE false
#define HANDLE void*
#define HWND void*
#define DWORD long
#define LPTSTR char*
#define LPVOID void*
#endif
#endif

//#define max(a, b) ((a)>(b)?(a):(b))
//#define min(a, b) ((a)<(b)?(a):(b))
#ifndef CYGWIN
#ifdef __cplusplus
#define __max(a, b) ((a)>(b)?(a):(b))
#define __min(a, b) ((a)<(b)?(a):(b))
#else
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
#endif
#endif

char* _itoa(int, char*, int);
char* _ltoa(long, char*, int);

#ifdef __cplusplus
extern "C" {
#endif
size_t filelength(int fd);
unsigned long long filelengthi64(int fd);
#define _filelengthi64 filelengthi64
#define _fileno fileno
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef CYGWIN
DWORD GetLastError(void);
DWORD GetTickCount(void);
void SetLastError(DWORD);
void ZeroMemory( void*, size_t );
pthread_t GetCurrentThreadId();
#endif
#endif

#endif /* GENERIC_LINUX */
#if defined(GENERIC_LINUX) || defined (CYGWIN)
char* _strupr(char*);
char* _strlwr(char*);
#endif /* GENERIC_LINUX || CYGWIN */
#endif /* SERVICES_H */
