/*****************************************************************************
* $Id: CS_AusgabeKonverter.h 2013-02-04 15:00:00 vogelsang $
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
* 2013-02-04 Profile
* 
****************************************************************************/
#ifndef DEFCS_AusgabeKonverter
#define DEFCS_AusgabeKonverter

#include "OklabiUtil.h"
#include "OklabiManaged.h"
#include "OklabiKern.h"
#include "AusgabeKonverter.h"

namespace Oklabi
{
	typedef void (CALLBACK* pAusgabeKonverterEntlade)(Datenbestand*);
	typedef void (CALLBACK* pAusgabeKonverterSetzeSortierung)(eSort);
	typedef void (CALLBACK* pAusgabeKonverterTransportiereErweiterungen)(bool);
	typedef void (CALLBACK* pAusgabeKonverterSetzeProfilerkennung)(bool);
	typedef void (CALLBACK* pAusgabeKonverterSetzeMetadaten)(eMetadaten, const Text&);
	typedef void (CALLBACK* pAusgabeKonverterSetzeFblVersion)(const FblVersion*);
	typedef void (CALLBACK* pAusgabeKonverterKomprimiere)(bool);
	typedef void (CALLBACK* pAusgabeKonverterKonkordanzSetzen)(Oklabi::Ausgabe*, const Oklabi::Text&, const Oklabi::Text&, const Oklabi::Text&);
	class CS_AusgabeKonverter : public AusgabeKonverter, public OklabiManaged
	{
	private:
		OKLABIUTIL_API CS_AusgabeKonverter();
		OKLABIUTIL_API ~CS_AusgabeKonverter();
		void OKLABIUTIL_API KonkordanzSetzen(Oklabi::Ausgabe* pDatei, const char* pFieldDelimit, const char* pStringDelimit, const char* pIdPrefix);
	public:
		static OKLABIUTIL_API AusgabeKonverter* Erzeuge();
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

#endif	// DEFCS_AusgabeKonverter
