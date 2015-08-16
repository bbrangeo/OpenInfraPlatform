/*****************************************************************************
* $Id: OklabiMixed.h 2011-10-31 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
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
* 2011-10-31 Cross Language Calls
* 
****************************************************************************/
#ifndef DEFOklabiMixed
#define DEFOklabiMixed

#include <map>
#include <string>
#include "OklabiUtil.h"

namespace Oklabi
{
	class OklabiMixed : public OklabiUtil
	{
	public:
		OKLABIUTIL_API OklabiMixed* GibClient() const;
		OKLABIUTIL_API OklabiMixed* GibHost() const;
		OKLABIUTIL_API void SetzeClient(OklabiMixed*);
	protected:
		OKLABIUTIL_API OklabiMixed();
		virtual OKLABIUTIL_API ~OklabiMixed();

		OklabiMixed* m_pClient;
		OklabiMixed* m_pHost;
	private:
		OKLABIUTIL_API void Befreie();
	};
}// namespace Oklabi
#endif // DEFOklabiMixed
