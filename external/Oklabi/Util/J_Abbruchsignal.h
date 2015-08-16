/*****************************************************************************
* $Id: J_Abbruchsignal.h 2012-10-15 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt f�r Stra�enwesen
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
* 
****************************************************************************/
#ifndef DEFJ_Abbruchsignal
#define DEFJ_Abbruchsignal

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "OklabiJava.h"
#include "Abbruchsignal.h"

namespace Oklabi
{
	typedef bool (CALLBACK* pBool)(void*, void*, const char*, const char*);
	class OKLABIUTIL_API J_Abbruchsignal : public Abbruchsignal, public OklabiJava
	{
		friend class OklabiJava;
	private:
		J_Abbruchsignal(void* JNIEnv, void* JOBJECT);
		~J_Abbruchsignal();
		static void Registriere();
	public:
		static Abbruchsignal* Erzeuge(void* JNIEnv, void* JOBJECT);
		Text GibKlassenname() const;
		Text GibBeschreibung() const;

		bool Empfange();

		pBool m_pCallbackAbbruchsignal;
	};
}// End of namespace Oklabi

#endif	// DEFJ_Abbruchsignal
