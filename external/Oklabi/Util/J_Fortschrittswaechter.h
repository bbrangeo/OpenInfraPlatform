/*****************************************************************************
* $Id: J_Fortschrittswaechter.h 2012-10-15 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt für Straßenwesen
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
* 
****************************************************************************/
#ifndef DEFJ_Fortschrittswaechter
#define DEFJ_Fortschrittswaechter

#include "OklabiUtil.h"
#include "OklabiKern.h"
#include "Fortschrittswaechter.h"

namespace Oklabi
{
	typedef void (CALLBACK* pJFortschrittswaechter)(void*, void*, const char*, const char*, int p, Oklabi::eFortTyp typ);
	class OKLABIUTIL_API J_Fortschrittswaechter : public Fortschrittswaechter, public OklabiJava
	{
		friend class OklabiJava;
	private:
		J_Fortschrittswaechter(void* JNIEnv, void* JOBJECT);
		~J_Fortschrittswaechter();
		static void Registriere();
	public:
		static Fortschrittswaechter* Erzeuge(void* JNIEnv, void* JOBJECT);
		Text GibKlassenname() const;
		Text GibBeschreibung() const;

		void Melde(int p, Oklabi::eFortTyp t);

		pJFortschrittswaechter m_pCallbackFortschrittswaechter;
	};
}// End of namespace Oklabi

#endif	// DEFJ_Fortschrittswaechter
