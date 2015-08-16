/*****************************************************************************
* $Id: XGml.h 2010-04-30 15:00:00 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010, Bundesanstalt für Straßenwesen
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
* 
****************************************************************************/
// XGml.h

/*
	In XGml werden Service-Funktionalitäten für den Umgang
	mit GML implementiert.

	Es werden die Pakete ??? und XercesXML verwendet.
*/

#ifndef DEFXGML
#define DEFXGML

#include "XGmlPackaging.h"

#include "XercesXML.h"

#include <string>

namespace XGml
{
	class ErrorInGmlElement : public XercesXML::Exception
	{
	public:
		// Ctor
		inline ErrorInGmlElement( std::string msg ) //throw()
			: Exception( msg, "ErrorInGmlElement" ) {};
	};

	class GmlNotImplemented : public XercesXML::Exception
	{
	public:
		// Ctor
		inline GmlNotImplemented( std::string msg ) //throw()
			: Exception( msg, "GmlNotImplemented" ) {};
	};

	// Die Klasse Transform stellt Methoden zur Verfügung,
	// um GML in Geo-Objekte zu transformieren und umgekehrt.
	class Transform
	{
	public:
		Transform();
		~Transform();

		void			getCoordinates( const XercesXML::DOMNode& dn, size_t dim, size_t minOcc, size_t maxOcc, std::vector<double>& coord )
							/*throw ( ErrorInGmlElement, XercesXML::NullPointer, XercesXML::NavigationError )*/;
		void			getSrs( const XercesXML::DOMNode& dn, std::string& srs ) const
							/*throw ( XercesXML::NullPointer, XercesXML::NavigationError )*/;
	};

}

#endif
