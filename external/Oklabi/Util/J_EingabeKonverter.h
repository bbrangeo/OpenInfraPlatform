/*****************************************************************************
* $Id: J_EingabeKonverter.h 2013-11-18 15:00:00 vogelsang $
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
* 2010-12-14 Vorschau auf Eingabedaten
* 2011-10-31 Cross Language Calls
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2012-10-15 Aufräumen bei Programmende
* 2013-02-04 Profile
* 2013-11-18 Transformierer eingeführt
* 
****************************************************************************/
#ifndef DEFJ_EingabeKonverter
#define DEFJ_EingabeKonverter

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "EingabeKonverter.h"

namespace Oklabi
{
	typedef Datenbestand* (CALLBACK* pEingabeKonverterLade)(void*, void*, const char*, const char*, Objektartfilter*, Objektartfilter*);
	typedef void (CALLBACK* pEingabeKonverterTransportiereErweiterungen)(void*, void*, const char*, const char*, bool);
	typedef void (CALLBACK* pEingabeKonverterVerschmelzeSymbolischeObjekte)(void*, void*, const char*, const char*, bool);
	typedef void (CALLBACK* pEingabeKonverterSetzeProfilerkennung)(void*, void*, const char*, const char*, bool);
	typedef void (CALLBACK* pEingabeKonverterTransformiere)(void*, void*, const char*, const char*, eKoordRefSys);
	typedef TextListe* (CALLBACK* pEingabeKonverterGibMetadaten)(void*, void*, const char*, const char*, eMetadaten);
	typedef FblVersion* (CALLBACK* pEingabeKonverterGibFblVersion)(void*, void*, const char*, const char*);
	typedef Version* (CALLBACK* pEingabeKonverterGibVersion)(void*, void*, const char*, const char*);
	typedef TextListe* (CALLBACK* pEingabeKonverterGibObjektarten)(void*, void*, const char*, const char*);
	typedef size_t (CALLBACK* pEingabeKonverterGibAnzahlObjekte)(void*, void*, const char*, const char*, const Text&);
	class OKLABIUTIL_API J_EingabeKonverter : public EingabeKonverter, public OklabiJava
	{
		friend class OklabiJava;
	private:
		J_EingabeKonverter(void* JNIEnv, void* JOBJECT);
		~J_EingabeKonverter();
		bool E_FSSchemaIdentifiers(TextListe&);
		static void Registriere();
	protected:
		void Identitaetswechsel(FachobjektPtr, FachobjektPtr, const Text&);
	public:
		static EingabeKonverter* Erzeuge(void* JNIEnv, void* JOBJECT);
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

#endif	// DEFJ_EingabeKonverter
