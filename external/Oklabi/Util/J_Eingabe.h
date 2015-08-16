/*****************************************************************************
* $Id: J_Eingabe.h 2013-01-24 15:00:00 vogelsang $
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
* 2012-07-27 Interface umbenannt
* 2012-10-15 Aufräumen bei Programmende
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFJ_Eingabe
#define DEFJ_Eingabe

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "Eingabe.h"

namespace Oklabi
{
	typedef void (CALLBACK* pVoid)(void*, void*, const char*, const char*);
	typedef bool (CALLBACK* pBool)(void*, void*, const char*, const char*);
	typedef int (CALLBACK* pEInt)(void*, void*, const char*, const char*);
	typedef void (CALLBACK* pEKod)(void*, void*, const char*, const char*, eKodierung);
	class OKLABIUTIL_API J_Eingabe : public Eingabe, public OklabiJava
	{
		friend class OklabiJava;
	private:
		J_Eingabe(void* JNIEnv, void* JOBJECT);
		~J_Eingabe();
		static void Registriere();
	public:
		static Eingabe*    Erzeuge(void* JNIEnv, void* JOBJECT);
		Text               GibKlassenname() const;
		Text               GibBeschreibung() const;

		void               Oeffne();
		void               Schliesse();
		int                LiesZeichen();
		size_t             GibAnzahl();
		size_t             GibZeilen();
		bool               IstBeendet();
		void               SetzeKodierung(eKodierung);
		bool               IstGueltig();
		void               ZumAnfang();

		pVoid              m_pCallbackEingabeOeffne;
		pVoid              m_pCallbackEingabeSchliesse;
		pEInt              m_pCallbackEingabeLiesZeichen;
		pEInt              m_pCallbackEingabeGibAnzahl;
		pBool              m_pCallbackEingabeIstBeendet;
		pBool              m_pCallbackEingabeIstGueltig;
		pVoid              m_pCallbackEingabeZumAnfang;
		pEKod              m_pCallbackEingabeSetzeKodierung;
	};
}// End of namespace Oklabi

#endif	// DEFJ_Eingabe
