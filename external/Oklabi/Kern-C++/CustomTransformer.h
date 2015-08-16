/*****************************************************************************
* $Id: CustomTransformer.h 2013-11-18 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2013-2014, Bundesanstalt f�r Stra�enwesen
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
* 2013-11-18 Transformierer eingef�hrt
* 
****************************************************************************/
#ifndef DEFCustomTransformer
#define DEFCustomTransformer

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "Transformierer.h"

namespace Oklabi
{
	class Geometrie;
	class CustomTransformer : public Transformierer
	{
		friend class Umgebung;
	private:
		CustomTransformer();
		~CustomTransformer();

	public:
		OKLABI_API bool                   Transformiere(Koordinate&, eKoordRefSys) const;
		OKLABI_API bool                   IstUnterstuetzt(eKoordRefSys) const;
		OKLABI_API Text                   GibKlassenname() const;
	private:
		OKLABI_API bool                   IstLatLong(eKoordRefSys) const;
		OKLABI_API bool                   IstEastingNorthing(eKoordRefSys) const;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// CustomTransformer
