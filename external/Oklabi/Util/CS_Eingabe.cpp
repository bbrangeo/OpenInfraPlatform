/*****************************************************************************
* $Id: CS_Eingabe.cpp 2013-01-24 15:00:00 vogelsang $
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
* 2010-07-19 Aufrufkonventionen bei Callback-Funktionen fehlerhaft
* 2012-07-27 Interface umbenannt
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "CS_Eingabe.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

CS_Eingabe::CS_Eingabe() : m_pCallbackOeffne(0), m_pCallbackSchliesse(0), m_pCallbackLiesZeichen(0),
	m_pCallbackGibAnzahl(0), m_pCallbackIstBeendet(0), m_pCallbackIstGueltig(0), m_pCallbackZumAnfang(0)
{
}

CS_Eingabe::~CS_Eingabe()
{
}

Text CS_Eingabe::GibKlassenname() const
{
	return "CS_Eingabe";
}

Text CS_Eingabe::GibBeschreibung() const
{
	return "CS_Eingabe";
}

Eingabe* CS_Eingabe::Erzeuge()
{
	return new CS_Eingabe();
}

void CS_Eingabe::Oeffne()
{
	if (m_pCallbackOeffne)
	{
		m_pCallbackOeffne();
	}
}

void CS_Eingabe::Schliesse()
{
	if (m_pCallbackSchliesse)
	{
		m_pCallbackSchliesse();
	}
}

int CS_Eingabe::LiesZeichen()
{
	if (m_pCallbackLiesZeichen)
	{
		return m_pCallbackLiesZeichen();
	}
	return Oklabi::eof;
}

size_t CS_Eingabe::GibAnzahl()
{
	if (m_pCallbackGibAnzahl)
	{
		return (size_t)m_pCallbackGibAnzahl();
	}
	return 0;
}

size_t CS_Eingabe::GibZeilen()
{
	// TODO: Ausfüllen
	return 0;
}

bool CS_Eingabe::IstBeendet()
{
	if (m_pCallbackIstBeendet)
	{
		return m_pCallbackIstBeendet();
	}
	return 0;
}

void CS_Eingabe::SetzeKodierung(eKodierung eKod)
{
	Eingabe::SetzeKodierung(eKod);
	if (m_pCallbackSetzeKodierung)
	{
		return m_pCallbackSetzeKodierung(eKod);
	}
}

bool CS_Eingabe::IstGueltig()
{
	if (m_pCallbackIstGueltig)
	{
		return m_pCallbackIstGueltig();
	}
	return 0;
}

void CS_Eingabe::ZumAnfang()
{
	if (m_pCallbackZumAnfang)
	{
		m_pCallbackZumAnfang();
	}
}

void CALLBACK SetzeCallbackEingabeCS(void* pObj,
	void (CALLBACK* fctOeffne)(),
	void (CALLBACK* fctSchliesse)(),
	int  (CALLBACK* fctLiesZeichen)(),
	int  (CALLBACK* fctGibAnzahl)(),
	bool (CALLBACK* fctIstBeendet)(),
	bool (CALLBACK* fctIstGueltig)(),
	void (CALLBACK* fctZumAnfang)(),
	void (CALLBACK* fctSetzeKodierung)(eKodierung))
{
	if (pObj)
	{
		CS_Eingabe* pInp = (CS_Eingabe*)pObj;
		pInp->m_pCallbackOeffne = fctOeffne;
		pInp->m_pCallbackSchliesse = fctSchliesse;
		pInp->m_pCallbackLiesZeichen = fctLiesZeichen;
		pInp->m_pCallbackGibAnzahl = fctGibAnzahl;
		pInp->m_pCallbackIstBeendet = fctIstBeendet;
		pInp->m_pCallbackIstGueltig = fctIstGueltig;
		pInp->m_pCallbackZumAnfang = fctZumAnfang;
		pInp->m_pCallbackSetzeKodierung = fctSetzeKodierung;
	}
}
