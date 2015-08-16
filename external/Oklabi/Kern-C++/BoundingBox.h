/*****************************************************************************
* $Id: BoundingBox.h 2013-02-04 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt für Straßenwesen
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
* 2012-05-14 Inkrementelles Entladen
* 2013-02-04 Übernahme Koordinatenreferenzsystem
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFBBox
#define DEFBBox

#include "oklabidll.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

namespace Oklabi
{
	class GeoPunkt;
	class OKLABI_API BoundingBox : public OklabiObjekt
	{
		friend class Fachobjekt;
		friend class XMLAusgabeKonverter;
		friend class SchemaGeo;
	public:
		double ROx;
		double ROy;
		double LUx;
		double LUy;

		BoundingBox();
		BoundingBox(double rox, double roy, double lux, double luy);
		BoundingBox(const BoundingBox&);
		BoundingBox& operator=(const BoundingBox&);
		BoundingBox& operator+=(const BoundingBox&);
		BoundingBox& operator+=(const GeoPunkt& p);
		Text GibKlassenname() const;
		bool KannVernichten() const;
		bool IstGueltig() const;
	private:
		static const double m_dInfinity;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFBBox
