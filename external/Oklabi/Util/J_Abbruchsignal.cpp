/*****************************************************************************
* $Id: J_Abbruchsignal.cpp 2012-10-15 15:00:00 vogelsang $
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
* 2011-10-31 Cross Language Calls
* 2012-10-15 Aufräumen bei Programmende
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "OklabiManaged.h"
#include "J_Abbruchsignal.h"
#include "CS_Abbruchsignal.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

void* CALLBACK _J_Abbruchsignal_Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return J_Abbruchsignal::Erzeuge(JNIEnv, JOBJECT);
}

static bool istInitialisiert = OklabiJava::Registriere("J_Abbruchsignal", &_J_Abbruchsignal_Erzeuge);

void J_Abbruchsignal::Registriere()
{
	OklabiJava::Registriere("J_Abbruchsignal", &_J_Abbruchsignal_Erzeuge);
}

J_Abbruchsignal::J_Abbruchsignal(void* JNIEnv, void* JOBJECT) : OklabiJava(JNIEnv,JOBJECT), m_pCallbackAbbruchsignal(0)
{
}

J_Abbruchsignal::~J_Abbruchsignal()
{
}

Abbruchsignal* J_Abbruchsignal::Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return new J_Abbruchsignal(JNIEnv, JOBJECT);
}

Text J_Abbruchsignal::GibKlassenname() const
{
	return "J_Abbruchsignal";
}

Text J_Abbruchsignal::GibBeschreibung() const
{
	return "J_Abbruchsignal";
}

bool J_Abbruchsignal::Empfange()
{
	if (!this->m_pHost)
	{
		if (m_pCallbackAbbruchsignal)
			return m_pCallbackAbbruchsignal(m_JNIEnv, m_JOBJECT, "Abbruchsignal", "Empfange");
	}
	else if (this->m_pHost->IstManagedObjekt())
	{
		// Cross Language Call
		Oklabi::CS_Abbruchsignal* pSignal = dynamic_cast<Oklabi::CS_Abbruchsignal*>(this->m_pHost);
		if (pSignal)
			return pSignal->Empfange();
	}
	else if (this->m_pHost->IstJavaObjekt())
	{
		// Cross Language Call
		Oklabi::J_Abbruchsignal* pSignal = dynamic_cast<Oklabi::J_Abbruchsignal*>(this->m_pHost);
		if (pSignal)
			return pSignal->Empfange();
	}
	return false;
}

void SetzeCallbackAbbruchsignalJava(void* pObj, bool (CALLBACK* fct)(void*, void*, const char*, const char*))
{
	if (pObj)
		((J_Abbruchsignal*)pObj)->m_pCallbackAbbruchsignal = fct;
}
