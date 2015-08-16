/*****************************************************************************
* $Id: InputSource.h 2012-07-27 15:57:11 vogelsang $
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
#ifndef InputSource_H
#define InputSource_H

#include <xercesc/sax/InputSource.hpp>
#include "XercesXML.h"
#include "AbstractInputSource.h"

using namespace XERCESCNAMESPACE;

namespace XercesXML
{
	class InputSource : public XERCESCNAMESPACE::InputSource
	{
	public:
		InputSource(AbstractInputSource*);
		~InputSource();
		virtual BinInputStream* makeStream() const;

	protected:
		InputSource(const InputSource&);
		InputSource& operator=(const InputSource&);
		AbstractInputSource* m_pHostedObject;
	};
} // namespace XercesXML
#endif // InputSource_H
