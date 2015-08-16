/*****************************************************************************
* $Id: SI-Gesamt1.h 28.09.2012 13:56:43 vogelsang $
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
* 13.01.2011  Code für Schema-Sammelmodul 1 erstellt
*
* Version OKSTRA-Express: 2011-01-13, OKSTRA 1.000-1.015
* Version OKSTRA-Klassenbibliothek: 1.1.0
*
*/
namespace Oklabi
{
class Schema1 : public Schema
{
friend class Schema;
OKLABI_SCHEMA_API static bool LocalInit();
OKLABI_SCHEMA_API static bool initialized;
OKLABI_SCHEMA_API static const char* GibExpressVersion();
OKLABI_SCHEMA_API static const char* GibOKLABIReleaseVersion();
#ifdef OKLABI_PLAUSI

// Streckenbeeinflussung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Streckenbeeinflussung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Streckenbeeinflussung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Streckenbeeinflussung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Streckenbeeinflussung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Streckenbeeinflussung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Streckenbeeinflussung( const Objektart& oa, const Version& version );

// Richtungswechselbetrieb

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Richtungswechselbetrieb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Richtungswechselbetrieb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Richtungswechselbetrieb( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Richtungswechselbetrieb( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Richtungswechselbetrieb( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Richtungswechselbetrieb( const Objektart& oa, const Version& version );

// Wechselwegweisung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wechselwegweisung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wechselwegweisung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wechselwegweisung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wechselwegweisung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wechselwegweisung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wechselwegweisung( const Objektart& oa, const Version& version );

// Knotenpunktbeeinflussung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Knotenpunktbeeinflussung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Knotenpunktbeeinflussung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Knotenpunktbeeinflussung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Knotenpunktbeeinflussung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Knotenpunktbeeinflussung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Knotenpunktbeeinflussung( const Objektart& oa, const Version& version );

// dyn_verkehrsreg_Beschilderung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_dyn_verkehrsreg_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_dyn_verkehrsreg_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_dyn_verkehrsreg_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_dyn_verkehrsreg_Beschilderung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_dyn_verkehrsreg_Beschilderung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_dyn_verkehrsreg_Beschilderung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_dyn_verkehrsreg_Beschilderung( const Objektart& oa, const Version& version );

// Kombination_von_Anlagentypen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kombination_von_Anlagentypen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kombination_von_Anlagentypen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kombination_von_Anlagentypen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kombination_von_Anlagentypen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kombination_von_Anlagentypen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kombination_von_Anlagentypen( const Objektart& oa, const Version& version );

// verwaltungstechn_Zuordnung_dyn

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verwaltungstechn_Zuordnung_dyn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verwaltungstechn_Zuordnung_dyn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verwaltungstechn_Zuordnung_dyn( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verwaltungstechn_Zuordnung_dyn( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verwaltungstechn_Zuordnung_dyn( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verwaltungstechn_Zuordnung_dyn( const Objektart& oa, const Version& version );

// Einsatzdauer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einsatzdauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einsatzdauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einsatzdauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einsatzdauer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einsatzdauer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einsatzdauer( const Objektart& oa, const Version& version );

// Art_der_Dauer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Dauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Dauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Dauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Dauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Dauer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Dauer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Dauer( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Dauer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Dauer(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Dauer(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Dauer(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Dauer(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Dauer(const Version& vsn, const Text& key, Text& value, const int& nVal);

// SB_Anlagentyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_SB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_SB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_SB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_SB_Anlagentyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_SB_Anlagentyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_SB_Anlagentyp( const Objektart& oa, const Version& version );

// Tab_SB_Anlagentyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_SB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_SB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_SB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_SB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_SB_Anlagentyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_SB_Anlagentyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_SB_Anlagentyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_SB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_SB_Anlagentyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_SB_Anlagentyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_SB_Anlagentyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_SB_Anlagentyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_SB_Anlagentyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// SB_Anzeigezustaende

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_SB_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_SB_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_SB_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_SB_Anzeigezustaende( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_SB_Anzeigezustaende( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_SB_Anzeigezustaende( const Objektart& oa, const Version& version );

// SB_Wirkungsbereiche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_SB_Wirkungsbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_SB_Wirkungsbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_SB_Wirkungsbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_SB_Wirkungsbereiche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_SB_Wirkungsbereiche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_SB_Wirkungsbereiche( const Objektart& oa, const Version& version );

// Tab_Wirkungsbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Wirkungsbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Wirkungsbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Wirkungsbereich( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Wirkungsbereich(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Wirkungsbereich(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Wirkungsbereich(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Wirkungsbereich(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Wirkungsbereich(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wirkungsbereich_SP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wirkungsbereich_SP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wirkungsbereich_SP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wirkungsbereich_SP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wirkungsbereich_SP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wirkungsbereich_SP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wirkungsbereich_SP( const Objektart& oa, const Version& version );

// WW_Anzeigezustaende

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_WW_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_WW_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_WW_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_WW_Anzeigezustaende( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_WW_Anzeigezustaende( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_WW_Anzeigezustaende( const Objektart& oa, const Version& version );

// WW_Anlagentyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_WW_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_WW_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_WW_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_WW_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_WW_Anlagentyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_WW_Anlagentyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_WW_Anlagentyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_WW_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_WW_Anlagentyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_WW_Anlagentyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_WW_Anlagentyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_WW_Anlagentyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_WW_Anlagentyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// WW_Wirkungsbereiche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_WW_Wirkungsbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_WW_Wirkungsbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_WW_Wirkungsbereiche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_WW_Wirkungsbereiche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_WW_Wirkungsbereiche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_WW_Wirkungsbereiche( const Objektart& oa, const Version& version );

// KB_Anlagentyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_KB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_KB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_KB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_KB_Anlagentyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_KB_Anlagentyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_KB_Anlagentyp( const Objektart& oa, const Version& version );

// Tab_KB_Anlagentyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_KB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_KB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_KB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_KB_Anlagentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_KB_Anlagentyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_KB_Anlagentyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_KB_Anlagentyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_KB_Anlagentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_KB_Anlagentyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_KB_Anlagentyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_KB_Anlagentyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_KB_Anlagentyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_KB_Anlagentyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// KB_Anzeigezustaende

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_KB_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_KB_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_KB_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_KB_Anzeigezustaende( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_KB_Anzeigezustaende( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_KB_Anzeigezustaende( const Objektart& oa, const Version& version );

// KB_Wirkungsbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_KB_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_KB_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_KB_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_KB_Wirkungsbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_KB_Wirkungsbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_KB_Wirkungsbereich( const Objektart& oa, const Version& version );

// Tab_KB_Wirkungsbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_KB_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_KB_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_KB_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_KB_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_KB_Wirkungsbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_KB_Wirkungsbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_KB_Wirkungsbereich( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_KB_Wirkungsbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_KB_Wirkungsbereich(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_KB_Wirkungsbereich(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_KB_Wirkungsbereich(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_KB_Wirkungsbereich(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_KB_Wirkungsbereich(const Version& vsn, const Text& key, Text& value, const int& nVal);

// richtungsbezogener_WB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_richtungsbezogener_WB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_richtungsbezogener_WB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_richtungsbezogener_WB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_richtungsbezogener_WB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_richtungsbezogener_WB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_richtungsbezogener_WB( const Objektart& oa, const Version& version );

// astbezogener_WB

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_astbezogener_WB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_astbezogener_WB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_astbezogener_WB( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_astbezogener_WB( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_astbezogener_WB( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_astbezogener_WB( const Objektart& oa, const Version& version );

// Angaben_zum_Knotenpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zum_Knotenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zum_Knotenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zum_Knotenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zum_Knotenpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zum_Knotenpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zum_Knotenpunkt( const Objektart& oa, const Version& version );

// Betriebsform

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Betriebsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Betriebsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Betriebsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Betriebsform( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Betriebsform( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Betriebsform( const Objektart& oa, const Version& version );

// RW_Anzeigezustaende

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_RW_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_RW_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_RW_Anzeigezustaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_RW_Anzeigezustaende( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_RW_Anzeigezustaende( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_RW_Anzeigezustaende( const Objektart& oa, const Version& version );

// RW_Wirkungsbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_RW_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_RW_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_RW_Wirkungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_RW_Wirkungsbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_RW_Wirkungsbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_RW_Wirkungsbereich( const Objektart& oa, const Version& version );

// Anlagenausstattung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anlagenausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anlagenausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anlagenausstattung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anlagenausstattung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anlagenausstattung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anlagenausstattung( const Objektart& oa, const Version& version );

// Art_der_Stromversorgung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Stromversorgung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Stromversorgung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Stromversorgung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Stromversorgung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Stromversorgung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Stromversorgung( const Objektart& oa, const Version& version );

// Tab_Art_der_Stromversorgung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Art_der_Stromversorgung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Art_der_Stromversorgung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Art_der_Stromversorgung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Art_der_Stromversorgung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Art_der_Stromversorgung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Art_der_Stromversorgung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Art_der_Stromversorgung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Art_der_Stromversorgung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Art_der_Stromversorgung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Art_der_Stromversorgung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Art_der_Stromversorgung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Art_der_Stromversorgung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Art_der_Stromversorgung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Steuerung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Steuerung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Steuerung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Steuerung( const Objektart& oa, const Version& version );

// manuelle_Steuerung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_manuelle_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_manuelle_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_manuelle_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_manuelle_Steuerung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_manuelle_Steuerung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_manuelle_Steuerung( const Objektart& oa, const Version& version );

// Tab_Steuerung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Steuerung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Steuerung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Steuerung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Steuerung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Steuerung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Steuerung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Steuerung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Steuerung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Steuerung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Steuerung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Datenuebertragungssystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datenuebertragungssystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datenuebertragungssystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datenuebertragungssystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datenuebertragungssystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datenuebertragungssystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datenuebertragungssystem( const Objektart& oa, const Version& version );

// Datenuebertragung_SST_UZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datenuebertragung_SST_UZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datenuebertragung_SST_UZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datenuebertragung_SST_UZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Datenuebertragung_SST_UZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datenuebertragung_SST_UZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datenuebertragung_SST_UZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datenuebertragung_SST_UZ( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Datenuebertragung_SST_UZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Datenuebertragung_SST_UZ(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Datenuebertragung_SST_UZ(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Datenuebertragung_SST_UZ(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Datenuebertragung_SST_UZ(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Datenuebertragung_SST_UZ(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Datenuebertragung_UZ_VRZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datenuebertragung_UZ_VRZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datenuebertragung_UZ_VRZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datenuebertragung_UZ_VRZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Datenuebertragung_UZ_VRZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datenuebertragung_UZ_VRZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datenuebertragung_UZ_VRZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datenuebertragung_UZ_VRZ( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Datenuebertragung_UZ_VRZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Datenuebertragung_UZ_VRZ(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Datenuebertragung_UZ_VRZ(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Datenuebertragung_UZ_VRZ(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Datenuebertragung_UZ_VRZ(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Datenuebertragung_UZ_VRZ(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Unterzentrale

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unterzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unterzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unterzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unterzentrale( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unterzentrale( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unterzentrale( const Objektart& oa, const Version& version );

// Existenz_Unterzentrale

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Existenz_Unterzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Existenz_Unterzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Existenz_Unterzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Existenz_Unterzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Existenz_Unterzentrale( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Existenz_Unterzentrale( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Existenz_Unterzentrale( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Existenz_Unterzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Existenz_Unterzentrale(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Existenz_Unterzentrale(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Existenz_Unterzentrale(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Existenz_Unterzentrale(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Existenz_Unterzentrale(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrsrechnerzentrale

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsrechnerzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsrechnerzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsrechnerzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsrechnerzentrale( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsrechnerzentrale( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsrechnerzentrale( const Objektart& oa, const Version& version );

// Exist_Verkehrsrechnerzentrale

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Exist_Verkehrsrechnerzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Exist_Verkehrsrechnerzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Exist_Verkehrsrechnerzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Exist_Verkehrsrechnerzentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Exist_Verkehrsrechnerzentrale( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Exist_Verkehrsrechnerzentrale( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Exist_Verkehrsrechnerzentrale( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Exist_Verkehrsrechnerzentrale(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Exist_Verkehrsrechnerzentrale(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Exist_Verkehrsrechnerzentrale(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Exist_Verkehrsrechnerzentrale(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Exist_Verkehrsrechnerzentrale(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Exist_Verkehrsrechnerzentrale(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ueberwachung_der_Anlage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ueberwachung_der_Anlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ueberwachung_der_Anlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ueberwachung_der_Anlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ueberwachung_der_Anlage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ueberwachung_der_Anlage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ueberwachung_der_Anlage( const Objektart& oa, const Version& version );

// Anzeigesystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anzeigesystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anzeigesystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anzeigesystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anzeigesystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anzeigesystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anzeigesystem( const Objektart& oa, const Version& version );

// Wechselverkehrszeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wechselverkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wechselverkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wechselverkehrszeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wechselverkehrszeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wechselverkehrszeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wechselverkehrszeichen( const Objektart& oa, const Version& version );

// Bauart_des_Zeichens

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauart_des_Zeichens( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauart_des_Zeichens( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauart_des_Zeichens( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bauart_des_Zeichens( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauart_des_Zeichens( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauart_des_Zeichens( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauart_des_Zeichens( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bauart_des_Zeichens(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bauart_des_Zeichens(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Bauart_des_Zeichens(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bauart_des_Zeichens(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bauart_des_Zeichens(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bauart_des_Zeichens(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Aufstellvorrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufstellvorrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufstellvorrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufstellvorrichtung( const Objektart& oa, const Version& version );

// Art_der_Aufstellung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Aufstellung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Aufstellung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Aufstellung( const Objektart& oa, const Version& version );

// Tab_Art_der_Aufstellung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Art_der_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Art_der_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Art_der_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Art_der_Aufstellung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Art_der_Aufstellung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Art_der_Aufstellung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Art_der_Aufstellung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Art_der_Aufstellung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Art_der_Aufstellung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Art_der_Aufstellung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Art_der_Aufstellung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Art_der_Aufstellung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Art_der_Aufstellung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anzahl_der_Anzeigequerschnitte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anzahl_der_Anzeigequerschnitte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anzahl_der_Anzeigequerschnitte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anzahl_der_Anzeigequerschnitte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anzahl_der_Anzeigequerschnitte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anzahl_der_Anzeigequerschnitte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anzahl_der_Anzeigequerschnitte( const Objektart& oa, const Version& version );

// Datenerfassungseinrichtungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datenerfassungseinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datenerfassungseinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datenerfassungseinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datenerfassungseinrichtungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datenerfassungseinrichtungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datenerfassungseinrichtungen( const Objektart& oa, const Version& version );

// Detektionsmethode

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detektionsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detektionsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detektionsmethode( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detektionsmethode( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detektionsmethode( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detektionsmethode( const Objektart& oa, const Version& version );

// Methode_VDE

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Methode_VDE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Methode_VDE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Methode_VDE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Methode_VDE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Methode_VDE( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Methode_VDE( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Methode_VDE( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Methode_VDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Methode_VDE(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Methode_VDE(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Methode_VDE(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Methode_VDE(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Methode_VDE(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Methode_UDE

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Methode_UDE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Methode_UDE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Methode_UDE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Methode_UDE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Methode_UDE( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Methode_UDE( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Methode_UDE( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Methode_UDE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Methode_UDE(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Methode_UDE(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Methode_UDE(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Methode_UDE(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Methode_UDE(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anordnung_des_Messsystems

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anordnung_des_Messsystems( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anordnung_des_Messsystems( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anordnung_des_Messsystems( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anordnung_des_Messsystems( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anordnung_des_Messsystems( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anordnung_des_Messsystems( const Objektart& oa, const Version& version );

// Art_der_Anordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Anordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Anordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Anordnung( const Objektart& oa, const Version& version );

// Tab_Art_der_Anordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Art_der_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Art_der_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Art_der_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Art_der_Anordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Art_der_Anordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Art_der_Anordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Art_der_Anordnung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Art_der_Anordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Art_der_Anordnung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Art_der_Anordnung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Art_der_Anordnung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Art_der_Anordnung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Art_der_Anordnung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_erfassten_Daten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_erfassten_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_erfassten_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_erfassten_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_erfassten_Daten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_erfassten_Daten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_erfassten_Daten( const Objektart& oa, const Version& version );

// Anzahl_der_Messquerschnitte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anzahl_der_Messquerschnitte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anzahl_der_Messquerschnitte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anzahl_der_Messquerschnitte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anzahl_der_Messquerschnitte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anzahl_der_Messquerschnitte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anzahl_der_Messquerschnitte( const Objektart& oa, const Version& version );

// Gueltigkeitsbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gueltigkeitsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gueltigkeitsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gueltigkeitsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gueltigkeitsbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gueltigkeitsbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gueltigkeitsbereich( const Objektart& oa, const Version& version );

// Bauwerkseinzelheiten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bauwerkseinzelheiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bauwerkseinzelheiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bauwerkseinzelheiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bauwerkseinzelheiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bauwerkseinzelheiten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bauwerkseinzelheiten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bauwerkseinzelheiten( const Objektart& oa, const Version& version );

// Beschilderung_Lichtsignalanl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beschilderung_Lichtsignalanl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beschilderung_Lichtsignalanl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beschilderung_Lichtsignalanl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beschilderung_Lichtsignalanl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beschilderung_Lichtsignalanl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beschilderung_Lichtsignalanl( const Objektart& oa, const Version& version );

// Fahrbahnmarkierungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrbahnmarkierungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrbahnmarkierungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrbahnmarkierungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrbahnmarkierungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrbahnmarkierungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrbahnmarkierungen( const Objektart& oa, const Version& version );

// Schutz_und_Leiteinrichtungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutz_und_Leiteinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutz_und_Leiteinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutz_und_Leiteinrichtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutz_und_Leiteinrichtungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutz_und_Leiteinrichtungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutz_und_Leiteinrichtungen( const Objektart& oa, const Version& version );

// allgemeines_Punktobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_allgemeines_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_allgemeines_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_allgemeines_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_allgemeines_Punktobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_allgemeines_Punktobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_allgemeines_Punktobjekt( const Objektart& oa, const Version& version );

// allgemeines_Linienobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_allgemeines_Linienobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_allgemeines_Linienobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_allgemeines_Linienobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_allgemeines_Linienobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_allgemeines_Linienobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_allgemeines_Linienobjekt( const Objektart& oa, const Version& version );

// allgemeines_Flaechenobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_allgemeines_Flaechenobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_allgemeines_Flaechenobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_allgemeines_Flaechenobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_allgemeines_Flaechenobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_allgemeines_Flaechenobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_allgemeines_Flaechenobjekt( const Objektart& oa, const Version& version );

// ALKIS_Objekt_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ALKIS_Objekt_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ALKIS_Objekt_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ALKIS_Objekt_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ALKIS_Objekt_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ALKIS_Objekt_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ALKIS_Objekt_Punkt( const Objektart& oa, const Version& version );

// ALKIS_Objekt_Linie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ALKIS_Objekt_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ALKIS_Objekt_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ALKIS_Objekt_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ALKIS_Objekt_Linie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ALKIS_Objekt_Linie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ALKIS_Objekt_Linie( const Objektart& oa, const Version& version );

// ALKIS_Objekt_Flaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ALKIS_Objekt_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ALKIS_Objekt_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ALKIS_Objekt_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ALKIS_Objekt_Flaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ALKIS_Objekt_Flaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ALKIS_Objekt_Flaeche( const Objektart& oa, const Version& version );

// Eigensch_allgem_Geometrieobj

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Eigensch_allgem_Geometrieobj( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Eigensch_allgem_Geometrieobj( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Eigensch_allgem_Geometrieobj( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Eigensch_allgem_Geometrieobj( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Eigensch_allgem_Geometrieobj( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Eigensch_allgem_Geometrieobj( const Objektart& oa, const Version& version );

// Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Symbol( const Objektart& oa, const Version& version );

// Einheit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Einheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einheit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einheit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einheit( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Einheit(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Einheit(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Einheit(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Einheit(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Einheit(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Boeschungsschraffen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Boeschungsschraffen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Boeschungsschraffen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Boeschungsschraffen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Boeschungsschraffen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Boeschungsschraffen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Boeschungsschraffen( const Objektart& oa, const Version& version );

// ALKIS_Identifikator

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ALKIS_Identifikator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ALKIS_Identifikator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ALKIS_Identifikator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_ALKIS_Identifikator( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ALKIS_Identifikator( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ALKIS_Identifikator( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ALKIS_Identifikator( const Objektart& oa, const Version& version );

// Dreieck

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Dreieck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Dreieck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Dreieck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Dreieck( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Dreieck( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Dreieck( const Objektart& oa, const Version& version );

// Seiteneigenschaft

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Seiteneigenschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Seiteneigenschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Seiteneigenschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Seiteneigenschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Seiteneigenschaft( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Seiteneigenschaft( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Seiteneigenschaft( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Seiteneigenschaft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Seiteneigenschaft(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Seiteneigenschaft(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Seiteneigenschaft(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Seiteneigenschaft(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Seiteneigenschaft(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Beschriftung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beschriftung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beschriftung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beschriftung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beschriftung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beschriftung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beschriftung( const Objektart& oa, const Version& version );

// Fahne

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahne( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahne( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahne( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahne(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Fahne(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahne(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahne(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahne(const Version& vsn, const Text& key, Text& value, const int& nVal);

// vertikale_Ausrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_vertikale_Ausrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_vertikale_Ausrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_vertikale_Ausrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_vertikale_Ausrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_vertikale_Ausrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_vertikale_Ausrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_vertikale_Ausrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_vertikale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_vertikale_Ausrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_vertikale_Ausrichtung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_vertikale_Ausrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_vertikale_Ausrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_vertikale_Ausrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// horizontale_Ausrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_horizontale_Ausrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_horizontale_Ausrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_horizontale_Ausrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_horizontale_Ausrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_horizontale_Ausrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_horizontale_Ausrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_horizontale_Ausrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_horizontale_Ausrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_horizontale_Ausrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_horizontale_Ausrichtung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_horizontale_Ausrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_horizontale_Ausrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_horizontale_Ausrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// DGM_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_DGM_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_DGM_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_DGM_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_DGM_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_DGM_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_DGM_Punkt( const Objektart& oa, const Version& version );

// Textausgestaltung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Textausgestaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Textausgestaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Textausgestaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Textausgestaltung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Textausgestaltung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Textausgestaltung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Textausgestaltung( const Objektart& oa, const Version& version );

// Einfuegeposition

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einfuegeposition( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einfuegeposition( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einfuegeposition( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Einfuegeposition( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einfuegeposition( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einfuegeposition( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einfuegeposition( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Einfuegeposition(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Einfuegeposition(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Einfuegeposition(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Einfuegeposition(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Einfuegeposition(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Einfuegeposition(const Version& vsn, const Text& key, Text& value, const int& nVal);

// RGB_Farbe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_RGB_Farbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_RGB_Farbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_RGB_Farbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_RGB_Farbe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_RGB_Farbe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_RGB_Farbe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_RGB_Farbe( const Objektart& oa, const Version& version );

// Beschriftungsfahne

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beschriftungsfahne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beschriftungsfahne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beschriftungsfahne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Beschriftungsfahne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beschriftungsfahne( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beschriftungsfahne( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beschriftungsfahne( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Beschriftungsfahne(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Beschriftungsfahne(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Beschriftungsfahne(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Beschriftungsfahne(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Beschriftungsfahne(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Beschriftungsfahne(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kompensationsmassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kompensationsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kompensationsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kompensationsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kompensationsmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kompensationsmassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kompensationsmassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kompensationsmassnahme( const Objektart& oa, const Version& version );

// Teilmassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Teilmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Teilmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Teilmassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Teilmassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Teilmassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Teilmassnahme( const Objektart& oa, const Version& version );

// Kompensationsteilflaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kompensationsteilflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kompensationsteilflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kompensationsteilflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kompensationsteilflaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kompensationsteilflaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kompensationsteilflaeche( const Objektart& oa, const Version& version );

// Herstellung_Fertigstpflege

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Herstellung_Fertigstpflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Herstellung_Fertigstpflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Herstellung_Fertigstpflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Herstellung_Fertigstpflege( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Herstellung_Fertigstpflege( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Herstellung_Fertigstpflege( const Objektart& oa, const Version& version );

// Entwicklungspflege

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwicklungspflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwicklungspflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwicklungspflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwicklungspflege( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwicklungspflege( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwicklungspflege( const Objektart& oa, const Version& version );

// Unterhaltungspflege

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unterhaltungspflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unterhaltungspflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unterhaltungspflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unterhaltungspflege( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unterhaltungspflege( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unterhaltungspflege( const Objektart& oa, const Version& version );

// Baumassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baumassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baumassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baumassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baumassnahme( const Objektart& oa, const Version& version );

// Baum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baum( const Objektart& oa, const Version& version );

// Baumart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baumart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baumart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baumart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Baumart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baumart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baumart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baumart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Baumart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Baumart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Baumart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Baumart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Baumart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Baumart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zustandsbeurteilung_Baum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zustandsbeurteilung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zustandsbeurteilung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zustandsbeurteilung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zustandsbeurteilung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zustandsbeurteilung_Baum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zustandsbeurteilung_Baum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zustandsbeurteilung_Baum( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zustandsbeurteilung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zustandsbeurteilung_Baum(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zustandsbeurteilung_Baum(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zustandsbeurteilung_Baum(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zustandsbeurteilung_Baum(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zustandsbeurteilung_Baum(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Baumschaden

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baumschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baumschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baumschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baumschaden( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baumschaden( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baumschaden( const Objektart& oa, const Version& version );

// Kronenschaden

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kronenschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kronenschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kronenschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kronenschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kronenschaden( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kronenschaden( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kronenschaden( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kronenschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kronenschaden(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Kronenschaden(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kronenschaden(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kronenschaden(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kronenschaden(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Stammschaden

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Stammschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Stammschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Stammschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Stammschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Stammschaden( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Stammschaden( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Stammschaden( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Stammschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Stammschaden(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Stammschaden(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Stammschaden(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Stammschaden(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Stammschaden(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wurzelschaden

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wurzelschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wurzelschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wurzelschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wurzelschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wurzelschaden( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wurzelschaden( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wurzelschaden( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Wurzelschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Wurzelschaden(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Wurzelschaden(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Wurzelschaden(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Wurzelschaden(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Wurzelschaden(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schadensursache_Baum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schadensursache_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schadensursache_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schadensursache_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schadensursache_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schadensursache_Baum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schadensursache_Baum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schadensursache_Baum( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schadensursache_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schadensursache_Baum(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Schadensursache_Baum(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schadensursache_Baum(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schadensursache_Baum(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schadensursache_Baum(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Standortbeschreibung_Baum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Standortbeschreibung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Standortbeschreibung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Standortbeschreibung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Standortbeschreibung_Baum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Standortbeschreibung_Baum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Standortbeschreibung_Baum( const Objektart& oa, const Version& version );

// Lagebeschreibung_Baum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lagebeschreibung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lagebeschreibung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lagebeschreibung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lagebeschreibung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lagebeschreibung_Baum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lagebeschreibung_Baum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lagebeschreibung_Baum( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lagebeschreibung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lagebeschreibung_Baum(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Lagebeschreibung_Baum(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lagebeschreibung_Baum(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lagebeschreibung_Baum(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lagebeschreibung_Baum(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bewuchs

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bewuchs( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bewuchs( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bewuchs( const Objektart& oa, const Version& version );

// Schutzstatus_Bewuchs

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schutzstatus_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schutzstatus_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schutzstatus_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schutzstatus_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schutzstatus_Bewuchs( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schutzstatus_Bewuchs( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schutzstatus_Bewuchs( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schutzstatus_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schutzstatus_Bewuchs(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Schutzstatus_Bewuchs(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schutzstatus_Bewuchs(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schutzstatus_Bewuchs(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schutzstatus_Bewuchs(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Pflegemassnahme_Bewuchs

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pflegemassnahme_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pflegemassnahme_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pflegemassnahme_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Pflegemassnahme_Bewuchs( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pflegemassnahme_Bewuchs( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pflegemassnahme_Bewuchs( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pflegemassnahme_Bewuchs( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Pflegemassnahme_Bewuchs(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Pflegemassnahme_Bewuchs(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Pflegemassnahme_Bewuchs(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Pflegemassnahme_Bewuchs(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Pflegemassnahme_Bewuchs(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Pflegemassnahme_Bewuchs(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Baumreihe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baumreihe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baumreihe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baumreihe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baumreihe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baumreihe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baumreihe( const Objektart& oa, const Version& version );

// Baumreihenabschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Baumreihenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Baumreihenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Baumreihenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Baumreihenabschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Baumreihenabschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Baumreihenabschnitt( const Objektart& oa, const Version& version );

// Allee

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Allee( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Allee( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Allee( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Allee( const Objektart& oa, const Version& version );

// Schiefstand_Baum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schiefstand_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schiefstand_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schiefstand_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schiefstand_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schiefstand_Baum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schiefstand_Baum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schiefstand_Baum( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schiefstand_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schiefstand_Baum(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Schiefstand_Baum(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schiefstand_Baum(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schiefstand_Baum(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schiefstand_Baum(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Stammfussschaden

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Stammfussschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Stammfussschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Stammfussschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Stammfussschaden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Stammfussschaden( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Stammfussschaden( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Stammfussschaden( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Stammfussschaden(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Stammfussschaden(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Stammfussschaden(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Stammfussschaden(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Stammfussschaden(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Stammfussschaden(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Schadenseinstufung_Baum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schadenseinstufung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schadenseinstufung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schadenseinstufung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Schadenseinstufung_Baum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schadenseinstufung_Baum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schadenseinstufung_Baum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schadenseinstufung_Baum( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Schadenseinstufung_Baum(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Schadenseinstufung_Baum(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Schadenseinstufung_Baum(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Schadenseinstufung_Baum(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Schadenseinstufung_Baum(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Schadenseinstufung_Baum(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Pflegemassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Pflegemassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Pflegemassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Pflegemassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Pflegemassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Pflegemassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Pflegemassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Pflegemassnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Pflegemassnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Pflegemassnahme(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Pflegemassnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Pflegemassnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Pflegemassnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Quelle_Pflegemassnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Quelle_Pflegemassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Quelle_Pflegemassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Quelle_Pflegemassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Quelle_Pflegemassnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Quelle_Pflegemassnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Quelle_Pflegemassnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Quelle_Pflegemassnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Quelle_Pflegemassnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Quelle_Pflegemassnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Quelle_Pflegemassnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Quelle_Pflegemassnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Quelle_Pflegemassnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Leistungserbringer_Pflege

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Leistungserbringer_Pflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Leistungserbringer_Pflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Leistungserbringer_Pflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Leistungserbringer_Pflege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Leistungserbringer_Pflege( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Leistungserbringer_Pflege( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Leistungserbringer_Pflege( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Leistungserbringer_Pflege(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Leistungserbringer_Pflege(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Leistungserbringer_Pflege(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Leistungserbringer_Pflege(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Leistungserbringer_Pflege(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Arbeitsstelle_an_Strassen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Arbeitsstelle_an_Strassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Arbeitsstelle_an_Strassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Arbeitsstelle_an_Strassen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Arbeitsstelle_an_Strassen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Arbeitsstelle_an_Strassen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Arbeitsstelle_an_Strassen( const Objektart& oa, const Version& version );

// Art_der_Leistung_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Leistung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Leistung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Leistung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Leistung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Leistung_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Leistung_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Leistung_Arbeitsstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Leistung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Leistung_Arbeitsstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Leistung_Arbeitsstelle(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Leistung_Arbeitsstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Leistung_Arbeitsstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Leistung_Arbeitsstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Status_der_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Status_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Status_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Status_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Status_der_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Status_der_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Status_der_Arbeitsstelle( const Objektart& oa, const Version& version );

// Tab_Status_der_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Status_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Status_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Status_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Status_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Status_der_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Status_der_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Status_der_Arbeitsstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Status_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Status_der_Arbeitsstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Status_der_Arbeitsstelle(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Status_der_Arbeitsstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Status_der_Arbeitsstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Status_der_Arbeitsstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// verkehrliche_Angaben_Arbeitsst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verkehrliche_Angaben_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verkehrliche_Angaben_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verkehrliche_Angaben_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verkehrliche_Angaben_Arbeitsst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verkehrliche_Angaben_Arbeitsst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verkehrliche_Angaben_Arbeitsst( const Objektart& oa, const Version& version );

// Status_der_verkehrl_Angabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Status_der_verkehrl_Angabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Status_der_verkehrl_Angabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Status_der_verkehrl_Angabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Status_der_verkehrl_Angabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Status_der_verkehrl_Angabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Status_der_verkehrl_Angabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Status_der_verkehrl_Angabe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Status_der_verkehrl_Angabe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Status_der_verkehrl_Angabe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Status_der_verkehrl_Angabe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Status_der_verkehrl_Angabe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Status_der_verkehrl_Angabe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Status_der_verkehrl_Angabe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Arbeitsstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Arbeitsstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Arbeitsstelle(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Arbeitsstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Arbeitsstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Arbeitsstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_Behinderung_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Behinderung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Behinderung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Behinderung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Behinderung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Behinderung_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Behinderung_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Behinderung_Arbeitsstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Behinderung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Behinderung_Arbeitsstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Behinderung_Arbeitsstelle(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Behinderung_Arbeitsstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Behinderung_Arbeitsstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Behinderung_Arbeitsstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrsfuehrung_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsfuehrung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsfuehrung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsfuehrung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verkehrsfuehrung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsfuehrung_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsfuehrung_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsfuehrung_Arbeitsstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verkehrsfuehrung_Arbeitsstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verkehrsfuehrung_Arbeitsstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verkehrsfuehrung_Arbeitsstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verkehrsfuehrung_Arbeitsstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verkehrsfuehrung_Arbeitsstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Behinderung_Prognose

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Behinderung_Prognose( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Behinderung_Prognose( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Behinderung_Prognose( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Behinderung_Prognose( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Behinderung_Prognose( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Behinderung_Prognose( const Objektart& oa, const Version& version );

// Behinderung_Status

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Behinderung_Status( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Behinderung_Status( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Behinderung_Status( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Behinderung_Status( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Behinderung_Status( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Behinderung_Status( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Behinderung_Status( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Behinderung_Status(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Behinderung_Status(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Behinderung_Status(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Behinderung_Status(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Behinderung_Status(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Behinderung_Status(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Umleitung_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Umleitung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Umleitung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Umleitung_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Umleitung_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Umleitung_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Umleitung_Arbeitsstelle( const Objektart& oa, const Version& version );

// Umleitung_Strecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Umleitung_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Umleitung_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Umleitung_Strecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Umleitung_Strecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Umleitung_Strecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Umleitung_Strecke( const Objektart& oa, const Version& version );

// RSA_Regelplan

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_RSA_Regelplan( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_RSA_Regelplan( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_RSA_Regelplan( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_RSA_Regelplan( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_RSA_Regelplan( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_RSA_Regelplan( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_RSA_Regelplan( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_RSA_Regelplan(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_RSA_Regelplan(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_RSA_Regelplan(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_RSA_Regelplan(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_RSA_Regelplan(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Rolle_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rolle_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rolle_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rolle_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rolle_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rolle_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rolle_Arbeitsstelle( const Objektart& oa, const Version& version );

// Rollenbeschreibung_Arbeitsst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rollenbeschreibung_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rollenbeschreibung_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rollenbeschreibung_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rollenbeschreibung_Arbeitsst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rollenbeschreibung_Arbeitsst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rollenbeschreibung_Arbeitsst( const Objektart& oa, const Version& version );

// Durchfuehrender_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Durchfuehrender_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Durchfuehrender_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Durchfuehrender_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Durchfuehrender_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Durchfuehrender_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Durchfuehrender_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Durchfuehrender_Arbeitsstelle( const Objektart& oa, const Version& version );

// Firma_Arbeitsstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Firma_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Firma_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Firma_Arbeitsstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Firma_Arbeitsstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Firma_Arbeitsstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Firma_Arbeitsstelle( const Objektart& oa, const Version& version );

// Zusatzinformationen_Arbeitsst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zusatzinformationen_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zusatzinformationen_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zusatzinformationen_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zusatzinformationen_Arbeitsst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zusatzinformationen_Arbeitsst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zusatzinformationen_Arbeitsst( const Objektart& oa, const Version& version );

// hist_Meldungszustand_Arbeitsst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_hist_Meldungszustand_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_hist_Meldungszustand_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_hist_Meldungszustand_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_hist_Meldungszustand_Arbeitsst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_hist_Meldungszustand_Arbeitsst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_hist_Meldungszustand_Arbeitsst( const Objektart& oa, const Version& version );

// Abbruch_Einstellung_Arbeitsst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abbruch_Einstellung_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abbruch_Einstellung_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abbruch_Einstellung_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abbruch_Einstellung_Arbeitsst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abbruch_Einstellung_Arbeitsst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abbruch_Einstellung_Arbeitsst( const Objektart& oa, const Version& version );

// Tab_Abbruch_Einst_Arbeitsst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Abbruch_Einst_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Abbruch_Einst_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Abbruch_Einst_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Abbruch_Einst_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Abbruch_Einst_Arbeitsst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Abbruch_Einst_Arbeitsst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Abbruch_Einst_Arbeitsst( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Abbruch_Einst_Arbeitsst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Abbruch_Einst_Arbeitsst(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Abbruch_Einst_Arbeitsst(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Abbruch_Einst_Arbeitsst(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Abbruch_Einst_Arbeitsst(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Abbruch_Einst_Arbeitsst(const Version& vsn, const Text& key, Text& value, const int& nVal);

// zust_Polizeidienstst_Arbeitsst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zust_Polizeidienstst_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zust_Polizeidienstst_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zust_Polizeidienstst_Arbeitsst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zust_Polizeidienstst_Arbeitsst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zust_Polizeidienstst_Arbeitsst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zust_Polizeidienstst_Arbeitsst( const Objektart& oa, const Version& version );

// Boeschung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Boeschung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Boeschung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Boeschung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Boeschung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Boeschung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Boeschung( const Objektart& oa, const Version& version );

// Art_Boeschung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Boeschung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Boeschung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Boeschung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Boeschung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Boeschung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Boeschung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Boeschung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Boeschung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Boeschung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Boeschung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Boeschung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Boeschung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Boeschung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Beginn_Interpolation

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beginn_Interpolation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beginn_Interpolation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beginn_Interpolation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Beginn_Interpolation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beginn_Interpolation( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beginn_Interpolation( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beginn_Interpolation( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Beginn_Interpolation(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Beginn_Interpolation(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Beginn_Interpolation(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Beginn_Interpolation(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Beginn_Interpolation(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Beginn_Interpolation(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Boeschungskantenabschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Boeschungskantenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Boeschungskantenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Boeschungskantenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Boeschungskantenabschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Boeschungskantenabschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Boeschungskantenabschnitt( const Objektart& oa, const Version& version );

// Boeschungslinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Boeschungslinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Boeschungslinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Boeschungslinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Boeschungslinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Boeschungslinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Boeschungslinie( const Objektart& oa, const Version& version );

// Art_Boeschungslinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Boeschungslinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Boeschungslinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Boeschungslinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Boeschungslinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Boeschungslinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Boeschungslinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Boeschungslinie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Boeschungslinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Boeschungslinie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Boeschungslinie(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Boeschungslinie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Boeschungslinie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Boeschungslinie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gebaeude

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gebaeude( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gebaeude( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gebaeude( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gebaeude( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gebaeude( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gebaeude( const Objektart& oa, const Version& version );

// Zaun

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaun( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaun( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaun( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaun( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaun( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaun( const Objektart& oa, const Version& version );

// Mauer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Mauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Mauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Mauer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Mauer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Mauer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Mauer( const Objektart& oa, const Version& version );

// Gebuesch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gebuesch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gebuesch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gebuesch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gebuesch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gebuesch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gebuesch( const Objektart& oa, const Version& version );

// Hecke

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hecke( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hecke( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hecke( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hecke( const Objektart& oa, const Version& version );

// Gehoelz

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gehoelz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gehoelz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gehoelz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gehoelz( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gehoelz( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gehoelz( const Objektart& oa, const Version& version );

// Status_Eigenschaft

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Status_Eigenschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Status_Eigenschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Status_Eigenschaft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Status_Eigenschaft( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Status_Eigenschaft( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Status_Eigenschaft( const Objektart& oa, const Version& version );

// Bestandsstatus

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bestandsstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bestandsstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bestandsstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Bestandsstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bestandsstatus( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bestandsstatus( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bestandsstatus( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Bestandsstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Bestandsstatus(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Bestandsstatus(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Bestandsstatus(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Bestandsstatus(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Bestandsstatus(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gebaeudenutzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gebaeudenutzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gebaeudenutzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gebaeudenutzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gebaeudenutzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gebaeudenutzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gebaeudenutzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gebaeudenutzung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gebaeudenutzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gebaeudenutzung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gebaeudenutzung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gebaeudenutzung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gebaeudenutzung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gebaeudefunktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gebaeudefunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gebaeudefunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gebaeudefunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gebaeudefunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gebaeudefunktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gebaeudefunktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gebaeudefunktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gebaeudefunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gebaeudefunktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gebaeudefunktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gebaeudefunktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gebaeudefunktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anschrift

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anschrift( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anschrift( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anschrift( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anschrift( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anschrift( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anschrift( const Objektart& oa, const Version& version );

// Geschoss

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Geschoss( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Geschoss( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Geschoss( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Geschoss( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Geschoss( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Geschoss( const Objektart& oa, const Version& version );

// Seite_Zaunpfaehle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Seite_Zaunpfaehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Seite_Zaunpfaehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Seite_Zaunpfaehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Seite_Zaunpfaehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Seite_Zaunpfaehle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Seite_Zaunpfaehle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Seite_Zaunpfaehle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Seite_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Seite_Zaunpfaehle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Seite_Zaunpfaehle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Seite_Zaunpfaehle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Seite_Zaunpfaehle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zaunart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaunart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaunart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaunart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zaunart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaunart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaunart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaunart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zaunart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zaunart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zaunart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zaunart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zaunart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zaunart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Zaunpfaehle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Zaunpfaehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Zaunpfaehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Zaunpfaehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Zaunpfaehle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Zaunpfaehle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Zaunpfaehle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Zaunpfaehle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Zaunpfaehle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Zaunpfaehle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Material_Zaunpfaehle(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Zaunpfaehle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Zaunpfaehle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Zaunpfaehle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zaunfunktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaunfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaunfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaunfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zaunfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaunfunktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaunfunktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaunfunktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zaunfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zaunfunktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zaunfunktion(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zaunfunktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zaunfunktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zaunfunktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Oeffnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Oeffnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Oeffnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Oeffnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Oeffnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Oeffnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Oeffnung( const Objektart& oa, const Version& version );

// Art_Oeffnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Oeffnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Oeffnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Oeffnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Oeffnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Oeffnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Oeffnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Oeffnung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Oeffnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Oeffnung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Oeffnung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Oeffnung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Oeffnung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Oeffnung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Mauerfunktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Mauerfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Mauerfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Mauerfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Mauerfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Mauerfunktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Mauerfunktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Mauerfunktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Mauerfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Mauerfunktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Mauerfunktion(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Mauerfunktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Mauerfunktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Mauerfunktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Mauerabschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Mauerabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Mauerabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Mauerabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Mauerabschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Mauerabschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Mauerabschnitt( const Objektart& oa, const Version& version );

// Lage_Bezugsgeometrie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_Bezugsgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_Bezugsgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_Bezugsgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_Bezugsgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_Bezugsgeometrie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_Bezugsgeometrie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_Bezugsgeometrie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_Bezugsgeometrie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_Bezugsgeometrie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_Bezugsgeometrie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_Bezugsgeometrie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_Bezugsgeometrie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Material_Mauerabschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Material_Mauerabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Material_Mauerabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Material_Mauerabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Material_Mauerabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Material_Mauerabschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Material_Mauerabschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Material_Mauerabschnitt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Material_Mauerabschnitt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Material_Mauerabschnitt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Material_Mauerabschnitt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Material_Mauerabschnitt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Material_Mauerabschnitt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gehoelzart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gehoelzart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gehoelzart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gehoelzart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gehoelzart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gehoelzart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gehoelzart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gehoelzart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gehoelzart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gehoelzart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gehoelzart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gehoelzart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gehoelzart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Heckenfunktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Heckenfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Heckenfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Heckenfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Heckenfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Heckenfunktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Heckenfunktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Heckenfunktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Heckenfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Heckenfunktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Heckenfunktion(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Heckenfunktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Heckenfunktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Heckenfunktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Heckenabschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Heckenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Heckenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Heckenabschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Heckenabschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Heckenabschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Heckenabschnitt( const Objektart& oa, const Version& version );

// Flurstueck

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flurstueck( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flurstueck( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flurstueck( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Flurstueck(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Flur

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flur( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flur( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flur( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flur( const Objektart& oa, const Version& version );

// Attribut_Flurstueck

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Attribut_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Attribut_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Attribut_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Attribut_Flurstueck( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Attribut_Flurstueck( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Attribut_Flurstueck( const Objektart& oa, const Version& version );

// Erwerbsflaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erwerbsflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erwerbsflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erwerbsflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Erwerbsflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erwerbsflaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erwerbsflaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erwerbsflaeche( const Objektart& oa, const Version& version );

// Erwerbsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erwerbsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erwerbsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erwerbsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Erwerbsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erwerbsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erwerbsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erwerbsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Erwerbsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Erwerbsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Erwerbsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Erwerbsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Erwerbsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// GEV_Ausgabespalte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GEV_Ausgabespalte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GEV_Ausgabespalte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GEV_Ausgabespalte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_GEV_Ausgabespalte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GEV_Ausgabespalte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GEV_Ausgabespalte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GEV_Ausgabespalte( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_GEV_Ausgabespalte(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_GEV_Ausgabespalte(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_GEV_Ausgabespalte(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_GEV_Ausgabespalte(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_GEV_Ausgabespalte(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_GEV_Ausgabespalte(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Erwerbszweck

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erwerbszweck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erwerbszweck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erwerbszweck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Erwerbszweck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erwerbszweck( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erwerbszweck( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erwerbszweck( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Erwerbszweck(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Erwerbszweck(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Erwerbszweck(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Erwerbszweck(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Erwerbszweck(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Nutzungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nutzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nutzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nutzungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nutzungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nutzungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nutzungsart( const Objektart& oa, const Version& version );

// GE_Massnahme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GE_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GE_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GE_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_GE_Massnahme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GE_Massnahme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GE_Massnahme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GE_Massnahme( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_GE_Massnahme(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_GE_Massnahme(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_GE_Massnahme(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_GE_Massnahme(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_GE_Massnahme(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Nutzungsartteilflaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nutzungsartteilflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nutzungsartteilflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nutzungsartteilflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nutzungsartteilflaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nutzungsartteilflaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nutzungsartteilflaeche( const Objektart& oa, const Version& version );

// Belastung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Belastung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Belastung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Belastung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Belastung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Belastung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Belastung( const Objektart& oa, const Version& version );

// Belastungsberechtigter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Belastungsberechtigter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Belastungsberechtigter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Belastungsberechtigter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Belastungsberechtigter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Belastungsberechtigter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Belastungsberechtigter( const Objektart& oa, const Version& version );

// Person_Flurstueck

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Person_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Person_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Person_Flurstueck( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Person_Flurstueck( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Person_Flurstueck( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Person_Flurstueck( const Objektart& oa, const Version& version );

// Verhaeltnis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verhaeltnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verhaeltnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verhaeltnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verhaeltnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verhaeltnis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verhaeltnis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verhaeltnis( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verhaeltnis(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verhaeltnis(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verhaeltnis(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verhaeltnis(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Flurstueck_Grundbuch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flurstueck_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flurstueck_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flurstueck_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flurstueck_Grundbuch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flurstueck_Grundbuch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flurstueck_Grundbuch( const Objektart& oa, const Version& version );

// Eigentumsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Eigentumsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Eigentumsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Eigentumsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Eigentumsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Eigentumsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Eigentumsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Eigentumsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Eigentumsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Eigentumsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Eigentumsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Eigentumsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Eigentumsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grundbuch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundbuch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundbuch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundbuch( const Objektart& oa, const Version& version );

// Gemarkung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gemarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gemarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gemarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gemarkung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gemarkung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gemarkung( const Objektart& oa, const Version& version );

// Paechter_Mieter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Paechter_Mieter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Paechter_Mieter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Paechter_Mieter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Paechter_Mieter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Paechter_Mieter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Paechter_Mieter( const Objektart& oa, const Version& version );

// Vertragsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vertragsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vertragsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vertragsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vertragsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vertragsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vertragsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vertragsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vertragsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vertragsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vertragsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vertragsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vertragsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Eigentuemer_Grundbuch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Eigentuemer_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Eigentuemer_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Eigentuemer_Grundbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Eigentuemer_Grundbuch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Eigentuemer_Grundbuch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Eigentuemer_Grundbuch( const Objektart& oa, const Version& version );

// Eigentumsverhaeltnis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Eigentumsverhaeltnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Eigentumsverhaeltnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Eigentumsverhaeltnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Eigentumsverhaeltnis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Eigentumsverhaeltnis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Eigentumsverhaeltnis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Eigentumsverhaeltnis( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Eigentumsverhaeltnis(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Eigentumsverhaeltnis(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Eigentumsverhaeltnis(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Eigentumsverhaeltnis(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Eigentumsverhaeltnis(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Person

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Person( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Person( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Person( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Person( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Person( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Person( const Objektart& oa, const Version& version );

// Land

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Land( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Land( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Land( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Land( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Land(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Land(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Land(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Land(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Land(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Personenklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Personenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Personenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Personenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Personenklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Personenklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Personenklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Personenklasse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Personenklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Personenklasse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Personenklasse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Personenklasse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Personenklasse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Erwerbsart_spezifisch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erwerbsart_spezifisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erwerbsart_spezifisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erwerbsart_spezifisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Erwerbsart_spezifisch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erwerbsart_spezifisch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erwerbsart_spezifisch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erwerbsart_spezifisch( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Erwerbsart_spezifisch(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Erwerbsart_spezifisch(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Erwerbsart_spezifisch(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Erwerbsart_spezifisch(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Erwerbsart_spezifisch(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Nutzungsartflaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nutzungsartflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nutzungsartflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nutzungsartflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nutzungsartflaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nutzungsartflaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nutzungsartflaeche( const Objektart& oa, const Version& version );

// Nutzungsartflaeche_Basis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nutzungsartflaeche_Basis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nutzungsartflaeche_Basis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nutzungsartflaeche_Basis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nutzungsartflaeche_Basis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nutzungsartflaeche_Basis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nutzungsartflaeche_Basis( const Objektart& oa, const Version& version );

// Pachtart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Pachtart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Pachtart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Pachtart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Pachtart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Pachtart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Pachtart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Pachtart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Pachtart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Pachtart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Pachtart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Pachtart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Pachtart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Pachtart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anordnungsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anordnungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anordnungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anordnungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Anordnungsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anordnungsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anordnungsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anordnungsart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Anordnungsart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Anordnungsart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Anordnungsart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Anordnungsart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Anordnungsart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Anordnungsart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// trigonometrischer_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_trigonometrischer_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_trigonometrischer_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_trigonometrischer_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_trigonometrischer_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_trigonometrischer_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_trigonometrischer_Punkt( const Objektart& oa, const Version& version );

// Sicherungspunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sicherungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sicherungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sicherungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sicherungspunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sicherungspunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sicherungspunkt( const Objektart& oa, const Version& version );

// Aufnahmepunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufnahmepunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufnahmepunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufnahmepunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufnahmepunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufnahmepunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufnahmepunkt( const Objektart& oa, const Version& version );

// sonstiger_Vermessungspunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_sonstiger_Vermessungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_sonstiger_Vermessungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_sonstiger_Vermessungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_sonstiger_Vermessungspunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_sonstiger_Vermessungspunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_sonstiger_Vermessungspunkt( const Objektart& oa, const Version& version );

// Lagepasspunkt_SBV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lagepasspunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lagepasspunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lagepasspunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lagepasspunkt_SBV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lagepasspunkt_SBV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lagepasspunkt_SBV( const Objektart& oa, const Version& version );

// Lagefestpunkt_SBV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lagefestpunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lagefestpunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lagefestpunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lagefestpunkt_SBV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lagefestpunkt_SBV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lagefestpunkt_SBV( const Objektart& oa, const Version& version );

// Lagefestpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lagefestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lagefestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lagefestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lagefestpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lagefestpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lagefestpunkt( const Objektart& oa, const Version& version );

// Nivellementpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nivellementpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nivellementpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nivellementpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nivellementpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nivellementpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nivellementpunkt( const Objektart& oa, const Version& version );

// Hoehenpasspunkt_SBV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenpasspunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenpasspunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenpasspunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenpasspunkt_SBV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenpasspunkt_SBV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenpasspunkt_SBV( const Objektart& oa, const Version& version );

// Hoehenfestpunkt_SBV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenfestpunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenfestpunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenfestpunkt_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenfestpunkt_SBV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenfestpunkt_SBV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenfestpunkt_SBV( const Objektart& oa, const Version& version );

// Hoehenfestpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenfestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenfestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenfestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenfestpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenfestpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenfestpunkt( const Objektart& oa, const Version& version );

// Festpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Festpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Festpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Festpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Festpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Festpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Festpunkt( const Objektart& oa, const Version& version );

// Referenzstationspunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Referenzstationspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Referenzstationspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Referenzstationspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Referenzstationspunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Referenzstationspunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Referenzstationspunkt( const Objektart& oa, const Version& version );

// Vermessungspunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vermessungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vermessungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vermessungspunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vermessungspunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vermessungspunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vermessungspunkt( const Objektart& oa, const Version& version );

// Punktvermarkung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktvermarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktvermarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktvermarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Punktvermarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktvermarkung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktvermarkung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktvermarkung( const Objektart& oa, const Version& version );

// Art_der_Vermarkung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Vermarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Vermarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Vermarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Vermarkung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Vermarkung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Vermarkung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Vermarkung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Vermarkung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Vermarkung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Vermarkung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Vermarkung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Vermarkung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Vermarkung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Punktort

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktort( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktort( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktort( const Objektart& oa, const Version& version );

// Koordinatenstatus

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Koordinatenstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Koordinatenstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Koordinatenstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Koordinatenstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Koordinatenstatus( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Koordinatenstatus( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Koordinatenstatus( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Koordinatenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Koordinatenstatus(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Koordinatenstatus(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Koordinatenstatus(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Koordinatenstatus(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Koordinatenstatus(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Qualitaetsangaben_Punktort

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Qualitaetsangaben_Punktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Qualitaetsangaben_Punktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Qualitaetsangaben_Punktort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Qualitaetsangaben_Punktort( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Qualitaetsangaben_Punktort( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Qualitaetsangaben_Punktort( const Objektart& oa, const Version& version );

// Datenerhebung_Pos_2D

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datenerhebung_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datenerhebung_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datenerhebung_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Datenerhebung_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datenerhebung_Pos_2D( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datenerhebung_Pos_2D( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datenerhebung_Pos_2D( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Datenerhebung_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Datenerhebung_Pos_2D(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Datenerhebung_Pos_2D(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Datenerhebung_Pos_2D(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Datenerhebung_Pos_2D(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Datenerhebung_Pos_2D(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Datenerhebung_Pos_Hoehe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datenerhebung_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datenerhebung_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datenerhebung_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Datenerhebung_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datenerhebung_Pos_Hoehe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datenerhebung_Pos_Hoehe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datenerhebung_Pos_Hoehe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Datenerhebung_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Datenerhebung_Pos_Hoehe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Datenerhebung_Pos_Hoehe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Datenerhebung_Pos_Hoehe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Datenerhebung_Pos_Hoehe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Datenerhebung_Pos_Hoehe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Datenerhebung_Pos_3D

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datenerhebung_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datenerhebung_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datenerhebung_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Datenerhebung_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datenerhebung_Pos_3D( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datenerhebung_Pos_3D( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datenerhebung_Pos_3D( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Datenerhebung_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Datenerhebung_Pos_3D(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Datenerhebung_Pos_3D(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Datenerhebung_Pos_3D(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Datenerhebung_Pos_3D(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Datenerhebung_Pos_3D(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Genauigkeit_Pos_2D

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Genauigkeit_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Genauigkeit_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Genauigkeit_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Genauigkeit_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Genauigkeit_Pos_2D( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Genauigkeit_Pos_2D( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Genauigkeit_Pos_2D( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Genauigkeit_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Genauigkeit_Pos_2D(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Genauigkeit_Pos_2D(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Genauigkeit_Pos_2D(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Genauigkeit_Pos_2D(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Genauigkeit_Pos_2D(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Genauigkeit_Pos_Hoehe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Genauigkeit_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Genauigkeit_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Genauigkeit_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Genauigkeit_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Genauigkeit_Pos_Hoehe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Genauigkeit_Pos_Hoehe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Genauigkeit_Pos_Hoehe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Genauigkeit_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Genauigkeit_Pos_Hoehe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Genauigkeit_Pos_Hoehe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Genauigkeit_Pos_Hoehe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Genauigkeit_Pos_Hoehe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Genauigkeit_Pos_Hoehe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Genauigkeit_Pos_3D

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Genauigkeit_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Genauigkeit_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Genauigkeit_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Genauigkeit_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Genauigkeit_Pos_3D( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Genauigkeit_Pos_3D( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Genauigkeit_Pos_3D( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Genauigkeit_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Genauigkeit_Pos_3D(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Genauigkeit_Pos_3D(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Genauigkeit_Pos_3D(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Genauigkeit_Pos_3D(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Genauigkeit_Pos_3D(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vertrauenswuerdigk_Pos_2D

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vertrauenswuerdigk_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vertrauenswuerdigk_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vertrauenswuerdigk_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vertrauenswuerdigk_Pos_2D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vertrauenswuerdigk_Pos_2D( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vertrauenswuerdigk_Pos_2D( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vertrauenswuerdigk_Pos_2D( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vertrauenswuerdigk_Pos_2D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vertrauenswuerdigk_Pos_2D(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Vertrauenswuerdigk_Pos_2D(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vertrauenswuerdigk_Pos_2D(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vertrauenswuerdigk_Pos_2D(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vertrauenswuerdigk_Pos_2D(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vertrauenswuerdigk_Pos_Hoehe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vertrauenswuerdigk_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vertrauenswuerdigk_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vertrauenswuerdigk_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vertrauenswuerdigk_Pos_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vertrauenswuerdigk_Pos_Hoehe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vertrauenswuerdigk_Pos_Hoehe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vertrauenswuerdigk_Pos_Hoehe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vertrauenswuerdigk_Pos_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vertrauenswuerdigk_Pos_Hoehe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Vertrauenswuerdigk_Pos_Hoehe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vertrauenswuerdigk_Pos_Hoehe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vertrauenswuerdigk_Pos_Hoehe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vertrauenswuerdigk_Pos_Hoehe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Vertrauenswuerdigk_Pos_3D

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Vertrauenswuerdigk_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Vertrauenswuerdigk_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Vertrauenswuerdigk_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Vertrauenswuerdigk_Pos_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Vertrauenswuerdigk_Pos_3D( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Vertrauenswuerdigk_Pos_3D( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Vertrauenswuerdigk_Pos_3D( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Vertrauenswuerdigk_Pos_3D(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Vertrauenswuerdigk_Pos_3D(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Vertrauenswuerdigk_Pos_3D(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Vertrauenswuerdigk_Pos_3D(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Vertrauenswuerdigk_Pos_3D(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Vertrauenswuerdigk_Pos_3D(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Hoehe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehe( const Objektart& oa, const Version& version );

// Hoehensystem

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehensystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehensystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehensystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hoehensystem( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehensystem( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehensystem( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehensystem( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Hoehensystem(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Hoehensystem(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Hoehensystem(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Hoehensystem(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Hoehensystem(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Hoehensystem(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Hoehenstatus

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hoehenstatus( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenstatus( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenstatus( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenstatus( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Hoehenstatus(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Hoehenstatus(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Hoehenstatus(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Hoehenstatus(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Hoehenstatus(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Hoehenstatus(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Qualitaetsangaben_Hoehe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Qualitaetsangaben_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Qualitaetsangaben_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Qualitaetsangaben_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Qualitaetsangaben_Hoehe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Qualitaetsangaben_Hoehe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Qualitaetsangaben_Hoehe( const Objektart& oa, const Version& version );

// Datenerhebung_Hoehe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datenerhebung_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datenerhebung_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datenerhebung_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Datenerhebung_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datenerhebung_Hoehe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datenerhebung_Hoehe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datenerhebung_Hoehe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Datenerhebung_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Datenerhebung_Hoehe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Datenerhebung_Hoehe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Datenerhebung_Hoehe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Datenerhebung_Hoehe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Datenerhebung_Hoehe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Genauigkeit_Hoehe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Genauigkeit_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Genauigkeit_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Genauigkeit_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Genauigkeit_Hoehe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Genauigkeit_Hoehe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Genauigkeit_Hoehe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Genauigkeit_Hoehe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Genauigkeit_Hoehe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Genauigkeit_Hoehe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Genauigkeit_Hoehe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Genauigkeit_Hoehe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Genauigkeit_Hoehe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Genauigkeit_Hoehe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Skizze

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Skizze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Skizze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Skizze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Skizze( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Skizze( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Skizze( const Objektart& oa, const Version& version );

// Skizzenart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Skizzenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Skizzenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Skizzenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Skizzenart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Skizzenart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Skizzenart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Skizzenart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Skizzenart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Skizzenart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Skizzenart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Skizzenart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Skizzenart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Skizzenart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// GPS_Tauglichkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GPS_Tauglichkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GPS_Tauglichkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GPS_Tauglichkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_GPS_Tauglichkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GPS_Tauglichkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GPS_Tauglichkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GPS_Tauglichkeit( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_GPS_Tauglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_GPS_Tauglichkeit(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_GPS_Tauglichkeit(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_GPS_Tauglichkeit(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_GPS_Tauglichkeit(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_GPS_Tauglichkeit(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Punktstabilitaet_Lagefestpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktstabilitaet_Lagefestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktstabilitaet_Lagefestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktstabilitaet_Lagefestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Punktstabilitaet_Lagefestpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktstabilitaet_Lagefestpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktstabilitaet_Lagefestpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktstabilitaet_Lagefestpunkt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Punktstabilitaet_Lagefestpunkt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Punktstabilitaet_Lagefestpunkt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Punktstabilitaet_Lagefestpunkt(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Punktstabilitaet_Lagefestpunkt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Punktstabilitaet_Lagefestpunkt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Punktstabilitaet_Lagefestpunkt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// vermutete_Hoehenstabilitaet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_vermutete_Hoehenstabilitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_vermutete_Hoehenstabilitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_vermutete_Hoehenstabilitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_vermutete_Hoehenstabilitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_vermutete_Hoehenstabilitaet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_vermutete_Hoehenstabilitaet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_vermutete_Hoehenstabilitaet( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_vermutete_Hoehenstabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_vermutete_Hoehenstabilitaet(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_vermutete_Hoehenstabilitaet(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_vermutete_Hoehenstabilitaet(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_vermutete_Hoehenstabilitaet(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_vermutete_Hoehenstabilitaet(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Guete_des_Vermarkungstraegers

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Guete_des_Vermarkungstraegers( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Guete_des_Vermarkungstraegers( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Guete_des_Vermarkungstraegers( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Guete_des_Vermarkungstraegers( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Guete_des_Vermarkungstraegers( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Guete_des_Vermarkungstraegers( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Guete_des_Vermarkungstraegers( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Guete_des_Vermarkungstraegers(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Guete_des_Vermarkungstraegers(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Guete_des_Vermarkungstraegers(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Guete_des_Vermarkungstraegers(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Guete_des_Vermarkungstraegers(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Guete_des_Vermarkungstraegers(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Topographie_und_Umwelt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Topographie_und_Umwelt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Topographie_und_Umwelt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Topographie_und_Umwelt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Topographie_und_Umwelt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Topographie_und_Umwelt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Topographie_und_Umwelt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Topographie_und_Umwelt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Topographie_und_Umwelt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Topographie_und_Umwelt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Topographie_und_Umwelt(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Topographie_und_Umwelt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Topographie_und_Umwelt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Topographie_und_Umwelt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Guete_des_Baugrundes

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Guete_des_Baugrundes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Guete_des_Baugrundes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Guete_des_Baugrundes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Guete_des_Baugrundes( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Guete_des_Baugrundes( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Guete_des_Baugrundes( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Guete_des_Baugrundes( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Guete_des_Baugrundes(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Guete_des_Baugrundes(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Guete_des_Baugrundes(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Guete_des_Baugrundes(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Guete_des_Baugrundes(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Guete_des_Baugrundes(const Version& vsn, const Text& key, Text& value, const int& nVal);

// geologische_Stabilitaet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_geologische_Stabilitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_geologische_Stabilitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_geologische_Stabilitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_geologische_Stabilitaet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_geologische_Stabilitaet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_geologische_Stabilitaet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_geologische_Stabilitaet( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_geologische_Stabilitaet(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_geologische_Stabilitaet(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_geologische_Stabilitaet(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_geologische_Stabilitaet(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_geologische_Stabilitaet(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_geologische_Stabilitaet(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grundwasserstand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundwasserstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundwasserstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundwasserstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Grundwasserstand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundwasserstand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundwasserstand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundwasserstand( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Grundwasserstand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Grundwasserstand(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Grundwasserstand(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Grundwasserstand(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Grundwasserstand(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Grundwasserstand(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grundwasserschwankung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundwasserschwankung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundwasserschwankung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundwasserschwankung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Grundwasserschwankung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundwasserschwankung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundwasserschwankung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundwasserschwankung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Grundwasserschwankung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Grundwasserschwankung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Grundwasserschwankung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Grundwasserschwankung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Grundwasserschwankung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Grundwasserschwankung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Hoehenstabilitaet_aus_Wdhmessg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenstabilitaet_aus_Wdhmessg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenstabilitaet_aus_Wdhmessg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenstabilitaet_aus_Wdhmessg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hoehenstabilitaet_aus_Wdhmessg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenstabilitaet_aus_Wdhmessg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenstabilitaet_aus_Wdhmessg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenstabilitaet_aus_Wdhmessg( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Hoehenstabilitaet_aus_Wdhmessg(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Hoehenstabilitaet_aus_Wdhmessg(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Hoehenstabilitaet_aus_Wdhmessg(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Hoehenstabilitaet_aus_Wdhmessg(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Hoehenstabilitaet_aus_Wdhmessg(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Hoehenstabilitaet_aus_Wdhmessg(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Punktnummer_SBV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktnummer_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktnummer_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktnummer_SBV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktnummer_SBV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktnummer_SBV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktnummer_SBV( const Objektart& oa, const Version& version );

// AFIS_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AFIS_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AFIS_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AFIS_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AFIS_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AFIS_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AFIS_Punkt( const Objektart& oa, const Version& version );

// Ordnung_TP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ordnung_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ordnung_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ordnung_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ordnung_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ordnung_TP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ordnung_TP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ordnung_TP( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ordnung_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ordnung_TP(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ordnung_TP(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ordnung_TP(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ordnung_TP(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ordnung_TP(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Hierarchiestufe_TP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hierarchiestufe_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hierarchiestufe_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hierarchiestufe_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hierarchiestufe_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hierarchiestufe_TP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hierarchiestufe_TP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hierarchiestufe_TP( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Hierarchiestufe_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Hierarchiestufe_TP(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Hierarchiestufe_TP(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Hierarchiestufe_TP(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Hierarchiestufe_TP(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Hierarchiestufe_TP(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wertigkeit_TP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wertigkeit_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wertigkeit_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wertigkeit_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wertigkeit_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wertigkeit_TP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wertigkeit_TP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wertigkeit_TP( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Wertigkeit_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Wertigkeit_TP(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Wertigkeit_TP(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Wertigkeit_TP(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Wertigkeit_TP(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Wertigkeit_TP(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_TP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_TP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_TP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_TP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_TP( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_TP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_TP(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Funktion_TP(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_TP(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_TP(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_TP(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ordnung_NivP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ordnung_NivP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ordnung_NivP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ordnung_NivP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ordnung_NivP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ordnung_NivP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ordnung_NivP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ordnung_NivP( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ordnung_NivP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ordnung_NivP(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ordnung_NivP(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ordnung_NivP(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ordnung_NivP(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ordnung_NivP(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Funktion_RSP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Funktion_RSP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Funktion_RSP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Funktion_RSP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Funktion_RSP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Funktion_RSP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Funktion_RSP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Funktion_RSP( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Funktion_RSP(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Funktion_RSP(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Funktion_RSP(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Funktion_RSP(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Funktion_RSP(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Funktion_RSP(const Version& vsn, const Text& key, Text& value, const int& nVal);

// GPS_Empfaenger

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GPS_Empfaenger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GPS_Empfaenger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GPS_Empfaenger( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GPS_Empfaenger( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GPS_Empfaenger( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GPS_Empfaenger( const Objektart& oa, const Version& version );

// GPS_Antenne

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_GPS_Antenne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_GPS_Antenne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_GPS_Antenne( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_GPS_Antenne( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_GPS_Antenne( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_GPS_Antenne( const Objektart& oa, const Version& version );

// PCV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_PCV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_PCV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_PCV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_PCV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_PCV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_PCV( const Objektart& oa, const Version& version );

// LV_Flurstuecksdetails

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_LV_Flurstuecksdetails( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_LV_Flurstuecksdetails( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_LV_Flurstuecksdetails( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_LV_Flurstuecksdetails( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_LV_Flurstuecksdetails( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_LV_Flurstuecksdetails( const Objektart& oa, const Version& version );

// LV_Vermoegensgruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_LV_Vermoegensgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_LV_Vermoegensgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_LV_Vermoegensgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_LV_Vermoegensgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_LV_Vermoegensgruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_LV_Vermoegensgruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_LV_Vermoegensgruppe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_LV_Vermoegensgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_LV_Vermoegensgruppe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_LV_Vermoegensgruppe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_LV_Vermoegensgruppe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_LV_Vermoegensgruppe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_LV_Vermoegensgruppe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// LV_GEStand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_LV_GEStand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_LV_GEStand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_LV_GEStand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_LV_GEStand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_LV_GEStand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_LV_GEStand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_LV_GEStand( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_LV_GEStand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_LV_GEStand(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_LV_GEStand(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_LV_GEStand(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_LV_GEStand(const Version& vsn, const Text& key, Text& value, const int& nVal);

// LV_GEArt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_LV_GEArt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_LV_GEArt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_LV_GEArt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_LV_GEArt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_LV_GEArt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_LV_GEArt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_LV_GEArt( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_LV_GEArt(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_LV_GEArt(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_LV_GEArt(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_LV_GEArt(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_LV_GEArt(const Version& vsn, const Text& key, Text& value, const int& nVal);

// LV_Behoerde

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_LV_Behoerde( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_LV_Behoerde( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_LV_Behoerde( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_LV_Behoerde( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_LV_Behoerde( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_LV_Behoerde( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_LV_Behoerde( const Objektart& oa, const Version& version );

// LV_Gebuehren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_LV_Gebuehren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_LV_Gebuehren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_LV_Gebuehren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_LV_Gebuehren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_LV_Gebuehren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_LV_Gebuehren( const Objektart& oa, const Version& version );

// besondere_Flurstuecksgrenze

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_besondere_Flurstuecksgrenze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_besondere_Flurstuecksgrenze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_besondere_Flurstuecksgrenze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_besondere_Flurstuecksgrenze( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_besondere_Flurstuecksgrenze( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_besondere_Flurstuecksgrenze( const Objektart& oa, const Version& version );

// Grenzpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grenzpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grenzpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grenzpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grenzpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grenzpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grenzpunkt( const Objektart& oa, const Version& version );

// ALKIS_Objekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ALKIS_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ALKIS_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ALKIS_Objekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ALKIS_Objekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ALKIS_Objekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ALKIS_Objekt( const Objektart& oa, const Version& version );

// Flurstueck_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flurstueck_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flurstueck_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flurstueck_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flurstueck_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flurstueck_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flurstueck_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Flurstueck_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Flurstueck_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flurstueck_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flurstueck_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flurstueck_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flurstueck_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flurstueck_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flurstueck_abstrakt( const Objektart& oa, const Version& version );

// Trasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Trasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Trasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Trasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Trasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Trasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Trasse( const Objektart& oa, const Version& version );

// Achse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achse( const Objektart& oa, const Version& version );

// Achselement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achselement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achselement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achselement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achselement( const Objektart& oa, const Version& version );

// Linienelementtyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Linienelementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Linienelementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Linienelementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Linienelementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Linienelementtyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Linienelementtyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Linienelementtyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Linienelementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Linienelementtyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Linienelementtyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Linienelementtyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Linienelementtyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Linienelementtyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Achselementtyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achselementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achselementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achselementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Achselementtyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achselementtyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achselementtyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achselementtyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Achselementtyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Achselementtyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Achselementtyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Achselementtyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Achselementtyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Achselementtyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Achselementpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achselementpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achselementpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achselementpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achselementpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achselementpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achselementpunkt( const Objektart& oa, const Version& version );

// Kreuzungs_o_Einmuendungsplang

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreuzungs_o_Einmuendungsplang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreuzungs_o_Einmuendungsplang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreuzungs_o_Einmuendungsplang( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreuzungs_o_Einmuendungsplang( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreuzungs_o_Einmuendungsplang( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreuzungs_o_Einmuendungsplang( const Objektart& oa, const Version& version );

// DGM

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_DGM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_DGM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_DGM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_DGM( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_DGM( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_DGM( const Objektart& oa, const Version& version );

// Laengsschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Laengsschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Laengsschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Laengsschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Laengsschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Laengsschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Laengsschnitt( const Objektart& oa, const Version& version );

// Gelaendehorizonte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gelaendehorizonte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gelaendehorizonte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gelaendehorizonte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gelaendehorizonte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gelaendehorizonte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gelaendehorizonte( const Objektart& oa, const Version& version );

// Gradiente

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gradiente( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gradiente( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gradiente( const Objektart& oa, const Version& version );

// kreuzende_Bauwerke_o_baul_Anl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_kreuzende_Bauwerke_o_baul_Anl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_kreuzende_Bauwerke_o_baul_Anl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_kreuzende_Bauwerke_o_baul_Anl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_kreuzende_Bauwerke_o_baul_Anl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_kreuzende_Bauwerke_o_baul_Anl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_kreuzende_Bauwerke_o_baul_Anl( const Objektart& oa, const Version& version );

// Tunnel_Kanal_Strasse_Durchlass

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tunnel_Kanal_Strasse_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tunnel_Kanal_Strasse_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tunnel_Kanal_Strasse_Durchlass( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tunnel_Kanal_Strasse_Durchlass( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tunnel_Kanal_Strasse_Durchlass( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tunnel_Kanal_Strasse_Durchlass( const Objektart& oa, const Version& version );

// Schnittgeometrie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schnittgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schnittgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schnittgeometrie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schnittgeometrie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schnittgeometrie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schnittgeometrie( const Objektart& oa, const Version& version );

// Schnittpolygone

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schnittpolygone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schnittpolygone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schnittpolygone( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schnittpolygone( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schnittpolygone( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schnittpolygone( const Objektart& oa, const Version& version );

// Mindestabstandspolygon

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Mindestabstandspolygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Mindestabstandspolygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Mindestabstandspolygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Mindestabstandspolygon( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Mindestabstandspolygon( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Mindestabstandspolygon( const Objektart& oa, const Version& version );

// Maximalabstandspolygon

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Maximalabstandspolygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Maximalabstandspolygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Maximalabstandspolygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Maximalabstandspolygon( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Maximalabstandspolygon( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Maximalabstandspolygon( const Objektart& oa, const Version& version );

// Polygon

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Polygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Polygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Polygon( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Polygon( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Polygon( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Polygon( const Objektart& oa, const Version& version );

// Polygonpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Polygonpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Polygonpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Polygonpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Polygonpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Polygonpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Polygonpunkt( const Objektart& oa, const Version& version );

// Laengsschnittlinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Laengsschnittlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Laengsschnittlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Laengsschnittlinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Laengsschnittlinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Laengsschnittlinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Laengsschnittlinie( const Objektart& oa, const Version& version );

// LS_Koor

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_LS_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_LS_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_LS_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_LS_Koor( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_LS_Koor( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_LS_Koor( const Objektart& oa, const Version& version );

// Punktfolge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktfolge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktfolge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktfolge( const Objektart& oa, const Version& version );

// Tangentenfolge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tangentenfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tangentenfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tangentenfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tangentenfolge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tangentenfolge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tangentenfolge( const Objektart& oa, const Version& version );

// Ausrundung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausrundung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausrundung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausrundung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ausrundung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausrundung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausrundung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausrundung( const Objektart& oa, const Version& version );

// Ausrundungstyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausrundungstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausrundungstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausrundungstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ausrundungstyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausrundungstyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausrundungstyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausrundungstyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ausrundungstyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ausrundungstyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ausrundungstyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ausrundungstyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ausrundungstyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ausrundungstyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tangente_Gerade

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tangente_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tangente_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tangente_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tangente_Gerade( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tangente_Gerade( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tangente_Gerade( const Objektart& oa, const Version& version );

// Volumen_Massenermittlung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Volumen_Massenermittlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Volumen_Massenermittlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Volumen_Massenermittlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Volumen_Massenermittlung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Volumen_Massenermittlung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Volumen_Massenermittlung( const Objektart& oa, const Version& version );

// Oberflaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Oberflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Oberflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Oberflaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Oberflaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Oberflaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Oberflaeche( const Objektart& oa, const Version& version );

// Trassenkoerper

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Trassenkoerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Trassenkoerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Trassenkoerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Trassenkoerper( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Trassenkoerper( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Trassenkoerper( const Objektart& oa, const Version& version );

// Querprofil

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Querprofil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Querprofil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Querprofil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Querprofil( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Querprofil( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Querprofil( const Objektart& oa, const Version& version );

// Bildungsgesetze

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bildungsgesetze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bildungsgesetze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bildungsgesetze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bildungsgesetze( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bildungsgesetze( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bildungsgesetze( const Objektart& oa, const Version& version );

// Ausgangsdaten_Bildungsgesetze

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausgangsdaten_Bildungsgesetze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausgangsdaten_Bildungsgesetze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausgangsdaten_Bildungsgesetze( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausgangsdaten_Bildungsgesetze( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausgangsdaten_Bildungsgesetze( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausgangsdaten_Bildungsgesetze( const Objektart& oa, const Version& version );

// Ausgangsdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausgangsdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausgangsdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausgangsdaten( const Objektart& oa, const Version& version );

// Hoehenzuege

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehenzuege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehenzuege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehenzuege( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehenzuege( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehenzuege( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehenzuege( const Objektart& oa, const Version& version );

// QP_Punkte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_QP_Punkte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_QP_Punkte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_QP_Punkte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_QP_Punkte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_QP_Punkte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_QP_Punkte( const Objektart& oa, const Version& version );

// Querprofilpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Querprofilpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Querprofilpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Querprofilpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Querprofilpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Querprofilpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Querprofilpunkt( const Objektart& oa, const Version& version );

// Profillinien

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Profillinien( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Profillinien( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Profillinien( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Profillinien( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Profillinien( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Profillinien( const Objektart& oa, const Version& version );

// Schnittebene

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Schnittebene( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Schnittebene( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Schnittebene( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Schnittebene( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Schnittebene( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Schnittebene( const Objektart& oa, const Version& version );

// SNT_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_SNT_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_SNT_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_SNT_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_SNT_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_SNT_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_SNT_Punkt( const Objektart& oa, const Version& version );

// Deckenbuch

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Deckenbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Deckenbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Deckenbuch( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Deckenbuch( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Deckenbuch( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Deckenbuch( const Objektart& oa, const Version& version );

// Spurfolge_Ausgangsdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Spurfolge_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Spurfolge_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Spurfolge_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Spurfolge_Ausgangsdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Spurfolge_Ausgangsdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Spurfolge_Ausgangsdaten( const Objektart& oa, const Version& version );

// Spur_aus_Ausgangsdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Spur_aus_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Spur_aus_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Spur_aus_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Spur_aus_Ausgangsdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Spur_aus_Ausgangsdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Spur_aus_Ausgangsdaten( const Objektart& oa, const Version& version );

// Spur_aus_Querprofilen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Spur_aus_Querprofilen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Spur_aus_Querprofilen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Spur_aus_Querprofilen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Spur_aus_Querprofilen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Spur_aus_Querprofilen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Spur_aus_Querprofilen( const Objektart& oa, const Version& version );

// Parallele_Breite_z_Achse_zwei

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Parallele_Breite_z_Achse_zwei( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Parallele_Breite_z_Achse_zwei( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Parallele_Breite_z_Achse_zwei( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Parallele_Breite_z_Achse_zwei( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Parallele_Breite_z_Achse_zwei( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Parallele_Breite_z_Achse_zwei( const Objektart& oa, const Version& version );

// Parallele_Breite_z_Achse_eins

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Parallele_Breite_z_Achse_eins( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Parallele_Breite_z_Achse_eins( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Parallele_Breite_z_Achse_eins( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Parallele_Breite_z_Achse_eins( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Parallele_Breite_z_Achse_eins( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Parallele_Breite_z_Achse_eins( const Objektart& oa, const Version& version );

// Breite

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Breite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Breite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Breite( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Breite( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Breite( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Breite( const Objektart& oa, const Version& version );

// BR_Punktfolge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_BR_Punktfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_BR_Punktfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_BR_Punktfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_BR_Punktfolge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_BR_Punktfolge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_BR_Punktfolge( const Objektart& oa, const Version& version );

// BR_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_BR_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_BR_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_BR_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_BR_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_BR_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_BR_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_BR_Punkt( const Objektart& oa, const Version& version );

// Aufweitung_Verbreit_Verbind

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufweitung_Verbreit_Verbind( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufweitung_Verbreit_Verbind( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufweitung_Verbreit_Verbind( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Aufweitung_Verbreit_Verbind( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufweitung_Verbreit_Verbind( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufweitung_Verbreit_Verbind( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufweitung_Verbreit_Verbind( const Objektart& oa, const Version& version );

// Parabelfolge_zweiten_Grades

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Parabelfolge_zweiten_Grades( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Parabelfolge_zweiten_Grades( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Parabelfolge_zweiten_Grades( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Parabelfolge_zweiten_Grades( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Parabelfolge_zweiten_Grades( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Parabelfolge_zweiten_Grades( const Objektart& oa, const Version& version );

// Bogenfolge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bogenfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bogenfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bogenfolge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bogenfolge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bogenfolge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bogenfolge( const Objektart& oa, const Version& version );

// Parabelf_zw_Grades_zw_Gerade

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Parabelf_zw_Grades_zw_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Parabelf_zw_Grades_zw_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Parabelf_zw_Grades_zw_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Parabelf_zw_Grades_zw_Gerade( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Parabelf_zw_Grades_zw_Gerade( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Parabelf_zw_Grades_zw_Gerade( const Objektart& oa, const Version& version );

// Gerade

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gerade( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gerade( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gerade( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gerade( const Objektart& oa, const Version& version );

// Abstand_Achse_Achse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abstand_Achse_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abstand_Achse_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abstand_Achse_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Abstand_Achse_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abstand_Achse_Achse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abstand_Achse_Achse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abstand_Achse_Achse( const Objektart& oa, const Version& version );

// Abstand_Achse_Linie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abstand_Achse_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abstand_Achse_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abstand_Achse_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abstand_Achse_Linie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abstand_Achse_Linie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abstand_Achse_Linie( const Objektart& oa, const Version& version );

// Lage_der_Knicklinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_der_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_der_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_der_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_der_Knicklinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_der_Knicklinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_der_Knicklinie( const Objektart& oa, const Version& version );

// zweite_Achse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zweite_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zweite_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zweite_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zweite_Achse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zweite_Achse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zweite_Achse( const Objektart& oa, const Version& version );

// Naeherungsstation_auf_zw_Achse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Naeherungsstation_auf_zw_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Naeherungsstation_auf_zw_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Naeherungsstation_auf_zw_Achse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Naeherungsstation_auf_zw_Achse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Naeherungsstation_auf_zw_Achse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Naeherungsstation_auf_zw_Achse( const Objektart& oa, const Version& version );

// mittig_m_Abstand_z_Knicklinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_mittig_m_Abstand_z_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_mittig_m_Abstand_z_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_mittig_m_Abstand_z_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_mittig_m_Abstand_z_Knicklinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_mittig_m_Abstand_z_Knicklinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_mittig_m_Abstand_z_Knicklinie( const Objektart& oa, const Version& version );

// Querneigung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Querneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Querneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Querneigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Querneigung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Querneigung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Querneigung( const Objektart& oa, const Version& version );

// Querneigungswechsel

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Querneigungswechsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Querneigungswechsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Querneigungswechsel( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Querneigungswechsel( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Querneigungswechsel( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Querneigungswechsel( const Objektart& oa, const Version& version );

// Verziehungsform

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verziehungsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verziehungsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verziehungsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verziehungsform( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verziehungsform( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verziehungsform( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verziehungsform( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verziehungsform(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verziehungsform(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Verziehungsform(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verziehungsform(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verziehungsform(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verziehungsform(const Version& vsn, const Text& key, Text& value, const int& nVal);

// QN_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_QN_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_QN_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_QN_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_QN_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_QN_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_QN_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_QN_Punkt( const Objektart& oa, const Version& version );

// Spurbezeichnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Spurbezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Spurbezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Spurbezeichnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Spurbezeichnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Spurbezeichnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Spurbezeichnung( const Objektart& oa, const Version& version );

// Achsstationswerte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achsstationswerte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achsstationswerte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achsstationswerte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achsstationswerte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achsstationswerte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achsstationswerte( const Objektart& oa, const Version& version );

// AW_Koor

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_AW_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_AW_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_AW_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_AW_Koor( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_AW_Koor( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_AW_Koor( const Objektart& oa, const Version& version );

// Entwurfsparameter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Entwurfsparameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Entwurfsparameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Entwurfsparameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Entwurfsparameter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Entwurfsparameter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Entwurfsparameter( const Objektart& oa, const Version& version );

// Geschwindigkeitsband

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Geschwindigkeitsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Geschwindigkeitsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Geschwindigkeitsband( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Geschwindigkeitsband( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Geschwindigkeitsband( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Geschwindigkeitsband( const Objektart& oa, const Version& version );

// V_Koor

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_V_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_V_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_V_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_V_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_V_Koor( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_V_Koor( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_V_Koor( const Objektart& oa, const Version& version );

// Sichtweiten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Sichtweiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Sichtweiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Sichtweiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Sichtweiten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Sichtweiten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Sichtweiten( const Objektart& oa, const Version& version );

// SW_Koor

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_SW_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_SW_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_SW_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_SW_Koor( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_SW_Koor( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_SW_Koor( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_SW_Koor( const Objektart& oa, const Version& version );

// Volumen_aus_QP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Volumen_aus_QP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Volumen_aus_QP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Volumen_aus_QP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Volumen_aus_QP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Volumen_aus_QP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Volumen_aus_QP( const Objektart& oa, const Version& version );

// Hoehendifferenz

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehendifferenz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehendifferenz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehendifferenz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehendifferenz( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehendifferenz( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehendifferenz( const Objektart& oa, const Version& version );

// HD_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HD_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HD_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HD_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HD_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HD_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HD_Punkt( const Objektart& oa, const Version& version );

// Hochbord

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hochbord( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hochbord( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hochbord( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hochbord( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hochbord( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hochbord( const Objektart& oa, const Version& version );

// allgemeine_Eigenschaften

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_allgemeine_Eigenschaften( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_allgemeine_Eigenschaften( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_allgemeine_Eigenschaften( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_allgemeine_Eigenschaften( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_allgemeine_Eigenschaften( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_allgemeine_Eigenschaften( const Objektart& oa, const Version& version );

// Achshauptpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Achshauptpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Achshauptpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Achshauptpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Achshauptpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Achshauptpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Achshauptpunkt( const Objektart& oa, const Version& version );

// Art_der_Verziehung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Verziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Verziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Verziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Verziehung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Verziehung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Verziehung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Verziehung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Verziehung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Verziehung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Verziehung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Verziehung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Verziehung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Verziehung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Typ_der_Knicklinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_der_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_der_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_der_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_der_Knicklinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_der_Knicklinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_der_Knicklinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_der_Knicklinie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_der_Knicklinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_der_Knicklinie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Typ_der_Knicklinie(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_der_Knicklinie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_der_Knicklinie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_der_Knicklinie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// HZ_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HZ_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HZ_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HZ_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_HZ_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HZ_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HZ_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HZ_Punkt( const Objektart& oa, const Version& version );

// Hoehe_Gradiente

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehe_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehe_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehe_Gradiente( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehe_Gradiente( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehe_Gradiente( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehe_Gradiente( const Objektart& oa, const Version& version );

// Hoehe_Linie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hoehe_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hoehe_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hoehe_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hoehe_Linie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hoehe_Linie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hoehe_Linie( const Objektart& oa, const Version& version );

// HB_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HB_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HB_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HB_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_HB_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HB_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HB_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HB_Punkt( const Objektart& oa, const Version& version );

// HB_Neigung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_HB_Neigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_HB_Neigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_HB_Neigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_HB_Neigung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_HB_Neigung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_HB_Neigung( const Objektart& oa, const Version& version );

// dynamisches_Querprofil

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_dynamisches_Querprofil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_dynamisches_Querprofil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_dynamisches_Querprofil( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_dynamisches_Querprofil( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_dynamisches_Querprofil( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_dynamisches_Querprofil( const Objektart& oa, const Version& version );

// RQ_Code

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_RQ_Code( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_RQ_Code( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_RQ_Code( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_RQ_Code( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_RQ_Code( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_RQ_Code( const Objektart& oa, const Version& version );

// RQ_Code_Modul

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_RQ_Code_Modul( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_RQ_Code_Modul( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_RQ_Code_Modul( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_RQ_Code_Modul( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_RQ_Code_Modul( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_RQ_Code_Modul( const Objektart& oa, const Version& version );

// Zuordnung_Ausgangsdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zuordnung_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zuordnung_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zuordnung_Ausgangsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zuordnung_Ausgangsdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zuordnung_Ausgangsdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zuordnung_Ausgangsdaten( const Objektart& oa, const Version& version );

// Ausgangsdaten_QP

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausgangsdaten_QP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausgangsdaten_QP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausgangsdaten_QP( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausgangsdaten_QP( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausgangsdaten_QP( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausgangsdaten_QP( const Objektart& oa, const Version& version );

// Art_des_Horizonts

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_des_Horizonts( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_des_Horizonts( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_des_Horizonts( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_des_Horizonts( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_des_Horizonts( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_des_Horizonts( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_des_Horizonts( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_des_Horizonts(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_des_Horizonts(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_des_Horizonts(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_des_Horizonts(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_des_Horizonts(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_des_Horizonts(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenkategorie_RAS_L

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenkategorie_RAS_L( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenkategorie_RAS_L( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenkategorie_RAS_L( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenkategorie_RAS_L( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenkategorie_RAS_L( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenkategorie_RAS_L( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenkategorie_RAS_L( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Strassenkategorie_RAS_L(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Strassenkategorie_RAS_L(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Strassenkategorie_RAS_L(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Strassenkategorie_RAS_L(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Strassenkategorie_RAS_L(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Strassenkategorie_RAS_L(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Breitenberechnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Breitenberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Breitenberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Breitenberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Breitenberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Breitenberechnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Breitenberechnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Breitenberechnung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Breitenberechnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Breitenberechnung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Breitenberechnung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Breitenberechnung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Breitenberechnung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Breitenberechnung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// direct_position

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_direct_position( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_direct_position( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_direct_position( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_direct_position( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_direct_position( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_direct_position( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_direct_position( const Objektart& oa, const Version& version );

// Punktobjekt_Modell

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punktobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punktobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punktobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punktobjekt_Modell( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punktobjekt_Modell( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punktobjekt_Modell( const Objektart& oa, const Version& version );

// Linienobjekt_Modell

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Linienobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Linienobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Linienobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Linienobjekt_Modell( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Linienobjekt_Modell( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Linienobjekt_Modell( const Objektart& oa, const Version& version );

// Flaechenobjekt_Modell

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flaechenobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flaechenobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flaechenobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flaechenobjekt_Modell( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flaechenobjekt_Modell( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flaechenobjekt_Modell( const Objektart& oa, const Version& version );

// Volumenobjekt_Modell

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Volumenobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Volumenobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Volumenobjekt_Modell( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Volumenobjekt_Modell( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Volumenobjekt_Modell( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Volumenobjekt_Modell( const Objektart& oa, const Version& version );

// isolierter_Knoten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_isolierter_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_isolierter_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_isolierter_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_isolierter_Knoten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_isolierter_Knoten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_isolierter_Knoten( const Objektart& oa, const Version& version );

// nicht_isolierter_Knoten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_nicht_isolierter_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_nicht_isolierter_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_nicht_isolierter_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_nicht_isolierter_Knoten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_nicht_isolierter_Knoten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_nicht_isolierter_Knoten( const Objektart& oa, const Version& version );

// Knoten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Knoten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Knoten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Knoten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Knoten( const Objektart& oa, const Version& version );

// Kante

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kante( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kante( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kante( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kante( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kante( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kante( const Objektart& oa, const Version& version );

// Masche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Masche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Masche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Masche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Masche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Masche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Masche( const Objektart& oa, const Version& version );

// Koerper

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Koerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Koerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Koerper( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Koerper( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Koerper( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Koerper( const Objektart& oa, const Version& version );

// gerechneter_Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_gerechneter_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_gerechneter_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_gerechneter_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_gerechneter_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_gerechneter_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_gerechneter_Punkt( const Objektart& oa, const Version& version );

// Punkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Punkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Punkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Punkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Punkt( const Objektart& oa, const Version& version );

// Linie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Linie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Linie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Linie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Linie( const Objektart& oa, const Version& version );

// Flaechenelement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flaechenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flaechenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flaechenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flaechenelement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flaechenelement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flaechenelement( const Objektart& oa, const Version& version );

// komplexe_Flaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_komplexe_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_komplexe_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_komplexe_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_komplexe_Flaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_komplexe_Flaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_komplexe_Flaeche( const Objektart& oa, const Version& version );

// Flaeche

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Flaeche( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Flaeche( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Flaeche( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Flaeche( const Objektart& oa, const Version& version );

// Volumen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Volumen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Volumen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Volumen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Volumen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Volumen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Volumen( const Objektart& oa, const Version& version );

// Raumbezugsart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Raumbezugsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Raumbezugsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Raumbezugsart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Raumbezugsart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Raumbezugsart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Raumbezugsart( const Objektart& oa, const Version& version );

// Linienelement_Spline

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Linienelement_Spline( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Linienelement_Spline( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Linienelement_Spline( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Linienelement_Spline( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Linienelement_Spline( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Linienelement_Spline( const Objektart& oa, const Version& version );

// gerades_Linienelement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_gerades_Linienelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_gerades_Linienelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_gerades_Linienelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_gerades_Linienelement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_gerades_Linienelement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_gerades_Linienelement( const Objektart& oa, const Version& version );

// Kreisbogen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kreisbogen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kreisbogen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kreisbogen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kreisbogen( const Objektart& oa, const Version& version );

// Linienelement_3D

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Linienelement_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Linienelement_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Linienelement_3D( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Linienelement_3D( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Linienelement_3D( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Linienelement_3D( const Objektart& oa, const Version& version );

// Linie_Flaechenelement

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Linie_Flaechenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Linie_Flaechenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Linie_Flaechenelement( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Linie_Flaechenelement( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Linie_Flaechenelement( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Linie_Flaechenelement( const Objektart& oa, const Version& version );

// Linienfunktion

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Linienfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Linienfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Linienfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Linienfunktion( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Linienfunktion( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Linienfunktion( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Linienfunktion( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Linienfunktion(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Linienfunktion(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Linienfunktion(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Linienfunktion(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Linienfunktion(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Linienfunktion(const Version& vsn, const Text& key, Text& value, const int& nVal);

// tangentialer_Anschluss

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_tangentialer_Anschluss( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_tangentialer_Anschluss( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_tangentialer_Anschluss( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_tangentialer_Anschluss( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_tangentialer_Anschluss( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_tangentialer_Anschluss( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_tangentialer_Anschluss( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_tangentialer_Anschluss(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_tangentialer_Anschluss(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_tangentialer_Anschluss(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_tangentialer_Anschluss(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_tangentialer_Anschluss(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_tangentialer_Anschluss(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Koordinatenherkunft

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Koordinatenherkunft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Koordinatenherkunft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Koordinatenherkunft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Koordinatenherkunft( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Koordinatenherkunft( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Koordinatenherkunft( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Koordinatenherkunft( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Koordinatenherkunft(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Koordinatenherkunft(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Koordinatenherkunft(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Koordinatenherkunft(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Koordinatenherkunft(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Koordinatenherkunft(const Version& vsn, const Text& key, Text& value, const int& nVal);

// BoundingBox

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_BoundingBox( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_BoundingBox( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_BoundingBox( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_BoundingBox( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_BoundingBox( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_BoundingBox( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_BoundingBox( const Objektart& oa, const Version& version );

// Unfall

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfall( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfall( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfall( const Objektart& oa, const Version& version );

// Angaben_zum_Unfall

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zum_Unfall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zum_Unfall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zum_Unfall( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zum_Unfall( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zum_Unfall( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zum_Unfall( const Objektart& oa, const Version& version );

// Angaben_zur_Unfallzeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zur_Unfallzeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zur_Unfallzeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zur_Unfallzeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zur_Unfallzeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zur_Unfallzeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zur_Unfallzeit( const Objektart& oa, const Version& version );

// Unfallnummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallnummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallnummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallnummer( const Objektart& oa, const Version& version );

// Freiziffern

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Freiziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Freiziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Freiziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Freiziffern( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Freiziffern( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Freiziffern( const Objektart& oa, const Version& version );

// Angaben_zum_Unfallort

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zum_Unfallort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zum_Unfallort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zum_Unfallort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Angaben_zum_Unfallort( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zum_Unfallort( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zum_Unfallort( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zum_Unfallort( const Objektart& oa, const Version& version );

// Angaben_zur_einmuend_Strasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zur_einmuend_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zur_einmuend_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zur_einmuend_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zur_einmuend_Strasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zur_einmuend_Strasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zur_einmuend_Strasse( const Objektart& oa, const Version& version );

// Ortslage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ortslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ortslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ortslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Ortslage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ortslage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ortslage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ortslage( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Ortslage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Ortslage(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Ortslage(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Ortslage(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Ortslage(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Ortslage(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Unfallumstaende

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallumstaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallumstaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallumstaende( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallumstaende( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallumstaende( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallumstaende( const Objektart& oa, const Version& version );

// Witterungsverhaeltnisse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Witterungsverhaeltnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Witterungsverhaeltnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Witterungsverhaeltnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Witterungsverhaeltnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Witterungsverhaeltnisse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Witterungsverhaeltnisse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Witterungsverhaeltnisse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Witterungsverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Witterungsverhaeltnisse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Witterungsverhaeltnisse(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Witterungsverhaeltnisse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Witterungsverhaeltnisse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Witterungsverhaeltnisse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenzustand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenzustand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenzustand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenzustand( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Strassenzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Strassenzustand(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Strassenzustand(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Strassenzustand(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Strassenzustand(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Strassenzustand(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Strassenbefestigung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Strassenbefestigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Strassenbefestigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Strassenbefestigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Strassenbefestigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Strassenbefestigung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Strassenbefestigung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Strassenbefestigung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Strassenbefestigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Strassenbefestigung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Strassenbefestigung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Strassenbefestigung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Strassenbefestigung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Strassenbefestigung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lichtzeichenanlage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lichtzeichenanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lichtzeichenanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lichtzeichenanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lichtzeichenanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lichtzeichenanlage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lichtzeichenanlage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lichtzeichenanlage( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lichtzeichenanlage(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lichtzeichenanlage(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Lichtzeichenanlage(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lichtzeichenanlage(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lichtzeichenanlage(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lichtzeichenanlage(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lichtverhaeltnisse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lichtverhaeltnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lichtverhaeltnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lichtverhaeltnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lichtverhaeltnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lichtverhaeltnisse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lichtverhaeltnisse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lichtverhaeltnisse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lichtverhaeltnisse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lichtverhaeltnisse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Lichtverhaeltnisse(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lichtverhaeltnisse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lichtverhaeltnisse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lichtverhaeltnisse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Charakterist_der_Unfallstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Charakterist_der_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Charakterist_der_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Charakterist_der_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Charakterist_der_Unfallstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Charakterist_der_Unfallstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Charakterist_der_Unfallstelle( const Objektart& oa, const Version& version );

// Charakteristik_Unfst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Charakteristik_Unfst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Charakteristik_Unfst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Charakteristik_Unfst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Charakteristik_Unfst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Charakteristik_Unfst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Charakteristik_Unfst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Charakteristik_Unfst( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Charakteristik_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Charakteristik_Unfst(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Charakteristik_Unfst(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Charakteristik_Unfst(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Charakteristik_Unfst(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Charakteristik_Unfst(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Besonderheiten_d_Unfallstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Besonderheiten_d_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Besonderheiten_d_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Besonderheiten_d_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Besonderheiten_d_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Besonderheiten_d_Unfallstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Besonderheiten_d_Unfallstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Besonderheiten_d_Unfallstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Besonderheiten_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Besonderheiten_d_Unfallstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Besonderheiten_d_Unfallstelle(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Besonderheiten_d_Unfallstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Besonderheiten_d_Unfallstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Besonderheiten_d_Unfallstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Besonderheiten_Unfst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Besonderheiten_Unfst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Besonderheiten_Unfst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Besonderheiten_Unfst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Besonderheiten_Unfst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Besonderheiten_Unfst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Besonderheiten_Unfst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Besonderheiten_Unfst( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Besonderheiten_Unfst(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Besonderheiten_Unfst(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Besonderheiten_Unfst(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Besonderheiten_Unfst(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Besonderheiten_Unfst(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Besonderheiten_Unfst(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Beteiligte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Beteiligte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Beteiligte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Beteiligte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Beteiligte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Beteiligte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Beteiligte( const Objektart& oa, const Version& version );

// Geschlecht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Geschlecht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Geschlecht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Geschlecht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Geschlecht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Geschlecht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Geschlecht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Geschlecht( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Geschlecht(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Geschlecht(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Geschlecht(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Geschlecht(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Geschlecht(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Geschlecht(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Mitfahrerangaben

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Mitfahrerangaben( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Mitfahrerangaben( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Mitfahrerangaben( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Mitfahrerangaben( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Mitfahrerangaben( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Mitfahrerangaben( const Objektart& oa, const Version& version );

// Angaben_z_Alter_und_Geschlecht

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_z_Alter_und_Geschlecht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_z_Alter_und_Geschlecht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_z_Alter_und_Geschlecht( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_z_Alter_und_Geschlecht( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_z_Alter_und_Geschlecht( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_z_Alter_und_Geschlecht( const Objektart& oa, const Version& version );

// weitergehende_Angaben

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_weitergehende_Angaben( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_weitergehende_Angaben( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_weitergehende_Angaben( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_weitergehende_Angaben( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_weitergehende_Angaben( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_weitergehende_Angaben( const Objektart& oa, const Version& version );

// Art_der_Verletzung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Verletzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Verletzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Verletzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Verletzung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Verletzung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Verletzung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Verletzung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Verletzung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Verletzung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Verletzung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Verletzung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Verletzung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Verletzung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zur_Unfalleinteilung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zur_Unfalleinteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zur_Unfalleinteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zur_Unfalleinteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zur_Unfalleinteilung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zur_Unfalleinteilung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zur_Unfalleinteilung( const Objektart& oa, const Version& version );

// Aufprall_auf_Hindernis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Aufprall_auf_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Aufprall_auf_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Aufprall_auf_Hindernis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Aufprall_auf_Hindernis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Aufprall_auf_Hindernis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Aufprall_auf_Hindernis( const Objektart& oa, const Version& version );

// Hindernisart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hindernisart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hindernisart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hindernisart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Hindernisart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hindernisart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hindernisart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hindernisart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Hindernisart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Hindernisart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Hindernisart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Hindernisart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Hindernisart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Hindernisart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fahrzustand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahrzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrzustand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrzustand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrzustand( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahrzustand(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahrzustand(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Fahrzustand(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahrzustand(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahrzustand(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahrzustand(const Version& vsn, const Text& key, Text& value, const int& nVal);

// verwaltungstechn_Zuordnung_UO

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verwaltungstechn_Zuordnung_UO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verwaltungstechn_Zuordnung_UO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verwaltungstechn_Zuordnung_UO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verwaltungstechn_Zuordnung_UO( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verwaltungstechn_Zuordnung_UO( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verwaltungstechn_Zuordnung_UO( const Objektart& oa, const Version& version );

// oertliche_Zuordnung_UO

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_oertliche_Zuordnung_UO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_oertliche_Zuordnung_UO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_oertliche_Zuordnung_UO( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_oertliche_Zuordnung_UO( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_oertliche_Zuordnung_UO( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_oertliche_Zuordnung_UO( const Objektart& oa, const Version& version );

// Fahrtrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrtrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrtrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrtrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahrtrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrtrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrtrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrtrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahrtrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahrtrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Fahrtrichtung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahrtrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahrtrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahrtrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// kommunale_Strasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_kommunale_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_kommunale_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_kommunale_Strasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_kommunale_Strasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_kommunale_Strasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_kommunale_Strasse( const Objektart& oa, const Version& version );

// Unfallort_Strassenpunkt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallort_Strassenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallort_Strassenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallort_Strassenpunkt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallort_Strassenpunkt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallort_Strassenpunkt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallort_Strassenpunkt( const Objektart& oa, const Version& version );

// Angaben_zum_Unfallgeschehen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zum_Unfallgeschehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zum_Unfallgeschehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zum_Unfallgeschehen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zum_Unfallgeschehen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zum_Unfallgeschehen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zum_Unfallgeschehen( const Objektart& oa, const Version& version );

// Unfallart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Unfallart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Unfallart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Unfallart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Unfallart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Unfallart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Unfallart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Unfallart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Unfallursache

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallursache( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallursache( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallursache( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Unfallursache( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallursache( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallursache( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallursache( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Unfallursache(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Unfallursache(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Unfallursache(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Unfallursache(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Unfallursache(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Unfallursache(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Unfallkategorie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallkategorie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallkategorie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallkategorie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Unfallkategorie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallkategorie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallkategorie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallkategorie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Unfallkategorie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Unfallkategorie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Unfallkategorie(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Unfallkategorie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Unfallkategorie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Unfallkategorie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Unfalltyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfalltyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfalltyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfalltyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Unfalltyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfalltyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfalltyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfalltyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Unfalltyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Unfalltyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Unfalltyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Unfalltyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Unfalltyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Unfalltyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zu_Unfallumstaenden

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zu_Unfallumstaenden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zu_Unfallumstaenden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zu_Unfallumstaenden( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zu_Unfallumstaenden( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zu_Unfallumstaenden( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zu_Unfallumstaenden( const Objektart& oa, const Version& version );

// Charakteristik_d_Unfallstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Charakteristik_d_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Charakteristik_d_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Charakteristik_d_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Charakteristik_d_Unfallstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Charakteristik_d_Unfallstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Charakteristik_d_Unfallstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Charakteristik_d_Unfallstelle( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Charakteristik_d_Unfallstelle(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Charakteristik_d_Unfallstelle(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Charakteristik_d_Unfallstelle(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Charakteristik_d_Unfallstelle(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Charakteristik_d_Unfallstelle(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Charakteristik_d_Unfallstelle(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrsregelung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsregelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsregelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsregelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verkehrsregelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsregelung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsregelung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsregelung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verkehrsregelung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verkehrsregelung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Verkehrsregelung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verkehrsregelung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verkehrsregelung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verkehrsregelung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Witterung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Witterung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Witterung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Witterung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Witterung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Witterung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Witterung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Witterung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Witterung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Witterung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Witterung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Witterung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Witterung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Witterung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Verkehrsstufe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsstufe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsstufe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsstufe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verkehrsstufe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsstufe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsstufe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsstufe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verkehrsstufe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verkehrsstufe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Verkehrsstufe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verkehrsstufe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verkehrsstufe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verkehrsstufe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zu_Unfallbeteiligten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zu_Unfallbeteiligten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zu_Unfallbeteiligten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zu_Unfallbeteiligten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zu_Unfallbeteiligten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zu_Unfallbeteiligten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zu_Unfallbeteiligten( const Objektart& oa, const Version& version );

// Unfallbeteiligter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallbeteiligter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallbeteiligter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallbeteiligter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallbeteiligter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallbeteiligter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallbeteiligter( const Objektart& oa, const Version& version );

// Art_der_Verkehrsbeteiligung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Verkehrsbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Verkehrsbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Verkehrsbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_der_Verkehrsbeteiligung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Verkehrsbeteiligung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Verkehrsbeteiligung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Verkehrsbeteiligung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_der_Verkehrsbeteiligung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_der_Verkehrsbeteiligung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_der_Verkehrsbeteiligung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_der_Verkehrsbeteiligung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_der_Verkehrsbeteiligung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_der_Verkehrsbeteiligung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wohnsitz_Ausl

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wohnsitz_Ausl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wohnsitz_Ausl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wohnsitz_Ausl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wohnsitz_Ausl( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wohnsitz_Ausl( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wohnsitz_Ausl( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wohnsitz_Ausl( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Wohnsitz_Ausl(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Wohnsitz_Ausl(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Wohnsitz_Ausl(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Wohnsitz_Ausl(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Wohnsitz_Ausl(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Wohnsitz_Ausl(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Mitfahrer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Mitfahrer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Mitfahrer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Mitfahrer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Mitfahrer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Mitfahrer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Mitfahrer( const Objektart& oa, const Version& version );

// Unfallfahrzeug

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unfallfahrzeug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unfallfahrzeug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unfallfahrzeug( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unfallfahrzeug( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unfallfahrzeug( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unfallfahrzeug( const Objektart& oa, const Version& version );

// Gefahrklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gefahrklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gefahrklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gefahrklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gefahrklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gefahrklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gefahrklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gefahrklasse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gefahrklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gefahrklasse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gefahrklasse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gefahrklasse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gefahrklasse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Gefahrgutkennzeichen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gefahrgutkennzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gefahrgutkennzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gefahrgutkennzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Gefahrgutkennzeichen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gefahrgutkennzeichen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gefahrgutkennzeichen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gefahrgutkennzeichen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Gefahrgutkennzeichen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Gefahrgutkennzeichen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Gefahrgutkennzeichen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Gefahrgutkennzeichen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Gefahrgutkennzeichen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// DV_Merkmale_StaLa

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_DV_Merkmale_StaLa( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_DV_Merkmale_StaLa( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_DV_Merkmale_StaLa( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_DV_Merkmale_StaLa( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_DV_Merkmale_StaLa( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_DV_Merkmale_StaLa( const Objektart& oa, const Version& version );

// Verkehrsstaerkekennwerte

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsstaerkekennwerte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsstaerkekennwerte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsstaerkekennwerte( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsstaerkekennwerte( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsstaerkekennwerte( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsstaerkekennwerte( const Objektart& oa, const Version& version );

// Verkehrsstaerken

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsstaerken( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsstaerken( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsstaerken( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsstaerken( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsstaerken( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsstaerken( const Objektart& oa, const Version& version );

// Verkehrsstaerkeverteilung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verkehrsstaerkeverteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verkehrsstaerkeverteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verkehrsstaerkeverteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verkehrsstaerkeverteilung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verkehrsstaerkeverteilung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verkehrsstaerkeverteilung( const Objektart& oa, const Version& version );

// Tageswert_q

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tageswert_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tageswert_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tageswert_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tageswert_q( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tageswert_q( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tageswert_q( const Objektart& oa, const Version& version );

// Wochenganglinie_q

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wochenganglinie_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wochenganglinie_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wochenganglinie_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wochenganglinie_q( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wochenganglinie_q( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wochenganglinie_q( const Objektart& oa, const Version& version );

// Jahresganglinie_q

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Jahresganglinie_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Jahresganglinie_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Jahresganglinie_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Jahresganglinie_q( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Jahresganglinie_q( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Jahresganglinie_q( const Objektart& oa, const Version& version );

// Tagesganglinien_q

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tagesganglinien_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tagesganglinien_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tagesganglinien_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tagesganglinien_q( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tagesganglinien_q( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tagesganglinien_q( const Objektart& oa, const Version& version );

// Wochentagskennung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wochentagskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wochentagskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wochentagskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Wochentagskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wochentagskennung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wochentagskennung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wochentagskennung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Wochentagskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Wochentagskennung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Wochentagskennung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Wochentagskennung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Wochentagskennung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Wochentagskennung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wochentagsganglinien_q

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wochentagsganglinien_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wochentagsganglinien_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wochentagsganglinien_q( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wochentagsganglinien_q( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wochentagsganglinien_q( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wochentagsganglinien_q( const Objektart& oa, const Version& version );

// Tageszeitwert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tageszeitwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tageszeitwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tageszeitwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tageszeitwert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tageszeitwert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tageszeitwert( const Objektart& oa, const Version& version );

// Nachtzeitwert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Nachtzeitwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Nachtzeitwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Nachtzeitwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Nachtzeitwert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Nachtzeitwert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Nachtzeitwert( const Objektart& oa, const Version& version );

// alle_Tage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_alle_Tage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_alle_Tage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_alle_Tage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_alle_Tage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_alle_Tage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_alle_Tage( const Objektart& oa, const Version& version );

// werktags

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_werktags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_werktags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_werktags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_werktags( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_werktags( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_werktags( const Objektart& oa, const Version& version );

// sonn_und_feiertags

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_sonn_und_feiertags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_sonn_und_feiertags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_sonn_und_feiertags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_sonn_und_feiertags( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_sonn_und_feiertags( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_sonn_und_feiertags( const Objektart& oa, const Version& version );

// ferienwerktags

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_ferienwerktags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_ferienwerktags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_ferienwerktags( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_ferienwerktags( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_ferienwerktags( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_ferienwerktags( const Objektart& oa, const Version& version );

// Di_bis_Do

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Di_bis_Do( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Di_bis_Do( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Di_bis_Do( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Di_bis_Do( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Di_bis_Do( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Di_bis_Do( const Objektart& oa, const Version& version );

// zeitliches_Zuordnungskriterium

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_zeitliches_Zuordnungskriterium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_zeitliches_Zuordnungskriterium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_zeitliches_Zuordnungskriterium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_zeitliches_Zuordnungskriterium( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_zeitliches_Zuordnungskriterium( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_zeitliches_Zuordnungskriterium( const Objektart& oa, const Version& version );

// DTV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_DTV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_DTV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_DTV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_DTV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_DTV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_DTV( const Objektart& oa, const Version& version );

// MSV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_MSV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_MSV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_MSV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_MSV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_MSV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_MSV( const Objektart& oa, const Version& version );

// Anteil_am_DTV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anteil_am_DTV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anteil_am_DTV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anteil_am_DTV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anteil_am_DTV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anteil_am_DTV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anteil_am_DTV( const Objektart& oa, const Version& version );

// Fahrzeugart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrzeugart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrzeugart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrzeugart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahrzeugart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrzeugart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrzeugart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrzeugart( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahrzeugart(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahrzeugart(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Fahrzeugart(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahrzeugart(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahrzeugart(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahrzeugart(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fahrzeuggruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrzeuggruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrzeuggruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrzeuggruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahrzeuggruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrzeuggruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrzeuggruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrzeuggruppe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahrzeuggruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahrzeuggruppe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahrzeuggruppe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahrzeuggruppe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahrzeuggruppe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fahrzeugkollektiv

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrzeugkollektiv( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrzeugkollektiv( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrzeugkollektiv( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahrzeugkollektiv( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrzeugkollektiv( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrzeugkollektiv( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrzeugkollektiv( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahrzeugkollektiv(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahrzeugkollektiv(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahrzeugkollektiv(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahrzeugkollektiv(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahrzeugkollektiv(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fahrtzweckgruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrtzweckgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrtzweckgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrtzweckgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahrtzweckgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrtzweckgruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrtzweckgruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrtzweckgruppe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahrtzweckgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahrtzweckgruppe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahrtzweckgruppe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahrtzweckgruppe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahrtzweckgruppe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Normalzeitbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Normalzeitbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Normalzeitbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Normalzeitbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Normalzeitbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Normalzeitbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Normalzeitbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Normalzeitbereich( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Normalzeitbereich(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Normalzeitbereich(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Normalzeitbereich(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Normalzeitbereich(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Normalzeitbereich(const Version& vsn, const Text& key, Text& value, const int& nVal);

// weitere_Tagesgruppen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_weitere_Tagesgruppen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_weitere_Tagesgruppen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_weitere_Tagesgruppen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_weitere_Tagesgruppen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_weitere_Tagesgruppen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_weitere_Tagesgruppen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_weitere_Tagesgruppen( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_weitere_Tagesgruppen(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_weitere_Tagesgruppen(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_weitere_Tagesgruppen(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_weitere_Tagesgruppen(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_weitere_Tagesgruppen(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tagesgruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tagesgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tagesgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tagesgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tagesgruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tagesgruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tagesgruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tagesgruppe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tagesgruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tagesgruppe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tagesgruppe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tagesgruppe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tagesgruppe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Zaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaehlstelle( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_Zaehlstelle(const Version& vsn);

// Zaehlstelle_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaehlstelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaehlstelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaehlstelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaehlstelle_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaehlstelle_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaehlstelle_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_Zaehlstelle_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// Zaehlstelle_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaehlstelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaehlstelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaehlstelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zaehlstelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaehlstelle_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaehlstelle_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaehlstelle_abstrakt( const Objektart& oa, const Version& version );

// Kennwert_zur_Laermberechnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kennwert_zur_Laermberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kennwert_zur_Laermberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kennwert_zur_Laermberechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kennwert_zur_Laermberechnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kennwert_zur_Laermberechnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kennwert_zur_Laermberechnung( const Objektart& oa, const Version& version );

// Stundengruppe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Stundengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Stundengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Stundengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Stundengruppe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Stundengruppe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Stundengruppe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Stundengruppe( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Stundengruppe(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Stundengruppe(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Stundengruppe(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Stundengruppe(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Stundengruppe(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Stundengruppe(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Anteil_Kennwert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Anteil_Kennwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Anteil_Kennwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Anteil_Kennwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Anteil_Kennwert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Anteil_Kennwert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Anteil_Kennwert( const Objektart& oa, const Version& version );

// Jahresganglinientyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Jahresganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Jahresganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Jahresganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Jahresganglinientyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Jahresganglinientyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Jahresganglinientyp( const Objektart& oa, const Version& version );

// Typ_Jahresganglinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_Jahresganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_Jahresganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_Jahresganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_Jahresganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_Jahresganglinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_Jahresganglinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_Jahresganglinie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_Jahresganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_Jahresganglinie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_Jahresganglinie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_Jahresganglinie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_Jahresganglinie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Wochenganglinientyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Wochenganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Wochenganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Wochenganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Wochenganglinientyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Wochenganglinientyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Wochenganglinientyp( const Objektart& oa, const Version& version );

// Typ_Wochenganglinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_Wochenganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_Wochenganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_Wochenganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_Wochenganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_Wochenganglinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_Wochenganglinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_Wochenganglinie( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_Wochenganglinie(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_Wochenganglinie(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_Wochenganglinie(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_Wochenganglinie(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_Wochenganglinie(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Tagesganglinientyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tagesganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tagesganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tagesganglinientyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tagesganglinientyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tagesganglinientyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tagesganglinientyp( const Objektart& oa, const Version& version );

// Tagesgruppe_Typ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tagesgruppe_Typ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tagesgruppe_Typ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tagesgruppe_Typ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tagesgruppe_Typ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tagesgruppe_Typ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tagesgruppe_Typ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tagesgruppe_Typ( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tagesgruppe_Typ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tagesgruppe_Typ(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tagesgruppe_Typ(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tagesgruppe_Typ(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tagesgruppe_Typ(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tagesgruppe_Typ(const Version& vsn, const Text& key, Text& value, const int& nVal);

// DTV_Basis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_DTV_Basis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_DTV_Basis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_DTV_Basis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_DTV_Basis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_DTV_Basis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_DTV_Basis( const Objektart& oa, const Version& version );

// Ganglinie

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ganglinie( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ganglinie( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ganglinie( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ganglinie( const Objektart& oa, const Version& version );

// Intervall_Einheit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Intervall_Einheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Intervall_Einheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Intervall_Einheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Intervall_Einheit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Intervall_Einheit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Intervall_Einheit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Intervall_Einheit( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Intervall_Einheit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Intervall_Einheit(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Intervall_Einheit(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Intervall_Einheit(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Intervall_Einheit(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Intervall_Einheit(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Ganglinie_Punktobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ganglinie_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ganglinie_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ganglinie_Punktobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ganglinie_Punktobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ganglinie_Punktobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ganglinie_Punktobjekt( const Objektart& oa, const Version& version );

// Ganglinie_Bereichsobjekt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ganglinie_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ganglinie_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ganglinie_Bereichsobjekt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ganglinie_Bereichsobjekt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ganglinie_Bereichsobjekt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ganglinie_Bereichsobjekt( const Objektart& oa, const Version& version );

// Ganglinienwert

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ganglinienwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ganglinienwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ganglinienwert( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ganglinienwert( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ganglinienwert( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ganglinienwert( const Objektart& oa, const Version& version );

// manuelle_Zaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_manuelle_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_manuelle_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_manuelle_Zaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_manuelle_Zaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_manuelle_Zaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_manuelle_Zaehlstelle( const Objektart& oa, const Version& version );

// Erfassung_Gesamtverkehr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassung_Gesamtverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassung_Gesamtverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassung_Gesamtverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassung_Gesamtverkehr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassung_Gesamtverkehr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassung_Gesamtverkehr( const Objektart& oa, const Version& version );

// Erfassung_Auslaenderverkehr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassung_Auslaenderverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassung_Auslaenderverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassung_Auslaenderverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassung_Auslaenderverkehr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassung_Auslaenderverkehr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassung_Auslaenderverkehr( const Objektart& oa, const Version& version );

// Gueltigkeitsbereich_AV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Gueltigkeitsbereich_AV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Gueltigkeitsbereich_AV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Gueltigkeitsbereich_AV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Gueltigkeitsbereich_AV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Gueltigkeitsbereich_AV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Gueltigkeitsbereich_AV( const Objektart& oa, const Version& version );

// keine_Erfassung_AV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_keine_Erfassung_AV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_keine_Erfassung_AV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_keine_Erfassung_AV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_keine_Erfassung_AV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_keine_Erfassung_AV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_keine_Erfassung_AV( const Objektart& oa, const Version& version );

// verwaltungstechn_Zuordnung_MZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verwaltungstechn_Zuordnung_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verwaltungstechn_Zuordnung_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verwaltungstechn_Zuordnung_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verwaltungstechn_Zuordnung_MZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verwaltungstechn_Zuordnung_MZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verwaltungstechn_Zuordnung_MZ( const Objektart& oa, const Version& version );

// Verwaltungskennziffern

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verwaltungskennziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verwaltungskennziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verwaltungskennziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verwaltungskennziffern( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verwaltungskennziffern( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verwaltungskennziffern( const Objektart& oa, const Version& version );

// Hochrechnungsergebnisse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hochrechnungsergebnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hochrechnungsergebnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hochrechnungsergebnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hochrechnungsergebnisse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hochrechnungsergebnisse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hochrechnungsergebnisse( const Objektart& oa, const Version& version );

// Charakteristik

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Charakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Charakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Charakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Charakteristik( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Charakteristik( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Charakteristik( const Objektart& oa, const Version& version );

// Tab_Charakteristik

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Charakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Charakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Charakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Charakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Charakteristik( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Charakteristik( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Charakteristik( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Charakteristik(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Charakteristik(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Charakteristik(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Charakteristik(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Charakteristik(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Charakteristik(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lagekennung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lagekennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lagekennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lagekennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lagekennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lagekennung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lagekennung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lagekennung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lagekennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lagekennung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lagekennung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lagekennung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lagekennung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_z_Strassenquerschnitt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_z_Strassenquerschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_z_Strassenquerschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_z_Strassenquerschnitt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_z_Strassenquerschnitt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_z_Strassenquerschnitt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_z_Strassenquerschnitt( const Objektart& oa, const Version& version );

// Richtungskennung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Richtungskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Richtungskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Richtungskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Richtungskennung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Richtungskennung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Richtungskennung( const Objektart& oa, const Version& version );

// Tab_Richtungskennung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Tab_Richtungskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Tab_Richtungskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Tab_Richtungskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Tab_Richtungskennung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Tab_Richtungskennung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Tab_Richtungskennung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Tab_Richtungskennung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Tab_Richtungskennung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Tab_Richtungskennung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Tab_Richtungskennung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Tab_Richtungskennung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Tab_Richtungskennung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Tab_Richtungskennung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Bemerkungskennziffern

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bemerkungskennziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bemerkungskennziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bemerkungskennziffern( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bemerkungskennziffern( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bemerkungskennziffern( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bemerkungskennziffern( const Objektart& oa, const Version& version );

// Kennziffer_1

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kennziffer_1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kennziffer_1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kennziffer_1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kennziffer_1( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kennziffer_1( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kennziffer_1( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kennziffer_1( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kennziffer_1(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kennziffer_1(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Kennziffer_1(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kennziffer_1(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kennziffer_1(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kennziffer_1(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Kennziffer_2

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kennziffer_2( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kennziffer_2( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kennziffer_2( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Kennziffer_2( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kennziffer_2( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kennziffer_2( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kennziffer_2( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Kennziffer_2(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Kennziffer_2(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Kennziffer_2(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Kennziffer_2(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Kennziffer_2(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Kennziffer_2(const Version& vsn, const Text& key, Text& value, const int& nVal);

// oertliche_Zuordnung_MZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_oertliche_Zuordnung_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_oertliche_Zuordnung_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_oertliche_Zuordnung_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_oertliche_Zuordnung_MZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_oertliche_Zuordnung_MZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_oertliche_Zuordnung_MZ( const Objektart& oa, const Version& version );

// benachbarte_Anschlussstellen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_benachbarte_Anschlussstellen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_benachbarte_Anschlussstellen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_benachbarte_Anschlussstellen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_benachbarte_Anschlussstellen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_benachbarte_Anschlussstellen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_benachbarte_Anschlussstellen( const Objektart& oa, const Version& version );

// Bezugszaehlstelle_Auslverkehr

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bezugszaehlstelle_Auslverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bezugszaehlstelle_Auslverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bezugszaehlstelle_Auslverkehr( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bezugszaehlstelle_Auslverkehr( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bezugszaehlstelle_Auslverkehr( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bezugszaehlstelle_Auslverkehr( const Objektart& oa, const Version& version );

// Bezugszaehlstelle_Gesamtverk

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Bezugszaehlstelle_Gesamtverk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Bezugszaehlstelle_Gesamtverk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Bezugszaehlstelle_Gesamtverk( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Bezugszaehlstelle_Gesamtverk( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Bezugszaehlstelle_Gesamtverk( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Bezugszaehlstelle_Gesamtverk( const Objektart& oa, const Version& version );

// Angaben_zur_letzten_Zaehlung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zur_letzten_Zaehlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zur_letzten_Zaehlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zur_letzten_Zaehlung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zur_letzten_Zaehlung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zur_letzten_Zaehlung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zur_letzten_Zaehlung( const Objektart& oa, const Version& version );

// manuelle_Zaehlstelle_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_manuelle_Zaehlstelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_manuelle_Zaehlstelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_manuelle_Zaehlstelle_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_manuelle_Zaehlstelle_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_manuelle_Zaehlstelle_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_manuelle_Zaehlstelle_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_manuelle_Zaehlstelle_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// manuelle_Zaehlstelle_SVZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_manuelle_Zaehlstelle_SVZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_manuelle_Zaehlstelle_SVZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_manuelle_Zaehlstelle_SVZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_manuelle_Zaehlstelle_SVZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_manuelle_Zaehlstelle_SVZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_manuelle_Zaehlstelle_SVZ( const Objektart& oa, const Version& version );

// manuelle_Zaehlstelle_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_manuelle_Zaehlstelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_manuelle_Zaehlstelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_manuelle_Zaehlstelle_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_manuelle_Zaehlstelle_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_manuelle_Zaehlstelle_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_manuelle_Zaehlstelle_abstrakt( const Objektart& oa, const Version& version );

// raeuml_Gueltigkeitsbereich_MZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_raeuml_Gueltigkeitsbereich_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_raeuml_Gueltigkeitsbereich_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_raeuml_Gueltigkeitsbereich_MZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_raeuml_Gueltigkeitsbereich_MZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_raeuml_Gueltigkeitsbereich_MZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_raeuml_Gueltigkeitsbereich_MZ( const Objektart& oa, const Version& version );

// automatische_Dauerzaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_automatische_Dauerzaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_automatische_Dauerzaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_automatische_Dauerzaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_automatische_Dauerzaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_automatische_Dauerzaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_automatische_Dauerzaehlstelle( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_automatische_Dauerzaehlstelle(const Version& vsn);

// Erfassungsergebnisse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungsergebnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungsergebnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungsergebnisse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungsergebnisse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungsergebnisse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungsergebnisse( const Objektart& oa, const Version& version );

// Erfassungscharakteristik

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungscharakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungscharakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungscharakteristik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungscharakteristik( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungscharakteristik( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungscharakteristik( const Objektart& oa, const Version& version );

// Zaehlintervallaenge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaehlintervallaenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaehlintervallaenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaehlintervallaenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zaehlintervallaenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaehlintervallaenge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaehlintervallaenge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaehlintervallaenge( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zaehlintervallaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zaehlintervallaenge(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zaehlintervallaenge(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zaehlintervallaenge(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zaehlintervallaenge(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zaehlintervallaenge(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fahrzeugartenunterscheidung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrzeugartenunterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrzeugartenunterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrzeugartenunterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrzeugartenunterscheidung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrzeugartenunterscheidung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrzeugartenunterscheidung( const Objektart& oa, const Version& version );

// Klassenunterscheidung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Klassenunterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Klassenunterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Klassenunterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Klassenunterscheidung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Klassenunterscheidung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Klassenunterscheidung( const Objektart& oa, const Version& version );

// Fahrzeugklasse

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrzeugklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrzeugklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrzeugklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahrzeugklasse( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrzeugklasse( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrzeugklasse( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrzeugklasse( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahrzeugklasse(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahrzeugklasse(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Fahrzeugklasse(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahrzeugklasse(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahrzeugklasse(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahrzeugklasse(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Methode_der_Unterscheidung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Methode_der_Unterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Methode_der_Unterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Methode_der_Unterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Methode_der_Unterscheidung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Methode_der_Unterscheidung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Methode_der_Unterscheidung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Methode_der_Unterscheidung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Methode_der_Unterscheidung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Methode_der_Unterscheidung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Methode_der_Unterscheidung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Methode_der_Unterscheidung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Methode_der_Unterscheidung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Methode_der_Unterscheidung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Differenzierung_der_Erfassung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Differenzierung_der_Erfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Differenzierung_der_Erfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Differenzierung_der_Erfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Differenzierung_der_Erfassung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Differenzierung_der_Erfassung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Differenzierung_der_Erfassung( const Objektart& oa, const Version& version );

// Fahrstreifenzuordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrstreifenzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrstreifenzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrstreifenzuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrstreifenzuordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrstreifenzuordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrstreifenzuordnung( const Objektart& oa, const Version& version );

// Fahrtrichtung_DE

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrtrichtung_DE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrtrichtung_DE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrtrichtung_DE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Fahrtrichtung_DE( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrtrichtung_DE( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrtrichtung_DE( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrtrichtung_DE( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Fahrtrichtung_DE(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Fahrtrichtung_DE(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Fahrtrichtung_DE(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Fahrtrichtung_DE(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Fahrtrichtung_DE(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Fahrtrichtung_DE(const Version& vsn, const Text& key, Text& value, const int& nVal);

// raeumliche_Differenzierung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_raeumliche_Differenzierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_raeumliche_Differenzierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_raeumliche_Differenzierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_raeumliche_Differenzierung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_raeumliche_Differenzierung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_raeumliche_Differenzierung( const Objektart& oa, const Version& version );

// Registrierung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Registrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Registrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Registrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Registrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Registrierung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Registrierung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Registrierung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Registrierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Registrierung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Registrierung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Registrierung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Registrierung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Registrierung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_registrierten_Daten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_registrierten_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_registrierten_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_registrierten_Daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_registrierten_Daten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_registrierten_Daten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_registrierten_Daten( const Objektart& oa, const Version& version );

// Datentyp

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Datentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Datentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Datentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Datentyp( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Datentyp( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Datentyp( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Datentyp( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Datentyp(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Datentyp(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Datentyp(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Datentyp(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Datentyp(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Datentyp(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Detektoren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detektoren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detektoren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detektoren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detektoren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detektoren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detektoren( const Objektart& oa, const Version& version );

// Detektorart

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detektorart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detektorart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detektorart( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detektorart( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detektorart( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detektorart( const Objektart& oa, const Version& version );

// Art_des_Detektors

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_des_Detektors( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_des_Detektors( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_des_Detektors( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_des_Detektors( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_des_Detektors( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_des_Detektors( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_des_Detektors( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_des_Detektors(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_des_Detektors(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_des_Detektors(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_des_Detektors(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_des_Detektors(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_des_Detektors(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Art_der_Registrierung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_der_Registrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_der_Registrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_der_Registrierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_der_Registrierung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_der_Registrierung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_der_Registrierung( const Objektart& oa, const Version& version );

// Registriermedium

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Registriermedium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Registriermedium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Registriermedium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Registriermedium( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Registriermedium( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Registriermedium( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Registriermedium( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Registriermedium(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Registriermedium(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Registriermedium(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Registriermedium(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Registriermedium(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Registriermedium(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Landesnummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Landesnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Landesnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Landesnummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Landesnummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Landesnummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Landesnummer( const Objektart& oa, const Version& version );

// Moegl_Einzelfahrzeugerfassung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Moegl_Einzelfahrzeugerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Moegl_Einzelfahrzeugerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Moegl_Einzelfahrzeugerfassung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Moegl_Einzelfahrzeugerfassung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Moegl_Einzelfahrzeugerfassung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Moegl_Einzelfahrzeugerfassung( const Objektart& oa, const Version& version );

// verwaltungstechn_Zuordnung_AD

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verwaltungstechn_Zuordnung_AD( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verwaltungstechn_Zuordnung_AD( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verwaltungstechn_Zuordnung_AD( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verwaltungstechn_Zuordnung_AD( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verwaltungstechn_Zuordnung_AD( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verwaltungstechn_Zuordnung_AD( const Objektart& oa, const Version& version );

// oertliche_Zuordnung_AD

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_oertliche_Zuordnung_AD( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_oertliche_Zuordnung_AD( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_oertliche_Zuordnung_AD( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_oertliche_Zuordnung_AD( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_oertliche_Zuordnung_AD( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_oertliche_Zuordnung_AD( const Objektart& oa, const Version& version );

// Richtungen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Richtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Richtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Richtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Richtungen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Richtungen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Richtungen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Richtungen( const Objektart& oa, const Version& version );

// Himmelsrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Himmelsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Himmelsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Himmelsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Himmelsrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Himmelsrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Himmelsrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Himmelsrichtung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Himmelsrichtung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Himmelsrichtung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Himmelsrichtung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Himmelsrichtung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Himmelsrichtung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Himmelsrichtung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Fahrstreifenzuteilung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Fahrstreifenzuteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Fahrstreifenzuteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Fahrstreifenzuteilung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Fahrstreifenzuteilung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Fahrstreifenzuteilung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Fahrstreifenzuteilung( const Objektart& oa, const Version& version );

// Unterzentrale_Verkehrsrechnerz

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Unterzentrale_Verkehrsrechnerz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Unterzentrale_Verkehrsrechnerz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Unterzentrale_Verkehrsrechnerz( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Unterzentrale_Verkehrsrechnerz( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Unterzentrale_Verkehrsrechnerz( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Unterzentrale_Verkehrsrechnerz( const Objektart& oa, const Version& version );

// Zuordnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zuordnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zuordnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zuordnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zuordnung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zuordnung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zuordnung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zuordnung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zuordnung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zuordnung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zuordnung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// autom_Dauerzaehlst_Symbol

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_autom_Dauerzaehlst_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_autom_Dauerzaehlst_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_autom_Dauerzaehlst_Symbol( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_autom_Dauerzaehlst_Symbol( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_autom_Dauerzaehlst_Symbol( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_autom_Dauerzaehlst_Symbol( const Objektart& oa, const Version& version );
#endif
OKLABI_SCHEMA_API static Text KennungErfragen_autom_Dauerzaehlst_Symbol(FachobjektPtr pObj, const Datum& stichtag, unsigned mode);
#ifdef OKLABI_PLAUSI

// autom_Dauerzaehlst_abstrakt

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_autom_Dauerzaehlst_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_autom_Dauerzaehlst_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_autom_Dauerzaehlst_abstrakt( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_autom_Dauerzaehlst_abstrakt( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_autom_Dauerzaehlst_abstrakt( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_autom_Dauerzaehlst_abstrakt( const Objektart& oa, const Version& version );

// Zaehlstellennummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaehlstellennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaehlstellennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaehlstellennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaehlstellennummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaehlstellennummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaehlstellennummer( const Objektart& oa, const Version& version );

// Art_Zaehlstellennummer

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Art_Zaehlstellennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Art_Zaehlstellennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Art_Zaehlstellennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Art_Zaehlstellennummer( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Art_Zaehlstellennummer( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Art_Zaehlstellennummer( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Art_Zaehlstellennummer( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Art_Zaehlstellennummer(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Art_Zaehlstellennummer(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Art_Zaehlstellennummer(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Art_Zaehlstellennummer(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Art_Zaehlstellennummer(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Art_Zaehlstellennummer(const Version& vsn, const Text& key, Text& value, const int& nVal);

// oertliche_Zuordnung_DZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_oertliche_Zuordnung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_oertliche_Zuordnung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_oertliche_Zuordnung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_oertliche_Zuordnung_DZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_oertliche_Zuordnung_DZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_oertliche_Zuordnung_DZ( const Objektart& oa, const Version& version );

// verwaltungstechn_Zuordnung_DZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verwaltungstechn_Zuordnung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verwaltungstechn_Zuordnung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verwaltungstechn_Zuordnung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verwaltungstechn_Zuordnung_DZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verwaltungstechn_Zuordnung_DZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verwaltungstechn_Zuordnung_DZ( const Objektart& oa, const Version& version );

// Erfassungstechnik

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungstechnik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungstechnik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungstechnik( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungstechnik( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungstechnik( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungstechnik( const Objektart& oa, const Version& version );

// Zaehlgeraet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaehlgeraet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaehlgeraet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaehlgeraet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaehlgeraet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaehlgeraet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaehlgeraet( const Objektart& oa, const Version& version );

// Erfassungsmerkmale_DZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungsmerkmale_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungsmerkmale_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungsmerkmale_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungsmerkmale_DZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungsmerkmale_DZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungsmerkmale_DZ( const Objektart& oa, const Version& version );

// Detektoren_DZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detektoren_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detektoren_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detektoren_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detektoren_DZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detektoren_DZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detektoren_DZ( const Objektart& oa, const Version& version );

// abgeleitete_Dauerzaehlstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_abgeleitete_Dauerzaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_abgeleitete_Dauerzaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_abgeleitete_Dauerzaehlstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_abgeleitete_Dauerzaehlstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_abgeleitete_Dauerzaehlstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_abgeleitete_Dauerzaehlstelle( const Objektart& oa, const Version& version );

OKLABI_SCHEMA_API static const Objektart* E_XMLNetzbezug_abgeleitete_Dauerzaehlstelle(const Version& vsn);

// Ableitung_DZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ableitung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ableitung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ableitung_DZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ableitung_DZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ableitung_DZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ableitung_DZ( const Objektart& oa, const Version& version );

// Ableitung_autom_Dauerzaehlst

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ableitung_autom_Dauerzaehlst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ableitung_autom_Dauerzaehlst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ableitung_autom_Dauerzaehlst( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ableitung_autom_Dauerzaehlst( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ableitung_autom_Dauerzaehlst( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ableitung_autom_Dauerzaehlst( const Objektart& oa, const Version& version );

// VBA_Wetterstation

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_VBA_Wetterstation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_VBA_Wetterstation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_VBA_Wetterstation( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_VBA_Wetterstation( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_VBA_Wetterstation( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_VBA_Wetterstation( const Objektart& oa, const Version& version );

// SWIS_GMA_Messstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_SWIS_GMA_Messstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_SWIS_GMA_Messstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_SWIS_GMA_Messstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_SWIS_GMA_Messstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_SWIS_GMA_Messstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_SWIS_GMA_Messstelle( const Objektart& oa, const Version& version );

// Umfeldmessstelle

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Umfeldmessstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Umfeldmessstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Umfeldmessstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Umfeldmessstelle( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Umfeldmessstelle( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Umfeldmessstelle( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Umfeldmessstelle( const Objektart& oa, const Version& version );

// Messdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Messdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Messdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Messdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Messdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Messdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Messdaten( const Objektart& oa, const Version& version );

// Erfassungsmodalitaeten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungsmodalitaeten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungsmodalitaeten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungsmodalitaeten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungsmodalitaeten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungsmodalitaeten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungsmodalitaeten( const Objektart& oa, const Version& version );

// Lage_der_Sensoren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lage_der_Sensoren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lage_der_Sensoren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lage_der_Sensoren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Lage_der_Sensoren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lage_der_Sensoren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lage_der_Sensoren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lage_der_Sensoren( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Lage_der_Sensoren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Lage_der_Sensoren(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Lage_der_Sensoren(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Lage_der_Sensoren(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Lage_der_Sensoren(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Lage_der_Sensoren(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Erfassungsbereich

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungsbereich( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungsbereich( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungsbereich( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungsbereich( const Objektart& oa, const Version& version );

// Zaehlzeitraum

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaehlzeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaehlzeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaehlzeitraum( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaehlzeitraum( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaehlzeitraum( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaehlzeitraum( const Objektart& oa, const Version& version );

// Detektoren_Umfelddatenerfassg

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Detektoren_Umfelddatenerfassg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Detektoren_Umfelddatenerfassg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Detektoren_Umfelddatenerfassg( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Detektoren_Umfelddatenerfassg( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Detektoren_Umfelddatenerfassg( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Detektoren_Umfelddatenerfassg( const Objektart& oa, const Version& version );

// Umfang_Umfelddaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Umfang_Umfelddaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Umfang_Umfelddaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Umfang_Umfelddaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Umfang_Umfelddaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Umfang_Umfelddaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Umfang_Umfelddaten( const Objektart& oa, const Version& version );

// Witterungsdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Witterungsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Witterungsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Witterungsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Witterungsdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Witterungsdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Witterungsdaten( const Objektart& oa, const Version& version );

// Umfelddaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Umfelddaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Umfelddaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Umfelddaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Umfelddaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Umfelddaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Umfelddaten( const Objektart& oa, const Version& version );

// witterungsbed_Strassenzustand

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_witterungsbed_Strassenzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_witterungsbed_Strassenzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_witterungsbed_Strassenzustand( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_witterungsbed_Strassenzustand( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_witterungsbed_Strassenzustand( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_witterungsbed_Strassenzustand( const Objektart& oa, const Version& version );

// verwaltungstechn_Zuordnung_UM

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_verwaltungstechn_Zuordnung_UM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_verwaltungstechn_Zuordnung_UM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_verwaltungstechn_Zuordnung_UM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_verwaltungstechn_Zuordnung_UM( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_verwaltungstechn_Zuordnung_UM( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_verwaltungstechn_Zuordnung_UM( const Objektart& oa, const Version& version );

// oertliche_Zuordnung_UM

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_oertliche_Zuordnung_UM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_oertliche_Zuordnung_UM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_oertliche_Zuordnung_UM( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_oertliche_Zuordnung_UM( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_oertliche_Zuordnung_UM( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_oertliche_Zuordnung_UM( const Objektart& oa, const Version& version );

// Zaehlintervalllaenge

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Zaehlintervalllaenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Zaehlintervalllaenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Zaehlintervalllaenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Zaehlintervalllaenge( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Zaehlintervalllaenge( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Zaehlintervalllaenge( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Zaehlintervalllaenge( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Zaehlintervalllaenge(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Zaehlintervalllaenge(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Zaehlintervalllaenge(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Zaehlintervalllaenge(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Zaehlintervalllaenge(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Zaehlintervalllaenge(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Lichtsignalanlage

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Lichtsignalanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Lichtsignalanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Lichtsignalanlage( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Lichtsignalanlage( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Lichtsignalanlage( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Lichtsignalanlage( const Objektart& oa, const Version& version );

// Rotlichtueberwachung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Rotlichtueberwachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Rotlichtueberwachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Rotlichtueberwachung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Rotlichtueberwachung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Rotlichtueberwachung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Rotlichtueberwachung( const Objektart& oa, const Version& version );

// Angaben_zum_Knotenpunkt_LSA

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zum_Knotenpunkt_LSA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zum_Knotenpunkt_LSA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zum_Knotenpunkt_LSA( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zum_Knotenpunkt_LSA( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zum_Knotenpunkt_LSA( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zum_Knotenpunkt_LSA( const Objektart& oa, const Version& version );

// Markierungspfeile

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Markierungspfeile( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Markierungspfeile( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Markierungspfeile( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Markierungspfeile( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Markierungspfeile( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Markierungspfeile( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Markierungspfeile( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Markierungspfeile(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Markierungspfeile(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Markierungspfeile(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Markierungspfeile(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Markierungspfeile(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Markierungspfeile(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Grundlage_und_Inbetriebn_daten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Grundlage_und_Inbetriebn_daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Grundlage_und_Inbetriebn_daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Grundlage_und_Inbetriebn_daten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Grundlage_und_Inbetriebn_daten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Grundlage_und_Inbetriebn_daten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Grundlage_und_Inbetriebn_daten( const Objektart& oa, const Version& version );

// Einsatzzeiten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Einsatzzeiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Einsatzzeiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Einsatzzeiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Einsatzzeiten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Einsatzzeiten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Einsatzzeiten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Einsatzzeiten( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Einsatzzeiten(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Einsatzzeiten(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Einsatzzeiten(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Einsatzzeiten(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Einsatzzeiten(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Einsatzzeiten(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zu_Verkehrsdaten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zu_Verkehrsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zu_Verkehrsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zu_Verkehrsdaten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zu_Verkehrsdaten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zu_Verkehrsdaten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zu_Verkehrsdaten( const Objektart& oa, const Version& version );

// Softwarekomponenten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Softwarekomponenten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Softwarekomponenten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Softwarekomponenten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Softwarekomponenten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Softwarekomponenten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Softwarekomponenten( const Objektart& oa, const Version& version );

// Signalprogrammparameter

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Signalprogrammparameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Signalprogrammparameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Signalprogrammparameter( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Signalprogrammparameter( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Signalprogrammparameter( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Signalprogrammparameter( const Objektart& oa, const Version& version );

// hinterlegte_Programme

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_hinterlegte_Programme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_hinterlegte_Programme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_hinterlegte_Programme( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_hinterlegte_Programme( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_hinterlegte_Programme( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_hinterlegte_Programme( const Objektart& oa, const Version& version );

// Auswahlverfahren

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Auswahlverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Auswahlverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Auswahlverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Auswahlverfahren( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Auswahlverfahren( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Auswahlverfahren( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Auswahlverfahren( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Auswahlverfahren(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Auswahlverfahren(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Auswahlverfahren(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Auswahlverfahren(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Auswahlverfahren(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Auswahlverfahren(const Version& vsn, const Text& key, Text& value, const int& nVal);

// OePNV_Berechtigung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_OePNV_Berechtigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_OePNV_Berechtigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_OePNV_Berechtigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_OePNV_Berechtigung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_OePNV_Berechtigung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_OePNV_Berechtigung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_OePNV_Berechtigung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_OePNV_Berechtigung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_OePNV_Berechtigung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_OePNV_Berechtigung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_OePNV_Berechtigung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_OePNV_Berechtigung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_OePNV_Berechtigung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Hardwarekomponenten

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Hardwarekomponenten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Hardwarekomponenten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Hardwarekomponenten( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Hardwarekomponenten( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Hardwarekomponenten( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Hardwarekomponenten( const Objektart& oa, const Version& version );

// akust_oder_taktile_Signalgeber

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_akust_oder_taktile_Signalgeber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_akust_oder_taktile_Signalgeber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_akust_oder_taktile_Signalgeber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_akust_oder_taktile_Signalgeber( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_akust_oder_taktile_Signalgeber( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_akust_oder_taktile_Signalgeber( const Objektart& oa, const Version& version );

// Position_SG

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Position_SG( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Position_SG( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Position_SG( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Position_SG( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Position_SG( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Position_SG( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Position_SG( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Position_SG(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Position_SG(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Position_SG(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Position_SG(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Position_SG(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Position_SG(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zum_Steuergeraet

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zum_Steuergeraet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zum_Steuergeraet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zum_Steuergeraet( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zum_Steuergeraet( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zum_Steuergeraet( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zum_Steuergeraet( const Objektart& oa, const Version& version );

// Koordinierung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Koordinierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Koordinierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Koordinierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Koordinierung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Koordinierung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Koordinierung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Koordinierung( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Koordinierung(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Koordinierung(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Koordinierung(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Koordinierung(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Koordinierung(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Koordinierung(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_zur_Verkabelung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_zur_Verkabelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_zur_Verkabelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_zur_Verkabelung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_zur_Verkabelung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_zur_Verkabelung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_zur_Verkabelung( const Objektart& oa, const Version& version );

// Verbindung_NK

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Verbindung_NK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Verbindung_NK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Verbindung_NK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Verbindung_NK( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Verbindung_NK( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Verbindung_NK( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Verbindung_NK( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Verbindung_NK(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Verbindung_NK(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Verbindung_NK(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Verbindung_NK(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Verbindung_NK(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Verbindung_NK(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Angaben_z_Aufstellvorrichtung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Angaben_z_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Angaben_z_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Angaben_z_Aufstellvorrichtung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Angaben_z_Aufstellvorrichtung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Angaben_z_Aufstellvorrichtung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Angaben_z_Aufstellvorrichtung( const Objektart& oa, const Version& version );

// optische_Signalgeber

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_optische_Signalgeber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_optische_Signalgeber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_optische_Signalgeber( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_optische_Signalgeber( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_optische_Signalgeber( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_optische_Signalgeber( const Objektart& oa, const Version& version );

// Erfassungseinrichtungen_IV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungseinrichtungen_IV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungseinrichtungen_IV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungseinrichtungen_IV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungseinrichtungen_IV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungseinrichtungen_IV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungseinrichtungen_IV( const Objektart& oa, const Version& version );

// Erfassungseinrichtungen_OeV

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Erfassungseinrichtungen_OeV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Erfassungseinrichtungen_OeV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Erfassungseinrichtungen_OeV( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Erfassungseinrichtungen_OeV( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Erfassungseinrichtungen_OeV( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Erfassungseinrichtungen_OeV( const Objektart& oa, const Version& version );

// uebergeordnete_Zentrale

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_uebergeordnete_Zentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_uebergeordnete_Zentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_uebergeordnete_Zentrale( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_uebergeordnete_Zentrale( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_uebergeordnete_Zentrale( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_uebergeordnete_Zentrale( const Objektart& oa, const Version& version );

// Typ_UeZ

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Typ_UeZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Typ_UeZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Typ_UeZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Typ_UeZ( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Typ_UeZ( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Typ_UeZ( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Typ_UeZ( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Typ_UeZ(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Typ_UeZ(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Typ_UeZ(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Typ_UeZ(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Typ_UeZ(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Typ_UeZ(const Version& vsn, const Text& key, Text& value, const int& nVal);

// Eingriffsmoeglichkeit

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Eingriffsmoeglichkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Eingriffsmoeglichkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Eingriffsmoeglichkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Pseudoinverse_Eingriffsmoeglichkeit( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Eingriffsmoeglichkeit( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Eingriffsmoeglichkeit( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Eingriffsmoeglichkeit( const Objektart& oa, const Version& version );
OKLABI_SCHEMA_API static void Init_10000_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10010_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10020_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10030_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10040_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10050_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10060_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10070_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10080_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10090_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10100_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10110_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10120_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10130_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10140_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static void Init_10150_Eingriffsmoeglichkeit(Sync::CriticalRegion& cr, KeyValueMapType*& pKeyMap);
OKLABI_SCHEMA_API static bool Hat_Ganzzahl_Schluessel_Eingriffsmoeglichkeit(const Version& vsn);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Int_Eingriffsmoeglichkeit(const Version& vsn, IntListe* keyList);
OKLABI_SCHEMA_API static void Gib_Schluesselwerte_Eingriffsmoeglichkeit(const Version& vsn, TextListe* keyList);
OKLABI_SCHEMA_API static void Gib_Langtexte_Eingriffsmoeglichkeit(const Version& vsn, TextListe* valList, const int& nVal);
OKLABI_SCHEMA_API static bool Gib_Langtext_Eingriffsmoeglichkeit(const Version& vsn, const Text& key, Text& value, const int& nVal);

// oertliche_Zuordnung_LS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_oertliche_Zuordnung_LS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_oertliche_Zuordnung_LS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_oertliche_Zuordnung_LS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_oertliche_Zuordnung_LS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_oertliche_Zuordnung_LS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_oertliche_Zuordnung_LS( const Objektart& oa, const Version& version );

// Projektressourcen

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Projektressourcen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Projektressourcen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Projektressourcen( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Projektressourcen( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Projektressourcen( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Projektressourcen( const Objektart& oa, const Version& version );

// Kostenberechnung_nach_AKS

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Kostenberechnung_nach_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Kostenberechnung_nach_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Kostenberechnung_nach_AKS( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Kostenberechnung_nach_AKS( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Kostenberechnung_nach_AKS( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Kostenberechnung_nach_AKS( const Objektart& oa, const Version& version );

// Ausschreibung_und_Vergabe

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Ausschreibung_und_Vergabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Ausschreibung_und_Vergabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Ausschreibung_und_Vergabe( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Ausschreibung_und_Vergabe( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Ausschreibung_und_Vergabe( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Ausschreibung_und_Vergabe( const Objektart& oa, const Version& version );

// Abrechnung

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Abrechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Abrechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Abrechnung( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Abrechnung( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Abrechnung( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Abrechnung( const Objektart& oa, const Version& version );

// Dokumentenverweis

OKLABI_SCHEMA_API static void E_Eigenschaftsnamen_Dokumentenverweis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_VirtuelleRelationen_Dokumentenverweis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static void E_Freunde_Dokumentenverweis( TextListe* sl, const Version& version, bool bClear );
OKLABI_SCHEMA_API static bool E_Eigenschaftsinfo_Dokumentenverweis( const Text& strNam, Eigenschaft& pInfo, const Version& version );
OKLABI_SCHEMA_API static void E_Klasseninfo_Dokumentenverweis( const Objektart& pInfo, const Version& version );
OKLABI_SCHEMA_API static bool KlassePruefen_Dokumentenverweis( const Objektart& oa, const Version& version );
#endif
};
} // Namespace Oklabi

