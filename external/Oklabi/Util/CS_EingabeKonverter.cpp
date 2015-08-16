/*****************************************************************************
* $Id: CS_EingabeKonverter.cpp 2013-11-18 15:00:00 vogelsang $
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
* 2010-12-14 Vorschau auf Eingabedaten
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2013-02-04 Profile
* 2013-11-18 Transformierer eingeführt
* 
****************************************************************************/
#include "OklabiMgd.h"
#include "CS_EingabeKonverter.h"
#include "Umgebung.h"

using namespace Oklabi;
using namespace std;

CS_EingabeKonverter::CS_EingabeKonverter()
: m_pCallbackLade(0),
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

CS_EingabeKonverter::~CS_EingabeKonverter()
{
}

Text CS_EingabeKonverter::GibKlassenname() const
{
	return "CS_EingabeKonverter";
}

EingabeKonverter* CS_EingabeKonverter::Erzeuge()
{
	return new CS_EingabeKonverter();
}

Datenbestand* CS_EingabeKonverter::Lade(Objektartfilter* pFilter, Objektartfilter* pSymbol)
{
	if (m_pCallbackLade)
	{
		return m_pCallbackLade(pFilter, pSymbol);
	}
	return NULL;
}

void CS_EingabeKonverter::TransportiereErweiterungen(bool f)
{
	if (m_pCallbackTransportiereErweiterungen)
	{
		m_pCallbackTransportiereErweiterungen(f);
	}
}

void CS_EingabeKonverter::SetzeProfilerkennung(bool f)
{
	if (m_pCallbackSetzeProfilerkennung)
	{
		m_pCallbackSetzeProfilerkennung(f);
	}
}

void CS_EingabeKonverter::Transformiere(eKoordRefSys f)
{
	m_eTargetSRS = f;
	if (m_pCallbackTransformiere)
	{
		m_pCallbackTransformiere(f);
	}
}

Version* CS_EingabeKonverter::GibVersion()
{
	if (m_pCallbackGibVersion)
	{
		return m_pCallbackGibVersion();
	}
	return NULL;
}

FblVersion* CS_EingabeKonverter::GibFblVersion()
{
	if (m_pCallbackGibFblVersion)
	{
		return m_pCallbackGibFblVersion();
	}
	return NULL;
}

TextListe CS_EingabeKonverter::GibMetadaten(eMetadaten m)
{
	if (m_pCallbackGibMetadaten)
	{
		TextListe* pListe = m_pCallbackGibMetadaten(m);
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

bool CS_EingabeKonverter::E_FSSchemaIdentifiers(TextListe& dumy)
{
	return false;
}

TextListe CS_EingabeKonverter::GibObjektarten()
{
	if (m_pCallbackGibObjektarten)
	{
		TextListe* pListe = m_pCallbackGibObjektarten();
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

size_t CS_EingabeKonverter::GibAnzahlObjekte(const Oklabi::Text& strOA)
{
	if (m_pCallbackGibAnzahlObjekte)
	{
		return m_pCallbackGibAnzahlObjekte(strOA);
	}
	return 0;
}

void CS_EingabeKonverter::VerschmelzeSymbolischeObjekte(bool bFlag)
{
	m_bMerge = bFlag;
	if (m_pCallbackVerschmelzeSymbolischeObjekte)
	{
		m_pCallbackVerschmelzeSymbolischeObjekte(bFlag);
	}
}

// Identitätswechsel beim symbolischen Laden
void CS_EingabeKonverter::Identitaetswechsel(FachobjektPtr p1, FachobjektPtr p2, const Text& kenn)
{
}

void CALLBACK SetzeCallbackEingabeKonverterCS(void* pObj,
	Datenbestand* (CALLBACK* fctLade)(Objektartfilter*, Objektartfilter*),
	Version* (CALLBACK* fctGibVersion)(),
	void (CALLBACK* fctTransportiereErweiterungen)(bool),
	void (CALLBACK* fctVerschmelzeSymbolischeObjekte)(bool),
	void (CALLBACK* fctSetzeProfilerkennung)(bool),
	void (CALLBACK* fctTransformiere)(eKoordRefSys),
	TextListe* (CALLBACK* fctGibMetadaten)(eMetadaten),
	FblVersion* (CALLBACK* fctGibFblVersion)(),
	TextListe* (CALLBACK* fctGibObjektarten)(),
	size_t (CALLBACK* fctGibAnzahlObjekte)(const Text&))
{
	if (pObj)
	{
		CS_EingabeKonverter* pIcv = (CS_EingabeKonverter*)pObj;
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
