/*****************************************************************************
* $Id: CS_Protokollant.h 2011-10-31 15:00:00 vogelsang $
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
#ifndef DEFCS_Protokollant
#define DEFCS_Protokollant

#include "OklabiUtil.h"
#include "OklabiManaged.h"
#include "OklabiKern.h"
#include "Protokollant.h"

namespace Oklabi
{
	typedef void (CALLBACK* pProtokollant)(int mnr, const Oklabi::Text& text, Oklabi::eMeldTyp typ);
	class OKLABIUTIL_API CS_Protokollant : public Protokollant, public OklabiManaged
	{
	private:
		Ausgabe*	m_pOut;
		bool		m_bOpen;

		CS_Protokollant();
		~CS_Protokollant();

	public:
		static Protokollant* Erzeuge(Ausgabe* da);

		void Melde(int, const Text&, eMeldTyp);
		Text GibKlassenname() const;
		pProtokollant m_pCallback;
	};
}// End of namespace Oklabi

#endif	// DEFCS_Protokollant
