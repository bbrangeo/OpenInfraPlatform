/*****************************************************************************
* $Id: TextpufferProtokollant.h 2012-10-01 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt für Straßenwesen
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
* 2012-10-01 Protokollant nutzt Ausgabe
* 
****************************************************************************/
#ifndef DEFTextpufferProtokollant
#define DEFTextpufferProtokollant

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "Protokollant.h"
#include "TextpufferAusgabe.h"

namespace Oklabi
{
	class TextpufferProtokollant : public Protokollant
	{
	private:
		Ausgabe*	                        m_pOut;
		bool		                        m_bOpen;

		TextpufferProtokollant();
		~TextpufferProtokollant();
		void OKLABIUTIL_API                 Austragen(OklabiObjekt*);

	public:
		static OKLABIUTIL_API Protokollant* Erzeuge(Ausgabe* da);

		void OKLABIUTIL_API                 Melde(int, const Text&, eMeldTyp);
		Text OKLABIUTIL_API                 GibKlassenname() const;
	};
}// End of namespace Oklabi

#endif	// DEFTextpufferProtokollant
