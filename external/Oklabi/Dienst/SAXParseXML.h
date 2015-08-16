/*****************************************************************************
* $Id: SAXParseXML.h 2012-07-27 15:57:11 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt für Straßenwesen
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
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 2012-07-27 InputSource verallgemeinert
* 
****************************************************************************/
/* SAXParseXML.h
*
* Parsen einer XML-Datei - konfigurierbar
*
*
* 22.04.2004  SO - geänderte String-Behandlung, Eingabedatei als InputSource
* 14.01.2004  SO - Datei erzeugt
*/

#ifndef SAXParseXML_h
#define SAXParseXML_h


#include <string>
#include <iostream>

#include "XercesXML.h"
#include "InputSource.h"

// Xerces-Klassen
namespace XERCESCNAMESPACE
{
	// forwards
	class SAX2XMLReader;
	class SecurityManager;
	class XMLPScanToken;
}

namespace XercesXML
{
	// forwards
	class SAXCommonHandler;
	class SAXReader;

	// ***************************************************************************
	//                                 SAXParseXML
	// ***************************************************************************
	// Die eigentliche Parse-Klasse die mit Hilfe eines Xerces-SAX-Parsers eine
	// übergebene XML-Datei parsen kann.
	// Die Klasse ist konfigurierbar so dass sowohl eine Validierung als auch
	// eine inhaltliche Analyse der Datei statt finden kann.
	// Das exakte Verhalten hängt spziell ab von dem übergebenem Handler-Objekt!
	// Erzeugt und aufgerufen wird diese Klasse nur von einem SAXReader-Objekt 
	// - daher sind alle Methoden private und SAXReader als friend deklariert.
	//
	// Es gibt zwei Möglichkeiten, einen Parse-Vorgang durchführen zu lassen:
	// 1. Methode 'parse'
	//    Der Parse-Vorgang liest in einem Durchlauf die komplette XML-Datei.
	// 2. Methoden 'parseStart', 'parseContinue', 'parseHalt', 'parseStop'
	//    Der Parse-Vorgang läuft schrittweise ab. Ein SAXReader-Objekt kann das
	//    Parsen starten, anhalten, wieder fortsetzen, und komplett beenden.
	//    Dabei kann durch ändern des Handler-Objektes zwischendurch ein anderes 
	//    Parse-Verhalten erreicht werden.
	//
	class SAXParseXML
	{
		friend class SAXReader;

	private:
		SAXParseXML() /*throw( NotInitialized )*/;
		~SAXParseXML();

	// Zentrale Parse-Methode für einen Parse-Vorgang 'in einem Rutsch'
	// Diese Methode wird auf jeden Fall für eine Validierung genutzt.
		//
		// IN:
		// handler - das allumfassende Handler-Objekt (Content- und Error-Handler)
		// xmlFile - Name der zu erforschenden XML-Datei
		// schemaLoc - Name eines externen Schemas (Namespace + <leer> + XSD-Datei)
		bool parseFile(SAXCommonHandler* pHandler, const std::string& xmlFile,
			const std::string& schemaLoc = "", bool bZipped = false) /*throw( ParsingError )*/;
		// Das gleiche für AbstractInputSource.
		//
		// IN:
		// handler - das allumfassende Handler-Objekt (Content- und Error-Handler)
		// xmlFile - Name der zu erforschenden XML-Datei
		// schemaLoc - Name eines externen Schemas (Namespace + <leer> + XSD-Datei)
		bool parseFile(SAXCommonHandler* pHandler, AbstractInputSource* pxmlInput,
			const std::string& schemaLoc = "") /*throw( ParsingError )*/;
		// Das gleiche für Buffer.
		// 
		// IN:
		// handler - das allumfassende Handler-Objekt (Content- und Error-Handler)
		// xmlString - der zu erforschende XML-String
		// bufferId - beliebige Id für den Buffer
		// schemaLoc - Name eines externen Schemas (Namespace + <leer> + XSD-Datei)
		bool parseString(SAXCommonHandler* pHandler, const std::string& xmlString,
			const std::string& xmlStringId, const std::string& schemaLoc="") 
			/*throw( ParsingError )*/;



	// Parse-Methoden um eine XML-Datei häppchenweise zu parsen ('ProgressiveScan').
	// Dieser Vorgang kann von außen beeinflusst werden durch den Aufruf
	// der entsprechenden Methoden:

		// parseStart:
		// Startet einen neuen Parse-Vorgang. Dabei wird noch keine verwertbare Information
		// erzeugt (das eigentliche Parsen kommt später).
		// Sollte ein laufender Parsing-Prozess existieren wird eine Exception erzeugt.
		bool parseStart(SAXCommonHandler* pHandler, const std::string& xmlFile, bool bZipped = false)
			/*throw( ParsingError )*/;
		bool parseStart(SAXCommonHandler* pHandler, const std::string& xmlString, 
			const std::string& xmlStringId) /*throw( ParsingError )*/;
		bool parseStart(SAXCommonHandler* pHandler, XercesXML::AbstractInputSource* pxmlSource) /*throw( ParsingError )*/;
		//
		// parseContinue:
		// Setzt einen begonnenen Parse-Vorgang fort.
		// Der Parse-Vorgang läuft so lange bis die XML-Datei komplett gelesen wurde,
		// oder bis zum zwischenzeitlichen Aufruf der Kommandos parseHalt oder parseStop.
		//
		// Durch Angabe eines Handler-Objektes wird dieses als neuer Handler
		// für den weiteren Parse-Vorgang festgelegt - fehlt eine solche Angabe
		// wird mit dem bisher genutztem Handler weiter geparst.
		bool parseContinue(SAXCommonHandler* pHandler = 0) /*throw( ParsingError )*/;
		//
		// parseHalt:
		// Sorgt für das Anhalten eines laufenden Parse-Vorgangs.
		// Der Vorgang kann anschließend mit parseContinue fortgesetzt werden.
		void parseHalt();
		//
		// parseStop:
		// Beendet einen laufenden Parse-Vorgang. Endgültig!
		void parseStop();

	// weitere Methoden:

		// Löscht den Xerces-Parser
		void finalizeParser();

		// Beendet das bestehende ProgressiveToken
		void finalizeToken();

		// Setzt die Umgebung für einen Parse-Vorgang
		bool initParsing(SAXCommonHandler* handler, const std::string& schemaLoc = "") /*throw( ParsingError )*/;

		void setSchemaLocation(const std::string& schemaLocation){ m_strSchemaLocation = schemaLocation; };

		void setEntityExpansionLimit(unsigned limit);
		void deactivateEntityExpansionLimit();

	private:
		bool m_contParse;   // wird auf false gesetzt um einen laufenden Parse-Vorgang anzuhalten
		xercesc::SAX2XMLReader* m_pXercesParser; // der Xerces-SAX-Parser
		
		xercesc::SecurityManager* m_pSecurity; // SecurityManager; regelt bislang nur das
			// EntityExpansionLimit. D.h. der SecurityManager ist genau dann da, wenn so ein Limit verwendet wird.

		xercesc::XMLPScanToken* m_pToken;    // Xerces-Token für einen ProgressiveScan - muss 
		                                     // für einen Parse-Vorgang immer das Gleiche sein!
		xercesc::InputSource* m_pInpSrc; // die Quelle (XML-Datei)

		SAXCommonHandler* m_pHandler;

		std::string m_strSchemaLocation;
	};

}//namespace

#endif

