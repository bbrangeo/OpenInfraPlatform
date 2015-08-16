/*****************************************************************************
* $Id: SAXReader.h 2012-07-27 15:57:11 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt f�r Stra�enwesen
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
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 2012-07-27 InputSource verallgemeinert
* 
****************************************************************************/
/* SAXReader.h
*
* Einlesen und Verarbeiten einer XML-Datei mit Hilfe des Xerces-SAX-Parser.
*
* 24.08.2011  MF - HandlerFactory nicht mehr statisch, sondern eine pro SAXReader
* 19.05.2009  MF - getCurrentNode ber�cksichtigt die in-scope-Namespaces
* 14.05.2009  MF - getInScopeNamespaces - liefert jetzt die f�r das *aktuelle* Element g�ltigen NS
* 13.05.2009  MF - getCurrentElementName - Elementnamen erfragen
* 11.05.2009  MF - getCurrentAttributeValues - Attribute des aktuellen Elements erfragen
* 11.05.2009  SO/MF - getCurrentNode - Fehlerkorrektur: Filter unterhalb des Elements ignorieren
* 11.05.2009  MF - getNextElementName kann auch die NS-Uri des ElementNamens zur�ckbringen
				   sowie den Parent-Context (vector aller Elemente in der Parent-Achse)
* 07.05.2009  MF - getNextElementName pr�ft Vorhandensein von m_pReader und wirft evtl. Exception
* 22.04.2004  SO - Erg�nzung von Parse-Methoden, Ber�cksichtigung von Suchlevels
* 28.01.2004  SO - Erweiterung um 'getTopElementNameToAttribute' 
*                   + Fehlerkorrekturen + Fehlerhandlung erweitert
* 14.01.2004  SO - Datei erzeugt
*
*
* Die Klasse SAXReader ist die zentrale Klasse, die von einer Anwendung
* benutzt werden kann, um den Parse-Vorgang ablaufen zu lassen und zu steuern.
* Dies geschieht durch die Bereitstellung mehrerer Methoden, die unterschiedliche
* Parse-Abl�ufe enthalten.
*
* �bersicht:
* M�gliche Aktionen �ber SAXReader, SAXNode, SAXHandler
*
* 1. Methode 'validate', Handler 'ValidiererHandler'
*	Gegeben: -
*	Ergibt:  Validierung der XML-Datei
*
* 2. Methode 'getNextNode' bzw. 'getNextNodeByElementName', Handler 'NodeHandlerElementSearch'
*	Gegeben: Name eines Elements
*	Ergibt:  Das Element als DOMNode (wenn vorhanden)
*
* 3. Methode 'getNextNodeByAttributeName', Handler 'NodeHandlerAttributeSearch'
*	Gegeben: Name eines Attributs
*	Ergibt:  Das Element, das das Attribut enth�lt, als DOMNode (wenn vorhanden)
*
* 4. Methode 'getAttributeContentByName', Handler 'AttributeContentHandler'
*	Gegeben: Name eines Attributs
*	Ergibt:  Name des Elements, das das Attribut enth�lt, plus den Attributwert (wenn vorhanden)
*
* 5. Methode 'getFirstElementChildName', Handler 'ElementChildFilterHandler'
*	Gegeben: Name eines Elements
*	Ergibt:  Name des FirstChildNode zu dem angegebenen Element (wenn vorhanden)
*	--	Erlaubt Fortsetzung mit 'rejectCurrentNode' (zugeh�riger Node wird verworfen)
*	--	und 'getCurrentNode' (das Element wird als DOMNode zur�ckgegeben).
*
* 6. Methode 'getNextElementName', Handler 'NextElementFilterHandler'
*	Gegeben: Name eines Element
*	Ergibt:  Name des Element (wenn vorhanden)
*	--	Erlaubt Fortsetzung mit 'rejectCurrentNode' (zugeh�riger Node wird verworfen)
*	--	und 'getCurrentNode' (das Element wird als DOMNode zur�ckgegeben).
*
* 7. Methode 'getTopElementNameToAttribute', Handler 'AttributeFilterHandler'
*	Gegeben: Name eines Attributs
*	Ergibt:  Name des Vaterlements, Name des Elements, das das Attribut enth�lt,
*	         den Attributnamen plus den Attributwert (wenn vorhanden)
*	--	Erlaubt Fortsetzung mit 'rejectCurrentNode' (zugeh�riger Node wird verworfen)
*	--	und 'getCurrentNode' (das Element wird als DOMNode zur�ckgegeben).
*
*
*/

#ifndef SAXReader_h
#define SAXReader_h


#include <string>
#include <iostream>
#include <set>
#include <map>

#include "XercesXML.h"

//#define MY_SAX_DEBUG  // erzeugt zus�tzliche Ausgaben auf der Konsole

namespace XercesXML
{
	// forwards:
	class SAXParseXML;
	class SAXCommonHandler;
	class ElementChildFilterHandler;
	class AttributeFilterHandler;
	class NodeHandler;
	class AttributeContentHandler;
	class NodeFactory;
	class NodeFilter;
	class NodeHandler;
	class HandlerFactory;
	class AttributeContentHandler;
	class InputSource;
	class InputStream;
	class AbstractInputSource;

	enum Node_Such_Art
	{
		EMPTY,
		SUCH_ELEMENT_NODE,
		SUCH_ATTRIBUTE_NODE,
		SUCH_ATTRIBUTE_VALUE,
		FILTER_ELEMENT_NAME,
		FILTER_ATTRIBUT_NAME,
		FILTER_NEXTELEMENT_NAME
	};

	enum LastFuncCall
	{
		NOCALL,
		FIRSTELEMCHILDNAME,
		NEXTELEMENTNAME
	};


	static const std::string STANDARD_SUCH_ELEMENT = "okstraObjekt";

	typedef std::set<std::string> AppSuchNamen;
	typedef std::set< std::pair<std::string, std::string> > AppSuchNamenNS; // Format: Namespace, Name
	typedef std::set<int> AppSuchLevels;

	// ***************************************************************************
	//                                    SAXReader
	// ***************************************************************************

	// Es werden verschiedene Methoden zur Verf�gung gestellt mit denen der Inhalt 
	// einer XML-Datei ausgelesen werden kann:
	//
	// - Validierung - pr�fen ob die XML-Datei einem gegebenem Schema entspricht
	//
	// - NodeReading - Die XML-Datei wird schrittweise bearbeitet. Pro Schritt wird,
	//        ausgehend vom aktuellen Fokus innerhalb der XML-Datei, ein Teil der
	//        Datei eingelesen und ggf. innerhalb eines DOMNode gespeichert.
	//        Ein Schritt endet mit dem Fokus hinter der Stelle, die zuletzt eingelesen
	//        wurde, oder mit Erreichen des Dateiendes.
	//
	// - Namensermittlung - Zu einem vorgegebenem Attributnamen werden die Namen der
	//        Elemente sowie der jeweilige Attributwert bestimmt, die dieses Attribut
	//        enthalten
	//
	// - NodeFilter - Ein Element wird zun�chst so weit eingelesen dass zus�tzliche 
	//        Klasseninformation zu einem Klassennamen oder einer Menge von Attributnamen
	//        erh�ltlich ist.
	//        In einem weiterem Aufruf kann dann entschieden werden ob die Inhalte dieses
	//        Elements als DOMNode erzeugt werden oder ob der Parser diesen Teil verwirft.

	class SAXReader
	{
		friend class AttributeContentHandler; // um Lesen von Attribut-Inhalten steuern zu k�nnen
		friend class NodeHandler; // der und seine Kinder d�rfen einen Parse-Vorgang anhalten (parseHalt-Methode)
		friend class ElementChildFilterHandler;
		friend class AttributeFilterHandler;
		friend class NextElementFilterHandler;

	public:
		SAXReader(const std::string& xmlFile, bool bZipped = false) /*throw ( ParsingError )*/;
		SAXReader(const std::string& xmlString, const std::string& xmlStringId) 
			/*throw ( ParsingError )*/;
		SAXReader(XercesXML::AbstractInputSource* pxmlSource) 
			/*throw ( ParsingError )*/;
		~SAXReader();

		// Setzen und Ermitteln des ErrorHandler
		void setErrorHandler(XercesXMLErrorHandlerInterface* pErrHandler);
		inline XercesXMLErrorHandlerInterface* getErrorHandler()
		{
			return m_pErrHandler;
		}

		// Einholen der Namespace-Info
		void getInScopeNamespaces(std::vector<std::string>& prefix, 
			std::vector<std::string>& uri ) const;

		// Der SAXReader wird wieder auf Datei-Anfang gesetzt und alle
		// internen Ressourcen f�r einen Neustart initialisiert.
		void reInitialize();

	// -- Validierung --
		// Validierung der XML-Datei (die vorher gesetzt werden muss).
		// Bei Bedarf kann ein XML-Schema angegeben werden um eine
		// Validierung gegen dieses Schema zu erreichen.
		// ACHTUNG: vorher ggf. reInitialize!!
		//
		// schemaLoc - Name eines externen Schemas (Namespace + <leer> + XSD-Datei)
		bool validate(const std::string& schemaLoc = "") /*throw ( ParsingError )*/;

		// externe schemaLocation
		void setSchemaLocation(const std::string& schemaLocation)
			{ m_strSchemaLocation = schemaLocation; };

		// EntityExpansionLimit
		void setEntityExpansionLimit(unsigned limit);
		void deactivateEntityExpansionLimit();

	// -- NodeReading --
		// Node-Verwaltung - Schnittstellen f�r die Anwendung:
		//
		// Bei allen Methoden gilt: 
		// Wenn das Ende der XML-Datei erreicht wurde ohne einen DOMNode mit Inhalten 
		// f�llen zu k�nnen wird eine NoNodeAvailable-Exception geworfen.
		//
		// Achtung: Die erzeugten DOMNodes h�ngen vom Reader ab (via Oberelement)! D.h.
		// die Nodes m�ssen vor dem Reader freigegeben werden (notfalls mit Zuweisung auf
		// einen leeren DOMNode).
		//
		// --- Auslese-Methoden die direkt DOMNode-Objekte erzeugen ---
		//
		// M�gliche Parameter:
		// - IN - std::string name - Name der gew�nschten Eigenschaft (Elementname bzw. Attributname)
		// - IN - AppSuchNamen& namen - Menge von Namen der gew�nschten Eigenschaft (Elementname bzw. Attributname)
		// - IN - EncodingType encoding - Encoding der namen
		// - IN - AppSuchLevels& level - Menge von Levels innerhalb der XML-Datei, bei denen die gew�nschte Info stehen kann
		//                               (wird nicht von allen Methoden unterst�tzt)
		//								 MF-2011-05-04: Levels beginnen bei 0 (= TopLevel)
		//
		// Methode ohne Parameter, wenn auch entsprechende Methoden mit Parameter existieren:
		// Die Methode wird mit den zuvor verwendeten Suchparametern verwendet.
		// Vorher muss also die entsprechende Methode mit Angabe von Parametern aufgerufen werden!
		//
		//
		// Liefert den n�chsten Node mit dem Elementnamen STANDARD_SUCH_ELEMENT
		// (definiert am Beginn von SAXReader.h)
		//
		XercesXML::DOMNode getNextNode() /*throw ( ParsingError )*/;
		//
		// Liefert den n�chsten Node mit dem Elementnamen name bzw. dessen Elementname
		// in der Namensliste namen enthalten ist
		XercesXML::DOMNode getNextNodeByElementName() /*throw ( ParsingError )*/;
		XercesXML::DOMNode getNextNodeByElementName(const std::string& name, 
			EncodingType encoding) /*throw ( ParsingError )*/;
		XercesXML::DOMNode getNextNodeByElementName(const AppSuchNamen& namen,
			EncodingType encoding) /*throw ( ParsingError )*/;
		XercesXML::DOMNode getNextNodeByElementName(const std::string& name, 
			EncodingType encoding, const AppSuchLevels& levels) /*throw ( ParsingError )*/;
		XercesXML::DOMNode getNextNodeByElementName(const AppSuchNamen& namen, 
			EncodingType encoding, const AppSuchLevels& levels) /*throw ( ParsingError )*/;
		//
		// Liefert den n�chsten Node mit dem Attributnamen name bzw. dessen Attributname
		// in der Namensliste namen enthalten ist
		XercesXML::DOMNode getNextNodeByAttributeName(const std::string& name,
			EncodingType encoding) /*throw ( ParsingError )*/;
		XercesXML::DOMNode getNextNodeByAttributeName(const AppSuchNamen& namen,
			EncodingType encoding) /*throw ( ParsingError )*/;
		//
		// Liefert alle folgenden Nodes mit dem Elementnamen name bzw. dessen Elementname
		// in der Namensliste namen enthalten ist
		XercesXML::DOMNode getNodesByElementName(const std::string& name,
			EncodingType encoding) /*throw ( ParsingError )*/;
		XercesXML::DOMNode getNodesByElementName(const AppSuchNamen& namen,
			EncodingType encoding) /*throw ( ParsingError )*/;
		//
		// Liefert alle folgenden Nodes mit dem Attributnamen name bzw. dessen Attributname
		// in der Namensliste namen enthalten ist
		XercesXML::DOMNode getNodesByAttributeName(const std::string& name,
			EncodingType encoding) /*throw ( ParsingError )*/;
		XercesXML::DOMNode getNodesByAttributeName(const AppSuchNamen& namen,
			EncodingType encoding) /*throw ( ParsingError )*/;

	// -- Namensermittlung --
		// --- Auslese-Methoden f�r die Ermittlung von Klassennamen ---
		//
		// Liefert Klassenname und Attributwert des n�chsten Node bei dem der Attributname 
		// dem Wert von 'name' entspricht bzw. in der Namensliste 'namen' enthalten ist.
		// Parameter:
		//        OUT - 'klassenname' - der Name des Elements, zu dem das Attribut geh�rt
		//        OUT - 'wert'        - der Wert des Attributs
		//         IN - 'name'        - der Name des Attributs, das ber�cksichtigt werden soll
		//        (bzw.) 'namen' - Liste von Attributnamen, die ber�cksichtigt werden sollen
		//		   IN - 'encoding' - Encoding der Namen
		//
		// Ein R�ckgabewert TRUE zeigt an dass die Suche erfolgreich war.
		bool getAttributeContentByName(std::string& klassenname,
			std::string& wert, const std::string& name, EncodingType encoding) 
			/*throw ( ParsingError )*/;
		bool getAttributeContentByName(std::string& klassenname,
			std::string& wert, const AppSuchNamen& namen, EncodingType encoding)
			/*throw ( ParsingError )*/;

	// -- NodeFilter --
		// --- Auslese-Methoden die ein geteiltes Zugreifen auf Elements erlauben: ---
		//     o erst Ermitteln der Klasseninformationen
		//     o dann eins von
		//       - Einlesen des restlichen Inhalts mit DOMNode-Erzeugung
		//       - Verwerfen des restlichen Inhalts
		// 
		// Liefert die Klasseninformation eines FirstChildNode f�r ein beginnendes Element.
		// R�ckgabeparameter: der Name des beginnenden Elements
		//                    oder bei Misserfolg ein Leerstring
		//
		// Parameter:
		//    IN - 'suchName'		- Name des Elements, dessen ChildNode-Name ermittelt werden soll
		//         bzw. 'suchNamen' - Namen der Elemente, deren ChildNode-Namen ermittelt werden sollen
		//    IN - 'encoding' - Encoding der Namen
		//    IN - 'levels': Menge von Level, bei denen reagiert werden soll, d.h. in diesen
		//                       Level der XML-Datei kann eine interessierende Information stecken
		//          bei leerer levels: alle Level werden ber�cksichtigt
		//
		// Methode ohne Parameter:
		// Das n�chste Element mit den zuvor genutzten Suchparametern wird ermittelt.
		// Vorher ist also ein Aufruf der Methode mit Parametern notwendig!
		//
		// !!! Nach dieser Funktion muss entweder 'getCurrentNode' oder 'rejectCurrentNode' !!!
		// !!! aufgerufen werden um die Bearbeitung eines Elements abzuschlie�en            !!!
		std::string getFirstElementChildName() /*throw( ParsingError )*/;
		std::string getFirstElementChildName(const std::string& suchName, 
			EncodingType encoding, const AppSuchLevels& levels) /*throw( ParsingError )*/;
		std::string getFirstElementChildName(const AppSuchNamen& suchNamen, EncodingType encoding,
			const AppSuchLevels& levels) /*throw( ParsingError )*/;

		// Liefert die Klasseninformation des n�chsten beginnenden Elements.
		// R�ckgabeparameter: der Name des beginnenden Elements
		//                    oder bei Misserfolg ein Leerstring
		//
		// Parameter:
		//    IN - 'suchNamen' - Namen der Elemente, bei deren Namen gestoppt werden soll
		//    IN - 'encoding' - Encoding der namen
		//    IN - 'levels': Menge von Level, bei denen reagiert werden soll, d.h. in diesen
		//                       Level der XML-Datei kann eine interessierende Information stecken
		//          bei leerer levels: alle Level werden ber�cksichtigt
		//
		// Methode ohne Parameter:
		// Das n�chste Element mit den zuvor genutzten Suchparametern wird ermittelt.
		// Vorher ist also ein Aufruf der Methode mit Parametern notwendig!
		//
		// !!! Nach dieser Funktion muss entweder 'getCurrentNode' oder 'rejectCurrentNode' !!!
		// !!! aufgerufen werden um die Bearbeitung eines Elements abzuschlie�en            !!!
		std::string getNextElementName() /*throw( ParsingError )*/;
		std::string getNextElementName(std::string& elemUri) /*throw( ParsingError )*/;
		std::string getNextElementName(const AppSuchNamen& suchNamen, EncodingType encoding,
			const AppSuchLevels& levels) /*throw( ParsingError )*/;
		std::string getNextElementName(const AppSuchNamen& suchNamen, EncodingType encoding,
			const AppSuchLevels& levels, std::string& elemUri) /*throw( ParsingError )*/;
		std::string getNextElementName(const AppSuchNamenNS& suchNamen, EncodingType encoding,
			const AppSuchLevels& levels) /*throw( ParsingError )*/;
		std::string getNextElementName(const AppSuchNamenNS& suchNamen, EncodingType encoding,
			const AppSuchLevels& levels, std::string& elemUri) /*throw( ParsingError )*/;

		//
		// Liefert folgende Informationen zu angegebeben Attributbezeichnern:
		// - OUT - 'topName': Name des Vater-Elements
		// - OUT - 'elementName': Name des Elements, dass eine angegebene Attributinformation hat
		// - OUT - 'attName': Name des gefundenen Attributs
		// - OUT - 'attWert': Wert eines angegebenen Attributs
		//
		// - IN - 'namen': Liste von Attributnamen, auf die reagiert werden soll
		// - IN - 'encoding': Encoding der namen
		//   IN - 'levels': Menge von Level, bei denen reagiert werden soll, d.h. in diesen
		//                  Level der XML-Datei kann eine interessierende Information stecken
		//          bei leerer levels: alle Level werden ber�cksichtigt
		//
		// R�ckgabeparameter: true falls ein Element gefunden wurde, sonst false
		//
		// !!! Nach dieser Funktion muss entweder 'getCurrentNode' oder 'rejectCurrentNode' !!!
		// !!! aufgerufen werden um die Bearbeitung eines Elements abzuschlie�en            !!!
		bool getTopElementNameToAttribute(std::string& topName, std::string& elementName, 
			                             std::string& attName, std::string& attWert,
			                             const AppSuchNamen& namen, EncodingType encoding) 
										 /*throw (ParsingError)*/;
		bool getTopElementNameToAttribute(std::string& topName, std::string& elementName, 
			                             std::string& attName, std::string& attWert,
			                             const AppSuchNamen& namen, EncodingType encoding,
										 const AppSuchLevels& levels) /*throw (ParsingError)*/;

		// Liefert zu dem Rest des gefilterten Nodes 
		// (in 'getFirstElementChildName', ... genutzt)
		// den DOMNode und stoppt danach den Parse-Vorgang
		XercesXML::DOMNode getCurrentNode() /*throw( ParsingError )*/;

		// Liefert Namen des aktuellen Elements
		std::string getCurrentElementName(std::string& elemUri) const;

		// Liefert alle Attribute des aktuellen Elements; der Parser wird *nicht*
		// gestartet
		struct AttributeVal
			{ std::string uri; std::string name; std::string value; };
		typedef std::vector<AttributeVal> AttributesType;
		void getCurrentAttributeValues(AttributesType& result) const;

		//
		// Verwirft den Rest des gefilterten Nodes 
		// (in 'getFirstElementChildName', ... genutzt)
		// und stoppt danach den Parse-Vorgang
		void rejectCurrentNode() /*throw( ParsingError )*/;

	private:
		// f�r die friends 
		
		// f�r Handler-Objekte:
		// stoppt den aktuellen Parse-Vorgang (wenn er stopp-f�hig ist),
		// beendet ihn aber nicht - er kann also fortgesetzt werden
		void parseHalt();

		// Set-Methode (f�r ein Handler-Objekt) falls zu einem Attributnamen
		// der Wert und der Elementname gesucht werden.
		void setAttributeContent(const std::string& klassenname, const std::string& wert);
		
		// Set-Methode (f�r ein Handler-Objekt) falls ein Vaterelement-Name gesucht wird
		// ('getTopElementNameToAttribute'-Methode)
		void setAttributeContent(const std::string& vaterklassenname, const std::string& klassenname,
								const std::string& attributname, const std::string& attributwert);

		// Set-Methode (f�r ein Handler-Objekt) falls ein Element-Name gesucht wird
		// ('getFirstElementChildName'-Methode bzw. 'getNextElementName'-Methode)
		void setElementName(const std::string& uri, const std::string& klassenname);

		// (f�r ein Handler-Objekt)
		// zum Aufbau der Namespace-Informationen aus der XML-Datei
		void addNamespace(const std::string& pref, const std::string& uri);
		
	private:
		// private, damit die XML-Datei direkt bei Objekt-Erzeugung angegeben werden muss
		SAXReader();
		// �ndern der zu parsenden XML-Datei.
		// Dies darf nicht w�hrend eines laufenden Parse-Vorgangs geschehen, sonst Exception.
		void setXmlFile(const std::string& xmlFile) /*throw ( ParsingError )*/;
		void setXmlString(const std::string& xmlString, const std::string& xmlStringId) 
			/*throw ( ParsingError )*/;
		void setXmlSource(XercesXML::AbstractInputSource* pxmlSource) /*throw ( ParsingError )*/;

		// F�r - NodeFilter -:
		// Das Einlesen eines Elements wird abgeschlossen
		// Parameter: 
		// - func - Name der aufrufenden Funktion
		// - createNode - true -> Node wird erzeugt, sonst wird das Element verworfen
		void finalizeCurrentNode(const std::string& func, bool createNode) /*throw ( ParsingError )*/;

		void initialize() /*throw ( ParsingError )*/;
		void finalize();

		// Parser-Objekt initialisieren.
		// Wenn bereits initialisiert passiert nichts
		void initializeParser();
		void finalizeParser();

		// Handler-Objekt initialisieren mit Angabe eines konkreten Handlers.
		// Wenn bereits ein Handler initialisiert ist wird der bestehende Handler ersetzt.
		void initializeHandler(SAXCommonHandler* pHandler);
		void finalizeHandler();
		// �ndern des Handlers, der f�r das Parse-Verhalten zust�ndig ist.
		// Wenn bereits ein Handler initialisiert ist wird der bestehende Handler ersetzt.
		inline void setHandler(SAXCommonHandler* pHandler);

		// allgemeine Parse-Methoden - zu Test-Zwecken
		void parse() /*throw ( ParsingError )*/;
		void parse(SAXCommonHandler* pHandler);
	
		// zentrale getNode-Methoden
		XercesXML::DOMNode getOneNode() /*throw ( ParsingError )*/;
		XercesXML::DOMNode getOneNode(const Node_Such_Art& suchArt, 
			const AppSuchNamen* suchnamenListe = NULL, EncodingType encoding = lcp)
			/*throw ( ParsingError )*/;
		XercesXML::DOMNode getOneNode(const Node_Such_Art& suchArt,
			const AppSuchLevels& levels,
			const AppSuchNamen* suchnamenListe = NULL, EncodingType encoding = lcp) 
			/*throw ( ParsingError )*/;
		XercesXML::DOMNode getManyNodes(const Node_Such_Art& suchArt, 
			const AppSuchNamen& suchnamenListe, EncodingType encoding) 
			/*throw ( ParsingError )*/;

		// Steuerung des NodeReading
		void startNodeReading(const Node_Such_Art& suchArt) /*throw( ParsingError )*/;
		void changeNodeReading(const Node_Such_Art& suchArt) /*throw( ParsingError )*/;
		void stopNodeReading() /*throw( ParsingError )*/;

	private:
		SAXParseXML* m_pParser;
		HandlerFactory* m_pHandlerFactory;
		SAXCommonHandler* m_pHandler;
		std::string m_xmlResource; // Ist ein Filename, genau dann wenn m_xmlStringId leer ist.
		std::string m_xmlStringId;
		XercesXML::AbstractInputSource* m_pxmlSource;
		std::string m_strSchemaLocation;
		unsigned* m_puEntityExpansionLimit;

		XercesXMLErrorHandlerInterface* m_pErrHandler;

	// --- NodeReading ---
		bool m_nodeReadingIsInitialized;
		Node_Such_Art m_nodeSuchArt;

		NodeFactory* m_pNodeFactory;
		NodeFilter*  m_pNodeFilter;

		// zur Aufnahme von Werten, die Handler-Objekte ermittelt haben
		std::string m_attributVaterKlasse;
		std::string m_attributKlasse;
		std::string m_attributName;
		std::string m_attributWert;
		bool m_attWertFound;

		std::string m_elemUri;
		std::string m_elemName;

		LastFuncCall m_lastFuncCall;
		bool m_bZipped;

	};


}//namespace

#endif

