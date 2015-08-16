/*****************************************************************************
* $Id: J_Eingabe.cpp 2013-01-24 15:00:00 vogelsang $
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
* 2012-07-27 Interface umbenannt
* 2012-10-15 Aufräumen bei Programmende
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "J_Eingabe.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

void* CALLBACK _J_Eingabe_Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return J_Eingabe::Erzeuge(JNIEnv, JOBJECT);
}

static bool istInitialisiert = OklabiJava::Registriere("J_Eingabe", &_J_Eingabe_Erzeuge);

void J_Eingabe::Registriere()
{
	OklabiJava::Registriere("J_Eingabe", &_J_Eingabe_Erzeuge);
}

J_Eingabe::J_Eingabe(void* JNIEnv, void* JOBJECT) : OklabiJava(JNIEnv,JOBJECT),
	m_pCallbackEingabeOeffne(0), m_pCallbackEingabeSchliesse(0), m_pCallbackEingabeLiesZeichen(0), m_pCallbackEingabeGibAnzahl(0),
	m_pCallbackEingabeIstBeendet(0), m_pCallbackEingabeIstGueltig(0), m_pCallbackEingabeZumAnfang(0)
{
}

J_Eingabe::~J_Eingabe()
{
}

Eingabe* J_Eingabe::Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return new J_Eingabe(JNIEnv, JOBJECT);
}

Text J_Eingabe::GibKlassenname() const
{
	return "J_Eingabe";
}

Text J_Eingabe::GibBeschreibung() const
{
	return "J_Eingabe";
}

void J_Eingabe::Oeffne()
{
	if (m_pCallbackEingabeOeffne)
	{
		m_pCallbackEingabeOeffne(m_JNIEnv, m_JOBJECT, "Eingabe", "Oeffne");
	}
}

void J_Eingabe::Schliesse()
{
	if (m_pCallbackEingabeSchliesse)
	{
		m_pCallbackEingabeSchliesse(m_JNIEnv, m_JOBJECT, "Eingabe", "Schliesse");
	}
}

int J_Eingabe::LiesZeichen()
{
	if (m_pCallbackEingabeLiesZeichen)
	{
		return m_pCallbackEingabeLiesZeichen(m_JNIEnv, m_JOBJECT, "Eingabe", "LiesZeichen");
	}
	return Oklabi::eof;
}

size_t J_Eingabe::GibAnzahl()
{
	if (m_pCallbackEingabeGibAnzahl)
	{
		return (size_t)m_pCallbackEingabeGibAnzahl(m_JNIEnv, m_JOBJECT, "Eingabe", "GibAnzahl");
	}
	return 0;
}

size_t J_Eingabe::GibZeilen()
{
	// TODO: Ausfüllen
	return 0;
}

bool J_Eingabe::IstBeendet()
{
	if (m_pCallbackEingabeIstBeendet)
	{
		return m_pCallbackEingabeIstBeendet(m_JNIEnv, m_JOBJECT, "Eingabe", "IstBeendet");
	}
	return 0;
}

void J_Eingabe::SetzeKodierung(eKodierung eKod)
{
	Eingabe::SetzeKodierung(eKod);
	if (m_pCallbackEingabeSetzeKodierung)
	{
		return m_pCallbackEingabeSetzeKodierung(m_JNIEnv, m_JOBJECT, "Eingabe", "SetzeKodierung", eKod);
	}
}

bool J_Eingabe::IstGueltig()
{
	if (m_pCallbackEingabeIstGueltig)
	{
		return m_pCallbackEingabeIstGueltig(m_JNIEnv, m_JOBJECT, "Eingabe", "IstGueltig");
	}
	return 0;
}

void J_Eingabe::ZumAnfang()
{
	if (m_pCallbackEingabeZumAnfang)
	{
		m_pCallbackEingabeZumAnfang(m_JNIEnv, m_JOBJECT, "Eingabe", "ZumAnfang");
	}
}

void SetzeCallbackEingabeJava(void* pObj,
	void (CALLBACK* fctOeffne)(void*, void*, const char*, const char*),
	void (CALLBACK* fctSchliesse)(void*, void*, const char*, const char*),
	int  (CALLBACK* fctLiesZeichen)(void*, void*, const char*, const char*),
	int  (CALLBACK* fctGibAnzahl)(void*, void*, const char*, const char*),
	bool (CALLBACK* fctIstBeendet)(void*, void*, const char*, const char*),
	bool (CALLBACK* fctIstGueltig)(void*, void*, const char*, const char*),
	void (CALLBACK* fctZumAnfang)(void*, void*, const char*, const char*),
	void (CALLBACK* fctSetzeKodierung)(void*, void*, const char*, const char*, eKodierung))
{
	if (pObj)
	{
		J_Eingabe* pInp = (J_Eingabe*)pObj;
		pInp->m_pCallbackEingabeOeffne = fctOeffne;
		pInp->m_pCallbackEingabeSchliesse = fctSchliesse;
		pInp->m_pCallbackEingabeLiesZeichen = fctLiesZeichen;
		pInp->m_pCallbackEingabeGibAnzahl = fctGibAnzahl;
		pInp->m_pCallbackEingabeIstBeendet = fctIstBeendet;
		pInp->m_pCallbackEingabeIstGueltig = fctIstGueltig;
		pInp->m_pCallbackEingabeZumAnfang = fctZumAnfang;
		pInp->m_pCallbackEingabeSetzeKodierung = fctSetzeKodierung;
	}
}
