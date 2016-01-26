/*****************************************************************************
* $Id: XercesXMLErrorHandlerInterface.h 2011-11-11 11:11:11 vogelsang $
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
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 
****************************************************************************/
// XercesXMLErrorHandlerInterface.h

//==============================================================================
//
// Fehlerbehandlungsinterface für XercesXML. Eine Implementierung kann den
// Default-ErrorHandler in XercesXML ersetzen 
// (siehe SetErrorHandler in XercesXML).
//
//==============================================================================

#ifndef XERCESXMLERRORHANDLERINTERFACE_H
#define XERCESXMLERRORHANDLERINTERFACE_H

#include <string>

namespace XercesXML
{
	// Fehlerbehandlungsinterface für XercesXML
	class XercesXMLErrorHandlerInterface
	{
	public:
		virtual void warning( const std::string& ) = 0;
		virtual void error( const std::string& ) = 0;
		virtual void fatalError( const std::string& ) = 0;
	};
}

#endif
