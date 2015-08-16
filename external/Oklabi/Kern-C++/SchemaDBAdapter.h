/*****************************************************************************
* $Id: SchemaDBAdapter.h 2013-06-06 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt für Straßenwesen
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
* 2011-08-12 template-Defintionen überarbeitet
* 2011-10-14 SchemaDB erweitert
* 2011-12-05 Oberklassenobjekte erzeugen für DBImporteur
* 2012-02-21 Laufzeitoptimierungen
* 2012-09-26 Virtuelle Relationen aus Unterklassen fehlen
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2013-04-18 Zugriff auf das konzeptionelle Fachdatenmodell
* 2013-06-06 Namenskollision bei impliziten Eigenschaften
* 
****************************************************************************/
#ifndef DEFSchemaDBAdapter
#define DEFSchemaDBAdapter

#ifdef OKLABI_SCHEMADB

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <list>

#include "OklabiKern.h"
#include "OklabiObjekt.h"
#include "Version.h"

namespace Oklabi
{
#if defined(LINUX) || defined(CYGWIN)
	class Version;
#endif
	class SchemaDBAdapter : public OklabiRoot
	{
		friend class Reflection;
		friend class Umgebung;
		friend class Version;
		friend class Objektart;
		friend class Eigenschaft;
		friend class Schema;
		friend class Datenbestand;
		friend class Profil;
		friend class ObjektartEnumerator;
	private:
		SchemaDBAdapter();
		~SchemaDBAdapter();

		static SchemaDBAdapter* Gib();
		static void Finalisiere();
		static bool IstInitialisiert();

		bool GibDBVersion(int& haupt, int& unter, int& entw, Text& beschr, Text& modell, Text& xmlns, Text& xmluri, Text& metadata);
		void GibModellarten(std::map<int, Text>&, std::map<int, Text>&, std::map<int, Text>&, std::map<int, Text>&);
		std::list<Version*> GibVersionen(const std::map<int, Text>&, std::list<int>&, std::list<int>&);
		void E_Eigenschaftsnamen( const char* klasse, TextListe* sl, const Version& version, bool bClear );
		void E_Superklassen( const char* klasse, TextListe* sl, const Version& version, bool bClear, bool bAll = false );
		void E_Superklassen( const Objektart* pInfo, ObjektartListType& olist );
		void E_Subklassen( const char* klasse, TextListe* sl, const Version& version, bool bClear, bool bAll = false );
		void E_Subklassen( const Objektart* pInfo, ObjektartListType& olist );
		void E_Klasseninfo( const char* klasse, const Objektart& pInfo, const Version& version );
		bool E_Eigenschaftsinfo( const char* klasse, const Text& strNam, Eigenschaft* pInfo, const Version& version, bool bColl );
		bool Hat_Ganzzahl_Schluessel( const Objektart* pOA, const Eigenschaft* pInfo, size_t& nKey );
		bool Hat_Text_Schluessel( const Objektart* pOA, const Eigenschaft* pInfo, size_t& nKey );
		bool Uebersetze_Schluessel( const Eigenschaft& pInfoKey, const Eigenschaft& pInfoValue, const Text& key, Text& wert );
		void E_Schluessel( const Objektart* pOA, const Eigenschaft* pInfo, IntListe* il, TextListe* sl );
		void E_Langtexte( const Eigenschaft& pInfo, TextListe* sl );
		void E_Pseudoinverse( const char* klasse, TextListe* sl, const Version& version, bool bClear );
		void E_Freunde( const char* klasse, TextListe* sl, const Version& version, bool bClear );
		void E_VirtuelleRelationen( const char* klasse, TextListe* sl, const Version& version, bool bClear );
		void LiesObjektartnamen( const Version& version, std::map<Text, Text, cicmp>* map, std::map<Text, Text, cicmp>* mapInv );
		void LiesSchemata( const Version& version, TextListe* sl );
		void LiesKlassenZuSchema( const Text& name, const Version& version, TextListe* kl );
		void LiesObjektarten( const Version& version );
		void PruefeGeerbteObjektart( const Objektart*, const Objektart* );
		void LiesEigenschaften( const Version& version );
		void LiesWerte( const Version& version );

		static SchemaDBAdapter* m_pDBAdapter;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // OKLABI_SCHEMADB
#endif // DEFSchemaDBAdapter
