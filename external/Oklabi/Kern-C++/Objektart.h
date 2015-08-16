/*****************************************************************************
* $Id: Objektart.h 2014-04-10 15:00:00 vogelsang $
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
* 2010-06-08 Interface GibSchemaname() ergänzt
* 2010-06-23 Interface IstKennung() in Eigenschaft ergänzt
* 2010-07-20 Vorbereitungen für Nutzung der Schema-Datenbank
* 2010-08-24 Interface IstDatentyp(), GibDokumentation() ergänzt
* 2011-08-04 Interface IstFachdatentyp() aus IstDatentyp() ergänzt
* 2011-08-09 Interface HatGeometrie() erweitert
* 2011-08-12 template-Defintionen überarbeitet
* 2011-11-05 Befreundung mit CTEEingabeKonverter
* 2012-02-21 Laufzeitoptimierungen
* 2012-05-14 Inkrementelles Entladen
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2013-02-04 Profile
* 2013-02-05 uom bei UML-Modellierung transportieren
* 2013-03-07 Typkennzeichner eingeführt
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-02-25 Schnittstelle Vereinigungstyp
* 2014-04-10 OKSTRA-Geometriemodell für Version 2.x ermöglichen
* 
****************************************************************************/
#ifndef DEFOklabiObjektart
#define DEFOklabiObjektart

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <list>

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "Version.h"
#include "Eigenschaft.h"
#include "AnyType.h"
#include "Fachobjekt.h"
#include "Reflection.h"

namespace Oklabi
{
	typedef const Objektart*              ObjektartConstPtr;
	typedef const Eigenschaft*            EigenschaftConstPtr;
	typedef std::vector<Eigenschaft*>     EigenschaftVektorType;
	template<class T> class Liste;
	template<class T> class Menge;
	typedef Liste< EigenschaftConstPtr>   EigenschaftListType;
	typedef Liste< ObjektartConstPtr>     ObjektartListType;

	const unsigned int unspezifisch           = (unsigned int)  0;
	const unsigned int geoKlasse              = (unsigned int)  1;
	const unsigned int streckeKlasse          = (unsigned int)  2;
	const unsigned int strassenPunktKlasse    = (unsigned int)  4;
	const unsigned int teilabschnittKlasse    = (unsigned int)  8;
	const unsigned int punktKlasse            = (unsigned int) 16;
	const unsigned int abstraktKlasse         = (unsigned int) 32;
	const unsigned int symbolKlasse           = (unsigned int) 64;
	const unsigned int grafischesSymbolKlasse = (unsigned int)128;

	class Profil;
class OKLABI_API Objektart : public OklabiObjekt
{
	friend class Fachobjekt;
	friend class Eigenschaft;
	friend class Objektartfilter;
	friend class Datenbestand;
	friend class DBImporteur;
	friend class Reflection;
	friend class Schema;
	friend class Schema1;
	friend class Schema2;
	friend class Schema3;
	friend class SchemaGeo;
	friend class EingabeKonverter;
	friend class CTEEingabeKonverter;
	friend class CTEAusgabeKonverter;
	friend class XMLAusgabeGenerator;
	friend class XMLAusgabeKonverter;
	friend class XMLAdapter;
	friend class Umgebung;
#ifdef OKLABI_SCHEMADB
	friend class SchemaDBAdapter;
#endif
	friend class Profil;
#if defined(OKLABI_MEMOPT_2)
	friend class PasIdentifizierer;
#endif

private:
	mutable const Objektart*		m_pXMLRef;
	mutable void*					m_pKeyValueFunctions;
	mutable void*					m_pDerivedFunctions;
	mutable Text					m_strKennungName;
	mutable Text					m_strLangtextName;
	mutable EigenschaftVektorType	m_vectEig;
	Text							m_strName;
	mutable Text					m_strNameSchema;
	mutable Text					m_strSchema;
	mutable TextListe				m_listVirt;
	mutable TextListe				m_listFriends;
	mutable TextListe				m_listPseudo;

#define OKLABICLASSINFOSUPERTYPESIZE 8
	mutable const Objektart*		m_pSupertypes[OKLABICLASSINFOSUPERTYPESIZE];

	Version							m_Version;
#ifdef OKLABI_SCHEMADB
	mutable int						m_nOID;
	mutable int						m_nGenauigkeit;
	mutable eTypKategorie			m_eTypKategorie;
	mutable eTyp					m_eType;
	mutable Text					m_strBedingung;
	mutable Text                    m_strUom;
	mutable TextListe				m_listEnum;
	mutable int						m_nEnumKat;
	mutable ObjektartListType		m_listSubtypes;
#endif
	mutable eErweiterung			m_eExtension;
	mutable bool					m_bKeyTable;
	mutable bool					m_bEnum;
	mutable bool					m_bGeoOpt;
	mutable bool				    m_bSymbol;
	mutable bool					m_bAbstract;
	mutable bool					m_bFachID;
	mutable bool					m_bHist;
	mutable bool					m_bKonz;
	mutable bool					m_bCreate;
	mutable bool					m_bKonfiguriert;
	mutable bool					m_bUnion;
	mutable bool					m_bExtend;
	mutable bool					m_bOksGeo;
	mutable unsigned int			m_nStatus;

private:
	Objektart();
	~Objektart();
	Objektart(const Text&, const Version&);
	Objektart(const Objektart&);
	Objektart& operator=(const Objektart&);
	bool                            KannVernichten() const;
	void                            clear();
	void                            copy(const Objektart&);
	const Eigenschaft*              FindeEigenschaft(const Text&, size_t& pos) const;
	Text                            GibLangtextname() const;
	bool                            HatTyp(const Objektart&, const Version&) const;
	static bool                     Finalisiere();
	void                            Beschreibe(TextListe&) const;
	bool                            HatLangtext() const;
	EigenschaftListType             GibLangtextEigenschaften() const;
	bool                            IstGeoKlasse() const;
	bool                            IstStreckeKlasse() const;
	bool                            IstPunktKlasse() const;
	bool                            IstStrassenpunktKlasse() const;
	bool                            IstTeilabschnittKlasse() const;
	bool                            IstAbstraktKlasse() const;
	bool                            IstSymbolKlasse() const;
	bool                            IstGrafischesSymbolKlasse() const;
	Text                            GibUom() const;
	static Enumerator*              GibEnumerator(const Profil*);

	mutable bool                    m_bInit;
	mutable bool                    m_bOnInit;

public:
	static const Objektart*         Gib(const Text& name, const Version* vsn);
	static Enumerator*              GibEnumerator(const Version*);
	size_t                          GibAnzahlEigenschaften() const;
	Text                            GibKlassenname() const;
	EigenschaftListType             GibEigenschaften() const;
	Fachobjekt*                     GibInstanz() const;
	template<class T> Fachobjekt*   GibEintrag(const T&) const;
	AnyType*                        GibEintraege() const;
	ObjektartListType               GibBasisobjektarten() const;
	ObjektartListType               GibUnterobjektarten() const;
	Text                            GibName() const;
	Text                            GibSchemaname() const;
	Text                            GibDokumentation() const;
	Text                            GibDokumentation(const Text&) const;
	Text                            GibDokumentation(const int&) const;
	int                             GibOID() const;
	int                             GibGenauigkeit() const;
	eTypKategorie                   GibKategorie() const;
	Text                            GibBedingung() const;
	const Version*                  GibVersion() const;
	const Objektart*                GibNetzbezug() const;
	size_t                          GibTabellenlaenge() const;
	AnyType*                        GibKennungen() const;
	bool                            HatFachkennung() const;
	bool                            HatGanzzahlkennung() const;
	bool                            HatTextkennung() const;
	bool                            HatFachbedeutung() const;
	bool                            HatGeometrie(const eGeoTyp& = Ohne) const;
	bool                            HatKompakteGeometrie() const;
	bool                            IstAbstrakt() const;
	bool                            IstAufzaehlung() const;
	bool                            IstErweiterung() const;
	bool                            IstGleich(const Objektart*) const;
	bool                            IstHistorisierend() const;
	bool                            IstInstanzierbar() const;
	bool                            IstKonfiguriert() const;
	bool                            IstKonzeptionell() const;
	bool                            IstSchluesseltabelle() const;
	bool                            IstSymbol() const;
	bool                            IstDatentyp() const { return IstFachdatentyp(); };
	bool                            IstFachdatentyp() const;
	bool                            IstVereinigungstyp() const;
	bool                            IstErweiterbar() const;
	bool                            IstGeometriemodell() const;
	template<class T> T             GibTypkennzeichner(eTypkennzeichner) const;

	class OKLABI_API ObjektartEnumerator : public Enumerator
	{
		friend class Objektart;
		friend class Datenbestand;
		friend class Profil;
		friend class ProfilEnumerator;
	private:
		ObjektartEnumerator();
		ObjektartEnumerator(const Profil* pPr);
	public:
		ObjektartEnumerator(const Version* vsn);
		~ObjektartEnumerator();
		ObjektartEnumerator(const ObjektartEnumerator& iter);
		ObjektartEnumerator& operator=(const ObjektartEnumerator& iter);
		Text                        GibKlassenname() const;
		template<class T> T         GibObjekt();
		void                        Weiter();
		bool                        IstBeendet() const;
		void                        ZumAnfang();
	protected:
		bool                        KannVernichten() const;
		eEnumeratorTyp              GibEnumeratorTyp() const;
	private:
		mutable Text                m_strLast;
		mutable Version             m_Version;
		mutable const Profil*       m_pProfil;
		mutable bool                m_bSymbol;
	};
};

// Spezialisierungen
template<> OKLABI_API const Objektart* Objektart::ObjektartEnumerator::GibObjekt<const Objektart*>();

template<> OKLABI_API eTyp Objektart::GibTypkennzeichner<eTyp>(eTypkennzeichner) const;
template<> OKLABI_API Text Objektart::GibTypkennzeichner<Text>(eTypkennzeichner) const;
template<> OKLABI_API int Objektart::GibTypkennzeichner<int>(eTypkennzeichner) const;
template<> OKLABI_API bool Objektart::GibTypkennzeichner<bool>(eTypkennzeichner) const;
template<> OKLABI_API eTypKategorie Objektart::GibTypkennzeichner<eTypKategorie>(eTypkennzeichner) const;

template<> OKLABI_API Fachobjekt* Objektart::GibEintrag<int>(const int&) const;
template<> OKLABI_API Fachobjekt* Objektart::GibEintrag<Text>(const Text&) const;

typedef std::map<const Objektart*,const Objektart*>	ClassToSymbolMapType;

}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFOklabiObjektart
