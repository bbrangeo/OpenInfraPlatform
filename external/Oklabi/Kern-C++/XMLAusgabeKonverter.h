/*****************************************************************************
* $Id: XMLAusgabeKonverter.h 2014-03-27 15:00:00 vogelsang $
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
* 2011-03-18 Schlüsseltabellen sind GML-Feature ab Version 1.015
* 2011-05-10 Normierte Ausgabe
* 2012-02-21 Laufzeitoptimierungen
* 2012-05-14 Inkrementelles Entladen
* 2013-02-04 Geometrieausgabe bei UML-Modellierung
* 2013-02-04 Profile
* 2013-06-10 Ausgabe gml:id überarbeitet
* 2013-10-31 Speicheroptimierungen bei Strings und Collections
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-03-27 Genauigkeit bei Vektoren
* 
****************************************************************************/
// Der XMLAusgabeKonverter erstellt zu den Objekten
// eines Datenbestandes eine zugehörige OKSTRA-XML-Datei.

#include "OklabiPackaging.h"

#ifndef DEFXMLOutputCv
#define DEFXMLOutputCv

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "AusgabeKonverter.h"
#include "Ausgabe.h"
#include "Koordinate.h"
#include "XMLAdapter.h"

namespace Oklabi
{
typedef std::map<const Objektart*,bool>         mapCheckGeoType;
typedef std::map<const Objektart*,bool>         mapCheckInherType;

typedef std::map<FachobjektReferenz,Text>       FachobjektXmlIdMapType;

struct RootAttribute
{
	Text            m_strAtt;
	XmlNamespace    m_eAttNs;
	Text            m_strVal;

	RootAttribute( const char* strAtt, XmlNamespace eAttNs, const char* strVal )
	{
		m_strAtt = strAtt;
		m_eAttNs = eAttNs;
		m_strVal = strVal;
	};
};

typedef std::list<RootAttribute>	RootAttributeListType;

enum XMLObjectSource{ _XMLDatenbestand, _XMLFachobjektMenge, _XMLSorted };

class Datenbestand;

class OKLABI_API XMLAusgabeKonverter : public AusgabeKonverter
{
	friend class XMLAdapter;
	friend class XMLAusgabeGenerator;
public:
	static XMLAusgabeKonverter*	Erzeuge(Ausgabe*);
	void                        SetzeSortierung( eSort = ohne );
	void                        TransportiereErweiterungen( bool = false );
	void                        SetzeMetadaten(eMetadaten, const Text&);
	void                        SetzeRootTag(eRootTag, const Text&);
	void                        SetzeSchemaLocation(const Text& strSL);
	bool                        SetzeZeichensatz(const Text& strCode);
	void                        Entlade( Datenbestand* pDB );
	void                        SetzeFblVersion(const FblVersion*);
	void                        Komprimiere(bool);
	Text						GibKlassenname() const;

	void                        BetteSchluesseltabellenEin(bool);
	void                        SetzeProfilerkennung(bool = true);

#ifdef OKLABI_KERN
private:
	XMLAusgabeKonverter(XMLAdapter*);
	~XMLAusgabeKonverter();

	XMLAdapter*                 m_pXMLAdapter;

	Text                        m_strSpecVers;

	XMLObjectSource             m_eSource;

	typedef std::map<Text,int>  KlasseNrMapType;
	KlasseNrMapType             m_mapKlasseNr;
	ClsConfMapType              m_mapClsConf;

	typedef std::multimap<Text,FachobjektReferenz>	LocEntityIdMapType;

	LocEntityIdMapType				m_mmapId;
	LocEntityIdMapType::iterator	m_iterId;

	bool                        m_bUrnExtern;
	bool                        m_bObjMIso;
	bool                        m_bRelEins;

	bool                        m_bLocId;
	FachobjektXmlIdMapType      m_mapLocId;
	void                        LokaleXmlIdSetzen( Fachobjekt* pxoObj, const Text& strId );
	Text                        LokaleXmlIdSuchen( Fachobjekt* pxoObj );

	bool                        m_bKeyEmb;
	bool                        m_bGeoRef;
	bool                        m_bFirst;
	bool                        m_bSwitchKoord;
	Text                        m_strBBoxSRSName;

	Datenbestand*               m_pDomain;
	Datenbestand::ObjectCollection::iterator m_iterDom;

	FachobjektMengeImpl*        m_pSet;
	FachobjektMengeImpl::iterator  m_iterSet;

	Text                        m_strOkstra, m_strOkstraBasis;
	std::string                 m_strOkstraHat_Teilabschnitt;
	std::string                 m_strOkstraEnthaelt_Teilabschnitt;
	std::string                 m_strOkstraKeyValue;
	std::string                 m_strOkstraMetaData;
	std::string                 m_strOkstraLangtext;
	std::string                 m_strOkstraKennung;
	std::string                 m_strOkstraDescription;
	std::string                 m_strOkstraImplementation_level;
	std::string                 m_strOkstraName;
	std::string                 m_strOkstraTime_stamp;
	std::string                 m_strOkstraAuthor;
	std::string                 m_strOkstraOrganization;
	std::string                 m_strOkstraPreprocessor_version;
	std::string                 m_strOkstraOriginating_system;
	std::string                 m_strOkstraAuthorization;
	std::string                 m_strOkstraSchema_identifiers;
	std::string                 m_strOkstraRelRep;
	std::string                 m_strOkstraDargestellt_von_Knoten;
	std::string                 m_strOkstraDargestellt_von_Kante;
	std::string                 m_strOkstraDargestellt_von_Masche;
	std::string                 m_strOkstraDargestellt_von_Koerper;
	std::string                 m_strOkstraDargestellt_von_Punkt;
	std::string                 m_strOkstraDargestellt_von_Linie;
	std::string                 m_strOkstraDargestellt_von_Flaeche;
	std::string                 m_strOkstraDargestellt_von_Volumen;
	std::string                 m_strOkstraBeginnt_bei_Station;
	std::string                 m_strOkstraBeginnt_mit_Abstand_zur_Bestandsachse;
	std::string                 m_strOkstraBeginnt_mit_Abstand_zur_Fahrbahnoberkante;
	std::string                 m_strOkstraEndet_bei_Station;
	std::string                 m_strOkstraEndet_mit_Abstand_zur_Bestandsachse;
	std::string                 m_strOkstraEndet_mit_Abstand_zur_Fahrbahnoberkante;
	std::string                 m_strOkstraAuf_Abschnitt_oder_Ast;
	Text                        m_strGml;
	Text                        m_strXlink;
	std::string                 m_strXlinkHref;
	std::string                 m_strGmlId;
	std::string                 m_strGmlName;
	std::string                 m_strGmlMetaDataProperty;
	std::string                 m_strGmlBoundedBy;
	std::string                 m_strGmlNull;
	std::string                 m_strGmlEnvelope;
	std::string                 m_strGmlCoordinates;
	std::string                 m_strGmlNode;
	std::string                 m_strGmlDirectedEdge;
	std::string                 m_strGmlContainer;
	std::string                 m_strGmlPointRep;
	std::string                 m_strGmlPointProperty;
	std::string                 m_strGmlEdge;
	std::string                 m_strGmlDirectedNode;
	std::string                 m_strGmlCurveProperty;
	std::string                 m_strGmlFace;
	std::string                 m_strGmlIsolated;
	std::string                 m_strGmlSurfaceProperty;
	std::string                 m_strGmlTopoSolid;
	std::string                 m_strGmlDirectedFace;
	std::string                 m_strGmlPoint;
	std::string                 m_strGmlPos;
	std::string                 m_strGmlCurve;
	std::string                 m_strGmlSegments;
	std::string                 m_strGmlLineStringSegment;
	std::string                 m_strGmlArc;
	std::string                 m_strGmlCubicSpline;
	std::string                 m_strGmlVectorAtStart;
	std::string                 m_strGmlVectorAtEnd;
	std::string                 m_strGmlPolygon;
	std::string                 m_strGmlExterior;
	std::string                 m_strGmlRing;
	std::string                 m_strGmlCurveMember;
	std::string                 m_strGmlSolid;
	std::string                 m_strGmlInterior;
	Text                        m_str_Punktobjekt;
	Text                        m_str_Streckenobjekt;
	Text                        m_str_Bereichsobjekt;
	Text                        m_str_hat_Strassenpunkt;
	Text                        m_str_Strassenpunkt_PO;
	Text                        m_str_Strassenpunkt_TA;
	Text                        m_str_Strassenpunkt_PoB;
	Text                        m_str_Teilabschnitt_Str;
	Text                        m_str_Teilabschnitt_IdNT;
	Text                        m_str_Abschnitt;
	Text                        m_str_Ast;
	Text                        m_str_von_Strasse;
	Text                        m_str_verallgemeinerte_Strecke;
	Text                        m_str_Netzbereichskomponente;
	Text                        m_str_Linienfunktion;
	Text                        m_str_tangentialer_Anschluss;
	const Objektart*            m_pHistorisch;
	const Objektart*            m_pPunktobjekt;
	const Objektart*            m_pStreckenobjekt;
	const Objektart*            m_pBereichsobjekt;
	const Objektart*            m_pTeilabschnitt;
	const Objektart*            m_pStreckenobjekt_hist;
	const Objektart*            m_pPunktobjekt_hist;
	const Objektart*            m_pBereichsobjekt_hist;
	const Objektart*            m_pStrecke;
	const Objektart*            m_pStrassenpunkt;
	const Objektart*            m_pStrassenpunkt_TA;
	const Objektart*            m_pLinienelement_3D;

	Text                        m_strRoot;
	XmlNamespace                m_eNsRoot;

	RootAttributeListType       m_listRootAttributes;

	size_t                      size();
	FachobjektReferenz          begin();
	bool                        end();
	FachobjektReferenz          next();
	Text                        key();
	bool                        contained( FachobjektReferenz );

	Datum                       m_datVon;
	Datum                       m_datBis;

	void                        Fehler( Text err, eMeldTyp nLevel = fehler );
	void                        Fehler( Text err, Fachobjekt* pxoObj );

	void                        put( const Text& );
	void                        put( const char* );

	void                        putXML();
	void                        putIntro();
	void                        putMeta();
	void                        putBBox();
	void                        putXML( Fachobjekt*, XmlGen::XmlTag*, bool bEmb = false );
	void                        putXMLK( Fachobjekt* pxoKey );
	void                        putXMLRef( Fachobjekt*, const Text&, XmlGen::XmlTag* );
	void                        putOutro();

	void                        Konkordanz( Fachobjekt*, const Text&, const Text& );

	Text                        transformKey(FachobjektPtr, const Text&, bool = false);
#ifdef OKLABI_INTERN
	bool                        putGeo( Fachobjekt*, const FachobjektMengeImpl&, const Text&, XmlGen::XmlTag* );
	void                        putKnoten( const FachobjektMengeImpl&, XmlGen::XmlTag*, XmlGen::XmlTag* tagProp, bool bFirst = false );
	void                        putKante( const FachobjektMengeImpl&, XmlGen::XmlTag*, XmlGen::XmlTag* tagProp, bool bFirst = false );
	void                        putMasche( const FachobjektMengeImpl&, XmlGen::XmlTag*, XmlGen::XmlTag* tagProp, bool bFirst = false );
	void                        putKoerper( const FachobjektMengeImpl&, XmlGen::XmlTag*, bool bFirst = false );
	void                        putPunkt( const FachobjektMengeImpl&, XmlGen::XmlTag*, XmlGen::XmlTag* tagProp, bool bFirst = false );
	bool                        appPointLE( XmlGen::XmlTag*&, XmlGen::XmlTag*&, XmlGen::XmlTag*&,
                                    XmlGen::XmlTag*&, XmlGen::XmlTag*&, FachobjektMengeImpl&, Text&, Text&, bool&, Koordinate& );
	void                        putLinie( const FachobjektMengeImpl&, XmlGen::XmlTag*, XmlGen::XmlTag* tagCurve, bool bRing, bool bFirst = false );
	void                        putFlaeche( const FachobjektMengeImpl&, XmlGen::XmlTag*, XmlGen::XmlTag* tagInt, bool bFirst = false );
	void                        addFlaechenelemente( FachobjektMengeImpl& pxosetFE, Fachobjekt* pxoObj, FachobjektMengeImpl& pxosetCyc );
	void                        putVolumen( const FachobjektMengeImpl&, XmlGen::XmlTag*, bool bFirst = false );
#endif
	Text                        getXMLKoo( const Koordinate& koo, char cSep = ',', int nPrec = -1 );
	bool                        putUmlGeo( Fachobjekt*, const Geometrie*, const Eigenschaft*, XmlGen::XmlTag* );
	void                        putUmlPunkt( Fachobjekt*, const GeoPunkt*, const Eigenschaft*, XmlGen::XmlTag*, XmlGen::XmlTag* tagProp );
	void                        putUmlLinie( Fachobjekt*, const GeoLinie*, const Eigenschaft*, XmlGen::XmlTag*, XmlGen::XmlTag* tagProp );
	void                        putUmlSegment( Fachobjekt*, const GeoLinie*, const Eigenschaft*, XmlGen::XmlTag*, XmlGen::XmlTag* tagProp, XmlGen::XmlTag*& tagSeg, XmlGen::XmlTag*& tagCoo, GeoPunkt& last);
	void                        putUmlFlaeche( Fachobjekt*, const GeoFlaeche*, const Eigenschaft*, XmlGen::XmlTag*, XmlGen::XmlTag* tagProp );
	Text                        getXMLKoo( const GeoPunkt& koo, char cSep = ',', int nPrec = -1 );
	mapCheckGeoType             m_mapCheckGeo;
	bool                        istGeo( Fachobjekt* );
	mapCheckGeoType             m_mapCheckGeoRep;
	bool                        repGeo( Fachobjekt* );
	void                        setGeoWritten( Fachobjekt*, bool bMode = true );
	bool                        isGeoWritten( Fachobjekt* );
	bool                        isRepresented( const Objektart*, const Eigenschaft* );
	FachobjektMengeImpl         m_pxosetGeoWritten;

	void                        putTA( Fachobjekt*, XmlGen::XmlTag* );
	void                        putAoAhatTA( Fachobjekt* pxoObj, XmlGen::XmlTag* );
	void                        putAoAhatSP( Fachobjekt* pxoObj, XmlGen::XmlTag* );

	Text                        getRootElement();
	Text                        getXMLId( Fachobjekt*, char cPre = '\0' );

	void                        Transscript( Text& str );
	Text*                       m_pOff;
	Text*                       m_pRep;
	Text                        m_strCS;
	void                        redKonz( const Objektart*, EigenschaftListType& );
	void                        removeProp( const Text&, EigenschaftListType& );

	mapCheckInherType           m_mapCheckInher;
	bool                        isInher( Fachobjekt* pxoObj );

	bool                        isDef( const Objektart* );

	void                        AusgabeInitialisieren();
	
	Text                        m_strSL;
	Text                        m_strRL;

	int                         m_nEnumId;

	bool                        m_bExtension;

	int                         m_nOpenCount;
	bool                        m_bControlled;
	BoundingBox                 m_BBox;
	void                        BeginneAusgabe();
	void                        BeginneEntladen(Datenbestand* pDomain, Datum datVon, Datum datBis);

// Member-Variablen für die Header Section
	
	// File-Description
	TextListe                   m_strlistFDDescription;
	// Implementation Level ist stets '1'

	// File-Name
	Text                        m_strFNName;	// wird von der Ausgabe-Datei erfragt, falls leer
	// Time Stamp wird vom System erfragt
	TextListe                   m_strlistFNAuthor;
	TextListe                   m_strlistFNOrganization;
	// Preprocessor Version ist stets "OKLABI"
	Text                        m_strFNOriginatingSystem;
	Text                        m_strFNAuthorization;
	
	// File-Schema
	// Schema Identifiers: ergänzt wird "OKSTRA x.yyy", je nach eingestellter OKSTRA-Version
	TextListe                   m_strlistFSSchemaIdentifiers;

	void                        AusgabedateiSetzen(Ausgabe* pDatei);
	void                        KonkordanzSetzen(Ausgabe* pDatei, const char* pFieldDelimit,
												 const char* pStringDelimit, const char* pIdPrefix);

	void                        RootElementSetzen(const Text& strRoot, const XmlNamespace& eNsRoot);
	void                        RootAttributeErgaenzen( const Text& strAtt, const Text& strVal, const XmlNamespace& eNsAtt = XmlnsUnknown );
	void                        RootAttributesLoeschen();

	void                        UrnExtern( bool bUrnExtern );
	void                        LokaleXMLIdVerwenden( bool bLocId );
	void                        ObjektMengeIsolieren( bool bObjMIso );
	void                        RelationenEinseitig( bool bRelEins );
	
	void                        SpezielleVersionSetzen( Text strVers );

//	void                        SchluesseltabellenEinbetten( bool bEmb );
	void                        GeometrieReferenzieren( bool bGeoRef );
	void                        GeometrieEinbettenFirstLevel( bool bFirst );
	void                        KoordinatenVertauschen( bool bSwitchKoord );
	void                        S_BBoxSRSName( const Text& strBBoxSRSName );

// Methoden für die Header Section

private:
	// File-Description
	void                        H_FDDescription( const Text& strVal );
	// Implementation Level ist stets '1'
	
	// File-Name
	void                        S_FNName( const Text& strVal );
	// Time Stamp wird vom System erfragt
	void                        H_FNAuthor( const Text& strVal );
	void                        H_FNOrganization( const Text& strVal );
	// Preprocessor Version ist stets "OKLABI"
	void                        S_FNOriginatingSystem( const Text& strVal );
	void                        S_FNAuthorization( const Text& strVal );

	// File-Schema
	// Schema Identifiers: ergänzt wird "OKSTRA x.yyy", je nach eingestellter OKSTRA-Version
	void                        H_FSSchemaIdentifiers( const Text& strVal );

	void                        Uebernehmen( XMLEingabeKonverter* pICv );
	void                        HeaderLoeschen();
	void                        Entlade( Datenbestand* , Datum von, Datum bis );
#endif
};

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFXMLOutputCv
