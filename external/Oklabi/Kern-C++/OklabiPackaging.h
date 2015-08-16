/*****************************************************************************
* $Id: OklabiPackaging.h 2014-07-10 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
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
* 2010-07-20 Vorbereitungen für Nutzung der Schema-Datenbank
* 2011-10-11 Wandlung von double in Text
* 2012-03-13 Debug-Aufwände für Release-Version vermindern
* 2012-08-10 Version Plattform und IDE erkennen
* 2012-12-17 Anpassungen für Visual Studio 2012
* 2013-10-31 Speicheroptimierungen bei Strings und Collections
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-04-08 Anpassungen für Visual Studio 2013
* 2014-04-29 Integration von libspatialite
* 2014-05-09 Iteration über Datenbestand beschleunigen
* 2014-07-10 SQL-Anbindung vorbereiten
* 
****************************************************************************/
#ifndef DEFOklabiPackaging
#define DEFOklabiPackaging

#pragma warning( disable : 4786 )
#pragma warning( disable : 4099 )
#pragma warning( disable : 4503 )

#include "OklabiVersion.h"

// Diese Preprocessor-Definition muss aktiviert sein,
// wenn OKLABI als DLL verwendet wird, und deaktiviert,
// wenn OKLABI als statische LIB verwendet wird.
#if !defined(LINUX) && !defined(CYGWIN)
#define OKLABIDLL
#endif

// Die folgenden Preprocessor-Definitionen
// dürfen nicht verändert werden.
#if !defined(LINUX) && !defined(CYGWIN)
#define OKLABI_S
#define OKLABI_PACK
#endif
#define OKLABI_CVT

#define OKLABI_CTE
//#define OKLABI_SPATIALITE
//#define OKLABI_PGSQL
#if (defined(OKLABI_SPATIALITE) || defined(OKLABI_PGSQL)) && !defined(OKLABI_SQL)
#define OKLABI_SQL
#endif
#define OKLABI_GEOMETRIE
#define OKLABI_SYMBOL
#define OKLABI_XML

#define OKLABI_SYNCHRONISATION
//#define OKLABI_LOGGING
//#define OKLABI_MEMORY
//#define OKLABI_STATISTIK
//#define OKLABI_TRACE
//#define OKLABI_PRINT

#define OKLABI_DEBUG
//#define OKLABI_MEMOPT_1
#define OKLABI_MEMOPT_2
#if defined(OKLABI_MEMOPT_1) && defined(OKLABI_MEMOPT_2)
#error Kombination der Parameter OKLABI_MEMOPT_1 und OKLABI_MEMOPT_2 ist nicht erlaubt
#endif

#if defined(_MSC_VER) && defined(_WIN64) && !defined(WIN64)
#define WIN64
#elif defined(LINUX) && defined(__GNUC__) && defined(__x86_64) && !defined(LINUX64)
#define LINUX64
#endif

#if defined(WIN64) || defined(LINUX64) || defined(CYGWIN64)
#define OKLABI_PLATFORM "64"
#elif defined(WIN32) || defined(LINUX) || defined(CYGWIN)
#define OKLABI_PLATFORM "32"
#else
#define OKLABI_PLATFORM ""
#endif

#if defined(_MSC_VER)
#if _MSC_VER >= 1400 && _MSC_VER < 1500
#ifndef MSVC80
#define MSVC80
#endif
#define OKLABI_IDEVERSION "8"
#define OKLABI_MSDEV "VS 2005"
#elif _MSC_VER >= 1500 && _MSC_VER < 1600
#ifndef MSVC90
#define MSVC90
#endif
#define OKLABI_IDEVERSION "9"
#define OKLABI_MSDEV "VS 2008"
#elif _MSC_VER >= 1600 && _MSC_VER < 1700
#ifndef MSVC100
#define MSVC100
#endif
#define OKLABI_IDEVERSION "10"
#define OKLABI_MSDEV "VS 2010"
#elif _MSC_VER >= 1700 && _MSC_VER < 1800
#ifndef MSVC110
#define MSVC110
#endif
#ifndef MSVC100
#define MSVC100
#endif
#define OKLABI_IDEVERSION "11"
#define OKLABI_MSDEV "VS 2012"
#elif _MSC_VER >= 1800 && _MSC_VER < 1900
#ifndef MSVC120
#define MSVC120
#endif
#ifndef MSVC100
#define MSVC100
#endif
#define OKLABI_IDEVERSION "12"
#define OKLABI_MSDEV "VS 2013"
#else
#define OKLABI_IDEVERSION ""
#define OKLABI_MSDEV ""
#endif
#elif defined(CYGWIN)
#define OKLABI_IDEVERSION "GCC "  __VERSION__ " (CYGWIN)"
#elif defined(LINUX) || defined(LINUX64)
#define OKLABI_IDEVERSION "GCC " __VERSION__ " (Linux)"
#endif

#endif // DEFOklabiPackaging

