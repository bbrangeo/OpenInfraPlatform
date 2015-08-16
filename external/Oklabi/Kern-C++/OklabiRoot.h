/*****************************************************************************
* $Id: OklabiRoot.h 2012-10-08 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2012-2012, Bundesanstalt für Straßenwesen
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
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 
****************************************************************************/
#ifndef DEFOklabiRoot
#define DEFOklabiRoot

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "oklabidll.h"

namespace Oklabi
{
    class OklabiRoot
    {
    public:
#if defined(WIN32) && !defined(CYGWIN)
        OKLABI_API void* operator new( size_t );
        OKLABI_API void* operator new( size_t, void* );
        OKLABI_API void operator delete( void* p );
        OKLABI_API void operator delete( void *, void * );
#endif
    };
}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFOklabiRoot
