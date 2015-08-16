/*****************************************************************************
* $Id: AbstractInputSource.h 2012-07-27 15:57:11 vogelsang $
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
#ifndef AbstractInputSource_H
#define AbstractInputSource_H

#include "XercesXML.h"

using namespace XERCESCNAMESPACE;

namespace XercesXML
{
	class AbstractInputSource
	{
	public:
		AbstractInputSource();
		~AbstractInputSource();

  		virtual bool reachedEOF() const = 0;
  		virtual bool getIsOpen() const = 0;
		virtual int readInt() const = 0;
		virtual void rewind() const = 0;
	};
} // namespace XercesXML
#endif // AbstractInputSource_H
