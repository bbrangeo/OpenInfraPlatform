/*****************************************************************************
* $Id: CTEAusgabeKonverter.h 2014-01-17 15:00:00 vogelsang $
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
* 2010-11-23 Komprimierte Ein- und Ausgabe
* 2010-12-09 Speicherung der Fachobjekte optimieren
* 2011-01-20 Ausgabe bei kompakter Geometriespeicherung
* 2011-05-10 Normierte Ausgabe
* 2012-09-18 Koordinatenreferenzsysteme bearbeitet
* 2013-02-04 Profile
* 2013-03-05 Genauigkeit bei der Ausgabe von Koordinaten
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFCTEOutputCv
#define DEFCTEOutputCv

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "OklabiKern.h"
#include "Objektartfilter.h"
#include "AusgabeKonverter.h"
#include "Ausgabe.h"

namespace Oklabi
{
typedef std::map<FachobjektReferenz,int,std::less<FachobjektReferenz> > LocCTEIdMapType;
typedef std::multimap<UINT64,FachobjektReferenz>                        LocEntityNumMapType;
typedef std::multimap<Text,FachobjektReferenz>                          LocEntityIdMapType;
typedef std::multimap<Text,Text>                                        LocClsCTEMapType;

class CTEEingabeKonverter;

class OKLABI_API CTEAusgabeKonverter : public AusgabeKonverter
{
public:
	static CTEAusgabeKonverter*		Erzeuge(Oklabi::Ausgabe*);
	Text							GibKlassenname() const;
	void							TransportiereErweiterungen( bool = false );
	void							Entlade(Datenbestand* pD);
	void							SetzeSortierung( eSort = ohne );
	void							SetzeMetadaten(eMetadaten, const Text&);
	void							SetzeFblVersion(const FblVersion*);
	void                            Komprimiere(bool);
	void                            SetzeProfilerkennung(bool = true);

private:
	LocCTEIdMapType                 m_imapCTEIdMap;

	Datenbestand::ObjectCollection::iterator m_iter;
	Datenbestand*                   m_pDomainDP;
	Datenbestand*                   m_pDomainKT;
	int                             m_nDPid;

	LocEntityNumMapType             m_mmapNumerisch;
	LocEntityNumMapType::iterator   m_numIter;

	LocEntityIdMapType              m_mmapId;
	LocEntityIdMapType::iterator    m_idIter;

	LocClsCTEMapType                m_mmapClsCTE;
	ClsConfMapType                  m_mapClsConf;

	void                            AusgabeInitialisieren( Datenbestand* pDomain, bool rebuild );
	void                            Ausgabe( Text& strCTE, const Text& strCls );
	void                            AusgabeAbschliessen();
	FachobjektReferenz              AusgabeNaechstesObjekt( Datenbestand* pDomain, Text& strKey );
	void                            Konkordanz( Fachobjekt* pxoObj, const Text& strCls, const Text& strKey );

	Text                            m_strSpecVers;

	bool                            m_bSep;

	bool                            TesteObjekt(Fachobjekt* obj);

	void                            Startmeldung();
	void                            InitEntityId( Datenbestand* pDomain );
	bool                            addProperty( Fachobjekt* pxoObj, const Text& strNam, Text& strCTE, 
                                                 Text& strSepG, const Eigenschaft* pProp, const Text& strProp, bool& opt, unsigned int& nVal );
	bool                            addPtr( const Text& strProp, Fachobjekt* pxoObj, Text& strCTE, Text& strSep );
	bool                            addString( const Text& strVal, Text& strCTE, Text& strSep );
	bool                            addStringL( const char* pszVal, Text& strCTE, Text& strSep );
	bool                            addInt( int nVal, Text& strCTE, Text& strSep );
	bool                            addDouble( double dVal, Text& strCTE, Text& strSep, bool bInCoo );
	bool                            addFloat( float fVal, Text& strCTE, Text& strSep );
	bool                            addBool( bool bVal, Text& strCTE, Text& strSep );
	bool                            addDate( const Datum& dateVal, Text& strCTE, Text& strSep );
	bool                            addBinary( const Text& strProp, const BinaerdatenPtr& binVal, Text& strCTE, Text& strSep );
	bool                            addEmpty( const Text& strProp, const Eigenschaft* pInfo, Text& strCTE, Text& strSep );
	bool                            abgebrochen();
	void                            breakLine(const Text& strCTEakk, Text& strCTE);

	void                            Fehler(const Text& err, eMeldTyp nLevel = fehler);

	int                             FindeId(Fachobjekt* ref);

	bool                            isDef(const Objektart*);

	int                             EntityNummer();
	int                             m_nEntNo;
	Text                            m_strEntNo;
	Text                            m_strCurCls;
	bool                            m_bEntAusId;

	int                             m_nOffs;

	size_t                          m_nLineLng;

	Umgebung*                       m_pServer;

	Text                            StrToCTE( const Text& val );
	Text                            StrListToCTE( TextListe& listStr );

	Text                            GibVersion();


// Member-Variablen für die Header Section
	
	// File-Description
	TextListe                       m_strlistFDDescription;
	// Implementation Level ist stets '1'

	// File-Name
	Text                            m_strFNName;	// wird von der Ausgabe-Datei erfragt, falls leer
	// Time Stamp wird vom System erfragt
	TextListe                       m_strlistFNAuthor;
	TextListe                       m_strlistFNOrganization;
	// Preprocessor Version ist stets "Oklabi"
	Text                            m_strFNOriginatingSystem;
	Text                            m_strFNAuthorization;
	
	// File-Schema
	// Schema Identifiers: ergänzt wird "OKSTRA x.yyy", je nach eingestellter OKSTRA-Version
	TextListe                       m_strlistFSSchemaIdentifiers;


	CTEAusgabeKonverter();
	~CTEAusgabeKonverter();

	// Methoden für die Header Section

	// File-Description
	void                            H_FDDescription( const Text& strVal );
	// Implementation Level ist stets '1'
	
	// File-Name
	void                            S_FNName( const Text& strVal );
	// Time Stamp wird vom System erfragt
	void                            H_FNAuthor( const Text& strVal );
	void                            H_FNOrganization( const Text& strVal );
	// Preprocessor Version ist stets "Oklabi"
	void                            S_FNOriginatingSystem( const Text& strVal );
	void                            S_FNAuthorization( const Text& strVal );

	// File-Schema
	// Schema Identifiers: ergänzt wird "OKSTRA x.yyy", je nach eingestellter OKSTRA-Version
	void                            H_FSSchemaIdentifiers( const Text& strVal );

	void                            Uebernehmen( CTEEingabeKonverter* pICv );
	void                            HeaderLoeschen();

	void                            AusgabedateiSetzen(Oklabi::Ausgabe* pDatei);
	void                            KonkordanzSetzen(Oklabi::Ausgabe* pDatei, const char* pFieldDelimit,
                                                     const char* pStringDelimit, const char* pIdPrefix);


	void                            SpezielleVersionSetzen( Text strVers );
	void                            EntityNrAusObjektId( bool bEnt );
	int                             ErfrageIdOffset( ) const;

	void                            EntladenIntern(Datenbestand* pD);
};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFCTEOutputCv
