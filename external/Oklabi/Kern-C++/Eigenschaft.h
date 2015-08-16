/*****************************************************************************
* $Id: Eigenschaft.h 2014-01-17 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2014, Bundesanstalt für Straßenwesen
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
* 2010-06-21 Interface GibInverse() veröffentlicht
* 2010-06-23 Interface IstKennung() ergänzt
* 2010-07-13 Interface GibPartner() ergänzt
* 2010-07-15 Interface IstEindeutig(), HatFachbedeutung() ergänzt
* 2010-07-20 Vorbereitungen für Nutzung der Schema-Datenbank
* 2010-08-27 Interface GibDokumentation() ergänzt, GIB() verändert
* 2010-09-09 Interface Uebersetze erweitert
* 2011-08-04 Interface GibFachdatentyp() ergänzt
* 2012-02-21 Laufzeitoptimierungen
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2013-02-04 Profile
* 2013-02-05 uom bei UML-Modellierung transportieren
* 2013-03-07 Typkennzeichner eingeführt
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFEigenschaft
#define DEFEigenschaft

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "OklabiIntern.h"
#include "Objektart.h"
#include "AnyType.h"

namespace Oklabi
{
// Prüf-Funktionen für Daten
#ifdef LINUX
	class Objektart;
#endif
typedef bool (*LocValidator)(void* aVal, Objektart* oa);

// Wandlungs-Funktionen für XML-In/Outputformat
typedef Text (*LocInputCvt)(const char* pData, bool& bSucc);
typedef Text (*LocOutputCvt)(void* pData, const char* pFormat, bool& bSucc);

typedef std::pair<size_t,size_t> KardinalitaetType;

class OKLABI_API Eigenschaft : public OklabiObjekt
{
	friend class Fachobjekt;
	friend class Objektart;
	friend class Reflection;
	friend class Schema1;
	friend class Schema2;
	friend class Schema3;
	friend class SchemaGeo;
	friend class CTEAusgabeKonverter;
	friend class CTEEingabeKonverter;
	friend class XMLAusgabeKonverter;
	friend class XMLAdapter;
	friend class Datenbestand;
	friend class Profil;
#ifdef OKLABI_SCHEMADB
	friend class SchemaDBAdapter;
#endif
#if defined(OKLABI_MEMOPT_2)
	friend class PasIdentifizierer;
#endif

private:
	const Objektart*           m_pObjektart;
	const Objektart*           m_pClass;
	const Objektart*           m_pHerkunft;
	mutable const Eigenschaft* m_pPartner;
	LocInputCvt                m_pInputCvt;
	LocOutputCvt               m_pOutputCvt;
	LocValidator               m_pValidator;
	Text                       m_strName;
	Text                       m_strInverse;
	Text                       m_strSynonym;
	size_t                     m_uLaenge;
	size_t                     m_uLoBound;
	size_t                     m_uHiBound;
	mutable size_t             m_uNrLangtext;
	eTyp                       m_eType;
	eAggreg                    m_eAggreg;
	eEinheitTyp                m_eUnit;
	eImplizit                  m_eImplicit;
	eErweiterung               m_eExtension;
#ifdef OKLABI_SCHEMADB
	mutable TextListe          m_listEnum;
	mutable int                m_nEnumKat;
	int                        m_nOID;
	bool                       m_bKennung;
#endif
	bool                       m_bArtificial;
	bool                       m_bKonfiguriert;
	bool                       m_bOptional;
	bool                       m_bFixed;
	bool                       m_bReadOnly;
	bool                       m_bVirtual;
	bool                       m_bPseudo;
	bool                       m_bInverse;
	bool                       m_bHatFB;
	bool                       m_bEindeutig;
	bool                       m_bGeoOpt;
	mutable size_t             m_nIndex;

private:
	Eigenschaft();
	~Eigenschaft();
	Eigenschaft(const Eigenschaft&);
	Eigenschaft& operator=(const Eigenschaft&);
	void                       clear();
	void                       copy(const Eigenschaft&);
	Text                       Uebersetze(int) const;
	Text                       Uebersetze(const Text&) const;
	TextListe                  LiesLangtexte() const;
	Text                       GibRuecksynonym() const;
	IntListe                   GibSchluesselwerte(int) const;
	TextListe                  GibSchluesselwerte() const;
	Text                       AlsText();
	bool                       IstPseudoinverse() const;
	bool                       KannVernichten() const;
	bool                       HatGanzzahlschluessel() const;
	bool                       HatTextschluessel() const;
	eAggreg                    GibAggregation() const;
	void                       Beschreibe(TextListe&) const;
	void                       Pruefe() const;
	Text                       GibUom() const;

public:
	static const Eigenschaft*  Gib(const Text&, const Objektart*, const Version* = NULL);
	const Objektart*           GibObjektart() const;
	const Objektart*           GibAssoziation() const;
	const Objektart*           GibHerkunft() const;
	const Eigenschaft*         GibPartner() const;
	KardinalitaetType          GibKardinalitaet() const;
	size_t                     GibLaenge() const;
	AnyType*                   GibTabellenwerte() const;
	AnyType*                   GibTabellenwert(int) const;
	AnyType*                   GibTabellenwert(const Text&) const;
	Text                       GibName() const;
	Text                       GibInverse() const;
	eTyp                       GibTyp() const;
	bool                       IstMehrwertig() const;
	bool                       IstGeordnet() const;
	eEinheitTyp                GibEinheit() const;
	const Objektart*           GibFachdatentyp() const;
	const Version*             GibVersion() const;
	bool                       HatVariableLaenge() const;
	bool                       HatKompakteGeometrie() const;
	bool                       HatFachbedeutung() const;
	bool                       IstImplizit() const;
	bool                       IstErweiterung() const;
	bool                       IstInvers() const;
	bool                       IstNurLesbar() const;
	bool                       IstOptional() const;
	bool                       IstVirtuell() const;
	bool                       IstKuenstlich() const;
	bool                       IstKennung() const;
	bool                       IstLangtext() const;
	bool                       IstEindeutig() const;

	Text                       GibKlassenname() const;
	Text                       GibDokumentation() const;
	int                        GibOID() const;
};

}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFEigenschaft
