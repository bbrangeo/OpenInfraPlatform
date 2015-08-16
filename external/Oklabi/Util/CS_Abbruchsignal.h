/*****************************************************************************
* $Id: CS_Abbruchsignal.h 2011-10-31 15:00:00 vogelsang $
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
* 2011-05-03 Formale Verbesserungen
* 2011-10-31 Cross Language Calls
* 
****************************************************************************/
#ifndef DEFCS_Abbruchsignal
#define DEFCS_Abbruchsignal

#include "OklabiUtil.h"
#include "OklabiManaged.h"
#include "OklabiKern.h"
#include "Abbruchsignal.h"

namespace Oklabi
{
	typedef bool (CALLBACK* pAbbruchsignal)();
	class OKLABIUTIL_API CS_Abbruchsignal : public Abbruchsignal, public OklabiManaged
	{
	private:
		CS_Abbruchsignal();
		~CS_Abbruchsignal();
	public:
		static Abbruchsignal* Erzeuge();

		bool Empfange();
		Text GibKlassenname() const;
		pAbbruchsignal m_pCallback;
	};
}// End of namespace Oklabi
#endif // DEFCS_Abbruchsignal
