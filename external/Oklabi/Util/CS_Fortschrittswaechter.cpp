/*****************************************************************************
* $Id: CS_Fortschrittswaechter.cpp 2011-10-31 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010, Bundesanstalt f�r Stra�enwesen
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
* 2010-07-19 Aufrufkonventionen bei Callback-Funktionen fehlerhaft
* 2011-10-31 Cross Language Calls
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "OklabiJava.h"
#include "CS_Fortschrittswaechter.h"
#include "J_Fortschrittswaechter.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

CS_Fortschrittswaechter::CS_Fortschrittswaechter() : m_pCallback(0)
{
}

CS_Fortschrittswaechter::~CS_Fortschrittswaechter()
{
	Umgebung::Objekt()->Austragen(this);
}

Fortschrittswaechter* CS_Fortschrittswaechter::Erzeuge()
{
	return new CS_Fortschrittswaechter();
}

void CS_Fortschrittswaechter::Melde(int p, Oklabi::eFortTyp t)
{
	if (!this->m_pHost)
	{
		if (m_pCallback)
			m_pCallback(p, t);
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

Text CS_Fortschrittswaechter::GibKlassenname() const
{
	return "CS_Fortschrittswaechter";
}

void CALLBACK SetzeCallbackFortschrittswaechterCS(bool dumy, void* pObj, void (CALLBACK* fct)(int p, Oklabi::eFortTyp typ))
{
	if (pObj)
		((CS_Fortschrittswaechter*)pObj)->m_pCallback = fct;
}
