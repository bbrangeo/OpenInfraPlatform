/*****************************************************************************
* $Id: J_Ausgabe.h 2013-01-24 15:00:00 vogelsang $
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
* 2011-10-31 Cross Language Calls
* 2012-10-15 Aufräumen bei Programmende
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFJ_Ausgabe
#define DEFJ_Ausgabe

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "Ausgabe.h"

namespace Oklabi
{
	typedef void (CALLBACK* pVoid)(void*, void*, const char*, const char*);
	typedef void (CALLBACK* pAInt)(void*, void*, const char*, const char*, int);
	typedef void (CALLBACK* pAKod)(void*, void*, const char*, const char*, eKodierung);
	class OKLABIUTIL_API J_Ausgabe : public Ausgabe, public OklabiJava
	{
		friend class OklabiJava;
	private:
		J_Ausgabe(void* JNIEnv, void* JOBJECT);
		~J_Ausgabe();
		static void Registriere();
	public:
		static Ausgabe*    Erzeuge(void* JNIEnv, void* JOBJECT);
		Text               GibKlassenname() const;
		Text               GibBeschreibung() const;

		void               Oeffne();
		void               Schliesse();
		void               SchreibeZeichen(const int&);
		void               SchreibeZeile(const Text&);
		void               SetzeKodierung(eKodierung);
		void               Leere();

		pVoid              m_pCallbackAusgabeOeffne;
		pVoid              m_pCallbackAusgabeSchliesse;
		pAInt              m_pCallbackAusgabeSchreibeZeichen;
		pVoid              m_pCallbackAusgabeLeere;
		pAKod              m_pCallbackAusgabeSetzeKodierung;
	};
}// End of namespace Oklabi

#endif	// DEFJ_Ausgabe
