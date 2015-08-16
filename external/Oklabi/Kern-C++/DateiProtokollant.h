/*****************************************************************************
* $Id: DateiProtokollant.h 2012-10-01 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
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
#ifndef DEFDateiProtokollant
#define DEFDateiProtokollant

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "Protokollant.h"
#include "DateiAusgabe.h"

namespace Oklabi
{
	class DateiProtokollant : public Protokollant
	{
	private:
		Ausgabe*                        m_pOut;
		bool                            m_bOpen;
		bool                            m_bActive;

		DateiProtokollant();
		~DateiProtokollant();
		void OKLABI_API                 Austragen(OklabiObjekt*);

	public:
		static OKLABI_API Protokollant* Erzeuge(Ausgabe* da);

		void OKLABI_API                 Melde(int, const Text&, eMeldTyp);
		Text OKLABI_API                 GibKlassenname() const;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DateiProtokollant
