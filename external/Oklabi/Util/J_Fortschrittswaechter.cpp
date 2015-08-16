/*****************************************************************************
* $Id: J_Fortschrittswaechter.cpp 2012-10-15 15:00:00 vogelsang $
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
#include "J_Fortschrittswaechter.h"
#include "CS_Fortschrittswaechter.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

void* CALLBACK _J_Fortschrittswaechter_Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return J_Fortschrittswaechter::Erzeuge(JNIEnv, JOBJECT);
}

static bool istInitialisiert = OklabiJava::Registriere("J_Fortschrittswaechter", &_J_Fortschrittswaechter_Erzeuge);

void J_Fortschrittswaechter::Registriere()
{
	OklabiJava::Registriere("J_Fortschrittswaechter", &_J_Fortschrittswaechter_Erzeuge);
}

J_Fortschrittswaechter::J_Fortschrittswaechter(void* JNIEnv, void* JOBJECT) : OklabiJava(JNIEnv,JOBJECT), m_pCallbackFortschrittswaechter(0)
{
}

J_Fortschrittswaechter::~J_Fortschrittswaechter()
{
}

Fortschrittswaechter* J_Fortschrittswaechter::Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return new J_Fortschrittswaechter(JNIEnv, JOBJECT);
}

Text J_Fortschrittswaechter::GibKlassenname() const
{
	return "J_Fortschrittswaechter";
}

Text J_Fortschrittswaechter::GibBeschreibung() const
{
	return "J_Fortschrittswaechter";
}

void J_Fortschrittswaechter::Melde(int p, Oklabi::eFortTyp t)
{
	if (!this->m_pHost)
	{
		if (m_pCallbackFortschrittswaechter)
			m_pCallbackFortschrittswaechter(m_JNIEnv, m_JOBJECT, "Fortschrittswaechter", "Melde", p, t);
	}
	else if (this->m_pHost->IstJavaObjekt())
	{
		// Cross Language Call
		Oklabi::J_Fortschrittswaechter* pProgr = dynamic_cast<Oklabi::J_Fortschrittswaechter*>(this->m_pHost);
		if (pProgr)
			pProgr->Melde(p, t);
	}
	else if (this->m_pHost->IstManagedObjekt())
	{
		// Cross Language Call
		Oklabi::CS_Fortschrittswaechter* pProgr = dynamic_cast<Oklabi::CS_Fortschrittswaechter*>(this->m_pHost);
		if (pProgr)
			pProgr->Melde(p, t);
	}
}

void SetzeCallbackFortschrittswaechterJava(void* pObj, void (CALLBACK* fct)(void*, void*, const char*, const char*, int p, Oklabi::eFortTyp typ))
{
	if (pObj)
		((J_Fortschrittswaechter*)pObj)->m_pCallbackFortschrittswaechter = fct;
}
