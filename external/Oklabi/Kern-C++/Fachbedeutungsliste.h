/*****************************************************************************
* $Id: Fachbedeutungsliste.h 2013-02-04 15:00:00 vogelsang $
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
* 2013-02-04 Profile
* 
****************************************************************************/
#ifndef DEFFachbedeutungsliste
#define DEFFachbedeutungsliste

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "OklabiIntern.h"
#include "FblVersion.h"
#include "DateiEingabe.h"
#include "Umgebung.h"

namespace Oklabi
{
class OKLABI_API Fachbedeutungsliste : public OklabiObjekt
{
	friend class Datenbestand;
	friend class Fachobjekt;
	friend class Umgebung;
	friend class Profil;
private:
#ifdef OKLABI_KERN
	// Map für Fachbedeutungen
	FblVersion     m_FblVersion;
	Text           m_strBuLa;
	Umgebung::FblisteMapType m_mapFB;
	bool           m_bFreeMap;

	Fachbedeutungsliste();
	~Fachbedeutungsliste();
	Fachbedeutungsliste(const FblVersion*, const DateiEingabe*);
	Fachbedeutungsliste(const Fachbedeutungsliste&);
	Fachbedeutungsliste& operator=(const Fachbedeutungsliste&);

	bool                        KannVernichten() const;
	static eBundesland          GibBundesland(const Text&, bool& bV);
	void                        KopiereTabelle(const Fachbedeutungsliste&);

	typedef std::vector< Text > stringVector;
	typedef std::multimap< Text, stringVector > mapLineType;
	typedef std::map< Text, int> mapStringType;
	static int                  readfile(bool, const Text&, mapLineType&, eBundesland, const Text&);
#endif

public:
	static Fachbedeutungsliste* Erzeuge(const FblVersion*, const DateiEingabe* = 0);
	Fachbedeutungsliste*        Kopiere() const;
	Text                        GibKlassenname() const;
	Text                        GibText(const Text&, eGeoTyp, eBundesland = bl_alle) const;
	FblVersion*                 GibFblVersion() const;
	bool                        IstGueltig(const Text&, eGeoTyp, eBundesland = bl_alle) const;
};

}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFFachbedeutungsliste
