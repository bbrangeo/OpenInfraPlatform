/*****************************************************************************
* $Id: Statistik.h 2012-10-08 15:00:00 vogelsang $
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

#ifndef DEFStatistik
#define DEFStatistik

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#ifdef OKLABI_STATISTIK

#include "OklabiKern.h"

namespace Oklabi
{
	class OKLABI_API Statistik : public OklabiRoot
	{
		friend class Umgebung;
	public:
		static void Registriere(size_t pos, const char*, int level, const char*);
		Statistik(size_t pos, const char*, int level, const char*);
		~Statistik();
	private:
		static void Report(int level = 3);
	};
}// End of namespace Oklabi
#define LINENR __LINE__
#define STATISTIK(level,position) if (OklabiObjekt::GibStatistik()) { Statistik _ST(LINENR, __FILE__, level, position); }
#define CONCAT(prf,sep,num) prf ## sep ## num
#define STATISTIK_ENTRY(linenr,offset,level,position) static Statistik CONCAT(_ST,_,linenr)((linenr)+(offset), __FILE__, level, position);
#ifdef OKLABI_STATISTIK_SCHEMA
#define STATISTIK_SCHEMA(level,position) if (OklabiObjekt::GibStatistik()) { Statistik _ST(LINENR, __FILE__, level, position); }
#define STATISTIK_ENTRY_ID_SCHEMA(id,linenr,offset,level,position) static Statistik CONCAT(_ST,id,linenr)((linenr)+(offset), __FILE__, level, position);
#else
#define STATISTIK_SCHEMA(level,position) 
#define STATISTIK_ENTRY_ID_SCHEMA(id,linenr,offset,level,position) 
#endif
#else
#define STATISTIK(level,position) 
#define STATISTIK_ENTRY(linenr,offset,level,position) 
#define STATISTIK_SCHEMA(level,position) 
#define STATISTIK_ENTRY_ID_SCHEMA(id,linenr,offset,level,position) 
#endif

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFStatistik
