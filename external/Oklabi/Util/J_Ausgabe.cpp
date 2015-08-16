/*****************************************************************************
* $Id: J_Ausgabe.cpp 2013-01-24 15:00:00 vogelsang $
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
* 2012-10-15 Aufräumen bei Programmende
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "J_Ausgabe.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

void* CALLBACK _J_Ausgabe_Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return J_Ausgabe::Erzeuge(JNIEnv, JOBJECT);
}

static bool istInitialisiert = OklabiJava::Registriere("J_Ausgabe", &_J_Ausgabe_Erzeuge);

void J_Ausgabe::Registriere()
{
	OklabiJava::Registriere("J_Ausgabe", &_J_Ausgabe_Erzeuge);
}

J_Ausgabe::J_Ausgabe(void* JNIEnv, void* JOBJECT) : OklabiJava(JNIEnv,JOBJECT),
	m_pCallbackAusgabeOeffne(0), m_pCallbackAusgabeSchliesse(0), m_pCallbackAusgabeSchreibeZeichen(0), m_pCallbackAusgabeLeere(0)
{
}

J_Ausgabe::~J_Ausgabe()
{
}

Ausgabe* J_Ausgabe::Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return new J_Ausgabe(JNIEnv, JOBJECT);
}

Text J_Ausgabe::GibKlassenname() const
{
	return "J_Ausgabe";
}

Text J_Ausgabe::GibBeschreibung() const
{
	return "J_Ausgabe";
}

void J_Ausgabe::Oeffne()
{
	if (m_pCallbackAusgabeOeffne)
	{
		m_pCallbackAusgabeOeffne(m_JNIEnv, m_JOBJECT, "Ausgabe", "Oeffne");
	}
}

void J_Ausgabe::Schliesse()
{
	if (m_pCallbackAusgabeSchliesse)
	{
		m_pCallbackAusgabeSchliesse(m_JNIEnv, m_JOBJECT, "Ausgabe", "Schliesse");
	}
}

void J_Ausgabe::SchreibeZeichen(const int& c)
{
	if (m_pCallbackAusgabeSchreibeZeichen)
	{
		m_pCallbackAusgabeSchreibeZeichen(m_JNIEnv, m_JOBJECT, "Ausgabe", "SchreibeZeichen", c);
	}
}

void J_Ausgabe::SchreibeZeile(const Text& line)
{
	if (m_pCallbackAusgabeSchreibeZeichen)
	{
		Ausgabe::SchreibeZeile(line);
	}
}

void J_Ausgabe::SetzeKodierung(eKodierung eKod)
{
	Ausgabe::SetzeKodierung(eKod);
	if (m_pCallbackAusgabeSetzeKodierung)
	{
		return m_pCallbackAusgabeSetzeKodierung(m_JNIEnv, m_JOBJECT, "Ausgabe", "SetzeKodierung", eKod);
	}
}

void J_Ausgabe::Leere()
{
	if (m_pCallbackAusgabeLeere)
	{
		m_pCallbackAusgabeLeere(m_JNIEnv, m_JOBJECT, "Ausgabe", "Leere");
	}
}

void SetzeCallbackAusgabeJava(void* pObj,
	void (CALLBACK* fctOeffne)(void*, void*, const char*, const char*),
	void (CALLBACK* fctSchliesse)(void*, void*, const char*, const char*),
	void (CALLBACK* fctSchreibeZeichen)(void*, void*, const char*, const char*, int),
	void (CALLBACK* fctLeere)(void*, void*, const char*, const char*),
	void (CALLBACK* fctSetzeKodierung)(void*, void*, const char*, const char*, eKodierung))
{
	if (pObj)
	{
		J_Ausgabe* pOut = (J_Ausgabe*)pObj;
		pOut->m_pCallbackAusgabeOeffne = fctOeffne;
		pOut->m_pCallbackAusgabeSchliesse = fctSchliesse;
		pOut->m_pCallbackAusgabeSchreibeZeichen = fctSchreibeZeichen;
		pOut->m_pCallbackAusgabeLeere = fctLeere;
		pOut->m_pCallbackAusgabeSetzeKodierung = fctSetzeKodierung;
	}
}
