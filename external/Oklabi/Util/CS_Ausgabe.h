/*****************************************************************************
* $Id: CS_Ausgabe.h 2013-01-24 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt f�r Stra�enwesen
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
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFCS_Ausgabe
#define DEFCS_Ausgabe

#include "OklabiUtil.h"
#include "OklabiManaged.h"
#include "OklabiKern.h"
#include "Ausgabe.h"

namespace Oklabi
{
	typedef void (CALLBACK* pAusgabeVoid)();
	typedef void (CALLBACK* pAusgabeInt)(const int&);
	typedef void (CALLBACK* pAusgabeKodierung)(eKodierung);
	class OKLABIUTIL_API CS_Ausgabe : public Ausgabe, public OklabiManaged
	{
	private:
		CS_Ausgabe();
		~CS_Ausgabe();
	public:
		static Ausgabe*   Erzeuge();
		Text              GibKlassenname() const;
		Text              GibBeschreibung() const;
		void              Oeffne();
		void              Schliesse();
		void              SchreibeZeichen(const int&);
		void              SchreibeZeile(const Text&);
		void              SetzeKodierung(eKodierung);
		void              Leere();

		pAusgabeVoid      m_pCallbackOeffne;
		pAusgabeVoid      m_pCallbackSchliesse;
		pAusgabeInt       m_pCallbackSchreibeZeichen;
		pAusgabeVoid      m_pCallbackLeere;
		pAusgabeKodierung m_pCallbackSetzeKodierung;
	};
}// End of namespace Oklabi

#endif	// DEFCS_Ausgabe
