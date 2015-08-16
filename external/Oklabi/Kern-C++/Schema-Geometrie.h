/*****************************************************************************
* $Id: Schema-Geometrie.h 2010-04-30 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010, Bundesanstalt für Straßenwesen
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
* 
****************************************************************************/
#ifndef DEFSchemaGeometrie
#define DEFSchemaGeometrie

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "Objektart.h"
#include "Eigenschaft.h"
#include "Reflection.h"
#include "BoundingBox.h"
#include "Geometrie.h"
#include "Logging.h"
#include "Statistik.h"
#include "Ausnahme.h"

#ifdef OKLABI_LOGGING_SCHEMA
#undef OKLABI_LOGGING_SCHEMA
#endif

#ifdef OKLABI_STATISTIK_SCHEMA
#undef OKLABI_STATISTIK_SCHEMA
#endif

#ifdef OKLABI_LOGGING
//#define OKLABI_LOGGING_SCHEMA
#else
#undef OKLABI_LOGGING_SCHEMA
#endif

#ifdef OKLABI_STATISTIK
#define OKLABI_STATISTIK_SCHEMA
#else
#undef OKLABI_STATISTIK_SCHEMA
#endif

namespace Oklabi
{
	class SchemaGeoWrapper : public Reflection
	{
		friend class Reflection;
	private:
		static void LazyInit();
	};
} // Namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFSchemaGeometrie
