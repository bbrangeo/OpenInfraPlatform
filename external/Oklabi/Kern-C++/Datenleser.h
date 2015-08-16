/*****************************************************************************
* $Id: Datenleser.h 2014-07-10 15:00:00 vogelsang $
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
#ifndef DEFDatenleser
#define DEFDatenleser

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#ifdef OKLABI_SQL

#include "OklabiKern.h"
#include "OklabiObjekt.h"
#include "Ausgabe.h"

namespace Oklabi
{
	class Datenleser : public OklabiObjekt
	{
	public:
		virtual bool            Weiter() = 0;
		virtual void            Schliesse() = 0;
		virtual bool            HatSpalten() const = 0;
		virtual Text            GibText(int) const = 0;
		virtual UINT64          GibUInt64(int) const = 0;
	protected:
		OKLABI_API Datenleser();
		OKLABI_API ~Datenleser();
		bool OKLABI_API         KannVernichten() const;
	};
}// End of namespace Oklabi

#endif // OKLABI_SQL

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFDatenleser
