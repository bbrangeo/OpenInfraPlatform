/*****************************************************************************
* $Id: InputStream.h 2012-07-27 15:57:11 vogelsang $
* $Paket: Oklabi-Dienst $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ Service-Routinen
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2012, Bundesanstalt für Straßenwesen
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
* 2012-07-27 InputSource verallgemeinert
* 
****************************************************************************/
#ifndef InputStream_H
#define InputStream_H

#include "XercesXML.h"
#include "InputSource.h"
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/BinInputStream.hpp>

namespace XercesXML
{
	class InputStream : public XERCESCNAMESPACE::BinInputStream
	{
	public:
		InputStream(AbstractInputSource*);
   		virtual ~InputStream();

  		bool getIsOpen() const;
		virtual XMLFilePos curPos() const;
		virtual XMLSize_t readBytes(XMLByte* const, const XMLSize_t);
		virtual const XMLCh* getContentType() const;
   		
    private:
    	InputStream();
    	InputStream(const InputStream&);
    	InputStream& operator=(const InputStream&);
		AbstractInputSource* m_pSource;
		size_t m_nPos;
	};
} // namespace XercesXML

#endif // InputStream_H
