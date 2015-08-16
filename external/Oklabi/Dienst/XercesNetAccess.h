/*****************************************************************************
* $Id: XercesNetAccess.h 2011-11-11 11:11:11 vogelsang $
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
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 
****************************************************************************/
// XercesNetAccess.h

//==============================================================================
//
// Dieser File bildet einen vereinfachten Wrapper um den Xerces-Netzzugriff. 
// Der Zweck ist, die zukünftigen Veränderungen am Xerces von der nutzenden
// Software zu trennen.
//
// This product includes software developed by the Apache Software Foundation
// (http://www.apache.org).
//
//==============================================================================

#ifndef XERCESNETACCESS_H
#define XERCESNETACCESS_H

#include <string>
#include "XercesXML.h"

namespace XERCESCNAMESPACE
{
	// Forwards
	class URLInputSource;
}

namespace XercesXML
{

	//--------------------------------------------------------------------------

	class GetError : public Exception
	{
	public:
		// Ctor
		inline GetError( const std::string& msg ) //throw()
			: Exception( msg, "GetError" ) {};
	};

	class MalformedUrl : public Exception
	{
	public:
		// Ctor
		inline MalformedUrl( const std::string& msg ) //throw()
			: Exception( msg, "MalformedUrl" ) {};
	};

	class SafetyException : public Exception
	{
	public:
		// Ctor
		inline SafetyException( const std::string& msg ) //throw()
			: Exception( msg, "SafetyException" ) {};
	};

	//--------------------------------------------------------------------------

	class HttpAccess
	{
	public:
		// Default Ctor
		HttpAccess() /*throw( NotInitialized )*/;

		// Ctor mit Angabe einer URL auf die
		// zu verwendende XSD
		HttpAccess( const char* pszURL ) /*throw( NotInitialized )*/;

		// Dtor
		virtual ~HttpAccess() /*throw()*/;

		// Die Url setzen
		virtual void setUrl( const char* pszURL ) /*throw()*/;

		// Die Url aus den Parametern konstruieren
		virtual void setUrl( const char* pszAgent, const char* pszUrl, const char* pszUser,
			const char* pszPass, const char* pszRequest, bool bIsGet = true ) /*throw( MalformedUrl )*/;

	protected:
		// Zeiger auf das Xerces-UrlInputSource-Objekt
		XERCESCNAMESPACE::URLInputSource* m_pUrl;

		// Die Url
		std::string m_strUrl;

		// Einen File downloaden
		// REENTRANT
		std::string getFile(size_t maxBytes, const std::string& file, bool bIsGet = true, const std::string& strPayload = "") 
			/*throw( GetError )*/;
	};

	//--------------------------------------------------------------------------

	class HttpGet : public HttpAccess
	{
	public:
		// Default Ctor
		HttpGet() /*throw( NotInitialized )*/;

		// Ctor mit Angabe einer URL auf die
		// zu verwendende XSD
		HttpGet( const char* pszURL ) /*throw( NotInitialized )*/;

		// Dtor
		~HttpGet() /*throw()*/;

		// Einen File downloaden
		// REENTRANT
		std::string getFile(size_t maxBytes, const std::string& file = "") 
			/*throw( GetError )*/;
	};

	//--------------------------------------------------------------------------

	class HttpPost : public HttpAccess
	{
	public:
		// Default Ctor
		HttpPost() /*throw( NotInitialized )*/;

		// Ctor mit Angabe einer URL auf die
		// zu verwendende XSD
		HttpPost( const char* pszURL ) /*throw( NotInitialized )*/;

		// Dtor
		~HttpPost() /*throw()*/;

		// Die Payload setzen
		void setPayload( const char* pszPayload ) /*throw()*/;

		// Die Url aus den Parametern konstruieren
		void setUrl( const char* pszAgent, const char* pszUrl, const char* pszUser,
			const char* pszPass, const char* pszRequest ) /*throw( MalformedUrl )*/;

		// Einen File downloaden
		// REENTRANT
		std::string getFile(size_t maxBytes, const std::string& file = "") 
			/*throw( GetError )*/;

	private:
		// Die Payload
		std::string m_strPayload;
	};
}

#endif
