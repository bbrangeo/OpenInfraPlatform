/*****************************************************************************
* $Id: SI-Gesamt3.h 28.09.2012 14:14:31 vogelsang $
* $Paket: Oklabi-Kern Schema $
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
* Die Erklärung zum Gewährleistungsausschluß und zur Haftungsbegrenzung
* befindet sich bei den Nutzungsbestimmungen.
*
* 2012-09-27 KennungErfragen-Methode für Staat fehlt
*
****************************************************************************/
/* Change-Log:
*
* 13.01.2011  Code für Schema-Sammelmodul 3 erstellt
*
* Version OKSTRA-Express: 2011-01-13, OKSTRA 1.000-1.015
* Version OKSTRA-Klassenbibliothek: 1.1.0
*
*/
namespace Oklabi
{
class Schema3 : public Schema
{
friend class Schema;
OKLABI_SCHEMA_API static bool LocalInit();
OKLABI_SCHEMA_API static bool initialized;
OKLABI_SCHEMA_API static const char* GibExpressVersion();
OKLABI_SCHEMA_API static const char* GibOKLABIReleaseVersion();
#ifdef OKLABI_PLAUSI

// Baum_Summe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baum_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baum_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baum_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baum_Summe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baum_Summe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baum_Summe( const Objektart& oa, const Version& version );

// Strassenbaeume

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenbaeume( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenbaeume( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenbaeume( const Objektart& oa, const Version& version );

// Art_Strassenbaeume

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Strassenbaeume( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Strassenbaeume( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Strassenbaeume( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Strassenbaeume(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Strassenbaeume(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Strassenbaeume(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Strassenbaeume(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zustaendigkeit_Strbaeume

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustaendigkeit_Strbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustaendigkeit_Strbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustaendigkeit_Strbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zustaendigkeit_Strbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustaendigkeit_Strbaeume( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustaendigkeit_Strbaeume( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustaendigkeit_Strbaeume( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zustaendigkeit_Strbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zustaendigkeit_Strbaeume(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zustaendigkeit_Strbaeume(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zustaendigkeit_Strbaeume(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zustaendigkeit_Strbaeume(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zustaendigkeit_Strbaeume(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vitalitaet_Strassenbaeume

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vitalitaet_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vitalitaet_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vitalitaet_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vitalitaet_Strassenbaeume( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vitalitaet_Strassenbaeume( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vitalitaet_Strassenbaeume( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vitalitaet_Strassenbaeume( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vitalitaet_Strassenbaeume(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vitalitaet_Strassenbaeume(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vitalitaet_Strassenbaeume(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vitalitaet_Strassenbaeume(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vitalitaet_Strassenbaeume(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Dichte_Allee

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Dichte_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Dichte_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Dichte_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Dichte_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Dichte_Allee( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Dichte_Allee( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Dichte_Allee( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Dichte_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Dichte_Allee(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Dichte_Allee(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Dichte_Allee(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Dichte_Allee(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zustand_Allee

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustand_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustand_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustand_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zustand_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustand_Allee( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustand_Allee( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustand_Allee( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zustand_Allee(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zustand_Allee(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zustand_Allee(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zustand_Allee(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zustand_Allee(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Pflanzzeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pflanzzeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pflanzzeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pflanzzeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Pflanzzeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pflanzzeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pflanzzeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pflanzzeit( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Pflanzzeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Pflanzzeit(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Pflanzzeit(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Pflanzzeit(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Pflanzzeit(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Baumreihenabschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Baumreihenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Baumreihenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Baumreihenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Baumreihenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Baumreihenabschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Baumreihenabschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Baumreihenabschnitt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Baumreihenabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Baumreihenabschnitt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Baumreihenabschnitt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Baumreihenabschnitt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Baumreihenabschnitt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zustaendigkeit_BRA

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustaendigkeit_BRA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustaendigkeit_BRA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustaendigkeit_BRA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zustaendigkeit_BRA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustaendigkeit_BRA( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustaendigkeit_BRA( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustaendigkeit_BRA( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zustaendigkeit_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zustaendigkeit_BRA(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zustaendigkeit_BRA(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zustaendigkeit_BRA(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zustaendigkeit_BRA(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vitalitaet_BRA

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vitalitaet_BRA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vitalitaet_BRA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vitalitaet_BRA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vitalitaet_BRA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vitalitaet_BRA( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vitalitaet_BRA( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vitalitaet_BRA( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vitalitaet_BRA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vitalitaet_BRA(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vitalitaet_BRA(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vitalitaet_BRA(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vitalitaet_BRA(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Administrative_Massnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Administrative_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Administrative_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Administrative_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Administrative_Massnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Administrative_Massnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Administrative_Massnahme( const Objektart& oa, const Version& version );

// Rb_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rb_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rb_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rb_massnahme_Str( const Objektart& oa, const Version& version );

// Rb_massnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rb_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rb_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rb_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rb_massnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rb_massnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rb_massnahme_Bwk( const Objektart& oa, const Version& version );

// Rb_massnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rb_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rb_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rb_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rb_massnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rb_massnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rb_massnahme_sonst_AT( const Objektart& oa, const Version& version );

// Rueckbaumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rueckbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rueckbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rueckbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rueckbaumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rueckbaumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rueckbaumassnahme( const Objektart& oa, const Version& version );

// Ub_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ub_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ub_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ub_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ub_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ub_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ub_massnahme_Str( const Objektart& oa, const Version& version );

// Ub_massnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ub_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ub_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ub_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ub_massnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ub_massnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ub_massnahme_Bwk( const Objektart& oa, const Version& version );

// Ub_massnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ub_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ub_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ub_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ub_massnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ub_massnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ub_massnahme_sonst_AT( const Objektart& oa, const Version& version );

// Umbaumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Umbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Umbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Umbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Umbaumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Umbaumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Umbaumassnahme( const Objektart& oa, const Version& version );

// Ab_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ab_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ab_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ab_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ab_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ab_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ab_massnahme_Str( const Objektart& oa, const Version& version );

// Ab_massnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ab_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ab_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ab_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ab_massnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ab_massnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ab_massnahme_Bwk( const Objektart& oa, const Version& version );

// Ab_massnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ab_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ab_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ab_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ab_massnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ab_massnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ab_massnahme_sonst_AT( const Objektart& oa, const Version& version );

// Ausbaumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausbaumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausbaumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausbaumassnahme( const Objektart& oa, const Version& version );

// Um_Ausbaumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Um_Ausbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Um_Ausbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Um_Ausbaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Um_Ausbaumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Um_Ausbaumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Um_Ausbaumassnahme( const Objektart& oa, const Version& version );

// Erw_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erw_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erw_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erw_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erw_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erw_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erw_massnahme_Str( const Objektart& oa, const Version& version );

// Erw_massnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erw_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erw_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erw_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erw_massnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erw_massnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erw_massnahme_Bwk( const Objektart& oa, const Version& version );

// Erw_massnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erw_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erw_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erw_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erw_massnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erw_massnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erw_massnahme_sonst_AT( const Objektart& oa, const Version& version );

// Erweiterungsmassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erweiterungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erweiterungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erweiterungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erweiterungsmassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erweiterungsmassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erweiterungsmassnahme( const Objektart& oa, const Version& version );

// Nb_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nb_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nb_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nb_massnahme_Str( const Objektart& oa, const Version& version );

// Nb_massnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nb_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nb_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nb_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nb_massnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nb_massnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nb_massnahme_Bwk( const Objektart& oa, const Version& version );

// Nb_massnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nb_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nb_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nb_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nb_massnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nb_massnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nb_massnahme_sonst_AT( const Objektart& oa, const Version& version );

// Neubaumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Neubaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Neubaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Neubaumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Neubaumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Neubaumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Neubaumassnahme( const Objektart& oa, const Version& version );

// Erh_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erh_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erh_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erh_massnahme_Str( const Objektart& oa, const Version& version );

// Erh_massnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erh_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erh_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erh_massnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erh_massnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erh_massnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erh_massnahme_Bwk( const Objektart& oa, const Version& version );

// Erh_massnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erh_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erh_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erh_massnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erh_massnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erh_massnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erh_massnahme_sonst_AT( const Objektart& oa, const Version& version );

// Erhaltungsmassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erhaltungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erhaltungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erhaltungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erhaltungsmassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erhaltungsmassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erhaltungsmassnahme( const Objektart& oa, const Version& version );

// Massnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Massnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Massnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Massnahme( const Objektart& oa, const Version& version );

// Haushaltsbezug

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Haushaltsbezug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Haushaltsbezug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Haushaltsbezug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Haushaltsbezug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Haushaltsbezug( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Haushaltsbezug( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Haushaltsbezug( const Objektart& oa, const Version& version );

// Status_Rb_massnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Status_Rb_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Status_Rb_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Status_Rb_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Status_Rb_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Status_Rb_massnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Status_Rb_massnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Status_Rb_massnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Status_Rb_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Status_Rb_massnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Status_Rb_massnahme(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Status_Rb_massnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Status_Rb_massnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Status_Rb_massnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Rb_teilmassnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rb_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rb_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rb_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rb_teilmassnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rb_teilmassnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rb_teilmassnahme_Str( const Objektart& oa, const Version& version );

// Art_Rb_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Rb_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Rb_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Rb_massnahme_Str( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Rb_massnahme_Str(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Rb_massnahme_Str(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Rb_massnahme_Str(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Rb_massnahme_Str(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Rb_massnahme_Str(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ursache_Rb_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ursache_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ursache_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ursache_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ursache_Rb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ursache_Rb_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ursache_Rb_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ursache_Rb_massnahme_Str( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ursache_Rb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ursache_Rb_massnahme_Str(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ursache_Rb_massnahme_Str(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ursache_Rb_massnahme_Str(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ursache_Rb_massnahme_Str(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ursache_Rb_massnahme_Str(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Status_Nb_Erw_Uab_massnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Status_Nb_Erw_Uab_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Status_Nb_Erw_Uab_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Status_Nb_Erw_Uab_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Status_Nb_Erw_Uab_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Status_Nb_Erw_Uab_massnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Status_Nb_Erw_Uab_massnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Status_Nb_Erw_Uab_massnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Status_Nb_Erw_Uab_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Status_Nb_Erw_Uab_massnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Status_Nb_Erw_Uab_massnahme(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Status_Nb_Erw_Uab_massnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Status_Nb_Erw_Uab_massnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Status_Nb_Erw_Uab_massnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ub_teilmassnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ub_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ub_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ub_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ub_teilmassnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ub_teilmassnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ub_teilmassnahme_Str( const Objektart& oa, const Version& version );

// Ursache_Erw_Uab_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ursache_Erw_Uab_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ursache_Erw_Uab_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ursache_Erw_Uab_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ursache_Erw_Uab_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ursache_Erw_Uab_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ursache_Erw_Uab_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ursache_Erw_Uab_massnahme_Str( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ursache_Erw_Uab_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ursache_Erw_Uab_massnahme_Str(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ursache_Erw_Uab_massnahme_Str(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ursache_Erw_Uab_massnahme_Str(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ursache_Erw_Uab_massnahme_Str(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ursache_Erw_Uab_massnahme_Str(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ab_teilmassnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ab_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ab_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ab_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ab_teilmassnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ab_teilmassnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ab_teilmassnahme_Str( const Objektart& oa, const Version& version );

// Erw_teilmassnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erw_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erw_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erw_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erw_teilmassnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erw_teilmassnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erw_teilmassnahme_Str( const Objektart& oa, const Version& version );

// Nb_teilmassnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nb_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nb_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nb_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nb_teilmassnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nb_teilmassnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nb_teilmassnahme_Str( const Objektart& oa, const Version& version );

// Ursache_Nb_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ursache_Nb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ursache_Nb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ursache_Nb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ursache_Nb_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ursache_Nb_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ursache_Nb_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ursache_Nb_massnahme_Str( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ursache_Nb_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ursache_Nb_massnahme_Str(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ursache_Nb_massnahme_Str(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ursache_Nb_massnahme_Str(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ursache_Nb_massnahme_Str(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ursache_Nb_massnahme_Str(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Status_Erh_massnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Status_Erh_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Status_Erh_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Status_Erh_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Status_Erh_massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Status_Erh_massnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Status_Erh_massnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Status_Erh_massnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Status_Erh_massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Status_Erh_massnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Status_Erh_massnahme(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Status_Erh_massnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Status_Erh_massnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Status_Erh_massnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Erh_teilmassnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erh_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erh_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erh_teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erh_teilmassnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erh_teilmassnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erh_teilmassnahme_Str( const Objektart& oa, const Version& version );

// Art_Erh_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Erh_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Erh_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Erh_massnahme_Str( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Erh_massnahme_Str(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Erh_massnahme_Str(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Erh_massnahme_Str(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Erh_massnahme_Str(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ursache_Erh_massnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ursache_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ursache_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ursache_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ursache_Erh_massnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ursache_Erh_massnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ursache_Erh_massnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ursache_Erh_massnahme_Str( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ursache_Erh_massnahme_Str(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ursache_Erh_massnahme_Str(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ursache_Erh_massnahme_Str(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ursache_Erh_massnahme_Str(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ursache_Erh_massnahme_Str(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ursache_Erh_massnahme_Str(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Teilmassnahme_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilmassnahme_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilmassnahme_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilmassnahme_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilmassnahme_Str( const Objektart& oa, const Version& version );

// Nb_teilmassnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nb_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nb_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nb_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nb_teilmassnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nb_teilmassnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nb_teilmassnahme_Bwk( const Objektart& oa, const Version& version );

// Erh_teilmassnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erh_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erh_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erh_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erh_teilmassnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erh_teilmassnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erh_teilmassnahme_Bwk( const Objektart& oa, const Version& version );

// Ub_teilmassnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ub_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ub_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ub_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ub_teilmassnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ub_teilmassnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ub_teilmassnahme_Bwk( const Objektart& oa, const Version& version );

// Ab_teilmassnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ab_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ab_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ab_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ab_teilmassnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ab_teilmassnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ab_teilmassnahme_Bwk( const Objektart& oa, const Version& version );

// Erw_teilmassnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erw_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erw_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erw_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erw_teilmassnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erw_teilmassnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erw_teilmassnahme_Bwk( const Objektart& oa, const Version& version );

// Rb_teilmassnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rb_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rb_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rb_teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rb_teilmassnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rb_teilmassnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rb_teilmassnahme_Bwk( const Objektart& oa, const Version& version );

// Teilmassnahme_Bwk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilmassnahme_Bwk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilmassnahme_Bwk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilmassnahme_Bwk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilmassnahme_Bwk( const Objektart& oa, const Version& version );

// Nb_teilmassnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nb_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nb_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nb_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nb_teilmassnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nb_teilmassnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nb_teilmassnahme_sonst_AT( const Objektart& oa, const Version& version );

// Erh_teilmassnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erh_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erh_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erh_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erh_teilmassnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erh_teilmassnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erh_teilmassnahme_sonst_AT( const Objektart& oa, const Version& version );

// Ub_teilmassnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ub_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ub_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ub_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ub_teilmassnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ub_teilmassnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ub_teilmassnahme_sonst_AT( const Objektart& oa, const Version& version );

// Ab_teilmassnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ab_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ab_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ab_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ab_teilmassnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ab_teilmassnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ab_teilmassnahme_sonst_AT( const Objektart& oa, const Version& version );

// Erw_teilmassnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erw_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erw_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erw_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erw_teilmassnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erw_teilmassnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erw_teilmassnahme_sonst_AT( const Objektart& oa, const Version& version );

// Rb_teilmassnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rb_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rb_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rb_teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rb_teilmassnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rb_teilmassnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rb_teilmassnahme_sonst_AT( const Objektart& oa, const Version& version );

// Teilmassnahme_sonst_AT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilmassnahme_sonst_AT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilmassnahme_sonst_AT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilmassnahme_sonst_AT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilmassnahme_sonst_AT( const Objektart& oa, const Version& version );

// Teilprojekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilprojekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilprojekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilprojekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilprojekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilprojekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilprojekt( const Objektart& oa, const Version& version );

// Art_Haushalt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Haushalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Haushalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Haushalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Haushalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Haushalt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Haushalt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Haushalt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Haushalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Haushalt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Haushalt(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Haushalt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Haushalt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Haushalt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Baumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Baumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Baumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Baumassnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Baumassnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Baumassnahme(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Baumassnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Baumassnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Baumassnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Objekt_Baumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Objekt_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Objekt_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Objekt_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Objekt_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Objekt_Baumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Objekt_Baumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Objekt_Baumassnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Objekt_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Objekt_Baumassnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Objekt_Baumassnahme(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Objekt_Baumassnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Objekt_Baumassnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Objekt_Baumassnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Status_Baumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Status_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Status_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Status_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Status_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Status_Baumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Status_Baumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Status_Baumassnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Status_Baumassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Status_Baumassnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Status_Baumassnahme(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Status_Baumassnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Status_Baumassnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Status_Baumassnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Planung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Planung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Planung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Planung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Planung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Planung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Planung( const Objektart& oa, const Version& version );

// Erstellg_Vergabeunterlagen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erstellg_Vergabeunterlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erstellg_Vergabeunterlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erstellg_Vergabeunterlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erstellg_Vergabeunterlagen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erstellg_Vergabeunterlagen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erstellg_Vergabeunterlagen( const Objektart& oa, const Version& version );

// Ausschreibungsverfahren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausschreibungsverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausschreibungsverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausschreibungsverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausschreibungsverfahren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausschreibungsverfahren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausschreibungsverfahren( const Objektart& oa, const Version& version );

// Bekanntmachung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bekanntmachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bekanntmachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bekanntmachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bekanntmachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bekanntmachung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bekanntmachung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bekanntmachung( const Objektart& oa, const Version& version );

// Ausschreibungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausschreibungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausschreibungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausschreibungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ausschreibungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausschreibungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausschreibungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausschreibungsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ausschreibungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ausschreibungsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ausschreibungsart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ausschreibungsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ausschreibungsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ausschreibungsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vergabeart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vergabeart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vergabeart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vergabeart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vergabeart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vergabeart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vergabeart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vergabeart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vergabeart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vergabeart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Vergabeart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vergabeart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vergabeart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vergabeart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vertragsart_I

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vertragsart_I( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vertragsart_I( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vertragsart_I( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vertragsart_I( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vertragsart_I( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vertragsart_I( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vertragsart_I( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vertragsart_I(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vertragsart_I(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Vertragsart_I(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vertragsart_I(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vertragsart_I(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vertragsart_I(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vertragsart_II

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vertragsart_II( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vertragsart_II( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vertragsart_II( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vertragsart_II( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vertragsart_II( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vertragsart_II( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vertragsart_II( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vertragsart_II(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vertragsart_II(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Vertragsart_II(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vertragsart_II(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vertragsart_II(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vertragsart_II(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_losweise_Vergabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_losweise_Vergabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_losweise_Vergabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_losweise_Vergabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_losweise_Vergabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_losweise_Vergabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_losweise_Vergabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_losweise_Vergabe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_losweise_Vergabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_losweise_Vergabe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_losweise_Vergabe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_losweise_Vergabe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_losweise_Vergabe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_losweise_Vergabe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Baustoff_Preisgleitklausel

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baustoff_Preisgleitklausel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baustoff_Preisgleitklausel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baustoff_Preisgleitklausel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baustoff_Preisgleitklausel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baustoff_Preisgleitklausel( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baustoff_Preisgleitklausel( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baustoff_Preisgleitklausel( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Baustoff_Preisgleitklausel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Baustoff_Preisgleitklausel(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Baustoff_Preisgleitklausel(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Baustoff_Preisgleitklausel(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Baustoff_Preisgleitklausel(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Baustoff_Preisgleitklausel(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vergabeverfahren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vergabeverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vergabeverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vergabeverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vergabeverfahren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vergabeverfahren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vergabeverfahren( const Objektart& oa, const Version& version );

// Bindefristverlaengerung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bindefristverlaengerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bindefristverlaengerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bindefristverlaengerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bindefristverlaengerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bindefristverlaengerung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bindefristverlaengerung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bindefristverlaengerung( const Objektart& oa, const Version& version );

// Wertung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wertung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wertung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wertung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wertung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wertung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wertung( const Objektart& oa, const Version& version );

// Wertungskriterium

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wertungskriterium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wertungskriterium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wertungskriterium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wertungskriterium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wertungskriterium( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wertungskriterium( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wertungskriterium( const Objektart& oa, const Version& version );

// Kriterium_bevorzgt_Bewerber

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kriterium_bevorzgt_Bewerber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kriterium_bevorzgt_Bewerber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kriterium_bevorzgt_Bewerber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kriterium_bevorzgt_Bewerber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kriterium_bevorzgt_Bewerber( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kriterium_bevorzgt_Bewerber( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kriterium_bevorzgt_Bewerber( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kriterium_bevorzgt_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kriterium_bevorzgt_Bewerber(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Kriterium_bevorzgt_Bewerber(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kriterium_bevorzgt_Bewerber(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kriterium_bevorzgt_Bewerber(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kriterium_bevorzgt_Bewerber(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Nachpruefungsverfahren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nachpruefungsverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nachpruefungsverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nachpruefungsverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nachpruefungsverfahren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nachpruefungsverfahren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nachpruefungsverfahren( const Objektart& oa, const Version& version );

// Art_Abschluss_Nachpruefung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Abschluss_Nachpruefung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Abschluss_Nachpruefung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Abschluss_Nachpruefung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Abschluss_Nachpruefung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Abschluss_Nachpruefung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Abschluss_Nachpruefung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Abschluss_Nachpruefung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Abschluss_Nachpruefung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Abschluss_Nachpruefung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Abschluss_Nachpruefung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Abschluss_Nachpruefung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Abschluss_Nachpruefung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Abschluss_Nachpruefung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Teilnahmewettbewerb

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilnahmewettbewerb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilnahmewettbewerb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilnahmewettbewerb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilnahmewettbewerb( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilnahmewettbewerb( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilnahmewettbewerb( const Objektart& oa, const Version& version );

// Angebot

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angebot( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angebot( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angebot( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angebot( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angebot( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angebot( const Objektart& oa, const Version& version );

// Bauausfuehrung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauausfuehrung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauausfuehrung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauausfuehrung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauausfuehrung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauausfuehrung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauausfuehrung( const Objektart& oa, const Version& version );

// Abnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abnahme( const Objektart& oa, const Version& version );

// Bauueberwachung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauueberwachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauueberwachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauueberwachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauueberwachung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauueberwachung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauueberwachung( const Objektart& oa, const Version& version );

// Objektbetreuung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Objektbetreuung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Objektbetreuung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Objektbetreuung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Objektbetreuung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Objektbetreuung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Objektbetreuung( const Objektart& oa, const Version& version );

// ARGE

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ARGE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ARGE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ARGE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ARGE( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ARGE( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ARGE( const Objektart& oa, const Version& version );

// Firma

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Firma( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Firma( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Firma( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Firma( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Firma( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Firma( const Objektart& oa, const Version& version );

// Marktteilnehmer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Marktteilnehmer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Marktteilnehmer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Marktteilnehmer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Marktteilnehmer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Marktteilnehmer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Marktteilnehmer( const Objektart& oa, const Version& version );

// Firmenart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Firmenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Firmenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Firmenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Firmenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Firmenart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Firmenart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Firmenart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Firmenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Firmenart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Firmenart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Firmenart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Firmenart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Firmenart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Typ_bevorzugter_Bewerber

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_bevorzugter_Bewerber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_bevorzugter_Bewerber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_bevorzugter_Bewerber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_bevorzugter_Bewerber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_bevorzugter_Bewerber( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_bevorzugter_Bewerber( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_bevorzugter_Bewerber( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_bevorzugter_Bewerber(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_bevorzugter_Bewerber(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Typ_bevorzugter_Bewerber(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_bevorzugter_Bewerber(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_bevorzugter_Bewerber(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_bevorzugter_Bewerber(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Sitz_Grobangabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sitz_Grobangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sitz_Grobangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sitz_Grobangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Sitz_Grobangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sitz_Grobangabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sitz_Grobangabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sitz_Grobangabe( const Objektart& oa, const Version& version );

// CSBF_Meldung_Info

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_CSBF_Meldung_Info( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_CSBF_Meldung_Info( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_CSBF_Meldung_Info( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_CSBF_Meldung_Info( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_CSBF_Meldung_Info( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_CSBF_Meldung_Info( const Objektart& oa, const Version& version );

// CSBF_Identnummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_CSBF_Identnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_CSBF_Identnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_CSBF_Identnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_CSBF_Identnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_CSBF_Identnummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_CSBF_Identnummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_CSBF_Identnummer( const Objektart& oa, const Version& version );

// Daten_zur_Gesamtabnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Daten_zur_Gesamtabnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Daten_zur_Gesamtabnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Daten_zur_Gesamtabnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Daten_zur_Gesamtabnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Daten_zur_Gesamtabnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Daten_zur_Gesamtabnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Daten_zur_Gesamtabnahme( const Objektart& oa, const Version& version );

// Frist_Maengelansprueche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Frist_Maengelansprueche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Frist_Maengelansprueche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Frist_Maengelansprueche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Frist_Maengelansprueche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Frist_Maengelansprueche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Frist_Maengelansprueche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Frist_Maengelansprueche( const Objektart& oa, const Version& version );

// Baubeginn

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baubeginn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baubeginn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baubeginn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baubeginn( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baubeginn( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baubeginn( const Objektart& oa, const Version& version );

// Nachtrag

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nachtrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nachtrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nachtrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nachtrag( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nachtrag( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nachtrag( const Objektart& oa, const Version& version );

// Ausgabestand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausgabestand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausgabestand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausgabestand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausgabestand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausgabestand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausgabestand( const Objektart& oa, const Version& version );

// Schlusszahlung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schlusszahlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schlusszahlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schlusszahlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schlusszahlung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schlusszahlung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schlusszahlung( const Objektart& oa, const Version& version );

// Erstellg_Entwurfsunterlagen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erstellg_Entwurfsunterlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erstellg_Entwurfsunterlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erstellg_Entwurfsunterlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erstellg_Entwurfsunterlagen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erstellg_Entwurfsunterlagen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erstellg_Entwurfsunterlagen( const Objektart& oa, const Version& version );

// Nebenangebote_zugelassen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nebenangebote_zugelassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nebenangebote_zugelassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nebenangebote_zugelassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Nebenangebote_zugelassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nebenangebote_zugelassen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nebenangebote_zugelassen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nebenangebote_zugelassen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Nebenangebote_zugelassen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Nebenangebote_zugelassen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Nebenangebote_zugelassen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Nebenangebote_zugelassen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Nebenangebote_zugelassen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gruende_Teilnahmewettbewerb

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gruende_Teilnahmewettbewerb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gruende_Teilnahmewettbewerb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gruende_Teilnahmewettbewerb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gruende_Teilnahmewettbewerb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gruende_Teilnahmewettbewerb( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gruende_Teilnahmewettbewerb( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gruende_Teilnahmewettbewerb( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gruende_Teilnahmewettbewerb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gruende_Teilnahmewettbewerb(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gruende_Teilnahmewettbewerb(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gruende_Teilnahmewettbewerb(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gruende_Teilnahmewettbewerb(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zuschlag

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zuschlag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zuschlag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zuschlag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zuschlag( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zuschlag( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zuschlag( const Objektart& oa, const Version& version );

// Auftragserteilung_HA_o_NA

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Auftragserteilung_HA_o_NA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Auftragserteilung_HA_o_NA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Auftragserteilung_HA_o_NA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Auftragserteilung_HA_o_NA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Auftragserteilung_HA_o_NA( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Auftragserteilung_HA_o_NA( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Auftragserteilung_HA_o_NA( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Auftragserteilung_HA_o_NA(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Auftragserteilung_HA_o_NA(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Auftragserteilung_HA_o_NA(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Auftragserteilung_HA_o_NA(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Auftragserteilung_HA_o_NA(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Firmenkonstrukt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Firmenkonstrukt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Firmenkonstrukt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Firmenkonstrukt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Firmenkonstrukt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Firmenkonstrukt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Firmenkonstrukt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Firmenkonstrukt( const Objektart& oa, const Version& version );

// Verwaltungskosten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verwaltungskosten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verwaltungskosten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verwaltungskosten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verwaltungskosten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verwaltungskosten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verwaltungskosten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verwaltungskosten( const Objektart& oa, const Version& version );

// Art_Fussgaengerueberweg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Fussgaengerueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Fussgaengerueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Fussgaengerueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Fussgaengerueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Fussgaengerueberweg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Fussgaengerueberweg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Fussgaengerueberweg( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Fussgaengerueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Fussgaengerueberweg(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Fussgaengerueberweg(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Fussgaengerueberweg(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Fussgaengerueberweg(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Knotenpunktform_Kreuzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Knotenpunktform_Kreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Knotenpunktform_Kreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Knotenpunktform_Kreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Knotenpunktform_Kreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Knotenpunktform_Kreuzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Knotenpunktform_Kreuzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Knotenpunktform_Kreuzung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Knotenpunktform_Kreuzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Knotenpunktform_Kreuzung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Knotenpunktform_Kreuzung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Knotenpunktform_Kreuzung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Knotenpunktform_Kreuzung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tierart_ASB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tierart_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tierart_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tierart_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tierart_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tierart_ASB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tierart_ASB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tierart_ASB( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tierart_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tierart_ASB(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tierart_ASB(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tierart_ASB(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tierart_ASB(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gueltigkeitsbereich_ZS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gueltigkeitsbereich_ZS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gueltigkeitsbereich_ZS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gueltigkeitsbereich_ZS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gueltigkeitsbereich_ZS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gueltigkeitsbereich_ZS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gueltigkeitsbereich_ZS( const Objektart& oa, const Version& version );

// Art_Zaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Zaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Zaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Zaehlstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Zaehlstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Zaehlstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Zaehlstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Zaehlstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Status_Zaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Status_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Status_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Status_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Status_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Status_Zaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Status_Zaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Status_Zaehlstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Status_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Status_Zaehlstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Status_Zaehlstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Status_Zaehlstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Status_Zaehlstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Richtung_Zaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Richtung_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Richtung_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Richtung_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Richtung_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Richtung_Zaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Richtung_Zaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Richtung_Zaehlstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Richtung_Zaehlstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Richtung_Zaehlstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Richtung_Zaehlstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Richtung_Zaehlstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Richtung_Zaehlstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrslage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrslage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrslage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrslage( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Verkehrslage(const Version& vsn);

// Verkehrsstau

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsstau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsstau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsstau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsstau( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsstau( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsstau( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Verkehrsstau(const Version& vsn);

// Einzelfahrzeugdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einzelfahrzeugdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einzelfahrzeugdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einzelfahrzeugdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einzelfahrzeugdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einzelfahrzeugdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einzelfahrzeugdaten( const Objektart& oa, const Version& version );

// Schwertransport

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schwertransport( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schwertransport( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schwertransport( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schwertransport( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schwertransport( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schwertransport( const Objektart& oa, const Version& version );

// VEMAGS_Ausgabeumfang

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VEMAGS_Ausgabeumfang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VEMAGS_Ausgabeumfang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VEMAGS_Ausgabeumfang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_VEMAGS_Ausgabeumfang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VEMAGS_Ausgabeumfang( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VEMAGS_Ausgabeumfang( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VEMAGS_Ausgabeumfang( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_VEMAGS_Ausgabeumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_VEMAGS_Ausgabeumfang(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_VEMAGS_Ausgabeumfang(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_VEMAGS_Ausgabeumfang(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_VEMAGS_Ausgabeumfang(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bauwerksueberfahrt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerksueberfahrt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerksueberfahrt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerksueberfahrt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerksueberfahrt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerksueberfahrt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerksueberfahrt( const Objektart& oa, const Version& version );

// VEMAGS_Berechnungsrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VEMAGS_Berechnungsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VEMAGS_Berechnungsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VEMAGS_Berechnungsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_VEMAGS_Berechnungsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VEMAGS_Berechnungsrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VEMAGS_Berechnungsrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VEMAGS_Berechnungsrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_VEMAGS_Berechnungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_VEMAGS_Berechnungsrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_VEMAGS_Berechnungsrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_VEMAGS_Berechnungsrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_VEMAGS_Berechnungsrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// VEMAGS_Berechnungsergebnis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VEMAGS_Berechnungsergebnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VEMAGS_Berechnungsergebnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VEMAGS_Berechnungsergebnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VEMAGS_Berechnungsergebnis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VEMAGS_Berechnungsergebnis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VEMAGS_Berechnungsergebnis( const Objektart& oa, const Version& version );

// VEMAGS_Info

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VEMAGS_Info( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VEMAGS_Info( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VEMAGS_Info( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_VEMAGS_Info( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VEMAGS_Info( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VEMAGS_Info( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VEMAGS_Info( const Objektart& oa, const Version& version );

// VEMAGS_Teilbauwerksergebnis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VEMAGS_Teilbauwerksergebnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VEMAGS_Teilbauwerksergebnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VEMAGS_Teilbauwerksergebnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VEMAGS_Teilbauwerksergebnis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VEMAGS_Teilbauwerksergebnis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VEMAGS_Teilbauwerksergebnis( const Objektart& oa, const Version& version );

// Schnittgroessenvergleich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schnittgroessenvergleich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schnittgroessenvergleich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schnittgroessenvergleich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schnittgroessenvergleich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schnittgroessenvergleich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schnittgroessenvergleich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schnittgroessenvergleich( const Objektart& oa, const Version& version );

// Art_Schnittgroesse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Schnittgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Schnittgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Schnittgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Schnittgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Schnittgroesse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Schnittgroesse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Schnittgroesse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Schnittgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Schnittgroesse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Schnittgroesse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Schnittgroesse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Schnittgroesse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// VEMAGS_Berechnungsgrundlage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VEMAGS_Berechnungsgrundlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VEMAGS_Berechnungsgrundlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VEMAGS_Berechnungsgrundlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VEMAGS_Berechnungsgrundlage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VEMAGS_Berechnungsgrundlage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VEMAGS_Berechnungsgrundlage( const Objektart& oa, const Version& version );

// VEMAGS_Lastbild_Definition

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VEMAGS_Lastbild_Definition( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VEMAGS_Lastbild_Definition( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VEMAGS_Lastbild_Definition( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VEMAGS_Lastbild_Definition( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VEMAGS_Lastbild_Definition( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VEMAGS_Lastbild_Definition( const Objektart& oa, const Version& version );

// NK_umbenennen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_NK_umbenennen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_NK_umbenennen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_NK_umbenennen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_NK_umbenennen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_NK_umbenennen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_NK_umbenennen( const Objektart& oa, const Version& version );

// NP_umbenennen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_NP_umbenennen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_NP_umbenennen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_NP_umbenennen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_NP_umbenennen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_NP_umbenennen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_NP_umbenennen( const Objektart& oa, const Version& version );

// AOA_anlegen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_anlegen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_anlegen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_anlegen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_anlegen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_anlegen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_anlegen( const Objektart& oa, const Version& version );

// AOA_Laenge_aendern

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_Laenge_aendern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_Laenge_aendern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_Laenge_aendern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_Laenge_aendern( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_Laenge_aendern( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_Laenge_aendern( const Objektart& oa, const Version& version );

// AOA_Teilgeometrie_aendern

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_Teilgeometrie_aendern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_Teilgeometrie_aendern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_Teilgeometrie_aendern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_Teilgeometrie_aendern( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_Teilgeometrie_aendern( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_Teilgeometrie_aendern( const Objektart& oa, const Version& version );

// AOA_Teilabschnitt_einfuegen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_Teilabschnitt_einfuegen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_Teilabschnitt_einfuegen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_Teilabschnitt_einfuegen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_Teilabschnitt_einfuegen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_Teilabschnitt_einfuegen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_Teilabschnitt_einfuegen( const Objektart& oa, const Version& version );

// AOA_Teilabschnitt_loeschen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_Teilabschnitt_loeschen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_Teilabschnitt_loeschen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_Teilabschnitt_loeschen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_Teilabschnitt_loeschen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_Teilabschnitt_loeschen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_Teilabschnitt_loeschen( const Objektart& oa, const Version& version );

// AOA_spalten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_spalten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_spalten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_spalten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_spalten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_spalten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_spalten( const Objektart& oa, const Version& version );

// AOA_verschmelzen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_verschmelzen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_verschmelzen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_verschmelzen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_verschmelzen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_verschmelzen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_verschmelzen( const Objektart& oa, const Version& version );

// AOA_drehen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_drehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_drehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_drehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_drehen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_drehen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_drehen( const Objektart& oa, const Version& version );

// AOA_loeschen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AOA_loeschen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AOA_loeschen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AOA_loeschen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AOA_loeschen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AOA_loeschen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AOA_loeschen( const Objektart& oa, const Version& version );

// Netzaenderungsoperation

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzaenderungsoperation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzaenderungsoperation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzaenderungsoperation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzaenderungsoperation( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzaenderungsoperation( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzaenderungsoperation( const Objektart& oa, const Version& version );

// Netzaenderungstransaktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzaenderungstransaktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzaenderungstransaktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzaenderungstransaktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzaenderungstransaktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzaenderungstransaktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzaenderungstransaktion( const Objektart& oa, const Version& version );

// Formular

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formular( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formular( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formular( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formular( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formular( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formular( const Objektart& oa, const Version& version );

// Zeitpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zeitpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zeitpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zeitpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zeitpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zeitpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zeitpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zeitpunkt( const Objektart& oa, const Version& version );

// Zeitabschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zeitabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zeitabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zeitabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zeitabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zeitabschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zeitabschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zeitabschnitt( const Objektart& oa, const Version& version );

// Formularfeldgruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formularfeldgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formularfeldgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formularfeldgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Formularfeldgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formularfeldgruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formularfeldgruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formularfeldgruppe( const Objektart& oa, const Version& version );

// Formularfeld

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formularfeld( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formularfeld( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formularfeld( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Formularfeld( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formularfeld( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formularfeld( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formularfeld( const Objektart& oa, const Version& version );

// Adressdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Adressdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Adressdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Adressdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Adressdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Adressdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Adressdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Adressdaten( const Objektart& oa, const Version& version );

// OKSTRA_konzept_Objekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_OKSTRA_konzept_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_OKSTRA_konzept_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_OKSTRA_konzept_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_OKSTRA_konzept_Objekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_OKSTRA_konzept_Objekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_OKSTRA_konzept_Objekt( const Objektart& oa, const Version& version );

// Dreiwertige_Logik

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Dreiwertige_Logik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Dreiwertige_Logik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Dreiwertige_Logik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Dreiwertige_Logik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Dreiwertige_Logik( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Dreiwertige_Logik( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Dreiwertige_Logik( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Dreiwertige_Logik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Dreiwertige_Logik(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Dreiwertige_Logik(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Dreiwertige_Logik(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Dreiwertige_Logik(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Dreiwertige_Logik(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Sonstiges

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sonstiges( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sonstiges( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sonstiges( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Sonstiges( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sonstiges( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sonstiges( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sonstiges( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Sonstiges(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Sonstiges(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Sonstiges(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Sonstiges(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Sonstiges(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Monat

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Monat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Monat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Monat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Monat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Monat( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Monat( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Monat( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Monat(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Monat(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Monat(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Monat(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Monat(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Monat(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Nummer_des_Wochentages

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nummer_des_Wochentages( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nummer_des_Wochentages( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nummer_des_Wochentages( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Nummer_des_Wochentages( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nummer_des_Wochentages( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nummer_des_Wochentages( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nummer_des_Wochentages( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Nummer_des_Wochentages(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Nummer_des_Wochentages(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Nummer_des_Wochentages(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Nummer_des_Wochentages(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Nummer_des_Wochentages(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Nummer_des_Wochentages(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Detaillierungsgrad_ASB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detaillierungsgrad_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detaillierungsgrad_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detaillierungsgrad_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Detaillierungsgrad_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detaillierungsgrad_ASB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detaillierungsgrad_ASB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detaillierungsgrad_ASB( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Detaillierungsgrad_ASB(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Detaillierungsgrad_ASB(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Detaillierungsgrad_ASB(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Detaillierungsgrad_ASB(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Detaillierungsgrad_ASB(const Version& vsn, const Text& key, Text& value, const int& nVal);

// OKSTRA_Schluesseltabelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_OKSTRA_Schluesseltabelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_OKSTRA_Schluesseltabelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_OKSTRA_Schluesseltabelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_OKSTRA_Schluesseltabelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_OKSTRA_Schluesseltabelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_OKSTRA_Schluesseltabelle( const Objektart& oa, const Version& version );

// Kommunikationsobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kommunikationsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kommunikationsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kommunikationsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kommunikationsobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kommunikationsobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kommunikationsobjekt( const Objektart& oa, const Version& version );

// Wegweiser_statisch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweiser_statisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweiser_statisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweiser_statisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweiser_statisch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweiser_statisch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweiser_statisch( const Objektart& oa, const Version& version );

// Wegweiser_dynamisch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweiser_dynamisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweiser_dynamisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweiser_dynamisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweiser_dynamisch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweiser_dynamisch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweiser_dynamisch( const Objektart& oa, const Version& version );

// Art_Wegweiser_dynamisch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Wegweiser_dynamisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Wegweiser_dynamisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Wegweiser_dynamisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Wegweiser_dynamisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Wegweiser_dynamisch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Wegweiser_dynamisch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Wegweiser_dynamisch( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Wegweiser_dynamisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Wegweiser_dynamisch(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Wegweiser_dynamisch(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Wegweiser_dynamisch(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Wegweiser_dynamisch(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lesbarkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lesbarkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lesbarkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lesbarkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lesbarkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lesbarkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lesbarkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lesbarkeit( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lesbarkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lesbarkeit(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lesbarkeit(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lesbarkeit(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lesbarkeit(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenbezug

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenbezug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenbezug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenbezug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenbezug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenbezug( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenbezug( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenbezug( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Strassenbezug(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Strassenbezug(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Strassenbezug(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Strassenbezug(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Strassenbezug(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Einzel_Mehrfach_Schild

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einzel_Mehrfach_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einzel_Mehrfach_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einzel_Mehrfach_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Einzel_Mehrfach_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einzel_Mehrfach_Schild( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einzel_Mehrfach_Schild( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einzel_Mehrfach_Schild( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Einzel_Mehrfach_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Einzel_Mehrfach_Schild(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Einzel_Mehrfach_Schild(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Einzel_Mehrfach_Schild(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Einzel_Mehrfach_Schild(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Beleuchtung_Verkehrszeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beleuchtung_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beleuchtung_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beleuchtung_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Beleuchtung_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beleuchtung_Verkehrszeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beleuchtung_Verkehrszeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beleuchtung_Verkehrszeichen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Beleuchtung_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Beleuchtung_Verkehrszeichen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Beleuchtung_Verkehrszeichen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Beleuchtung_Verkehrszeichen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Beleuchtung_Verkehrszeichen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Groesse_Verkehrszeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Groesse_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Groesse_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Groesse_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Groesse_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Groesse_Verkehrszeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Groesse_Verkehrszeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Groesse_Verkehrszeichen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Groesse_Verkehrszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Groesse_Verkehrszeichen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Groesse_Verkehrszeichen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Groesse_Verkehrszeichen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Groesse_Verkehrszeichen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Symbol_graphisch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Symbol_graphisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Symbol_graphisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Symbol_graphisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Symbol_graphisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Symbol_graphisch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Symbol_graphisch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Symbol_graphisch( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Symbol_graphisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Symbol_graphisch(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Symbol_graphisch(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Symbol_graphisch(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Symbol_graphisch(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Symbol_graphisch(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrszeichen_amtlich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrszeichen_amtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrszeichen_amtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrszeichen_amtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrszeichen_amtlich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrszeichen_amtlich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrszeichen_amtlich( const Objektart& oa, const Version& version );

// Verkehrszeichen_nichtamtl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrszeichen_nichtamtl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrszeichen_nichtamtl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrszeichen_nichtamtl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrszeichen_nichtamtl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrszeichen_nichtamtl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrszeichen_nichtamtl( const Objektart& oa, const Version& version );

// Verkehrszeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrszeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrszeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrszeichen( const Objektart& oa, const Version& version );

// Art_VZ_nichtamtl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_VZ_nichtamtl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_VZ_nichtamtl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_VZ_nichtamtl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_VZ_nichtamtl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_VZ_nichtamtl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_VZ_nichtamtl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_VZ_nichtamtl( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_VZ_nichtamtl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_VZ_nichtamtl(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_VZ_nichtamtl(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_VZ_nichtamtl(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_VZ_nichtamtl(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Aufstellvorrichtung_Schild

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufstellvorrichtung_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufstellvorrichtung_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufstellvorrichtung_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufstellvorrichtung_Schild( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufstellvorrichtung_Schild( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufstellvorrichtung_Schild( const Objektart& oa, const Version& version );

// Schild_amtlich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schild_amtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schild_amtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schild_amtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schild_amtlich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schild_amtlich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schild_amtlich( const Objektart& oa, const Version& version );

// Schild_nichtamtlich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schild_nichtamtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schild_nichtamtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schild_nichtamtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schild_nichtamtlich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schild_nichtamtlich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schild_nichtamtlich( const Objektart& oa, const Version& version );

// Schild

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schild( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schild( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schild( const Objektart& oa, const Version& version );

// Lage_Schild

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Schild( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Schild( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Schild( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Schild(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Schild(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Schild(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Schild(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Beleuchtung_Schild

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beleuchtung_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beleuchtung_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beleuchtung_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Beleuchtung_Schild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beleuchtung_Schild( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beleuchtung_Schild( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beleuchtung_Schild( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Beleuchtung_Schild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Beleuchtung_Schild(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Beleuchtung_Schild(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Beleuchtung_Schild(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Beleuchtung_Schild(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ausfuehrungstyp_Wegweiser

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausfuehrungstyp_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausfuehrungstyp_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausfuehrungstyp_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ausfuehrungstyp_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausfuehrungstyp_Wegweiser( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausfuehrungstyp_Wegweiser( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausfuehrungstyp_Wegweiser( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ausfuehrungstyp_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ausfuehrungstyp_Wegweiser(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ausfuehrungstyp_Wegweiser(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ausfuehrungstyp_Wegweiser(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ausfuehrungstyp_Wegweiser(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Wegweiser

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Wegweiser( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Wegweiser( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Wegweiser( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Wegweiser(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Wegweiser(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Wegweiser(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Wegweiser(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Groessenklasse_VZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Groessenklasse_VZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Groessenklasse_VZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Groessenklasse_VZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Groessenklasse_VZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Groessenklasse_VZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Groessenklasse_VZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Groessenklasse_VZ( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Groessenklasse_VZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Groessenklasse_VZ(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Groessenklasse_VZ(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Groessenklasse_VZ(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Groessenklasse_VZ(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Schild_nichtamtlich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Schild_nichtamtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Schild_nichtamtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Schild_nichtamtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Schild_nichtamtlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Schild_nichtamtlich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Schild_nichtamtlich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Schild_nichtamtlich( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Schild_nichtamtlich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Schild_nichtamtlich(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Schild_nichtamtlich(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Schild_nichtamtlich(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Schild_nichtamtlich(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wegweiser_Summe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweiser_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweiser_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweiser_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweiser_Summe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweiser_Summe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweiser_Summe( const Objektart& oa, const Version& version );

// Verkehrszeichen_Summe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrszeichen_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrszeichen_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrszeichen_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrszeichen_Summe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrszeichen_Summe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrszeichen_Summe( const Objektart& oa, const Version& version );

// Schild_nichtamtlich_Summe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schild_nichtamtlich_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schild_nichtamtlich_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schild_nichtamtlich_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schild_nichtamtlich_Summe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schild_nichtamtlich_Summe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schild_nichtamtlich_Summe( const Objektart& oa, const Version& version );

// Beschilderung_Summe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beschilderung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beschilderung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beschilderung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beschilderung_Summe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beschilderung_Summe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beschilderung_Summe( const Objektart& oa, const Version& version );

// Telematik_Zaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Telematik_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Telematik_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Telematik_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Telematik_Zaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Telematik_Zaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Telematik_Zaehlstelle( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Telematik_Zaehlstelle(const Version& vsn);

// sonstige_Zaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_sonstige_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_sonstige_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_sonstige_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_sonstige_Zaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_sonstige_Zaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_sonstige_Zaehlstelle( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_sonstige_Zaehlstelle(const Version& vsn);

// Uebermittlungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Uebermittlungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Uebermittlungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Uebermittlungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Uebermittlungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Uebermittlungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Uebermittlungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Uebermittlungsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Uebermittlungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Uebermittlungsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Uebermittlungsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Uebermittlungsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Uebermittlungsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Unfalldichte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfalldichte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfalldichte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfalldichte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfalldichte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfalldichte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfalldichte( const Objektart& oa, const Version& version );

// Unfallrate

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallrate( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallrate( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallrate( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallrate( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallrate( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallrate( const Objektart& oa, const Version& version );

// Unfallkenngroesse_Strecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallkenngroesse_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallkenngroesse_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallkenngroesse_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallkenngroesse_Strecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallkenngroesse_Strecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallkenngroesse_Strecke( const Objektart& oa, const Version& version );

// Ausschnitt_Unfallgeschehen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausschnitt_Unfallgeschehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausschnitt_Unfallgeschehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausschnitt_Unfallgeschehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ausschnitt_Unfallgeschehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausschnitt_Unfallgeschehen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausschnitt_Unfallgeschehen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausschnitt_Unfallgeschehen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ausschnitt_Unfallgeschehen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ausschnitt_Unfallgeschehen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ausschnitt_Unfallgeschehen(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ausschnitt_Unfallgeschehen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ausschnitt_Unfallgeschehen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ausschnitt_Unfallgeschehen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Multigeometrieobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Multigeometrieobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Multigeometrieobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Multigeometrieobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Multigeometrieobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Multigeometrieobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Multigeometrieobjekt( const Objektart& oa, const Version& version );

// Punktgeometrie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktgeometrie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktgeometrie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktgeometrie( const Objektart& oa, const Version& version );

// Liniengeometrie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Liniengeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Liniengeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Liniengeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Liniengeometrie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Liniengeometrie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Liniengeometrie( const Objektart& oa, const Version& version );

// Koordinatenherkunft_Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Koordinatenherkunft_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Koordinatenherkunft_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Koordinatenherkunft_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Koordinatenherkunft_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Koordinatenherkunft_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Koordinatenherkunft_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Koordinatenherkunft_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Koordinatenherkunft_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Koordinatenherkunft_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Koordinatenherkunft_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Koordinatenherkunft_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Koordinatenherkunft_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// geodaetisches_Datum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_geodaetisches_Datum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_geodaetisches_Datum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_geodaetisches_Datum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_geodaetisches_Datum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_geodaetisches_Datum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_geodaetisches_Datum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_geodaetisches_Datum( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_geodaetisches_Datum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_geodaetisches_Datum(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_geodaetisches_Datum(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_geodaetisches_Datum(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_geodaetisches_Datum(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Koordinatensystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Koordinatensystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Koordinatensystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Koordinatensystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Koordinatensystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Koordinatensystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Koordinatensystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Koordinatensystem( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Koordinatensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Koordinatensystem(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Koordinatensystem(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Koordinatensystem(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Koordinatensystem(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Achse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Achse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Achse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Achse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Achse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Achse(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Achse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Achse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Achse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Netzfunktion_Achse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzfunktion_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzfunktion_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzfunktion_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Netzfunktion_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzfunktion_Achse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzfunktion_Achse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzfunktion_Achse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Netzfunktion_Achse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Netzfunktion_Achse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Netzfunktion_Achse(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Netzfunktion_Achse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Netzfunktion_Achse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Netzfunktion_Achse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Gelaendehorizont

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Gelaendehorizont( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Gelaendehorizont( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Gelaendehorizont( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Gelaendehorizont( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Gelaendehorizont( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Gelaendehorizont( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Gelaendehorizont( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Gelaendehorizont(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Gelaendehorizont(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Gelaendehorizont(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Gelaendehorizont(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Gelaendehorizont(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Gelaendehorizont(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Gradiente

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Gradiente( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Gradiente( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Gradiente( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Gradiente(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Gradiente(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Gradiente(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Gradiente(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Gradiente(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Gradiente(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_kreuzendes_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_kreuzendes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_kreuzendes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_kreuzendes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_kreuzendes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_kreuzendes_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_kreuzendes_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_kreuzendes_Bauwerk( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_kreuzendes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_kreuzendes_Bauwerk(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_kreuzendes_Bauwerk(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_kreuzendes_Bauwerk(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_kreuzendes_Bauwerk(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_kreuzendes_Bauwerk(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_QP_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_QP_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_QP_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_QP_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_QP_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_QP_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_QP_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_QP_Punkt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_QP_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_QP_Punkt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_QP_Punkt(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_QP_Punkt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_QP_Punkt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_QP_Punkt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Profillinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Profillinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Profillinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Profillinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Profillinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Profillinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Profillinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Profillinie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Profillinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Profillinie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Profillinie(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Profillinie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Profillinie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Profillinie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Spur_aus_Ausgangsdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Spur_aus_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Spur_aus_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Spur_aus_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Spur_aus_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Spur_aus_Ausgangsdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Spur_aus_Ausgangsdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Spur_aus_Ausgangsdaten( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Spur_aus_Ausgangsdaten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Spur_aus_Ausgangsdaten(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Spur_aus_Ausgangsdaten(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Spur_aus_Ausgangsdaten(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Spur_aus_Ausgangsdaten(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Spur_aus_Ausgangsdaten(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Geschwindigkeitsband

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Geschwindigkeitsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Geschwindigkeitsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Geschwindigkeitsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Geschwindigkeitsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Geschwindigkeitsband( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Geschwindigkeitsband( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Geschwindigkeitsband( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Geschwindigkeitsband(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Geschwindigkeitsband(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Geschwindigkeitsband(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Geschwindigkeitsband(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Geschwindigkeitsband(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Geschwindigkeitsband(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Sichtweiten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Sichtweiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Sichtweiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Sichtweiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Sichtweiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Sichtweiten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Sichtweiten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Sichtweiten( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Sichtweiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Sichtweiten(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Sichtweiten(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Sichtweiten(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Sichtweiten(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Sichtweiten(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenkategorie_RAS_N_RIN

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenkategorie_RAS_N_RIN( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenkategorie_RAS_N_RIN( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenkategorie_RAS_N_RIN( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenkategorie_RAS_N_RIN( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenkategorie_RAS_N_RIN( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenkategorie_RAS_N_RIN( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenkategorie_RAS_N_RIN( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Strassenkategorie_RAS_N_RIN(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Strassenkategorie_RAS_N_RIN(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Strassenkategorie_RAS_N_RIN(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Strassenkategorie_RAS_N_RIN(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Strassenkategorie_RAS_N_RIN(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grad_Koor

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grad_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grad_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grad_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Grad_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grad_Koor( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grad_Koor( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grad_Koor( const Objektart& oa, const Version& version );

// Horizontlinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Horizontlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Horizontlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Horizontlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Horizontlinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Horizontlinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Horizontlinie( const Objektart& oa, const Version& version );

// Art_Horizontlinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Horizontlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Horizontlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Horizontlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Horizontlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Horizontlinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Horizontlinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Horizontlinie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Horizontlinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Horizontlinie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Horizontlinie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Horizontlinie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Horizontlinie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Hor_Koor

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hor_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hor_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hor_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hor_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hor_Koor( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hor_Koor( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hor_Koor( const Objektart& oa, const Version& version );

// Profillinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Profillinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Profillinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Profillinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Profillinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Profillinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Profillinie( const Objektart& oa, const Version& version );

// QP_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_QP_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_QP_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_QP_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_QP_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_QP_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_QP_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_QP_Punkt( const Objektart& oa, const Version& version );

// Spur

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Spur( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Spur( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Spur( const Objektart& oa, const Version& version );

// Hochbordspur

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hochbordspur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hochbordspur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hochbordspur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hochbordspur( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hochbordspur( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hochbordspur( const Objektart& oa, const Version& version );

// verallg_Spur

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verallg_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verallg_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verallg_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_verallg_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verallg_Spur( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verallg_Spur( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verallg_Spur( const Objektart& oa, const Version& version );

// Art_verallg_Spur

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_verallg_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_verallg_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_verallg_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_verallg_Spur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_verallg_Spur( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_verallg_Spur( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_verallg_Spur( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_verallg_Spur(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_verallg_Spur(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_verallg_Spur(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_verallg_Spur(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_verallg_Spur(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Breitenband

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Breitenband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Breitenband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Breitenband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Breitenband( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Breitenband( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Breitenband( const Objektart& oa, const Version& version );

// Bedeutung_Berechnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bedeutung_Berechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bedeutung_Berechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bedeutung_Berechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bedeutung_Berechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bedeutung_Berechnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bedeutung_Berechnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bedeutung_Berechnung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bedeutung_Berechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bedeutung_Berechnung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bedeutung_Berechnung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bedeutung_Berechnung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bedeutung_Berechnung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Querneigungsband

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Querneigungsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Querneigungsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Querneigungsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Querneigungsband( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Querneigungsband( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Querneigungsband( const Objektart& oa, const Version& version );

// Hoehenzug

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenzug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenzug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenzug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenzug( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenzug( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenzug( const Objektart& oa, const Version& version );

// anderes_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_anderes_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_anderes_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_anderes_Bauwerk( const Objektart& oa, const Version& version );

// Art_anderes_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_anderes_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_anderes_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_anderes_Bauwerk( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_anderes_Bauwerk(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_anderes_Bauwerk(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_anderes_Bauwerk(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_anderes_Bauwerk(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_anderes_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_anderes_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_anderes_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_anderes_Bauwerk( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_anderes_Bauwerk(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_anderes_Bauwerk(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_anderes_Bauwerk(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_anderes_Bauwerk(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_anderes_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_anderes_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_anderes_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_anderes_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_anderes_Bauwerk( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_anderes_Bauwerk(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_anderes_Bauwerk(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_anderes_Bauwerk(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_anderes_Bauwerk(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_anderes_Bauwerk(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Adsorptionsfaehigkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Adsorptionsfaehigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Adsorptionsfaehigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Adsorptionsfaehigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Adsorptionsfaehigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Adsorptionsfaehigkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Adsorptionsfaehigkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Adsorptionsfaehigkeit( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Adsorptionsfaehigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Adsorptionsfaehigkeit(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Adsorptionsfaehigkeit(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Adsorptionsfaehigkeit(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Adsorptionsfaehigkeit(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Laermschutzwall

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Laermschutzwall( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Laermschutzwall( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Laermschutzwall( const Objektart& oa, const Version& version );

// Art_Laermschutzwall

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Laermschutzwall( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Laermschutzwall( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Laermschutzwall( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Laermschutzwall(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Laermschutzwall(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Laermschutzwall(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Laermschutzwall(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_Laermschutzwall

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_Laermschutzwall( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_Laermschutzwall( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_Laermschutzwall( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_Laermschutzwall(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_Laermschutzwall(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_Laermschutzwall(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_Laermschutzwall(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Laermschutzwall

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Laermschutzwall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Laermschutzwall( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Laermschutzwall( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Laermschutzwall( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Laermschutzwall(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Laermschutzwall(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Laermschutzwall(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Laermschutzwall(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Laermschutzwall(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Absorbtionsfaehigkeit_LSW

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Absorbtionsfaehigkeit_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Absorbtionsfaehigkeit_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Absorbtionsfaehigkeit_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Absorbtionsfaehigkeit_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Absorbtionsfaehigkeit_LSW( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Absorbtionsfaehigkeit_LSW( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Absorbtionsfaehigkeit_LSW( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Absorbtionsfaehigkeit_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Absorbtionsfaehigkeit_LSW(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Absorbtionsfaehigkeit_LSW(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Absorbtionsfaehigkeit_LSW(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Absorbtionsfaehigkeit_LSW(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_part_Baulasttraeger_LSW

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_part_Baulasttraeger_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_part_Baulasttraeger_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_part_Baulasttraeger_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_part_Baulasttraeger_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_part_Baulasttraeger_LSW( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_part_Baulasttraeger_LSW( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_part_Baulasttraeger_LSW( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_part_Baulasttraeger_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_part_Baulasttraeger_LSW(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_part_Baulasttraeger_LSW(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_part_Baulasttraeger_LSW(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_part_Baulasttraeger_LSW(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_part_UI_Partner_LSW

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_part_UI_Partner_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_part_UI_Partner_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_part_UI_Partner_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_part_UI_Partner_LSW( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_part_UI_Partner_LSW( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_part_UI_Partner_LSW( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_part_UI_Partner_LSW( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_part_UI_Partner_LSW(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_part_UI_Partner_LSW(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_part_UI_Partner_LSW(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_part_UI_Partner_LSW(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_part_UI_Partner_LSW(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Sonstige_Konstruktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sonstige_Konstruktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sonstige_Konstruktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sonstige_Konstruktion( const Objektart& oa, const Version& version );

// Art_sonstige_Konstruktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_sonstige_Konstruktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_sonstige_Konstruktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_sonstige_Konstruktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_sonstige_Konstruktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_sonstige_Konstruktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_sonstige_Konstruktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_sonstige_Konstruktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Konstruktion_sonst_Konst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Konstruktion_sonst_Konst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Konstruktion_sonst_Konst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Konstruktion_sonst_Konst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Konstruktion_sonst_Konst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Konstruktion_sonst_Konst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Konstruktion_sonst_Konst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Konstruktion_sonst_Konst( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Konstruktion_sonst_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Konstruktion_sonst_Konst(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Konstruktion_sonst_Konst(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Konstruktion_sonst_Konst(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Konstruktion_sonst_Konst(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fkt_sonstige_Konstruktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fkt_sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fkt_sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fkt_sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fkt_sonstige_Konstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fkt_sonstige_Konstruktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fkt_sonstige_Konstruktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fkt_sonstige_Konstruktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fkt_sonstige_Konstruktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fkt_sonstige_Konstruktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fkt_sonstige_Konstruktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fkt_sonstige_Konstruktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fkt_sonstige_Konstruktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Absorbtionsfaehigkeit_Konst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Absorbtionsfaehigkeit_Konst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Absorbtionsfaehigkeit_Konst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Absorbtionsfaehigkeit_Konst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Absorbtionsfaehigkeit_Konst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Absorbtionsfaehigkeit_Konst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Absorbtionsfaehigkeit_Konst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Absorbtionsfaehigkeit_Konst( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Absorbtionsfaehigkeit_Konst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Absorbtionsfaehigkeit_Konst(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Absorbtionsfaehigkeit_Konst(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Absorbtionsfaehigkeit_Konst(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Absorbtionsfaehigkeit_Konst(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_sonstige_Konstr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_sonstige_Konstr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_sonstige_Konstr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_sonstige_Konstr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_sonstige_Konstr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_sonstige_Konstr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_sonstige_Konstr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_sonstige_Konstr( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_sonstige_Konstr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_sonstige_Konstr(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_sonstige_Konstr(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_sonstige_Konstr(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_sonstige_Konstr(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schaden_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schaden_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schaden_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schaden_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schaden_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schaden_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schaden_Bauwerk( const Objektart& oa, const Version& version );

// Empfehlung_BMS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Empfehlung_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Empfehlung_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Empfehlung_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Empfehlung_BMS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Empfehlung_BMS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Empfehlung_BMS( const Objektart& oa, const Version& version );

// Empfehlung_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Empfehlung_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Empfehlung_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Empfehlung_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Empfehlung_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Empfehlung_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Empfehlung_Bauwerk( const Objektart& oa, const Version& version );

// Strategie_BMS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strategie_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strategie_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strategie_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strategie_BMS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strategie_BMS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strategie_BMS( const Objektart& oa, const Version& version );

// Kostenkatalog_BMS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kostenkatalog_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kostenkatalog_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kostenkatalog_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kostenkatalog_BMS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kostenkatalog_BMS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kostenkatalog_BMS( const Objektart& oa, const Version& version );

// Kostenkatalogeintrag_BMS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kostenkatalogeintrag_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kostenkatalogeintrag_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kostenkatalogeintrag_BMS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kostenkatalogeintrag_BMS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kostenkatalogeintrag_BMS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kostenkatalogeintrag_BMS( const Objektart& oa, const Version& version );

// Bezugseinheit_Kostenkatalog

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bezugseinheit_Kostenkatalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bezugseinheit_Kostenkatalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bezugseinheit_Kostenkatalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bezugseinheit_Kostenkatalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bezugseinheit_Kostenkatalog( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bezugseinheit_Kostenkatalog( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bezugseinheit_Kostenkatalog( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bezugseinheit_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bezugseinheit_Kostenkatalog(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Bezugseinheit_Kostenkatalog(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bezugseinheit_Kostenkatalog(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bezugseinheit_Kostenkatalog(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bezugseinheit_Kostenkatalog(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zuordkatalog_Schadbsp_Massn

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zuordkatalog_Schadbsp_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zuordkatalog_Schadbsp_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zuordkatalog_Schadbsp_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zuordkatalog_Schadbsp_Massn( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zuordkatalog_Schadbsp_Massn( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zuordkatalog_Schadbsp_Massn( const Objektart& oa, const Version& version );

// Kateintrag_Schadbsp_Massn

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kateintrag_Schadbsp_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kateintrag_Schadbsp_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kateintrag_Schadbsp_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kateintrag_Schadbsp_Massn( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kateintrag_Schadbsp_Massn( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kateintrag_Schadbsp_Massn( const Objektart& oa, const Version& version );

// Bezugsgroesse_Kostenkatalog

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bezugsgroesse_Kostenkatalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bezugsgroesse_Kostenkatalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bezugsgroesse_Kostenkatalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bezugsgroesse_Kostenkatalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bezugsgroesse_Kostenkatalog( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bezugsgroesse_Kostenkatalog( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bezugsgroesse_Kostenkatalog( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bezugsgroesse_Kostenkatalog(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bezugsgroesse_Kostenkatalog(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bezugsgroesse_Kostenkatalog(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bezugsgroesse_Kostenkatalog(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bezugsgroesse_Kostenkatalog(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Betriebsstaette

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betriebsstaette( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betriebsstaette( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betriebsstaette( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betriebsstaette( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betriebsstaette( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betriebsstaette( const Objektart& oa, const Version& version );

// Betriebseinrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betriebseinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betriebseinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betriebseinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betriebseinrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betriebseinrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betriebseinrichtung( const Objektart& oa, const Version& version );

// Betriebsobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betriebsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betriebsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betriebsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betriebsobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betriebsobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betriebsobjekt( const Objektart& oa, const Version& version );

// Art_der_Betriebsstaette

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Betriebsstaette( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Betriebsstaette( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Betriebsstaette( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Betriebsstaette( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Betriebsstaette( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Betriebsstaette( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Betriebsstaette( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Betriebsstaette(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Betriebsstaette(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Betriebsstaette(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Betriebsstaette(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Betriebsstaette(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Betriebseinrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Betriebseinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Betriebseinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Betriebseinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Betriebseinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Betriebseinrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Betriebseinrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Betriebseinrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Betriebseinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Betriebseinrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Betriebseinrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Betriebseinrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Betriebseinrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Rastanlage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Rastanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Rastanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Rastanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Rastanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Rastanlage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Rastanlage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Rastanlage( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Rastanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Rastanlage(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Rastanlage(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Rastanlage(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Rastanlage(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Sondereinrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sondereinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sondereinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sondereinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sondereinrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sondereinrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sondereinrichtung( const Objektart& oa, const Version& version );

// Art_Sondereinrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Sondereinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Sondereinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Sondereinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Sondereinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Sondereinrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Sondereinrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Sondereinrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Sondereinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Sondereinrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Sondereinrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Sondereinrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Sondereinrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenausstattung_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenausstattung_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenausstattung_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenausstattung_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenausstattung_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenausstattung_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenausstattung_Punkt( const Objektart& oa, const Version& version );

// Art_Strassenausst_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Strassenausst_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Strassenausst_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Strassenausst_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Strassenausst_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Strassenausst_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Strassenausst_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Strassenausst_Punkt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Strassenausst_Punkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Strassenausst_Punkt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Strassenausst_Punkt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Strassenausst_Punkt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Strassenausst_Punkt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenausstattung_Strecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenausstattung_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenausstattung_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenausstattung_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenausstattung_Strecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenausstattung_Strecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenausstattung_Strecke( const Objektart& oa, const Version& version );

// Art_Strassenausst_Strecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Strassenausst_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Strassenausst_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Strassenausst_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Strassenausst_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Strassenausst_Strecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Strassenausst_Strecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Strassenausst_Strecke( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Strassenausst_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Strassenausst_Strecke(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Strassenausst_Strecke(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Strassenausst_Strecke(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Strassenausst_Strecke(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schutzeinrichtung_fuer_Tiere

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzeinrichtung_fuer_Tiere( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzeinrichtung_fuer_Tiere( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzeinrichtung_fuer_Tiere( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzeinrichtung_fuer_Tiere( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzeinrichtung_fuer_Tiere( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzeinrichtung_fuer_Tiere( const Objektart& oa, const Version& version );

// Art_Schutzeinrichtung_Tier

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Schutzeinrichtung_Tier( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Schutzeinrichtung_Tier( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Schutzeinrichtung_Tier( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Schutzeinrichtung_Tier( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Schutzeinrichtung_Tier( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Schutzeinrichtung_Tier( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Schutzeinrichtung_Tier( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Schutzeinrichtung_Tier(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Schutzeinrichtung_Tier(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Schutzeinrichtung_Tier(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Schutzeinrichtung_Tier(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Schutzeinrichtung_Tier(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bewuchs_Schutzeinr_Tiere

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bewuchs_Schutzeinr_Tiere( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bewuchs_Schutzeinr_Tiere( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bewuchs_Schutzeinr_Tiere( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bewuchs_Schutzeinr_Tiere( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bewuchs_Schutzeinr_Tiere( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bewuchs_Schutzeinr_Tiere( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bewuchs_Schutzeinr_Tiere( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bewuchs_Schutzeinr_Tiere(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bewuchs_Schutzeinr_Tiere(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bewuchs_Schutzeinr_Tiere(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bewuchs_Schutzeinr_Tiere(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bewuchs_Schutzeinr_Tiere(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Leitpfostenstrecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leitpfostenstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leitpfostenstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leitpfostenstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leitpfostenstrecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leitpfostenstrecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leitpfostenstrecke( const Objektart& oa, const Version& version );

// Art_Leitung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Leitung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Leitung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Leitung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Leitung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Leitung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Leitung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Leitung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Leitung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Leitung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Leitung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Leitung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Leitung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Leitung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Leitung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Leitung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Betreiber_Leitung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betreiber_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betreiber_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betreiber_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Betreiber_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betreiber_Leitung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betreiber_Leitung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betreiber_Leitung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Betreiber_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Betreiber_Leitung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Betreiber_Leitung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Betreiber_Leitung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Betreiber_Leitung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schutzwand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzwand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzwand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzwand( const Objektart& oa, const Version& version );

// Anpralldaempfer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anpralldaempfer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anpralldaempfer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anpralldaempfer( const Objektart& oa, const Version& version );

// Bremsbett

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bremsbett( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bremsbett( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bremsbett( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bremsbett( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bremsbett( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bremsbett( const Objektart& oa, const Version& version );

// Fussgaenger_Rueckhsystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fussgaenger_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fussgaenger_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fussgaenger_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fussgaenger_Rueckhsystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fussgaenger_Rueckhsystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fussgaenger_Rueckhsystem( const Objektart& oa, const Version& version );

// Rueckhaltesystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rueckhaltesystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rueckhaltesystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rueckhaltesystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rueckhaltesystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rueckhaltesystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rueckhaltesystem( const Objektart& oa, const Version& version );

// Standort_Schutzpl_Schutzwand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Standort_Schutzpl_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Standort_Schutzpl_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Standort_Schutzpl_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Standort_Schutzpl_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Standort_Schutzpl_Schutzwand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Standort_Schutzpl_Schutzwand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Standort_Schutzpl_Schutzwand( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Standort_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Standort_Schutzpl_Schutzwand(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Standort_Schutzpl_Schutzwand(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Standort_Schutzpl_Schutzwand(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Standort_Schutzpl_Schutzwand(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Typ_Schutzplanke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_Schutzplanke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_Schutzplanke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_Schutzplanke( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_Schutzplanke(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_Schutzplanke(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_Schutzplanke(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_Schutzplanke(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Schutzplanke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Schutzplanke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Schutzplanke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Schutzplanke( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Schutzplanke(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Schutzplanke(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Schutzplanke(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Schutzplanke(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Schutzplanke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Schutzplanke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Schutzplanke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Schutzplanke( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Schutzplanke(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Schutzplanke(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Schutzplanke(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Schutzplanke(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Pfostenkonstruktion_Schutzpl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pfostenkonstruktion_Schutzpl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pfostenkonstruktion_Schutzpl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pfostenkonstruktion_Schutzpl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Pfostenkonstruktion_Schutzpl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pfostenkonstruktion_Schutzpl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pfostenkonstruktion_Schutzpl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pfostenkonstruktion_Schutzpl( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Pfostenkonstruktion_Schutzpl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Pfostenkonstruktion_Schutzpl(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Pfostenkonstruktion_Schutzpl(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Pfostenkonstruktion_Schutzpl(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Pfostenkonstruktion_Schutzpl(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_Schutzpl_Schutzwand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_Schutzpl_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_Schutzpl_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_Schutzpl_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_Schutzpl_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_Schutzpl_Schutzwand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_Schutzpl_Schutzwand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_Schutzpl_Schutzwand( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_Schutzpl_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_Schutzpl_Schutzwand(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_Schutzpl_Schutzwand(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_Schutzpl_Schutzwand(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_Schutzpl_Schutzwand(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Absenkung_Schutzplanke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Absenkung_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Absenkung_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Absenkung_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Absenkung_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Absenkung_Schutzplanke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Absenkung_Schutzplanke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Absenkung_Schutzplanke( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Absenkung_Schutzplanke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Absenkung_Schutzplanke(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Absenkung_Schutzplanke(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Absenkung_Schutzplanke(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Absenkung_Schutzplanke(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Typ_Schutzwand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_Schutzwand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_Schutzwand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_Schutzwand( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_Schutzwand(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_Schutzwand(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_Schutzwand(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_Schutzwand(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bauart_Schutzwand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauart_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauart_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauart_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bauart_Schutzwand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauart_Schutzwand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauart_Schutzwand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauart_Schutzwand( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bauart_Schutzwand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bauart_Schutzwand(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bauart_Schutzwand(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bauart_Schutzwand(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bauart_Schutzwand(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Standort_Anpralldaempfer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Standort_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Standort_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Standort_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Standort_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Standort_Anpralldaempfer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Standort_Anpralldaempfer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Standort_Anpralldaempfer( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Standort_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Standort_Anpralldaempfer(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Standort_Anpralldaempfer(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Standort_Anpralldaempfer(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Standort_Anpralldaempfer(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Typ_Anpralldaempfer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_Anpralldaempfer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_Anpralldaempfer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_Anpralldaempfer( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_Anpralldaempfer(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_Anpralldaempfer(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_Anpralldaempfer(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_Anpralldaempfer(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Anpralldaempfer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Anpralldaempfer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Anpralldaempfer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Anpralldaempfer( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Anpralldaempfer(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Anpralldaempfer(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Anpralldaempfer(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Anpralldaempfer(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Leistungskl_Anpralldaempfer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leistungskl_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leistungskl_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leistungskl_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Leistungskl_Anpralldaempfer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leistungskl_Anpralldaempfer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leistungskl_Anpralldaempfer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leistungskl_Anpralldaempfer( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Leistungskl_Anpralldaempfer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Leistungskl_Anpralldaempfer(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Leistungskl_Anpralldaempfer(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Leistungskl_Anpralldaempfer(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Leistungskl_Anpralldaempfer(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Typ_Fussgaenger_Rueckhsystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_Fussgaenger_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_Fussgaenger_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_Fussgaenger_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_Fussgaenger_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_Fussgaenger_Rueckhsystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_Fussgaenger_Rueckhsystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_Fussgaenger_Rueckhsystem( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_Fussgaenger_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_Fussgaenger_Rueckhsystem(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_Fussgaenger_Rueckhsystem(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_Fussgaenger_Rueckhsystem(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_Fussgaenger_Rueckhsystem(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_Fussg_Rueckhsystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_Fussg_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_Fussg_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_Fussg_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_Fussg_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_Fussg_Rueckhsystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_Fussg_Rueckhsystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_Fussg_Rueckhsystem( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_Fussg_Rueckhsystem(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_Fussg_Rueckhsystem(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_Fussg_Rueckhsystem(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_Fussg_Rueckhsystem(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Fussg_Rueckhsystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Fussg_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Fussg_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Fussg_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Fussg_Rueckhsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Fussg_Rueckhsystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Fussg_Rueckhsystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Fussg_Rueckhsystem( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Fussg_Rueckhsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Fussg_Rueckhsystem(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Fussg_Rueckhsystem(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Fussg_Rueckhsystem(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Fussg_Rueckhsystem(const Version& vsn, const Text& key, Text& value, const int& nVal);

// entwaesserte_Flaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_entwaesserte_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_entwaesserte_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_entwaesserte_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_entwaesserte_Flaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_entwaesserte_Flaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_entwaesserte_Flaeche( const Objektart& oa, const Version& version );

// Art_entwaesserte_Flaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_entwaesserte_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_entwaesserte_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_entwaesserte_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_entwaesserte_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_entwaesserte_Flaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_entwaesserte_Flaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_entwaesserte_Flaeche( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_entwaesserte_Flaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_entwaesserte_Flaeche(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_entwaesserte_Flaeche(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_entwaesserte_Flaeche(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_entwaesserte_Flaeche(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wassereinleitungsstrecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wassereinleitungsstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wassereinleitungsstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wassereinleitungsstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wassereinleitungsstrecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wassereinleitungsstrecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wassereinleitungsstrecke( const Objektart& oa, const Version& version );

// Art_Wassereinleitungsstrecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Wassereinleitungsstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Wassereinleitungsstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Wassereinleitungsstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Wassereinleitungsstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Wassereinleitungsstrecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Wassereinleitungsstrecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Wassereinleitungsstrecke( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Wassereinleitungsstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Wassereinleitungsstrecke(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Wassereinleitungsstrecke(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Wassereinleitungsstrecke(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Wassereinleitungsstrecke(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wassereinleitungspunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wassereinleitungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wassereinleitungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wassereinleitungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wassereinleitungspunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wassereinleitungspunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wassereinleitungspunkt( const Objektart& oa, const Version& version );

// Art_Wassereinleitungspunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Wassereinleitungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Wassereinleitungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Wassereinleitungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Wassereinleitungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Wassereinleitungspunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Wassereinleitungspunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Wassereinleitungspunkt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Wassereinleitungspunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Wassereinleitungspunkt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Wassereinleitungspunkt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Wassereinleitungspunkt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Wassereinleitungspunkt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// zust_Dritter_Wassereinlpkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zust_Dritter_Wassereinlpkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zust_Dritter_Wassereinlpkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zust_Dritter_Wassereinlpkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_zust_Dritter_Wassereinlpkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zust_Dritter_Wassereinlpkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zust_Dritter_Wassereinlpkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zust_Dritter_Wassereinlpkt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_zust_Dritter_Wassereinlpkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_zust_Dritter_Wassereinlpkt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_zust_Dritter_Wassereinlpkt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_zust_Dritter_Wassereinlpkt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_zust_Dritter_Wassereinlpkt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vorschalteinrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vorschalteinrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vorschalteinrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vorschalteinrichtung( const Objektart& oa, const Version& version );

// Art_Vorschalteinrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Vorschalteinrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Vorschalteinrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Vorschalteinrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Vorschalteinrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Vorschalteinrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Vorschalteinrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Vorschalteinrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bauweise_Vorschalteinrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauweise_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauweise_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauweise_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bauweise_Vorschalteinrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauweise_Vorschalteinrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauweise_Vorschalteinrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauweise_Vorschalteinrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bauweise_Vorschalteinrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bauweise_Vorschalteinrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bauweise_Vorschalteinrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bauweise_Vorschalteinrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bauweise_Vorschalteinrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Spindel_Vorschalteinr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Spindel_Vorschalteinr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Spindel_Vorschalteinr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Spindel_Vorschalteinr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Spindel_Vorschalteinr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Spindel_Vorschalteinr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Spindel_Vorschalteinr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Spindel_Vorschalteinr( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Spindel_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Spindel_Vorschalteinr(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Spindel_Vorschalteinr(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Spindel_Vorschalteinr(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Spindel_Vorschalteinr(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Entleerung_Vorschalteinr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entleerung_Vorschalteinr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entleerung_Vorschalteinr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entleerung_Vorschalteinr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Entleerung_Vorschalteinr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entleerung_Vorschalteinr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entleerung_Vorschalteinr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entleerung_Vorschalteinr( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Entleerung_Vorschalteinr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Entleerung_Vorschalteinr(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Entleerung_Vorschalteinr(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Entleerung_Vorschalteinr(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Entleerung_Vorschalteinr(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schacht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schacht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schacht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schacht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schacht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schacht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schacht( const Objektart& oa, const Version& version );

// Art_Schacht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Schacht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Schacht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Schacht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Schacht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Schacht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Schacht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Schacht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Schacht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Schacht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Schacht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Schacht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Schacht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zum_Konus

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zum_Konus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zum_Konus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zum_Konus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Angaben_zum_Konus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zum_Konus( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zum_Konus( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zum_Konus( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Angaben_zum_Konus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Angaben_zum_Konus(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Angaben_zum_Konus(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Angaben_zum_Konus(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Angaben_zum_Konus(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenablauf

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenablauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenablauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenablauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenablauf( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenablauf( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenablauf( const Objektart& oa, const Version& version );

// Art_Aufsatz

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Aufsatz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Aufsatz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Aufsatz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Aufsatz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Aufsatz( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Aufsatz( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Aufsatz( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Aufsatz(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Aufsatz(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Aufsatz(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Aufsatz(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Aufsatz(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Unterteil

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Unterteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Unterteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Unterteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Unterteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Unterteil( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Unterteil( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Unterteil( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Unterteil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Unterteil(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Unterteil(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Unterteil(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Unterteil(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lage_Schacht_Strassenablauf

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Schacht_Strassenablauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Schacht_Strassenablauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Schacht_Strassenablauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Schacht_Strassenablauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Schacht_Strassenablauf( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Schacht_Strassenablauf( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Schacht_Strassenablauf( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Schacht_Strassenablauf(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Schacht_Strassenablauf(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Schacht_Strassenablauf(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Schacht_Strassenablauf(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Schacht_Strassenablauf(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenausstattung_seriell

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenausstattung_seriell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenausstattung_seriell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenausstattung_seriell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenausstattung_seriell( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenausstattung_seriell( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenausstattung_seriell( const Objektart& oa, const Version& version );

// Art_Strassenausst_seriell

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Strassenausst_seriell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Strassenausst_seriell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Strassenausst_seriell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Strassenausst_seriell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Strassenausst_seriell( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Strassenausst_seriell( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Strassenausst_seriell( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Strassenausst_seriell(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Strassenausst_seriell(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Strassenausst_seriell(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Strassenausst_seriell(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Strassenausst_seriell(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenausstattung_Summe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenausstattung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenausstattung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenausstattung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenausstattung_Summe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenausstattung_Summe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenausstattung_Summe( const Objektart& oa, const Version& version );

// Art_Strassenausst_Summe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Strassenausst_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Strassenausst_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Strassenausst_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Strassenausst_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Strassenausst_Summe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Strassenausst_Summe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Strassenausst_Summe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Strassenausst_Summe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Strassenausst_Summe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Strassenausst_Summe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Strassenausst_Summe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Strassenausst_Summe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Stationszeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Stationszeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Stationszeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Stationszeichen( const Objektart& oa, const Version& version );

// Art_Stationszeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Stationszeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Stationszeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Stationszeichen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Stationszeichen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Stationszeichen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Stationszeichen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Stationszeichen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Befest_Stationszeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Befest_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Befest_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Befest_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Befest_Stationszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Befest_Stationszeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Befest_Stationszeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Befest_Stationszeichen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Befest_Stationszeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Befest_Stationszeichen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Befest_Stationszeichen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Befest_Stationszeichen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Befest_Stationszeichen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Leitung_Detail

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Leitung_Detail( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Leitung_Detail( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Leitung_Detail( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Leitung_Detail( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Leitung_Detail( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Leitung_Detail( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Leitung_Detail( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Leitung_Detail(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Leitung_Detail(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Leitung_Detail(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Leitung_Detail(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Leitung_Detail(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Schutzrohr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Schutzrohr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Schutzrohr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Schutzrohr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Schutzrohr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Schutzrohr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Schutzrohr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Schutzrohr( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Schutzrohr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Schutzrohr(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Schutzrohr(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Schutzrohr(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Schutzrohr(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lage_Leitung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Leitung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Leitung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Leitung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Leitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Leitung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Leitung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Leitung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Leitung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lage_Wassereinleitstrecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Wassereinleitstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Wassereinleitstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Wassereinleitstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Wassereinleitstrecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Wassereinleitstrecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Wassereinleitstrecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Wassereinleitstrecke( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Wassereinleitstrecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Wassereinleitstrecke(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Wassereinleitstrecke(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Wassereinleitstrecke(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Wassereinleitstrecke(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Entwaesserung_Summe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwaesserung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwaesserung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwaesserung_Summe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwaesserung_Summe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwaesserung_Summe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwaesserung_Summe( const Objektart& oa, const Version& version );

// Lage_Leitung_Rigole

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Leitung_Rigole( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Leitung_Rigole( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Leitung_Rigole( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Leitung_Rigole( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Leitung_Rigole( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Leitung_Rigole( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Leitung_Rigole( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Leitung_Rigole(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Leitung_Rigole(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Leitung_Rigole(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Leitung_Rigole(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Leitung_Rigole(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Entwaesserung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Entwaesserung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Entwaesserung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Entwaesserung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Entwaesserung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Entwaesserung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Entwaesserung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Entwaesserung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Entwaesserung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grundrisselement_Kreisbogen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundrisselement_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundrisselement_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundrisselement_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundrisselement_Kreisbogen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundrisselement_Kreisbogen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundrisselement_Kreisbogen( const Objektart& oa, const Version& version );

// Grundrisselement_Klothoide

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundrisselement_Klothoide( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundrisselement_Klothoide( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundrisselement_Klothoide( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundrisselement_Klothoide( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundrisselement_Klothoide( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundrisselement_Klothoide( const Objektart& oa, const Version& version );

// Grundrisselement_Gerade

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundrisselement_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundrisselement_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundrisselement_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundrisselement_Gerade( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundrisselement_Gerade( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundrisselement_Gerade( const Objektart& oa, const Version& version );

// Grundrisselement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundrisselement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundrisselement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundrisselement( const Objektart& oa, const Version& version );

// Aufrisselement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufrisselement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufrisselement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufrisselement( const Objektart& oa, const Version& version );

// Art_Aufrisselement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Aufrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Aufrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Aufrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Aufrisselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Aufrisselement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Aufrisselement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Aufrisselement( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Aufrisselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Aufrisselement(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Aufrisselement(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Aufrisselement(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Aufrisselement(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Hoehenpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenpunkt( const Objektart& oa, const Version& version );

// Aufbauschicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufbauschicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufbauschicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufbauschicht( const Objektart& oa, const Version& version );

// Art_Aufbauschicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Aufbauschicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Aufbauschicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Aufbauschicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Aufbauschicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Aufbauschicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Aufbauschicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Aufbauschicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Aufbauschicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Aufbauschicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Aufbauschicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Aufbauschicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Aufbauschicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Aufbauschicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Aufbauschicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Aufbauschicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bindemittel_Aufbauschicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bindemittel_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bindemittel_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bindemittel_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bindemittel_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bindemittel_Aufbauschicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bindemittel_Aufbauschicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bindemittel_Aufbauschicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bindemittel_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bindemittel_Aufbauschicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bindemittel_Aufbauschicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bindemittel_Aufbauschicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bindemittel_Aufbauschicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Detail_A_Aufbauschicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detail_A_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detail_A_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detail_A_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Detail_A_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detail_A_Aufbauschicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detail_A_Aufbauschicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detail_A_Aufbauschicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Detail_A_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Detail_A_Aufbauschicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Detail_A_Aufbauschicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Detail_A_Aufbauschicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Detail_A_Aufbauschicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Detail_B_Aufbauschicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detail_B_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detail_B_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detail_B_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Detail_B_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detail_B_Aufbauschicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detail_B_Aufbauschicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detail_B_Aufbauschicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Detail_B_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Detail_B_Aufbauschicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Detail_B_Aufbauschicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Detail_B_Aufbauschicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Detail_B_Aufbauschicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Detail_C_Aufbauschicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detail_C_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detail_C_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detail_C_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Detail_C_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detail_C_Aufbauschicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detail_C_Aufbauschicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detail_C_Aufbauschicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Detail_C_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Detail_C_Aufbauschicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Detail_C_Aufbauschicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Detail_C_Aufbauschicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Detail_C_Aufbauschicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Detail_D_Aufbauschicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detail_D_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detail_D_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detail_D_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Detail_D_Aufbauschicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detail_D_Aufbauschicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detail_D_Aufbauschicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detail_D_Aufbauschicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Detail_D_Aufbauschicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Detail_D_Aufbauschicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Detail_D_Aufbauschicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Detail_D_Aufbauschicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Detail_D_Aufbauschicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Herkunft_Angaben_Aufbau

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Herkunft_Angaben_Aufbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Herkunft_Angaben_Aufbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Herkunft_Angaben_Aufbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Herkunft_Angaben_Aufbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Herkunft_Angaben_Aufbau( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Herkunft_Angaben_Aufbau( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Herkunft_Angaben_Aufbau( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Herkunft_Angaben_Aufbau(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Herkunft_Angaben_Aufbau(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Herkunft_Angaben_Aufbau(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Herkunft_Angaben_Aufbau(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Herkunft_Angaben_Aufbau(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Streifenart_Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Streifenart_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Streifenart_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Streifenart_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Streifenart_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Streifenart_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Streifenart_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Streifenart_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Streifenart_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Streifenart_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Streifenart_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Streifenart_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Streifenart_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anzahl_Gleise_laengs

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anzahl_Gleise_laengs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anzahl_Gleise_laengs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anzahl_Gleise_laengs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Anzahl_Gleise_laengs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anzahl_Gleise_laengs( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anzahl_Gleise_laengs( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anzahl_Gleise_laengs( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Anzahl_Gleise_laengs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Anzahl_Gleise_laengs(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Anzahl_Gleise_laengs(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Anzahl_Gleise_laengs(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Anzahl_Gleise_laengs(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Oberflaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Oberflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Oberflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Oberflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Oberflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Oberflaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Oberflaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Oberflaeche( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Oberflaeche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Oberflaeche(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Oberflaeche(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Oberflaeche(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Oberflaeche(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bauklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauklasse( const Objektart& oa, const Version& version );

// Art_Bauklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Bauklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Bauklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Bauklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Bauklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Bauklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Bauklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Bauklasse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Bauklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Bauklasse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Bauklasse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Bauklasse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Bauklasse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bauklasse_RStO

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauklasse_RStO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauklasse_RStO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauklasse_RStO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bauklasse_RStO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauklasse_RStO( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauklasse_RStO( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauklasse_RStO( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bauklasse_RStO(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bauklasse_RStO(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bauklasse_RStO(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bauklasse_RStO(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bauklasse_RStO(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bohrkern

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bohrkern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bohrkern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bohrkern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bohrkern( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bohrkern( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bohrkern( const Objektart& oa, const Version& version );

// Zusatzfahrstreifen_RQ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zusatzfahrstreifen_RQ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zusatzfahrstreifen_RQ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zusatzfahrstreifen_RQ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zusatzfahrstreifen_RQ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zusatzfahrstreifen_RQ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zusatzfahrstreifen_RQ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zusatzfahrstreifen_RQ( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zusatzfahrstreifen_RQ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zusatzfahrstreifen_RQ(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zusatzfahrstreifen_RQ(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zusatzfahrstreifen_RQ(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zusatzfahrstreifen_RQ(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lage_Fahrbahn

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Fahrbahn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Fahrbahn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Fahrbahn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Fahrbahn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Fahrbahn( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Fahrbahn( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Fahrbahn( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Fahrbahn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Fahrbahn(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Fahrbahn(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Fahrbahn(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Fahrbahn(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Teilhindernis_Strecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilhindernis_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilhindernis_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilhindernis_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilhindernis_Strecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilhindernis_Strecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilhindernis_Strecke( const Objektart& oa, const Version& version );

// Teilhindernis_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilhindernis_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilhindernis_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilhindernis_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilhindernis_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilhindernis_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilhindernis_Punkt( const Objektart& oa, const Version& version );

// Teilhindernis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilhindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilhindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilhindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilhindernis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilhindernis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilhindernis( const Objektart& oa, const Version& version );

// Eigentuemer_Hindernis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Eigentuemer_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Eigentuemer_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Eigentuemer_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Eigentuemer_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Eigentuemer_Hindernis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Eigentuemer_Hindernis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Eigentuemer_Hindernis( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Eigentuemer_Hindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Eigentuemer_Hindernis(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Eigentuemer_Hindernis(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Eigentuemer_Hindernis(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Eigentuemer_Hindernis(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Raumangabe_Teilhindernis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Raumangabe_Teilhindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Raumangabe_Teilhindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Raumangabe_Teilhindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Raumangabe_Teilhindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Raumangabe_Teilhindernis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Raumangabe_Teilhindernis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Raumangabe_Teilhindernis( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Raumangabe_Teilhindernis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Raumangabe_Teilhindernis(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Raumangabe_Teilhindernis(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Raumangabe_Teilhindernis(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Raumangabe_Teilhindernis(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lage_Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Durchlass( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Durchlass(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Durchlass(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Durchlass(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Durchlass(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Profil_Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Profil_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Profil_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Profil_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Profil_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Profil_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Profil_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Profil_Durchlass( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Profil_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Profil_Durchlass(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Profil_Durchlass(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Profil_Durchlass(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Profil_Durchlass(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Durchlass( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Durchlass(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Durchlass(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Durchlass(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Durchlass(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_Durchlass( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_Durchlass(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_Durchlass(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_Durchlass(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_Durchlass(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zustand_Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustand_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustand_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustand_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zustand_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustand_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustand_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustand_Durchlass( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zustand_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zustand_Durchlass(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zustand_Durchlass(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zustand_Durchlass(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zustand_Durchlass(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schutzeinrichtung_Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzeinrichtung_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzeinrichtung_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzeinrichtung_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schutzeinrichtung_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzeinrichtung_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzeinrichtung_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzeinrichtung_Durchlass( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schutzeinrichtung_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schutzeinrichtung_Durchlass(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schutzeinrichtung_Durchlass(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schutzeinrichtung_Durchlass(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schutzeinrichtung_Durchlass(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Stadium_Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Stadium_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Stadium_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Stadium_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Stadium_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Stadium_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Stadium_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Stadium_Durchlass( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Stadium_Durchlass(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Stadium_Durchlass(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Stadium_Durchlass(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Stadium_Durchlass(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Stadium_Durchlass(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kreisverkehr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreisverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreisverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreisverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreisverkehr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreisverkehr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreisverkehr( const Objektart& oa, const Version& version );

// Art_Kreisverkehr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Kreisverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Kreisverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Kreisverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Kreisverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Kreisverkehr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Kreisverkehr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Kreisverkehr( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Kreisverkehr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Kreisverkehr(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Kreisverkehr(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Kreisverkehr(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Kreisverkehr(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kreisverkehr_ueberfahrbar

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreisverkehr_ueberfahrbar( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreisverkehr_ueberfahrbar( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreisverkehr_ueberfahrbar( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kreisverkehr_ueberfahrbar( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreisverkehr_ueberfahrbar( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreisverkehr_ueberfahrbar( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreisverkehr_ueberfahrbar( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kreisverkehr_ueberfahrbar(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kreisverkehr_ueberfahrbar(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kreisverkehr_ueberfahrbar(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kreisverkehr_ueberfahrbar(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kreisverkehr_ueberfahrbar(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gestaltung_der_Kreisinsel

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gestaltung_der_Kreisinsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gestaltung_der_Kreisinsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gestaltung_der_Kreisinsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gestaltung_der_Kreisinsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gestaltung_der_Kreisinsel( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gestaltung_der_Kreisinsel( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gestaltung_der_Kreisinsel( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gestaltung_der_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gestaltung_der_Kreisinsel(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gestaltung_der_Kreisinsel(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gestaltung_der_Kreisinsel(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gestaltung_der_Kreisinsel(const Version& vsn, const Text& key, Text& value, const int& nVal);

// UI_Partner_Kreisinsel

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_UI_Partner_Kreisinsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_UI_Partner_Kreisinsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_UI_Partner_Kreisinsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_UI_Partner_Kreisinsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_UI_Partner_Kreisinsel( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_UI_Partner_Kreisinsel( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_UI_Partner_Kreisinsel( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_UI_Partner_Kreisinsel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_UI_Partner_Kreisinsel(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_UI_Partner_Kreisinsel(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_UI_Partner_Kreisinsel(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_UI_Partner_Kreisinsel(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrseinschraenkung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrseinschraenkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrseinschraenkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrseinschraenkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrseinschraenkung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrseinschraenkung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrseinschraenkung( const Objektart& oa, const Version& version );

// Art_VES

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_VES( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_VES( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_VES( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_VES(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_VES(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_VES(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_VES(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrsteilnehmergruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsteilnehmergruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsteilnehmergruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsteilnehmergruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verkehrsteilnehmergruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsteilnehmergruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsteilnehmergruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsteilnehmergruppe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verkehrsteilnehmergruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verkehrsteilnehmergruppe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verkehrsteilnehmergruppe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verkehrsteilnehmergruppe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verkehrsteilnehmergruppe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Umfang_VES

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Umfang_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Umfang_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Umfang_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Umfang_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Umfang_VES( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Umfang_VES( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Umfang_VES( const Objektart& oa, const Version& version );

// Gueltigkeit_VES

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gueltigkeit_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gueltigkeit_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gueltigkeit_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gueltigkeit_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gueltigkeit_VES( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gueltigkeit_VES( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gueltigkeit_VES( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gueltigkeit_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gueltigkeit_VES(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gueltigkeit_VES(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gueltigkeit_VES(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gueltigkeit_VES(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wochentag_VES

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wochentag_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wochentag_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wochentag_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wochentag_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wochentag_VES( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wochentag_VES( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wochentag_VES( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Wochentag_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Wochentag_VES(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Wochentag_VES(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Wochentag_VES(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Wochentag_VES(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Querschnitt_Streifenart_VES

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Querschnitt_Streifenart_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Querschnitt_Streifenart_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Querschnitt_Streifenart_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Querschnitt_Streifenart_VES( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Querschnitt_Streifenart_VES( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Querschnitt_Streifenart_VES( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Querschnitt_Streifenart_VES( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Querschnitt_Streifenart_VES(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Querschnitt_Streifenart_VES(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Querschnitt_Streifenart_VES(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Querschnitt_Streifenart_VES(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Querschnitt_Streifenart_VES(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Unterhaltungsvereinbarung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unterhaltungsvereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unterhaltungsvereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unterhaltungsvereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unterhaltungsvereinbarung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unterhaltungsvereinbarung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unterhaltungsvereinbarung( const Objektart& oa, const Version& version );

// Baulasttraeger_Dritter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baulasttraeger_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baulasttraeger_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baulasttraeger_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baulasttraeger_Dritter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baulasttraeger_Dritter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baulasttraeger_Dritter( const Objektart& oa, const Version& version );

// Baudienststelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baudienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baudienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baudienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baudienststelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baudienststelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baudienststelle( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Baudienststelle(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Art_der_Erfassung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Erfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Erfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Erfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Erfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Erfassung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Erfassung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Erfassung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Erfassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Erfassung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Erfassung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Erfassung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Erfassung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Erfassung_Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Erfassung_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Erfassung_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Erfassung_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Erfassung_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Erfassung_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Erfassung_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Erfassung_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Erfassung_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Erfassung_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Erfassung_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Erfassung_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Erfassung_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Quelle_der_Information

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Quelle_der_Information( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Quelle_der_Information( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Quelle_der_Information( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Quelle_der_Information( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Quelle_der_Information( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Quelle_der_Information( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Quelle_der_Information( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Quelle_der_Information(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Quelle_der_Information(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Quelle_der_Information(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Quelle_der_Information(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Quelle_der_Information(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Quelle_der_Information_Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Quelle_der_Information_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Quelle_der_Information_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Quelle_der_Information_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Quelle_der_Information_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Quelle_der_Information_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Quelle_der_Information_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Quelle_der_Information_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Quelle_der_Information_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Quelle_der_Information_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Quelle_der_Information_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Quelle_der_Information_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Quelle_der_Information_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_part_Baulasttraeger

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_part_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_part_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_part_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_part_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_part_Baulasttraeger( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_part_Baulasttraeger( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_part_Baulasttraeger( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_part_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_part_Baulasttraeger(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_part_Baulasttraeger(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_part_Baulasttraeger(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_part_Baulasttraeger(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_part_UI_Partner

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_part_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_part_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_part_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_part_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_part_UI_Partner( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_part_UI_Partner( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_part_UI_Partner( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_part_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_part_UI_Partner(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_part_UI_Partner(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_part_UI_Partner(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_part_UI_Partner(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Verwaltung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Verwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Verwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Verwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Verwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Verwaltung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Verwaltung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Verwaltung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Verwaltung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Verwaltung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Verwaltung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Verwaltung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Verwaltung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Unterhaltungspflicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unterhaltungspflicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unterhaltungspflicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unterhaltungspflicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Unterhaltungspflicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unterhaltungspflicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unterhaltungspflicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unterhaltungspflicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Unterhaltungspflicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Unterhaltungspflicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Unterhaltungspflicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Unterhaltungspflicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Str_Unterhaltungspflicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Str_Unterhaltungspflicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Str_Unterhaltungspflicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Str_Unterhaltungspflicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Str_Unterhaltungspflicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Str_Unterhaltungspflicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Str_Unterhaltungspflicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Str_Unterhaltungspflicht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Str_Unterhaltungspflicht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Str_Unterhaltungspflicht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Str_Unterhaltungspflicht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Str_Unterhaltungspflicht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Str_Unterhaltungspflicht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Sonstige_Unterhaltspflichtige

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sonstige_Unterhaltspflichtige( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sonstige_Unterhaltspflichtige( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sonstige_Unterhaltspflichtige( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Sonstige_Unterhaltspflichtige( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sonstige_Unterhaltspflichtige( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sonstige_Unterhaltspflichtige( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sonstige_Unterhaltspflichtige( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Sonstige_Unterhaltspflichtige(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Sonstige_Unterhaltspflichtige(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Sonstige_Unterhaltspflichtige(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Sonstige_Unterhaltspflichtige(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Sonstige_Unterhaltspflichtige(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Landesschluessel

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Landesschluessel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Landesschluessel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Landesschluessel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Landesschluessel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Landesschluessel( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Landesschluessel( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Landesschluessel( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Landesschluessel(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Landesschluessel(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Landesschluessel(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Landesschluessel(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Landesschluessel(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tab_Baulast_Dritter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Baulast_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Baulast_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Baulast_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Baulast_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Baulast_Dritter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Baulast_Dritter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Baulast_Dritter( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Baulast_Dritter(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Baulast_Dritter(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Baulast_Dritter(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Baulast_Dritter(const Version& vsn, const Text& key, Text& value, const int& nVal);

// EU_Mitglied

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_EU_Mitglied( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_EU_Mitglied( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_EU_Mitglied( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_EU_Mitglied( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_EU_Mitglied( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_EU_Mitglied( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_EU_Mitglied( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_EU_Mitglied(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_EU_Mitglied(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_EU_Mitglied(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_EU_Mitglied(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_EU_Mitglied(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_UI_Partner

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_UI_Partner( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_UI_Partner( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_UI_Partner( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_UI_Partner(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_UI_Partner(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_UI_Partner(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_UI_Partner(const Version& vsn, const Text& key, Text& value, const int& nVal);

// sonstiger_UI_Partner

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_sonstiger_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_sonstiger_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_sonstiger_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_sonstiger_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_sonstiger_UI_Partner( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_sonstiger_UI_Partner( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_sonstiger_UI_Partner( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_sonstiger_UI_Partner(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_sonstiger_UI_Partner(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_sonstiger_UI_Partner(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_sonstiger_UI_Partner(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_sonstiger_UI_Partner(const Version& vsn, const Text& key, Text& value, const int& nVal);

// sonstiger_UI_Partner_Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_sonstiger_UI_Partner_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_sonstiger_UI_Partner_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_sonstiger_UI_Partner_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_sonstiger_UI_Partner_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_sonstiger_UI_Partner_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_sonstiger_UI_Partner_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_sonstiger_UI_Partner_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_sonstiger_UI_Partner_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_sonstiger_UI_Partner_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_sonstiger_UI_Partner_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_sonstiger_UI_Partner_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_sonstiger_UI_Partner_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tab_Baulasttraeger_Dr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Baulasttraeger_Dr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Baulasttraeger_Dr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Baulasttraeger_Dr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Baulasttraeger_Dr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Baulasttraeger_Dr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Baulasttraeger_Dr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Baulasttraeger_Dr( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Baulasttraeger_Dr(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Baulasttraeger_Dr(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Baulasttraeger_Dr(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Baulasttraeger_Dr(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Baulasttraeger_Dr(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tab_Baulasttraeger_Dr_Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Baulasttraeger_Dr_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Baulasttraeger_Dr_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Baulasttraeger_Dr_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Baulasttraeger_Dr_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Baulasttraeger_Dr_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Baulasttraeger_Dr_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Baulasttraeger_Dr_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Baulasttraeger_Dr_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Baulasttraeger_Dr_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Baulasttraeger_Dr_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Baulasttraeger_Dr_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Baulasttraeger_Dr_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zuordnungsobjekt_ASB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zuordnungsobjekt_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zuordnungsobjekt_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zuordnungsobjekt_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zuordnungsobjekt_ASB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zuordnungsobjekt_ASB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zuordnungsobjekt_ASB( const Objektart& oa, const Version& version );

// Kreuzungszuordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreuzungszuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreuzungszuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreuzungszuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kreuzungszuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreuzungszuordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreuzungszuordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreuzungszuordnung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kreuzungszuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kreuzungszuordnung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kreuzungszuordnung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kreuzungszuordnung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kreuzungszuordnung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// VE_Bereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VE_Bereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VE_Bereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VE_Bereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_VE_Bereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VE_Bereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VE_Bereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VE_Bereich( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_VE_Bereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_VE_Bereich(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_VE_Bereich(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_VE_Bereich(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_VE_Bereich(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Baudienststelle_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baudienststelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baudienststelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baudienststelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baudienststelle_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baudienststelle_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baudienststelle_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Baudienststelle_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Baudienststelle_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baudienststelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baudienststelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baudienststelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baudienststelle_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baudienststelle_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baudienststelle_abstrakt( const Objektart& oa, const Version& version );

// Nullpunktort

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nullpunktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nullpunktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nullpunktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nullpunktort( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nullpunktort( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nullpunktort( const Objektart& oa, const Version& version );

// Verkehrsfreigabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsfreigabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsfreigabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsfreigabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsfreigabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsfreigabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsfreigabe( const Objektart& oa, const Version& version );

// Richtung_verallg_Strecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Richtung_verallg_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Richtung_verallg_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Richtung_verallg_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Richtung_verallg_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Richtung_verallg_Strecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Richtung_verallg_Strecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Richtung_verallg_Strecke( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Richtung_verallg_Strecke(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Richtung_verallg_Strecke(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Richtung_verallg_Strecke(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Richtung_verallg_Strecke(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Richtung_verallg_Strecke(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Richtung_verallg_Strecke(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Orientierungsrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Orientierungsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Orientierungsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Orientierungsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Orientierungsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Orientierungsrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Orientierungsrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Orientierungsrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Orientierungsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Orientierungsrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Orientierungsrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Orientierungsrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Orientierungsrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Knotenpunktform

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Knotenpunktform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Knotenpunktform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Knotenpunktform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Knotenpunktform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Knotenpunktform( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Knotenpunktform( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Knotenpunktform( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Knotenpunktform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Knotenpunktform(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Knotenpunktform(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Knotenpunktform(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Knotenpunktform(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Knotenpunktfunktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Knotenpunktfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Knotenpunktfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Knotenpunktfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Knotenpunktfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Knotenpunktfunktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Knotenpunktfunktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Knotenpunktfunktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Knotenpunktfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Knotenpunktfunktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Knotenpunktfunktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Knotenpunktfunktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Knotenpunktfunktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// BAB_Knotenpunkt_Nummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_BAB_Knotenpunkt_Nummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_BAB_Knotenpunkt_Nummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_BAB_Knotenpunkt_Nummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_BAB_Knotenpunkt_Nummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_BAB_Knotenpunkt_Nummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_BAB_Knotenpunkt_Nummer( const Objektart& oa, const Version& version );

// Lage_Verkehrsfreigabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Verkehrsfreigabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Verkehrsfreigabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Verkehrsfreigabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Verkehrsfreigabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Verkehrsfreigabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Verkehrsfreigabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Verkehrsfreigabe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Verkehrsfreigabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Verkehrsfreigabe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Verkehrsfreigabe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Verkehrsfreigabe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Verkehrsfreigabe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Seitenarm

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Seitenarm( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Seitenarm( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Seitenarm( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Seitenarm( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Seitenarm( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Seitenarm( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Seitenarm( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Seitenarm(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Seitenarm(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Seitenarm(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Seitenarm(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Seitenarm(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tab_Funktion_des_Astes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Funktion_des_Astes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Funktion_des_Astes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Funktion_des_Astes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Funktion_des_Astes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Funktion_des_Astes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Funktion_des_Astes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Funktion_des_Astes( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Funktion_des_Astes(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Funktion_des_Astes(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Funktion_des_Astes(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Funktion_des_Astes(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Teilnetzklasse_Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilnetzklasse_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilnetzklasse_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilnetzklasse_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Teilnetzklasse_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilnetzklasse_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilnetzklasse_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilnetzklasse_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Teilnetzklasse_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Teilnetzklasse_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Teilnetzklasse_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Teilnetzklasse_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Teilnetzklasse_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Attribut_des_Teilnetzes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Attribut_des_Teilnetzes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Attribut_des_Teilnetzes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Attribut_des_Teilnetzes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Attribut_des_Teilnetzes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Attribut_des_Teilnetzes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Attribut_des_Teilnetzes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Attribut_des_Teilnetzes( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Attribut_des_Teilnetzes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Attribut_des_Teilnetzes(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Attribut_des_Teilnetzes(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Attribut_des_Teilnetzes(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Attribut_des_Teilnetzes(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Attribut_Teilnetz_Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Attribut_Teilnetz_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Attribut_Teilnetz_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Attribut_Teilnetz_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Attribut_Teilnetz_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Attribut_Teilnetz_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Attribut_Teilnetz_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Attribut_Teilnetz_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Attribut_Teilnetz_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Attribut_Teilnetz_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Attribut_Teilnetz_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Attribut_Teilnetz_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Attribut_Teilnetz_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Km_Richtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Km_Richtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Km_Richtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Km_Richtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Km_Richtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Km_Richtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Km_Richtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Km_Richtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Km_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Km_Richtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Km_Richtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Km_Richtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Km_Richtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenteilstueck

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenteilstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenteilstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenteilstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenteilstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenteilstueck( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenteilstueck( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenteilstueck( const Objektart& oa, const Version& version );

// Verbotene_Fahrbeziehung_NP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verbotene_Fahrbeziehung_NP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verbotene_Fahrbeziehung_NP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verbotene_Fahrbeziehung_NP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verbotene_Fahrbeziehung_NP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verbotene_Fahrbeziehung_NP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verbotene_Fahrbeziehung_NP( const Objektart& oa, const Version& version );
#endif
};
} // Namespace Oklabi

