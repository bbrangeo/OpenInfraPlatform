/*****************************************************************************
* $Id: Schema.h 2012-10-15 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
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
* 2010-08-24 SchemaEnumerator erg�nzt
* 2011-10-14 Schnittstelle �berarbeitet
* 2012-10-15 Aufr�umen bei Programmende
* 
****************************************************************************/
#ifndef DEFSchema
#define DEFSchema

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#ifdef OKLABI_LOGGING_SCHEMA
#undef OKLABI_LOGGING_SCHEMA
#endif

#ifdef OKLABI_STATISTIK_SCHEMA
#undef OKLABI_STATISTIK_SCHEMA
#endif

#ifdef OKLABI_LOGGING
#define OKLABI_LOGGING_SCHEMA
#else
#undef OKLABI_LOGGING_SCHEMA
#endif

#ifdef OKLABI_STATISTIK
#define OKLABI_STATISTIK_SCHEMA
#else
#undef OKLABI_STATISTIK_SCHEMA
#endif

#include "Objektart.h"
#include "Eigenschaft.h"
#include "Reflection.h"
#include "BoundingBox.h"
#include "Geometrie.h"
#include "Logging.h"
#include "Statistik.h"
#include "Ausnahme.h"

namespace Oklabi
{
	class Schema : public Reflection
	{
		friend class Reflection;
		friend class Umgebung;
		friend class Schema1;
		friend class Schema2;
		friend class Schema3;
	private:
		static void ReInit();
		static void LazyInit();
		static void Finalisiere();
		static Text GibExpressVersion();
		static void GibKlassenZuSchema(const Version&, const Text&, TextListe&);
		static Text testSchema( const Version&, const char*);
		static bool testObjektart(const Text&, const Text&, const Version&);
	public:
		static void GibSchemata(const Version&, TextListe&);
	};
} // Namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFSchema
