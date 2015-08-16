/*****************************************************************************
* $Id: SAXHandler.h 2011-11-11 11:11:11 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2011, Bundesanstalt für Straßenwesen
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
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 
****************************************************************************/
/* SAXHandler.h
*
* Definition der notwendigen Handler-Objekte um eine XML-Datei
* mit Hilfe des SAX-Parsers einzulesen (Validierung + Objektermittlung)
*
* Eine Übersicht der Handler-Objekte befindet sich in SAXReader.h
*
* 24.08.2011  MF - HandlerFactory nicht mehr statisch
* 19.05.2009  MF - createNodes( NodeCont* ) kann auch die in-scope-Namespaces berücksichtigen
* 12.05.2009  MF - NodeCont::setValues muss *alle* alten Attribute überschreiben
* 01.02.2005  AV - Formale Änderungen
* 11.10.2004  SO - Fehlerbehebung (mit 'SAXParseXML.cpp')
* 22.04.2004  SO - Erweiterung um 'NextElementFilterhandler', Berücksichtigung
*                  der XML-Datei-Ebene bei einigen Handlern, Whitespace-Behandlung,
*                  geänderte String-Behandlung
* 28.01.2004  SO - Erweiterung um 'AttributeFilterHandler' 
*                   + Fehlerkorrekturen + Fehlerhandling erweitert
* 14.01.2004  SO - Datei erzeugt
*/

#ifndef SAXHandler_h
#define SAXHandler_h


// Falls Status-Meldungen der einzelnen Callback-Methoden eines Handler-Objektes 
// gewünscht sind sollte folgendes definiert sein:
//#define SEE_HANDLER_CB

#include <map>
#include <list>
#include <string>
#include <sstream>
#include <iostream>

#include "XercesXML.h"
#include "XercesXMLErrorHandlerInterface.h"

// Xerces-Klassen
#include <xercesc/sax2/DefaultHandler.hpp>
namespace XERCESCNAMESPACE
{
	// forwards
	class Attributes;
	class SAXParseException;
}

namespace XercesXML
{
	// forwards
	class SAXReader;
	class NodeFactory;
	class NodeFilter;

	class HandlerFactory;

	struct AttCont;
	struct NodeCont;

	// ***************************************************************************
	// ***************************************************************************
	//                               Konfigurationsobjekte
	//
	//
	// --------------------------------------------------------------------------
	// Eine Legende der genutzten Features findet sich in SAXParseXML.cpp bei der
	// Kommentierung der Methode 'SAXParseXML::initParsing'
	// --------------------------------------------------------------------------

	// ***************************************************************************
	//                                    SAXConfig
	// ***************************************************************************
	// Die Haupt-Konfigurationsklasse - die nicht direkt instantiiert werden kann.
	// Statt dessen sollen die mit sinnvollen Variablen-Belegungen ausgestatteten,
	// abgeleiteten Klassen verwendet werden.
	// Reihenfolge der Konstruktorparameter:
	// doNamespaces, doSchema, doValidation, handleErrors, handleContent
	class SAXConfig
	{
	public:
 		bool m_featDoNamespaces;
		bool m_featDoSchema;
		bool m_featDoValidation;

		bool m_handleErr;
		bool m_handleCont;

	protected:
		SAXConfig()
		{
 			m_featDoNamespaces = true;
			m_featDoSchema = true;
			m_featDoValidation = true;

			m_handleErr = true;
			m_handleCont = true;
		}

		// Reihenfolge der Konstruktorparameter:
		// doNamespaces, doSchema, doValidation, handleErrors, handleContent
		SAXConfig(bool featDoNamespaces, bool featDoSchema, bool featDoValidation,
			bool handleErr, bool handleCont)
		{
 			m_featDoNamespaces = featDoNamespaces;
			m_featDoSchema = featDoSchema;
			m_featDoValidation = featDoValidation;

			m_handleErr = handleErr;
			m_handleCont = handleCont;
		}
	};

	// ***************************************************************************
	//                                 SAXConfigParse
	// ***************************************************************************
	// Die Konfigurationsklasse für das Parsen des Inhaltes einer XML-Datei.
	// Wenn die Variablenbelegung unverändert bleibt wird hier keine Validierung 
	// aktiviert.
	class SAXConfigParse : public SAXConfig
	{
	public:
		// Reihenfolge der Konstruktorparameter:
		// doNamespaces, doSchema, doValidation, handleErrors, handleContent
		SAXConfigParse()
			:SAXConfig(true, false, false, true, true){};
	};

	// ***************************************************************************
	//                               SAXConfigValidate
	// ***************************************************************************
	// Die Konfigurationsklasse für das Validieren einer XML-Datei.
	// Wenn die Variablenbelegung unverändert bleibt wird hier keine inhaltliche
	// Analyse der XML-Datei aktiviert.
	class SAXConfigValidate : public SAXConfig
	{
	public:
		// Reihenfolge der Konstruktorparameter:
		// doNamespaces, doSchema, doValidation, handleErrors, handleContent
		SAXConfigValidate()
			:SAXConfig(true, true, true, true, false){};
	};


	
	// ***************************************************************************
	// ***************************************************************************
	//	                             Handlerobjekte
	//
	//
	// ***************************************************************************
	//	                         class SAXCommonHandler
	//
	//	                erweitert das SAX DefaultHandler interface
	//
	// Das Handler-Objekt erhält als Member-Variable ein zu ihm passendes 
	// Konfigurationsobjekt. Dieses muss über den Konstruktor gesetzt werden!
	//
	// Die Klasse ist nicht direkt instantiierbar - nur über eine abgeleitete Klassen.
	// ***************************************************************************
	class SAXCommonHandler : public xercesc::DefaultHandler
	{
	public:
		void startDocument();
		void endDocument();

		inline bool endOfFileReached()
		{
			return m_endOfFileReached;
		}

		inline void fileEndIsReached()
		{
			m_endOfFileReached = true;
		}

		inline SAXConfig* getSAXConfig()
		{
			return m_pSaxConf;
		}

		~SAXCommonHandler()
		{
			delete m_pSaxConf;
		}

		void setErrorHandler(XercesXMLErrorHandlerInterface* pErrHandler)
		{
			m_pErrHandler = pErrHandler;
		}

		// -----------------------------------------------------------------------
		// Reset
		//
		void reset()
		{
			m_errorMsg.str("");
			m_errorMsg.clear();
			m_errorCount = 0;
		}

		// -----------------------------------------------------------------------
		// Methoden des SAX ErrorHandler Interface
		// -----------------------------------------------------------------------
		virtual void warning(const xercesc::SAXParseException& exception);
		virtual void error(const xercesc::SAXParseException& exception);
		virtual void fatalError(const xercesc::SAXParseException& exception);

		inline std::string getErrorMsg() const
		{
			return m_errorMsg.str();
		}

		inline unsigned int getErrorCount() const
		{
			return m_errorCount;
		}

	protected:
		SAXCommonHandler(XercesXML::SAXConfig* pSaxConf)
		{
			m_errorCount = 0;
			m_pSaxConf = pSaxConf;
			m_pErrHandler = 0;
		}

		SAXConfig* m_pSaxConf;
		XercesXMLErrorHandlerInterface* m_pErrHandler;

		// -----------------------------------------------------------------------
		//  m_errorMsg    - Sammelt die Fehlermeldungen auf
		//  m_countErrors - Enthält die Anzahl erkannter Validierungsfehler.
		// 
		std::ostringstream m_errorMsg;
		unsigned int  m_errorCount;

	private:
		SAXCommonHandler() /*throw (NotInitialized)*/;

		bool m_endOfFileReached;

	};

	// ***************************************************************************
	//	                         class ValidiererHandler
	//
	//	                überschreibt SAX ErrorHandler interface
	//
	// Die Erzeugung eines Handler-Objektes läuft über die HandlerFactory.
	//
	// Die Ausstattung mit einem Config-Objekt erfolgt im Konstruktor des Handlers.
	// ***************************************************************************

	class ValidiererHandler : public SAXCommonHandler
	{
		friend class HandlerFactory;

	public:

		// -----------------------------------------------------------------------
		// Methoden des SAX ContentHandler Interface
		// 
		// Der ContentHandler ist komplett ausgeschaltet !!!

	private:
		// -----------------------------------------------------------------------
		// Konstruktor + Destruktor
		// 
		ValidiererHandler();
		~ValidiererHandler();
	};


	// ***************************************************************************
	//	                         class NodeHandler
	//
	//	               überschreibt SAX ContentHandler interface
	//
	// Die Erzeugung eines Handler-Objektes läuft über die HandlerFactory.
	//
	// Die Ausstattung mit einem Config-Objekt erfolgt im Konstruktor des Handlers.
	// ***************************************************************************

	enum LastItem {
		START,
		OTHER
	};

	class NodeHandler : public SAXCommonHandler
	{
		friend class HandlerFactory;

	public:
		// -----------------------------------------------------------------------
		//  Methoden des SAX ContentHandler Interface
		// -----------------------------------------------------------------------

		virtual void startElement(const XMLCh* const uri, const XMLCh* const localname, 
			const XMLCh* const qname, const xercesc::Attributes& attrs) = 0;
		void endElement(const XMLCh* const uri, const XMLCh* const localname, 
								const XMLCh* const qname);

		void characters(const XMLCh* const chars, const XMLSize_t length);

		void startPrefixMapping (const XMLCh* const prefix, const XMLCh* const uri);
		void endPrefixMapping(const XMLCh* const prefix);

		// -----------------------------------------------------------------------
		//  Get-Methoden
		// 
		inline int getAktEbene()
		{
			return m_aktEbene;
		}

		void getInScopeNamespaces(std::vector<std::string>& prefix,
			std::vector<std::string>& uri ) const;

		// -----------------------------------------------------------------------
		//  Set-Methoden
		// 
		inline void setAktEbene(int ebene)
		{	m_aktEbene = ebene;	}

	protected:
		// -----------------------------------------------------------------------
		// Konstruktor + Destruktor
		// -----------------------------------------------------------------------
		NodeHandler(SAXReader* pSR, NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
		~NodeHandler();

		// Aus den Informationen, die ein 'startElement'-Callback erhält, wird mit
		// Hilfe von einer dieser Methoden eine Menge von Nodes erzeugt.
		void createNodes(const XMLCh* const uri, const XMLCh* const localname, 
			const XMLCh* const qname, const xercesc::Attributes& attrs);

		SAXReader* m_pSR;
		NodeFactory* m_pNodeFactory;
		NodeFilter*  m_pNodeFilter;

		// m_aktEbene - die Ebene innerhalb der XML-Datei, die gerade gelesen wird
		int m_aktEbene;
		// m_endEbene - die Ebene, bei der das Einlesen (=Speichern) eines Elements
		//              beendet wird
		int m_endEbene;
		// m_recObject - Flag ob gerade ein Element eingelesen wird oder nicht
		bool m_recObject;
		// m_skipObject - true wenn Objekt bei rejectCurrentNode verworfen und keine Suche nach Filterausdrücken stattfinden soll
		bool m_skipObject;

		std::string elemName;
		std::string elemValue;

		LastItem m_lastItem;
		XMLCh* m_whitespace;

		// Namespace-Verwaltung
		struct NamespaceDecl 
		{ 
			NamespaceDecl(const std::string& pref, const std::string& uri)
				: m_pref(pref), m_uri(uri) {};
			std::string m_pref; std::string m_uri;
		};
		typedef std::list<NamespaceDecl> NamespaceContainer;
		NamespaceContainer m_inScopeNamespaces;

// DEBUG
//		boolean tmp_printName;
	};


	// ***************************************************************************
	//	                     class NodeHandlerElementSearch
	//
	//	               überschreibt SAX ContentHandler interface
	//
	// Die Erzeugung eines Handler-Objektes läuft über die HandlerFactory.
	//
	// NodeHandlerElementSearch ist ein Handler-Objekt, das für die Gewinnung eines
	// Objektes zuständig ist, das über seinen Element-Namen qualifiziert wird.
	// Damit ist also die Suche nach bestimmten Elementen möglich.
	// ***************************************************************************

	class NodeHandlerElementSearch : public NodeHandler
	{
		friend class HandlerFactory;

	public:
		void startElement(const XMLCh* const uri, const XMLCh* const localname, 
								const XMLCh* const qname, const xercesc::Attributes& attrs);
	private:
		NodeHandlerElementSearch(SAXReader* pSR, NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);

	};

	// ***************************************************************************
	//	                     class NodeHandlerAttributeSearch
	//
	//	               überschreibt SAX ContentHandler interface
	//
	// Die Erzeugung eines Handler-Objektes läuft über die HandlerFactory.
	//
	// NodeHandlerAttributeSearch ist ein Handler-Objekt, das für die Gewinnung eines
	// Objektes zuständig ist, das über seinen Attribut-Namen qualifiziert wird.
	// Damit ist also die Suche nach Elementen mit bestimmten Attributen möglich.
	// ***************************************************************************

	class NodeHandlerAttributeSearch : public NodeHandler
	{
		friend class HandlerFactory;

	public:
		void startElement(const XMLCh* const uri, const XMLCh* const localname, 
								const XMLCh* const qname, const xercesc::Attributes& attrs);
	private:
		NodeHandlerAttributeSearch(SAXReader* pSR, NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
	};


	// ***************************************************************************
	//	                     class AttributeContentHandler
	//
	//	               überschreibt SAX ContentHandler interface
	//
	// Die Erzeugung eines Handler-Objektes läuft über die HandlerFactory.
	//
	// AttributeContentHandler ist ein Handler-Objekt, das zu einem gegebenem
	// Attributnamen den Attributwert und zugehörigem Elementnamen gewinnen kann.
	//
	// Die Ausstattung mit einem Config-Objekt erfolgt im Konstruktor des Handlers.
	// ***************************************************************************

	class AttributeContentHandler : public SAXCommonHandler
	{
		friend class HandlerFactory;

	public:
		// -----------------------------------------------------------------------
		//  Methoden des SAX ContentHandler Interface
		// -----------------------------------------------------------------------

		void startElement(const XMLCh* const uri, const XMLCh* const localname, 
								const XMLCh* const qname, const xercesc::Attributes& attrs);

		void endElement(const XMLCh* const uri, const XMLCh* const localname, 
								const XMLCh* const qname);

		// -----------------------------------------------------------------------
		//  Get-Methoden
		// 
		inline int getAktEbene()
		{
			return m_aktEbene;
		}

		// -----------------------------------------------------------------------
		//  Set-Methoden
		// 
		inline void setAktEbene(int ebene)
		{
			m_aktEbene = ebene;
		}

	protected:
		// -----------------------------------------------------------------------
		// Konstruktor + Destruktor
		// -----------------------------------------------------------------------
		AttributeContentHandler(SAXReader* pSR, NodeFilter*  pNodeFilter);

		SAXReader* m_pSR;
		NodeFilter*  m_pNodeFilter;

		int m_aktEbene;
	};



	// ***************************************************************************
	//	                     class ElementChildFilterHandler
	//
	//	               überschreibt SAX ContentHandler interface
	//
	// Die Erzeugung eines Handler-Objektes läuft über die HandlerFactory.
	// Die Ausstattung mit einem Config-Objekt erfolgt im Konstruktor des Handlers.
	//
	// Ein gegebener Such-Ausdruck soll dem Element-Namen eines Child-Elements entsprechen,
	// Bei Erfolg muss also ggf. der aktuelle (Child-)Knoten sowie der zuvor eingelesene
	// Vater-Knoten erzeugt werden sowie alle darunter liegenden Nodes.
	// Solange noch keine Nodes gespeichert (bzw. erzeugt) werden muss also ein gerade
	// eingelesenes Element (inkl. seiner Attribute) zwischengespeichert werden, weil es 
	// ggf. als Vater-Element benötigt wird.
	//
	// ***************************************************************************

	// Attribut-Inhalte für ein zwischengespeichertes Element
	struct AttCont
	{
	public:
		XMLCh*  m_attUri;
		XMLCh*  m_attQName;
		XMLCh*  m_attValue;

		AttCont()
		{
			m_attUri   = 0;
			m_attQName = 0;
			m_attValue = 0;
		};

		AttCont(XMLCh* attUri, XMLCh* attQName, XMLCh* attValue)
		{
			XERCESCNAMESPACE::XMLString::copyString(m_attUri, attUri);
			XERCESCNAMESPACE::XMLString::copyString(m_attQName, attQName);
			XERCESCNAMESPACE::XMLString::copyString(m_attValue, attValue);
		}

		~AttCont()
		{
			if(m_attUri)
				XERCESCNAMESPACE::XMLString::release(&m_attUri);
			if(m_attQName)
				XERCESCNAMESPACE::XMLString::release(&m_attQName);
			if(m_attValue)
				XERCESCNAMESPACE::XMLString::release(&m_attValue);
		};
	};

	
	struct AttributesCont
	{
	private:
		std::vector<AttCont*>* m_atts;
	public:
		// Default-Größe für die Attribut-Liste: 20 Einträge
		AttributesCont(unsigned int size = 20)
		{
			m_atts = new std::vector<AttCont*>(size);
			for(unsigned int i=0; i<m_atts->size(); i++)
			{
				m_atts->at(i) = new AttCont();
			}
		}
		~AttributesCont()
		{
			for(size_t i=0; i<m_atts->size(); i++)
			{
				delete m_atts->at(i);
			}
			delete m_atts;
		}

		inline size_t size()
		{
			if(m_atts)
				return m_atts->size();
			return 0;
		}
		inline AttCont* at(size_t index)
		{
			if(m_atts)
				return m_atts->at(index);
			return 0;
		}
	};

	// Node-Inhalte für ein zwischengespeichertes Element
	struct NodeCont
	{
	public:
		XMLCh* m_uri;
		XMLCh* m_localname;
		XMLCh* m_qname;
		AttributesCont* m_attributes;

		NodeCont()
		{
			m_uri = 0;
			m_localname = 0;
			m_qname = 0;
			m_attributes  = new AttributesCont();
		}

		~NodeCont()
		{
			if(m_uri)
				XERCESCNAMESPACE::XMLString::release(&m_uri);
			if(m_localname)
				XERCESCNAMESPACE::XMLString::release(&m_localname);
			if(m_qname)
				XERCESCNAMESPACE::XMLString::release(&m_qname);
			if(m_attributes != 0)
				delete m_attributes;
		}

		// Neue Werte setzen
		// mit Attributen
		void setValues(const XMLCh* const uri, const XMLCh* const localname, 
			const XMLCh* const qname, const xercesc::Attributes& attrs);
		// ohne Attribute
		void setValues(const XMLCh* const uri, const XMLCh* const localname, 
			const XMLCh* const qname);
	};

	class ElementChildFilterHandler : public NodeHandler
	{
		friend class HandlerFactory;
		friend class SAXReader;

	public:
		// -----------------------------------------------------------------------
		//  Methoden des SAX ContentHandler Interface
		// -----------------------------------------------------------------------

		virtual void startElement(const XMLCh* const uri, const XMLCh* const localname, 
			const XMLCh* const qname, const xercesc::Attributes& attrs);
		void endElement(const XMLCh* const uri, const XMLCh* const localname, 
			const XMLCh* const qname);

	protected:
		// -----------------------------------------------------------------------
		// Konstruktor + Destruktor
		// -----------------------------------------------------------------------
		ElementChildFilterHandler(SAXReader* pSR, NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
		~ElementChildFilterHandler();

		void createNodes(NodeCont* pNC, bool addInScopeNamespaces = false);
		void deleteNodeCont(NodeCont* pNC);

		// Inhalte von Nodes, die wir evtl. später noch erzeugen möchten (in Abhängigkeit
		// von 'SAXReader::rejectNode' bzw. 'SAXReader::getCurrentNode') merken wir uns
		NodeCont* m_pNode;
		NodeCont* m_pChild;
	private:
		// Methoden für den SAXReader, um den Lese-Status (Node-Erzeugen vs. Node-Verwerfen)
		// beeinflussen zu können
		void setStatus(bool createNode);

	private:
		bool m_nextChildName;
	};



	// ***************************************************************************
	//	                         class AttributeFilterHandler
	//
	//	               überschreibt SAX ContentHandler interface
	//
	// Die Erzeugung eines Handler-Objektes läuft über die HandlerFactory.
	//
	// Die Ausstattung mit einem Config-Objekt erfolgt im Konstruktor des Handlers.
	// ***************************************************************************

	class AttributeFilterHandler : public ElementChildFilterHandler
	{
		friend class HandlerFactory;
		friend class SAXReader;

	public:
		// -----------------------------------------------------------------------
		//  Methoden des SAX ContentHandler Interface
		// -----------------------------------------------------------------------

		virtual void startElement(const XMLCh* const uri, const XMLCh* const localname, 
			const XMLCh* const qname, const xercesc::Attributes& attrs);

	protected:
		// -----------------------------------------------------------------------
		// Konstruktor + Destruktor
		// -----------------------------------------------------------------------
		AttributeFilterHandler(SAXReader* pSR, NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
	private:
		// Methoden für den SAXReader, um den Lese-Status (Node-Erzeugen vs. Node-Verwerfen)
		// beeinflussen zu können
		void setStatus(bool createNode);
	};


	// ***************************************************************************
	//	                         class NextElementFilterHandler
	//
	//	               überschreibt SAX ContentHandler interface
	//
	// Die Erzeugung eines Handler-Objektes läuft über die HandlerFactory.
	//
	// Die Ausstattung mit einem Config-Objekt erfolgt im Konstruktor des Handlers.
	// ***************************************************************************

	class NextElementFilterHandler : public ElementChildFilterHandler
	{
		friend class HandlerFactory;
		friend class SAXReader;

	public:
		// -----------------------------------------------------------------------
		//  Methoden des SAX ContentHandler Interface
		// -----------------------------------------------------------------------

		virtual void startElement(const XMLCh* const uri, const XMLCh* const localname, 
			const XMLCh* const qname, const xercesc::Attributes& attrs);

	protected:
		// -----------------------------------------------------------------------
		// Konstruktor + Destruktor
		// -----------------------------------------------------------------------
		NextElementFilterHandler(SAXReader* pSR, NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
	private:
		// Methoden für den SAXReader, um den Lese-Status (Node-Erzeugen vs. Node-Verwerfen)
		// beeinflussen zu können
		void setStatus(bool createNode, bool skipNode=false);
	};


	// ***************************************************************************
	//	                     class HandlerFactory
	//
	//	               überreicht die interessierenden Handler
	//
	// Die HandlerFactory liefert auf Wunsch ein passendes Handler-Objekt.
	// Singleton-Mechanismus.
	// Für jedes Handler-Objekt muss eine get-Methode implementiert werden.
	// ***************************************************************************

	enum HandleMode {
		NO_MODE,
		VALID,
		NODE_ELEM,
		NODE_ATT,
		ATT_CONT,
		FILT_ELEM,
		FILT_ATT,
		FILT_NEXTELEM
	};

	class HandlerFactory
	{
		friend class SAXReader;	
	public:
		// 'Frischen' Handler holen
		SAXCommonHandler* getValidiererHandler();

		SAXCommonHandler* getNodeHandlerElementSearch(SAXReader* pSR, 
							NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
		SAXCommonHandler* getNodeHandlerAttributeSearch(SAXReader* pSR, 
							NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
		SAXCommonHandler* getAttributeContentHandler(SAXReader* pSR, 
							NodeFilter*  pNodeFilter);
		SAXCommonHandler* getElementChildFilterHandler(SAXReader* pSR, 
							NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
		SAXCommonHandler* getAttributeFilterHandler(SAXReader* pSR, 
							NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
		SAXCommonHandler* getNextElementFilterHandler(SAXReader* pSR, 
							NodeFactory* pNodeFactory, NodeFilter*  pNodeFilter);
	private:
		
		HandlerFactory();
		HandlerFactory(const HandlerFactory& hf){}
		~HandlerFactory();

		int getHandlerEbene();

		ValidiererHandler* m_pValidierer;
		NodeHandlerElementSearch* m_pNodeElement;
		NodeHandlerAttributeSearch* m_pNodeAttribute;
		AttributeContentHandler* m_pAttribCont;
		ElementChildFilterHandler* m_pFilter;
		AttributeFilterHandler* m_pAttFilter;
		NextElementFilterHandler* m_pNextElemFilter;

		HandleMode m_mode;
	};




}//namespace

#endif

