/*****************************************************************************
* $Id: J_Protokollant.cpp 2012-10-15 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt f�r Stra�enwesen
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
* 2012-10-15 Aufr�umen bei Programmende
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "J_Protokollant.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

void* CALLBACK _J_Protokollant_Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return J_Protokollant::Erzeuge(JNIEnv, JOBJECT);
}

static bool istInitialisiert = OklabiJava::Registriere("J_Protokollant", &_J_Protokollant_Erzeuge);

void J_Protokollant::Registriere()
{
	OklabiJava::Registriere("J_Protokollant", &_J_Protokollant_Erzeuge);
}

J_Protokollant::J_Protokollant(void* JNIEnv, void* JOBJECT) : OklabiJava(JNIEnv,JOBJECT), m_pCallbackProtokollant(0)
{
}

J_Protokollant::~J_Protokollant()
{
}

Protokollant* J_Protokollant::Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return new J_Protokollant(JNIEnv, JOBJECT);
}

Text J_Protokollant::GibKlassenname() const
{
	return "J_Protokollant";
}

Text J_Protokollant::GibBeschreibung() const
{
	return "J_Protokollant";
}

void J_Protokollant::Melde( int nr, const Text& str, eMeldTyp m )
{
	if (m_pCallbackProtokollant)
		m_pCallbackProtokollant(m_JNIEnv, m_JOBJECT, "Protokollant", "Melde", nr, str, m);
}

void SetzeCallbackProtokollantJava(void* pObj, void (CALLBACK* fct)(void*, void*, const char*, const char*, int nr, const Oklabi::Text& text, Oklabi::eMeldTyp typ))
{
	if (pObj)
		((J_Protokollant*)pObj)->m_pCallbackProtokollant = fct;
}
