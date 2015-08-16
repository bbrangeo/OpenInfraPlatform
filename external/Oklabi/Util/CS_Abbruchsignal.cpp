/*****************************************************************************
* $Id: CS_Abbruchsignal.cpp 2011-10-31 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010, Bundesanstalt für Straßenwesen
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
* 2011-10-31 Cross Language Calls
* 
****************************************************************************/
#include "CS_Abbruchsignal.h"
#include "J_Abbruchsignal.h"
#include "OklabiMgd.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

CS_Abbruchsignal::CS_Abbruchsignal() : m_pCallback(0)
{
}

CS_Abbruchsignal::~CS_Abbruchsignal()
{
	Umgebung::Objekt()->Austragen(this);
}

Abbruchsignal* CS_Abbruchsignal::Erzeuge()
{
	return new CS_Abbruchsignal();
}

bool CS_Abbruchsignal::Empfange()
{
	if (!this->m_pHost)
	{
		if (m_pCallback)
			return m_pCallback();
	}
	else if (this->m_pHost->IstJavaObjekt())
	{
		// Cross Language Call
		Oklabi::J_Abbruchsignal* pSign = dynamic_cast<Oklabi::J_Abbruchsignal*>(this->m_pHost);
		if (pSign)
			return pSign->Empfange();
	}
	else if (this->m_pHost->IstManagedObjekt())
	{
		// Cross Language Call
		Oklabi::CS_Abbruchsignal* pSign = dynamic_cast<Oklabi::CS_Abbruchsignal*>(this->m_pHost);
		if (pSign)
			return pSign->Empfange();
	}
	return false;
}

Text CS_Abbruchsignal::GibKlassenname() const
{
	return "CS_Abbruchsignal";
}

void CALLBACK SetzeCallbackAbbruchsignalCS(void* pObj, bool (CALLBACK* fct)())
{
	if (pObj)
		((CS_Abbruchsignal*)pObj)->m_pCallback = fct;
}
