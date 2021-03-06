/*****************************************************************************
* $Id: OklabiManaged.h 2011-10-31 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2011, Bundesanstalt f�r Stra�enwesen
*
* Erstellt durch interactive instruments GmbH, Bonn
*
* Die Nutzungsbestimmungen f�r die Software und die zugeh�rigen Bestandteile
* sind unter folgender Adresse einsehbar:
*    http://www.okstra.de/oklabi/Lizenz/Nutzung.txt
* 
* Der Hinweis auf das Copyright und die Lizenzbestimmungen ist in allen
* Kopien der Software oder wesentlichen Bestandteilen daraus aufzunehmen.
*
* Die Erkl�rungen zum Gew�hrleistungsausschlu� und zur Haftungsbegrenzung 
* befinden sich bei den Nutzungsbestimmungen.
* 
* 2011-10-31 Cross Language Calls
* 
****************************************************************************/
#ifndef DEFOklabiManaged
#define DEFOklabiManaged

#include <map>
#include <string>
#include "OklabiUtil.h"
#include "OklabiMixed.h"

namespace Oklabi
{
	class OklabiManaged : public OklabiMixed
	{
	public:
	protected:
		OKLABIUTIL_API OklabiManaged();
		virtual OKLABIUTIL_API ~OklabiManaged();
	};
}// namespace Oklabi
#endif // DEFOklabiManaged
