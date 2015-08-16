/*****************************************************************************
* $Id: Fortschrittswaechter.h 2010-04-30 15:00:00 vogelsang $
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
#ifndef DEFFortschrittswaechter
#define DEFFortschrittswaechter

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiObjekt.h"

namespace Oklabi
{
	class Fortschrittswaechter : public OklabiObjekt
	{
		friend class Umgebung;
	public:
		virtual void Melde(int, eFortTyp) = 0;
		OKLABI_API Text GibKlassenname() const;
	protected:
		OKLABI_API Fortschrittswaechter();
		OKLABI_API ~Fortschrittswaechter();
		OKLABI_API bool KannVernichten() const;
	private:
		bool m_bInUse;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFFortschrittswaechter
