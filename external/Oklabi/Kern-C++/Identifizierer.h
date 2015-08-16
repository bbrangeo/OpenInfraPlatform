/*****************************************************************************
* $Id: Identifizierer.h 2014-01-17 15:00:00 vogelsang $
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
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#ifndef DEFIdentifizierer
#define DEFIdentifizierer

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiRoot.h"

namespace Oklabi
{
	class Fachobjekt;
	class Identifizierer : public OklabiRoot
	{
		friend class Umgebung;
		friend class Datenbestand;
		friend class Fachobjekt;
		friend class AnyType;
	public:
		virtual OKLABI_API operator Fachobjekt*() const = 0;
		virtual OKLABI_API Fachobjekt* operator->() const = 0;
		virtual OKLABI_API bool operator==(Fachobjekt*) const = 0;
		virtual OKLABI_API void Halte(bool) const = 0;
	protected:
		OKLABI_API Identifizierer();
		OKLABI_API ~Identifizierer();
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFIdentifizierer
