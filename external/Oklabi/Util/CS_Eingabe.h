/*****************************************************************************
* $Id: CS_Eingabe.h 2013-01-24 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt für Straßenwesen
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
* 2012-07-27 Interface umbenannt
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFCS_Eingabe
#define DEFCS_Eingabe

#include "OklabiUtil.h"
#include "OklabiManaged.h"
#include "OklabiKern.h"
#include "Eingabe.h"

namespace Oklabi
{
	typedef void (CALLBACK* pEingabeVoid)();
	typedef bool (CALLBACK* pEingabeBool)();
	typedef int (CALLBACK* pEingabeInt)();
	typedef void (CALLBACK* pEingabeKodierung)(eKodierung);
	class OKLABIUTIL_API CS_Eingabe : public Eingabe, public OklabiManaged
	{
	private:
		CS_Eingabe();
		~CS_Eingabe();
	public:
		static Eingabe*   Erzeuge();
		Text              GibKlassenname() const;
		Text              GibBeschreibung() const;
		void              Oeffne();
		void              Schliesse();
		int               LiesZeichen();
		size_t            GibAnzahl();
		size_t            GibZeilen();
		bool              IstBeendet();
		void              SetzeKodierung(eKodierung);
		bool              IstGueltig();
		void              ZumAnfang();

		pEingabeVoid      m_pCallbackOeffne;
		pEingabeVoid      m_pCallbackSchliesse;
		pEingabeInt       m_pCallbackLiesZeichen;
		pEingabeInt       m_pCallbackGibAnzahl;
		pEingabeBool      m_pCallbackIstBeendet;
		pEingabeBool      m_pCallbackIstGueltig;
		pEingabeVoid      m_pCallbackZumAnfang;
		pEingabeKodierung m_pCallbackSetzeKodierung;
	};
}// End of namespace Oklabi

#endif	// DEFCS_Eingabe
