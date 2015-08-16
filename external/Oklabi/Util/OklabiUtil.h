/*****************************************************************************
* $Id: OklabiUtil.h 2011-10-31 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2011, Bundesanstalt für Straßenwesen
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
* 
****************************************************************************/
#ifndef DEFOklabiUtil
#define DEFOklabiUtil
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the OKLABIUTIL_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// OKLABIUTIL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#if defined(WIN32)
#ifdef OKLABIUTIL_EXPORTS
#define OKLABIUTIL_API __declspec(dllexport)
#else
#define OKLABIUTIL_API __declspec(dllimport)
#endif
#else // defined(WIN32)
#define OKLABIUTIL_API 
#define CALLBACK 
#endif

namespace Oklabi
{
	class OklabiUtil
	{
	public:
		OKLABIUTIL_API bool IstJavaObjekt() const;
		OKLABIUTIL_API bool IstManagedObjekt() const;
	protected:
		OKLABIUTIL_API OklabiUtil();
		virtual OKLABIUTIL_API ~OklabiUtil();
	};
}// namespace Oklabi

#endif // DEFOklabiUtil
