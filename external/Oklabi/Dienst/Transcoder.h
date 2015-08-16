/*****************************************************************************
* $Id: Transcoder.h 2011-11-11 11:11:11 vogelsang $
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
// Transcoder.h
//
// Wrapper für XMLTranscoder
//
//
// 14.01.2010  MF - Datei erzeugt


#ifndef XERCESTranscoder_h
#define XERCESTranscoder_h

#include <xercesc/util/TransService.hpp>

#include <string>

namespace XercesXML
{
	class Transcoder
	{
	public:
		Transcoder()
			: t1(NULL), t2(NULL), m_inputIsLCP(false), m_approxScale(1) {};
		~Transcoder();

		bool transcode(const std::string&, std::string&) const;
		std::string transcode(const std::string&) const;

		// Schätz(!)wert, wie stark sich die Länge des Outputs von
		// der des Inputs unterscheiden wird.
		unsigned estimateOutputLength(unsigned inputLength) const;

	private:
	
		// Zum Wechsel des Encodings brauchen wir 2 Transcoder
		// InputEncoding -> Unicode -> OutputEncoding.
		XERCES_CPP_NAMESPACE::XMLTranscoder* t1;
		XERCES_CPP_NAMESPACE::XMLTranscoder* t2;
		
		// Flag, ob fehlender t1 für 'Input = LCP' steht
		// (t1 (sowie t2) fehlt auch, falls wir einen UTF8<->UTF8-Transcoder
		// haben.)
		bool m_inputIsLCP;

		double m_approxScale;

		friend Transcoder* makeTranscoderForUTF8(const std::string&);
		friend Transcoder* makeTranscoder(const std::string&,
			const std::string&);
		friend Transcoder* makeTranscoderFromLCP(const std::string&);
	};
	
	// Auf UTF-8 prüfen (normalisieren)
	bool isUTF8(std::string encoding);
	// Grobe Schätzung, wieviele Bytes ein Character
	// in einer bestimmten Codierung hat
	double BytesPerChar(std::string encoding);

	// UTF8-Transcoder erzeugen (UTF8 -> to )
	Transcoder* makeTranscoderForUTF8(const std::string& to);

	// Beliebigen Transcoder erzeugen
	Transcoder* makeTranscoder(const std::string& from,	const std::string& to);

	// Transcoder von LCP zu beliebigem Code
	Transcoder* makeTranscoderFromLCP(const std::string& to);
};

#endif
