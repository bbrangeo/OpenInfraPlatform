/*****************************************************************************
* $Id: J_Transformierer.cpp 2015-04-27 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2013-2015, Bundesanstalt f�r Stra�enwesen
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
* 2013-11-18 Transformierer eingef�hrt
* 2011-05-03 Formale Verbesserungen
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "J_Transformierer.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

void* CALLBACK _J_Transformierer_Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return J_Transformierer::Erzeuge(JNIEnv, JOBJECT);
}

static bool istInitialisiert = OklabiJava::Registriere("J_Transformierer", &_J_Transformierer_Erzeuge);

void J_Transformierer::Registriere()
{
	OklabiJava::Registriere("J_Transformierer", &_J_Transformierer_Erzeuge);
}

J_Transformierer::J_Transformierer(void* JNIEnv, void* JOBJECT) : OklabiJava(JNIEnv,JOBJECT),
	m_pCallbackTransform(0), m_pCallbackSRS(0)
{
}

J_Transformierer::~J_Transformierer()
{
}

Transformierer* J_Transformierer::Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return new J_Transformierer(JNIEnv, JOBJECT);
}

Text J_Transformierer::GibKlassenname() const
{
	return "J_Transformierer";
}

Text J_Transformierer::GibBeschreibung() const
{
	return "J_Transformierer";
}

bool J_Transformierer::Transformiere(Oklabi::Koordinate& koo, Oklabi::eKoordRefSys eSRS) const
{
	if (m_pCallbackTransform)
	{
		return m_pCallbackTransform(m_JNIEnv, m_JOBJECT, "Transformierer", "Transformiere", koo, eSRS);
	}
	return false;
}

bool J_Transformierer::IstUnterstuetzt(eKoordRefSys eSRS) const
{
	if (m_pCallbackSRS)
	{
		return m_pCallbackSRS(m_JNIEnv, m_JOBJECT, "Transformierer", "IstUnterstuetzt", eSRS);
	}
	return false;
}

bool J_Transformierer::IstLatLong(eKoordRefSys eSRS) const
{
	return false;
}

bool J_Transformierer::IstEastingNorthing(eKoordRefSys eSRS) const
{
	return false;
}

void SetzeCallbackTransformiererJava(void* pObj,
	bool (CALLBACK* fctTransform)(void*, void*, const char*, const char*, Koordinate&, eKoordRefSys),
	bool (CALLBACK* fctSRS)(void*, void*, const char*, const char*, eKoordRefSys))
{
	if (pObj)
	{
		J_Transformierer* pInp = (J_Transformierer*)pObj;
		pInp->m_pCallbackTransform = fctTransform;
		pInp->m_pCallbackSRS = fctSRS;
	}
}
