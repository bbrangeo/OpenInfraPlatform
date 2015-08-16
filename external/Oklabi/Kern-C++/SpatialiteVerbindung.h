/*****************************************************************************
* $Id: SpatialiteVerbindung.h 2014-07-10 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2014-2014, Bundesanstalt f�r Stra�enwesen
*
* Erstellt durch interactive instruments GmbH, Bonn
*
* Die Nutzungsbestimmungen f�r die Software und die zugeh�rigen Bestandteile
* sind unter folgender Adresse einsehbar:
*    http://www.okstra.de/oklabi/Lizenz/Nutzung.txt
* 
* Der Hinweis auf das Copyright und die Lizenzbestimmungen ist in allen
* Kopien der Software oder wesentlichen Bestandteilen daraus aufzunehmen.
*
* Die Erkl�rungen zum Gew�hrleistungsausschlu� und zur Haftungsbegrenzung 
* befinden sich bei den Nutzungsbestimmungen.
* 
* 2014-07-10 SQL-Anbindung vorbereiten
* 
****************************************************************************/
#ifndef DEFSpatialiteVerbindung
#define DEFSpatialiteVerbindung

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#ifdef OKLABI_SPATIALITE

#include "OklabiKern.h"
#include "SQLVerbindung.h"
#include "SyncClasses.h"
#include "sqlite3.h"

namespace Oklabi
{
	class SpatialiteVerbindung : public SQLVerbindung
	{
	public:
	    static OKLABI_API SQLVerbindung* Erzeuge(const Text&);
		OKLABI_API void                  Oeffne();
		OKLABI_API void                  Schliesse();
		OKLABI_API bool                  Teste();
		OKLABI_API void                  BeginneTransaktion();
		OKLABI_API void                  Uebernimm();
		OKLABI_API void                  FuehreZurueck();
		OKLABI_API int                   Aendere(const Text&, bool = true);
		OKLABI_API int                   Loesche(const Text&, bool = true);
		OKLABI_API Datenleser*           Lies(const Text&);
		OKLABI_API void                  GibVersionen(VersionListe&);
		OKLABI_API void                  GibObjektarten(const Version*, bool);
		OKLABI_API Text                  GibKlassenname() const;
		OKLABI_API Text                  GibBeschreibung() const;
	private:
		OKLABI_API SpatialiteVerbindung(const Text&);
		OKLABI_API ~SpatialiteVerbindung();
		OKLABI_API Text                  GibBoolean(bool) const;
		OKLABI_API Text                  GibZwTabIndexDefinition(const Text&, const Text&) const;
		OKLABI_API Text                  GibIndexDefinition(const Text&, const Text&, const Text&) const;
		OKLABI_API Text                  GibGeometrieDefinition(const Text&, const Text&, int, const Text&, int) const;
		Text                             m_strName;
		Text                             m_strMsg;
		bool                             m_bFailure;
		sqlite3*                         db;
		Sync::CriticalRegion             AccessExclusive;
	};
}// End of namespace Oklabi

#endif // OKLABI_SPATIALITE

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFSpatialiteVerbindung
