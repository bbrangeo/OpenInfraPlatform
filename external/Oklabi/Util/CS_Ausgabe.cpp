/*****************************************************************************
* $Id: CS_Ausgabe.cpp 2013-01-24 15:00:00 vogelsang $
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
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "CS_Ausgabe.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

CS_Ausgabe::CS_Ausgabe() : 	m_pCallbackOeffne(0), m_pCallbackSchliesse(0), m_pCallbackSchreibeZeichen(0), m_pCallbackLeere(0)
{
}

CS_Ausgabe::~CS_Ausgabe()
{
}

Text CS_Ausgabe::GibKlassenname() const
{
	return "CS_Ausgabe";
}

Text CS_Ausgabe::GibBeschreibung() const
{
	return "CS_Ausgabe";
}

Ausgabe* CS_Ausgabe::Erzeuge()
{
	return new CS_Ausgabe();
}

void CS_Ausgabe::Oeffne()
{
	if (m_pCallbackOeffne)
	{
		m_pCallbackOeffne();
	}
}

void CS_Ausgabe::Schliesse()
{
	if (m_pCallbackSchliesse)
	{
		m_pCallbackSchliesse();
	}
}

void CS_Ausgabe::SchreibeZeichen(const int& c)
{
	if (m_pCallbackSchreibeZeichen)
	{
		m_pCallbackSchreibeZeichen(c);
	}
}

void CS_Ausgabe::SchreibeZeile(const Text& line)
{
	if (m_pCallbackSchreibeZeichen)
	{
		Ausgabe::SchreibeZeile(line);
	}
}

void CS_Ausgabe::SetzeKodierung(eKodierung eKod)
{
	Ausgabe::SetzeKodierung(eKod);
	if (m_pCallbackSetzeKodierung)
	{
		return m_pCallbackSetzeKodierung(eKod);
	}
}

void CS_Ausgabe::Leere()
{
	if (m_pCallbackLeere)
	{
		m_pCallbackLeere();
	}
}

void CALLBACK SetzeCallbackAusgabeCS(void* pObj,
	void (CALLBACK* fctOeffne)(),
	void (CALLBACK* fctSchliesse)(),
	void (CALLBACK* fctSchreibeZeichen)(const int&),
	void (CALLBACK* fctLeere)(),
	void (CALLBACK* fctSetzeKodierung)(eKodierung))
{
	if (pObj)
	{
		CS_Ausgabe* pOut = (CS_Ausgabe*)pObj;
		pOut->m_pCallbackOeffne = fctOeffne;
		pOut->m_pCallbackSchliesse = fctSchliesse;
		pOut->m_pCallbackSchreibeZeichen = fctSchreibeZeichen;
		pOut->m_pCallbackLeere = fctLeere;
		pOut->m_pCallbackSetzeKodierung = fctSetzeKodierung;
	}
}
