/*****************************************************************************
* $Id: OklabiJava.h 2012-10-15 15:00:00 vogelsang $
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
