/*****************************************************************************
* $Id: SAXNode.h 2011-11-11 11:11:11 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2011, Bundesanstalt f�r Stra�enwesen
*
* Erstellt durch interactive instruments GmbH, Bonn
*
* Die Nutzungsbestimmungen f�r die Software und die zugeh�rigen Bestandteile
* sind unter folgender Adresse einsehbar:
*    http://www.okstra.de/oklabi/Lizenz/Nutzung.txt
* 
* Der Hinweis auf das Copyright und die Lizenzbestimmungen ist in allen
* Kopien der Software oder wesentlichen Bestandteilen daraus aufzunehmen.
*
* Die Erkl�rungen zum Gew�hrleistungsausschlu� und zur Haftungsbegrenzung 
* befinden sich bei den Nutzungsbestimmungen.
* 
* 2010-11-18 Bereinigungen im Interface
* 2010-11-22 Speicherlecks beseitigen
* 2010-11-24 Komprimierte XML-Dateien lesen
* 2011-08-05 Formale Anpassungen f�r CYGWIN
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 
****************************************************************************/
/* SAXNode.h
*
* XMLNodes:    Verwaltung eines Node-Pools, so dass DOMNodes nicht jedes Mal neu erzeugt werden
*              m�ssen sondern aus dem bestehenden Pool entnommen werden k�nnen.
* NodeFactory: Erzeugung einer Knotenstruktur von DOMNodes (der in XercesXML.h definiert ist)
* NodeFilter:  Filter f�r die gezielte Auswahl von gelesenen Elementen
*
*
* 22.04.2004  SO - Ver�nderte Node-Erzeugung, Anlage eines Node-Pool, ge�nderte String-Behandlung
* 14.01.2004  SO - Datei erzeugt
*/


#ifndef SAXNode_h
#define SAXNode_h

#ifdef CYGWIN
#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif
#endif

#include <stack>
#include <set>
#include <string>
#include <iostream>

#include "XercesXML.h"
#include "SAXHandler.h"
#include "SAXReader.h"

//#define SEE_PUFF // erm�glicht die Ausgabe von Infos bzgl. der Node-Puffer

// Xerces-Klassen
namespace XERCESCNAMESPACE
{
	// forwards
	class DOMImplementation;
	class DOMDocument;
	class DOMElement;
	class DOMNode;
}

namespace XercesXML
{
	// forwards
	class SAXAttributeNode;
	class SAXElementNode;
	class SAXTextNode;
	class SAXNode;


	// ***************************************************************************
	//                                    XMLNodes
	// ***************************************************************************

	class XMLNodes
	{
	protected:
		XMLNodes(XERCESCNAMESPACE::DOMDocument* pDOMDoc) /*throw ( ParsingError )*/;
		~XMLNodes();

		XERCESCNAMESPACE::DOMDocument* m_pDOMDoc;
	};

	class XMLElementNodes : public XMLNodes
	{
	public:
		// Konstruktor
		XMLElementNodes(XERCESCNAMESPACE::DOMDocument* pDOMDoc) //throw ( ParsingError )
			: XMLNodes( pDOMDoc ) {}

		// Gib einen Element-Node mit URI 'pUri' und Name 'pName'
		XERCESCNAMESPACE::DOMElement* getNode(const XMLCh* pUri, const XMLCh* pName);
	};

	class XMLAttributeNodes : public XMLNodes
	{
	public:
		// Konstruktor
		XMLAttributeNodes(XERCESCNAMESPACE::DOMDocument* pDOMDoc) //throw ( ParsingError )
			: XMLNodes( pDOMDoc ) {}

		// Gib einen Attribute-Node mit URI 'pUri', Name 'pName' und Wert 'pValue'
		XERCESCNAMESPACE::DOMAttr* getNode(const XMLCh* pUri, const XMLCh* pName, const XMLCh* pValue);
	};

	class XMLTextNodes : public XMLNodes
	{
	public:
		// Konstruktor
		XMLTextNodes(XERCESCNAMESPACE::DOMDocument* pDOMDoc) //throw ( ParsingError )
			: XMLNodes( pDOMDoc ) {}

		// Gib einen Text-Node mit Wert 'pValue'
		XERCESCNAMESPACE::DOMText* getNode(const XMLCh* pValue);
	};


	// ***************************************************************************
	//                                    NodeFactory

	// Erzeugung einer Knotenstruktur in folgender Weise:
	// - unver�nderliche Bestandteile:
	//   o DOMDocument - die Mutter aller Nodes
	//   o DOMElement 'RootElement' - das oberste ElementNode-Objekt
	// - ver�nderliche Bestandteile:
	//   o DOMElement 'OberElement' - der oberste ElemetNode, der �ber den Node-Pool verwaltet wird,
	//                                und der keine Inhalte enth�lt
	//   o DOMElement mit Dateninhalt
	//     plus davon abh�ngige Nodes
	//
	// Die Erzeugung erfolgt durch die create...Node-Methoden, die wiederum von einem
	// Handler-Objekt aufgerufen werden.
	//
	// Weitere Erl�uterungen zur Node-Erzeugung stehen in der cpp-Datei.
	// ***************************************************************************

	typedef std::stack<xercesc::DOMElement*> OffenStack;

	static const char* XML_IMPLEMENT_ART = "Core";

	class NodeFactory
	{
		friend class SAXReader;	
	public:
		NodeFactory(SAXReader* pReader);
		~NodeFactory();

		// Liefert den Vaterknoten der zuletzt erzeugten Knotenstruktur.
		// 
		// Wenn kein Nodes erzeugt wurde (Dateieinde erreicht ohne dass ein Element
		// der Suchangabe entsprechen w�rde) dann wird ein leerer Node zur�ckgegeben
		//
		XercesXML::DOMNode getTopNode();

		// Schnittstellen f�r die Knoten-Erzeugung
		// - F�r das Handler-Objekt:
		//   Die 'startElement'- , 'endElement'- oder 'chars'-Methoden der Handler-Objekte
		//   �bergeben ihre gelesenen Inhalte an die hier folgenden Methoden.
		//   Dies sind Create-Methoden f�r die einzelnen Node-Arten
		void createTextNode(const XMLCh* pTextValue); 
		void createAttributeNode(const XMLCh* pAttUri, 
									  const XMLCh* pAttName, const XMLCh* pAttValue);
		void createElementNode(const XMLCh* const pElemUri, const XMLCh* pElemName); 

		void finishNode();

	private:
		NodeFactory() /*throw (NotInitialized)*/; // verboten, daher private

		// Initialisierung der Factory - muss aufgerufen werden vor dem Starten
		// eines neuen Parse-Vorgangs
		void initialize();

		// Entfernt das aktuelle OberElement
		void removeOberElement();

		void newNodeAvailable();

	private:
		SAXReader*  m_pReader;
		OffenStack  m_openNodes;
		bool m_nextIsFirst;
		bool m_nodeFound;

		XMLElementNodes* m_pElemNodes;
		XMLAttributeNodes* m_pAttNodes;
		XMLTextNodes* m_pTextNodes;

		// Xerces-Bereich
		xercesc::DOMImplementation* m_pDOMImp;
		xercesc::DOMDocument* m_pDOMDoc;
		xercesc::DOMNode* m_pDOMRetNode;
	};

	// ***************************************************************************
	//                                    NodeFilter
	//
	// �ber den NodeFilter lassen sich Suchausdr�cke setzen und abfragen.
	// Er soll dabei helfen, Elemente einer XML-Datei mit bestimmten Eigenschaften
	// (Klassenname, Attributname, ..) zu ermitteln.
	//
	// Bedienung: 
	// Dem NodeFilter wird ein String bzw. eine Menge von Strings �bergeben. Das
	// sind dann die Suchausdr�cke.
	// Danach kann mit 'isSearchName' gepr�ft werden, ob ein bestimmter String in 
	// der Menge der Suchausdr�cke enthalten ist.
	// ***************************************************************************

	typedef std::set<XMLCh*> SuchStrings;
	typedef std::set< std::pair<XMLCh*,XMLCh*> > SuchStringPaare;

	class NodeFilter
	{
	public:
		NodeFilter();
		~NodeFilter();

		// Setzen der Suchausdr�cke
		// Evtl. bis dahin vorhandene Suchausdr�cke werden gel�scht.
		void setSearchName(const std::string& suchName, EncodingType encoding);
		void setSearchNames(const AppSuchNamen& suchNamen, EncodingType encoding);
		void setSearchName(const std::string& suchNameUri, const std::string& suchName,
			EncodingType encoding);
		void setSearchNames(const AppSuchNamenNS& suchNamen, EncodingType encoding);

		// Setzen der Such-Level
		// Evtl. bis dahin vorhandene Such-Level werden gel�scht.
		void setSearchLevels(const AppSuchLevels& suchNamen);

		// Abfrage: ist 'name' einer der Suchausdr�cke?
		bool isSearchName(const XMLCh* name);
		bool isSearchName(const XMLCh* uri, const XMLCh* name);

		// Abfrage: ist 'level' einer der Level, in denen gesuchte Objekte zu finden sind?
		bool isSearchLevel(const size_t& level);
	private:
		void initializeNamen();
		void initializeLevel();
		// Hilfsfunktion
		void _setSearchName(const std::string& suchName, EncodingType encoding);
		void _setSearchName(const std::string& suchNameUri, const std::string& suchName,
			EncodingType encoding);

		SuchStrings m_SuchWerte;
		SuchStringPaare m_SuchWertePaare;
		size_t* m_suchLevel;
		size_t m_suchLevelCnt;
	};

}//namespace

#endif

