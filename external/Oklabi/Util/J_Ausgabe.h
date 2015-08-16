/*****************************************************************************
* $Id: J_Ausgabe.h 2013-01-24 15:00:00 vogelsang $
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
* 2011-10-31 Cross Language Calls
* 2012-10-15 Aufr�umen bei Programmende
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
