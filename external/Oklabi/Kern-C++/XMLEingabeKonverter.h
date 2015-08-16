/*****************************************************************************
* $Id: XMLEingabeKonverter.h 2014-03-27 15:57:11 vogelsang $
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
* 2010-12-14 Vorschau auf Eingabedaten
* 2011-03-18 Schlüsseltabellen sind GML-Feature ab Version 1.015
* 2011-07-05 Elementnamen konfigurierbar machen
* 2011-07-14 Lesen von WFS Response
* 2011-11-14 Umstieg auf Xerces-3.1.1
* 2012-03-12 Metadaten
* 2012-07-27 InputSource verallgemeinert
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2013-02-04 Profile
* 2013-11-18 Transformierer eingeführt
* 2013-12-12 Fremdobjekt für Nachbarstandards eingeführt
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-03-27 XMLMultiEingabeKonverter eingeführt 
* 
****************************************************************************/
// Der XMLEingabeKonverter erzeugt aus einer OKSTRA-XML-Datei
// die zugehörigen OKSTRA-Objekte und trägt sie in einen Datenbestand ein.

#include "OklabiPackaging.h"

#ifndef DEFXMLInputCv
#define DEFXMLInputCv

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "XMLAdapter.h"
#ifdef OKLABI_KERN
#include "XercesXMLErrorHandler.h"
#endif
#include "EingabeKonverter.h"
#include "Eingabe.h"

#ifdef OKLABI_KERN
namespace XercesXML
{
	// forwards:
	class SAXReader;
	class InputSource;
	class AbstractInputSource;
}
#endif

namespace Oklabi
{
typedef std::map<int,const Objektart*>	LocXMLObjMapTypeIgnored;

class Objektartfilter;
class Datenbestand;

typedef std::map<Text,XmlNamespace>	    NSMapType;

typedef Liste< Version* >               VersionListe;
typedef std::map<Text, Version*>        MapNS2VersionType;
typedef std::map<Text, Datenbestand*>   MapNS2DomainType;

enum ComparisonOperator
{
	Less          = 0,
	LessEqual     = 1,
	Equal         = 2,
	Greater       = 3,
	GreaterEqual  = 4,
	DontKnow      = 5
};

class OKLABI_API XMLEingabeKonverter : public EingabeKonverter
{
#ifdef OKLABI_KERN
	friend class XMLAdapter;
	friend class IsybauImporteur;
#endif
	friend class XMLAusgabeKonverter;
	friend class Profil;
public:
	static XMLEingabeKonverter* Erzeuge(Eingabe*);
	Text                        GibKlassenname() const;
	Version*                    GibVersion();
	FblVersion*                 GibFblVersion();
	void                        TransportiereErweiterungen(bool = false);
	void                        VerschmelzeSymbolischeObjekte(bool = true);
	void                        ErzeugeReferenzierteObjekte(bool);
	Datenbestand*               Lade(Objektartfilter* pFilt = 0, Objektartfilter* pSymb = 0);
	TextListe                   GibMetadaten(eMetadaten);
	void                        SetzeSchemaLocation( const Text& strXSD );
	void                        ValidiereSchema(bool);
	bool                        GibValidierung() const;
	TextListe                   GibObjektarten();
	size_t                      GibAnzahlObjekte(const Text&);
	void                        SetzeElementname(eElementtyp, const Text&);
	Text                        GibElementname(eElementtyp) const;
	void                        InitialisiereElementnamen();
	bool                        IstWfsResponse();
	void                        SetzeProfilerkennung(bool = true);
	void                        Transformiere(eKoordRefSys);

protected:
#ifdef OKLABI_KERN
	XMLEingabeKonverter(XMLAdapter*);
	~XMLEingabeKonverter();

	XMLAdapter*                 m_pXMLAdapter;

	Eingabe*                    m_pDatei;
	XercesXML::AbstractInputSource* m_pInputConn;

	bool                        m_bUseSAX; // zeigt an ob SAX-Reader (true) oder DOM-Parser (false) verwendet wird
	XercesXML::SAXReader*       m_pSAXReader;
	bool                        m_bValidate; // zeigt an ob das XML-Schema validiert wird oder nicht

	bool                        m_bSrvExcRep;
	Text                        m_strExceptionCode;
	Text                        m_strException;

	bool                        m_bWfsResponse;
	Text                        m_strTimeStamp;

	bool                        m_bExtension;
	bool                        m_bId;
	Text                        m_strXSD;
	Text                        m_strOKSTRA;
	bool                        m_bRelEins;

	LocXMLObjMapTypeIgnored     m_pmapObjectMapIgnored;

	NSMapType                   m_mapNS;
	MapNS2VersionType           m_mapNS2Version;
	MapNS2DomainType            m_mapNS2Domain;
	ClsConfMapType              m_mapClsConf;

	void                        NamespaceLaden(std::vector<std::string>& vecPref, std::vector<std::string>& vecUri );

	// Laden der Header-Information der aktuell geladenen XML-Datei
	// Rückgabewert false:
	// Es wurde noch keine XML-Datei angegeben, oder das Laden des DOMNode der
	// Meta-Info schlug fehl.
	virtual bool                HeaderLaden();

	// der DOMNode für die Header Section
	XercesXML::DOMNode*         m_pNodeMeta;
	XercesXML::EncodingType     m_eEncoding;

	// spezifische Methoden/Variablen der DOM-Methode:
	void                        LokaleIdsRegistrierenDOM( const XercesXML::DOMNode& domNode, Datenbestand* pDomain, float dPO );
	void                        LokaleIdsRecRegistrierenDOM( const XercesXML::DOMNode& domNode, Datenbestand* pDomain );

	// spezifische Methoden/Variablen der SAX-Methode:
	void                        LokaleIdsRegistrierenSAX( Datenbestand* pDomain, float dPO );
	bool                        erzeugeGmlOkstraNameSAX(const Text& strCls, Text& strOks);
	FachobjektPtr               OkstraKeyValRegistrierenSAX(Datenbestand* pDomain, XercesXML::DOMNode& oksNode, bool bFeature = false);
	void                        setSaxParse(bool useSAX); // true = verwende SAX-Reader, sonst DOM-Parser
	bool                        createSAXReader();
	void                        finalizeSAXReader();
	void                        resetSAXObjects();

	// Parsen einer XML-Datei entweder über die DOM- oder über die SAX-Methode (default).
	// Wenn 'useSAX' == false dann wird der DOM-Parser verwendet.
	void                        LadenSD( Datenbestand* pDomain );
//	void                        LadenSD( Datenbestand* pDomain, Text strDatei );

	void                        EingabedateiSetzen(Eingabe* pDatei);

	void                        LokaleIdAlsObjektId( bool bId );

	// Einstellung der verwendeten Parse-Methode:
	// true: SAX-Parser, false: DOM-Parser
	void                        ParseMethode(bool nimmSaxParser = true);

// Methoden für die Header Section
	// File-Description
	bool                        E_FDDescription( TextListe& strList );
	bool                        E_FDImplementationLevel( Text& strVal );
	// File-Name
	bool                        E_FNName( Text& strVal );
	bool                        E_FNTimeStamp( Text& strVal );
	bool                        E_FNAuthor( TextListe& strList );
	bool                        E_FNOrganization( TextListe& strList );
	bool                        E_FNPreprocessorVersion( Text& strVal );
	bool                        E_FNOriginatingSystem( Text& strVal );
	bool                        E_FNAuthorization( Text& strVal );
	// File-Schema
	bool                        E_FSSchemaIdentifiers( TextListe& strList );
	// Rel-Rep
	bool                        E_RelRep( Text& strRR );

	Version                     ErfrageOKSTRAVersion();
	Text                        ErfrageOKSTRAVersionString();

	TextListe                   GibNamespaces();
	Text                        GibNamespace(const Version*);
	VersionListe                GibVersionen();
	Version*                    GibVersion(const Text&);
	Datenbestand*               GibDatenbestand(const Text&, bool = true);


// Parsen einer XML-Datei
	void                        Lade( Datenbestand* pDomain, Objektartfilter* pFilt, Objektartfilter* pSymb );
//	void                        Lade( Datenbestand* pDomain, Objektartfilter* pFilt, Objektartfilter* pSymb, Text strDatei );

	void                        Zaehle();

	// Filterung von Klassen
	void                        setzeKlassenauswahlVirtualisierung( Objektartfilter* );
	void                        setzeKlassenauswahlIgnorieren( Objektartfilter* );
	void                        setzeKlassenauswahlOhneID( Objektartfilter* );
	void                        setzeKlassenauswahlSymbol( Objektartfilter* );

	// Filterung von Versionen
	bool                        Vergleiche( const Version&, ComparisonOperator );

protected:
	void                        Identitaetswechsel(FachobjektPtr, FachobjektPtr, const Text&);

private:
	Objektartfilter*            m_pKlassenIgnorieren;
	Objektartfilter*            m_pKlassenOhneID;
	Objektartfilter*            m_pKlassenSymbol;
#endif
};

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFXMLInputCv
