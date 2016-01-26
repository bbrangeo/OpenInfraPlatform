/*****************************************************************************
* $Id: Fachobjekt.h 2015-05-07 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2015, Bundesanstalt für Straßenwesen
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
* 2010-11-12 Funktion Loesche ohne AnyType
* 2010-11-18 Finalisierung beim Rundown
* 2011-04-07 Migration von Datenbestand erfordert 2 Durchgänge
* 2011-11-07 Quadratisches Laufzeitverhalten beim Löschen
* 2011-12-05 Oberklassenobjekte erzeugen für DBImporteur
* 2012-02-21 Laufzeitoptimierungen
* 2012-03-13 Referenzen beim Laden von XML
* 2012-05-14 Inkrementelles Entladen
* 2012-06-01 Meldungsausgabe erweitern
* 2012-09-18 Koordinatenreferenzsysteme bearbeitet
* 2012-09-24 Verschmelzen von Objektreferenzen
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2013-02-04 Profile
* 2013-03-01 Geometrie erfragen
* 2013-06-05 Methode für GUID eingeführt
* 2013-10-31 Speicheroptimierungen bei Strings und Collections
* 2013-11-18 Transformierer eingeführt
* 2013-12-12 Fremdobjekt für Nachbarstandards eingeführt
* 2014-01-13 Speicheroptimierungen beim Laden von OKSTRA-Daten
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-04-15 Fachkennung nur im OKSTRA-Datenmodell
* 2014-05-09 Iteration über Datenbestand beschleunigen
* 2014-06-06 Benutzerattribut am Fachobjekt
* 2014-08-06 Referenzen erkennen
* 2014-10-06 Kontrolle von Geometriemeldungen
* 2014-11-28 Überzählige Einträge durch inverse Relationen bei Listen
* 2015-02-05 Identitätswechsel bei AnyType durch dynamische Vergrösserung
* 2015-02-24 Referenzielles Geometrieformat(2)
* 2015-05-07 Neue Methode für Fehlermeldung benötigt
* 
****************************************************************************/
#ifndef DEFFachobjekt
#define DEFFachobjekt

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif
#include <math.h>

#include "SyncClasses.h"
#include "BoundingBox.h"
#include "Umgebung.h"
#include "Objektart.h"
#include "Eigenschaft.h"
#include "Fachbedeutungsliste.h"
#ifdef OKLABI_MEMOPT_2
#include "PasIdentifizierer.h"
#endif

namespace Oklabi
{

class StatusType : public OklabiRoot
{
public:
	unsigned short m_nOffset;	// Offset im Eigenschaftenvektor
	unsigned char  m_eState;	// Status des Wertes
	StatusType();
	~StatusType();
};

class WertType : public OklabiRoot
{
public:
	AnyType		m_Any;
	StatusType	m_State;
	WertType();
	~WertType();
};

class less_Point : public OklabiRoot
{
public:
	bool operator()(const GeoPunkt& p1, const GeoPunkt& p2) const;
};

class Fachobjekt;
typedef Fachobjekt*                    FachobjektPtr;
template<class T> class Liste;
template<class T> class Menge;
typedef const Fachobjekt*              FachobjektConstPtr;
typedef const AnyType*                 AnyTypeConstPtr;
typedef Menge< Fachobjekt*>            FachobjektMenge;
typedef Liste< Fachobjekt*>            FachobjektListe;
typedef	Menge< FachobjektConstPtr >    FachobjektMengeConst;
typedef Liste< AnyTypeConstPtr >       AnyTypeList;
typedef Menge< Fremdobjekt* >          FremdobjektMenge;
typedef Liste< Fremdobjekt* >          FremdobjektListe;

class Fremdobjekt;
class OKLABI_API Fachobjekt : public OklabiObjekt
{
	friend class Objektart;
	friend class Datenbestand;
	friend class AnyType;
	friend class EingabeKonverter;
	friend class CTEAusgabeKonverter;
	friend class XMLAusgabeKonverter;
	friend class XMLAusgabeGenerator;
	friend class XMLAdapter;
	friend class CTEEingabeKonverter;
	friend class XMLEingabeKonverter;
	friend class Umgebung;
	friend class Transaktion;
	friend class DBImporteur;
	friend class Profil;
	friend class Reflection;
	friend class Schema1;
	friend class Schema2;
	friend class Schema3;
	friend class Schema;
	friend class SchemaGeo;
	friend class Geometrie;
#if defined(OKLABI_MEMOPT_2)
	friend class PasIdentifizierer;
	friend class ObjektVertreter;
#endif
	friend class fidcmp;

private:
#ifdef OKLABI_PAS_ACTIVE
	mutable UINT64                m_uIdentifier;
#endif
	const Objektart*              m_pOA;
	size_t                        m_nInternId;

	struct PID_Type
	{
		Datenbestand* pDB;
	};
	mutable PID_Type              PID;

	typedef std::vector<WertType> WertVectorType;
	WertVectorType*               m_pVectProp;
	Text                          m_strObjektId;
	struct Zustand_Type
	{
		unsigned short            m_nFlags;
		unsigned short            m_nReserved;
		unsigned int              m_nRefCount;
	};
	mutable union
	{
		Zustand_Type              m_Zustand;
		UINT64                    m_nState;
	} m_uState;

	static Sync::CriticalRegion   FachobjektExclusive;	// Nebenläufigkeit
	static bool                   m_bValidateKeyTable;
	static bool                   m_bValidateFbSimple;
	static size_t                 m_nLastInternId;
	static AnyType*               m_pNullValue;
	static Eigenschaft*           m_pForeignReference;
	static Eigenschaft*           m_pUserAttribute;

public:
	Datenbestand*                 GibDatenbestand() const;
	const Objektart*              GibObjektart() const;
	const Version*                GibVersion() const;
	bool                          HatObjektart(const Objektartfilter*) const;
	bool                          HatTyp(const Objektartfilter*) const;

	static Fachobjekt*            Erzeuge(const Objektart*);
	void                          Vernichte() const;
	Text                          GibKlassenname() const;
	Fachobjekt*                   Kopiere(Datenbestand* = 0);
	bool                          Assimiliere(Fachobjekt* pSrc);
	Fachobjekt*                   Migriere(const Version* vsn, Datenbestand* = 0);
	bool                          IstGueltig() const;
	bool                          HatGueltigeFachbedeutung(const Fachbedeutungsliste*, const Text& = "alle") const;
	const AnyType*                Gib(const Text&) const;
	void                          FuegeHinzu(const Text&, const AnyType*);
	void                          Setze(const Text&, const AnyType*);
	void                          Loesche(const Text&, const AnyType* = 0);
	bool                          IstEnthalten(const Text&, const AnyType*);
	void                          SetzeOKSTRAID();
	size_t                        GibInternId() const;
	void                          SetzeInternId(size_t);
	bool                          IstNeu() const;
	bool                          IstGeaendert() const;
	bool                          IstGeloescht() const;
	Text                          GibObjektartname() const;
	TextListe                     GibEigenschaftsnamen() const;
	AnyTypeList                   GibEigenschaften(bool = true) const;
	bool                          HatEigenschaft(const Text&) const;
	const AnyType*                GibGeometrie(const Text&, const Eigenschaft*, size_t&) const;
	void                          Transformiere(eKoordRefSys);
	bool                          Verknuepfe(Fremdobjekt*);
	bool                          Loese(Fremdobjekt*);
	FremdobjektMenge              GibFremdobjekte() const;
	bool                          IstFixiert() const;
	bool                          Fixiere(bool) const;
	bool                          IstReferenz() const;
	void                          SetzeBenutzerattribut(UINT64);
	UINT64                        GibBenutzerattribut() const;

	static bool                   Zeitfilter(Fachobjekt* pxoObj, const Datum& von, const Datum& bis);
	Text                          KennungErfragen(const Datum& stichtag = Datum::today(), unsigned mode = offiziell) const;

	static void                   SetzeKoordinate(Fachobjekt*, const Koordinate&);
#if defined(OKLABI_MEMOPT_2)
	bool                          HatStellvertreter() const;
#endif

private:
	Fachobjekt(const Objektart*);
	Fachobjekt(UINT64, UINT64, const Objektart*, Datenbestand*, size_t, UINT64, const Text&);
	~Fachobjekt();
#ifdef OKLABI_INTERN
	bool                          KannVernichten() const;
	bool                          SetzeReferenz(bool) const;
	bool                          IstVerwaltet() const;
	bool                          SetzeVerwaltet(bool) const;
	bool                          PruefeFlagge(unsigned short) const;
	bool                          SetzeFlagge(unsigned short, bool) const;
	void                          FuegeHinzu(const Text&, const AnyType&, bool);
	void                          Setze(const Text&, const AnyType&, bool, bool, bool);
	void                          Setze(const Eigenschaft*, size_t, const Text&, const AnyType&, bool, bool, bool);
	size_t                        GibWert(const Eigenschaft*, size_t pos, bool);
	kt_ergebnis                   SchluesselobjektPruefen() const;
	bool                          IstGueltig(FachobjektMengeImpl* pSet, bool bDeep) const;
	bool                          HatGueltigeFachbedeutung(const Fachbedeutungsliste*, eFbVersion, eBundesland) const;
	static void                   LinienGeometrienAnordnen(const Datum&, AnyType::AnyEnumerator<Fachobjekt*>*, Geometrie*&);
	Fachobjekt*                   Migriere( const Version* vsn, Datenbestand* pBestand, TextMenge&, int );
	Fachobjekt*                   Migriere( Datenbestand*, const Version*, int, TextMenge&, int );
	const Eigenschaft*            SonderbehandlungMigration(FachobjektPtr, const Text&, const Text&, AnyType&);
	void                          Beschreibe(TextListe&) const;
	static Fachobjekt*            Erzeuge(const Objektart*, Datenbestand*, bool = false);
	bool                          SetzeNeuExport(bool);
	bool                          SetzeGeaendertExport(bool);
	bool                          SetzeGeloeschtExport(bool);
	bool                          IstGeloescht(const OklabiObjekt*) const;
	void                          Loesche(const Text&, const AnyType*, bool bTrans, const Eigenschaft* = NULL);
	bool                          DatenbestandVergleichen(const Fachobjekt* pObj) const;
	void                          FachobjektEinsetzen( Fachobjekt* pTarget );
	bool                          ReferenzEinsetzen( Fachobjekt* pTarget );
	Fachobjekt*                   KopierenAusfuehren(Datenbestand* = 0);
	void                          KomprimiereGeometrie(const Eigenschaft*, size_t) const;
	void                          ExpandiereGeometrie(const Eigenschaft*, size_t) const;
	size_t                        GibSpeicherplatz() const;
	bool                          ObjektIdSetzen(const Text& strId);
	Text                          ObjektIdErfragen() const;
	Text                          KlassennamenErfragen(bool bUpper = false) const;
	Text                          Gueltigkeitsintervall() const;
	void                          Gueltigkeitsintervall(Datum& von, Datum& bis) const;
	Text                          NormIdErfragen(const Datum& dat) const;
	void                          BoundingBoxErfragen( BoundingBox& BBox, const Datum& Stichtag = 0, FachobjektMengeImpl* pxosetcyc = NULL );
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1) const;
	void                          Fehlermeldung(const Text& strId, Text& strP1) const;
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1, const char* pstrP2) const;
	void                          Fehlermeldung(const Text& strId, Text& strP1, Text& strP2) const;
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1, const char* pstrP2, const char* pstrP3) const;
	void                          Fehlermeldung(const Text& strId, Text& strP1, Text& strP2, const Text& strP3) const;
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1, const char* pstrP2, const char* pstrP3, const char* pstrP4) const;
	void                          Fehlermeldung(const Text& strId, Text& strP1, Text& strP2, const Text& strP3, Text& strP4) const;
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1, const size_t& nP1) const;
	void                          Fehlermeldung(const Text& strId, Text& strP1, const size_t& nP1) const;
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1, const size_t& nP1, const size_t& nP2) const;
	void                          Fehlermeldung(const Text& strId, Text& strP1, const size_t& nP1, const size_t& nP2) const;
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1, const size_t& nP1, const size_t& nP2, const size_t& nP3) const;
	void                          Fehlermeldung(const Text& strId, Text& strP1, const size_t& nP1, const size_t& nP2, const size_t& nP3) const;
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1, const char* pstrP2, const size_t& nP1, const size_t& nP2, const size_t& nP3) const;
	void                          Fehlermeldung(const Text& strId, Text& strP1, Text& strP2, const size_t& nP1, const size_t& nP2, const size_t& nP3) const;
	void                          Fehlermeldung(const char* pstrId, const char* pstrP1, const char* pstrP2, const char* pstrP3, const char* pstrP4, const char* pstrP5) const;
	void                          Fehlermeldung(const char* pstrId, const size_t& nP1) const;
	void                          Fehlermeldung(const Text& strId, const size_t& nP1) const;

	bool                          testElementInListe(const Eigenschaft*, const Text&, const Text&, FachobjektListeImpl&, Fachobjekt*);

	template<class T> void        LoescheWert(const Text& nam, const AnyType& wert, const T& w);
	template<class T> void        PflegeWert(const Text& nam, eAggreg propAgg, bool bAdd, size_t off, const AnyType& val, T* dum);

	static void                   E_Eigenschaft( Fachobjekt*, const Eigenschaft*, const AnyType*& pAny, bool& bValid, const Datum&, const Datum& );
	static void                   E_Eigenschaft( Fachobjekt*, const Text&, const AnyType*& pAny, bool& bValid, const Datum&, const Datum& );
	static void                   P_Eigenschaft( Fachobjekt*, const Text&, const AnyType* pAny, bool& bValid, const Datum&, const Datum& );
	static bool                   Zeitfilter(const Datum& von, const Datum& bis, const Datum& von_obj, const Datum& bis_obj);

	static bool                   LiesKoordinate(Fachobjekt*, Koordinate&);

	static bool                   PruefeTyp(Fachobjekt*, const Text&);
	static bool                   PruefeTyp(Fachobjekt*, const Objektart*);
	template<class T> bool        WandleInText(const T&, Text&, Text&, size_t = 0) const;
	template<class T> bool        WandleVonText(const Text&, T&, Text&) const;

	static void                   Finalisiere();

	static void                   GibMenge(const AnyType*, FachobjektMengeImpl*&, FachobjektPtr&);
	static void                   GibListe(const AnyType*, FachobjektListeImpl*&, FachobjektPtr&);
	static void                   GibMenge(const AnyType*, KoordinatenMenge*&, Koordinate::KoordType*&);
	static void                   GibListe(const AnyType*, KoordinatenListe*&, Koordinate::KoordType*&);

	const AnyType*                Gib(const Eigenschaft*) const;
	const AnyType*                Gib(const Text&, const Eigenschaft*, size_t&, const bool& = false) const;
	const AnyType*                Suche(const size_t&) const;

	static void                   Setze_Datum(const Version&, Datenbestand*, const Text&, AnyType&);
	static void                   Setze_Koordinatensystem(const Version&, Datenbestand*, const Text&, AnyType&);

	static Text                   GibGUID(bool = false);

	Eigenschaft*                  ForeignInit() const;
	Eigenschaft*                  UserAttributeInit() const;

#ifdef OKLABI_DEBUG
	static size_t                 m_nWertResize;
	static size_t                 m_nWertVector;
	static size_t                 GibWertVektoren();
	static size_t                 GibWertKopien();
#endif

	typedef struct
	{
		unsigned                  Grad;
		bool                      Verbindung;
		FachobjektMengeImpl       Beg_von;
		FachobjektMengeImpl       Ende_von;
	} InfoType;
	typedef std::map<GeoPunkt, InfoType, less_Point> GraphType;
	static void                   LinienZusammenfassen(const Datum&, AnyType::AnyEnumerator<Fachobjekt*>*, Geometrie*& Geometrie);
#endif	// OKLABI_INTERN
};

#ifdef OKLABI_INTERN
#if defined(OKLABI_MEMOPT_2) || defined(OKLABI_MEMOPT_1)
// Spezialisierungen
template<> void Fachobjekt::LoescheWert(const Text& nam, const AnyType& wert, const FachobjektPtr& w);
template<> void Fachobjekt::PflegeWert(const Text& nam, eAggreg propAgg, bool bAdd, size_t off, const AnyType& val, FachobjektPtr* dum);
#endif
#endif	// OKLABI_INTERN

class OKLABI_API FixMe : public OklabiRoot
{
	friend class Fachobjekt;
public:
	FixMe(const Fachobjekt*);
	FixMe(const FixMe&);
	FixMe& operator=(const FixMe&);
	operator const Fachobjekt*() const;
	const Fachobjekt* operator->() const;
	operator Fachobjekt*();
	Fachobjekt* operator->();
	~FixMe();
private:
	const Fachobjekt* m_pObj;
	bool              m_bWasFixed;
};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFFachobjekt
