/*****************************************************************************
* $Id: msgdef 2010-04-30 15:00:00 vogelsang $
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

//==============================================================================
//
// Message Handling Subsystem - msg
// 
// Internal Interface Declarations
//
//==============================================================================

#ifndef MSGDEF_H
#define MSGDEF_H

namespace msg
{
	// Forwards
	class MessageHandler;
	class MessageExists;

	// Message Table Element

	struct MTE
	{
		MTE*	m_pMTE;				// The rehash link
		short	m_sevty;			// Severity
		short	m_lang;				// Language
		const char*	m_pNS;			// The namespace
		const char* m_pId;			// The identifier
		const char*	m_pTxt;			// The message text
		mutable unsigned int m_nHash; // The Hash Value

		// Ctor
		$IFMSG MTE( short sev, short lng, 
			const char* pNS, const char* pId, const char* pTxt,
			MessageHandler* pMH=0, bool noOverwrite=true ) /*throw (MessageExists)*/;

		// Dtor
		$IFMSG ~MTE();

	};
}

#endif
