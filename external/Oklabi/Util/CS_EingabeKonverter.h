/*****************************************************************************
* $Id: CS_EingabeKonverter.h 2013-11-18 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt f�r Stra�enwesen
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
* 2010-12-14 Vorschau auf Eingabedaten
* 2011-10-31 Cross Language Calls
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2013-02-04 Profile
* 2013-11-18 Transformierer eingef�hrt
* 
****************************************************************************/
#ifndef DEFCS_EingabeKonverter
#define DEFCS_EingabeKonverter

#include "OklabiUtil.h"
#include "OklabiManaged.h"
#include "OklabiKern.h"
#include "EingabeKonverter.h"

namespace Oklabi
{
	typedef Datenbestand* (CALLBACK* pEingabeKonverterLade)(Objektartfilter*, Objektartfilter*);
	typedef void (CALLBACK* pEingabeKonverterTransportiereErweiterungen)(bool);
	typedef void (CALLBACK* pEingabeKonverterVerschmelzeSymbolischeObjekte)(bool);
	typedef void (CALLBACK* pEingabeKonverterSetzeProfilerkennung)(bool);
	typedef void (CALLBACK* pEingabeKonverterTransformiere)(eKoordRefSys);
	typedef TextListe* (CALLBACK* pEingabeKonverterGibMetadaten)(eMetadaten);
	typedef FblVersion* (CALLBACK* pEingabeKonverterGibFblVersion)();
	typedef Version* (CALLBACK* pEingabeKonverterGibVersion)();
	typedef TextListe* (CALLBACK* pEingabeKonverterGibObjektarten)();
	typedef size_t (CALLBACK* pEingabeKonverterGibAnzahlObjekte)(const Text&);
	class OKLABIUTIL_API CS_EingabeKonverter : public EingabeKonverter, public OklabiManaged
	{
	private:
		CS_EingabeKonverter();
		~CS_EingabeKonverter();
		bool E_FSSchemaIdentifiers(TextListe&);
	protected:
		void Identitaetswechsel(FachobjektPtr, FachobjektPtr, const Text&);
	public:
		static EingabeKonverter* Erzeuge();
		Text                     GibKlassenname() const;
		Datenbestand*            Lade(Objektartfilter* = 0, Objektartfilter* = 0);
		void                     TransportiereErweiterungen(bool = false);
		void                     VerschmelzeSymbolischeObjekte(bool = true);
		Version*                 GibVersion();
		FblVersion*              GibFblVersion();
		TextListe                GibMetadaten(eMetadaten);
		TextListe                GibObjektarten();
		size_t                   GibAnzahlObjekte(const Text&);
		void                     SetzeProfilerkennung(bool = true);
		void                     Transformiere(eKoordRefSys);

		pEingabeKonverterLade                          m_pCallbackLade;
		pEingabeKonverterTransportiereErweiterungen    m_pCallbackTransportiereErweiterungen;
		pEingabeKonverterVerschmelzeSymbolischeObjekte m_pCallbackVerschmelzeSymbolischeObjekte;
		pEingabeKonverterSetzeProfilerkennung          m_pCallbackSetzeProfilerkennung;
		pEingabeKonverterTransformiere                 m_pCallbackTransformiere;
		pEingabeKonverterGibMetadaten                  m_pCallbackGibMetadaten;
		pEingabeKonverterGibFblVersion                 m_pCallbackGibFblVersion;
		pEingabeKonverterGibVersion                    m_pCallbackGibVersion;
		pEingabeKonverterGibObjektarten                m_pCallbackGibObjektarten;
		pEingabeKonverterGibAnzahlObjekte              m_pCallbackGibAnzahlObjekte;
	};
}// End of namespace Oklabi

#endif	// DEFCS_EingabeKonverter
