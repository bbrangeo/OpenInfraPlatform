/*****************************************************************************
* $Id: J_AusgabeKonverter.cpp 2013-02-04 15:00:00 vogelsang $
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
* 2010-11-23 Komprimierte Ein- und Ausgabe
* 2012-10-15 Aufräumen bei Programmende
* 2013-02-04 Profile
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "J_AusgabeKonverter.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

void* CALLBACK _J_AusgabeKonverter_Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return J_AusgabeKonverter::Erzeuge(JNIEnv, JOBJECT);
}

static bool istInitialisiert = OklabiJava::Registriere("J_AusgabeKonverter", &_J_AusgabeKonverter_Erzeuge);

void J_AusgabeKonverter::Registriere()
{
	OklabiJava::Registriere("J_AusgabeKonverter", &_J_AusgabeKonverter_Erzeuge);
}

J_AusgabeKonverter::J_AusgabeKonverter(void* JNIEnv, void* JOBJECT) : OklabiJava(JNIEnv,JOBJECT),
  m_pCallbackEntlade(0),
  m_pCallbackSetzeSortierung(0),
  m_pCallbackTransportiereErweiterungen(0),
  m_pCallbackSetzeProfilerkennung(0),
  m_pCallbackSetzeMetadaten(0),
  m_pCallbackSetzeFblVersion(0),
  m_pCallbackKomprimiere(0)
{
}

J_AusgabeKonverter::~J_AusgabeKonverter()
{
}

Text J_AusgabeKonverter::GibKlassenname() const
{
	return "J_AusgabeKonverter";
}

AusgabeKonverter* J_AusgabeKonverter::Erzeuge(void* JNIEnv, void* JOBJECT)
{
	return new J_AusgabeKonverter(JNIEnv, JOBJECT);
}

void J_AusgabeKonverter::Entlade(Datenbestand* pBestand)
{
	if (m_pCallbackEntlade)
	{
		m_pCallbackEntlade(m_JNIEnv, m_JOBJECT, "AusgabeKonverter", "Entlade", pBestand);
	}
}

void J_AusgabeKonverter::SetzeSortierung(eSort s)
{
	if (m_pCallbackSetzeSortierung)
	{
		m_pCallbackSetzeSortierung(m_JNIEnv, m_JOBJECT, "AusgabeKonverter", "SetzeSortierung", s);
	}
}

void J_AusgabeKonverter::TransportiereErweiterungen(bool f)
{
	if (m_pCallbackTransportiereErweiterungen)
	{
		m_pCallbackTransportiereErweiterungen(m_JNIEnv, m_JOBJECT, "AusgabeKonverter", "TransportiereErweiterungen", f);
	}
}

void J_AusgabeKonverter::SetzeProfilerkennung(bool f)
{
	if (m_pCallbackSetzeProfilerkennung)
	{
		m_pCallbackSetzeProfilerkennung(m_JNIEnv, m_JOBJECT, "AusgabeKonverter", "SetzeProfilerkennung", f);
	}
}

void J_AusgabeKonverter::Komprimiere(bool f)
{
	if (m_pCallbackKomprimiere)
	{
		m_pCallbackKomprimiere(m_JNIEnv, m_JOBJECT, "AusgabeKonverter", "Komprimiere", f);
	}
}

void J_AusgabeKonverter::SetzeMetadaten(eMetadaten m, const Text& t)
{
	if (m_pCallbackSetzeMetadaten)
	{
		m_pCallbackSetzeMetadaten(m_JNIEnv, m_JOBJECT, "AusgabeKonverter", "SetzeMetadaten", m, t);
	}
}

void J_AusgabeKonverter::SetzeFblVersion(const FblVersion* pFbl)
{
	if (m_pCallbackSetzeFblVersion)
	{
		m_pCallbackSetzeFblVersion(m_JNIEnv, m_JOBJECT, "AusgabeKonverter", "SetzeFblVersion", pFbl);
	}
}

void J_AusgabeKonverter::KonkordanzSetzen(Oklabi::Ausgabe* pDatei, const char* pFieldDelimit, const char* pStringDelimit, const char* pIdPrefix)
{
	if (m_pCallbackKonkordanz)
	{
		m_pCallbackKonkordanz(m_JNIEnv, m_JOBJECT, "AusgabeKonverter", "KonkordanzSetzen", pDatei, pFieldDelimit, pStringDelimit, pIdPrefix);
	}
}

void SetzeCallbackAusgabeKonverterJava(void* pObj,
	void (CALLBACK* fctEntlade)(void*, void*, const char*, const char*, Datenbestand*),
	void (CALLBACK* fctSetzeSortierung)(void*, void*, const char*, const char*, eSort),
	void (CALLBACK* fctTransportiereErweiterungen)(void*, void*, const char*, const char*, bool),
	void (CALLBACK* fctSetzeProfilerkennung)(void*, void*, const char*, const char*, bool),
	void (CALLBACK* fctSetzeMetadaten)(void*, void*, const char*, const char*, eMetadaten, const Text&),
	void (CALLBACK* fctSetzeFblVersion)(void*, void*, const char*, const char*, const FblVersion*),
	void (CALLBACK* fctKomprimiere)(void*, void*, const char*, const char*, bool),
	void (CALLBACK* fctKonkordanzSetzen)(void*, void*, const char*, const char*, Oklabi::Ausgabe*, const Oklabi::Text&, const Oklabi::Text&, const Oklabi::Text&))
{
	if (pObj)
	{
		J_AusgabeKonverter* pOut = (J_AusgabeKonverter*)pObj;
		pOut->m_pCallbackEntlade = fctEntlade;
		pOut->m_pCallbackSetzeSortierung = fctSetzeSortierung;
		pOut->m_pCallbackTransportiereErweiterungen = fctTransportiereErweiterungen;
		pOut->m_pCallbackSetzeProfilerkennung = fctSetzeProfilerkennung;
		pOut->m_pCallbackSetzeMetadaten = fctSetzeMetadaten;
		pOut->m_pCallbackSetzeFblVersion = fctSetzeFblVersion;
		pOut->m_pCallbackKomprimiere = fctKomprimiere;
		pOut->m_pCallbackKonkordanz = fctKonkordanzSetzen;
	}
}
