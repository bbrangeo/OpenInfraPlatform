/*****************************************************************************
* $Id: oklabidll.h 2010-04-30 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010, Bundesanstalt für Straßenwesen
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
* 
****************************************************************************/
#ifndef DEFOklabidll
#define DEFOklabidll

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the OKLABIDLL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// OKLABI_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.

#ifdef OKLABIDLL

#if (defined(WIN32) && defined(OKLABIKERN_EXPORTS))
#ifndef WINDOWS
#define WINDOWS
#endif
#ifndef _USRDLL
#define _USRDLL
#endif
#ifdef _LIB
#undef _LIB
#endif
#endif

// definitions for usage in OKLABI Dynamic Library
#if !defined(LINUX) && !defined(CYGWIN)
#ifdef OKLABIKERN_EXPORTS
#define OKLABI_API			__declspec(dllexport)
#define OKLABI_TEMPLATE
#else // OKLABIDLL_EXPORTS
#define OKLABI_API			__declspec(dllimport)
#define OKLABI_TEMPLATE		extern
#endif // OKLABIDLL_EXPORTS

#else // !LINUX && !CYGWIN
#ifdef OKLABIDLL_EXPORTS
#define OKLABI_API
#define OKLABI_TEMPLATE
#else // OKLABIDLL_EXPORTS
#define OKLABI_API
#define OKLABI_TEMPLATE		extern
#endif
#endif // LINUX

#else  // OKLABIDLL

// definitions for usage in OKLABI Static Library
#define OKLABI_API 
#define OKLABI_TEMPLATE

#endif // OKLABIDLL
#define OKLABI_SCHEMA_API 

#pragma warning( disable : 4251 )
#pragma warning( disable : 4275 )

#endif
