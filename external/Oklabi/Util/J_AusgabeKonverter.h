/*****************************************************************************
* $Id: J_AusgabeKonverter.h 2013-02-04 15:00:00 vogelsang $
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
* 2011-05-10 Normierte Ausgabe
* 2011-10-31 Cross Language Calls
* 2012-10-15 Aufräumen bei Programmende
* 2013-02-04 Profile
* 
****************************************************************************/
#ifndef DEFJ_AusgabeKonverter
#define DEFJ_AusgabeKonverter

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "AusgabeKonverter.h"

namespace Oklabi
{
	typedef void (CALLBACK* pAusgabeKonverterEntlade)(void*, void*, const char*, const char*, Datenbestand*);
	typedef void (CALLBACK* pAusgabeKonverterSetzeSortierung)(void*, void*, const char*, const char*, eSort);
	typedef void (CALLBACK* pAusgabeKonverterTransportiereErweiterungen)(void*, void*, const char*, const char*, bool);
	typedef void (CALLBACK* pAusgabeKonverterSetzeProfilerkennung)(void*, void*, const char*, const char*, bool);
	typedef void (CALLBACK* pAusgabeKonverterKomprimiere)(void*, void*, const char*, const char*, bool);
	typedef void (CALLBACK* pAusgabeKonverterSetzeMetadaten)(void*, void*, const char*, const char*, eMetadaten, const Text&);
	typedef void (CALLBACK* pAusgabeKonverterSetzeFblVersion)(void*, void*, const char*, const char*, const FblVersion*);
	typedef void (CALLBACK* pAusgabeKonverterKonkordanzSetzen)(void*, void*, const char*, const char*, Oklabi::Ausgabe*, const Oklabi::Text&, const Oklabi::Text&, const Oklabi::Text&);
	class J_AusgabeKonverter : public AusgabeKonverter, public OklabiJava
	{
		friend class OklabiJava;
	private:
		OKLABIUTIL_API J_AusgabeKonverter(void* JNIEnv, void* JOBJECT);
		OKLABIUTIL_API ~J_AusgabeKonverter();
		static void Registriere();
	protected:
		void OKLABIUTIL_API KonkordanzSetzen(Oklabi::Ausgabe* pDatei, const char* pFieldDelimit, const char* pStringDelimit, const char* pIdPrefix);
	public:
		static OKLABIUTIL_API AusgabeKonverter* Erzeuge(void* JNIEnv, void* JOBJECT);
		Text OKLABIUTIL_API GibKlassenname() const;
		void OKLABIUTIL_API Entlade(Datenbestand*);
		void OKLABIUTIL_API SetzeSortierung(eSort = ohne);
		void OKLABIUTIL_API TransportiereErweiterungen(bool = false);
		void OKLABIUTIL_API SetzeMetadaten(eMetadaten, const Text&);
		void OKLABIUTIL_API SetzeFblVersion(const FblVersion*);
		void OKLABIUTIL_API Komprimiere(bool);
		void OKLABIUTIL_API SetzeProfilerkennung(bool = true);

		pAusgabeKonverterEntlade                    m_pCallbackEntlade;
		pAusgabeKonverterSetzeSortierung            m_pCallbackSetzeSortierung;
		pAusgabeKonverterTransportiereErweiterungen m_pCallbackTransportiereErweiterungen;
		pAusgabeKonverterSetzeProfilerkennung       m_pCallbackSetzeProfilerkennung;
		pAusgabeKonverterSetzeMetadaten             m_pCallbackSetzeMetadaten;
		pAusgabeKonverterSetzeFblVersion            m_pCallbackSetzeFblVersion;
		pAusgabeKonverterKomprimiere                m_pCallbackKomprimiere;
		pAusgabeKonverterKonkordanzSetzen           m_pCallbackKonkordanz;
	};
}// End of namespace Oklabi

#endif	// DEFJ_AusgabeKonverter
