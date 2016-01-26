/*****************************************************************************
* $Id: XercesXMLErrorHandlerInterface.h 2011-11-11 11:11:11 vogelsang $
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
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 
****************************************************************************/
// XercesXMLErrorHandlerInterface.h

//==============================================================================
//
// Fehlerbehandlungsinterface f�r XercesXML. Eine Implementierung kann den
// Default-ErrorHandler in XercesXML ersetzen 
// (siehe SetErrorHandler in XercesXML).
//
//==============================================================================

#ifndef XERCESXMLERRORHANDLERINTERFACE_H
#define XERCESXMLERRORHANDLERINTERFACE_H

#include <string>

namespace XercesXML
{
	// Fehlerbehandlungsinterface f�r XercesXML
	class XercesXMLErrorHandlerInterface
	{
	public:
		virtual void warning( const std::string& ) = 0;
		virtual void error( const std::string& ) = 0;
		virtual void fatalError( const std::string& ) = 0;
	};
}

#endif
