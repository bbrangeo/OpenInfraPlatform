/*****************************************************************************
* $Id: SpatialiteDatenleser.h 2014-07-10 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2014-2014, Bundesanstalt für Straßenwesen
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
* 2014-07-10 SQL-Anbindung vorbereiten
* 
****************************************************************************/
#ifndef DEFSpatialiteDatenleser
#define DEFSpatialiteDatenleser

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#ifdef OKLABI_SPATIALITE

#include "OklabiKern.h"
#include "OklabiObjekt.h"
#include "Datenleser.h"
#include "sqlite3.h"
#include "spatialite.h"

namespace Oklabi
{
	class SpatialiteDatenleser : public Datenleser
	{
		friend class SpatialiteVerbindung;
	public:
		bool OKLABI_API         Weiter();
		void OKLABI_API         Schliesse();
		bool OKLABI_API         HatSpalten() const;
		Text OKLABI_API         GibText(int) const;
		UINT64 OKLABI_API       GibUInt64(int) const;
		int  OKLABI_API         Geaendert() const;
		Text OKLABI_API         GibKlassenname() const;
	protected:
		OKLABI_API SpatialiteDatenleser(sqlite3*, sqlite3_stmt*);
		OKLABI_API ~SpatialiteDatenleser();
		bool OKLABI_API         KannVernichten() const;
	private:
		sqlite3*                m_pDB;
		sqlite3_stmt*           m_pStmt;
		int                     m_nState;
		int                     m_nModified;
	};
}// End of namespace Oklabi

#endif // OKLABI_SPATIALITE

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFSpatialiteDatenleser
