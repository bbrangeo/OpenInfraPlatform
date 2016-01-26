/*****************************************************************************
* $Id: XMLAdapter.h 2015-02-24 15:00:00 vogelsang $
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
* 2011-03-18 Schlüsseltabellen sind GML-Feature ab Version 1.015
* 2011-07-05 Elementnamen konfigurierbar machen
* 2011-07-14 Lesen von WFS Response
* 2012-02-21 Laufzeitoptimierungen
* 2012-05-14 Inkrementelles Entladen
* 2012-06-25 Laden von Objekt_ID erzeugt Fehler im XML-Format
* 2012-09-18 Koordinatenreferenzsysteme bearbeitet
* 2012-09-27 Attribute im Element gml:coordinates beachten (Trennzeichen)
* 2013-02-04 Profile
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-03-27 XMLMultiEingabeKonverter eingeführt 
* 2014-04-28 Express-Geometriemodell für Version 2.x
* 2014-07-17 Umwandlung von Enum eKoordRefSys in Schlüsseltabellenwert
* 2015-02-24 Referenzielles Geometrieformat(2)
* 
****************************************************************************/
// Zentrale Service-Klasse zur Überbrückung der Modellunterschiede
// zwischen OKSTRA-XML und der OKSTRA-Modellierung in EXPRESS

#include "OklabiPackaging.h"

#ifndef DEFXMLAdapter
#define DEFXMLAdapter

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiObjekt.h"
#include "Objektart.h"
#include "AnyType.h"
#include "Objektartfilter.h"
#include "Eigenschaft.h"
#include "Ausnahme.h"

#ifdef OKLABI_KERN
#include "XercesXML.h"
#endif

namespace Oklabi
{
enum XmlNamespace { XmlnsOkstra, XmlnsBasis, XmlnsOklabi, XmlnsGml, XmlnsWfs, XmlnsXlink, XmlnsXsi, XmlnsUnknown };
enum ExpressMode { ExpressYes, ExpressNo, ExpressUnknown };

#ifdef OKLABI_KERN
typedef	std::map<XmlNamespace,TextListe>   NamespacePrefixMapType;
typedef	std::map<Text,XmlNamespace>        PrefixNamespaceMapType;
typedef	std::map<XmlNamespace,Text>        NamespaceNameMapType;

typedef std::map<Text,Text>                GmlToGeoMapType;
typedef std::map<Text,Text>                XmlToMapType;

typedef std::map<Text,FachobjektReferenz>  XmlIdFachobjektMapType;

typedef std::map<Text,const Eigenschaft*>  ClassToPropMapType;

typedef std::vector<OklabiObjekt*>         vecDPType;

class XMLMultiEingabeKonverter;
class XMLEingabeKonverter;
class XMLAusgabeKonverter;
class Objektartfilter;

class OKLABI_API XMLAdapter : public OklabiObjekt
{
	friend class Umgebung;
	friend class EingabeKonverter;
	friend class XMLMultiEingabeKonverter;
	friend class XMLEingabeKonverter;
	friend class XMLAusgabeKonverter;
	friend class XMLAusgabeGenerator;
	friend class Transaktion;
	friend class Fachobjekt;
	friend class Datenbestand;
	friend class CTEAusgabeKonverter;
	friend class CTEEingabeKonverter;
	friend class Profil;
	friend class SchemaGeo;

private:
	XMLAdapter(bool = false);
	~XMLAdapter();
	bool KannVernichten() const;

	XmlNamespace              m_eDefaultNamespace;

	NamespacePrefixMapType    m_mapNamespacePrefix;
	PrefixNamespaceMapType    m_mapPrefixNamespace;
	NamespaceNameMapType      m_mapNamespaceName;

	GmlToGeoMapType           m_mapGmlToGeo;
	XmlToMapType              m_mapXmlTo;
	XmlIdFachobjektMapType    m_mapXmlIdFachobjekt;

	typedef std::map<const Objektart*,Text>	ClsUrnMapType;
	ClsUrnMapType                           m_mapClsUrn;

	typedef std::map<const Objektart*,Text>	KtPropMapType;
	KtPropMapType                           m_mapKtProp;

	Text                      LangtextPropZuKeytable( Fachobjekt* pxoKt );

	ClassToSymbolMapType      m_mapClassToSymbol;
	ClassToPropMapType        m_mapClassToProp;
	static void	              InitialisiereSymbolischeTabelle(ClassToSymbolMapType&, const Version&);
	XMLEingabeKonverter*      m_pXMLInputCv;

	Text                      m_strRI;
	Text                      m_strOkstra, m_strOkstraBasis;
	Text                      m_strGml, m_strGml32;
	Text                      m_strGmlId, m_strGml32Id;
	std::string               m_strGmlName, m_strGml32Name;
	Text                      m_strXlink;
	std::string               m_strXlinkHref;
	Version                   m_Version;
	void                      SetzeOKSTRAVersion(const Version&);

	Umgebung*                 m_pServer;
	Datenbestand*             m_pDomain;
	XMLAdapter*               m_pGeoAdapter;
	XMLAdapter*               m_pXMLAdapter;
	Datenbestand*             m_pGeoDomain;

	bool                      m_bGeoAdapter;
	ExpressMode               m_eExpress;
	bool                      m_bMsgOptionalMissing;
	bool                      m_bMsgMissing;

	bool                      m_bStatistik;

	void                      SrsEintragen( Fachobjekt* pxoObj, const Text& strPRS, const Text& strCOO );
	OklabiObjekt*             getPos( const XercesXML::DOMNode& nodCoo, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, Text& strSRS );
	OklabiObjekt*             getCoo( const XercesXML::DOMNode& nodCoo, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	OklabiObjekt*             initCoo( Text strCont, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, const char& cSep = ' ', const char& cDecimal = '.' );
	void                      appLineStringSegment( Fachobjekt* pxoObj, Fachobjekt* pxoPktA, Fachobjekt* pxoPktE, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	void                      getCoordinates( vecDPType& vecDP, const XercesXML::DOMNode& nodRep, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, Text& strSRS, Datenbestand* pDom = 0 );
	Fachobjekt*               getPoint( const Text& strProp, const XercesXML::DOMNode& nodRep, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, Text& strSRS, Datenbestand* pDom );

	void                      EigenschaftswertObjekt_IDHinzufuegen( Fachobjekt* pxoObj, const Text& strPropNam, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	void                      EigenschaftswertStrassenbezeichnungHinzufuegen( Fachobjekt* pxoObj, const Text& strPropNam, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	void                      EigenschaftswertStrassenpunktHinzufuegen( Fachobjekt* pxoObj, const Text& strPropNam, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	void                      EigenschaftswertTeilabschnittHinzufuegen( Fachobjekt* pxoObj, const Text& strPropNam, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	void                      EigenschaftswertIdentischesNetzteilHinzufuegen( Fachobjekt* pxoObj, const Text& strPropNam, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	void                      EigenschaftswertPunktvermarkungHinzufuegen( Fachobjekt* pxoObj, const Text& strPropNam, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	void                      EigenschaftswertGMLHinzufuegen( Fachobjekt*& pxoObj, const Text& strProp, const Text& strEmb, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, const char* pszSRS = 0, const char* pszRel = 0 );
	Fachobjekt*               EigenschaftswertPointHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, Datenbestand* pDom = 0, bool bFirst = true );
	Fachobjekt*               EigenschaftswertNodeHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, bool bIso = false );
	Fachobjekt*               EigenschaftswertCurveHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, const char* pszSRS = 0, const char* pszRel = 0, bool bFirst = true );
	Fachobjekt*               EigenschaftswertLineStringHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, const char* pszSRS = 0, const char* pszRel = 0, bool bFirst = true );
	void                      EigenschaftswertLineStringSegmentHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, Text& strSRS );
	void                      EigenschaftswertArcHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, Text& strSRS );
	void                      EigenschaftswertCubicSplineHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, Text& strSRS );
	Fachobjekt*               EigenschaftswertEdgeHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	Fachobjekt*               EigenschaftswertPolygonHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, const char* pszSRS = 0, const char* pszRel = 0, bool bFirst = true );
	Fachobjekt*               EigenschaftswertFaceHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );
	Fachobjekt*               EigenschaftswertSolidHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt, const char* pszSRS = 0 );
	Fachobjekt*               EigenschaftswertTopoSolidHinzufuegen( Fachobjekt* pxoObj, const Text& strProp, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );

	void                      S_Kennung(Fachobjekt*, const Text&);
	void                      S_Langtext(Fachobjekt*, const Text&);

	void                      _Statistik(const Objektart* ok, const Text& strCls, Fachobjekt* pxoObj, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt) const;

private:
	static XMLAdapter*        Erzeuge();
	Text                      GibKlassenname() const;

	void                      NamespaceSetzen( XmlNamespace ns, bool isDefNs, const TextListe& nsPref, const Text* nsName = 0 );
	void                      NamespaceSetzen( XmlNamespace ns, bool isDefNs, const TextListe& nsPref, const char* pszName );
	void                      NamespaceRepSetzen( XmlNamespace ns, const char* pszName );
	XmlNamespace              DefaultNamespace( ) const;
	void                      NamespaceReinit();
	Text                      Split( Text& strNam ) const;
	bool                      MessageOptionalRelationMissing(bool);
	bool                      MessageRelationMissing(bool);

	// Methoden zum Umgang mit Objekteigenschaften XML Sicht
	void                      E_Eigenschaft( Fachobjekt* pxoObj, const Text& strNam, AnyType& aVal, bool& bValid, const Datum& von, const Datum& bis ) const;
	void                      S_Eigenschaft( Fachobjekt* pxoObj, const Text& strNam, AnyType& aVal );
	void                      H_Eigenschaft( Fachobjekt* pxoObj, const Text& strNam, AnyType& aVal );
	void                      L_Eigenschaft( Fachobjekt* pxoObj, const Text& strNam, AnyType& aVal );
	void                      P_Eigenschaft( Fachobjekt* pxoObj, const Text& strNam, AnyType& aVal, bool& bValid, const Datum& von, const Datum& bis ) const;
	void                      E_Eigenschaftsnamen( const Objektart* pOA, TextListe& sl ) const;
	void                      E_Eigenschaftsinfo( const Objektart* pOA, const Text& strNam, const Text& strPref, const Text& strEig, const Eigenschaft*& pInfo );
	bool                      KlasseHatEigenschaft( const Objektart* pOA, const Text& strProp ) const;

	// Interface zum Umgang mit XML-Namespaces und deren Kürzel
	XmlNamespace              NamespaceZuPrefix( const Text& strPref ) const;
	Text                      PrefixZuNamespace( XmlNamespace eNs ) const;
	Text                      NameZuNamespace( XmlNamespace eNs ) const;

	void                      ResourceIdentifierSetzen(Text strRI);
	Text                      ResourceIdentifierErfragen() const;

	// Objekterzeugung und Initialisierung auf Basis von XML
	Fachobjekt*               ObjektErzeugen( const Objektart* okl, Datenbestand* pDom = 0, ClsConfMapType* pConfMap = 0, Objektartfilter* pClsFilt = 0 ) const;
	Fachobjekt*               ObjektErzeugen( const Text& featureType, const Objektart* okl = 0, Datenbestand* pDom = 0, ClsConfMapType* pConfMap = 0, Objektartfilter* pClsFilt = 0, bool bSplit = true ) const;
	Fachobjekt*               ObjektErzeugen( const XercesXML::DOMNode& node, Datenbestand* pDom = 0, ClsConfMapType* pConfMap = 0, Objektartfilter* pClsFilt = 0, bool bFeature = false );
	bool                      ObjektInitialisieren( Fachobjekt* pxoObj, const XercesXML::DOMNode& node, Datenbestand* pDom = 0, ClsConfMapType* pConfMap = 0, Objektartfilter* pClsFilt = 0 );
	void                      EigenschaftswertHinzufuegen( Fachobjekt* pxoObj, const Text& strPropNam, const XercesXML::DOMNode& valuenode, ClsConfMapType* pConfMap, Objektartfilter* pClsFilt );

	// Methode zum Auflösen eines URI in ein Fachobjekt
	Fachobjekt*               UriAufloesen( Text& strUri, bool bThrow = true ) const;

	Text                      UrnErfragen( Fachobjekt* pxoObj ) const;

	// Interface zum Umgang mit Elementnamen
	void                      SetzeElementname( eElementtyp, const Text& );
	Text                      GibElementname( eElementtyp ) const;
	void                      InitialisiereElementnamen();

	// Interface zum Umgang mit URN-Prefixes
	void                      UrnNamespaceSetzen( const Objektart* pOA = NULL, Text strPref = "" );
	Text                      UrnNamespace( const Objektart* pOA ) const;
	bool                      UrnNamespaceVorhanden( const Text& strPref ) const;
	void                      UrnNamespacesLoeschen();

	// Interface zum Umgang mit lokalen XML-IDs
	void                      LokaleXmlIdSetzen( Fachobjekt* pxoObj, const Text& strID, bool bReplace = false );
	Fachobjekt*               ObjektNachLokalerIdSuchen( const Text& strID ) const;
	Fachobjekt*               ObjektNachIdSuchen( const Text& strID ) const;
	void                      LokaleXmlIdsLoeschen();

	// gekapselter Konstruktor/Destruktor für XMLInputCv
	XMLEingabeKonverter*      XMLInputCvErzeugen();
	void                      XMLInputCvLoeschen(XMLEingabeKonverter*);
	XMLMultiEingabeKonverter* XMLMultiInputCvErzeugen();
	void                      XMLMultiInputCvLoeschen(XMLMultiEingabeKonverter*);

	// gekapselter Konstruktor/Destruktor für XMLOutputCv
	XMLAusgabeKonverter*      XMLOutputCvErzeugen();
	void                      XMLOutputCvLoeschen(XMLAusgabeKonverter*);

private:
	void                      BelegeNamen();
	void                      InitPrefix();
	bool                      IsGeoAdapter() const;

	static const char* pStrElmtName;
	static const char* pStrKeyValue;
	static const char* pStrMetaData;
	static const char* pStrObjectSet;
	static const char* pStrException;
	static const char* pStrExcReport;
	static const char* pStrExcCode;
	static const char* pStrWfsFeatColl;
	static const char* pStrGmlFeatMem;
	Text m_strOkstra_m_str_Kennung, m_strOkstra_m_str_hat_Lage, m_strOkstra_m_str_in_pos_ref_system,
		 m_strOkstra_m_str_in_coordinate_system, m_strOkstra_m_str_dargestellt_von_Punkt, m_strOkstra_m_str_Beginn_von,
		 m_strOkstra_m_str_Ende_von, m_strOkstra_m_str_hat_Punkt, m_strOkstra_m_str_liegt_in_Masche,
		 m_strOkstra_m_str_dargestellt_von_Knoten, m_strOkstra_m_str_beginnt_bei_Punkt, m_strOkstra_m_str_endet_bei_Punkt,
		 m_strOkstra_m_str_besteht_aus_Linienelementen, m_strOkstra_m_str_hat_Zwischenpunkt, m_strOkstra_m_str_hat_Stuetzpunkte,
		 m_strOkstra_m_str_Tangente_am_Anfang, m_strOkstra_m_str_Tangente_am_Ende, m_strOkstra_m_str_beginnt_bei,
		 m_strOkstra_m_str_endet_bei, m_strOkstra_m_str_begrenzt_Masche, m_strOkstra_m_str_hat_Linie,
		 m_strOkstra_m_str_dargestellt_von_Kante, m_strOkstra_m_str_beschrieben_durch_Linien, m_strOkstra_m_str_bei_Linienfunktion,
		 m_strOkstra_m_str_Linie, m_strOkstra_m_str_enthaelt_Knoten, m_strOkstra_m_str_hat_Kante, m_strOkstra_m_str_begrenzt_Koerper,
		 m_strOkstra_m_str_hat_Flaeche, m_strOkstra_m_str_dargestellt_von_Masche, m_strOkstra_m_str_dargestellt_von_Volumen,
		 m_strOkstra_m_str_hat_Masche, m_strOkstra_m_str_dargestellt_von_Koerper, m_strOkstra_m_str_dargestellt_von_Flaeche,
		 m_strOkstra_m_str_dargestellt_von_Linie;

	static Text m_strElmtName;
	static Text m_strKeyValue;
	static Text m_strMetaData;
	static Text m_strObjectSet;
	static Text m_strException;
	static Text m_strExcReport;
	static Text m_strExcCode;
	static Text m_strWfsFeatColl;
	static Text m_strGmlFeatMem;
	static Text m_strUrn;
	static Text m_str_auf_Abschnitt_oder_Ast;
	static Text m_str_gml_id;
	static Text m_str_gml32_id;
	static Text m_str_fid;
	static Text m_str_kid;
	static Text m_str_Langtext;
	static Text m_str_Objektklasse;
	static Text m_str_beginnt_;
	static Text m_str_beginnt_bei_Station;
	static Text m_str_beginnt_mit_Abstand_zur_Bestandsachse;
	static Text m_str_beginnt_mit_Abstand_zur_Fahrbahnoberkante;
	static Text m_str_endet_;
	static Text m_str_endet_bei_Station;
	static Text m_str_endet_mit_Abstand_zur_Bestandsachse;
	static Text m_str_endet_mit_Abstand_zur_Fahrbahnoberkante;
	static Text m_str_Station;
	static Text m_str_Abstand_zur_Bestandsachse;
	static Text m_str_Abstand_zur_Fahrbahnoberkante;
	static Text m_str_hat_Teilabschnitt;
	static Text m_str_hat_Strecke;
	static Text m_str_beginnt_bei_SP;
	static Text m_str_endet_bei_SP;
	static Text m_str_enthaelt_Netzbereich;
	static Text m_str_enthaelt_Strecke;
	static Text m_str_enthaelt_Teilabschnitt;
	static Text m_str_enthaelt_Netzbereichskomp;
	static Text m_str_Strecke;
	static Text m_str_Strecke_SO;
	static Text m_str_zu_Streckenobjekt;
	static Text m_str_Kennung;
	static Text m_str_name;
	static Text m_str_href;
	static Text m_str_Point;
	static Text m_str_Node;
	static Text m_str_Curve;
	static Text m_str_LineString;
	static Text m_str_Edge;
	static Text m_str_Polygon;
	static Text m_str_Face;
	static Text m_str_Solid;
	static Text m_str_TopoSolid;
	static Text m_str_Objekt_ID;
	static Text m_str_Strassenbezeichnung;
	static Text m_str_Nullpunktsort;
	static Text m_str_Nullpunktort;
	static Text m_str_Strassenpunkt;
	static Text m_str_Teilabschnitt;
	static Text m_str_identisches_Netzteil;
	static Text m_str_Punktvermarkung;
	static Text m_str_Geometrie;
	static Text m_str_GeoPunkt;
	static Text m_str_GeoLinie;
	static Text m_str_GeoRegion;
	static Text m_str_GeoVolumen;
	static Text m_str_BoundingBox;
	static Text m_str_id;
	static Text m_str_hat_Objekt_ID;
	static Text m_str_hat_Strassenbezeichnung;
	static Text m_str_bei_Strassenpunkt;
	static Text m_str_ist_Punktobjekt;
	static Text m_str_gehoert_zu_PO;
	static Text m_str_Punktobjekt_o_Bereichsobjekt;
	static Text m_str_Beginn_von_TA;
	static Text m_str_Ende_von_TA;
	static Text m_str_entlang_Teilabschnitt;
	static Text m_str_in_Strecke;
	static Text m_str_in_Netzbereich;
	static Text m_str_war_Teilabschnitt;
	static Text m_str_wurde_zu_Teilabschnitt;
	static Text m_str_altes_Netzteil;
	static Text m_str_neues_Netzteil;
	static Text m_str_Teil_von_Ereignis;
	static Text m_str_von_Vermessungspunkt;
	static Text m_str_hat_Lage;
	static Text m_str_besteht_aus_Linienelementen;
	static Text m_str_beginnt_bei_Punkt;
	static Text m_str_endet_bei_Punkt;
	static Text m_str_hat_Stuetzpunkte;
	static Text m_str_hat_Zwischenpunkt;
	static Text m_str_Tangente_am_Anfang;
	static Text m_str_Tangente_am_Ende;
	static Text m_str_beginnt_bei;
	static Text m_str_endet_bei;
	static Text m_str_dargestellt_von_Punkt;
	static Text m_str_in_pos_ref_system;
	static Text m_str_in_coordinate_system;
	static Text m_str_in_coord_ref_system;
	static Text m_str_Beginn_von;
	static Text m_str_Ende_von;
	static Text m_str_Koordinate;
	static Text m_str_hat_Punkt;
	static Text m_str_liegt_in_Masche;
	static Text m_str_enthaelt_Knoten;
	static Text m_str_hat_Kante;
	static Text m_str_hat_Masche;
	static Text m_str_dargestellt_von_Koerper;
	static Text m_str_x_okstra_object;
	static Text m_str_okstra_object;
	static Text m_str_Teilabschnitt_SO;
	static Text m_str_Teilabschnitt_NB;
	static Text m_str_Netzbereich;
	static Text m_str_dargestellt_von_Knoten;
	static Text m_str_dargestellt_von_Kante;
	static Text m_str_dargestellt_von_Masche;
	static Text m_str_dargestellt_von_Volumen;
	static Text m_str__abstrakt;
	static Text m_str__Symbol;
	static Text m_str_graphisches_Symbol;
	static Text m_str_0123456789;
	static Text m_str_whitespace;
	static Text m_str_begrenzt_Masche;
	static Text m_str_hat_Linie;
	static Text m_str_bei_Linienfunktion;
	static Text m_str_beschrieben_durch_Linien;
	static Text m_str_einschliessende_Linie;
	static Text m_str_ausschliessende_Linie;
	static Text m_str_dargestellt_von_Flaeche;
	static Text m_str_begrenzt_Koerper;
	static Text m_str_hat_Flaeche;
	static Text m_str_Linie;
	static Text m_str_dargestellt_von_Linie;
	static Text m_str_gueltig_von;
	static Text m_str_gueltig_bis;
	static Text m_str_Fachkennung;
	static Text m_str_Einbaumonat;
	static Text m_str_Bezugsmonat;
	static Text m_str_Berichtsmonat;
	static Text m_str_Monat_im_Jahr;
	static Text m_str_zentraler_Nullpunkt;
	static Text m_str_Nullpunktart;
	static Text m_str_fachliche_Bedeutung;
	static Text m_str_Schluessel;
	static Text m_str_Punkt;
	static Text m_str_isolierter_Knoten;
	static Text m_str_nicht_isolierter_Knoten;
	static Text m_str_Kante;
	static Text m_str_Flaechenelement;
	static Text m_str_Ring;
	static Text m_str_LinearRing;
	static Text m_str_Masche;
	static Text m_str_Volumen;
	static Text m_str_Koerper;
	static Text m_str_direct_position;
	static Text m_str_geodaetisches_Datum;
	static Text m_str_Koordinatensystem;
	static Text m_str_Koordinatenreferenzsystem;
	static Text m_str_Teilbauwerk;
	static Text m_str_Abschnitt_oder_Ast_Symbol;
	static Text m_str_Abschnitt;
	static Text m_str_Ast;
	static Text m_str_Verwaltungsbezirk_Symbol;

	static std::string m_stl_coordinates;
	static std::string m_stl_pos;
	static std::string m_stl_Point;
	static std::string m_stl_pointProperty;
	static std::string m_stl_pointRep;
	static std::string m_stl_vectorAtStart;
	static std::string m_stl_vectorAtEnd;
	static std::string m_stl_directedNode;
	static std::string m_stl_orientation;
	static std::string m_stl_container;
	static std::string m_stl_Node;
	static std::string m_stl_directedEdge;
	static std::string m_stl_isolated;
	static std::string m_stl_Edge;
	static std::string m_stl_Face;
	static std::string m_stl_directedFace;
	static std::string m_stl_directedTopoSolid;
	static std::string m_stl_Kennung;
	static std::string m_stl_Langtext;
	static std::string m_stl_srsName;
	static std::string m_stl_segments;
	static std::string m_stl_LineStringSegment;
	static std::string m_stl_Arc;
	static std::string m_stl_CubicSpline;
	static std::string m_stl_curveProperty;
	static std::string m_stl_exterior;
	static std::string m_stl_interior;
	static std::string m_stl_Ring;
	static std::string m_stl_curveMember;
	static std::string m_stl_LinearRing;
	static std::string m_stl_TopoSolid;
	static std::string m_stl_surfaceProperty;
	static std::string m_stl_Polygon;
	static std::string m_stl_GmlId;
	static std::string m_stl_Gml32Id;
	static std::string m_stl_name;
	static std::string m_stl_time_stamp;
	static std::string m_stl_author;
	static std::string m_stl_organization;
	static std::string m_stl_preprocessor_version;
	static std::string m_stl_originating_system;
	static std::string m_stl_authorization;
	static std::string m_stl_schema_identifiers;
	static std::string m_stl_relRep;
	static std::string m_stl_gml_id;
	static std::string m_stl_gml32_id;
	static std::string m_stl_id;
	static std::string m_stl_cs;
	static std::string m_stl_decimal;
	static std::string m_stl_ts;
	
	const Objektart* m_pStrecke;
	const Objektart* m_pStrecke_SO;
	const Objektart* m_pPunkt;
	const Objektart* m_pPunktobjekt;
	const Objektart* m_pdirect_position;
	const Objektart* m_pLinie;
	const Objektart* m_pFlaeche;
	const Objektart* m_pgerades_Linienelement;
	const Objektart* m_pStreckenobjekt;
	const Objektart* m_pNetzbereich;
	const Objektart* m_pTeilabschnitt;
	const Objektart* m_pStrassenpunkt;
	const Objektart* m_pStrassenbezeichnung;
	const Objektart* m_pidentisches_Netzteil;
	const Objektart* m_pPunktvermarkung;
	const Objektart* m_pKoerper;
	const Objektart* m_pVolumen;
	const Objektart* m_pLinienfunktion;
	const Objektart* m_pLinie_Flaechenelement;
	const Objektart* m_pFlaechenelement;
	const Objektart* m_pLinienelement_Spline;
	const Objektart* m_pKreisbogen;
	const Objektart* m_pKnoten;
	const Objektart* m_pKante;
	const Objektart* m_pMasche;
	const Objektart* m_pObjekt_ID;
	const Objektart* m_pStrassenpunkt_PO;
	const Objektart* m_pStrassenpunkt_PoB;
	const Objektart* m_pStrassenpunkt_TA;
	const Objektart* m_pTeilabschnitt_SO;
	const Objektart* m_pTeilabschnitt_Str;
	const Objektart* m_pTeilabschnitt_NB;
	const Objektart* m_pTeilabschnitt_IdNT;
	const Objektart* m_pisolierter_Knoten;
	const Objektart* m_pnicht_isolierter_Knoten;
	const Objektart* m_pPunktobjekt_Modell;
	const Objektart* m_pLinienobjekt_Modell;
	const Objektart* m_pFlaechenobjekt_Modell;
	const Objektart* m_pVolumenobjekt_Modell;
	const Objektart* m_pkomplexe_Flaeche;
	const Objektart* m_pAbschnitt_oder_Ast;
	static void InitialisiereKonstanten(bool bForce = false);
};
#endif
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFXMLAdapter
