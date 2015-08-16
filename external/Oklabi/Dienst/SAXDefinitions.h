/*****************************************************************************
* $Id: SAXDefinitions.h 2011-11-11 11:11:11 vogelsang $
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
//
// Definitionen für die String-Konvertierung zwischen Xerces und std::string bzw. char*
//
//
// 22.04.2004  SO - Ergänzung um weitere Xerces-String-Behandlung
// 14.01.2004  SO - Datei erzeugt


#ifndef SAXDefinitions_h
#define SAXDefinitions_h

#include "XercesXML.h"
// (Holt die Definition von XERCESCNAMESPACE)
#include <xercesc/util/TransService.hpp>

// die (einzige ?) Möglichkeit, an die Definition des 'XMLCh' zu kommen,
// damit diese bereits hier verwendet werden können:
// (die exakte Definition befindet sich unter xercesc\util\Compilers)
#include <xercesc/util/XMLString.hpp>
// Alternativ:
// Nach der gültigen Definition funktioniert auch
// typedef unsigned short XMLCh;
// (entliehen aus MVSCPPDefs.hpp)


#include <string>

// Forwards
namespace XERCESCNAMESPACE
{
	class XMLTranscoder;
};

namespace XercesXML
{
	class XercesString
	{
		XMLCh *_wstr;
	public:
		XercesString() : _wstr(0L) { };
		XercesString(const char *str);
		XercesString(XMLCh *wstr);
		XercesString(const XMLCh *wstr);
		XercesString(const XercesString &copy);
		~XercesString();
		bool append(const XMLCh *tail);
		bool erase(const XMLCh *head, const XMLCh *tail);
		const XMLCh* begin() const;
		const XMLCh* end() const;
		XMLSize_t size() const;
		XMLCh & operator [] (const int i);
		const XMLCh operator [] (const int i) const;
		operator const XMLCh * () const { return _wstr; };
	};




	// sinnvolle Definition in Dateien, die die Klasse 'XStr' verwenden:
	// #define X(str) XStr(str).unicodeForm()

	// Aus einem Xerces-Beispiel geliehen:
	// ---------------------------------------------------------------------------
	//  This is a simple class that lets us do easy (though not terribly efficient)
	//  trancoding of char* data to XMLCh data.
	// ---------------------------------------------------------------------------
	class XStr
	{
	public :
		// -----------------------------------------------------------------------
		//  Constructors and Destructor
		// -----------------------------------------------------------------------
		XStr(const char* toTranscode);

		~XStr();


		// -----------------------------------------------------------------------
		//  Getter methods
		// -----------------------------------------------------------------------
		const XMLCh* unicodeForm() const;

	private :
		// -----------------------------------------------------------------------
		//  Private data members
		//
		//  fUnicodeForm
		//      This is the Unicode XMLCh format of the string.
		// -----------------------------------------------------------------------
		XMLCh*   fUnicodeForm;
	};


		
	// Freie Funktion: ASCII-String aus Xerces 2-Byte Code
	// (entnommen und hierher verschoben aus XercesXML.cpp)
	// Transcodiert jetzt nach UTF-8
	std::string transcodeFromXMLCh( const XMLCh* ch );

	// Wrapper für den internen, statischen UTF8-Transcoder
	class UTF8Transcoder
	{
	public:
		// transcodeTo: Unicode -> UTF-8
		static XMLSize_t transcodeTo(const XMLCh* const srcData, 
			const XMLSize_t srcCount, XMLByte* const toFill, 
			const XMLSize_t maxBytes, XMLSize_t& charsEaten, 
			const XERCESCNAMESPACE::XMLTranscoder::UnRepOpts options);

		// transcodeFrom: UTF-8 -> Unicode
		static XMLSize_t transcodeFrom(const XMLByte* const srcData,
			const XMLSize_t srcCount, XMLCh* const toFill, 
			const XMLSize_t maxChars, XMLSize_t& bytesEaten, 
			unsigned char* const charSizes);

		// Transcoder initialisieren/finalisieren
		static void initialize();
		static void finalize();

	private:
		// Der Transcoder
		static XERCESCNAMESPACE::XMLTranscoder* pUTF8Transcoder;
	};

} // namespace

#endif
