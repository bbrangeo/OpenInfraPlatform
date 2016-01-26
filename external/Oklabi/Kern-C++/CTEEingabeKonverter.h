/*****************************************************************************
* $Id: CTEEingabeKonverter.h 2015-02-03 15:00:00 vogelsang $
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
* 2010-12-14 Vorschau auf Eingabedaten
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2013-02-04 Profile
* 2013-09-24 Sondebehandlungen beim Laden von direct_position
* 2013-11-18 Transformierer eingeführt
* 2015-02-03 CTE String im Header dekodieren
* 
****************************************************************************/
#ifndef DEFCTEInputCv
#define DEFCTEInputCv

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "EingabeKonverter.h"
#include "Eingabe.h"

namespace Oklabi
{
typedef std::map<int,OklabiObjekt*>     LocCTEObjMapType;
typedef std::map<int,const Objektart*>  LocCTEObjMapTypeIgnored;

struct valCTEType;

class OKLABI_API CTEEingabeKonverter : public EingabeKonverter
{
	friend class CTEAusgabeKonverter;

public:
	static CTEEingabeKonverter*	Erzeuge(Eingabe* d);
	Text						GibKlassenname() const;
	Version*					GibVersion();
	FblVersion*					GibFblVersion();
	Datenbestand*				Lade(Objektartfilter* pFilt = 0, Objektartfilter* pSymb = 0);
	void						TransportiereErweiterungen(bool = false);
	void                        VerschmelzeSymbolischeObjekte(bool = true);
	TextListe					GibMetadaten(eMetadaten);
	void						ErlaubeFormatfehler(bool = false);
	TextListe                   GibObjektarten();
	size_t                      GibAnzahlObjekte(const Text&);
	void                        SetzeProfilerkennung(bool = true);
	void                        Transformiere(eKoordRefSys);

private:
	LocCTEObjMapType			m_pmapObjectMap;
	LocCTEObjMapTypeIgnored		m_pmapObjectMapIgnored;
	ClsConfMapType				m_mapClsConf;

	Text						IdPraefixBestimmen();
	int							ExtractEntityInstanceName();
	void						Startmeldung();
	void						Schlussmeldung();
	bool						abgebrochen();

	bool						CTEInitObj( OklabiObjekt* pxoObj, const char* pstrDef, size_t& nDAnf, size_t& nDEnd, size_t& nWAnf, size_t& nWEnd,
									Text& strProp, valCTEType& valCTE );
	bool						CTEToProp( const Text&, const Eigenschaft*, const char* pstrWork, size_t& nWAnf, size_t& nWEnd, valCTEType& valCTE );
	bool						CTEToRel( const Text&, const char* pstrWork, size_t& nWAnf, size_t& nWEnd, valCTEType& valCTE, const Text& );
	bool						CTEToNumber( const Text&, const char* pstrWork, size_t& nWAnf, size_t& nWEnd, valCTEType& valCTE, eTyp eT, bool bSig );
	bool						CTEToStr( const eAggreg&, const Text&, const char* pstrWork, size_t& nWAnf, size_t& nWEnd, valCTEType& valCTE, bool = true );
	bool						CTEToBinary( const Text&, const char* pstrWork, size_t& nWAnf, size_t& nWEnd, valCTEType& valCTE );
	bool						CTEToDate( const Text&, const char* pstrWork, size_t& nWAnf, size_t& nWEnd, valCTEType& valCTE );
	bool						CTEToBool( const Text&, const char* pstrWork, size_t& nWAnf, size_t& nWEnd, valCTEType& valCTE );

	char						m_cTemp;
	bool						m_bLiteral;

	char						Read();
	char						ReadCh();
	bool						ReadUpTo(const char* str);
	bool						ReadNext(const char* str);
	void						UnRead(char ch);
	char						Trim();
	void						Trim(const char* pstr, size_t& nAnf, size_t& nEnd, const char& ch1, const char& ch2);
	bool						Extract(char del);
	char*						ExtractUpTo(char del);
	bool						ExtractNumber(int& nr);
	bool						ExtractString(Text& strVal, bool = true, bool = true);
	bool						ExtractStringList(TextListe& strlist);
	int	                        ExtractVersion();
	bool						ReadHeader( bool bVersLog );
	bool						nibble( const char* pstrDef, size_t& nDAnf, size_t& nDEnd, size_t& nWAnf, size_t& nWEnd );
	bool						prefixWas( const char* pstrVal, size_t& nAnf, size_t& nEnd, char cTest );
	bool						suffixWas( const char* pstrVal, size_t& nAnf, size_t& nEnd, char cTest );

	void						SchluesselPruefen( Fachobjekt* pxoObj );
	int							m_nEntNo;
	bool						m_bIdGen;
	char						m_cBuff[10000];
	char*						m_pszBuff;
	int							m_nMax;
	int							m_nOffs;
	int							m_nBase;
	int                         m_nPass;
	bool						m_bClsId;
	bool						m_bExtension;
	bool						m_bStrict;
	bool                        m_bPunkt;
	bool                        m_bSaveMem;

	Umgebung*					m_pServer;
	Datenbestand*               m_pDomain;

// Member-Variablen für die Header Section
	// File-Description
	TextListe					m_strlistFDDescription;
	Text						m_strFDImplementationLevel;
	// File-Name
	Text						m_strFNName;
	Text						m_strFNTimeStamp;
	TextListe					m_strlistFNAuthor;
	TextListe					m_strlistFNOrganization;
	Text						m_strFNPreprocessorVersion;
	Text						m_strFNOriginatingSystem;
	Text						m_strFNAuthorization;
	// File-Schema
	TextListe					m_strlistFSSchemaIdentifiers;

	Eingabe*					m_pDatei;

	Text						m_strIdPraefix;
	bool						m_bUsePrefix;

	Text						m_strOKSTRA;

	Datum                       m_Heute;
	
	CTEEingabeKonverter();
	~CTEEingabeKonverter();

// Methoden für die Header Section
	// File-Description
	bool						E_FDDescription( TextListe& strList );
	bool						E_FDImplementationLevel( Text& strVal );
	// File-Name
	bool						E_FNName( Text& strVal );
	bool						E_FNTimeStamp( Text& strVal );
	bool						E_FNAuthor( TextListe& strList );
	bool						E_FNOrganization( TextListe& strList );
	bool						E_FNPreprocessorVersion( Text& strVal );
	bool						E_FNOriginatingSystem( Text& strVal );
	bool						E_FNAuthorization( Text& strVal );
	// File-Schema
	bool						E_FSSchemaIdentifiers( TextListe& strList );

	Version						ErfrageOKSTRAVersion();
	Text						ErfrageOKSTRAVersionString();

	void						EingabedateiSetzen(Eingabe* pDatei);

	void						SetzeIdGen( bool bIdGen );
	void						SetzeIdPraefix( Text strPraefix, bool = false );
	void						SetzeIdMitKlasse( bool bClsId );
	void						SetzeIdOffset( int nOffs );
	int							ErfrageIdOffset( ) const;
	Text                        GibObjektId(const Objektart*, FachobjektPtr, const Text&, const Text&, int pass);

	OklabiObjekt*               FindeObjekt(int nId, const Text& strOA, bool bRekurs = false);

private:
	void						HeaderLaden(const bool = true);
	void						Lade(Datenbestand* db, Objektartfilter* pFilt, Objektartfilter* pSymb);
	void						LadenIntern(Datenbestand* db);
	void						setzeKlassenauswahlIgnorieren( Objektartfilter* );
	void						setzeKlassenauswahlOhneID( Objektartfilter* );
	void						setzeKlassenauswahlSymbol( Objektartfilter* );
	bool                        Zaehle(const Text&, const Objektart*, int, bool);

	void						Zaehle();

protected:
	void						Identitaetswechsel(FachobjektPtr, FachobjektPtr, const Text&);

	Objektartfilter*			m_pKlassenIgnorieren;
	Objektartfilter*			m_pKlassenOhneID;
	Objektartfilter*			m_pKlassenSymbol;
};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFCTEInputCv
