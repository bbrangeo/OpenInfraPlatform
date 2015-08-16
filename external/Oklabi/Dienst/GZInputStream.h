/*****************************************************************************
* $Id: GZInputStream.h 2011-11-11 11:11:11 vogelsang $
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
* 2010-11-24 Komprimierte XML-Dateien lesen
* 2011-11-11 Umstellung auf Xerces-C-3.1.1
* 
****************************************************************************/
#ifndef GZInputStream_H
#define GZInputStream_H

#include "XercesXML.h"
#include "GZInputFileStream.h"
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/BinFileInputStream.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <string>

namespace XercesXML
{
	class GZInputStream : public XERCESCNAMESPACE::BinInputStream
	{
	public:
		GZInputStream(const std::string&);
   		GZInputStream(const char* const);
   		virtual ~GZInputStream();

  		bool getIsOpen() const;
		virtual XMLFilePos curPos() const;
		virtual XMLSize_t readBytes(XMLByte* const, const XMLSize_t);
		virtual const XMLCh* getContentType() const;
   		
    private:
    	GZInputFileStream* m_pStream;
		unsigned int m_nPos;
    	
    	GZInputStream();
    	GZInputStream(const GZInputStream&);
    	GZInputStream& operator=(const GZInputStream&);
	};
} // namespace XercesXML

#endif // GZInputStream_H
