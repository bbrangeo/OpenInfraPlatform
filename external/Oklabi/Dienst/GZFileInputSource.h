/*****************************************************************************
* $Id: GZFileInputSource.h 2011-11-11 11:11:11 vogelsang $
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
#ifndef GZFileInputSource_H
#define GZFileInputSource_H

#include <xercesc/framework/LocalFileInputSource.hpp>
#include <xercesc/sax/InputSource.hpp>
#include "XercesXML.h"

using namespace XERCESCNAMESPACE;

//class BinInputStream;

namespace XercesXML
{
	class GZFileInputSource : public LocalFileInputSource
	{
	public:
		GZFileInputSource
		(
			const   XMLCh* const   basePath
			, const XMLCh* const   relativePath
		);
		GZFileInputSource
		(
			const   XMLCh* const   filePath
		);

		~GZFileInputSource();
		virtual BinInputStream* makeStream() const;

	private:
		GZFileInputSource(const GZFileInputSource&);
		GZFileInputSource& operator=(const GZFileInputSource&);
	};
} // namespace XercesXML
#endif // GZFileInputSource_H
