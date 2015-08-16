/*****************************************************************************
* $Id: OklabiJava.h 2012-10-15 15:00:00 vogelsang $
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
#ifndef DEFOklabiFct
#define DEFOklabiFct

#include <map>
#include <string>
#include "OklabiUtil.h"
#include "OklabiMixed.h"

namespace Oklabi
{
	typedef void* (CALLBACK* pJErzeugeFunktion)(void* JNIEnv, void* JOBJECT);
	typedef std::map< std::string, pJErzeugeFunktion > ErzeugeFunktionMapType;
	class OklabiJava : public OklabiMixed
	{
	public:
		static OKLABIUTIL_API bool Registriere(const char*, pJErzeugeFunktion);
		static OKLABIUTIL_API pJErzeugeFunktion GibErzeugeFunktion(const char*);
		OKLABIUTIL_API void SetzeJavaObjekt(void*);
		OKLABIUTIL_API void* GibJavaObjekt();
	protected:
		OKLABIUTIL_API OklabiJava(void* JNIEnv, void* JOBJECT);
		virtual OKLABIUTIL_API ~OklabiJava();
		void* m_JNIEnv;
		void* m_JOBJECT;
	private:
		static ErzeugeFunktionMapType* m_pmapErzFkt;
		static OKLABIUTIL_API int finalize();
		static OKLABIUTIL_API bool intialize();
	};
}// namespace Oklabi
#endif // DEFOklabiFct
