/*****************************************************************************
* $Id: Transformierer.h 2013-11-18 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2013-2013, Bundesanstalt für Straßenwesen
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
* 2013-11-18 Transformierer eingeführt
* 2014-01-23 Koordinatenreihenfolge Transformierer
* 
****************************************************************************/
#ifndef DEFTransformierer
#define DEFTransformierer

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiObjekt.h"

namespace Oklabi
{
	class Geometrie;
	class Transformierer : public OklabiObjekt
	{
		friend class Umgebung;
		friend class Geometrie;
	public:
		virtual bool            Transformiere(Koordinate&, eKoordRefSys) const = 0;
		virtual bool            IstUnterstuetzt(eKoordRefSys) const = 0;
	private:
		virtual bool            IstLatLong(eKoordRefSys) const = 0;
		virtual bool            IstEastingNorthing(eKoordRefSys) const = 0;
	protected:
		OKLABI_API Transformierer();
		OKLABI_API ~Transformierer();
		OKLABI_API bool         KannVernichten() const;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFTransformierer
