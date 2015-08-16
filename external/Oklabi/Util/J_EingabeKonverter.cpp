/*****************************************************************************
* $Id: J_EingabeKonverter.cpp 2013-11-18 15:00:00 vogelsang $
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
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2012-10-15 Aufräumen bei Programmende
* 2013-02-04 Profile
* 2013-11-18 Transformierer eingeführt
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "J_EingabeKonverter.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

void* CALLBACK _J_EingabeKonverter_Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return J_EingabeKonverter::Erzeuge(JNIEnv, JOBJECT);
}

static bool istInitialisiert = OklabiJava::Registriere("J_EingabeKonverter", &_J_EingabeKonverter_Erzeuge);

void J_EingabeKonverter::Registriere()
{
	OklabiJava::Registriere("J_EingabeKonverter", &_J_EingabeKonverter_Erzeuge);
}

J_EingabeKonverter::J_EingabeKonverter(void* JNIEnv, void* JOBJECT) : OklabiJava(JNIEnv,JOBJECT),
  m_pCallbackLade(0),
  m_pCallbackTransportiereErweiterungen(0),
  m_pCallbackVerschmelzeSymbolischeObjekte(0),
  m_pCallbackSetzeProfilerkennung(0),
  m_pCallbackTransformiere(0),
  m_pCallbackGibMetadaten(0),
  m_pCallbackGibFblVersion(0),
  m_pCallbackGibVersion(0),
  m_pCallbackGibObjektarten(0),
  m_pCallbackGibAnzahlObjekte(0)
{
}

J_EingabeKonverter::~J_EingabeKonverter()
{
}

Text J_EingabeKonverter::GibKlassenname() const
{
	return "J_EingabeKonverter";
}

EingabeKonverter* J_EingabeKonverter::Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return new J_EingabeKonverter(JNIEnv, JOBJECT);
}

Datenbestand* J_EingabeKonverter::Lade(Objektartfilter* pFilter, Objektartfilter* pSymbol)
{
	if (m_pCallbackLade)
	{
		return m_pCallbackLade(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "Lade", pFilter, pSymbol);
	}
	return NULL;
}

void J_EingabeKonverter::TransportiereErweiterungen(bool f)
{
	if (m_pCallbackTransportiereErweiterungen)
	{
		m_pCallbackTransportiereErweiterungen(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "TransportiereErweiterungen", f);
	}
}

void J_EingabeKonverter::SetzeProfilerkennung(bool f)
{
	if (m_pCallbackSetzeProfilerkennung)
	{
		m_pCallbackSetzeProfilerkennung(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "SetzeProfilerkennung", f);
	}
}

void J_EingabeKonverter::Transformiere(eKoordRefSys f)
{
	m_eTargetSRS = f;
	if (m_pCallbackTransformiere)
	{
		m_pCallbackTransformiere(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "Transformiere", f);
	}
}

Version* J_EingabeKonverter::GibVersion()
{
	if (m_pCallbackGibVersion)
	{
		return m_pCallbackGibVersion(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "GibVersion");
	}
	return NULL;
}

FblVersion* J_EingabeKonverter::GibFblVersion()
{
	if (m_pCallbackGibFblVersion)
	{
		return m_pCallbackGibFblVersion(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "GibFblVersion");
	}
	return NULL;
}

TextListe J_EingabeKonverter::GibMetadaten(eMetadaten m)
{
	if (m_pCallbackGibMetadaten)
	{
		TextListe* pListe = m_pCallbackGibMetadaten(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "GibMetadaten", m);
		if (pListe)
		{
			TextListe tl = *pListe;
			delete pListe;
			return tl;
		}
	}
	TextListe tl;
	return tl;
}

bool J_EingabeKonverter::E_FSSchemaIdentifiers(TextListe& dumy)
{
	return false;
}

TextListe J_EingabeKonverter::GibObjektarten()
{
	if (m_pCallbackGibObjektarten)
	{
		TextListe* pListe = m_pCallbackGibObjektarten(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "GibObjektarten");
		if (pListe)
		{
			TextListe tl = *pListe;
			delete pListe;
			return tl;
		}
	}
	TextListe tl;
	return tl;
}

size_t J_EingabeKonverter::GibAnzahlObjekte(const Oklabi::Text& strOA)
{
	if (m_pCallbackGibAnzahlObjekte)
	{
		return m_pCallbackGibAnzahlObjekte(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "GibAnzahlObjekte", strOA);
	}
	return 0;
}

void J_EingabeKonverter::VerschmelzeSymbolischeObjekte(bool bFlag)
{
	m_bMerge = bFlag;
	if (m_pCallbackVerschmelzeSymbolischeObjekte)
	{
		m_pCallbackVerschmelzeSymbolischeObjekte(m_JNIEnv, m_JOBJECT, "EingabeKonverter", "VerschmelzeSymbolischeObjekte", bFlag);
	}
}

// Identitätswechsel beim symbolischen Laden
void J_EingabeKonverter::Identitaetswechsel(FachobjektPtr p1, FachobjektPtr p2, const Text& kenn)
{
}

void SetzeCallbackEingabeKonverterJava(void* pObj,
	Datenbestand* (CALLBACK* fctLade)(void*, void*, const char*, const char*, Objektartfilter*, Objektartfilter*),
	Version* (CALLBACK* fctGibVersion)(void*, void*, const char*, const char*),
	void (CALLBACK* fctTransportiereErweiterungen)(void*, void*, const char*, const char*, bool),
	void (CALLBACK* fctVerschmelzeSymbolischeObjekte)(void*, void*, const char*, const char*, bool),
	void (CALLBACK* fctSetzeProfilerkennung)(void*, void*, const char*, const char*, bool),
	void (CALLBACK* fctTransformiere)(void*, void*, const char*, const char*, eKoordRefSys),
	TextListe* (CALLBACK* fctGibMetadaten)(void*, void*, const char*, const char*, eMetadaten),
	FblVersion* (CALLBACK* fctGibFblVersion)(void*, void*, const char*, const char*),
	TextListe* (CALLBACK* fctGibObjektarten)(void*, void*, const char*, const char*),
	size_t (CALLBACK* fctGibAnzahlObjekte)(void*, void*, const char*, const char*, const Text&))
{
	if (pObj)
	{
		J_EingabeKonverter* pIcv = (J_EingabeKonverter*)pObj;
		pIcv->m_pCallbackLade = fctLade;
		pIcv->m_pCallbackGibVersion = fctGibVersion;
		pIcv->m_pCallbackTransportiereErweiterungen = fctTransportiereErweiterungen;
		pIcv->m_pCallbackVerschmelzeSymbolischeObjekte = fctVerschmelzeSymbolischeObjekte;
		pIcv->m_pCallbackSetzeProfilerkennung = fctSetzeProfilerkennung;
		pIcv->m_pCallbackTransformiere = fctTransformiere;
		pIcv->m_pCallbackGibMetadaten = fctGibMetadaten;
		pIcv->m_pCallbackGibFblVersion = fctGibFblVersion;
		pIcv->m_pCallbackGibObjektarten = fctGibObjektarten;
		pIcv->m_pCallbackGibAnzahlObjekte = fctGibAnzahlObjekte;
	}
}
