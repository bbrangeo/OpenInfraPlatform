/*****************************************************************************
* $Id: CS_AusgabeKonverter.cpp 2013-02-04 15:00:00 vogelsang $
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
* 2010-07-19 Aufrufkonventionen bei Callback-Funktionen fehlerhaft
* 2010-11-23 Komprimierte Ein- und Ausgabe
* 2013-02-04 Profile
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "CS_AusgabeKonverter.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

CS_AusgabeKonverter::CS_AusgabeKonverter()
: m_pCallbackEntlade(0),
  m_pCallbackSetzeSortierung(0),
  m_pCallbackTransportiereErweiterungen(0),
  m_pCallbackSetzeProfilerkennung(0),
  m_pCallbackSetzeMetadaten(0),
  m_pCallbackSetzeFblVersion(0),
  m_pCallbackKomprimiere(0)
{
}

CS_AusgabeKonverter::~CS_AusgabeKonverter()
{
}

Text CS_AusgabeKonverter::GibKlassenname() const
{
	return "CS_AusgabeKonverter";
}

AusgabeKonverter* CS_AusgabeKonverter::Erzeuge()
{
	return new CS_AusgabeKonverter();
}

void CS_AusgabeKonverter::Entlade(Datenbestand* pBestand)
{
	if (m_pCallbackEntlade)
	{
		m_pCallbackEntlade(pBestand);
	}
}

void CS_AusgabeKonverter::SetzeSortierung(eSort s)
{
	if (m_pCallbackSetzeSortierung)
	{
		m_pCallbackSetzeSortierung(s);
	}
}

void CS_AusgabeKonverter::TransportiereErweiterungen(bool f)
{
	if (m_pCallbackTransportiereErweiterungen)
	{
		m_pCallbackTransportiereErweiterungen(f);
	}
}

void CS_AusgabeKonverter::SetzeProfilerkennung(bool f)
{
	if (m_pCallbackSetzeProfilerkennung)
	{
		m_pCallbackSetzeProfilerkennung(f);
	}
}

void CS_AusgabeKonverter::Komprimiere(bool f)
{
	if (m_pCallbackKomprimiere)
	{
		m_pCallbackKomprimiere(f);
	}
}

void CS_AusgabeKonverter::SetzeMetadaten(eMetadaten m, const Text& t)
{
	if (m_pCallbackSetzeMetadaten)
	{
		m_pCallbackSetzeMetadaten(m, t);
	}
}

void CS_AusgabeKonverter::SetzeFblVersion(const FblVersion* pFbl)
{
	if (m_pCallbackSetzeFblVersion)
	{
		m_pCallbackSetzeFblVersion(pFbl);
	}
}

void CS_AusgabeKonverter::KonkordanzSetzen(Oklabi::Ausgabe* pDatei, const char* pFieldDelimit, const char* pStringDelimit, const char* pIdPrefix)
{
	if (m_pCallbackKonkordanz)
	{
		m_pCallbackKonkordanz(pDatei, pFieldDelimit, pStringDelimit, pIdPrefix);
	}
}

void CALLBACK SetzeCallbackAusgabeKonverterCS(void* pObj,
	void (CALLBACK* fctEntlade)(Datenbestand*),
	void (CALLBACK* fctSetzeSortierung)(eSort),
	void (CALLBACK* fctTransportiereErweiterungen)(bool),
	void (CALLBACK* fctSetzeProfilerkennung)(bool),
	void (CALLBACK* fctSetzeMetadaten)(eMetadaten, const Text&),
	void (CALLBACK* fctSetzeFblVersion)(const FblVersion*),
	void (CALLBACK* fctKomprimiere)(bool),
	void (CALLBACK* fctKonkordanzSetzen)(Oklabi::Ausgabe*, const Oklabi::Text&, const Oklabi::Text&, const Oklabi::Text&))
{
	if (pObj)
	{
		CS_AusgabeKonverter* pOut = (CS_AusgabeKonverter*)pObj;
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

