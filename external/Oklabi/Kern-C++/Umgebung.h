/*****************************************************************************
* $Id: Umgebung.h 2014-06-27 15:00:00 vogelsang $
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
* 2010-07-08 Aufzaehlungstyp eAufzaehlungen, Interface GibTextZuWert ergänzt
* 2010-07-20 Vorbereitungen für Nutzung der Schema-Datenbank
* 2010-10-25 Version Schema-Datenbank eingeführt
* 2010-11-10 Kompakte Speicherung von Geometrie
* 2010-11-25 Validierung Fachbedeutungslisten
* 2011-01-20 Ausgabe bei kompakter Geometriespeicherung
* 2011-04-07 Umrechnung bei Einheitenwandlung
* 2011-08-16 Zeilenumbruch plattformabhängig
* 2011-09-06 Textformat umgestellt
* 2011-10-17 Zeilenlänge bei CTE steuerbar machen
* 2011-11-02 Ressourcenverzeichnis setzbar machen
* 2011-12-09 Schemavalidierung steuerbar machen
* 2012-02-21 Laufzeitoptimierungen
* 2012-09-18 Koordinatenreferenzsysteme bearbeitet
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2012-10-01 Protokollant nutzt Ausgabe
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2012-10-15 Aufräumen bei Programmende
* 2013-02-04 Profile
* 2013-03-05 Genauigkeit bei der Ausgabe von Koordinaten
* 2013-03-11 Harmonisierung der Schnittstelle
* 2013-09-24 Initialisierung der Umgebung
* 2013-11-18 Transformierer eingeführt
* 2013-01-10 OGR-Transformierer eingebaut
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-04-28 Express-Geometriemodell für Version 2.x
* 2014-06-27 Zugriff auf GDAL-Ressourcen für Tansformierer
* 
****************************************************************************/
#ifndef DEFUmgebung
#define DEFUmgebung

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <memory>
#include <list>

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "OklabiIntern.h"
#include "Protokollant.h"
#include "Fortschrittswaechter.h"
#include "Abbruchsignal.h"
#include "Version.h"
#include "Services.h"
#ifdef OKLABI_SCHEMADB
#include "SchemaDBAdapter.h"
#endif
#include "Transformierer.h"
#ifdef OKLABI_MEMOPT_2
#include "PasIdentifizierer.h"
#endif

namespace Oklabi
{
	class Fachobjekt;
	class Datenbestand;
	class Fachbedeutungsliste;
	typedef bool (*InitializerPtr)(void);
	typedef std::list<Oklabi::InitializerPtr> InitializerListType;
	typedef int (*FinalizerPtr)(void);
	typedef std::list<Oklabi::FinalizerPtr> FinalizerListType;

	class OKLABI_API Umgebung : public OklabiObjekt
	{
		friend class CTEEingabeKonverter;
		friend class CTEAusgabeKonverter;
		friend class XMLAusgabeKonverter;
		friend class XMLAdapter;
#ifdef OKLABI_LOGGING
		friend class Logging;
#endif
#ifdef OKLABI_STATISTIK
		friend class Statistik;
#endif
#ifdef OKLABI_MEMORY
		friend class Speicherverbrauch;
#endif
#ifdef OKLABI_MEMOPT_2
		friend class PasIdentifizierer;
#endif
		friend class LoggingConditional;
		friend class Synchronisation;
		friend class Fachobjekt;
		friend class AnyType;
		friend class Version;
		friend class OklabiObjekt;
		friend class Fachbedeutungsliste;
		friend class Protokollant;
#ifdef OKLABI_SCHEMADB
		friend class SchemaDBAdapter;
#endif
		friend class Text;
		friend class Profil;
		friend class Ausnahme;
		friend class Transformierer;
	public:
		void              Austragen(OklabiObjekt*);

		// Gib das Singleton-Objekt ...
		static Umgebung*  Objekt() /*throw( std::bad_alloc )*/;
		Text GibKlassenname() const;

		static Umgebung*  Starte();	// deprecated
		static void       Beende();	// deprecated
		static void       AktiviereErweiterungen();
		static void       DeaktiviereErweiterungen();
		static bool       GibErweiterungen();
		       void       Registriere(Fachobjekt*);
		       Datenbestand* GibStandardbestand(const Version*);
		       Datenbestand* Standardbestand(const Version*);	// deprecated
		static Protokollant* Registriere(Protokollant*, eProtokollTyp = meldungen);
		static Fortschrittswaechter* Registriere(Fortschrittswaechter*);
		static Abbruchsignal* Registriere(Abbruchsignal*);
		static Transformierer* Registriere(Transformierer*);
		static Transformierer* GibTransformierer();
		static void       SetzeNebenlaeufigkeit(bool);
		static bool       GibNebenlaeufigkeit();
		static void       SetzeAufrufprotokollierung(bool, int = 1);
		static bool       GibAufrufprotokollierung();
		static int        GibAufrufprotokollierungStufe();
		static void       ProtokolliereSpeicherverbrauch(bool, int = 100);
		static void       SchreibeSpeicherverbrauch();
		static void       ProtokolliereStatistik(bool, int = 3);
		static void       ProtokolliereOklabiObjekte(bool, size_t = 500);
		static void       SchreibeOklabiObjekte(size_t = 0, bool = true);
		static Text       GibXMLSchemaVerzeichnis();
		static void       SetzeXMLSchemaVerzeichnis(const Text&);
		static Text       GibFbVerzeichnis();
		static void       SetzeFbVerzeichnis(const Text&);
		static Text       GibRessourcenVerzeichnis();
		static void       SetzeRessourcenVerzeichnis(const Text&);
		static Text       GibPfadTrenner();
		static Text       GibZeilenumbruch();
		static void       SetzeFachbedeutungspruefung(bool);
		static bool       GibFachbedeutungspruefung();
		static void       SetzeFachbedeutungslistenmeldung(bool);
		static bool       GibFachbedeutungslistenmeldung();
		static void       SetzeSchluesseltabellenpruefung(bool);
		static bool       GibSchluesseltabellenpruefung();
		static void       SetzeSchluesseltabelleneinbettung(bool);
		static bool       GibSchluesseltabelleneinbettung();
		static void       SetzeXMLSchemavalidierung(bool);
		static bool       GibXMLSchemavalidierung();
		static Text::eStringType GibTextTyp();
		static Text       GibSRSPraefix();
		static void       SetzeSRSPraefix(const Text&);
		static void       SetzeVerschmelzungSymbolischeObjekte(bool);
		static bool       GibVerschmelzungSymbolischeObjekte();
		static void       SetzeKennungKorrektur(bool);
		static bool       GibKennungKorrektur();
		static Text       GibURNPraefix();
		static void       SetzeURNPraefix(const Text&);

		static void       Melde(int, const Text&, eMeldTyp = fehler, eProtokollTyp = meldungen);
		static bool       Transformiere(Koordinate&, eKoordRefSys);

		static bool       AbbruchstatusErfragen();
		static void       Fortschrittsmeldung(int, eFortTyp);

		static bool       Startend();
		static bool       Beendend();

		static Text       GibOKLABIReleaseDatum();
		static Text       GibOKLABIReleaseVersion();
		static Text       GibOKLABIReleaseVersionURL();
		static Text       GibExpressVersion();
		static Text       GibSchemaDBVersion();
		static Text       GibModell();
		static Text       GibXmlNs();
		static Text       GibXmlUri();
		static Text       GibMetadatenKnoten();

		static eGeoFormat GibGeometrieformat();
		static double     GibVergleichsgenauigkeit();
		static void       SetzeVergleichsgenauigkeit(const double&);
		static double     GibKoordinatengenauigkeit();
		static void       SetzeKoordinatengenauigkeit(const double&);
		static double     GibLaengengenauigkeit();

		static Text       GibTextZuWert(eAufzaehlungen, int);
#ifdef OKLABI_SCHEMADB
		static Text       GibSchemaDBName();
#endif
		template<class T> static void SetzeEinstellung(eEinstellung, const T&);
		template<class T> static T GibEinstellung(eEinstellung);
		static eTyp GibTyp(eEinstellung, eAufzaehlungen&);
		static eTyp GibTyp(eTypkennzeichner, eAufzaehlungen&);

		static eMeldTyp Fehlerstufe( const int& nSeverity );
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const char* pstrP1,
			const char* pObjId, const char* pstrCTX);
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const char* pstrP1, const char* pstrP2,
			const char* pObjId, const char* pstrCTX);
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const char* pstrP1, const char* pstrP2, const char* pstrP3,
			const char* pObjId, const char* pstrCTX);
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const char* pstrP1, const char* pstrP2, const char* pstrP3,
			const char* pstrP4, const char* pObjId, const char* pstrCTX);
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const char* pstrP1, const size_t& nP1,
			const char* pObjId, const char* pstrCTX);
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const char* pstrP1, const size_t& nP1, const size_t& nP2,
			const char* pObjId, const char* pstrCTX);
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const char* pstrP1, const size_t& nP1, const size_t& nP2, const size_t& nP3,
			const char* pObjId, const char* pstrCTX);
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const char* pstrP1, const char* pstrP2, const size_t& nP1, const size_t& nP2, const size_t& nP3,
			const char* pObjId, const char* pstrCTX);
		static void Fehlermeldung(const char* pxonam, const char* pstrId, const size_t& nP1,
			const char* pObjId, const char* pstrCTX);

		// Ausgabe von Meldungsfenster
		static void Warnung(HWND, const Text&, const wchar_t*, int);

		// Registrierung von Initialisierungs-Handlern
		static bool Initialisierer(InitializerPtr);

		// Registrierung von Abschluss-Handlern (analog zu atexit)
		static void Finalisierer(FinalizerPtr);

	private:
#ifdef OKLABI_KERN
		// Ctor & Dtor ...
		Umgebung() /*throw( std::bad_alloc )*/;
		~Umgebung() /*throw()*/;
		bool KannVernichten() const;
		void InitBestandVektor();

		// Lebensdauerkontrolle für das Singleton ...
		friend class std::auto_ptr<Umgebung>;
		static std::auto_ptr<Umgebung> dasObjekt;

	public:
		typedef const char*					      PoolStringType;
		class ccmp : public OklabiRoot
		{
		public:
			OKLABI_API bool operator()(PoolStringType x, PoolStringType y) const;
		};
		typedef std::map< PoolStringType, int, ccmp > PoolStringMapType;
		typedef std::multimap< const char*, const char**, Umgebung::ccmp > FblisteMapType;

	private:

		static void EntferneProtokollant(Protokollant*);
		static void EntferneTransformierer(Transformierer*);

		static bool LiesProfil(Text::eStringType&, bool bReset = false);
		static void Finalize();
		static void Cleanup();
		static InitializerListType*   m_pListInitializer;
		static FinalizerListType*     m_pListFinalizer;

		static void ClearPoolString();
		static Umgebung::PoolStringType S_Text( Umgebung::PoolStringType val, bool bConst = false );
		static void L_Text( Umgebung::PoolStringType val );

	private:
		static Umgebung::PoolStringMapType      m_mapString;
		static int                    m_RefCount;
		static long                   m_nExitFlag;
		static Protokollant*          m_pProtoObj;
		static Protokollant*          m_pProtoStatus;
		static Fortschrittswaechter*  m_pFortschrObj;
		static Abbruchsignal*         m_pAbbruchObj;
#ifdef OKLABI_LOGGING
		static Protokollant*          m_pProtoLogg;
#endif
#ifdef OKLABI_STATISTIK
		static Protokollant*          m_pProtoStat;
#endif
		static Transformierer*        m_pTransformer;
		static bool                   m_bThreading;
		static int                    m_nThreadingLevel;
		static bool                   m_bLogging;
		static int                    m_nLogLevel;
		static bool                   m_bMemStat;
		static int                    m_nMemLevel;
		static bool                   m_bMemHole;
		static size_t                 m_nMemHoleReportSize;
		static bool                   m_bStatistic;
		static int                    m_nStatLevel;
		static bool                   m_bExtension;
		static bool                   m_bGeoKomp;
		static bool                   m_bDomainMerge;
		static bool                   m_bIDFix;
		static Text                   m_strXMLSchema;
		static Text                   m_strFbliste;
		static Text                   m_strProfile;
		static Text                   m_strRessourcen;
		static Text                   m_strProtokoll;
		static bool                   m_bProfilGelesen;
		static bool                   m_bEmbedKeytable;
		static bool                   m_bFbListValidate;
#ifdef OKLABI_SCHEMADB
		static Text                   m_strSchemaDBName;
#endif
		static Text::eStringType      m_eTextType;
		static bool                   m_bWarnungen;
		static size_t                 m_nCharPerCTELine;
		static bool                   m_bCTE1010Error;
		static bool                   m_bVerbose;
		static bool                   m_bDeveloper;
		static bool                   m_bMeldet;
		static bool                   m_bStackTrace;
		static bool                   m_bXMLRelBeidseitig;
		static bool                   m_bXMLSchemaValidierung;
		static bool                   m_bOgrTransformierer;
		static bool                   m_bExpressGeometrie;
		static Text                   m_strSRSPrefix;
		static Text                   m_strURNPrefix;
		static Text                   m_strGdalData;
		static size_t                 m_nPagePoolSize;
		static int                    m_nPasLevel;

		class lessSRS : public OklabiRoot
		{
		public:
			bool operator() ( const std::pair<Text,Text> p, const std::pair<Text,Text> q ) const;
		};

		typedef std::map<Text,eKoordRefSys>                      CODEtoENUMmapType;
		typedef std::map<eKoordRefSys, Text>                     ENUMtoCODEmapType;
		typedef std::map<Text,std::pair<Text,Text> >             CODEtoSRSmapType;
		typedef	std::multimap<std::pair<Text,Text>,Text,lessSRS> SRStoCODEmapType;
		static CODEtoSRSmapType m_mapCODEtoSRS;
		static SRStoCODEmapType m_mapSRStoCODE;
		static ENUMtoCODEmapType m_mapENUMtoCODE;
		static CODEtoENUMmapType m_mapCODEtoENUM;
		static void InitSRSmaps();
		static void L_SRSMaps();
		static void H_SRSMaps( const Text& strPRS, const Text& strCOO, const Text& strSRS );
		static void CODEnachSRS( Text& strCODE, Text& strPosRef, Text& strCoord );
		static void CODEnachSRS( const Text& strCODE, eKoordRefSys& );
		static void SRSnachCODE( Text& strPosRef, Text& strCoord, Text& strCODE );
		static void SRSnachCODE( Text& strPosRef, Text& strCoord, Text& strCODE, const Text& strPrefix );
		static void SRSnachCODE( const eKoordRefSys&, Text& strCODE );
		static void ResetSRSMaps();
		static void SpeichereKompakteGeometrie(bool);
		static bool GibKompakteGeometrie();

		static Text Fachobjektkennung(Fachobjekt*);

		bool Gib_FbListe(const FblisteMapType&, bool, const char*, const eFbGeoTyp&, const eBundesland&, TextListe*, TextListe*, TextListe*);
		bool Gib_FbListe_13(const char*, const eFbGeoTyp&, const eBundesland&, TextListe*, TextListe*, TextListe*);
		bool Gib_FbListe_14(const char*, const eFbGeoTyp&, const eBundesland&, TextListe*, TextListe*, TextListe*);
		bool Gib_FbListe_15(const char*, const eFbGeoTyp&, const eBundesland&, TextListe*, TextListe*, TextListe*);
		bool Gib_FbListe_16(const char*, const eFbGeoTyp&, const eBundesland&, TextListe*, TextListe*, TextListe*);
		bool Gib_Langtexte_FbListe(const Fachobjekt*, const Fachbedeutungsliste*, const char*, const eFbVersion&, const eFbGeoTyp&, const eBundesland&, TextListe*, TextListe* = 0, TextListe* = 0);
#endif
};

// Explizite Instanzierungen
template<> OKLABI_API void   Umgebung::SetzeEinstellung<Text>(eEinstellung, const Text&);
template<> OKLABI_API void   Umgebung::SetzeEinstellung<int>(eEinstellung, const int&);
template<> OKLABI_API void   Umgebung::SetzeEinstellung<bool>(eEinstellung, const bool&);
template<> OKLABI_API void   Umgebung::SetzeEinstellung<double>(eEinstellung, const double&);

template<> OKLABI_API Text   Umgebung::GibEinstellung<Text>(eEinstellung);
template<> OKLABI_API int    Umgebung::GibEinstellung<int>(eEinstellung);
template<> OKLABI_API bool   Umgebung::GibEinstellung<bool>(eEinstellung);
template<> OKLABI_API double Umgebung::GibEinstellung<double>(eEinstellung);
}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFUmgebung
