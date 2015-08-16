/*****************************************************************************
* $Id: SI-Gesamt2.h 28.09.2012 14:04:46 vogelsang $
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
* 13.01.2011  Code für Schema-Sammelmodul 2 erstellt
*
* Version OKSTRA-Express: 2011-01-13, OKSTRA 1.000-1.015
* Version OKSTRA-Klassenbibliothek: 1.1.0
*
*/
namespace Oklabi
{
class Schema2 : public Schema
{
friend class Schema;
OKLABI_SCHEMA_API static bool LocalInit();
OKLABI_SCHEMA_API static bool initialized;
OKLABI_SCHEMA_API static const char* GibExpressVersion();
OKLABI_SCHEMA_API static const char* GibOKLABIReleaseVersion();
#ifdef OKLABI_PLAUSI

// Kreuzung_Strasse_Weg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreuzung_Strasse_Weg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreuzung_Strasse_Weg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreuzung_Strasse_Weg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreuzung_Strasse_Weg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreuzung_Strasse_Weg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreuzung_Strasse_Weg( const Objektart& oa, const Version& version );

// Bahnkreuzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bahnkreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bahnkreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bahnkreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bahnkreuzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bahnkreuzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bahnkreuzung( const Objektart& oa, const Version& version );

// Gewaesserkreuzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gewaesserkreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gewaesserkreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gewaesserkreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gewaesserkreuzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gewaesserkreuzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gewaesserkreuzung( const Objektart& oa, const Version& version );

// Tierwechsel

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tierwechsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tierwechsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tierwechsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tierwechsel( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tierwechsel( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tierwechsel( const Objektart& oa, const Version& version );

// Kreuzung_sonst_Verkehrsanl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreuzung_sonst_Verkehrsanl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreuzung_sonst_Verkehrsanl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreuzung_sonst_Verkehrsanl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreuzung_sonst_Verkehrsanl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreuzung_sonst_Verkehrsanl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreuzung_sonst_Verkehrsanl( const Objektart& oa, const Version& version );

// Kreuzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreuzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreuzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreuzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreuzung( const Objektart& oa, const Version& version );

// Kreuzungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreuzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreuzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreuzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kreuzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreuzungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreuzungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreuzungsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kreuzungsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Kreuzungsart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kreuzungsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kreuzungsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kreuzungsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kreuzungslage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreuzungslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreuzungslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreuzungslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kreuzungslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreuzungslage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreuzungslage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreuzungslage( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kreuzungslage(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kreuzungslage(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kreuzungslage(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kreuzungslage(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Beruehrungsebene

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beruehrungsebene( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beruehrungsebene( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beruehrungsebene( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Beruehrungsebene( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beruehrungsebene( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beruehrungsebene( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beruehrungsebene( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Beruehrungsebene(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Beruehrungsebene(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Beruehrungsebene(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Beruehrungsebene(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Beruehrungsebene(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Beruehrungsebene(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Hoehenlage_aufzun_Strasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenlage_aufzun_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenlage_aufzun_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenlage_aufzun_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hoehenlage_aufzun_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenlage_aufzun_Strasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenlage_aufzun_Strasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenlage_aufzun_Strasse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Hoehenlage_aufzun_Strasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Hoehenlage_aufzun_Strasse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Hoehenlage_aufzun_Strasse(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Hoehenlage_aufzun_Strasse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Hoehenlage_aufzun_Strasse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Hoehenlage_aufzun_Strasse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anschluss_Bauform

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anschluss_Bauform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anschluss_Bauform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anschluss_Bauform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Anschluss_Bauform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anschluss_Bauform( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anschluss_Bauform( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anschluss_Bauform( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Anschluss_Bauform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Anschluss_Bauform(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Anschluss_Bauform(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Anschluss_Bauform(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Anschluss_Bauform(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Anschluss_Bauform(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vorrangregelung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vorrangregelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vorrangregelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vorrangregelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vorrangregelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vorrangregelung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vorrangregelung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vorrangregelung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vorrangregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vorrangregelung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Vorrangregelung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vorrangregelung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vorrangregelung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vorrangregelung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bahnkreuzungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bahnkreuzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bahnkreuzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bahnkreuzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bahnkreuzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bahnkreuzungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bahnkreuzungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bahnkreuzungsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bahnkreuzungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bahnkreuzungsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Bahnkreuzungsart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bahnkreuzungsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bahnkreuzungsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bahnkreuzungsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bahnkreuzungsstadium

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bahnkreuzungsstadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bahnkreuzungsstadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bahnkreuzungsstadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bahnkreuzungsstadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bahnkreuzungsstadium( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bahnkreuzungsstadium( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bahnkreuzungsstadium( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bahnkreuzungsstadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bahnkreuzungsstadium(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Bahnkreuzungsstadium(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bahnkreuzungsstadium(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bahnkreuzungsstadium(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bahnkreuzungsstadium(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bahnkreuzungslage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bahnkreuzungslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bahnkreuzungslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bahnkreuzungslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bahnkreuzungslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bahnkreuzungslage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bahnkreuzungslage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bahnkreuzungslage( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bahnkreuzungslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bahnkreuzungslage(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bahnkreuzungslage(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bahnkreuzungslage(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bahnkreuzungslage(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bahnkoerper

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bahnkoerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bahnkoerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bahnkoerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bahnkoerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bahnkoerper( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bahnkoerper( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bahnkoerper( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bahnkoerper(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bahnkoerper(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Bahnkoerper(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bahnkoerper(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bahnkoerper(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bahnkoerper(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bahnkreuzung_Sicherungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bahnkreuzung_Sicherungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bahnkreuzung_Sicherungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bahnkreuzung_Sicherungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bahnkreuzung_Sicherungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bahnkreuzung_Sicherungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bahnkreuzung_Sicherungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bahnkreuzung_Sicherungsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bahnkreuzung_Sicherungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bahnkreuzung_Sicherungsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Bahnkreuzung_Sicherungsart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bahnkreuzung_Sicherungsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bahnkreuzung_Sicherungsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bahnkreuzung_Sicherungsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gewaesserart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gewaesserart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gewaesserart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gewaesserart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gewaesserart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gewaesserart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gewaesserart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gewaesserart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gewaesserart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gewaesserart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Gewaesserart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gewaesserart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gewaesserart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gewaesserart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tierart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tierart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tierart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tierart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tierart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tierart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tierart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tierart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tierart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tierart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tierart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tierart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tierart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tierart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrsanlagenart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsanlagenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsanlagenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsanlagenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verkehrsanlagenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsanlagenart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsanlagenart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsanlagenart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verkehrsanlagenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verkehrsanlagenart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Verkehrsanlagenart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verkehrsanlagenart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verkehrsanlagenart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verkehrsanlagenart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Erfassung_Geschwindigkeiten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassung_Geschwindigkeiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassung_Geschwindigkeiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassung_Geschwindigkeiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassung_Geschwindigkeiten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassung_Geschwindigkeiten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassung_Geschwindigkeiten( const Objektart& oa, const Version& version );

// V_Verteilungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_V_Verteilungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_V_Verteilungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_V_Verteilungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_V_Verteilungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_V_Verteilungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_V_Verteilungen( const Objektart& oa, const Version& version );

// Anzahl_V_Klassen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anzahl_V_Klassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anzahl_V_Klassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anzahl_V_Klassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anzahl_V_Klassen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anzahl_V_Klassen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anzahl_V_Klassen( const Objektart& oa, const Version& version );

// V_Klassen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_V_Klassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_V_Klassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_V_Klassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_V_Klassen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_V_Klassen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_V_Klassen( const Objektart& oa, const Version& version );

// abgel_Werte_u_Verteilgen_VK

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_abgel_Werte_u_Verteilgen_VK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_abgel_Werte_u_Verteilgen_VK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_abgel_Werte_u_Verteilgen_VK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_abgel_Werte_u_Verteilgen_VK( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_abgel_Werte_u_Verteilgen_VK( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_abgel_Werte_u_Verteilgen_VK( const Objektart& oa, const Version& version );

// aggregierte_Werte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_aggregierte_Werte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_aggregierte_Werte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_aggregierte_Werte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_aggregierte_Werte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_aggregierte_Werte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_aggregierte_Werte( const Objektart& oa, const Version& version );

// mittlere_Geschwindigkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_mittlere_Geschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_mittlere_Geschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_mittlere_Geschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_mittlere_Geschwindigkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_mittlere_Geschwindigkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_mittlere_Geschwindigkeit( const Objektart& oa, const Version& version );

// abgeleitete_Werte_VM

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_abgeleitete_Werte_VM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_abgeleitete_Werte_VM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_abgeleitete_Werte_VM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_abgeleitete_Werte_VM( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_abgeleitete_Werte_VM( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_abgeleitete_Werte_VM( const Objektart& oa, const Version& version );

// Achslastdatenerfassung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achslastdatenerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achslastdatenerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achslastdatenerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achslastdatenerfassung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achslastdatenerfassung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achslastdatenerfassung( const Objektart& oa, const Version& version );

// abgel_Werte_und_Verteilungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_abgel_Werte_und_Verteilungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_abgel_Werte_und_Verteilungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_abgel_Werte_und_Verteilungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_abgel_Werte_und_Verteilungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_abgel_Werte_und_Verteilungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_abgel_Werte_und_Verteilungen( const Objektart& oa, const Version& version );

// GG_Verteilung_einer_FZ_Klasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GG_Verteilung_einer_FZ_Klasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GG_Verteilung_einer_FZ_Klasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GG_Verteilung_einer_FZ_Klasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GG_Verteilung_einer_FZ_Klasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GG_Verteilung_einer_FZ_Klasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GG_Verteilung_einer_FZ_Klasse( const Objektart& oa, const Version& version );

// GG_Klasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GG_Klasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GG_Klasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GG_Klasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GG_Klasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GG_Klasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GG_Klasse( const Objektart& oa, const Version& version );

// Achstyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Achstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achstyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achstyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achstyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Achstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Achstyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Achstyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Achstyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Achstyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Achstyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Achslastverteilung_e_Achstyps

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achslastverteilung_e_Achstyps( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achslastverteilung_e_Achstyps( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achslastverteilung_e_Achstyps( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achslastverteilung_e_Achstyps( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achslastverteilung_e_Achstyps( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achslastverteilung_e_Achstyps( const Objektart& oa, const Version& version );

// Klasse_AL

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Klasse_AL( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Klasse_AL( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Klasse_AL( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Klasse_AL( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Klasse_AL( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Klasse_AL( const Objektart& oa, const Version& version );

// Einzelfahrzeugdatenerfassung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einzelfahrzeugdatenerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einzelfahrzeugdatenerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einzelfahrzeugdatenerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einzelfahrzeugdatenerfassung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einzelfahrzeugdatenerfassung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einzelfahrzeugdatenerfassung( const Objektart& oa, const Version& version );

// zugehoerige_Fahrzeugklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zugehoerige_Fahrzeugklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zugehoerige_Fahrzeugklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zugehoerige_Fahrzeugklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zugehoerige_Fahrzeugklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zugehoerige_Fahrzeugklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zugehoerige_Fahrzeugklasse( const Objektart& oa, const Version& version );

// zugehoeriger_Zeitpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zugehoeriger_Zeitpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zugehoeriger_Zeitpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zugehoeriger_Zeitpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zugehoeriger_Zeitpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zugehoeriger_Zeitpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zugehoeriger_Zeitpunkt( const Objektart& oa, const Version& version );

// fahrzeugbezogene_Achslastdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_fahrzeugbezogene_Achslastdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_fahrzeugbezogene_Achslastdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_fahrzeugbezogene_Achslastdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_fahrzeugbezogene_Achslastdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_fahrzeugbezogene_Achslastdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_fahrzeugbezogene_Achslastdaten( const Objektart& oa, const Version& version );

// Ueberladung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ueberladung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ueberladung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ueberladung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ueberladung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ueberladung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ueberladung( const Objektart& oa, const Version& version );

// achsbezogene_Daten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_achsbezogene_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_achsbezogene_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_achsbezogene_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_achsbezogene_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_achsbezogene_Daten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_achsbezogene_Daten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_achsbezogene_Daten( const Objektart& oa, const Version& version );

// stat_wegweisende_Beschilderung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_stat_wegweisende_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_stat_wegweisende_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_stat_wegweisende_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_stat_wegweisende_Beschilderung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_stat_wegweisende_Beschilderung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_stat_wegweisende_Beschilderung( const Objektart& oa, const Version& version );

// Wegweiserbild

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweiserbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweiserbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweiserbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweiserbild( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweiserbild( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweiserbild( const Objektart& oa, const Version& version );

// Einzugsbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einzugsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einzugsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einzugsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einzugsbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einzugsbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einzugsbereich( const Objektart& oa, const Version& version );

// Typ_des_Einzugsbereiches

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_des_Einzugsbereiches( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_des_Einzugsbereiches( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_des_Einzugsbereiches( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_des_Einzugsbereiches( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_des_Einzugsbereiches( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_des_Einzugsbereiches( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_des_Einzugsbereiches( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_des_Einzugsbereiches(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Typ_des_Einzugsbereiches(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_des_Einzugsbereiches(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_des_Einzugsbereiches(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_des_Einzugsbereiches(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_des_Einzugsbereiches

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_des_Einzugsbereiches( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_des_Einzugsbereiches( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_des_Einzugsbereiches( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_des_Einzugsbereiches( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_des_Einzugsbereiches( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_des_Einzugsbereiches( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_des_Einzugsbereiches( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_des_Einzugsbereiches(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_des_Einzugsbereiches(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_des_Einzugsbereiches(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_des_Einzugsbereiches(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_des_Einzugsbereiches(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_des_Einzugsbereiches(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Standort_Wegweiser

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Standort_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Standort_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Standort_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Standort_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Standort_Wegweiser( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Standort_Wegweiser( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Standort_Wegweiser( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Standort_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Standort_Wegweiser(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Standort_Wegweiser(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Standort_Wegweiser(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Standort_Wegweiser(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Numerierung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Numerierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Numerierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Numerierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Numerierung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Numerierung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Numerierung( const Objektart& oa, const Version& version );

// Position

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Position( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Position( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Position( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Position( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Position( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Position( const Objektart& oa, const Version& version );

// Netzzuordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzzuordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzzuordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzzuordnung( const Objektart& oa, const Version& version );

// Aufstellung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufstellung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufstellung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufstellung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Aufstellung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Aufstellung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Aufstellung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Aufstellung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Aufstellung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// richtungsbezogene_Ausfuehrung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_richtungsbezogene_Ausfuehrung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_richtungsbezogene_Ausfuehrung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_richtungsbezogene_Ausfuehrung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_richtungsbezogene_Ausfuehrung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_richtungsbezogene_Ausfuehrung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_richtungsbezogene_Ausfuehrung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_richtungsbezogene_Ausfuehrung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_richtungsbezogene_Ausfuehrung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_richtungsbezogene_Ausfuehrung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_richtungsbezogene_Ausfuehrung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_richtungsbezogene_Ausfuehrung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_richtungsbezogene_Ausfuehrung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_richtungsbezogene_Ausfuehrung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_wegweisend

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_wegweisend( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_wegweisend( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_wegweisend( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_wegweisend( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_wegweisend( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_wegweisend( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_wegweisend( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_wegweisend(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_wegweisend(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Funktion_wegweisend(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_wegweisend(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_wegweisend(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_wegweisend(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wegweiserfarbe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweiserfarbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweiserfarbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweiserfarbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wegweiserfarbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweiserfarbe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweiserfarbe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweiserfarbe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Wegweiserfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Wegweiserfarbe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Wegweiserfarbe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Wegweiserfarbe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Wegweiserfarbe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Wegweiserfarbe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wegweisertafel_mit_Epunkten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweisertafel_mit_Epunkten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweisertafel_mit_Epunkten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweisertafel_mit_Epunkten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweisertafel_mit_Epunkten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweisertafel_mit_Epunkten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweisertafel_mit_Epunkten( const Objektart& oa, const Version& version );

// Richtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Richtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Richtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Richtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Richtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Richtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Richtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Richtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Richtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Richtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Richtung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Richtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Richtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Richtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Beschriftungselemente_Symbole

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beschriftungselemente_Symbole( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beschriftungselemente_Symbole( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beschriftungselemente_Symbole( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beschriftungselemente_Symbole( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beschriftungselemente_Symbole( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beschriftungselemente_Symbole( const Objektart& oa, const Version& version );

// Elementtyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Elementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Elementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Elementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Elementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Elementtyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Elementtyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Elementtyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Elementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Elementtyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Elementtyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Elementtyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Elementtyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Elementtyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Farbe_Beschriftungselem_Symb

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Farbe_Beschriftungselem_Symb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Farbe_Beschriftungselem_Symb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Farbe_Beschriftungselem_Symb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Farbe_Beschriftungselem_Symb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Farbe_Beschriftungselem_Symb( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Farbe_Beschriftungselem_Symb( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Farbe_Beschriftungselem_Symb( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Farbe_Beschriftungselem_Symb(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Farbe_Beschriftungselem_Symb(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Farbe_Beschriftungselem_Symb(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Farbe_Beschriftungselem_Symb(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Farbe_Beschriftungselem_Symb(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Farbe_Beschriftungselem_Symb(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anordnung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Anordnung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Anordnung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Anordnung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Anordnung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Anordnung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// stat_verkehrsreg_Beschilderung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_stat_verkehrsreg_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_stat_verkehrsreg_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_stat_verkehrsreg_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_stat_verkehrsreg_Beschilderung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_stat_verkehrsreg_Beschilderung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_stat_verkehrsreg_Beschilderung( const Objektart& oa, const Version& version );

// Standort_Beschilderung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Standort_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Standort_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Standort_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Standort_Beschilderung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Standort_Beschilderung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Standort_Beschilderung( const Objektart& oa, const Version& version );

// Aufstellart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufstellart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufstellart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufstellart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Aufstellart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufstellart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufstellart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufstellart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Aufstellart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Aufstellart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Aufstellart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Aufstellart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Aufstellart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Aufstellart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// verkehrsregelnde_Funktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verkehrsregelnde_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verkehrsregelnde_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verkehrsregelnde_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verkehrsregelnde_Funktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verkehrsregelnde_Funktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verkehrsregelnde_Funktion( const Objektart& oa, const Version& version );

// Funktion_verkehrsregelnd

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_verkehrsregelnd( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_verkehrsregelnd( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_verkehrsregelnd( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_verkehrsregelnd( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_verkehrsregelnd( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_verkehrsregelnd( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_verkehrsregelnd( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_verkehrsregelnd(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_verkehrsregelnd(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Funktion_verkehrsregelnd(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_verkehrsregelnd(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_verkehrsregelnd(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_verkehrsregelnd(const Version& vsn, const Text& key, Text& value, const int& nVal);

// StVO_Zuordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_StVO_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_StVO_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_StVO_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_StVO_Zuordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_StVO_Zuordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_StVO_Zuordnung( const Objektart& oa, const Version& version );

// Gueltigkeitsbereich_VRB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gueltigkeitsbereich_VRB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gueltigkeitsbereich_VRB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gueltigkeitsbereich_VRB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gueltigkeitsbereich_VRB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gueltigkeitsbereich_VRB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gueltigkeitsbereich_VRB( const Objektart& oa, const Version& version );

// raeumlicher_Gueltigkeitsber

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_raeumlicher_Gueltigkeitsber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_raeumlicher_Gueltigkeitsber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_raeumlicher_Gueltigkeitsber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_raeumlicher_Gueltigkeitsber( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_raeumlicher_Gueltigkeitsber( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_raeumlicher_Gueltigkeitsber( const Objektart& oa, const Version& version );

// zeitlicher_Gueltigkeitsber

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zeitlicher_Gueltigkeitsber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zeitlicher_Gueltigkeitsber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zeitlicher_Gueltigkeitsber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zeitlicher_Gueltigkeitsber( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zeitlicher_Gueltigkeitsber( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zeitlicher_Gueltigkeitsber( const Objektart& oa, const Version& version );

// Wegweiser

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweiser( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweiser( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweiser( const Objektart& oa, const Version& version );

// komplexer_Wegweiser

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_komplexer_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_komplexer_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_komplexer_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_komplexer_Wegweiser( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_komplexer_Wegweiser( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_komplexer_Wegweiser( const Objektart& oa, const Version& version );

// Bildart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bildart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bildart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bildart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bildart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bildart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bildart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bildart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bildart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bildart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Bildart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bildart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bildart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bildart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wegweisertyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweisertyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweisertyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweisertyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wegweisertyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweisertyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweisertyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweisertyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Wegweisertyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Wegweisertyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Wegweisertyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Wegweisertyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Wegweisertyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Wegweisertyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// lichttechnische_Bauart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_lichttechnische_Bauart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_lichttechnische_Bauart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_lichttechnische_Bauart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_lichttechnische_Bauart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_lichttechnische_Bauart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_lichttechnische_Bauart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_lichttechnische_Bauart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_lichttechnische_Bauart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_lichttechnische_Bauart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_lichttechnische_Bauart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_lichttechnische_Bauart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_lichttechnische_Bauart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_lichttechnische_Bauart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Sichtrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sichtrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sichtrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sichtrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Sichtrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sichtrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sichtrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sichtrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Sichtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Sichtrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Sichtrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Sichtrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Sichtrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// StVO_Zeichennummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_StVO_Zeichennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_StVO_Zeichennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_StVO_Zeichennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_StVO_Zeichennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_StVO_Zeichennummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_StVO_Zeichennummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_StVO_Zeichennummer( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_StVO_Zeichennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_StVO_Zeichennummer(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_StVO_Zeichennummer(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_StVO_Zeichennummer(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_StVO_Zeichennummer(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grundfarbe_Wegweiser

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundfarbe_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundfarbe_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundfarbe_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Grundfarbe_Wegweiser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundfarbe_Wegweiser( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundfarbe_Wegweiser( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundfarbe_Wegweiser( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Grundfarbe_Wegweiser(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Grundfarbe_Wegweiser(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Grundfarbe_Wegweiser(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Grundfarbe_Wegweiser(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Grundfarbe_Wegweiser(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Grundfarbe_Wegweiser(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrszeichentraeger

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrszeichentraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrszeichentraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrszeichentraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrszeichentraeger( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrszeichentraeger( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrszeichentraeger( const Objektart& oa, const Version& version );

// Aufstellvorrichtung_VZT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufstellvorrichtung_VZT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufstellvorrichtung_VZT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufstellvorrichtung_VZT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufstellvorrichtung_VZT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufstellvorrichtung_VZT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufstellvorrichtung_VZT( const Objektart& oa, const Version& version );

// Art_der_Aufstellvorrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Aufstellvorrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Aufstellvorrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Aufstellvorrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Aufstellvorrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Aufstellvorrichtung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Aufstellvorrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Aufstellvorrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Aufstellvorrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Aufstellvorrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Aufstellvorrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Aufstellvorrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Aufstellvorrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Aufstellvorrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Aufstellvorrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Material_Aufstellvorrichtung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Aufstellvorrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Aufstellvorrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Aufstellvorrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Standort

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Standort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Standort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Standort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Standort( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Standort( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Standort( const Objektart& oa, const Version& version );

// Wegweiserinhalt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wegweiserinhalt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wegweiserinhalt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wegweiserinhalt( const Objektart& oa, const Version& version );

// komplexer_Wegweiserinhalt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_komplexer_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_komplexer_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_komplexer_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_komplexer_Wegweiserinhalt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_komplexer_Wegweiserinhalt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_komplexer_Wegweiserinhalt( const Objektart& oa, const Version& version );

// Inhaltstyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Inhaltstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Inhaltstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Inhaltstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Inhaltstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Inhaltstyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Inhaltstyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Inhaltstyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Inhaltstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Inhaltstyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Inhaltstyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Inhaltstyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Inhaltstyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Inhaltstyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schriftart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schriftart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schriftart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schriftart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schriftart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schriftart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schriftart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schriftart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schriftart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schriftart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Schriftart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schriftart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schriftart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schriftart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schriftfarbe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schriftfarbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schriftfarbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schriftfarbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schriftfarbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schriftfarbe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schriftfarbe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schriftfarbe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schriftfarbe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schriftfarbe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Schriftfarbe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schriftfarbe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schriftfarbe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schriftfarbe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schriftgroesse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schriftgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schriftgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schriftgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schriftgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schriftgroesse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schriftgroesse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schriftgroesse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schriftgroesse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schriftgroesse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Schriftgroesse(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schriftgroesse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schriftgroesse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schriftgroesse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grundfarbe_Wegweiserinhalt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundfarbe_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundfarbe_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundfarbe_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Grundfarbe_Wegweiserinhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundfarbe_Wegweiserinhalt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundfarbe_Wegweiserinhalt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundfarbe_Wegweiserinhalt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Grundfarbe_Wegweiserinhalt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Grundfarbe_Wegweiserinhalt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Grundfarbe_Wegweiserinhalt(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Grundfarbe_Wegweiserinhalt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Grundfarbe_Wegweiserinhalt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Grundfarbe_Wegweiserinhalt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// graphisches_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_graphisches_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_graphisches_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_graphisches_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_graphisches_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_graphisches_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_graphisches_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_graphisches_Symbol( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_graphisches_Symbol(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_graphisches_Symbol(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_graphisches_Symbol(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_graphisches_Symbol(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_graphisches_Symbol(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_graphisches_Symbol(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Pfeilart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pfeilart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pfeilart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pfeilart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Pfeilart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pfeilart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pfeilart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pfeilart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Pfeilart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Pfeilart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Pfeilart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Pfeilart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Pfeilart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Pfeilart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Pfeilgrundform

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pfeilgrundform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pfeilgrundform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pfeilgrundform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Pfeilgrundform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pfeilgrundform( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pfeilgrundform( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pfeilgrundform( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Pfeilgrundform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Pfeilgrundform(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Pfeilgrundform(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Pfeilgrundform(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Pfeilgrundform(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Pfeilgrundform(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Pfeilspitze

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pfeilspitze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pfeilspitze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pfeilspitze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Pfeilspitze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pfeilspitze( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pfeilspitze( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pfeilspitze( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Pfeilspitze(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Pfeilspitze(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Pfeilspitze(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Pfeilspitze(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Pfeilspitze(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Pfeilspitze(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Pfeilschaft

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pfeilschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pfeilschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pfeilschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Pfeilschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pfeilschaft( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pfeilschaft( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pfeilschaft( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Pfeilschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Pfeilschaft(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Pfeilschaft(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Pfeilschaft(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Pfeilschaft(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Pfeilschaft(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Referenzzielangabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Referenzzielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Referenzzielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Referenzzielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Referenzzielangabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Referenzzielangabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Referenzzielangabe( const Objektart& oa, const Version& version );

// Synonym

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Synonym( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Synonym( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Synonym( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Synonym( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Synonym( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Synonym( const Objektart& oa, const Version& version );

// Synonym_Zielangabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Synonym_Zielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Synonym_Zielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Synonym_Zielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Synonym_Zielangabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Synonym_Zielangabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Synonym_Zielangabe( const Objektart& oa, const Version& version );

// Zielangabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zielangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zielangabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zielangabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zielangabe( const Objektart& oa, const Version& version );

// Zielkategorie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zielkategorie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zielkategorie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zielkategorie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zielkategorie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zielkategorie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zielkategorie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zielkategorie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zielkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zielkategorie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zielkategorie(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zielkategorie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zielkategorie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zielkategorie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kostra_Projekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kostra_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kostra_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kostra_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kostra_Projekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kostra_Projekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kostra_Projekt( const Objektart& oa, const Version& version );

// Projektkennzeichnung_Kostra

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Projektkennzeichnung_Kostra( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Projektkennzeichnung_Kostra( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Projektkennzeichnung_Kostra( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Projektkennzeichnung_Kostra( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Projektkennzeichnung_Kostra( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Projektkennzeichnung_Kostra( const Objektart& oa, const Version& version );

// Entwurfsart_AKS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwurfsart_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwurfsart_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwurfsart_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Entwurfsart_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwurfsart_AKS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwurfsart_AKS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwurfsart_AKS( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Entwurfsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Entwurfsart_AKS(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Entwurfsart_AKS(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Entwurfsart_AKS(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Entwurfsart_AKS(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Entwurfsart_AKS(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Stand_der_Fortschreibung_AKS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Stand_der_Fortschreibung_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Stand_der_Fortschreibung_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Stand_der_Fortschreibung_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Stand_der_Fortschreibung_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Stand_der_Fortschreibung_AKS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Stand_der_Fortschreibung_AKS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Stand_der_Fortschreibung_AKS( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Stand_der_Fortschreibung_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Stand_der_Fortschreibung_AKS(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Stand_der_Fortschreibung_AKS(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Stand_der_Fortschreibung_AKS(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Stand_der_Fortschreibung_AKS(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Stand_der_Fortschreibung_AKS(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Berechnungsart_AKS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Berechnungsart_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Berechnungsart_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Berechnungsart_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Berechnungsart_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Berechnungsart_AKS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Berechnungsart_AKS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Berechnungsart_AKS( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Berechnungsart_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Berechnungsart_AKS(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Berechnungsart_AKS(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Berechnungsart_AKS(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Berechnungsart_AKS(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Genauigkeit_AKS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Genauigkeit_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Genauigkeit_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Genauigkeit_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Genauigkeit_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Genauigkeit_AKS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Genauigkeit_AKS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Genauigkeit_AKS( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Genauigkeit_AKS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Genauigkeit_AKS(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Genauigkeit_AKS(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Genauigkeit_AKS(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Genauigkeit_AKS(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zusatzdaten_Kostra

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zusatzdaten_Kostra( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zusatzdaten_Kostra( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zusatzdaten_Kostra( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zusatzdaten_Kostra( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zusatzdaten_Kostra( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zusatzdaten_Kostra( const Objektart& oa, const Version& version );

// Kostendaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kostendaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kostendaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kostendaten( const Objektart& oa, const Version& version );

// Lose

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lose( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lose( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lose( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lose( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lose( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lose( const Objektart& oa, const Version& version );

// Kostenbeteiligte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kostenbeteiligte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kostenbeteiligte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kostenbeteiligte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kostenbeteiligte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kostenbeteiligte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kostenbeteiligte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kostenbeteiligte( const Objektart& oa, const Version& version );

// Typ_des_Kostenbeteiligten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_des_Kostenbeteiligten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_des_Kostenbeteiligten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_des_Kostenbeteiligten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_des_Kostenbeteiligten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_des_Kostenbeteiligten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_des_Kostenbeteiligten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_des_Kostenbeteiligten( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_des_Kostenbeteiligten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_des_Kostenbeteiligten(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Typ_des_Kostenbeteiligten(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_des_Kostenbeteiligten(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_des_Kostenbeteiligten(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_des_Kostenbeteiligten(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kostenbeteiligung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kostenbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kostenbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kostenbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kostenbeteiligung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kostenbeteiligung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kostenbeteiligung( const Objektart& oa, const Version& version );

// Art_der_Kostenbeteiligung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Kostenbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Kostenbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Kostenbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Kostenbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Kostenbeteiligung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Kostenbeteiligung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Kostenbeteiligung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Kostenbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Kostenbeteiligung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Kostenbeteiligung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Kostenbeteiligung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Kostenbeteiligung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Kostenbeteiligung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Teil_Kostendaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teil_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teil_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teil_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teil_Kostendaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teil_Kostendaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teil_Kostendaten( const Objektart& oa, const Version& version );

// Leistungsbeschreibung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leistungsbeschreibung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leistungsbeschreibung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leistungsbeschreibung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leistungsbeschreibung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leistungsbeschreibung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leistungsbeschreibung( const Objektart& oa, const Version& version );

// Regionaltext_Freitext

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Regionaltext_Freitext( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Regionaltext_Freitext( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Regionaltext_Freitext( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Regionaltext_Freitext( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Regionaltext_Freitext( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Regionaltext_Freitext( const Objektart& oa, const Version& version );

// Regionaltext_Freitext_Katalog

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Regionaltext_Freitext_Katalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Regionaltext_Freitext_Katalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Regionaltext_Freitext_Katalog( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Regionaltext_Freitext_Katalog( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Regionaltext_Freitext_Katalog( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Regionaltext_Freitext_Katalog( const Objektart& oa, const Version& version );

// Formblatt_C

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formblatt_C( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formblatt_C( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formblatt_C( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formblatt_C( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formblatt_C( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formblatt_C( const Objektart& oa, const Version& version );

// Formblaetter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formblaetter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formblaetter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formblaetter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formblaetter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formblaetter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formblaetter( const Objektart& oa, const Version& version );

// Formblatt_A1

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formblatt_A1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formblatt_A1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formblatt_A1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formblatt_A1( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formblatt_A1( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formblatt_A1( const Objektart& oa, const Version& version );

// Formblatt_A2

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formblatt_A2( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formblatt_A2( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formblatt_A2( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formblatt_A2( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formblatt_A2( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formblatt_A2( const Objektart& oa, const Version& version );

// Gesamtkostenverteilung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gesamtkostenverteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gesamtkostenverteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gesamtkostenverteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gesamtkostenverteilung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gesamtkostenverteilung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gesamtkostenverteilung( const Objektart& oa, const Version& version );

// Formblatt_A3

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formblatt_A3( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formblatt_A3( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formblatt_A3( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formblatt_A3( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formblatt_A3( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formblatt_A3( const Objektart& oa, const Version& version );

// Formblatt_B

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formblatt_B( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formblatt_B( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formblatt_B( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formblatt_B( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formblatt_B( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formblatt_B( const Objektart& oa, const Version& version );

// zusammenges_Hauptteilkosten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zusammenges_Hauptteilkosten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zusammenges_Hauptteilkosten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zusammenges_Hauptteilkosten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zusammenges_Hauptteilkosten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zusammenges_Hauptteilkosten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zusammenges_Hauptteilkosten( const Objektart& oa, const Version& version );

// Formblatt_S1

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Formblatt_S1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Formblatt_S1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Formblatt_S1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Formblatt_S1( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Formblatt_S1( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Formblatt_S1( const Objektart& oa, const Version& version );

// HOAI_Daten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HOAI_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HOAI_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HOAI_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HOAI_Daten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HOAI_Daten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HOAI_Daten( const Objektart& oa, const Version& version );

// HOAI_Projektdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HOAI_Projektdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HOAI_Projektdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HOAI_Projektdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HOAI_Projektdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HOAI_Projektdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HOAI_Projektdaten( const Objektart& oa, const Version& version );

// Minderung_nach_52_5_HOAI

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Minderung_nach_52_5_HOAI( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Minderung_nach_52_5_HOAI( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Minderung_nach_52_5_HOAI( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Minderung_nach_52_5_HOAI( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Minderung_nach_52_5_HOAI( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Minderung_nach_52_5_HOAI( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Minderung_nach_52_5_HOAI( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Minderung_nach_52_5_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Minderung_nach_52_5_HOAI(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Minderung_nach_52_5_HOAI(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Minderung_nach_52_5_HOAI(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Minderung_nach_52_5_HOAI(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Minderung_nach_52_5_HOAI(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zuordnung_KBK_ING3

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zuordnung_KBK_ING3( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zuordnung_KBK_ING3( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zuordnung_KBK_ING3( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zuordnung_KBK_ING3( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zuordnung_KBK_ING3( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zuordnung_KBK_ING3( const Objektart& oa, const Version& version );

// Zuordnung_KBK_ING4

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zuordnung_KBK_ING4( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zuordnung_KBK_ING4( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zuordnung_KBK_ING4( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zuordnung_KBK_ING4( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zuordnung_KBK_ING4( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zuordnung_KBK_ING4( const Objektart& oa, const Version& version );

// Index_HOAI_Fassung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Index_HOAI_Fassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Index_HOAI_Fassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Index_HOAI_Fassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Index_HOAI_Fassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Index_HOAI_Fassung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Index_HOAI_Fassung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Index_HOAI_Fassung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Index_HOAI_Fassung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Index_HOAI_Fassung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Index_HOAI_Fassung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Index_HOAI_Fassung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Index_HOAI_Fassung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Index_HOAI_Fassung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Index_HOAI_Teil

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Index_HOAI_Teil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Index_HOAI_Teil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Index_HOAI_Teil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Index_HOAI_Teil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Index_HOAI_Teil( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Index_HOAI_Teil( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Index_HOAI_Teil( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Index_HOAI_Teil(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Index_HOAI_Teil(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Index_HOAI_Teil(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Index_HOAI_Teil(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Index_HOAI_Teil(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Index_HOAI_Teil(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Index_HOAI_Vertrag

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Index_HOAI_Vertrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Index_HOAI_Vertrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Index_HOAI_Vertrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Index_HOAI_Vertrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Index_HOAI_Vertrag( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Index_HOAI_Vertrag( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Index_HOAI_Vertrag( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Index_HOAI_Vertrag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Index_HOAI_Vertrag(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Index_HOAI_Vertrag(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Index_HOAI_Vertrag(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Index_HOAI_Vertrag(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Index_HOAI_Vertrag(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kostenquelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kostenquelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kostenquelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kostenquelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kostenquelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kostenquelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kostenquelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kostenquelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kostenquelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kostenquelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Kostenquelle(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kostenquelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kostenquelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kostenquelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// HOAI_Honorarberechnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HOAI_Honorarberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HOAI_Honorarberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HOAI_Honorarberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HOAI_Honorarberechnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HOAI_Honorarberechnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HOAI_Honorarberechnung( const Objektart& oa, const Version& version );

// Honorarvereinbarung_HOAI

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Honorarvereinbarung_HOAI( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Honorarvereinbarung_HOAI( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Honorarvereinbarung_HOAI( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Honorarvereinbarung_HOAI( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Honorarvereinbarung_HOAI( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Honorarvereinbarung_HOAI( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Honorarvereinbarung_HOAI( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Honorarvereinbarung_HOAI(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Honorarvereinbarung_HOAI(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Honorarvereinbarung_HOAI(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Honorarvereinbarung_HOAI(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Honorarvereinbarung_HOAI(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Honorarvereinbarung_HOAI(const Version& vsn, const Text& key, Text& value, const int& nVal);

// HOAI_Grundleistungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HOAI_Grundleistungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HOAI_Grundleistungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HOAI_Grundleistungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HOAI_Grundleistungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HOAI_Grundleistungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HOAI_Grundleistungen( const Objektart& oa, const Version& version );

// HOAI_Sonstiges

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HOAI_Sonstiges( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HOAI_Sonstiges( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HOAI_Sonstiges( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HOAI_Sonstiges( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HOAI_Sonstiges( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HOAI_Sonstiges( const Objektart& oa, const Version& version );

// Zuschlag_b_Umbauten_u_Modern

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zuschlag_b_Umbauten_u_Modern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zuschlag_b_Umbauten_u_Modern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zuschlag_b_Umbauten_u_Modern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zuschlag_b_Umbauten_u_Modern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zuschlag_b_Umbauten_u_Modern( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zuschlag_b_Umbauten_u_Modern( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zuschlag_b_Umbauten_u_Modern( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zuschlag_b_Umbauten_u_Modern(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zuschlag_b_Umbauten_u_Modern(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zuschlag_b_Umbauten_u_Modern(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zuschlag_b_Umbauten_u_Modern(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zuschlag_b_Umbauten_u_Modern(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zuschlag_b_Umbauten_u_Modern(const Version& vsn, const Text& key, Text& value, const int& nVal);

// HOAI_Ermittlung_ING_10_11

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HOAI_Ermittlung_ING_10_11( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HOAI_Ermittlung_ING_10_11( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HOAI_Ermittlung_ING_10_11( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HOAI_Ermittlung_ING_10_11( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HOAI_Ermittlung_ING_10_11( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HOAI_Ermittlung_ING_10_11( const Objektart& oa, const Version& version );

// Flaechenanteil_Kostendaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flaechenanteil_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flaechenanteil_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flaechenanteil_Kostendaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flaechenanteil_Kostendaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flaechenanteil_Kostendaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flaechenanteil_Kostendaten( const Objektart& oa, const Version& version );

// MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_MELVER( const Objektart& oa, const Version& version );

// administrative_Angaben_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_administrative_Angaben_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_administrative_Angaben_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_administrative_Angaben_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_administrative_Angaben_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_administrative_Angaben_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_administrative_Angaben_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_administrative_Angaben_MELVER( const Objektart& oa, const Version& version );

// Haushalts_Buchungsst_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Haushalts_Buchungsst_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Haushalts_Buchungsst_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Haushalts_Buchungsst_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Haushalts_Buchungsst_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Haushalts_Buchungsst_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Haushalts_Buchungsst_MELVER( const Objektart& oa, const Version& version );

// Bearbeiter_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bearbeiter_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bearbeiter_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bearbeiter_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bearbeiter_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bearbeiter_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bearbeiter_MELVER( const Objektart& oa, const Version& version );

// Angaben_zur_Bauleistung_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zur_Bauleistung_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zur_Bauleistung_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zur_Bauleistung_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zur_Bauleistung_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zur_Bauleistung_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zur_Bauleistung_MELVER( const Objektart& oa, const Version& version );

// Art_der_Baumassnahme_P_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Baumassnahme_P_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Baumassnahme_P_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Baumassnahme_P_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Baumassnahme_P_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Baumassnahme_P_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Baumassnahme_P_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Baumassnahme_P_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Baumassnahme_P_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Baumassnahme_P_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Baumassnahme_P_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Baumassnahme_P_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Baumassnahme_P_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Baumassnahme_P_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Baumassnahme_B_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Baumassnahme_B_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Baumassnahme_B_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Baumassnahme_B_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Baumassnahme_B_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Baumassnahme_B_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Baumassnahme_B_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Baumassnahme_B_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Baumassnahme_B_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Baumassnahme_B_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Baumassnahme_B_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Baumassnahme_B_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Baumassnahme_B_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Baumassnahme_B_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zu_Bew_Biet_Ang_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zu_Bew_Biet_Ang_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zu_Bew_Biet_Ang_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zu_Bew_Biet_Ang_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zu_Bew_Biet_Ang_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zu_Bew_Biet_Ang_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zu_Bew_Biet_Ang_MELVER( const Objektart& oa, const Version& version );

// Anz_Bewerb_Bieter_Angeb_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anz_Bewerb_Bieter_Angeb_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anz_Bewerb_Bieter_Angeb_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anz_Bewerb_Bieter_Angeb_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anz_Bewerb_Bieter_Angeb_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anz_Bewerb_Bieter_Angeb_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anz_Bewerb_Bieter_Angeb_MELVER( const Objektart& oa, const Version& version );

// Art_Bewerb_Bieter_Angeb_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Bewerb_Bieter_Angeb_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Bewerb_Bieter_Angeb_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Bewerb_Bieter_Angeb_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Bewerb_Bieter_Angeb_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Bewerb_Bieter_Angeb_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Bewerb_Bieter_Angeb_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Bewerb_Bieter_Angeb_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Bewerb_Bieter_Angeb_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Bewerb_Bieter_Angeb_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Bewerb_Bieter_Angeb_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Bewerb_Bieter_Angeb_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Bewerb_Bieter_Angeb_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Bewerb_Bieter_Angeb_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Region_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Region_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Region_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Region_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Region_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Region_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Region_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Region_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Region_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Region_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Region_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Region_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Region_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Region_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zur_Vergabe_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zur_Vergabe_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zur_Vergabe_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zur_Vergabe_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zur_Vergabe_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zur_Vergabe_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zur_Vergabe_MELVER( const Objektart& oa, const Version& version );

// Vergabeart_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vergabeart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vergabeart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vergabeart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vergabeart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vergabeart_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vergabeart_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vergabeart_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vergabeart_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Vergabeart_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vergabeart_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vergabeart_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vergabeart_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angebotsart_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angebotsart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angebotsart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angebotsart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Angebotsart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angebotsart_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angebotsart_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angebotsart_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Angebotsart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Angebotsart_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Angebotsart_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Angebotsart_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Angebotsart_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Angebotsart_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Erl_zur_Vergabeart_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erl_zur_Vergabeart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erl_zur_Vergabeart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erl_zur_Vergabeart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Erl_zur_Vergabeart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erl_zur_Vergabeart_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erl_zur_Vergabeart_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erl_zur_Vergabeart_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Erl_zur_Vergabeart_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Erl_zur_Vergabeart_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Erl_zur_Vergabeart_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Erl_zur_Vergabeart_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Erl_zur_Vergabeart_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Erl_zur_Vergabeart_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ang_zum_Auftragnehmer_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ang_zum_Auftragnehmer_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ang_zum_Auftragnehmer_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ang_zum_Auftragnehmer_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ang_zum_Auftragnehmer_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ang_zum_Auftragnehmer_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ang_zum_Auftragnehmer_MELVER( const Objektart& oa, const Version& version );

// Art_des_Auftragnehmers_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_des_Auftragnehmers_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_des_Auftragnehmers_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_des_Auftragnehmers_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_des_Auftragnehmers_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_des_Auftragnehmers_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_des_Auftragnehmers_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_des_Auftragnehmers_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_des_Auftragnehmers_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_des_Auftragnehmers_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_des_Auftragnehmers_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_des_Auftragnehmers_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_des_Auftragnehmers_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_des_Auftragnehmers_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// vertragl_Best_und_Massn_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_vertragl_Best_und_Massn_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_vertragl_Best_und_Massn_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_vertragl_Best_und_Massn_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_vertragl_Best_und_Massn_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_vertragl_Best_und_Massn_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_vertragl_Best_und_Massn_MELVER( const Objektart& oa, const Version& version );

// rechtliche_Instanz_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_rechtliche_Instanz_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_rechtliche_Instanz_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_rechtliche_Instanz_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_rechtliche_Instanz_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_rechtliche_Instanz_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_rechtliche_Instanz_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_rechtliche_Instanz_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_rechtliche_Instanz_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_rechtliche_Instanz_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_rechtliche_Instanz_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_rechtliche_Instanz_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_rechtliche_Instanz_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_rechtliche_Instanz_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_z_Auftragssumme_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_z_Auftragssumme_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_z_Auftragssumme_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_z_Auftragssumme_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_z_Auftragssumme_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_z_Auftragssumme_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_z_Auftragssumme_MELVER( const Objektart& oa, const Version& version );

// Summe_n_Art_der_Arbeit_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Summe_n_Art_der_Arbeit_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Summe_n_Art_der_Arbeit_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Summe_n_Art_der_Arbeit_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Summe_n_Art_der_Arbeit_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Summe_n_Art_der_Arbeit_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Summe_n_Art_der_Arbeit_MELVER( const Objektart& oa, const Version& version );

// Art_der_Arbeit_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Arbeit_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Arbeit_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Arbeit_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Arbeit_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Arbeit_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Arbeit_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Arbeit_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Arbeit_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Arbeit_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Arbeit_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Arbeit_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Arbeit_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Arbeit_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Summe_n_Unternehmensart_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Summe_n_Unternehmensart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Summe_n_Unternehmensart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Summe_n_Unternehmensart_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Summe_n_Unternehmensart_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Summe_n_Unternehmensart_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Summe_n_Unternehmensart_MELVER( const Objektart& oa, const Version& version );

// Art_des_Unternehmens_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_des_Unternehmens_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_des_Unternehmens_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_des_Unternehmens_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_des_Unternehmens_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_des_Unternehmens_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_des_Unternehmens_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_des_Unternehmens_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_des_Unternehmens_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_des_Unternehmens_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_des_Unternehmens_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_des_Unternehmens_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_des_Unternehmens_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_des_Unternehmens_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Summe_nach_Regionen_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Summe_nach_Regionen_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Summe_nach_Regionen_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Summe_nach_Regionen_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Summe_nach_Regionen_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Summe_nach_Regionen_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Summe_nach_Regionen_MELVER( const Objektart& oa, const Version& version );

// Summe_bevorz_Bewerber_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Summe_bevorz_Bewerber_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Summe_bevorz_Bewerber_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Summe_bevorz_Bewerber_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Summe_bevorz_Bewerber_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Summe_bevorz_Bewerber_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Summe_bevorz_Bewerber_MELVER( const Objektart& oa, const Version& version );

// Grund_der_Bevorzugung_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grund_der_Bevorzugung_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grund_der_Bevorzugung_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grund_der_Bevorzugung_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Grund_der_Bevorzugung_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grund_der_Bevorzugung_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grund_der_Bevorzugung_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grund_der_Bevorzugung_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Grund_der_Bevorzugung_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Grund_der_Bevorzugung_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Grund_der_Bevorzugung_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Grund_der_Bevorzugung_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Grund_der_Bevorzugung_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Grund_der_Bevorzugung_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Auftragskriterium_MELVER

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Auftragskriterium_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Auftragskriterium_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Auftragskriterium_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Auftragskriterium_MELVER( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Auftragskriterium_MELVER( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Auftragskriterium_MELVER( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Auftragskriterium_MELVER( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Auftragskriterium_MELVER(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Auftragskriterium_MELVER(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Auftragskriterium_MELVER(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Auftragskriterium_MELVER(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Auftragskriterium_MELVER(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Auftragskriterium_MELVER(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wochentag

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wochentag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wochentag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wochentag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wochentag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wochentag( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wochentag( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wochentag( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Wochentag(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Wochentag(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Wochentag(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Wochentag(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Wochentag(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Wochentag(const Version& vsn, const Text& key, Text& value, const int& nVal);

// einfacher_Zeitraum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_einfacher_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_einfacher_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_einfacher_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_einfacher_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_einfacher_Zeitraum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_einfacher_Zeitraum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_einfacher_Zeitraum( const Objektart& oa, const Version& version );

// Startdatum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Startdatum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Startdatum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Startdatum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Startdatum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Startdatum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Startdatum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Startdatum( const Objektart& oa, const Version& version );

// Dauer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Dauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Dauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Dauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Dauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Dauer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Dauer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Dauer( const Objektart& oa, const Version& version );

// komplexer_Zeitraum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_komplexer_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_komplexer_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_komplexer_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_komplexer_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_komplexer_Zeitraum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_komplexer_Zeitraum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_komplexer_Zeitraum( const Objektart& oa, const Version& version );

// Operator

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Operator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Operator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Operator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Operator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Operator( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Operator( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Operator( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Operator(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Operator(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Operator(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Operator(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Operator(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zeitraum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zeitraum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zeitraum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zeitraum( const Objektart& oa, const Version& version );

// verwaltungstechn_Zuordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verwaltungstechn_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verwaltungstechn_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verwaltungstechn_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verwaltungstechn_Zuordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verwaltungstechn_Zuordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verwaltungstechn_Zuordnung( const Objektart& oa, const Version& version );

// oertliche_Zuordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_oertliche_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_oertliche_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_oertliche_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_oertliche_Zuordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_oertliche_Zuordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_oertliche_Zuordnung( const Objektart& oa, const Version& version );

// oertliche_Zuordnung_SP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_oertliche_Zuordnung_SP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_oertliche_Zuordnung_SP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_oertliche_Zuordnung_SP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_oertliche_Zuordnung_SP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_oertliche_Zuordnung_SP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_oertliche_Zuordnung_SP( const Objektart& oa, const Version& version );

// nicht_nach_ASB_klass_Strasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_nicht_nach_ASB_klass_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_nicht_nach_ASB_klass_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_nicht_nach_ASB_klass_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_nicht_nach_ASB_klass_Strasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_nicht_nach_ASB_klass_Strasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_nicht_nach_ASB_klass_Strasse( const Objektart& oa, const Version& version );

// Waehrungsangabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Waehrungsangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Waehrungsangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Waehrungsangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Waehrungsangabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Waehrungsangabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Waehrungsangabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Waehrungsangabe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Waehrungsangabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Waehrungsangabe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Waehrungsangabe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Waehrungsangabe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Waehrungsangabe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Waehrungsangabe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vorzeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vorzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vorzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vorzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vorzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vorzeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vorzeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vorzeichen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vorzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vorzeichen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vorzeichen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vorzeichen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vorzeichen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Objekt_ID

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Objekt_ID( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Objekt_ID( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Objekt_ID( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Objekt_ID( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Objekt_ID( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Objekt_ID( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Objekt_ID( const Objektart& oa, const Version& version );

// geometrische_Auspraegung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_geometrische_Auspraegung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_geometrische_Auspraegung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_geometrische_Auspraegung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_geometrische_Auspraegung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_geometrische_Auspraegung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_geometrische_Auspraegung( const Objektart& oa, const Version& version );

// geometrische_Auspraegung_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_geometrische_Auspraegung_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_geometrische_Auspraegung_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_geometrische_Auspraegung_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_geometrische_Auspraegung_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_geometrische_Auspraegung_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_geometrische_Auspraegung_Punkt( const Objektart& oa, const Version& version );

// geometrische_Auspraegung_Linie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_geometrische_Auspraegung_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_geometrische_Auspraegung_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_geometrische_Auspraegung_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_geometrische_Auspraegung_Linie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_geometrische_Auspraegung_Linie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_geometrische_Auspraegung_Linie( const Objektart& oa, const Version& version );

// geometrische_Auspraegung_Flaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_geometrische_Auspraegung_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_geometrische_Auspraegung_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_geometrische_Auspraegung_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_geometrische_Auspraegung_Flaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_geometrische_Auspraegung_Flaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_geometrische_Auspraegung_Flaeche( const Objektart& oa, const Version& version );

// Fotostandpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fotostandpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fotostandpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fotostandpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fotostandpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fotostandpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fotostandpunkt( const Objektart& oa, const Version& version );

// Sensor

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sensor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sensor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sensor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sensor( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sensor( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sensor( const Objektart& oa, const Version& version );

// Art_Sensor

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Sensor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Sensor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Sensor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Sensor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Sensor( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Sensor( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Sensor( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Sensor(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Sensor(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Sensor(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Sensor(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Sensor(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Sensor(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Sensorstandort

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sensorstandort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sensorstandort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sensorstandort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sensorstandort( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sensorstandort( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sensorstandort( const Objektart& oa, const Version& version );

// Sensorstandpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sensorstandpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sensorstandpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sensorstandpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sensorstandpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sensorstandpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sensorstandpunkt( const Objektart& oa, const Version& version );

// Sensorstandlinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sensorstandlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sensorstandlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sensorstandlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sensorstandlinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sensorstandlinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sensorstandlinie( const Objektart& oa, const Version& version );

// Foto

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Foto( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Foto( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Foto( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Foto( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Foto( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Foto( const Objektart& oa, const Version& version );

// fotografisches_Verfahren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_fotografisches_Verfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_fotografisches_Verfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_fotografisches_Verfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_fotografisches_Verfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_fotografisches_Verfahren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_fotografisches_Verfahren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_fotografisches_Verfahren( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_fotografisches_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_fotografisches_Verfahren(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_fotografisches_Verfahren(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_fotografisches_Verfahren(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_fotografisches_Verfahren(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_fotografisches_Verfahren(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Dokument

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Dokument( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Dokument( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Dokument( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Dokument( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Dokument( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Dokument( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Dokument(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Dokument_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Dokument_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Dokument_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Dokument_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Dokument_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Dokument_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Dokument_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Dokument_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Dokument_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Dokument_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Dokument_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Dokument_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Dokument_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Dokument_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Dokument_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Dokument_abstrakt( const Objektart& oa, const Version& version );

// Waehrungsbetrag

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Waehrungsbetrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Waehrungsbetrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Waehrungsbetrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Waehrungsbetrag( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Waehrungsbetrag( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Waehrungsbetrag( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Waehrungsbetrag( const Objektart& oa, const Version& version );

// Objekt_mit_ID

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Objekt_mit_ID( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Objekt_mit_ID( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Objekt_mit_ID( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Objekt_mit_ID( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Objekt_mit_ID( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Objekt_mit_ID( const Objektart& oa, const Version& version );

// Bankverbindung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bankverbindung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bankverbindung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bankverbindung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bankverbindung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bankverbindung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bankverbindung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bankverbindung( const Objektart& oa, const Version& version );

// Erfassungsqualitaet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungsqualitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungsqualitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungsqualitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Erfassungsqualitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungsqualitaet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungsqualitaet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungsqualitaet( const Objektart& oa, const Version& version );

// OKSTRA_Objekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_OKSTRA_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_OKSTRA_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_OKSTRA_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_OKSTRA_Objekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_OKSTRA_Objekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_OKSTRA_Objekt( const Objektart& oa, const Version& version );

// Erfassung_Verfahren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassung_Verfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassung_Verfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassung_Verfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Erfassung_Verfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassung_Verfahren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassung_Verfahren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassung_Verfahren( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Erfassung_Verfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Erfassung_Verfahren(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Erfassung_Verfahren(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Erfassung_Verfahren(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Erfassung_Verfahren(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Erfassung_Verfahren(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Leitung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leitung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leitung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leitung( const Objektart& oa, const Version& version );

// Markierung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Markierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Markierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Markierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Markierung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Markierung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Markierung( const Objektart& oa, const Version& version );

// Schutzplanke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzplanke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzplanke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzplanke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzplanke( const Objektart& oa, const Version& version );

// Strassenausstattung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenausstattung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenausstattung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenausstattung( const Objektart& oa, const Version& version );

// Nebenanlage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nebenanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nebenanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nebenanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nebenanlage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nebenanlage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nebenanlage( const Objektart& oa, const Version& version );

// Rastanlage_nicht_bew

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rastanlage_nicht_bew( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rastanlage_nicht_bew( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rastanlage_nicht_bew( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rastanlage_nicht_bew( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rastanlage_nicht_bew( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rastanlage_nicht_bew( const Objektart& oa, const Version& version );

// Nebenbetrieb

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nebenbetrieb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nebenbetrieb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nebenbetrieb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nebenbetrieb( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nebenbetrieb( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nebenbetrieb( const Objektart& oa, const Version& version );

// Rastanlage_bew

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rastanlage_bew( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rastanlage_bew( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rastanlage_bew( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rastanlage_bew( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rastanlage_bew( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rastanlage_bew( const Objektart& oa, const Version& version );

// Rastanlage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rastanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rastanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rastanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rastanlage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rastanlage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rastanlage( const Objektart& oa, const Version& version );

// Ausstattung_und_Anlagen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausstattung_und_Anlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausstattung_und_Anlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausstattung_und_Anlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausstattung_und_Anlagen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausstattung_und_Anlagen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausstattung_und_Anlagen( const Objektart& oa, const Version& version );

// Leitungsverlauf

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leitungsverlauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leitungsverlauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leitungsverlauf( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leitungsverlauf( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leitungsverlauf( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leitungsverlauf( const Objektart& oa, const Version& version );

// Leitungstraeger

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leitungstraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leitungstraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leitungstraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leitungstraeger( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leitungstraeger( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leitungstraeger( const Objektart& oa, const Version& version );

// Leitungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leitungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leitungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leitungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leitungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leitungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leitungsart( const Objektart& oa, const Version& version );

// Tab_Markierung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Markierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Markierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Markierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Markierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Markierung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Markierung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Markierung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Markierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Markierung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Markierung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Markierung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Markierung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenentwaesserung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenentwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenentwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenentwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenentwaesserung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenentwaesserung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenentwaesserung( const Objektart& oa, const Version& version );

// entwaesserte_Fahrbahnflaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_entwaesserte_Fahrbahnflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_entwaesserte_Fahrbahnflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_entwaesserte_Fahrbahnflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_entwaesserte_Fahrbahnflaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_entwaesserte_Fahrbahnflaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_entwaesserte_Fahrbahnflaeche( const Objektart& oa, const Version& version );

// Lage_Entwaesserung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Entwaesserung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Entwaesserung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Entwaesserung( const Objektart& oa, const Version& version );

// Lage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Einleitung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einleitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einleitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einleitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Einleitung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einleitung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einleitung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einleitung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Einleitung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Einleitung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Einleitung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Einleitung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Einleitung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Entwaesserung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Entwaesserung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Entwaesserung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Entwaesserung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Entwaesserung( const Objektart& oa, const Version& version );

// historisches_Objekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_historisches_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_historisches_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_historisches_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_historisches_Objekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_historisches_Objekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_historisches_Objekt( const Objektart& oa, const Version& version );

// Ereignis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ereignis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ereignis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ereignis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ereignis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ereignis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ereignis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ereignis( const Objektart& oa, const Version& version );

// Projekt_Strassenbau

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Projekt_Strassenbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Projekt_Strassenbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Projekt_Strassenbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Projekt_Strassenbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Projekt_Strassenbau( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Projekt_Strassenbau( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Projekt_Strassenbau( const Objektart& oa, const Version& version );

// identisches_Netzteil

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_identisches_Netzteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_identisches_Netzteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_identisches_Netzteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_identisches_Netzteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_identisches_Netzteil( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_identisches_Netzteil( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_identisches_Netzteil( const Objektart& oa, const Version& version );

// Veraenderungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Veraenderungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Veraenderungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Veraenderungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Veraenderungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Veraenderungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Veraenderungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Veraenderungsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Veraenderungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Veraenderungsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Veraenderungsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Veraenderungsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Veraenderungsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Teilabschnitt_IdNT

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilabschnitt_IdNT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilabschnitt_IdNT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilabschnitt_IdNT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Teilabschnitt_IdNT( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilabschnitt_IdNT( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilabschnitt_IdNT( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilabschnitt_IdNT( const Objektart& oa, const Version& version );

// Fahrstreifen_Nummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrstreifen_Nummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrstreifen_Nummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrstreifen_Nummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrstreifen_Nummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrstreifen_Nummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrstreifen_Nummer( const Objektart& oa, const Version& version );

// Verkehrsrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verkehrsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verkehrsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verkehrsrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verkehrsrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verkehrsrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verkehrsrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anzahl_Fahrstreifen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anzahl_Fahrstreifen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anzahl_Fahrstreifen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anzahl_Fahrstreifen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anzahl_Fahrstreifen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anzahl_Fahrstreifen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anzahl_Fahrstreifen( const Objektart& oa, const Version& version );

// Insassen_min_Anzahl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Insassen_min_Anzahl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Insassen_min_Anzahl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Insassen_min_Anzahl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Insassen_min_Anzahl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Insassen_min_Anzahl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Insassen_min_Anzahl( const Objektart& oa, const Version& version );

// max_Geschwindigkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_max_Geschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_max_Geschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_max_Geschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_max_Geschwindigkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_max_Geschwindigkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_max_Geschwindigkeit( const Objektart& oa, const Version& version );

// max_Hoehe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_max_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_max_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_max_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_max_Hoehe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_max_Hoehe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_max_Hoehe( const Objektart& oa, const Version& version );

// max_Breite

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_max_Breite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_max_Breite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_max_Breite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_max_Breite( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_max_Breite( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_max_Breite( const Objektart& oa, const Version& version );

// max_Laenge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_max_Laenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_max_Laenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_max_Laenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_max_Laenge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_max_Laenge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_max_Laenge( const Objektart& oa, const Version& version );

// max_Gewicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_max_Gewicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_max_Gewicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_max_Gewicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_max_Gewicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_max_Gewicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_max_Gewicht( const Objektart& oa, const Version& version );

// max_Achsgewicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_max_Achsgewicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_max_Achsgewicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_max_Achsgewicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_max_Achsgewicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_max_Achsgewicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_max_Achsgewicht( const Objektart& oa, const Version& version );

// Ueberholverbot

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ueberholverbot( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ueberholverbot( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ueberholverbot( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ueberholverbot( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ueberholverbot( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ueberholverbot( const Objektart& oa, const Version& version );

// Zugangsbeschraenkung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zugangsbeschraenkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zugangsbeschraenkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zugangsbeschraenkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zugangsbeschraenkung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zugangsbeschraenkung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zugangsbeschraenkung( const Objektart& oa, const Version& version );

// Gesperrt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gesperrt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gesperrt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gesperrt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gesperrt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gesperrt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gesperrt( const Objektart& oa, const Version& version );

// Beschraenkung_verkehrlich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beschraenkung_verkehrlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beschraenkung_verkehrlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beschraenkung_verkehrlich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beschraenkung_verkehrlich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beschraenkung_verkehrlich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beschraenkung_verkehrlich( const Objektart& oa, const Version& version );

// Fkt_d_Verb_im_Knotenpktber

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fkt_d_Verb_im_Knotenpktber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fkt_d_Verb_im_Knotenpktber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fkt_d_Verb_im_Knotenpktber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fkt_d_Verb_im_Knotenpktber( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fkt_d_Verb_im_Knotenpktber( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fkt_d_Verb_im_Knotenpktber( const Objektart& oa, const Version& version );

// Bergpass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bergpass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bergpass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bergpass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bergpass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bergpass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bergpass( const Objektart& oa, const Version& version );

// Verkehrsbedeutung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsbedeutung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsbedeutung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsbedeutung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsbedeutung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsbedeutung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsbedeutung( const Objektart& oa, const Version& version );

// Spur_fuer_Rettungsfahrzeuge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Spur_fuer_Rettungsfahrzeuge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Spur_fuer_Rettungsfahrzeuge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Spur_fuer_Rettungsfahrzeuge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Spur_fuer_Rettungsfahrzeuge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Spur_fuer_Rettungsfahrzeuge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Spur_fuer_Rettungsfahrzeuge( const Objektart& oa, const Version& version );

// Strassenfunktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenfunktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenfunktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenfunktion( const Objektart& oa, const Version& version );

// Aussichtswert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aussichtswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aussichtswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aussichtswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aussichtswert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aussichtswert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aussichtswert( const Objektart& oa, const Version& version );

// gebuehrenpflichtig

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_gebuehrenpflichtig( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_gebuehrenpflichtig( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_gebuehrenpflichtig( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_gebuehrenpflichtig( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_gebuehrenpflichtig( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_gebuehrenpflichtig( const Objektart& oa, const Version& version );

// Staugefahr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Staugefahr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Staugefahr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Staugefahr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Staugefahr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Staugefahr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Staugefahr( const Objektart& oa, const Version& version );

// Durchschnittsgeschwindigkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Durchschnittsgeschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Durchschnittsgeschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Durchschnittsgeschwindigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Durchschnittsgeschwindigkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Durchschnittsgeschwindigkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Durchschnittsgeschwindigkeit( const Objektart& oa, const Version& version );

// Strassenbeschreibung_verkehrl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenbeschreibung_verkehrl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenbeschreibung_verkehrl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenbeschreibung_verkehrl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenbeschreibung_verkehrl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenbeschreibung_verkehrl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenbeschreibung_verkehrl( const Objektart& oa, const Version& version );

// Tab_Funktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Funktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Funktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Funktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Funktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Funktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Funktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Funktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// ZEB_Objekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Objekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Objekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Objekt( const Objektart& oa, const Version& version );

// ZEB_Projekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Projekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Projekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Projekt( const Objektart& oa, const Version& version );

// Wert_der_Zustandsgroesse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_der_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_der_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_der_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_der_Zustandsgroesse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_der_Zustandsgroesse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_der_Zustandsgroesse( const Objektart& oa, const Version& version );

// Wert_eines_Messwertes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_eines_Messwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_eines_Messwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_eines_Messwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_eines_Messwertes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_eines_Messwertes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_eines_Messwertes( const Objektart& oa, const Version& version );

// Wert_des_Zustandswertes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_des_Zustandswertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_des_Zustandswertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_des_Zustandswertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_des_Zustandswertes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_des_Zustandswertes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_des_Zustandswertes( const Objektart& oa, const Version& version );

// Eintrag_in_Beschreibungstext

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Eintrag_in_Beschreibungstext( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Eintrag_in_Beschreibungstext( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Eintrag_in_Beschreibungstext( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Eintrag_in_Beschreibungstext( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Eintrag_in_Beschreibungstext( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Eintrag_in_Beschreibungstext( const Objektart& oa, const Version& version );

// Wert_des_Zustandsteilwertes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_des_Zustandsteilwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_des_Zustandsteilwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_des_Zustandsteilwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_des_Zustandsteilwertes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_des_Zustandsteilwertes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_des_Zustandsteilwertes( const Objektart& oa, const Version& version );

// Wert_des_Zustandsgesamtwertes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_des_Zustandsgesamtwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_des_Zustandsgesamtwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_des_Zustandsgesamtwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_des_Zustandsgesamtwertes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_des_Zustandsgesamtwertes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_des_Zustandsgesamtwertes( const Objektart& oa, const Version& version );

// zugewiesene_Zustandsklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zugewiesene_Zustandsklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zugewiesene_Zustandsklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zugewiesene_Zustandsklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zugewiesene_Zustandsklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zugewiesene_Zustandsklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zugewiesene_Zustandsklasse( const Objektart& oa, const Version& version );

// Wert_einer_Zustandsgroesse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_einer_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_einer_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_einer_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_einer_Zustandsgroesse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_einer_Zustandsgroesse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_einer_Zustandsgroesse( const Objektart& oa, const Version& version );

// Wert_eines_Zustandswertes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_eines_Zustandswertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_eines_Zustandswertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_eines_Zustandswertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_eines_Zustandswertes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_eines_Zustandswertes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_eines_Zustandswertes( const Objektart& oa, const Version& version );

// Wert_eines_Teilwertes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_eines_Teilwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_eines_Teilwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_eines_Teilwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_eines_Teilwertes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_eines_Teilwertes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_eines_Teilwertes( const Objektart& oa, const Version& version );

// Wert_eines_Gesamtwertes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_eines_Gesamtwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_eines_Gesamtwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_eines_Gesamtwertes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_eines_Gesamtwertes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_eines_Gesamtwertes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_eines_Gesamtwertes( const Objektart& oa, const Version& version );

// Wert_eines_Rohdatums

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_eines_Rohdatums( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_eines_Rohdatums( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_eines_Rohdatums( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_eines_Rohdatums( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_eines_Rohdatums( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_eines_Rohdatums( const Objektart& oa, const Version& version );

// ZEB_Parameterwert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Parameterwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Parameterwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Parameterwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Parameterwert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Parameterwert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Parameterwert( const Objektart& oa, const Version& version );

// Art_des_ZEB_Objektes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_des_ZEB_Objektes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_des_ZEB_Objektes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_des_ZEB_Objektes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_des_ZEB_Objektes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_des_ZEB_Objektes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_des_ZEB_Objektes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_des_ZEB_Objektes( const Objektart& oa, const Version& version );

// ZEB_Parameter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Parameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Parameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Parameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Parameter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Parameter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Parameter( const Objektart& oa, const Version& version );

// ZEB_Dokument

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Dokument( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Dokument( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Dokument( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Dokument( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Dokument( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Dokument( const Objektart& oa, const Version& version );

// ZEB_Ereignis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Ereignis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Ereignis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Ereignis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Ereignis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Ereignis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Ereignis( const Objektart& oa, const Version& version );

// ZEB_Erfasser

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Erfasser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Erfasser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Erfasser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Erfasser( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Erfasser( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Erfasser( const Objektart& oa, const Version& version );

// ZEB_Bewerter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Bewerter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Bewerter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Bewerter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Bewerter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Bewerter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Bewerter( const Objektart& oa, const Version& version );

// ZEB_Veranlasser

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Veranlasser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Veranlasser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Veranlasser( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Veranlasser( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Veranlasser( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Veranlasser( const Objektart& oa, const Version& version );

// ZEB_Subjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Subjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Subjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Subjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Subjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Subjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Subjekt( const Objektart& oa, const Version& version );

// ZEB_Parameterliste

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Parameterliste( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Parameterliste( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Parameterliste( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Parameterliste( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Parameterliste( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Parameterliste( const Objektart& oa, const Version& version );

// Zustandsmessverfahren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsmessverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsmessverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsmessverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsmessverfahren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsmessverfahren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsmessverfahren( const Objektart& oa, const Version& version );

// ZEB_visuell_sensit_Wahrnehmung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_visuell_sensit_Wahrnehmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_visuell_sensit_Wahrnehmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_visuell_sensit_Wahrnehmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_visuell_sensit_Wahrnehmung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_visuell_sensit_Wahrnehmung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_visuell_sensit_Wahrnehmung( const Objektart& oa, const Version& version );

// Aggregationsmethode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aggregationsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aggregationsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aggregationsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aggregationsmethode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aggregationsmethode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aggregationsmethode( const Objektart& oa, const Version& version );

// Zustandserfassungsmethode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandserfassungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandserfassungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandserfassungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandserfassungsmethode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandserfassungsmethode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandserfassungsmethode( const Objektart& oa, const Version& version );

// Normierungsmethode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Normierungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Normierungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Normierungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Normierungsmethode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Normierungsmethode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Normierungsmethode( const Objektart& oa, const Version& version );

// Kombinationsmethode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kombinationsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kombinationsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kombinationsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kombinationsmethode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kombinationsmethode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kombinationsmethode( const Objektart& oa, const Version& version );

// Klassifizierungsmethode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Klassifizierungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Klassifizierungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Klassifizierungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Klassifizierungsmethode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Klassifizierungsmethode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Klassifizierungsmethode( const Objektart& oa, const Version& version );

// Zustandsbewertungsmethode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsbewertungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsbewertungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsbewertungsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsbewertungsmethode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsbewertungsmethode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsbewertungsmethode( const Objektart& oa, const Version& version );

// ZEB_Methode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ZEB_Methode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ZEB_Methode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ZEB_Methode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ZEB_Methode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ZEB_Methode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ZEB_Methode( const Objektart& oa, const Version& version );

// Zustandsgroesse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsgroesse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsgroesse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsgroesse( const Objektart& oa, const Version& version );

// Zustandswert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandswert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandswert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandswert( const Objektart& oa, const Version& version );

// Zustandsteilwert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsteilwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsteilwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsteilwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsteilwert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsteilwert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsteilwert( const Objektart& oa, const Version& version );

// Zustandsgesamtwert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsgesamtwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsgesamtwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsgesamtwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsgesamtwert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsgesamtwert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsgesamtwert( const Objektart& oa, const Version& version );

// Zustandsklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsklasse( const Objektart& oa, const Version& version );

// Zustandsgroesse_o_Zustandswert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsgroesse_o_Zustandswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsgroesse_o_Zustandswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsgroesse_o_Zustandswert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsgroesse_o_Zustandswert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsgroesse_o_Zustandswert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsgroesse_o_Zustandswert( const Objektart& oa, const Version& version );

// Zustandsindikator

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsindikator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsindikator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsindikator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsindikator( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsindikator( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsindikator( const Objektart& oa, const Version& version );

// Zustandsmerkmal

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsmerkmal( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsmerkmal( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsmerkmal( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsmerkmal( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsmerkmal( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsmerkmal( const Objektart& oa, const Version& version );

// Messwert_oder_Beschrgroesse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Messwert_oder_Beschrgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Messwert_oder_Beschrgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Messwert_oder_Beschrgroesse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Messwert_oder_Beschrgroesse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Messwert_oder_Beschrgroesse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Messwert_oder_Beschrgroesse( const Objektart& oa, const Version& version );

// Art_ZEB_Parameter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_ZEB_Parameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_ZEB_Parameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_ZEB_Parameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_ZEB_Parameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_ZEB_Parameter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_ZEB_Parameter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_ZEB_Parameter( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_ZEB_Parameter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_ZEB_Parameter(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_ZEB_Parameter(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_ZEB_Parameter(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_ZEB_Parameter(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_ZEB_Parameter(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_ZEB_Methode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_ZEB_Methode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_ZEB_Methode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_ZEB_Methode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_ZEB_Methode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_ZEB_Methode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_ZEB_Methode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_ZEB_Methode( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_ZEB_Methode(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_ZEB_Methode(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_ZEB_Methode(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_ZEB_Methode(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_ZEB_Methode(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_ZEB_Methode(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schicht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schicht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schicht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schicht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schicht( const Objektart& oa, const Version& version );

// Schichtbegrenzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schichtbegrenzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schichtbegrenzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schichtbegrenzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schichtbegrenzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schichtbegrenzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schichtbegrenzung( const Objektart& oa, const Version& version );

// Schichtart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schichtart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schichtart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schichtart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schichtart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schichtart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schichtart( const Objektart& oa, const Version& version );

// Schichtmaterial

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schichtmaterial( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schichtmaterial( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schichtmaterial( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schichtmaterial( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schichtmaterial( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schichtmaterial( const Objektart& oa, const Version& version );

// Querschnittstreifen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Querschnittstreifen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Querschnittstreifen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Querschnittstreifen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Querschnittstreifen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Querschnittstreifen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Querschnittstreifen( const Objektart& oa, const Version& version );

// Streifenart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Streifenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Streifenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Streifenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Streifenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Streifenart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Streifenart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Streifenart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Streifenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Streifenart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Streifenart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Streifenart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Streifenart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Streifenbegrenzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Streifenbegrenzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Streifenbegrenzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Streifenbegrenzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Streifenbegrenzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Streifenbegrenzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Streifenbegrenzung( const Objektart& oa, const Version& version );

// Bauklasse_Oberbau

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauklasse_Oberbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauklasse_Oberbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauklasse_Oberbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauklasse_Oberbau( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauklasse_Oberbau( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauklasse_Oberbau( const Objektart& oa, const Version& version );

// Bauweise_Oberbau

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauweise_Oberbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauweise_Oberbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauweise_Oberbau( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauweise_Oberbau( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauweise_Oberbau( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauweise_Oberbau( const Objektart& oa, const Version& version );

// Regelquerschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Regelquerschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Regelquerschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Regelquerschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Regelquerschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Regelquerschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Regelquerschnitt( const Objektart& oa, const Version& version );

// Bahnigkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bahnigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bahnigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bahnigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bahnigkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bahnigkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bahnigkeit( const Objektart& oa, const Version& version );

// Kennzeichen_Bahnigkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kennzeichen_Bahnigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kennzeichen_Bahnigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kennzeichen_Bahnigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kennzeichen_Bahnigkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kennzeichen_Bahnigkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kennzeichen_Bahnigkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kennzeichen_Bahnigkeit( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kennzeichen_Bahnigkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kennzeichen_Bahnigkeit(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Kennzeichen_Bahnigkeit(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kennzeichen_Bahnigkeit(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kennzeichen_Bahnigkeit(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kennzeichen_Bahnigkeit(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fahrbahnlaengsneigung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrbahnlaengsneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrbahnlaengsneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrbahnlaengsneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrbahnlaengsneigung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrbahnlaengsneigung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrbahnlaengsneigung( const Objektart& oa, const Version& version );

// Fahrbahnquerneigung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrbahnquerneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrbahnquerneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrbahnquerneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrbahnquerneigung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrbahnquerneigung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrbahnquerneigung( const Objektart& oa, const Version& version );

// Fahrbahntrennung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrbahntrennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrbahntrennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrbahntrennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrbahntrennung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrbahntrennung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrbahntrennung( const Objektart& oa, const Version& version );

// Trassenbreite

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Trassenbreite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Trassenbreite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Trassenbreite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Trassenbreite( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Trassenbreite( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Trassenbreite( const Objektart& oa, const Version& version );

// Fahrbahnbreite

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrbahnbreite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrbahnbreite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrbahnbreite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrbahnbreite( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrbahnbreite( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrbahnbreite( const Objektart& oa, const Version& version );

// Fussweg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fussweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fussweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fussweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fussweg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fussweg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fussweg( const Objektart& oa, const Version& version );

// Radweg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Radweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Radweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Radweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Radweg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Radweg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Radweg( const Objektart& oa, const Version& version );

// Schutzzone

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzzone( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzzone( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzzone( const Objektart& oa, const Version& version );

// Hindernis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hindernis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hindernis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hindernis( const Objektart& oa, const Version& version );

// Hindernis_Art

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hindernis_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hindernis_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hindernis_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hindernis_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hindernis_Art( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hindernis_Art( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hindernis_Art( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Hindernis_Art(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Hindernis_Art(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Hindernis_Art(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Hindernis_Art(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Hindernis_Art(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Hindernis_Art(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fussgaengerueberweg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fussgaengerueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fussgaengerueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fussgaengerueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fussgaengerueberweg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fussgaengerueberweg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fussgaengerueberweg( const Objektart& oa, const Version& version );

// Bahnkoerperlage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bahnkoerperlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bahnkoerperlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bahnkoerperlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bahnkoerperlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bahnkoerperlage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bahnkoerperlage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bahnkoerperlage( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bahnkoerperlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bahnkoerperlage(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bahnkoerperlage(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bahnkoerperlage(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bahnkoerperlage(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lage_Ueberweg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Ueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Ueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Ueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Ueberweg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Ueberweg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Ueberweg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Ueberweg( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Ueberweg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Ueberweg(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Ueberweg(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Ueberweg(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Ueberweg(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Durchlass( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Durchlass(const Version& vsn);

// Baustoff

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baustoff( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baustoff( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baustoff( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baustoff( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baustoff( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baustoff( const Objektart& oa, const Version& version );

// Profil

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Profil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Profil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Profil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Profil( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Profil( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Profil( const Objektart& oa, const Version& version );

// Profilform

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Profilform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Profilform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Profilform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Profilform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Profilform( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Profilform( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Profilform( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Profilform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Profilform(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Profilform(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Profilform(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Profilform(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Profilform(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerk( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Bauwerk(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Bruecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bruecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bruecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bruecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bruecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bruecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bruecke( const Objektart& oa, const Version& version );

// Verkehrszeichenbruecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrszeichenbruecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrszeichenbruecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrszeichenbruecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrszeichenbruecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrszeichenbruecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrszeichenbruecke( const Objektart& oa, const Version& version );

// Tunnel_Trogbauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tunnel_Trogbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tunnel_Trogbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tunnel_Trogbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tunnel_Trogbauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tunnel_Trogbauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tunnel_Trogbauwerk( const Objektart& oa, const Version& version );

// Laermschutzbauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Laermschutzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Laermschutzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Laermschutzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Laermschutzbauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Laermschutzbauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Laermschutzbauwerk( const Objektart& oa, const Version& version );

// Stuetzbauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Stuetzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Stuetzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Stuetzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Stuetzbauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Stuetzbauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Stuetzbauwerk( const Objektart& oa, const Version& version );

// sonstiges_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_sonstiges_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_sonstiges_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_sonstiges_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_sonstiges_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_sonstiges_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_sonstiges_Bauwerk( const Objektart& oa, const Version& version );

// Teilbauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilbauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilbauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilbauwerk( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Teilbauwerk(const Version& vsn);
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Teilbauwerk(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Sachverhalt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sachverhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sachverhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sachverhalt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sachverhalt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sachverhalt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sachverhalt( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Sachverhalt(const Version& vsn);

// Bauwerksbeschilderung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerksbeschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerksbeschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerksbeschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerksbeschilderung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerksbeschilderung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerksbeschilderung( const Objektart& oa, const Version& version );

// Bauwerksbelaege

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerksbelaege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerksbelaege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerksbelaege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerksbelaege( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerksbelaege( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerksbelaege( const Objektart& oa, const Version& version );

// Entwuerfe_und_Berechnungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwuerfe_und_Berechnungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwuerfe_und_Berechnungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwuerfe_und_Berechnungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwuerfe_und_Berechnungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwuerfe_und_Berechnungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwuerfe_und_Berechnungen( const Objektart& oa, const Version& version );

// Brueckenfeld_Stuetzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Brueckenfeld_Stuetzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Brueckenfeld_Stuetzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Brueckenfeld_Stuetzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Brueckenfeld_Stuetzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Brueckenfeld_Stuetzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Brueckenfeld_Stuetzung( const Objektart& oa, const Version& version );

// Segment_Tunnel_Trogbauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Segment_Tunnel_Trogbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Segment_Tunnel_Trogbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Segment_Tunnel_Trogbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Segment_Tunnel_Trogbauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Segment_Tunnel_Trogbauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Segment_Tunnel_Trogbauwerk( const Objektart& oa, const Version& version );

// Segment_Laermschutzbauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Segment_Laermschutzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Segment_Laermschutzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Segment_Laermschutzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Segment_Laermschutzbauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Segment_Laermschutzbauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Segment_Laermschutzbauwerk( const Objektart& oa, const Version& version );

// Segment_Stuetzbauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Segment_Stuetzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Segment_Stuetzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Segment_Stuetzbauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Segment_Stuetzbauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Segment_Stuetzbauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Segment_Stuetzbauwerk( const Objektart& oa, const Version& version );

// Pruefanweisungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pruefanweisungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pruefanweisungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pruefanweisungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pruefanweisungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pruefanweisungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pruefanweisungen( const Objektart& oa, const Version& version );

// durchgef_Pruefungen_Messungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_durchgef_Pruefungen_Messungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_durchgef_Pruefungen_Messungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_durchgef_Pruefungen_Messungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_durchgef_Pruefungen_Messungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_durchgef_Pruefungen_Messungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_durchgef_Pruefungen_Messungen( const Objektart& oa, const Version& version );

// gegenw_dokum_Schadensstand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_gegenw_dokum_Schadensstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_gegenw_dokum_Schadensstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_gegenw_dokum_Schadensstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_gegenw_dokum_Schadensstand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_gegenw_dokum_Schadensstand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_gegenw_dokum_Schadensstand( const Objektart& oa, const Version& version );

// gegenw_dokum_Pruefungsstand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_gegenw_dokum_Pruefungsstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_gegenw_dokum_Pruefungsstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_gegenw_dokum_Pruefungsstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_gegenw_dokum_Pruefungsstand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_gegenw_dokum_Pruefungsstand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_gegenw_dokum_Pruefungsstand( const Objektart& oa, const Version& version );

// Schadensdaten_abgeschl_Prfg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schadensdaten_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schadensdaten_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schadensdaten_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schadensdaten_abgeschl_Prfg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schadensdaten_abgeschl_Prfg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schadensdaten_abgeschl_Prfg( const Objektart& oa, const Version& version );

// Pruefungsdaten_abgeschl_Prfg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pruefungsdaten_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pruefungsdaten_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pruefungsdaten_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pruefungsdaten_abgeschl_Prfg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pruefungsdaten_abgeschl_Prfg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pruefungsdaten_abgeschl_Prfg( const Objektart& oa, const Version& version );

// Prueffahrzeuge_Pruefgeraete

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Prueffahrzeuge_Pruefgeraete( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Prueffahrzeuge_Pruefgeraete( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Prueffahrzeuge_Pruefgeraete( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Prueffahrzeuge_Pruefgeraete( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Prueffahrzeuge_Pruefgeraete( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Prueffahrzeuge_Pruefgeraete( const Objektart& oa, const Version& version );

// Anlagen_Bauwerksbuch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anlagen_Bauwerksbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anlagen_Bauwerksbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anlagen_Bauwerksbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anlagen_Bauwerksbuch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anlagen_Bauwerksbuch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anlagen_Bauwerksbuch( const Objektart& oa, const Version& version );

// Verwaltungsmassn_Sondervereinb

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verwaltungsmassn_Sondervereinb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verwaltungsmassn_Sondervereinb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verwaltungsmassn_Sondervereinb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verwaltungsmassn_Sondervereinb( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verwaltungsmassn_Sondervereinb( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verwaltungsmassn_Sondervereinb( const Objektart& oa, const Version& version );

// Bau_und_Erhaltungsmassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bau_und_Erhaltungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bau_und_Erhaltungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bau_und_Erhaltungsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bau_und_Erhaltungsmassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bau_und_Erhaltungsmassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bau_und_Erhaltungsmassnahme( const Objektart& oa, const Version& version );

// Kosten_fuer_Bau_Erh_und_Betr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kosten_fuer_Bau_Erh_und_Betr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kosten_fuer_Bau_Erh_und_Betr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kosten_fuer_Bau_Erh_und_Betr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kosten_fuer_Bau_Erh_und_Betr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kosten_fuer_Bau_Erh_und_Betr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kosten_fuer_Bau_Erh_und_Betr( const Objektart& oa, const Version& version );

// Ausstattung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausstattung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausstattung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausstattung( const Objektart& oa, const Version& version );

// Schutzeinrichtungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzeinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzeinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzeinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzeinrichtungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzeinrichtungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzeinrichtungen( const Objektart& oa, const Version& version );

// Vorspannungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vorspannungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vorspannungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vorspannungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vorspannungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vorspannungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vorspannungen( const Objektart& oa, const Version& version );

// Gruendungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gruendungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gruendungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gruendungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gruendungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gruendungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gruendungen( const Objektart& oa, const Version& version );

// Erd_und_Felsanker

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erd_und_Felsanker( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erd_und_Felsanker( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erd_und_Felsanker( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erd_und_Felsanker( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erd_und_Felsanker( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erd_und_Felsanker( const Objektart& oa, const Version& version );

// Lager

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lager( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lager( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lager( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lager( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lager( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lager( const Objektart& oa, const Version& version );

// Fahrbahnuebergangskonstruktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrbahnuebergangskonstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrbahnuebergangskonstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrbahnuebergangskonstruktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrbahnuebergangskonstruktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrbahnuebergangskonstruktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrbahnuebergangskonstruktion( const Objektart& oa, const Version& version );

// Kappe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kappe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kappe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kappe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kappe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kappe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kappe( const Objektart& oa, const Version& version );

// Brueckenseile_und_kabel

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Brueckenseile_und_kabel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Brueckenseile_und_kabel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Brueckenseile_und_kabel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Brueckenseile_und_kabel( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Brueckenseile_und_kabel( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Brueckenseile_und_kabel( const Objektart& oa, const Version& version );

// Abdichtungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abdichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abdichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abdichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abdichtungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abdichtungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abdichtungen( const Objektart& oa, const Version& version );

// statisches_System_Tragfaehigkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_statisches_System_Tragfaehigkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_statisches_System_Tragfaehigkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_statisches_System_Tragfaehigkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_statisches_System_Tragfaehigkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_statisches_System_Tragfaehigkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_statisches_System_Tragfaehigkt( const Objektart& oa, const Version& version );

// Hauptbaustoff_Beton

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hauptbaustoff_Beton( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hauptbaustoff_Beton( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hauptbaustoff_Beton( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hauptbaustoff_Beton( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hauptbaustoff_Beton( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hauptbaustoff_Beton( const Objektart& oa, const Version& version );

// Hauptbaustoff_Stahl_Holz_Kunst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hauptbaustoff_Stahl_Holz_Kunst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hauptbaustoff_Stahl_Holz_Kunst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hauptbaustoff_Stahl_Holz_Kunst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hauptbaustoff_Stahl_Holz_Kunst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hauptbaustoff_Stahl_Holz_Kunst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hauptbaustoff_Stahl_Holz_Kunst( const Objektart& oa, const Version& version );

// Hauptbaustoff_Verbundwerkst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hauptbaustoff_Verbundwerkst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hauptbaustoff_Verbundwerkst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hauptbaustoff_Verbundwerkst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hauptbaustoff_Verbundwerkst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hauptbaustoff_Verbundwerkst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hauptbaustoff_Verbundwerkst( const Objektart& oa, const Version& version );

// Gestaltungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gestaltungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gestaltungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gestaltungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gestaltungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gestaltungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gestaltungen( const Objektart& oa, const Version& version );

// Leitungen_an_Bauwerken

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leitungen_an_Bauwerken( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leitungen_an_Bauwerken( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leitungen_an_Bauwerken( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leitungen_an_Bauwerken( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leitungen_an_Bauwerken( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leitungen_an_Bauwerken( const Objektart& oa, const Version& version );

// Verfuellungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verfuellungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verfuellungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verfuellungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verfuellungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verfuellungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verfuellungen( const Objektart& oa, const Version& version );

// Betonersatz_nach_ZTV_SIB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betonersatz_nach_ZTV_SIB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betonersatz_nach_ZTV_SIB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betonersatz_nach_ZTV_SIB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betonersatz_nach_ZTV_SIB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betonersatz_nach_ZTV_SIB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betonersatz_nach_ZTV_SIB( const Objektart& oa, const Version& version );

// Oberflschutz_nach_ZTV_SIB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Oberflschutz_nach_ZTV_SIB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Oberflschutz_nach_ZTV_SIB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Oberflschutz_nach_ZTV_SIB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Oberflschutz_nach_ZTV_SIB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Oberflschutz_nach_ZTV_SIB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Oberflschutz_nach_ZTV_SIB( const Objektart& oa, const Version& version );

// Korrosionsschutzbeschichtungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Korrosionsschutzbeschichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Korrosionsschutzbeschichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Korrosionsschutzbeschichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Korrosionsschutzbeschichtungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Korrosionsschutzbeschichtungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Korrosionsschutzbeschichtungen( const Objektart& oa, const Version& version );

// Reaktionsharzgeb_Duennbelaege

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Reaktionsharzgeb_Duennbelaege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Reaktionsharzgeb_Duennbelaege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Reaktionsharzgeb_Duennbelaege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Reaktionsharzgeb_Duennbelaege( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Reaktionsharzgeb_Duennbelaege( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Reaktionsharzgeb_Duennbelaege( const Objektart& oa, const Version& version );

// Tunnelbeleuchtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tunnelbeleuchtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tunnelbeleuchtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tunnelbeleuchtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tunnelbeleuchtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tunnelbeleuchtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tunnelbeleuchtung( const Objektart& oa, const Version& version );

// Tunnellueftung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tunnellueftung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tunnellueftung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tunnellueftung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tunnellueftung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tunnellueftung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tunnellueftung( const Objektart& oa, const Version& version );

// Tunnelsicherheit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tunnelsicherheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tunnelsicherheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tunnelsicherheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tunnelsicherheit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tunnelsicherheit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tunnelsicherheit( const Objektart& oa, const Version& version );

// Tunnel_Verkehrseinrichtungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tunnel_Verkehrseinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tunnel_Verkehrseinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tunnel_Verkehrseinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tunnel_Verkehrseinrichtungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tunnel_Verkehrseinrichtungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tunnel_Verkehrseinrichtungen( const Objektart& oa, const Version& version );

// Tunnel_Zentrale_Anlagen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tunnel_Zentrale_Anlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tunnel_Zentrale_Anlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tunnel_Zentrale_Anlagen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tunnel_Zentrale_Anlagen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tunnel_Zentrale_Anlagen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tunnel_Zentrale_Anlagen( const Objektart& oa, const Version& version );

// Bauwerk_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerk_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerk_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerk_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Bauwerk_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Bauwerk_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bauwerk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerk_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerk_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerk_abstrakt( const Objektart& oa, const Version& version );

// Teilbauwerk_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilbauwerk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilbauwerk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilbauwerk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilbauwerk_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilbauwerk_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilbauwerk_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Teilbauwerk_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Teilbauwerk_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilbauwerk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilbauwerk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilbauwerk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Teilbauwerk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilbauwerk_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilbauwerk_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilbauwerk_abstrakt( const Objektart& oa, const Version& version );

// Bauwerk_Netzzuordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerk_Netzzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerk_Netzzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerk_Netzzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerk_Netzzuordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerk_Netzzuordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerk_Netzzuordnung( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Bauwerk_Netzzuordnung(const Version& vsn);

// Routing

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Routing( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Routing( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Routing( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Routing( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Routing( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Routing( const Objektart& oa, const Version& version );

// Durchfahrtshoehen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Durchfahrtshoehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Durchfahrtshoehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Durchfahrtshoehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Durchfahrtshoehen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Durchfahrtshoehen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Durchfahrtshoehen( const Objektart& oa, const Version& version );

// Info_Strasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Info_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Info_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Info_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Info_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Info_Strasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Info_Strasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Info_Strasse( const Objektart& oa, const Version& version );

// Bauwerk_Verkehrsstaerke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerk_Verkehrsstaerke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerk_Verkehrsstaerke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerk_Verkehrsstaerke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerk_Verkehrsstaerke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerk_Verkehrsstaerke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerk_Verkehrsstaerke( const Objektart& oa, const Version& version );

// gegenw_dokum_Schaden

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_gegenw_dokum_Schaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_gegenw_dokum_Schaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_gegenw_dokum_Schaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_gegenw_dokum_Schaden( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_gegenw_dokum_Schaden( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_gegenw_dokum_Schaden( const Objektart& oa, const Version& version );

// gegenw_dokum_Bauwerkszustand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_gegenw_dokum_Bauwerkszustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_gegenw_dokum_Bauwerkszustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_gegenw_dokum_Bauwerkszustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_gegenw_dokum_Bauwerkszustand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_gegenw_dokum_Bauwerkszustand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_gegenw_dokum_Bauwerkszustand( const Objektart& oa, const Version& version );

// Schaden_abgeschl_Prfg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schaden_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schaden_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schaden_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schaden_abgeschl_Prfg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schaden_abgeschl_Prfg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schaden_abgeschl_Prfg( const Objektart& oa, const Version& version );

// abgeschlossene_Pruefung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_abgeschlossene_Pruefung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_abgeschlossene_Pruefung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_abgeschlossene_Pruefung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_abgeschlossene_Pruefung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_abgeschlossene_Pruefung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_abgeschlossene_Pruefung( const Objektart& oa, const Version& version );

// gegenw_dokum_Empfehlung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_gegenw_dokum_Empfehlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_gegenw_dokum_Empfehlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_gegenw_dokum_Empfehlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_gegenw_dokum_Empfehlung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_gegenw_dokum_Empfehlung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_gegenw_dokum_Empfehlung( const Objektart& oa, const Version& version );

// Empfehlung_abgeschl_Prfg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Empfehlung_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Empfehlung_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Empfehlung_abgeschl_Prfg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Empfehlung_abgeschl_Prfg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Empfehlung_abgeschl_Prfg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Empfehlung_abgeschl_Prfg( const Objektart& oa, const Version& version );

// Fahrbahnuebergang

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrbahnuebergang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrbahnuebergang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrbahnuebergang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrbahnuebergang( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrbahnuebergang( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrbahnuebergang( const Objektart& oa, const Version& version );

// Baustoff_Bauwerk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baustoff_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baustoff_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baustoff_Bauwerk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baustoff_Bauwerk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baustoff_Bauwerk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baustoff_Bauwerk( const Objektart& oa, const Version& version );

// Betonersatzsystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betonersatzsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betonersatzsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betonersatzsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betonersatzsystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betonersatzsystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betonersatzsystem( const Objektart& oa, const Version& version );

// Oberflaechenschutzsystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Oberflaechenschutzsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Oberflaechenschutzsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Oberflaechenschutzsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Oberflaechenschutzsystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Oberflaechenschutzsystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Oberflaechenschutzsystem( const Objektart& oa, const Version& version );

// Bundesland

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bundesland( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bundesland( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bundesland( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bundesland( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bundesland( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bundesland( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Bundesland(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Regierungsbezirk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Regierungsbezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Regierungsbezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Regierungsbezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Regierungsbezirk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Regierungsbezirk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Regierungsbezirk( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Regierungsbezirk(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Kreis_kreisfreie_Stadt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreis_kreisfreie_Stadt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreis_kreisfreie_Stadt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreis_kreisfreie_Stadt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreis_kreisfreie_Stadt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreis_kreisfreie_Stadt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreis_kreisfreie_Stadt( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Kreis_kreisfreie_Stadt(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Gemeindebezirk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gemeindebezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gemeindebezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gemeindebezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gemeindebezirk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gemeindebezirk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gemeindebezirk( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Gemeindebezirk(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Ortsteil

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ortsteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ortsteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ortsteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ortsteil( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ortsteil( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ortsteil( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Ortsteil(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Staat

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Staat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Staat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Staat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Staat( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Staat( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Staat( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Staat(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Verwaltungsbezirk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verwaltungsbezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verwaltungsbezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verwaltungsbezirk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verwaltungsbezirk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verwaltungsbezirk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verwaltungsbezirk( const Objektart& oa, const Version& version );

// Land_Ministerium

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Land_Ministerium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Land_Ministerium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Land_Ministerium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Land_Ministerium( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Land_Ministerium( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Land_Ministerium( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Land_Ministerium(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Regierungspraesidium_Landesamt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Regierungspraesidium_Landesamt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Regierungspraesidium_Landesamt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Regierungspraesidium_Landesamt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Regierungspraesidium_Landesamt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Regierungspraesidium_Landesamt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Regierungspraesidium_Landesamt( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Regierungspraesidium_Landesamt(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Amt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Amt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Amt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Amt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Amt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Amt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Amt( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Amt(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Meisterei

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Meisterei( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Meisterei( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Meisterei( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Meisterei( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Meisterei( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Meisterei( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Meisterei(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Kreisverwaltung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreisverwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreisverwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreisverwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreisverwaltung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreisverwaltung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreisverwaltung( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Kreisverwaltung(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Gemeindeverwaltung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gemeindeverwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gemeindeverwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gemeindeverwaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gemeindeverwaltung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gemeindeverwaltung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gemeindeverwaltung( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Gemeindeverwaltung(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Strassenbaudienststelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenbaudienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenbaudienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenbaudienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenbaudienststelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenbaudienststelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenbaudienststelle( const Objektart& oa, const Version& version );

// Baulast_Dritter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baulast_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baulast_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baulast_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baulast_Dritter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baulast_Dritter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baulast_Dritter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baulast_Dritter( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Baulast_Dritter(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Baulast_Dritter(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Baulast_Dritter(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Baulast_Dritter(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Baulast_Dritter(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Baulast_Dritter(const Version& vsn, const Text& key, Text& value, const int& nVal);

// sonstige_UI_Partner

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_sonstige_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_sonstige_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_sonstige_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_sonstige_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_sonstige_UI_Partner( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_sonstige_UI_Partner( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_sonstige_UI_Partner( const Objektart& oa, const Version& version );

// ASB_Bezeichnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ASB_Bezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ASB_Bezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ASB_Bezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ASB_Bezeichnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ASB_Bezeichnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ASB_Bezeichnung( const Objektart& oa, const Version& version );

// Kreisart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreisart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreisart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreisart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kreisart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreisart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreisart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreisart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kreisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kreisart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kreisart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kreisart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kreisart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Baulast_Strassenklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baulast_Strassenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baulast_Strassenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baulast_Strassenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baulast_Strassenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baulast_Strassenklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baulast_Strassenklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baulast_Strassenklasse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Baulast_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Baulast_Strassenklasse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Baulast_Strassenklasse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Baulast_Strassenklasse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Baulast_Strassenklasse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gemeinde_Funktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gemeinde_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gemeinde_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gemeinde_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gemeinde_Funktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gemeinde_Funktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gemeinde_Funktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gemeinde_Funktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gemeinde_Funktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gemeinde_Funktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Gemeinde_Funktion(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gemeinde_Funktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gemeinde_Funktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gemeinde_Funktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// UI_Vereinbarung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_UI_Vereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_UI_Vereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_UI_Vereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_UI_Vereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_UI_Vereinbarung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_UI_Vereinbarung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_UI_Vereinbarung( const Objektart& oa, const Version& version );

// UI_Partner

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_UI_Partner( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_UI_Partner( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_UI_Partner( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_UI_Partner( const Objektart& oa, const Version& version );

// Baulast

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baulast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baulast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baulast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baulast( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baulast( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baulast( const Objektart& oa, const Version& version );

// Art_Baulast

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Baulast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Baulast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Baulast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Baulast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Baulast( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Baulast( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Baulast( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Baulast(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Baulast(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Baulast(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Baulast(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Baulast(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Baulasttraeger

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baulasttraeger( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baulasttraeger( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baulasttraeger( const Objektart& oa, const Version& version );

// OD_FS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_OD_FS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_OD_FS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_OD_FS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_OD_FS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_OD_FS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_OD_FS( const Objektart& oa, const Version& version );

// Tab_OD_FS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_OD_FS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_OD_FS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_OD_FS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_OD_FS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_OD_FS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_OD_FS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_OD_FS( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_OD_FS(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_OD_FS(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_OD_FS(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_OD_FS(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_OD_FS(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Widmung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Widmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Widmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Widmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Widmung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Widmung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Widmung( const Objektart& oa, const Version& version );

// Tab_Widmung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Widmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Widmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Widmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Widmung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Widmung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Widmung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Widmung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Widmung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Widmung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Widmung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Widmung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Widmung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Widmung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verwaltungsbezirk_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verwaltungsbezirk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verwaltungsbezirk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verwaltungsbezirk_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verwaltungsbezirk_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verwaltungsbezirk_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verwaltungsbezirk_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Verwaltungsbezirk_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Verwaltungsbezirk_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verwaltungsbezirk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verwaltungsbezirk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verwaltungsbezirk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verwaltungsbezirk_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verwaltungsbezirk_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verwaltungsbezirk_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verwaltungsbezirk_abstrakt( const Objektart& oa, const Version& version );

// Strassenbaudienststelle_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenbaudienststelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenbaudienststelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenbaudienststelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenbaudienststelle_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenbaudienststelle_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenbaudienststelle_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Strassenbaudienststelle_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Strassenbaudienststelle_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenbaudienststelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenbaudienststelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenbaudienststelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenbaudienststelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenbaudienststelle_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenbaudienststelle_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenbaudienststelle_abstrakt( const Objektart& oa, const Version& version );

// Polizeidienststelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Polizeidienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Polizeidienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Polizeidienststelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Polizeidienststelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Polizeidienststelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Polizeidienststelle( const Objektart& oa, const Version& version );

// ASB_Objekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ASB_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ASB_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ASB_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ASB_Objekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ASB_Objekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ASB_Objekt( const Objektart& oa, const Version& version );

// Art_UI_Vereinbarung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_UI_Vereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_UI_Vereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_UI_Vereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_UI_Vereinbarung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_UI_Vereinbarung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_UI_Vereinbarung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_UI_Vereinbarung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_UI_Vereinbarung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_UI_Vereinbarung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_UI_Vereinbarung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_UI_Vereinbarung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_UI_Vereinbarung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_UI_Vereinbarung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Baulasttraeger

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Baulasttraeger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Baulasttraeger( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Baulasttraeger( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Baulasttraeger( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Baulasttraeger(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Baulasttraeger(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Baulasttraeger(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Baulasttraeger(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Baulasttraeger(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Baulasttraeger(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenklasse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Strassenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Strassenklasse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Strassenklasse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Strassenklasse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Strassenklasse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenbezeichnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenbezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenbezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenbezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenbezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenbezeichnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenbezeichnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenbezeichnung( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Strassenbezeichnung(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Strasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strasse( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Strasse(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Verlaufskennzeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verlaufskennzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verlaufskennzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verlaufskennzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verlaufskennzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verlaufskennzeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verlaufskennzeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verlaufskennzeichen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verlaufskennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verlaufskennzeichen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Verlaufskennzeichen(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verlaufskennzeichen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verlaufskennzeichen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verlaufskennzeichen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strasse_Netzknoten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strasse_Netzknoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strasse_Netzknoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strasse_Netzknoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strasse_Netzknoten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strasse_Netzknoten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strasse_Netzknoten( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Strasse_Netzknoten(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Knotenart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Knotenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Knotenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Knotenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Knotenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Knotenart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Knotenart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Knotenart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Knotenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Knotenart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Knotenart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Knotenart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Knotenart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Knotenart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Knotenpunktsform

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Knotenpunktsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Knotenpunktsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Knotenpunktsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Knotenpunktsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Knotenpunktsform( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Knotenpunktsform( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Knotenpunktsform( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Knotenpunktsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Knotenpunktsform(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Knotenpunktsform(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Knotenpunktsform(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Knotenpunktsform(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Knotenpunktsform(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Knotenpunktsystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Knotenpunktsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Knotenpunktsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Knotenpunktsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Knotenpunktsystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Knotenpunktsystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Knotenpunktsystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Knotenpunktsystem( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Knotenpunktsystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Knotenpunktsystem(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Knotenpunktsystem(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Knotenpunktsystem(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Knotenpunktsystem(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Knotenpunktsystem(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Netzknoten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzknoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzknoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzknoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzknoten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzknoten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzknoten( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Netzknoten(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// BAB_Knotennummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_BAB_Knotennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_BAB_Knotennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_BAB_Knotennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_BAB_Knotennummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_BAB_Knotennummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_BAB_Knotennummer( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_BAB_Knotennummer(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Stadium

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Stadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Stadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Stadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Stadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Stadium( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Stadium( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Stadium( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Stadium(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Stadium(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Stadium(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Stadium(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Stadium(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Abschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abschnitt( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Abschnitt(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Ast

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ast( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ast( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ast( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Ast(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Abschnitt_oder_Ast

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abschnitt_oder_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abschnitt_oder_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abschnitt_oder_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abschnitt_oder_Ast( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abschnitt_oder_Ast( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abschnitt_oder_Ast( const Objektart& oa, const Version& version );

// Verkehrliche_Verknuepfung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrliche_Verknuepfung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrliche_Verknuepfung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrliche_Verknuepfung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrliche_Verknuepfung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrliche_Verknuepfung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrliche_Verknuepfung( const Objektart& oa, const Version& version );

// Nullpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nullpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nullpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nullpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nullpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nullpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nullpunkt( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Nullpunkt(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Strassenpunkt_TA

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenpunkt_TA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenpunkt_TA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenpunkt_TA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenpunkt_TA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenpunkt_TA( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenpunkt_TA( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenpunkt_TA( const Objektart& oa, const Version& version );

// Strassenpunkt_PO

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenpunkt_PO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenpunkt_PO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenpunkt_PO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenpunkt_PO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenpunkt_PO( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenpunkt_PO( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenpunkt_PO( const Objektart& oa, const Version& version );

// Nullpunktsort

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nullpunktsort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nullpunktsort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nullpunktsort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nullpunktsort( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nullpunktsort( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nullpunktsort( const Objektart& oa, const Version& version );

// Strassenpunkt_PoB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenpunkt_PoB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenpunkt_PoB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenpunkt_PoB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenpunkt_PoB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenpunkt_PoB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenpunkt_PoB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenpunkt_PoB( const Objektart& oa, const Version& version );

// Strassenpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenpunkt( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Strassenpunkt(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// GDF_Verbindungspunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GDF_Verbindungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GDF_Verbindungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GDF_Verbindungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GDF_Verbindungspunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GDF_Verbindungspunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GDF_Verbindungspunkt( const Objektart& oa, const Version& version );

// Punktobjekt_stat

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktobjekt_stat( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktobjekt_stat( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktobjekt_stat( const Objektart& oa, const Version& version );

// Betriebskilometer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betriebskilometer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betriebskilometer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betriebskilometer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betriebskilometer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betriebskilometer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betriebskilometer( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Betriebskilometer(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Kilometrierung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kilometrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kilometrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kilometrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kilometrierung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kilometrierung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kilometrierung( const Objektart& oa, const Version& version );

// Punktobjekt_hist

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktobjekt_hist( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktobjekt_hist( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktobjekt_hist( const Objektart& oa, const Version& version );

// Punktobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktobjekt( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Punktobjekt(const Version& vsn);

// Punktobjekt_o_Bereichsobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktobjekt_o_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktobjekt_o_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktobjekt_o_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktobjekt_o_Bereichsobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktobjekt_o_Bereichsobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktobjekt_o_Bereichsobjekt( const Objektart& oa, const Version& version );

// Teilabschnitt_NB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilabschnitt_NB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilabschnitt_NB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilabschnitt_NB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Teilabschnitt_NB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilabschnitt_NB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilabschnitt_NB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilabschnitt_NB( const Objektart& oa, const Version& version );

// Netzbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzbereich( const Objektart& oa, const Version& version );

// Strecke_SO

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strecke_SO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strecke_SO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strecke_SO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strecke_SO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strecke_SO( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strecke_SO( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strecke_SO( const Objektart& oa, const Version& version );

// Strecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strecke( const Objektart& oa, const Version& version );

// Netzbereichskomponente

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzbereichskomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzbereichskomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzbereichskomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzbereichskomponente( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzbereichskomponente( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzbereichskomponente( const Objektart& oa, const Version& version );

// Bereichsobjekt_stat

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bereichsobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bereichsobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bereichsobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bereichsobjekt_stat( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bereichsobjekt_stat( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bereichsobjekt_stat( const Objektart& oa, const Version& version );

// Teilnetz_ASB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilnetz_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilnetz_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilnetz_ASB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilnetz_ASB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilnetz_ASB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilnetz_ASB( const Objektart& oa, const Version& version );

// Bereichsobjekt_hist

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bereichsobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bereichsobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bereichsobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bereichsobjekt_hist( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bereichsobjekt_hist( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bereichsobjekt_hist( const Objektart& oa, const Version& version );

// Bereichsobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bereichsobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bereichsobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bereichsobjekt( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Bereichsobjekt(const Version& vsn);

// Teilabschnitt_SO

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilabschnitt_SO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilabschnitt_SO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilabschnitt_SO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Teilabschnitt_SO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilabschnitt_SO( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilabschnitt_SO( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilabschnitt_SO( const Objektart& oa, const Version& version );

// Teilabschnitt_Str

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilabschnitt_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilabschnitt_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilabschnitt_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Teilabschnitt_Str( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilabschnitt_Str( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilabschnitt_Str( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilabschnitt_Str( const Objektart& oa, const Version& version );

// Teilabschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Teilabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilabschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilabschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilabschnitt( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Teilabschnitt(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Strassenelement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenelement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenelement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenelement( const Objektart& oa, const Version& version );

// verallgemeinerte_Strecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verallgemeinerte_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verallgemeinerte_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verallgemeinerte_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verallgemeinerte_Strecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verallgemeinerte_Strecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verallgemeinerte_Strecke( const Objektart& oa, const Version& version );

// Entwurfselement_Kreisbogen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwurfselement_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwurfselement_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwurfselement_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwurfselement_Kreisbogen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwurfselement_Kreisbogen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwurfselement_Kreisbogen( const Objektart& oa, const Version& version );

// Entwurfselement_Klothoide

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwurfselement_Klothoide( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwurfselement_Klothoide( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwurfselement_Klothoide( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwurfselement_Klothoide( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwurfselement_Klothoide( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwurfselement_Klothoide( const Objektart& oa, const Version& version );

// Entwurfselement_Gerade

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwurfselement_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwurfselement_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwurfselement_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwurfselement_Gerade( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwurfselement_Gerade( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwurfselement_Gerade( const Objektart& oa, const Version& version );

// Entwurfselement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwurfselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwurfselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwurfselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwurfselement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwurfselement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwurfselement( const Objektart& oa, const Version& version );

// Streckenobjekt_stat

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Streckenobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Streckenobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Streckenobjekt_stat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Streckenobjekt_stat( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Streckenobjekt_stat( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Streckenobjekt_stat( const Objektart& oa, const Version& version );

// Block

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Block( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Block( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Block( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Block( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Block( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Block( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Block(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Strassenelement_auf_Abschnitt_oder_Ast

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenelement_auf_Abschnitt_oder_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenelement_auf_Abschnitt_oder_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenelement_auf_Abschnitt_oder_Ast( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenelement_auf_Abschnitt_oder_Ast( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenelement_auf_Abschnitt_oder_Ast( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenelement_auf_Abschnitt_oder_Ast( const Objektart& oa, const Version& version );

// Streckenobjekt_hist

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Streckenobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Streckenobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Streckenobjekt_hist( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Streckenobjekt_hist( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Streckenobjekt_hist( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Streckenobjekt_hist( const Objektart& oa, const Version& version );

// Streckenobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Streckenobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Streckenobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Streckenobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Streckenobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Streckenobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Streckenobjekt( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Streckenobjekt(const Version& vsn);

// Teilnetz

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilnetz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilnetz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilnetz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilnetz( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilnetz( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilnetz( const Objektart& oa, const Version& version );

// Route

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Route( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Route( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Route( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Route( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Route( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Route( const Objektart& oa, const Version& version );

// Teilnetzkomponente

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilnetzkomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilnetzkomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilnetzkomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilnetzkomponente( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilnetzkomponente( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilnetzkomponente( const Objektart& oa, const Version& version );

// Routenkomponente

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Routenkomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Routenkomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Routenkomponente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Routenkomponente( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Routenkomponente( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Routenkomponente( const Objektart& oa, const Version& version );

// GDF_Verbindungselement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GDF_Verbindungselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GDF_Verbindungselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GDF_Verbindungselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GDF_Verbindungselement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GDF_Verbindungselement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GDF_Verbindungselement( const Objektart& oa, const Version& version );

// verallgemeinerter_Nullpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verallgemeinerter_Nullpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verallgemeinerter_Nullpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verallgemeinerter_Nullpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verallgemeinerter_Nullpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verallgemeinerter_Nullpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verallgemeinerter_Nullpunkt( const Objektart& oa, const Version& version );

// Strasse_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strasse_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strasse_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strasse_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strasse_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strasse_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strasse_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Strasse_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Strasse_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strasse_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strasse_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strasse_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strasse_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strasse_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strasse_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strasse_abstrakt( const Objektart& oa, const Version& version );

// Netzknoten_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzknoten_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzknoten_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzknoten_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzknoten_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzknoten_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzknoten_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Netzknoten_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Netzknoten_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Netzknoten_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Netzknoten_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Netzknoten_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Netzknoten_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Netzknoten_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Netzknoten_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Netzknoten_abstrakt( const Objektart& oa, const Version& version );

// Abschnitt_oder_Ast_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abschnitt_oder_Ast_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abschnitt_oder_Ast_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abschnitt_oder_Ast_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abschnitt_oder_Ast_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abschnitt_oder_Ast_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abschnitt_oder_Ast_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Abschnitt_oder_Ast_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Abschnitt_oder_Ast_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abschnitt_oder_Ast_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abschnitt_oder_Ast_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abschnitt_oder_Ast_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Abschnitt_oder_Ast_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abschnitt_oder_Ast_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abschnitt_oder_Ast_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abschnitt_oder_Ast_abstrakt( const Objektart& oa, const Version& version );

// Nullpunkt_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nullpunkt_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nullpunkt_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nullpunkt_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nullpunkt_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nullpunkt_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nullpunkt_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Nullpunkt_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Nullpunkt_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nullpunkt_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nullpunkt_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nullpunkt_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Nullpunkt_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nullpunkt_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nullpunkt_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nullpunkt_abstrakt( const Objektart& oa, const Version& version );

// Bezugsrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bezugsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bezugsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bezugsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bezugsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bezugsrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bezugsrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bezugsrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bezugsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bezugsrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bezugsrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bezugsrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bezugsrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// TK25Blatt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_TK25Blatt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_TK25Blatt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_TK25Blatt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_TK25Blatt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_TK25Blatt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_TK25Blatt( const Objektart& oa, const Version& version );

// Nummernintervall

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nummernintervall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nummernintervall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nummernintervall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nummernintervall( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nummernintervall( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nummernintervall( const Objektart& oa, const Version& version );

// Tab_Stadium

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Stadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Stadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Stadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Stadium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Stadium( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Stadium( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Stadium( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Stadium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Stadium(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Stadium(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Stadium(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Stadium(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Herkunft_Laenge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Herkunft_Laenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Herkunft_Laenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Herkunft_Laenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Herkunft_Laenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Herkunft_Laenge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Herkunft_Laenge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Herkunft_Laenge( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Herkunft_Laenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Herkunft_Laenge(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Herkunft_Laenge(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Herkunft_Laenge(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Herkunft_Laenge(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Herkunft_Laenge(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zweig_der_Trennung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zweig_der_Trennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zweig_der_Trennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zweig_der_Trennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zweig_der_Trennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zweig_der_Trennung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zweig_der_Trennung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zweig_der_Trennung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zweig_der_Trennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zweig_der_Trennung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zweig_der_Trennung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zweig_der_Trennung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zweig_der_Trennung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zweig_der_Trennung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_des_Astes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_des_Astes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_des_Astes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_des_Astes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_des_Astes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_des_Astes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_des_Astes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_des_Astes( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_des_Astes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_des_Astes(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Funktion_des_Astes(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_des_Astes(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_des_Astes(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_des_Astes(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Betriebsmerkmal

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betriebsmerkmal( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betriebsmerkmal( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betriebsmerkmal( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Betriebsmerkmal( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betriebsmerkmal( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betriebsmerkmal( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betriebsmerkmal( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Betriebsmerkmal(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Betriebsmerkmal(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Betriebsmerkmal(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Betriebsmerkmal(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Betriebsmerkmal(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Betriebsmerkmal(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Nullpunktart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nullpunktart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nullpunktart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nullpunktart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Nullpunktart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nullpunktart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nullpunktart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nullpunktart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Nullpunktart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Nullpunktart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Nullpunktart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Nullpunktart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Nullpunktart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Nullpunktart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Teilnetzklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilnetzklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilnetzklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilnetzklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Teilnetzklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilnetzklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilnetzklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilnetzklasse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Teilnetzklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Teilnetzklasse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Teilnetzklasse(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Teilnetzklasse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Teilnetzklasse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Teilnetzklasse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Winterdienstprioritaet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Winterdienstprioritaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Winterdienstprioritaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Winterdienstprioritaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Winterdienstprioritaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Winterdienstprioritaet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Winterdienstprioritaet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Winterdienstprioritaet( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Winterdienstprioritaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Winterdienstprioritaet(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Winterdienstprioritaet(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Winterdienstprioritaet(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Winterdienstprioritaet(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Winterdienstprioritaet(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrsrichtung_SE

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsrichtung_SE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsrichtung_SE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsrichtung_SE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verkehrsrichtung_SE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsrichtung_SE( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsrichtung_SE( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsrichtung_SE( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verkehrsrichtung_SE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verkehrsrichtung_SE(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verkehrsrichtung_SE(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verkehrsrichtung_SE(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verkehrsrichtung_SE(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenelement_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenelement_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenelement_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenelement_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenelement_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenelement_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenelement_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Strassenelement_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Strassenelement_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenelement_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenelement_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenelement_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenelement_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenelement_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenelement_abstrakt( const Objektart& oa, const Version& version );

// Verbindungspunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verbindungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verbindungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verbindungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verbindungspunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verbindungspunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verbindungspunkt( const Objektart& oa, const Version& version );

// Verbindungspunkt_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verbindungspunkt_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verbindungspunkt_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verbindungspunkt_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verbindungspunkt_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verbindungspunkt_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verbindungspunkt_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Verbindungspunkt_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Verbindungspunkt_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verbindungspunkt_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verbindungspunkt_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verbindungspunkt_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verbindungspunkt_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verbindungspunkt_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verbindungspunkt_abstrakt( const Objektart& oa, const Version& version );

// Verbotene_Fahrbeziehung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verbotene_Fahrbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verbotene_Fahrbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verbotene_Fahrbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verbotene_Fahrbeziehung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verbotene_Fahrbeziehung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verbotene_Fahrbeziehung( const Objektart& oa, const Version& version );

// manuelle_Zaehlstelle_AVZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_manuelle_Zaehlstelle_AVZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_manuelle_Zaehlstelle_AVZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_manuelle_Zaehlstelle_AVZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_manuelle_Zaehlstelle_AVZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_manuelle_Zaehlstelle_AVZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_manuelle_Zaehlstelle_AVZ( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_manuelle_Zaehlstelle_AVZ(const Version& vsn);

// Streckenbild

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Streckenbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Streckenbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Streckenbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Streckenbild( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Streckenbild( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Streckenbild( const Objektart& oa, const Version& version );

// Art_Kamera_Streckenbild

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Kamera_Streckenbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Kamera_Streckenbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Kamera_Streckenbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Kamera_Streckenbild( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Kamera_Streckenbild( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Kamera_Streckenbild( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Kamera_Streckenbild( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Kamera_Streckenbild(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Kamera_Streckenbild(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Kamera_Streckenbild(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Kamera_Streckenbild(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Kamera_Streckenbild(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bestandsplan

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bestandsplan( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bestandsplan( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bestandsplan( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bestandsplan( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bestandsplan( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bestandsplan( const Objektart& oa, const Version& version );

// Art_DGM

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_DGM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_DGM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_DGM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_DGM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_DGM( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_DGM( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_DGM( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_DGM(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_DGM(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_DGM(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_DGM(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_DGM(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_DGM(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Blattschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Blattschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Blattschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Blattschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Blattschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Blattschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Blattschnitt( const Objektart& oa, const Version& version );

// Art_Blattschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Blattschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Blattschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Blattschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Blattschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Blattschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Blattschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Blattschnitt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Blattschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Blattschnitt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Blattschnitt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Blattschnitt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Blattschnitt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kehle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kehle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kehle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kehle( const Objektart& oa, const Version& version );

// Isolinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Isolinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Isolinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Isolinie( const Objektart& oa, const Version& version );

// Art_Isolinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Isolinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Isolinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Isolinie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Isolinie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Isolinie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Isolinie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Isolinie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Einheit_Isolinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einheit_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einheit_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einheit_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Einheit_Isolinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einheit_Isolinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einheit_Isolinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einheit_Isolinie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Einheit_Isolinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Einheit_Isolinie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Einheit_Isolinie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Einheit_Isolinie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Einheit_Isolinie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lpf_Objekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Objekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Objekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Objekt( const Objektart& oa, const Version& version );

// Biotopkomplex

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Biotopkomplex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Biotopkomplex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Biotopkomplex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Biotopkomplex( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Biotopkomplex( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Biotopkomplex( const Objektart& oa, const Version& version );

// Biotop

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Biotop( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Biotop( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Biotop( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Biotop( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Biotop( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Biotop( const Objektart& oa, const Version& version );

// FFH_Lebensraumtyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_FFH_Lebensraumtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_FFH_Lebensraumtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_FFH_Lebensraumtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_FFH_Lebensraumtyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_FFH_Lebensraumtyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_FFH_Lebensraumtyp( const Objektart& oa, const Version& version );

// Lpf_Superobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Superobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Superobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Superobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Superobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Superobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Superobjekt( const Objektart& oa, const Version& version );

// STLK_Bezugsobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_STLK_Bezugsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_STLK_Bezugsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_STLK_Bezugsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_STLK_Bezugsobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_STLK_Bezugsobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_STLK_Bezugsobjekt( const Objektart& oa, const Version& version );

// Leistungsbeschreibung_STLK

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Leistungsbeschreibung_STLK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Leistungsbeschreibung_STLK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Leistungsbeschreibung_STLK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Leistungsbeschreibung_STLK( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Leistungsbeschreibung_STLK( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Leistungsbeschreibung_STLK( const Objektart& oa, const Version& version );

// Folgetext_STLK

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Folgetext_STLK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Folgetext_STLK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Folgetext_STLK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Folgetext_STLK( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Folgetext_STLK( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Folgetext_STLK( const Objektart& oa, const Version& version );

// Lpf_Teilelement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Teilelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Teilelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Teilelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Teilelement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Teilelement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Teilelement( const Objektart& oa, const Version& version );

// Habitat

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Habitat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Habitat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Habitat( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Habitat( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Habitat( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Habitat( const Objektart& oa, const Version& version );

// Funktionsbeziehung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktionsbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktionsbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktionsbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktionsbeziehung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktionsbeziehung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktionsbeziehung( const Objektart& oa, const Version& version );

// Boden

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Boden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Boden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Boden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Boden( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Boden( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Boden( const Objektart& oa, const Version& version );

// Landschaftsbildelement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Landschaftsbildelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Landschaftsbildelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Landschaftsbildelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Landschaftsbildelement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Landschaftsbildelement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Landschaftsbildelement( const Objektart& oa, const Version& version );

// Wert_Funktionselement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wert_Funktionselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wert_Funktionselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wert_Funktionselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wert_Funktionselement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wert_Funktionselement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wert_Funktionselement( const Objektart& oa, const Version& version );

// Biotoptyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Biotoptyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Biotoptyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Biotoptyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Biotoptyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Biotoptyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Biotoptyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Biotoptyp( const Objektart& oa, const Version& version );

// Tab_Biotoptyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Biotoptyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Biotoptyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Biotoptyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Biotoptyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Biotoptyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Biotoptyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Biotoptyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Biotoptyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Biotoptyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Biotoptyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Biotoptyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Biotoptyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Biotopentwicklung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Biotopentwicklung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Biotopentwicklung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Biotopentwicklung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Biotopentwicklung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Biotopentwicklung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Biotopentwicklung( const Objektart& oa, const Version& version );

// Pflanzenart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pflanzenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pflanzenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pflanzenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pflanzenart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pflanzenart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pflanzenart( const Objektart& oa, const Version& version );

// biologische_Art

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_biologische_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_biologische_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_biologische_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_biologische_Art( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_biologische_Art( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_biologische_Art( const Objektart& oa, const Version& version );

// Fundstelle_biologische_Art

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fundstelle_biologische_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fundstelle_biologische_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fundstelle_biologische_Art( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fundstelle_biologische_Art( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fundstelle_biologische_Art( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fundstelle_biologische_Art( const Objektart& oa, const Version& version );

// Schutzstatus

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzstatus( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzstatus( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzstatus( const Objektart& oa, const Version& version );

// Tab_Schutzstatus

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Schutzstatus( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Schutzstatus( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Schutzstatus( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Schutzstatus(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Schutzstatus(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Schutzstatus(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Schutzstatus(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Quelle_Schutzstatus

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Quelle_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Quelle_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Quelle_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Quelle_Schutzstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Quelle_Schutzstatus( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Quelle_Schutzstatus( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Quelle_Schutzstatus( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Quelle_Schutzstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Quelle_Schutzstatus(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Quelle_Schutzstatus(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Quelle_Schutzstatus(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Quelle_Schutzstatus(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Artengruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Artengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Artengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Artengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Artengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Artengruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Artengruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Artengruppe( const Objektart& oa, const Version& version );

// Tab_Artengruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Artengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Artengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Artengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Artengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Artengruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Artengruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Artengruppe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Artengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Artengruppe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Artengruppe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Artengruppe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Artengruppe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tab_FFH_Lebensraumtyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_FFH_Lebensraumtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_FFH_Lebensraumtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_FFH_Lebensraumtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_FFH_Lebensraumtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_FFH_Lebensraumtyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_FFH_Lebensraumtyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_FFH_Lebensraumtyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_FFH_Lebensraumtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_FFH_Lebensraumtyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_FFH_Lebensraumtyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_FFH_Lebensraumtyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_FFH_Lebensraumtyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Funktionsbeziehung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Funktionsbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Funktionsbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Funktionsbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Funktionsbeziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Funktionsbeziehung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Funktionsbeziehung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Funktionsbeziehung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Funktionsbeziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Funktionsbeziehung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Funktionsbeziehung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Funktionsbeziehung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Funktionsbeziehung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bodenart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bodenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bodenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bodenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bodenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bodenart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bodenart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bodenart( const Objektart& oa, const Version& version );

// Tab_Bodenart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Bodenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Bodenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Bodenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Bodenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Bodenart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Bodenart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Bodenart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Bodenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Bodenart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Bodenart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Bodenart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Bodenart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grundwasserfliessrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundwasserfliessrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundwasserfliessrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundwasserfliessrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundwasserfliessrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundwasserfliessrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundwasserfliessrichtung( const Objektart& oa, const Version& version );

// Kalt_Frischluftbahn

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kalt_Frischluftbahn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kalt_Frischluftbahn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kalt_Frischluftbahn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kalt_Frischluftbahn( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kalt_Frischluftbahn( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kalt_Frischluftbahn( const Objektart& oa, const Version& version );

// Art_Landschaftsbildelement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Landschaftsbildelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Landschaftsbildelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Landschaftsbildelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Landschaftsbildelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Landschaftsbildelement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Landschaftsbildelement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Landschaftsbildelement( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Landschaftsbildelement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Landschaftsbildelement(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Landschaftsbildelement(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Landschaftsbildelement(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Landschaftsbildelement(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Lpf_Objekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Lpf_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Lpf_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Lpf_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Lpf_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Lpf_Objekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Lpf_Objekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Lpf_Objekt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Lpf_Objekt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Lpf_Objekt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Lpf_Objekt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Lpf_Objekt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Lpf_Objekt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Konflikt_LBP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Konflikt_LBP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Konflikt_LBP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Konflikt_LBP( const Objektart& oa, const Version& version );

// Erheblichkeit_Konflikt_LBP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erheblichkeit_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erheblichkeit_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erheblichkeit_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Erheblichkeit_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erheblichkeit_Konflikt_LBP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erheblichkeit_Konflikt_LBP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erheblichkeit_Konflikt_LBP( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Erheblichkeit_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Erheblichkeit_Konflikt_LBP(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Erheblichkeit_Konflikt_LBP(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Erheblichkeit_Konflikt_LBP(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Erheblichkeit_Konflikt_LBP(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Konflikt_primaer_betr_Fkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Konflikt_primaer_betr_Fkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Konflikt_primaer_betr_Fkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Konflikt_primaer_betr_Fkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Konflikt_primaer_betr_Fkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Konflikt_primaer_betr_Fkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Konflikt_primaer_betr_Fkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Konflikt_primaer_betr_Fkt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Konflikt_primaer_betr_Fkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Konflikt_primaer_betr_Fkt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Konflikt_primaer_betr_Fkt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Konflikt_primaer_betr_Fkt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Konflikt_primaer_betr_Fkt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Konfliktbestandteil

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Konfliktbestandteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Konfliktbestandteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Konfliktbestandteil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Konfliktbestandteil( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Konfliktbestandteil( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Konfliktbestandteil( const Objektart& oa, const Version& version );

// Art_Konflikt_LBP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Konflikt_LBP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Konflikt_LBP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Konflikt_LBP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Konflikt_LBP( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Konflikt_LBP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Konflikt_LBP(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Konflikt_LBP(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Konflikt_LBP(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Konflikt_LBP(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Wert_Funktionselement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Wert_Funktionselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Wert_Funktionselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Wert_Funktionselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Wert_Funktionselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Wert_Funktionselement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Wert_Funktionselement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Wert_Funktionselement( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Wert_Funktionselement(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Wert_Funktionselement(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Wert_Funktionselement(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Wert_Funktionselement(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Wert_Funktionselement(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wirkzone

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wirkzone( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wirkzone( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wirkzone( const Objektart& oa, const Version& version );

// Art_Wirkzone

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Wirkzone( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Wirkzone( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Wirkzone( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Wirkzone(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Wirkzone(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Wirkzone(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Wirkzone(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Einheit_Wirkzone

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einheit_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einheit_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einheit_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Einheit_Wirkzone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einheit_Wirkzone( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einheit_Wirkzone( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einheit_Wirkzone( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Einheit_Wirkzone(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Einheit_Wirkzone(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Einheit_Wirkzone(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Einheit_Wirkzone(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Einheit_Wirkzone(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Planungsraum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Planungsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Planungsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Planungsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Planungsraum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Planungsraum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Planungsraum( const Objektart& oa, const Version& version );

// Art_Planungsraum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Planungsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Planungsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Planungsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Planungsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Planungsraum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Planungsraum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Planungsraum( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Planungsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Planungsraum(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Planungsraum(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Planungsraum(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Planungsraum(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bezugsraum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bezugsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bezugsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bezugsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bezugsraum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bezugsraum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bezugsraum( const Objektart& oa, const Version& version );

// Art_Bezugsraum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Bezugsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Bezugsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Bezugsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Bezugsraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Bezugsraum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Bezugsraum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Bezugsraum( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Bezugsraum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Bezugsraum(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Bezugsraum(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Bezugsraum(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Bezugsraum(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lpf_Projekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Projekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Projekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Projekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Projekt( const Objektart& oa, const Version& version );

// Baukilometerbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baukilometerbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baukilometerbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baukilometerbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baukilometerbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baukilometerbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baukilometerbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baukilometerbereich( const Objektart& oa, const Version& version );

// Lpf_Einzelmassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Einzelmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Einzelmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Einzelmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Einzelmassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Einzelmassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Einzelmassnahme( const Objektart& oa, const Version& version );

// Lpf_Einzelkomplexmassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Einzelkomplexmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Einzelkomplexmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Einzelkomplexmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Einzelkomplexmassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Einzelkomplexmassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Einzelkomplexmassnahme( const Objektart& oa, const Version& version );

// Lpf_Massnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Massnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Massnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Massnahme( const Objektart& oa, const Version& version );

// Lpf_Massnahme_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Massnahme_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Massnahme_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Massnahme_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Massnahme_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Massnahme_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Massnahme_Symbol( const Objektart& oa, const Version& version );

// Lpf_Massnahme_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Massnahme_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Massnahme_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Massnahme_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Massnahme_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Massnahme_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Massnahme_abstrakt( const Objektart& oa, const Version& version );

// Lpf_Massnahmetyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Massnahmetyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Massnahmetyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Massnahmetyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lpf_Massnahmetyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Massnahmetyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Massnahmetyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Massnahmetyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lpf_Massnahmetyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lpf_Massnahmetyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lpf_Massnahmetyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lpf_Massnahmetyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lpf_Massnahmetyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lpf_Zusatzindex

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Zusatzindex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Zusatzindex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Zusatzindex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lpf_Zusatzindex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Zusatzindex( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Zusatzindex( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Zusatzindex( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lpf_Zusatzindex(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lpf_Zusatzindex(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lpf_Zusatzindex(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lpf_Zusatzindex(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lpf_Zusatzindex(const Version& vsn, const Text& key, Text& value, const int& nVal);

// zeitliche_Zuordnung_Massn

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zeitliche_Zuordnung_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zeitliche_Zuordnung_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zeitliche_Zuordnung_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_zeitliche_Zuordnung_Massn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zeitliche_Zuordnung_Massn( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zeitliche_Zuordnung_Massn( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zeitliche_Zuordnung_Massn( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_zeitliche_Zuordnung_Massn(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_zeitliche_Zuordnung_Massn(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_zeitliche_Zuordnung_Massn(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_zeitliche_Zuordnung_Massn(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_zeitliche_Zuordnung_Massn(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Einheit_Gesamtumfang

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einheit_Gesamtumfang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einheit_Gesamtumfang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einheit_Gesamtumfang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Einheit_Gesamtumfang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einheit_Gesamtumfang( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einheit_Gesamtumfang( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einheit_Gesamtumfang( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Einheit_Gesamtumfang(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Einheit_Gesamtumfang(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Einheit_Gesamtumfang(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Einheit_Gesamtumfang(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Einheit_Gesamtumfang(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lpf_Zuordnung_Fachbereiche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Zuordnung_Fachbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Zuordnung_Fachbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Zuordnung_Fachbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lpf_Zuordnung_Fachbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Zuordnung_Fachbereiche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Zuordnung_Fachbereiche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Zuordnung_Fachbereiche( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lpf_Zuordnung_Fachbereiche(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lpf_Zuordnung_Fachbereiche(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lpf_Zuordnung_Fachbereiche(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lpf_Zuordnung_Fachbereiche(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lpf_Zuordnung_Fachbereiche(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lpf_Ausarbeitung_erforderl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Ausarbeitung_erforderl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Ausarbeitung_erforderl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Ausarbeitung_erforderl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lpf_Ausarbeitung_erforderl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Ausarbeitung_erforderl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Ausarbeitung_erforderl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Ausarbeitung_erforderl( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lpf_Ausarbeitung_erforderl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lpf_Ausarbeitung_erforderl(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lpf_Ausarbeitung_erforderl(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lpf_Ausarbeitung_erforderl(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lpf_Ausarbeitung_erforderl(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lpf_Darstellung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Darstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Darstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Darstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lpf_Darstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Darstellung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Darstellung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Darstellung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lpf_Darstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lpf_Darstellung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lpf_Darstellung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lpf_Darstellung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lpf_Darstellung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lpf_Massnahmenkomplex

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Massnahmenkomplex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Massnahmenkomplex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Massnahmenkomplex( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Massnahmenkomplex( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Massnahmenkomplex( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Massnahmenkomplex( const Objektart& oa, const Version& version );

// Lpf_Massnahmeneinheit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Massnahmeneinheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Massnahmeneinheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Massnahmeneinheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Massnahmeneinheit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Massnahmeneinheit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Massnahmeneinheit( const Objektart& oa, const Version& version );

// Lpf_Massnahmenbegruendung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lpf_Massnahmenbegruendung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lpf_Massnahmenbegruendung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lpf_Massnahmenbegruendung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lpf_Massnahmenbegruendung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lpf_Massnahmenbegruendung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lpf_Massnahmenbegruendung( const Objektart& oa, const Version& version );

// Kompensationsteilmassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kompensationsteilmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kompensationsteilmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kompensationsteilmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kompensationsteilmassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kompensationsteilmassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kompensationsteilmassnahme( const Objektart& oa, const Version& version );

// Baumassnahme_Oekologie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baumassnahme_Oekologie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baumassnahme_Oekologie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baumassnahme_Oekologie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baumassnahme_Oekologie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baumassnahme_Oekologie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baumassnahme_Oekologie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baumassnahme_Oekologie( const Objektart& oa, const Version& version );

// Schutzgebiet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzgebiet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzgebiet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzgebiet( const Objektart& oa, const Version& version );

// Art_Schutzgebiet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Schutzgebiet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Schutzgebiet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Schutzgebiet( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Schutzgebiet(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Schutzgebiet(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Schutzgebiet(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Schutzgebiet(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schutzstatus_Schutzgebiet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzstatus_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzstatus_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzstatus_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schutzstatus_Schutzgebiet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzstatus_Schutzgebiet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzstatus_Schutzgebiet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzstatus_Schutzgebiet( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schutzstatus_Schutzgebiet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schutzstatus_Schutzgebiet(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schutzstatus_Schutzgebiet(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schutzstatus_Schutzgebiet(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schutzstatus_Schutzgebiet(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Baumgattung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baumgattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baumgattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baumgattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baumgattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baumgattung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baumgattung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baumgattung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Baumgattung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Baumgattung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Baumgattung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Baumgattung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Baumgattung(const Version& vsn, const Text& key, Text& value, const int& nVal);
#endif
};
} // Namespace Oklabi

