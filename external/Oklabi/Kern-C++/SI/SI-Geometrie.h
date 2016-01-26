/*****************************************************************************
* $Id: SI-Geometrie.h 2015-02-24 13:56:43 vogelsang $
* $Paket: Oklabi-Kern Schema $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2015, Bundesanstalt für Straßenwesen
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
* 2012-10-15 Aufräumen bei Programmende
* 2012-10-31 Stationskorrektur bei Teilabschnitten
* 2013-11-15 Geometriemethoden ergänzt
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2015-02-24 Referenzielles Geometrieformat(2)
*
****************************************************************************/
/* Change-Log:
*
* 13.01.2011  Code für Geometrie-Sammelmodul erstellt
*
* Version OKSTRA-Express: 2011-01-13, OKSTRA 1.000-1.015
* Version OKSTRA-Klassenbibliothek: 1.1.0
*
*/
namespace Oklabi
{
class SchemaGeo : public SchemaGeoWrapper
{
friend class Schema;
friend class SchemaGeoWrapper;
friend class XMLAusgabeKonverter;
friend class XMLEingabeKonverter;
friend class XMLAdapter;
private:
static double KorrigiereStation(double stat, FachobjektPtr AoAPtr, const GeoLinie* pGeometrie);
static bool IsRefGeo();
static bool DelExpressGeo(FachobjektPtr);
static void CollectRef(FachobjektPtr, const Text&, FachobjektPtr, FachobjektMengeImpl&, Geometrie*&);
static size_t CollectPointRef(FachobjektPtr, FachobjektPtr, FachobjektMengeImpl&, Geometrie*&);
static Geometrie* CollectGeo(FachobjektPtr, const Text&, Geometrie*);
static bool LocalInit();
static bool initialized;
static const char* GibExpressVersion();
static const char* GibOKLABIReleaseVersion();
static void BoundingBox_Dreieck(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Dreieck(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Gebaeude(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoRegion_Gebaeude(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Trasse(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Trasse(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Achse(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Achse(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Achselement(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Achselement(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Kreuzungs_o_Einmuendungsplang(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Kreuzungs_o_Einmuendungsplang(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Laengsschnitt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Laengsschnitt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Laengsschnittlinie(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Laengsschnittlinie(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_LS_Koor(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_LS_Koor(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Deckenbuch(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Deckenbuch(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_direct_position(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_direct_position(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Punktobjekt_Modell(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Punktobjekt_Modell(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Linienobjekt_Modell(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Linienobjekt_Modell(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Flaechenobjekt_Modell(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoRegion_Flaechenobjekt_Modell(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Punkt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Punkt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Linie(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Linie(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Flaechenelement(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoRegion_Flaechenelement(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_komplexe_Flaeche(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoRegion_komplexe_Flaeche(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Flaeche(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoRegion_Flaeche(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Linienelement_Spline(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Linienelement_Spline(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_gerades_Linienelement(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_gerades_Linienelement(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Kreisbogen(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Kreisbogen(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Zaehlstelle(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Zaehlstelle(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_manuelle_Zaehlstelle(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_manuelle_Zaehlstelle(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_manuelle_Zaehlstelle_SVZ(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_manuelle_Zaehlstelle_SVZ(FachobjektPtr pxo, const Datum& stag);
#endif
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_manuelle_Zaehlstelle_SVZ(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_automatische_Dauerzaehlstelle(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_automatische_Dauerzaehlstelle(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_abgeleitete_Dauerzaehlstelle(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_abgeleitete_Dauerzaehlstelle(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_oertliche_Zuordnung(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_oertliche_Zuordnung(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Schicht(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Schicht(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Querschnittstreifen(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Querschnittstreifen(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Streifenbegrenzung(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Streifenbegrenzung(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Fahrbahnlaengsneigung(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Fahrbahnlaengsneigung(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Fahrbahnquerneigung(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Fahrbahnquerneigung(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Durchlass(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Durchlass(FachobjektPtr pxo, const Datum& stag);
#endif
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Durchlass(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Bauwerk(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Bauwerk(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Teilbauwerk(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Teilbauwerk(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Sachverhalt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Sachverhalt(FachobjektPtr pxo, const Datum& stag);
#endif
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Sachverhalt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Bauwerk_Netzzuordnung(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Bauwerk_Netzzuordnung(FachobjektPtr pxo, const Datum& stag);
#endif
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Bauwerk_Netzzuordnung(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Verwaltungsbezirk(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoRegion_Verwaltungsbezirk(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Strasse(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Strasse(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Netzknoten(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Netzknoten(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Abschnitt_oder_Ast(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Abschnitt_oder_Ast(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Nullpunkt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Nullpunkt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Nullpunktsort(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Nullpunktsort(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Strassenpunkt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Strassenpunkt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_GDF_Verbindungspunkt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_GDF_Verbindungspunkt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Punktobjekt_hist(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Punktobjekt_hist(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Punktobjekt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Punktobjekt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Teilabschnitt_NB(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Teilabschnitt_NB(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Netzbereich(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Netzbereich(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Strecke(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Strecke(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Netzbereichskomponente(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
static void BoundingBox_Bereichsobjekt_hist(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Bereichsobjekt_hist(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Bereichsobjekt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Bereichsobjekt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Teilabschnitt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Teilabschnitt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Strassenelement(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Strassenelement(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Streckenobjekt_hist(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Streckenobjekt_hist(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Streckenobjekt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Streckenobjekt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Teilnetz(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Teilnetz(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Route(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Route(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Verbindungspunkt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Verbindungspunkt(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_manuelle_Zaehlstelle_AVZ(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_manuelle_Zaehlstelle_AVZ(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Verkehrslage(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Verkehrslage(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Verkehrsstau(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Verkehrsstau(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Telematik_Zaehlstelle(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_Telematik_Zaehlstelle(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_sonstige_Zaehlstelle(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoLinie_sonstige_Zaehlstelle(FachobjektPtr pxo, const Datum& stag);
#endif
static void BoundingBox_Wassereinleitungspunkt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Wassereinleitungspunkt(FachobjektPtr pxo, const Datum& stag);
#endif
// Händisch ergänzt
static void BoundingBox_Strassenelementpunkt(FachobjektPtr pxoObj, BoundingBox& bBox, const Datum& stag, FachobjektMengeImpl* pxosetcyc);
#ifdef OKLABI_GEOMETRIE_METHODEN
static const Geometrie* E_GeoPunkt_Strassenelementpunkt(FachobjektPtr pxo, const Datum& stag);
#endif
};
} // Namespace Oklabi

