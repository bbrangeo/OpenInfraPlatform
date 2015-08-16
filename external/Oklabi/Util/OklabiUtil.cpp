/*****************************************************************************
* $Id: OklabiUtil.cpp 2012-10-15 15:00:00 vogelsang $
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
* 2012-10-15 Aufräumen bei Programmende
* 
****************************************************************************/
// OklabiUtil.cpp : Defines the entry point for the DLL application.
//
#include "OklabiUtil.h"
#include "OklabiMgd.h"
#include "OklabiManaged.h"
#include "OklabiJava.h"
#include "OklabiMixed.h"
#include "Umgebung.h"
#include "J_Abbruchsignal.h"
#include "J_Ausgabe.h"
#include "J_AusgabeKonverter.h"
#include "J_Eingabe.h"
#include "J_EingabeKonverter.h"
#include "J_Fortschrittswaechter.h"
#include "J_Protokollant.h"
#include "J_Transformierer.h"
#ifdef WIN32
#include "stdafx.h"

#ifdef _MANAGED
#pragma managed(push, off)
#endif

using namespace Oklabi;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif
#endif

using namespace Oklabi;

///////////////////////////////////////////////////////////////////////////////
// OklabiJava

Oklabi::ErzeugeFunktionMapType* Oklabi::OklabiJava::m_pmapErzFkt = NULL;

pJErzeugeFunktion Oklabi::OklabiJava::GibErzeugeFunktion(const char* pName)
{
	if (!m_pmapErzFkt)
		OklabiJava::intialize();
	if (m_pmapErzFkt)
	{
		Oklabi::ErzeugeFunktionMapType::const_iterator iter = m_pmapErzFkt->find(pName);
		if (iter != m_pmapErzFkt->end())
			return (*iter).second;
	}
	return NULL;
}

// Registrierung kann über statische Initialisierung oder
// durch LazyInit per OklabiJava::initialize() erfolgen
bool Oklabi::OklabiJava::Registriere(const char* pName, Oklabi::pJErzeugeFunktion pFkt)
{
	if (!m_pmapErzFkt)
	{
		m_pmapErzFkt = new Oklabi::ErzeugeFunktionMapType();
		Umgebung::Finalisierer(OklabiJava::finalize);
	}
	if (m_pmapErzFkt->find(pName) == m_pmapErzFkt->end())
		m_pmapErzFkt->insert(Oklabi::ErzeugeFunktionMapType::value_type(pName, pFkt));
	return true;
}

bool Oklabi::OklabiJava::intialize()
{
	J_Abbruchsignal::Registriere();
	J_Ausgabe::Registriere();
	J_AusgabeKonverter::Registriere();
	J_Eingabe::Registriere();
	J_EingabeKonverter::Registriere();
	J_Fortschrittswaechter::Registriere();
	J_Protokollant::Registriere();
	J_Transformierer::Registriere();
	return true;
}

int Oklabi::OklabiJava::finalize()
{
	if (m_pmapErzFkt)
	{
		delete m_pmapErzFkt;
		m_pmapErzFkt = 0;
	}
	return 0;
}

OklabiJava::OklabiJava(void* JNIEnv, void* JOBJECT) : m_JNIEnv(JNIEnv), m_JOBJECT(JOBJECT)
{
}

OklabiJava::~OklabiJava()
{
	pJErzeugeFunktion pFkt = (m_JNIEnv && m_JOBJECT) ? GibErzeugeFunktion("_ReleaseJavaObject") : NULL;
	if (pFkt)
		(*pFkt)(m_JNIEnv, m_JOBJECT);
}

void OklabiJava::SetzeJavaObjekt(void* pObj)
{
	m_JOBJECT = pObj;
}

void* OklabiJava::GibJavaObjekt()
{
	return m_JOBJECT;
}

///////////////////////////////////////////////////////////////////////////////
// OklabiManaged

OklabiManaged::OklabiManaged()
{
}

OklabiManaged::~OklabiManaged()
{
}

///////////////////////////////////////////////////////////////////////////////
// OklabiMixed

OklabiMixed::OklabiMixed() : m_pClient(NULL), m_pHost(NULL)
{
}

OklabiMixed::~OklabiMixed()
{
	// Client-Objekt beseitigen wenn vorhanden
	Befreie();
}

OklabiMixed* OklabiMixed::GibClient() const
{
	return m_pClient;
}

OklabiMixed* OklabiMixed::GibHost() const
{
	return m_pHost;
}

void OklabiMixed::SetzeClient(OklabiMixed* pClient)
{
	// Vorhandenes Client-Objekt beseitigen
	if (m_pClient && m_pClient != pClient)
		Befreie();
	// Neues Client-Objekt übernehmen
	// und referenzieren, ist Privatbesitz
	m_pClient = pClient;
	if (m_pClient)
		m_pClient->m_pHost = this;
	Oklabi::OklabiObjekt* pObj = dynamic_cast<Oklabi::OklabiObjekt*>(m_pClient);
	if (pObj)
		pObj->Referenziere();
}

void OklabiMixed::Befreie()
{
	// Client-Objekt ablösen
	if (m_pClient)
		m_pClient->m_pHost = NULL;
	Oklabi::OklabiObjekt* pObj = dynamic_cast<Oklabi::OklabiObjekt*>(m_pClient);
	this->m_pClient = NULL;
	if (!pObj)
		return;
	// Client-Objekt ist im exklusiven Besitz, freigeben
	// wenn keine weiteren Referenzen vorhanden sind
	UINT64 nID = pObj->GibIdentifizierer();
	pObj->Dereferenziere();
	if (!Oklabi::OklabiObjekt::SucheIdentifizierer(nID))
		pObj->Vernichte();
}

///////////////////////////////////////////////////////////////////////////////
// OklabiUtil

bool OklabiUtil::IstJavaObjekt() const
{
	return dynamic_cast<const Oklabi::OklabiJava*>(this) ? true : false;
}

bool OklabiUtil::IstManagedObjekt() const
{
	return dynamic_cast<const Oklabi::OklabiManaged*>(this) ? true : false;
}

OklabiUtil::OklabiUtil()
{
}

OklabiUtil::~OklabiUtil()
{
}
