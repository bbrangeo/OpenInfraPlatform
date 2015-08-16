/*****************************************************************************
* $Id: Logging.h 2012-10-08 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
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
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFLogging
#define DEFLogging

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"

#ifdef OKLABI_LOGGING
namespace Oklabi
{
	class Logging : public OklabiRoot
	{
	public:
		Logging(int level, int line, const char*);
		~Logging();
	private:
		size_t m_nTicks;
		int m_nLevel;
		int m_nLineNo;
	};

	class OKLABI_API LoggingConditional : public OklabiRoot
	{
	public:
		LoggingConditional(int level, int line, const char*);
		~LoggingConditional();
	private:
		Logging* m_pLogging;
	};
}// End of namespace Oklabi

#define LOGGING(level,description) LoggingConditional _LOG(level, (__LINE__), description);
#ifdef OKLABI_LOGGING_SCHEMA
#define LOGGING_SCHEMA(level,description) LoggingConditional _LOG(level, (__LINE__), description);
#else
#define LOGGING_SCHEMA(level,description) 
#endif
#else
#define LOGGING(level,description) 
#define LOGGING_SCHEMA(level,description) 
#endif

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFLogging
