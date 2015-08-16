/*****************************************************************************
* $Id: Datenbestand.h 2014-07-10 15:00:00 vogelsang $
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
* 2010-10-28 Löschung Datenbestand beschleunigen
* 2010-11-10 Kompakte Speicherung von Geometrie
* 2010-12-14 Speicherung der Fachobjekte optimieren
* 2011-08-12 template-Defintionen überarbeitet
* 2011-11-14 Private Definitionen verbergen
* 2012-05-14 Inkrementelles Entladen
* 2012-05-31 Private Definitionen verbergen(2)
* 2012-09-24 Verschmelzen von Objektreferenzen
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2012-11-14 Objektartnamen vergleichen ohne Fallunterscheidung
* 2013-02-04 Profile
* 2013-03-11 Harmonisierung der Schnittstelle
* 2013-11-18 Transformierer eingeführt
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-05-05 Fortschritt anzeigen bei Bestandlöschung
* 2014-05-09 Iteration über Datenbestand beschleunigen
* 2014-05-21 BoundingBox für Datenbestand erfragen
* 2014-07-10 SQL-Anbindung vorbereiten
* 
****************************************************************************/
#ifndef DEFDatenbestand
#define DEFDatenbestand

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "Ausnahme.h"
#include "Objektart.h"
#include "Fachobjekt.h"
#include "Enumerator.h"
#include "Objektartfilter.h"
#include "Fachbedeutungsliste.h"

namespace Oklabi
{
enum DomainState
{
	DomainLoadNone,		// Default, list relations are checked
	DomainLoadCTE,		// Loading CTE (set by CTEInputCv)
	DomainLoadXML,		// Loading XML (set by XMLInputCv)
	DomainNoTestList	// Suppress testing of list relation
};
enum AxisOrder
{
	EastingNorthing,	// Ost, Nord
	NorthingEasting		// Nord, Ost
};

typedef Menge< Datenbestand* >                             DatenbestandMenge;
typedef Liste< Datenbestand* >                             DatenbestandListe;

typedef	std::map<Text,FachobjektReferenz>                  LocIdMapType;

typedef std::multimap<Text,FachobjektReferenz>             IdMMapType;
typedef std::map<Text,IdMMapType>                          ClsIndexMapType;

typedef std::map<Text, TextListe>                          RelPartnerMap;
typedef std::map<FachobjektReferenz, RelPartnerMap>        XlinkHrefMapType;

typedef std::map<Text, FachobjektMengeImpl, Oklabi::cicmp> ObjectMapType;

	class Transaktion;
	class EingabeKonverter;
	class AusgabeKonverter;

class OKLABI_API Datenbestand : public OklabiObjekt
{
	friend class Umgebung;
	friend class Fachobjekt;
	friend class AusgabeKonverter;
	friend class CTEEingabeKonverter;
	friend class CTEAusgabeKonverter;
	friend class XMLEingabeKonverter;
	friend class XMLAusgabeKonverter;
	friend class XMLAusgabeGenerator;
	friend class XMLAdapter;
	friend class Transaktion;
	friend class DBImporteur;
	friend class Profil;

public:
	static Datenbestand*		Erzeuge(const Version*);
	static Datenbestand*		Standardbestand(const Version*);	// deprecated
	static Datenbestand*		GibStandardbestand(const Version*);
	Datenbestand*				Kopiere();
	Text						GibKlassenname() const;
	size_t						GibAnzahl() const;
	bool						IstLeer() const;
	bool                        IstGueltig() const;
	TextListe					GibObjektarten() const;
	size_t                      GibAnzahlObjekte(const Text&) const;
	void						Vereinige(const Datenbestand*);
	static void					Migriere(const Datenbestand*, const Version*, Datenbestand* = 0);
	void						Leere();
	void                        Transformiere(eKoordRefSys);
	void						VerschmelzeSymbolischeObjekte(bool);
	Enumerator*					GibEnumerator(Objektartfilter* = NULL);
	const Version*				GibVersion() const;
	const FblVersion*			GibFblVersion() const;
	void						SetzeFbl(const Fachbedeutungsliste* fl);
	Fachobjekt*					Suche(const Text&);
	void						KopiereObjekt(Fachobjekt*);
	void						KopiereObjekte(const AnyType&);
	void						Verschiebe(Fachobjekt*);
	void						Verschiebe(const AnyType&);
	Fachobjekt*					FuegeHinzu(const Objektart*);
	Transaktion*                GibTransaktion() const;
	size_t                      GibSpeicherplatz() const;
	void                        SetzeRelationsLoeschung(bool);
	bool                        GibRelationsLoeschung();
	bool                        LoescheRelationenVollstaendig(bool);	// deprecated
	const Profil*               GibProfil() const;
	void                        SetzeProfil(const Profil* = 0);
	GeoRechteck*                GibAusdehnung();
	bool                        Schreibe(const Text&, Fortschrittswaechter* = 0, Abbruchsignal* = 0);

	class ObjectCollection : public OklabiRoot
	{
		friend class Datenbestand;
		friend class CTEAusgabeKonverter;
		friend class XMLAusgabeKonverter;
#ifdef OKLABI_KERN
		friend class iterator;
		friend class const_iterator;
#endif
	private:
		ObjectCollection();
		~ObjectCollection();
		bool FuegeHinzu(FachobjektPtr);
		size_t Entferne(FachobjektPtr);
		size_t GibAnzahl(const char* = NULL) const;
		void GibFachobjekte(FachobjektMengeImpl&) const;
		void Loesche();
		bool IstLeer() const;

		class iterator : public OklabiRoot
		{
#ifdef OKLABI_KERN
			friend class Datenbestand::ObjectCollection;
#endif
			friend class Datenbestand;
			friend class CTEAusgabeKonverter;
			friend class XMLAusgabeKonverter;
		private:
			iterator();
			iterator(ObjectCollection*, const char* = NULL, bool = false);
			iterator(const iterator&);
			iterator& operator=(const iterator&);
			~iterator();
			iterator& operator++();
			iterator operator++(int);
			bool operator==(const iterator&);
			bool operator!=(const iterator&);
			ObjectCollection::iterator begin();
			ObjectCollection::iterator end();
			ObjectCollection::iterator find(const FachobjektReferenz&);
			FachobjektReferenz operator*() const;
			void next();
			void finish();
#ifdef OKLABI_KERN
			mutable ObjectMapType::iterator         m_ObjMapIter;
			mutable FachobjektMengeImpl::iterator   m_ObjIter;
			mutable Text                            m_strObjArt;
			mutable ObjectCollection*				m_pCollection;
#endif
		};

		class const_iterator : public OklabiRoot
		{
#ifdef OKLABI_KERN
			friend class Datenbestand::ObjectCollection;
#endif
			friend class Datenbestand;
			friend class CTEAusgabeKonverter;
			friend class XMLAusgabeKonverter;
		private:
			const_iterator();
			const_iterator(const ObjectCollection*, const char* = NULL, bool = false);
			const_iterator(const const_iterator&);
			const_iterator& operator=(const const_iterator&);
			~const_iterator();
			const_iterator& operator++();
			const_iterator operator++(int);
			bool operator==(const const_iterator&);
			bool operator!=(const const_iterator&);
			ObjectCollection::const_iterator begin() const;
			ObjectCollection::const_iterator end() const;
			ObjectCollection::const_iterator find(const FachobjektReferenz&) const;
			FachobjektReferenz operator*() const;
			void next() const;
			void finish() const;
#ifdef OKLABI_KERN
			mutable ObjectMapType::const_iterator       m_ObjMapIter;
			mutable FachobjektMengeImpl::const_iterator m_ObjIter;
			mutable Text                                m_strObjArt;
			mutable const ObjectCollection*			    m_pCollection;
#endif
		};

		iterator GibIterator(bool = false, const char* = NULL);
		const_iterator GibConstIterator(bool = false, const char* = NULL) const;
		mutable ObjectMapType              m_mapObjSet;
		mutable std::set<iterator*>        m_setIter;
		mutable std::set<const_iterator*>  m_setIterConst;
		static FachobjektMengeImpl         m_ObjSet;
	};

	class OKLABI_API FachobjektEnumerator : public Enumerator
	{
		friend class Datenbestand;
	public:
		FachobjektEnumerator(const Datenbestand* pDomain, Objektartfilter* pFilt = NULL);
		~FachobjektEnumerator();
		FachobjektEnumerator(const FachobjektEnumerator& iter);
		FachobjektEnumerator& operator=(const FachobjektEnumerator& iter);
		Text                              GibKlassenname() const;
		template<class T> T               GibObjekt();
		void                              Weiter();
		bool                              IstBeendet() const;
		void                              ZumAnfang();
	protected:
		bool                              KannVernichten() const;
		eEnumeratorTyp                    GibEnumeratorTyp() const;
	private:
		mutable const Datenbestand*       m_pDomain;
#ifdef OKLABI_KERN
		mutable ObjectCollection::const_iterator m_Iter;
#endif
		mutable Fachobjekt*               m_pObjekt;
		mutable Objektartfilter*          m_pFilter;
		mutable bool                      m_bNext;
		void Next() const;
	};

protected:
	Datenbestand();
	~Datenbestand();

	bool KannVernichten() const;

	ObjectCollection			m_ObjectCollection;
	AxisOrder					m_eAxisOrder;
	Text						m_strCRS;
	DomainState                 m_eState;
	XlinkHrefMapType			m_mapXlinkHref;
	Version						m_Version;
	Fachbedeutungsliste*		m_pFbliste;
	LocIdMapType*				m_pMapId;
	Transaktion*                m_pTransaktion;
	EingabeKonverter*			m_pInpCv;
	AusgabeKonverter*			m_pOutCv;
	const Profil*               m_pProfil;

	bool                        m_bSort;
	bool                        m_bVollstaendigesLoeschen;
	bool                        m_bOnDelete;
	bool                        m_bProgress;

	void						FuegeHinzu(const FachobjektPtr) const;

	// Test auf Objektsorte
	bool						check();

	// Hilfsfunktionen für den Iterator
	// Iterator auf den Anfang der Objektmenge
	ObjectCollection::iterator	begin();

	// Iterator auf das Ende der Objektmenge
	ObjectCollection::iterator	end();

	// Iterator auf ein gesuchtes Element oder das Ende der Objektmenge,
	// falls das Objekt nicht in der Menge enthalten ist
	ObjectCollection::iterator	find( const FachobjektReferenz& pObj );

	// const-Iterator auf den Anfang der Objektmenge
	ObjectCollection::const_iterator	cbegin() const;

	// const-Iterator auf das Ende der Objektmenge
	ObjectCollection::const_iterator	cend() const;

	// const-Iterator auf ein gesuchtes Element oder das Ende der Objektmenge,
	// falls das Objekt nicht in der Menge enthalten ist
	ObjectCollection::const_iterator	cfind( const FachobjektReferenz& pObj ) const;

	// Verwaltung der externen Verweise
	virtual TextListe       Finde_XlinkHref(Fachobjekt*, const Text&);
	virtual bool            Trage_XlinkHrefEin(Fachobjekt*, const Text&, const Text&);
	virtual bool            Loesche_XlinkHref(Fachobjekt*, const Text&, const Text&);

	// Status
	DomainState             SetzeStatus(DomainState eS);
	DomainState             ErfrageStatus();

	// Koordinatenreferenzsystem
	AxisOrder               ErfrageAchsenanordnung();
	void                    SetzeAchsenanordnung(const AxisOrder& order);
	Text                    ErfrageKoordinatenreferenzsystem();
	void                    SetzeKoordinatenreferenzsystem(const Text& crs);

	void					ObjektEintragen( Fachobjekt* pO, bool& bSucc );
	void					ObjektEntfernen( Fachobjekt* pO );
	void					ObjektEntfernen( Fachobjekt* pO, size_t& nAnz );
	
	void					ObjektmengeErfragen(FachobjektMengeImpl& psetObj) const;
	void					ObjektmengeVernichten();

	void					ObjektmengeNachKlasse( FachobjektMengeImpl& pset, const Objektart* eCl );
	bool					SubKlasse( const Objektart* pSub, const Objektart* pSuper );

	bool					ObjektEintragen(const Text& strId, Fachobjekt* pObj);
	Fachobjekt*				ObjektFinden(const Text& strId) const;
	bool					ObjektAustragen(const Text& strId, Fachobjekt* pObj);

	void					IndexAufbauen( ClsIndexMapType& mapClsIndexTarget, TextMenge* ) const;
	void					ObjekteVerschmelzen( FachobjektMengeImpl& );

};

// Spezialisierungen
template<> OKLABI_API Fachobjekt* Datenbestand::FachobjektEnumerator::GibObjekt<Fachobjekt*>();
template<> OKLABI_API const Fachobjekt* Datenbestand::FachobjektEnumerator::GibObjekt<const Fachobjekt*>();

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFDatenbestand
