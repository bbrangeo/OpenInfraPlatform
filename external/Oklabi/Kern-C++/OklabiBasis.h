/*****************************************************************************
* $Id: OklabiBasis.h 2013-02-08 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt für Straßenwesen
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
* 2010-10-26 Anpassungen für Linux
* 2011-08-18 Text einkapseln
* 2012-09-18 Koordinatenreferenzsysteme bearbeitet
* 2013-02-08 Definitionen für verschiedene Schnittstellen zentralisieren
* 
****************************************************************************/
#ifndef DEFOklabiBasis
#define DEFOklabiBasis

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#pragma comment( compiler )
#pragma comment( user, "Compiled on " __DATE__ " at " __TIME__ )

#include <string>
#include <set>
#include <list>
#include <map>
#ifdef CYGWIN
#undef max
#undef min
#endif
#include <istream>
#include <ostream>
#if defined(WIN32) || defined(CYGWIN)
#include <windows.h>
#endif

#include "OklabiEnum.h"

#include "Text.h"

#define OKLABI_D_UNDEF -99999999
#define OKLABI_F_UNDEF -99999

namespace Oklabi
{
#if defined(LINUX) && !defined(UINT64)
#define UINT64 unsigned long long
#endif
        
	template<class T> class Liste;
	template<class T> class Menge;
	typedef Menge< Text >              TextMenge;
	typedef Liste< Text >              TextListe;

	typedef Text WKT;
	typedef Text BinaerdatenType;

	const int unbekannt	 = 00000000; // zuvor 19000101
	const int offen		 = 99990000; // zuvor 20991231
	const int i_undef    = 0;
	const char eof       = '\0';

	const double d_undef = OKLABI_D_UNDEF;
	const float f_undef  = OKLABI_F_UNDEF;

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFOklabiBasis
