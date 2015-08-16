/*****************************************************************************
* $Id: XercesXML.h 2011-11-11 11:11:11 vogelsang $
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
* 2010-11-18 Bereinigungen im Interface
* 2010-11-22 Speicherlecks beseitigen
* 2010-11-24 Komprimierte XML-Dateien lesen
* 2011-08-05 Formale Anpassungen für CYGWIN
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 
****************************************************************************/
// XercesXML.h

//==============================================================================
//
// Dieser File bildet einen vereinfachten Wrapper um den Xerces-XML-Parser. 
// Der Zweck ist, die zukünftigen Veränderungen am Xerces von der nutzenden
// Software zu trennen.
//
// This product includes software developed by the Apache Software Foundation
// (http://www.apache.org).
//
// Das XercesXML-System ist durch die Funktionen XercesXML::System::initialize() 
// zu starten und durch XercesXML::System::finalize() zu beenden.
//
// Das durch den Default-Constructor erzeugte Parser-Objekt kennt Namespaces
// und macht volle Schemavalidierung entsprechend den Angaben in der XML-Datei.
// Ergebnis ist ein DOMNode-Objekt, das für das Document steht.
//
// Die DOMNodes repräsentieren "delegierende Smart-Pointer"-Objekte. Sie 
// weisen selbst das Methoden-Inferface auf und delegieren in geeigneter Form 
// an Xerces weiter. Die DOMNode-Objekte übernehmen selbsttätig die Lebens-
// dauerverwaltung der Objekte des tatsächlichen Xerces-DOM.
//
//==============================================================================

#ifndef XERCESXML_H
#define XERCESXML_H

#include <string>
#include <vector>

#include "XercesXMLErrorHandlerInterface.h"
#include "Exceptions.h"
//#include <xercesc/util/XercesDefs.hpp>

#ifdef WIN32
#if (_MSC_VER < 1400) && !defined(CYGWIN)
#define XERCESCNAMESPACE xercesc
#else
#define XERCESCNAMESPACE xercesc_3_1
#endif
#endif
#ifdef GENERIC_LINUX
#define XERCESCNAMESPACE xercesc_3_1
#endif
namespace XERCESCNAMESPACE
{
	// Forwards
	class XercesDOMParser;
	class SecurityManager;
	class DOMNode;
	class DOMTypeInfo;
	class DOMDocument;
	class MemBufFormatTarget;
	class BinInputStream;
	class InputSource;
}

namespace XercesXML
{
	// Forwards
	class DocCounter;
	class DOMNode;
	class DOMTypeInfo;
	class DOMDocument;
	class NodeFactory;
	class BufferType;

	//--------------------------------------------------------------------------

	class Exception : public structured_exception
	{
	public:
		// Dtor
		~Exception() NOTHROW 
		{};
		// Message erfragen
		std::string getMessage() const NOTHROW 
		{ return m_errMsg; }
	protected:
		// Ctor
		Exception( const std::string& msg, const char* pId, int nS = 0, const char** pS = 0 ) NOTHROW
			: structured_exception(msg.c_str(), false, "Xerces", pId, nS, pS ), m_errMsg( msg ) {};
	protected:
		std::string m_errMsg;
	};

	class NotInitialized : public Exception
	{
	public:
		// Ctor
		inline NotInitialized( const std::string& msg ) NOTHROW
			: Exception( msg, "NotInitialized" ) {};
	};

	class InitializationFailure : public Exception
	{
	public:
		// Ctor
		inline InitializationFailure( const std::string& msg ) NOTHROW 
			: Exception( msg, "InitializationFailure" ) {};
	};

	class ParsingError : public Exception
	{
	public:
		// Ctor
		inline ParsingError( const std::string& msg ) NOTHROW
			: Exception( msg, "ParsingError" ) {};
	};

	class NullPointer : public Exception
	{
	public:
		// Ctor
		inline NullPointer( const std::string& msg ) NOTHROW
			: Exception( msg, "NullPointer" ) {};
	};

	class NavigationError : public Exception
	{
	public:
		// Ctor
		inline NavigationError( const std::string& msg ) NOTHROW
			: Exception( msg, "NavigationError" ) {};
	};

	class ConversionError : public Exception
	{
	public:
		// Ctor
		inline ConversionError( const std::string& msg ) NOTHROW
			: Exception( msg, "ConversionError" ) {};
	};

	class FormatError : public Exception
	{
	public:
		// Ctor
		inline FormatError( const std::string& msg ) NOTHROW
			: Exception( msg, "FormatError" ) {};
	};

	class TranscoderError : public Exception
	{
	public:
		// Ctor
		inline TranscoderError( const std::string& msg ) NOTHROW
			: Exception( msg, "TranscoderError" ) {};
	};

	//--------------------------------------------------------------------------

	// Zähler-Objekt, das die Lebensdauer der Documents überwacht.
	class DocCounter
	{
		friend class DOMNode;
		friend class DOMDocument;
		friend class NodeFactory;
	private:
		// Default Ctor
		DocCounter() 
			: m_count(1), m_pOwner(0), m_pProxy(0) {}
		// Ctor with Owner-Node
		DocCounter( XERCESCNAMESPACE::DOMNode* pOwn ) 
			: m_count(1), m_pOwner(pOwn), m_pProxy(0) {}
		// Dtor
		~DocCounter() {}
		// Referenzzähler erhöhen
		void addRef() { m_count++; }
		// Referenzzähler vermindern. Bei Null, Aufgeben des verwalteten
		// Objekts (Document oder anderer DocCounter)
		void release();
	private:
		unsigned	m_count;			// Benutzungszähler
		XERCESCNAMESPACE::DOMNode*	m_pOwner;	// Zeiger auf Document (oder äquiv.)
		DocCounter*	m_pProxy;			// Alternativ: Zeiger auf DocCounter
	};

	//--------------------------------------------------------------------------
	// Encoding für Output und SAX-Methoden
	enum EncodingType { lcp, utf8 };

	//--------------------------------------------------------------------------

	class System
	{
	public:
		// XercesXML-System initialisieren
		static void initialize(EncodingType outputEncoding = lcp) 
			/*throw( InitializationFailure )*/;

		// XercesXML-System finalisieren
		static void finalize() /*throw()*/;

		// Erfragen, ob XercesXML-System initilaisiert ist
		static bool isInitialized();

		// OutputEncoding erfragen
		static EncodingType getOutputEncoding() /*throw( NotInitialized )*/;

	private:
		// Initialisierungs-Flag
		static int m_nInitializations;

		static EncodingType m_outputEncoding;
	};

	//--------------------------------------------------------------------------

	class DOMNode
	{
		friend class Parser;
		friend class NodeFactory;

	public:
		// Default Ctor
		// Leere DOM-Node erzeugen
		// REENTRANT
		DOMNode() /*throw( NotInitialized )*/;

		// Copy Ctor
		// REENTRANT
		DOMNode( const DOMNode& dn ) /*throw( NotInitialized )*/;

		// Dtor
		// DOM-Node und gesamtes Dokument vergessen
		// REENTRANT
		~DOMNode() /*throw()*/;

		// Zuweisung
		DOMNode& operator=( const DOMNode& dn ) /*throw()*/;

		// Gleichheit
		// REENTRANT
		bool operator==( const DOMNode& dn ) const /*throw()*/;

		// Konversion nach Bool
		// REENTRANT
		operator bool() const /*throw()*/;

		// Erstes ChildNode ermitteln
		// REENTRANT
		DOMNode getFirstChild() const /*throw( NullPointer, NavigationError )*/;

		// Erstes ChildNode, das Element ist, ermitteln
		// REENTRANT
		DOMNode getFirstElementChild() const 
			/*throw( NullPointer, NavigationError )*/;

		// Nächstes SiblingNode ermitteln
		// REENTRANT
		DOMNode getNextSibling() const /*throw( NullPointer, NavigationError )*/;

		// Nächstes SiblingNode, das Element ist, ermitteln
		// REENTRANT
		DOMNode getNextElementSibling() const 
			/*throw( NullPointer, NavigationError )*/;

		// Namen des Knotens ermitteln
		// REENTANT
		std::string getNodeName() const /*throw( NullPointer, NavigationError )*/;

		// Namespace-Prefix des Knotens ermitteln
		// REENTRANT
		std::string getNamespacePrefix() const 
			/*throw( NullPointer, NavigationError )*/;

		// Namespace-Uri des Knotens ermitteln
		// REENTRANT
		std::string getNamespaceUri() const 
			/*throw( NullPointer, NavigationError )*/;

		// Wert des Knotens ermitteln
		// REENTANT
		std::string getNodeValue() const /*throw( NullPointer, NavigationError )*/;

		// Prädikat: Ist das ein Element?
		// REENTRANT
		bool isElement() const /*throw()*/;

		// Prädikat: Ist das ein Text?
		// REENTRANT
		bool isText() const /*throw()*/;

		// Textwert der Kinder ermitteln
		// REENTRANT
		std::string getNodeChildText() const 
			/*throw( NullPointer, NavigationError )*/;

		// Knoten eines vorgegebenen Namens ermitteln
		// REENTRANT
		DOMNode findFirstNodeByName( const std::string& name ) const
			/*throw( NavigationError )*/;

		// Knoten mehrerer vorgegebener Namen ermitteln
		// REENTRANT
		DOMNode findFirstNodeByNameList( 
			const std::vector<std::string>& name ) const
			/*throw( NavigationError )*/;

		// Attributwert per Attributnamen
		// REENTRANT
        std::string getAttributeValueByName( const std::string& name, const std::string& nsuri="" ) const
			/*throw( NullPointer, NavigationError )*/;

		// Alle Namespaces, die für ein Node gültig sind, nachweisen
		// REENTRANT
		void getInScopeNamespaces( 
			std::vector<std::string>& prefix,
			std::vector<std::string>& nsuri ) const
			/*throw( NavigationError )*/;

		// Namespace-URI zum Präfix feststellen
		bool getNamespaceURI( 
			const std::string& prefix, std::string& nsuri ) const
			/*throw( NavigationError )*/;

		// Namespace-Präfix zur URI feststellen
		bool getNamespacePrefix(
			const std::string& nsuri, std::string& prefix ) const
			/*throw( NavigationError )*/;

		// GML2-Koordinaten <coord> oder <coordinates> parsen
		void getGml2Coordinates( 
			size_t dim, std::vector<double>& coord ) const
			/*throw( NullPointer, ConversionError, FormatError )*/;

		// Parent ermitteln
		DOMNode getParentNode() const /*throw( NullPointer, NavigationError )*/;

		// Attribute ermitteln
		size_t getNoOfAttributes() const;
		bool getAttribute( size_t idx, std::string& name, std::string& value )
			const;

		// Typ-Name für Element/Attribut-Nodes
		// ('false' bedeutet Fehler: keien Element/Attribute-Node oder keine
		// Schema-Info beim Parsen.)
		bool getTypeName( std::string& type_name, std::string& type_namespace )
			const;
		
		// Ist der Type abgeleitet aus dem übergebenen Typ?
		// (to do! Prüft z.Zt. nur den eigenen Typ.)
		bool TypeIsDerivedFrom( const std::string& type_name,
			const std::string& type_namespace ) const;

		// Id in Form des DOM_Node-Ptrs
		size_t getId() const { return (size_t)m_pDOM_Node; };

		// Node als Xml
		// (Output-Encoding kann frei gewählt werden; Default
		// ist das der Eingabe.)
		// ...in ein File
		void asXml( const std::string& strOutputfile,
			const std::string& strOutputEncoding="" ) const
			/*throw( ParsingError )*/;
		// ...ins Memory
		void asXml( BufferType& buf, const std::string& strOutputEncoding="" )
			const /*throw( ParsingError )*/;

		// URI des geöffneten DOMDocuments
		std::string getDocumentURI() const;

	private:
		// Ctor mit Xerces DOMNode
		// REENTRANT
		DOMNode( XERCESCNAMESPACE::DOMNode* pXdn, DocCounter* pDCn=0 )
			/*throw()*/;

		// TypeInfo für Elemente/Attribute ermitteln
		const XERCESCNAMESPACE::DOMTypeInfo* getTypeInfo() const;

		// Helper für asXml
		void _asXml( const std::string& strOutputfile,
			BufferType& buf, const std::string& strOutputEncoding ) const
			/*throw( ParsingError )*/;

		// DEBUG
#ifdef SEE_PUFF
		void printContent();
#endif

	private:
		// Zeiger auf das echte Xerces-DOMNode-Objekt. 
		XERCESCNAMESPACE::DOMNode* m_pDOM_Node;

		// Zeiger auf das zugehörige Zähler-Objekt, das die bestehenden
		// Nutzungen des gesamten Documents mitführt.
		DocCounter* m_pDocCounter;
	};

	//--------------------------------------------------------------------------

	class Parser
	{
	public:
		// Default Ctor
		// Parser-Objekt erzeugen 
		// REENTRANT
		Parser( bool lax = false, bool createSchemaInfo = false ) 
			/*throw( NotInitialized )*/;

		// Dtor
		~Parser() /*throw()*/;

		// Dem Parset die Verarbeitung von XIncludes ermöglichen
		// (ACHTUNG: In diesem Fall erfolgt *keine* Schema-Validierung,
		// auch nicht, wenn im Ctor lax == true war!!)
		// Weiterer Parameter (wird ignoriert, falls doXInclude==false):
		// FileName für den Dump des Files mit aufgelösten XIncludes (leerer
		// String schaltet Anlegen des Dumps ab)
		void setDoXInclude( bool doXInclude, const std::string& dumpfn="" );
		// Zustand bzgl. XInclude erfragen
		bool getDoXInclude() const;
		// Filename für File-Kopie mit aufgelösten XIncludes
		std::string getDoXIncludeDumpFileName() const;

		// Am Parser-Objekt andere SchemaLocations setzen
		void setExternalSchemaLocation( const std::string& strExtSchemaLoc );
		// Am Parser-Objekt gesetzte SchemaLocations erfragen
		std::string getExternalSchemaLocation() const;

		// Security
		// Im Moment nur EntityExpansionLimit
		void setEntityExpansionLimit(unsigned limit);
		void deactivateEntityExpansionLimit();

		// Einen File parsen
		// REENTRANT
		DOMNode parseFile( const std::string& fn ) 
			/*throw( ParsingError )*/;

		// Einen Char-String parsen
		// REENTRANT
		DOMNode parseFile( const std::string& bytes, const std::string& root )
			/*throw( ParsingError )*/;

		// Text im Buffer (s. DOMNode::asXml()) parsen
		// REENTRANT
		DOMNode parseBuffer( const BufferType& buf, const std::string& root ) 
			/*throw( ParsingError )*/;

		// Den Default-ErrorHandler für Ausgaben von Fehlermeldungen
		// überschreiben
		void setErrorHandler( XercesXMLErrorHandlerInterface* errHandler );

	private:
        // Diese Funktion führt ein striktes Re-Parsing durch, oder gibt einen Dump aus, oder beides
        void reparseAndOrDump(const std::string& fn, bool reparse);

		// Zeiger auf das eigentliche Xerces-DOM-Parser-Objekt
		XERCESCNAMESPACE::XercesDOMParser* m_pParser;
		XERCESCNAMESPACE::SecurityManager* m_pSecurity;
		// Der eigentliche ErrorHandler
		XercesXMLErrorHandlerInterface* m_pErrHandler;
		// Filename für Dump beim Parsen von XInclude
		std::string m_strXInclDumpFn;
	};

	// BufferType ist ein Wrapper für Xerces-c-MemoryBuffer
	class BufferType
	{
	public:
		BufferType();
		~BufferType();

		// Inhalt als String (ohne Transcodierung!)
		std::string getString() const;

	private:
		XERCESCNAMESPACE::MemBufFormatTarget* pFormTarget;

		friend class DOMNode;
		friend class Parser;
	};


}

#endif
