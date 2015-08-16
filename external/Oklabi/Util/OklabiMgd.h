/*****************************************************************************
* $Id: OklabiMgd.h 2013-11-18 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2014, Bundesanstalt für Straßenwesen
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
* 2011-05-03 Formale Verbesserungen
* 2011-05-10 Normierte Ausgabe
* 2011-10-31 Cross Language Calls
* 2012-07-27 Interface umbenannt
* 2013-01-24 Zeichenkodierung
* 2013-02-04 Profile
* 2013-11-18 Transformierer eingeführt
* 
****************************************************************************/
#ifndef DEFOklabiMgd
#define DEFOklabiMgd

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "Datenbestand.h"
#include "OklabiJava.h"

extern "C"
{
	OKLABIUTIL_API void CALLBACK SetzeCallbackFortschrittswaechterCS(bool, void* pObj,
		void (CALLBACK* fct)(int p, Oklabi::eFortTyp typ));
	OKLABIUTIL_API void CALLBACK SetzeCallbackProtokollantCS(void* pObj,
		void (CALLBACK* fct)(int p, const Oklabi::Text& text, Oklabi::eMeldTyp typ));
	OKLABIUTIL_API void CALLBACK SetzeCallbackAbbruchsignalCS(void* pObj,
		bool (CALLBACK* fct)());
	OKLABIUTIL_API void CALLBACK SetzeCallbackEingabeCS(void* pObj,
		void (CALLBACK* fctOeffne)(),
		void (CALLBACK* fctSchliesse)(),
		int  (CALLBACK* fctLiesZeichen)(),
		int  (CALLBACK* fctGibAnzahl)(),
		bool (CALLBACK* fctIstBeendet)(),
		bool (CALLBACK* fctIstGueltig)(),
		void (CALLBACK* fctZumAnfang)(),
		void (CALLBACK* fctSetzeKodierung)(Oklabi::eKodierung));
	OKLABIUTIL_API void CALLBACK SetzeCallbackAusgabeCS(void* pObj,
		void (CALLBACK* fctOeffne)(),
		void (CALLBACK* fctSchliesse)(),
		void (CALLBACK* fctSchreibeZeichen)(const int&),
		void (CALLBACK* fctLeere)(),
		void (CALLBACK* fctSetzeKodierung)(Oklabi::eKodierung));
	OKLABIUTIL_API void CALLBACK SetzeCallbackAusgabeKonverterCS(void* pObj,
		void (CALLBACK* fctEntlade)(Oklabi::Datenbestand*),
		void (CALLBACK* fctSetzeSortierung)(Oklabi::eSort),
		void (CALLBACK* fctTransportiereErweiterungen)(bool),
		void (CALLBACK* fctSetzeProfilerkennung)(bool),
		void (CALLBACK* fctKomprimiere)(bool),
		void (CALLBACK* fctSetzeMetadaten)(Oklabi::eMetadaten, const Oklabi::Text&),
		void (CALLBACK* fctSetzeFblVersion)(const Oklabi::FblVersion*),
		void (CALLBACK* fctKonkordanzSetzen)(Oklabi::Ausgabe*, const Oklabi::Text&, const Oklabi::Text&, const Oklabi::Text&));
	OKLABIUTIL_API void CALLBACK SetzeCallbackEingabeKonverterCS(void* pObj,
		Oklabi::Datenbestand* (CALLBACK* fctLade)(Oklabi::Objektartfilter*, Oklabi::Objektartfilter*),
		Oklabi::Version* (CALLBACK* fctGibVersion)(),
		void (CALLBACK* fctTransportiereErweiterungen)(bool),
		void (CALLBACK* fctVerschmelzeSymbolischeObjekte)(bool),
		void (CALLBACK* fctSetzeProfilerkennung)(bool),
		void (CALLBACK* fctTransformiere)(Oklabi::eKoordRefSys),
		Oklabi::TextListe* (CALLBACK* fctGibMetadaten)(Oklabi::eMetadaten),
		Oklabi::FblVersion* (CALLBACK* fctGibFblVersion)(),
		Oklabi::TextListe* (CALLBACK* fctGibObjektarten)(),
		size_t (CALLBACK* fctGibAnzahlObjekte)(const Oklabi::Text&));
	OKLABIUTIL_API void CALLBACK SetzeCallbackTransformiererCS(void* pObj,
		bool (CALLBACK* fctTransform)(Oklabi::Koordinate&, Oklabi::eKoordRefSys),
		bool (CALLBACK* fctSRS)(Oklabi::eKoordRefSys));

	OKLABIUTIL_API void SetzeCallbackFortschrittswaechterJava(void* pObj,
		void (CALLBACK* fct)(void*, void*, const char*, const char*, int p, Oklabi::eFortTyp typ));
	OKLABIUTIL_API void SetzeCallbackProtokollantJava(void* pObj,
		void (CALLBACK* fct)(void*, void*, const char*, const char*, int p, const Oklabi::Text& text, Oklabi::eMeldTyp typ));
	OKLABIUTIL_API void SetzeCallbackAbbruchsignalJava(void* pObj,
		bool (CALLBACK* fct)(void*, void*, const char*, const char*));
	OKLABIUTIL_API void SetzeCallbackEingabeJava(void* pObj,
		void (CALLBACK* fctOeffne)(void*, void*, const char*, const char*),
		void (CALLBACK* fctSchliesse)(void*, void*, const char*, const char*),
		int  (CALLBACK* fctLiesZeichen)(void*, void*, const char*, const char*),
		int  (CALLBACK* fctGibAnzahl)(void*, void*, const char*, const char*),
		bool (CALLBACK* fctIstBeendet)(void*, void*, const char*, const char*),
		bool (CALLBACK* fctIstGueltig)(void*, void*, const char*, const char*),
		void (CALLBACK* fctZumAnfang)(void*, void*, const char*, const char*),
		void (CALLBACK* fctSetzeKodierung)(void*, void*, const char*, const char*, Oklabi::eKodierung));
	OKLABIUTIL_API void SetzeCallbackAusgabeJava(void* pObj,
		void (CALLBACK* fctOeffne)(void*, void*, const char*, const char*),
		void (CALLBACK* fctSchliesse)(void*, void*, const char*, const char*),
		void (CALLBACK* fctSchreibeZeichen)(void*, void*, const char*, const char*, int),
		void (CALLBACK* fctLeere)(void*, void*, const char*, const char*),
		void (CALLBACK* fctSetzeKodierung)(void*, void*, const char*, const char*, Oklabi::eKodierung));
	OKLABIUTIL_API void SetzeCallbackAusgabeKonverterJava(void* pObj,
		void (CALLBACK* fctEntlade)(void*, void*, const char*, const char*, Oklabi::Datenbestand*),
		void (CALLBACK* fctSetzeSortierung)(void*, void*, const char*, const char*, Oklabi::eSort),
		void (CALLBACK* fctTransportiereErweiterungen)(void*, void*, const char*, const char*, bool),
		void (CALLBACK* fctSetzeProfilerkennung)(void*, void*, const char*, const char*, bool),
		void (CALLBACK* fctSetzeMetadaten)(void*, void*, const char*, const char*, Oklabi::eMetadaten, const Oklabi::Text&),
		void (CALLBACK* fctSetzeFblVersion)(void*, void*, const char*, const char*, const Oklabi::FblVersion*),
		void (CALLBACK* fctKomprimiere)(void*, void*, const char*, const char*, bool),
		void (CALLBACK* fctKonkordanzSetzen)(void*, void*, const char*, const char*, Oklabi::Ausgabe*, const Oklabi::Text&, const Oklabi::Text&, const Oklabi::Text&));
	OKLABIUTIL_API void SetzeCallbackEingabeKonverterJava(void* pObj,
		Oklabi::Datenbestand* (CALLBACK* fctLade)(void*, void*, const char*, const char*, Oklabi::Objektartfilter*, Oklabi::Objektartfilter*),
		Oklabi::Version* (CALLBACK* fctGibVersion)(void*, void*, const char*, const char*),
		void (CALLBACK* fctTransportiereErweiterungen)(void*, void*, const char*, const char*, bool),
		void (CALLBACK* fctVerschmelzeSymbolischeObjekte)(void*, void*, const char*, const char*, bool),
		void (CALLBACK* fctSetzeProfilerkennung)(void*, void*, const char*, const char*, bool),
		void (CALLBACK* fctTransformiere)(void*, void*, const char*, const char*, Oklabi::eKoordRefSys),
		Oklabi::TextListe* (CALLBACK* fctGibMetadaten)(void*, void*, const char*, const char*, Oklabi::eMetadaten),
		Oklabi::FblVersion* (CALLBACK* fctGibFblVersion)(void*, void*, const char*, const char*),
		Oklabi::TextListe* (CALLBACK* fctGibObjektarten)(void*, void*, const char*, const char*),
		size_t (CALLBACK* fctGibAnzahlObjekte)(void*, void*, const char*, const char*, const Oklabi::Text&));
	OKLABIUTIL_API void CALLBACK SetzeCallbackTransformiererJava(void* pObj,
		bool (CALLBACK* fctTransform)(void*, void*, const char*, const char*, Oklabi::Koordinate&, Oklabi::eKoordRefSys),
		bool (CALLBACK* fctSRS)(void*, void*, const char*, const char*, Oklabi::eKoordRefSys));
}
#endif // DEFOklabiMgd
