/*****************************************************************************
* $Id: XercesXMLErrorHandler.h 2012-10-08 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
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
* 2012-10-08 Gemeinsame Oberklasse f�r alle Objekte der Oklabi
* 
****************************************************************************/
// XercesXMLErrorHandler.h
// Weiterleitung von Fehlermeldungen des Xerces-Parsers

#include "OklabiPackaging.h"

#ifndef DEFXercesXMLErrorHandler
#define DEFXercesXMLErrorHandler

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "XercesXMLErrorHandlerInterface.h"
#include <string>

namespace Oklabi
{
	class OKLABI_API XercesXMLErrorHandler : public XercesXML::XercesXMLErrorHandlerInterface, public OklabiRoot
	{
	public:
		// Implementierungen der Interface-Methoden
		inline void warning( const std::string& msg ) { ausgabe( msg.c_str(), 1 ); };
		inline void error( const std::string& msg ) { ausgabe( msg.c_str(), 2 ); };
		inline void fatalError( const std::string& msg ) { ausgabe( msg.c_str(), 3 ); };

		void ausgabe( const char*, int loglevel );
	};
} // End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	 // DEFXercesXMLErrorHandler
