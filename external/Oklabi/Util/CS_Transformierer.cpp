/*****************************************************************************
* $Id: CS_Transformierer.cpp 2013-11-18 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2013-2014, Bundesanstalt für Straßenwesen
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
* 2013-11-18 Transformierer eingeführt
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "CS_Transformierer.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

CS_Transformierer::CS_Transformierer() : m_pCallbackTransform(0), m_pCallbackSRS(0)
{
}

CS_Transformierer::~CS_Transformierer()
{
}

Text CS_Transformierer::GibKlassenname() const
{
	return "CS_Transformierer";
}

Text CS_Transformierer::GibBeschreibung() const
{
	return "CS_Transformierer";
}

Transformierer* CS_Transformierer::Erzeuge()
{
	return new CS_Transformierer();
}

bool CS_Transformierer::Transformiere(Oklabi::Koordinate& koo, Oklabi::eKoordRefSys eSRS) const
{
	if (m_pCallbackTransform)
	{
		return m_pCallbackTransform(koo, eSRS);
	}
	return false;
}

bool CS_Transformierer::IstUnterstuetzt(eKoordRefSys eSRS) const
{
	if (m_pCallbackSRS)
	{
		return m_pCallbackSRS(eSRS);
	}
	return false;
}

bool CS_Transformierer::IstLatLong(eKoordRefSys eSRS) const
{
	return false;
}

bool CS_Transformierer::IstEastingNorthing(eKoordRefSys eSRS) const
{
	return false;
}

void CALLBACK SetzeCallbackTransformiererCS(void* pObj,
	bool (CALLBACK* fctTransform)(Koordinate&, eKoordRefSys),
	bool (CALLBACK* fctSRS)(eKoordRefSys))
{
	if (pObj)
	{
		CS_Transformierer* pInp = (CS_Transformierer*)pObj;
		pInp->m_pCallbackTransform = fctTransform;
		pInp->m_pCallbackSRS = fctSRS;
	}
}
