/*****************************************************************************
* $Id: FblVersion.h 2013-02-04 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt f�r Stra�enwesen
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
* 2012-10-18 Formale Verbesserungen
* 2013-02-04 Profile
* 
****************************************************************************/
#ifndef DEFFblVersion
#define DEFFblVersion

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "OklabiIntern.h"

namespace Oklabi
{
class OKLABI_API FblVersion : public OklabiObjekt
{
	friend class Fachbedeutungsliste;
	friend class Datenbestand;
	friend class AusgabeKonverter;
	friend class CTEAusgabeKonverter;
	friend class XMLAusgabeKonverter;
	friend class XMLAusgabeGenerator;
	friend class EingabeKonverter;
	friend class CTEEingabeKonverter;
	friend class XMLEingabeKonverter;
	friend class Fachobjekt;
	friend class Profil;
	friend class Aggregat;

private:
	unsigned char m_nMajor;
	unsigned char m_nMinor;
	Text m_strBuLa;

	FblVersion();
	~FblVersion();
	FblVersion(int major, int minor, const Text&);
	FblVersion(const FblVersion&);
	FblVersion& operator=(const FblVersion&);
	bool KannVernichten() const;
	bool operator==(const FblVersion&) const;
	bool operator!=(const FblVersion& v) const { return !this->operator==(v); };
	bool IstGleich(const FblVersion*) const;
#ifdef OKLABI_PRUEF
public:
#endif
	eFbVersion GibFbVersion() const;

public:
	static FblVersion* Erzeuge(int major, int minor, const Text& bl = "");
	FblVersion* Kopiere() const;
	Text GibKlassenname() const;
	Text GibText() const;

	int GibHauptversion() const;
	int GibUnterversion() const;
	Text GibBundesland() const;
};

}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFFblVersion
