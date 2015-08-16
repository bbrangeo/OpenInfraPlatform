/*****************************************************************************
* $Id: J_Protokollant.h 2012-10-15 15:00:00 vogelsang $
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
#ifndef DEFJ_Protokollant
#define DEFJ_Protokollant

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "Protokollant.h"

namespace Oklabi
{
	typedef void (CALLBACK* pProtokollant)(void*, void*, const char*, const char*, int mnr, const Oklabi::Text& text, Oklabi::eMeldTyp typ);
	class OKLABIUTIL_API J_Protokollant : public Protokollant, public OklabiJava
	{
		friend class OklabiJava;
	private:
		J_Protokollant(void* JNIEnv, void* JOBJECT);
		~J_Protokollant();
		static void Registriere();
	public:
		static Protokollant* Erzeuge(void* JNIEnv, void* JOBJECT);
		Text GibKlassenname() const;
		Text GibBeschreibung() const;

		void Melde( int nr, const Text& str, eMeldTyp m );

		pProtokollant m_pCallbackProtokollant;
	};
}// End of namespace Oklabi

#endif	// DEFJ_Protokollant
