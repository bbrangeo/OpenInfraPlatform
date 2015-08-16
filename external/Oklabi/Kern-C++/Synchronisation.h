/*****************************************************************************
* $Id: Synchronisation.h 2012-10-08 15:00:00 vogelsang $
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
* 2011-02-07 Synchronisation verfeinert
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFSynchronisation
#define DEFSynchronisation

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "SyncClasses.h"

#ifdef OKLABI_SYNCHRONISATION

namespace Oklabi
{
	class Synchronisation : public OklabiRoot
	{
	public:
		Synchronisation(int level = 1, bool excl = false);
		Synchronisation(Sync::CriticalRegion*, int level = 1);
		Synchronisation(Sync::SimpleLock*, int level = 1);
		~Synchronisation();
	private:
		union
		{
			Sync::CriticalRegionOwnership* m_pOwnedCr;
			Sync::SimpleLockOwnership* m_pSharedLock;
		};
		bool m_bExclusive;
	};
}// End of namespace Oklabi

#define SYNCHRONISATION(p1,p2) Synchronisation _SYNC(p1,p2);
#ifdef OKLABI_SYNCHRONISATION_SCHEMA
#define SYNCHRONISATION_SCHEMA(p1,p2) Synchronisation _SYNC(p1,p2);
#else
#define SYNCHRONISATION_SCHEMA(p1,p2) 
#endif
#else
#define SYNCHRONISATION(p1,p2) 
#define SYNCHRONISATION_SCHEMA(p1,p2) 
#endif

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFSynchronisation
