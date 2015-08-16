/*****************************************************************************
* $Id: CS_Protokollant.cpp 2010-07-19 15:00:00 vogelsang $
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
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "CS_Protokollant.h"
#include "Umgebung.h"

#include <sstream>
#include <iomanip>

using namespace Oklabi;
using namespace std;

CS_Protokollant::CS_Protokollant() : m_pCallback(0), m_pOut(NULL), m_bOpen(false)
{
}

CS_Protokollant::~CS_Protokollant()
{
	if (m_pOut && m_bOpen)
		m_pOut->Schliesse();
	Umgebung::Objekt()->Austragen(this);
}

Text CS_Protokollant::GibKlassenname() const
{
	return "CS_Protokollant";
}

Protokollant* CS_Protokollant::Erzeuge(Ausgabe* pOut)
{
	CS_Protokollant* pPr = new CS_Protokollant();
	pPr->m_pOut = pOut;
	return pPr;
}

void CS_Protokollant::Melde( int nr, const Text& str, eMeldTyp m )
{
	if (m_pCallback)
		m_pCallback(nr, str, m);
}

void CALLBACK SetzeCallbackProtokollantCS(void* pObj, void (CALLBACK* fct)(int nr, const Oklabi::Text& text, Oklabi::eMeldTyp typ))
{
	if (pObj)
		((CS_Protokollant*)pObj)->m_pCallback = fct;
}
