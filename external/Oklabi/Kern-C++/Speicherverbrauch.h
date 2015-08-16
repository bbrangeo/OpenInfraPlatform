/*****************************************************************************
* $Id: Speicherverbrauch.h 2012-10-08 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt für Straßenwesen
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
* 2010-11-15 Aufräumen bei Programmende
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFMemStat
#define DEFMemStat

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"

#ifdef OKLABI_MEMORY
namespace Oklabi
{
	class OKLABI_API Speicherverbrauch : public OklabiRoot
	{
		friend class Umgebung;
	public:
		Speicherverbrauch(int level, bool alloc, size_t siz, const char*);
		~Speicherverbrauch();
	private:
		static void Report(int level = 100);
		static void Finalisiere();
		size_t m_nSize;
		int m_nLevel;
	};
}// End of namespace Oklabi

#define MEMORYSTAT(level,alloc,size,description) Speicherverbrauch _MemStat(level, alloc, size, description);
#else
#define MEMORYSTAT(level,alloc,size,description) 
#endif

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFMemStat
