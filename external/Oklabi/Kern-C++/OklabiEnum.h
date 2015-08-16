/*****************************************************************************
* $Id: OklabiEnum.h 2014-06-27 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2012-2014, Bundesanstalt für Straßenwesen
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
* 2012-10-18 Formale Verbesserungen
* 2012-12-17 Anpassungen für Visual Studio 2012
* 2013-01-24 Zeichenkodierung
* 2013-02-01 Anpassungen für UML-Modellierung
* 2013-03-07 Typkennzeichner eingeführt
* 2013-03-11 Harmonisierung der Schnittstelle
* 2013-04-18 Zugriff auf das konzeptionelle Fachdatenmodell
* 2013-11-18 Transformierer eingeführt
* 2014-04-28 Express-Geometriemodell für Version 2.x
* 2014-05-20 Lagestatus für Koordinatenreferenzsysteme
* 2014-06-27 Zugriff auf GDAL-Ressourcen für Tansformierer
* 2014-07-17 Umwandlung von Enum eKoordRefSys in Schlüsseltabellenwert
* 
****************************************************************************/
#if !defined(DEFOklabiEnum) && !defined(OKLABI_MANAGED) && !defined(OKLABI_C)
namespace Oklabi
{
#endif

#ifndef OKLABI_DECL_ENUM
#define OKLABI_DECL_ENUM enum
#endif
#ifndef OKLABI_CAST
#define OKLABI_CAST(x) ((int)(x))
#endif
#ifndef OKLABI_SRSDEF
#define OKLABI_SRSDEF(n) (49152+8192+(n))
#endif
#ifndef OKLABI_SRSEXTRACT
#define OKLABI_SRSEXTRACT(e) ((((int)(e))>(49152+8192) && ((int)(e))<(49152+8192+4096+2048)) ? ((int)(e))-(49152+8192) : (int)(e))
#endif

#if !defined(DEFOklabiEnum) || defined(OKLABI_MANAGED) || defined(OKLABI_C)
	// Koordinatenreferenzsystem (basierend auf EPSG gebildet,
	// muss zum Typ unsigned short kompatibel sein)
	OKLABI_DECL_ENUM eKoordRefSys
	{
		Undefiniert  = 0,
		GK2DHDN      = 31466,    // DHDN, 3GK2
		GK3DHDN      = 31467,    // DHDN, 3GK3
		GK4DHDN      = 31468,    // DHDN oder 40-83, 3GK4
		GK5DHDN      = 31469,    // DHDN oder 40-83, 3GK5
		WGS84        = 4326,     // WGS84, X-Y
		WGS84H       = 4979,     // WGS84, X-Y-Z
		ETRS89       = 4258,     // ETRS89, X-Y
		ETRS89H      = 4937,     // ETRS89, X-Y-Z
		UTM32N       = 25832,    // ETRS89, UTM32
		UTM33N       = 25833,    // ETRS89, UTM33
		Amersfoort   = 28992,    // RD, Amersfoort
		Pulk42_83_33 = 2397,     // 42-83, 3GK3
		Pulk42_83_34 = 2398,     // 42-83, 3GK4
		Pulk42_83_35 = 2399,     // 42-83, 3GK5
		Pulk42_83_62 = 28462,    // 42-83, 6GK2
		Pulk42_83_63 = 28463     // 42-83, 6GK3
#ifdef OKLABI_KERN
		//
		// Partielle Angaben als Zwischenzustände beim Laden
		//
		,__DHDN      = 65535,
		__40_83      = 65534,
		__42_83      = 65533,
		__WGS84      = 65532,
		__ETRS89     = 65531,
		__RD         = 65530,
		__3GK2       = 65529,
		__3GK3       = 65528,
		__3GK4       = 65527,
		__3GK5       = 65526,
		__6GK2       = 65525,
		__6GK3       = 65524,
		__X_Y_Z      = 65523,
		__UTM32      = 65522,
		__UTM33      = 65521,
		__Amersfoort = 65520,
#else
		,
#endif
        DE_DHDN_3GK2_BE200 = OKLABI_SRSDEF(201),
        DE_DHDN_3GK2_BW100 = OKLABI_SRSDEF(202),
        DE_DHDN_3GK2_BY110 = OKLABI_SRSDEF(203),
        DE_DHDN_3GK2_BY120 = OKLABI_SRSDEF(204),
        DE_DHDN_3GK2_HB100 = OKLABI_SRSDEF(205),
        DE_DHDN_3GK2_HE100 = OKLABI_SRSDEF(206),
        DE_DHDN_3GK2_HE110 = OKLABI_SRSDEF(207),
        DE_DHDN_3GK2_HE120 = OKLABI_SRSDEF(208),
        DE_DHDN_3GK2_HH100 = OKLABI_SRSDEF(209),
        DE_DHDN_3GK2_NI000 = OKLABI_SRSDEF(210),
        DE_DHDN_3GK2_NI100 = OKLABI_SRSDEF(211),
        DE_DHDN_3GK2_NI200 = OKLABI_SRSDEF(212),
        DE_DHDN_3GK2_NI210 = OKLABI_SRSDEF(213),
        DE_DHDN_3GK2_NW101 = OKLABI_SRSDEF(214),
        DE_DHDN_3GK2_NW119 = OKLABI_SRSDEF(215),
        DE_DHDN_3GK2_NW131 = OKLABI_SRSDEF(216),
        DE_DHDN_3GK2_NW133 = OKLABI_SRSDEF(217),
        DE_DHDN_3GK2_NW158 = OKLABI_SRSDEF(218),
        DE_DHDN_3GK2_NW163 = OKLABI_SRSDEF(219),
        DE_DHDN_3GK2_NW166 = OKLABI_SRSDEF(220),
        DE_DHDN_3GK2_NW173 = OKLABI_SRSDEF(221),
        DE_DHDN_3GK2_NW174 = OKLABI_SRSDEF(222),
        DE_DHDN_3GK2_NW175 = OKLABI_SRSDEF(223),
        DE_DHDN_3GK2_NW176 = OKLABI_SRSDEF(224),
        DE_DHDN_3GK2_NW177 = OKLABI_SRSDEF(225),
        DE_DHDN_3GK2_RDN = OKLABI_SRSDEF(226),
        DE_DHDN_3GK2_RP101 = OKLABI_SRSDEF(227),
        DE_DHDN_3GK2_RP180 = OKLABI_SRSDEF(228),
        DE_DHDN_3GK2_SH200 = OKLABI_SRSDEF(229),
        DE_DHDN_3GK2_SH210 = OKLABI_SRSDEF(230),
        DE_DHDN_3GK2_SL159 = OKLABI_SRSDEF(231),
        DE_DHDN_3GK2_SL197 = OKLABI_SRSDEF(232),
        DE_DHDN_3GK2_ST200 = OKLABI_SRSDEF(233),
        DE_DHDN_3GK2_TH200 = OKLABI_SRSDEF(234),
        DE_DHDN_3GK2_TH210 = OKLABI_SRSDEF(235),
        DE_DHDN_3GK3_BE200 = OKLABI_SRSDEF(301),
        DE_DHDN_3GK3_BW100 = OKLABI_SRSDEF(302),
        DE_DHDN_3GK3_BY110 = OKLABI_SRSDEF(303),
        DE_DHDN_3GK3_BY120 = OKLABI_SRSDEF(304),
        DE_DHDN_3GK3_HB100 = OKLABI_SRSDEF(305),
        DE_DHDN_3GK3_HE100 = OKLABI_SRSDEF(306),
        DE_DHDN_3GK3_HE110 = OKLABI_SRSDEF(307),
        DE_DHDN_3GK3_HE120 = OKLABI_SRSDEF(308),
        DE_DHDN_3GK3_HH100 = OKLABI_SRSDEF(309),
        DE_DHDN_3GK3_NI000 = OKLABI_SRSDEF(310),
        DE_DHDN_3GK3_NI100 = OKLABI_SRSDEF(311),
        DE_DHDN_3GK3_NI200 = OKLABI_SRSDEF(312),
        DE_DHDN_3GK3_NI210 = OKLABI_SRSDEF(313),
        DE_DHDN_3GK3_NW101 = OKLABI_SRSDEF(314),
        DE_DHDN_3GK3_NW119 = OKLABI_SRSDEF(315),
        DE_DHDN_3GK3_NW131 = OKLABI_SRSDEF(316),
        DE_DHDN_3GK3_NW133 = OKLABI_SRSDEF(317),
        DE_DHDN_3GK3_NW158 = OKLABI_SRSDEF(318),
        DE_DHDN_3GK3_NW163 = OKLABI_SRSDEF(319),
        DE_DHDN_3GK3_NW166 = OKLABI_SRSDEF(320),
        DE_DHDN_3GK3_NW173 = OKLABI_SRSDEF(321),
        DE_DHDN_3GK3_NW174 = OKLABI_SRSDEF(322),
        DE_DHDN_3GK3_NW175 = OKLABI_SRSDEF(323),
        DE_DHDN_3GK3_NW176 = OKLABI_SRSDEF(324),
        DE_DHDN_3GK3_NW177 = OKLABI_SRSDEF(325),
        DE_DHDN_3GK3_RDN = OKLABI_SRSDEF(326),
        DE_DHDN_3GK3_RP101 = OKLABI_SRSDEF(327),
        DE_DHDN_3GK3_RP180 = OKLABI_SRSDEF(328),
        DE_DHDN_3GK3_SH200 = OKLABI_SRSDEF(329),
        DE_DHDN_3GK3_SH210 = OKLABI_SRSDEF(330),
        DE_DHDN_3GK3_SL159 = OKLABI_SRSDEF(331),
        DE_DHDN_3GK3_SL197 = OKLABI_SRSDEF(332),
        DE_DHDN_3GK3_ST200 = OKLABI_SRSDEF(333),
        DE_DHDN_3GK3_TH200 = OKLABI_SRSDEF(334),
        DE_DHDN_3GK3_TH210 = OKLABI_SRSDEF(335),
        DE_DHDN_3GK4_BE200 = OKLABI_SRSDEF(401),
        DE_DHDN_3GK4_BW100 = OKLABI_SRSDEF(402),
        DE_DHDN_3GK4_BY110 = OKLABI_SRSDEF(403),
        DE_DHDN_3GK4_BY120 = OKLABI_SRSDEF(404),
        DE_DHDN_3GK4_HB100 = OKLABI_SRSDEF(405),
        DE_DHDN_3GK4_HE100 = OKLABI_SRSDEF(406),
        DE_DHDN_3GK4_HE110 = OKLABI_SRSDEF(407),
        DE_DHDN_3GK4_HE120 = OKLABI_SRSDEF(408),
        DE_DHDN_3GK4_HH100 = OKLABI_SRSDEF(409),
        DE_DHDN_3GK4_NI000 = OKLABI_SRSDEF(410),
        DE_DHDN_3GK4_NI100 = OKLABI_SRSDEF(411),
        DE_DHDN_3GK4_NI200 = OKLABI_SRSDEF(412),
        DE_DHDN_3GK4_NI210 = OKLABI_SRSDEF(413),
        DE_DHDN_3GK4_NW101 = OKLABI_SRSDEF(414),
        DE_DHDN_3GK4_NW119 = OKLABI_SRSDEF(415),
        DE_DHDN_3GK4_NW131 = OKLABI_SRSDEF(416),
        DE_DHDN_3GK4_NW133 = OKLABI_SRSDEF(417),
        DE_DHDN_3GK4_NW158 = OKLABI_SRSDEF(418),
        DE_DHDN_3GK4_NW163 = OKLABI_SRSDEF(419),
        DE_DHDN_3GK4_NW166 = OKLABI_SRSDEF(420),
        DE_DHDN_3GK4_NW173 = OKLABI_SRSDEF(421),
        DE_DHDN_3GK4_NW174 = OKLABI_SRSDEF(422),
        DE_DHDN_3GK4_NW175 = OKLABI_SRSDEF(423),
        DE_DHDN_3GK4_NW176 = OKLABI_SRSDEF(424),
        DE_DHDN_3GK4_NW177 = OKLABI_SRSDEF(425),
        DE_DHDN_3GK4_RDN = OKLABI_SRSDEF(426),
        DE_DHDN_3GK4_RP101 = OKLABI_SRSDEF(427),
        DE_DHDN_3GK4_RP180 = OKLABI_SRSDEF(428),
        DE_DHDN_3GK4_SH200 = OKLABI_SRSDEF(429),
        DE_DHDN_3GK4_SH210 = OKLABI_SRSDEF(430),
        DE_DHDN_3GK4_SL159 = OKLABI_SRSDEF(431),
        DE_DHDN_3GK4_SL197 = OKLABI_SRSDEF(432),
        DE_DHDN_3GK4_ST200 = OKLABI_SRSDEF(433),
        DE_DHDN_3GK4_TH200 = OKLABI_SRSDEF(434),
        DE_DHDN_3GK4_TH210 = OKLABI_SRSDEF(435),
        DE_DHDN_3GK5_BE200 = OKLABI_SRSDEF(501),
        DE_DHDN_3GK5_BW100 = OKLABI_SRSDEF(502),
        DE_DHDN_3GK5_BY110 = OKLABI_SRSDEF(503),
        DE_DHDN_3GK5_BY120 = OKLABI_SRSDEF(504),
        DE_DHDN_3GK5_HB100 = OKLABI_SRSDEF(505),
        DE_DHDN_3GK5_HE100 = OKLABI_SRSDEF(506),
        DE_DHDN_3GK5_HE110 = OKLABI_SRSDEF(507),
        DE_DHDN_3GK5_HE120 = OKLABI_SRSDEF(508),
        DE_DHDN_3GK5_HH100 = OKLABI_SRSDEF(509),
        DE_DHDN_3GK5_NI000 = OKLABI_SRSDEF(510),
        DE_DHDN_3GK5_NI100 = OKLABI_SRSDEF(511),
        DE_DHDN_3GK5_NI200 = OKLABI_SRSDEF(512),
        DE_DHDN_3GK5_NI210 = OKLABI_SRSDEF(513),
        DE_DHDN_3GK5_NW101 = OKLABI_SRSDEF(514),
        DE_DHDN_3GK5_NW119 = OKLABI_SRSDEF(515),
        DE_DHDN_3GK5_NW131 = OKLABI_SRSDEF(516),
        DE_DHDN_3GK5_NW133 = OKLABI_SRSDEF(517),
        DE_DHDN_3GK5_NW158 = OKLABI_SRSDEF(518),
        DE_DHDN_3GK5_NW163 = OKLABI_SRSDEF(519),
        DE_DHDN_3GK5_NW166 = OKLABI_SRSDEF(520),
        DE_DHDN_3GK5_NW173 = OKLABI_SRSDEF(521),
        DE_DHDN_3GK5_NW174 = OKLABI_SRSDEF(522),
        DE_DHDN_3GK5_NW175 = OKLABI_SRSDEF(523),
        DE_DHDN_3GK5_NW176 = OKLABI_SRSDEF(524),
        DE_DHDN_3GK5_NW177 = OKLABI_SRSDEF(525),
        DE_DHDN_3GK5_RDN = OKLABI_SRSDEF(526),
        DE_DHDN_3GK5_RP101 = OKLABI_SRSDEF(527),
        DE_DHDN_3GK5_RP180 = OKLABI_SRSDEF(528),
        DE_DHDN_3GK5_SH200 = OKLABI_SRSDEF(529),
        DE_DHDN_3GK5_SH210 = OKLABI_SRSDEF(530),
        DE_DHDN_3GK5_SL159 = OKLABI_SRSDEF(531),
        DE_DHDN_3GK5_SL197 = OKLABI_SRSDEF(532),
        DE_DHDN_3GK5_ST200 = OKLABI_SRSDEF(533),
        DE_DHDN_3GK5_TH200 = OKLABI_SRSDEF(534),
        DE_DHDN_3GK5_TH210 = OKLABI_SRSDEF(535)
	};

	// Art der Modellierung
	OKLABI_DECL_ENUM eModellierung
	{
		EXPRESS        = 0,
		UML            = 1
	};

	// Art der Kodierung
	OKLABI_DECL_ENUM eKodierung
	{
		ISOLATIN1      = 0,
		UTF8           = 1
	};

	// Sortierung für Ausgabe nach CTE/XML
	OKLABI_DECL_ENUM eSort
	{ 
		ohne           = 0,
		alphanumerisch = 1,
		numerisch      = 2,
		klassenweise   = 3,
		normiert       = 4,
		chronologisch  = 5
	};

	// Benötigt in Eigenschaft
	OKLABI_DECL_ENUM eTyp
	{
		nilType     = 10,
		intType     = 11,
		doubleType  = 12,
		floatType   = 13,
		boolType    = 14,
		dateType    = 15,
		koordType   = 16,
		stringType  = 17,
		objectType  = 18,
		geoType     = 19,
		binaryType  = 20,
		longIntType = 21,
		gPointType  = 22,
		gPathType   = 23,
		gLineType   = 24,
		gCubicType  = 25,
		gArcType    = 26,
		gSurfaceType= 27,
		gSolidType  = 28
	};

	// Benötigt für Datentypen
	OKLABI_DECL_ENUM eTypKategorie
	{
		kUnbekannt    = -1,
		kObjektart    =  0,
		kGanz         =  1,
		kReell        =  2,
		kReellFixiert =  3,
		kText         =  4,
		kTextLaenge   =  5,
		kTextFixiert  =  6,
		kAbgeleitet   =  7,
		kLogisch      =  8,
		kBinaer       =  9,
		kKoordinate   = 10,
		kGeometrie    = 11,
		kGanzLang     = 12,
		kReellEinfach = 13,
		kSchluessel   = 20,
		kAufzaehlung  = 21,
		kKonzeptOA    = 22,
		kDatum        = 23,
		kUhrzeit      = 24,
		kPunkt        = 25,
		kLinie        = 26,
		kFlaeche      = 27,
		kVolumen      = 28
	};

	// Einheiten bei Attributwerten
	OKLABI_DECL_ENUM eEinheitTyp
	{
		uUnbelegt						= 100,
		uSTRING							= 101,
		uINTEGER						= 102,
		uBOOLEAN						= 103,
		uREAL							= 104,
		uGUID							= 105,
		uBINARY							= 106,
		uProzent						= 107,
		uPromille						= 108,
		uDatum							= 120,
		uASB_Datum						= 121,
		uTag							= 122,
		uWoche							= 123,
		uMonat							= 124,
		uJahr							= 125,
		uJahre							= 126,
		uMonate							= 127,
		uWochen							= 128,
		uTage							= 129,
		uSekunde						= 130,
		uMinute							= 131,
		uStunde							= 132,
		uSekunden						= 133,
		uMillisekunden					= 134,
		uMinuten						= 135,
		uStunden						= 136,
		uUhrzeit						= 137,
		uGrad							= 145,
		uGon							= 146,
		uAnzahl							= 148,
		uAnzahl_einstellig				= 149,
		uAnzahl_zweistellig				= 150,
		uAnzahl_Klassen					= 151,
		uGroesse						= 152,
		uWinkel							= 153,
		uKlassenwert					= 154,
		uRTF							= 155,
		uRGB_Farbwert					= 156,
		udpi							= 157,
		uFarbtiefe						= 158,
		uErfassungsqualitaet			= 159,
		uTK25_Blattnummer				= 160,
		uASB_ING_Schluessel				= 161,
		uSchadensbewertung				= 162,
		uKoordinatengenauigkeit			= 163,
		uWegweisernummer				= 164,
		uStrassennummer					= 165,
		uZusatzbuchstabe				= 166,
		ulfd_NK_Nummer					= 167,
		uNullpunktkennung				= 168,
		uUnfallursache					= 169,
		uArt_der_Verkehrsbeteiligung	= 170,
		uallgemeine_Unfallursache		= 171,
		uUnfaelle_pro_km_und_Jahr		= 172,
		uUnfaelle_pro_Mio_Kfz_km		= 173,
		uKfz_pro_Stunde					= 174,
		uKfz_pro_Tag					= 175,
		uLkw_pro_Stunde					= 176,
		uLkw_pro_Tag					= 177,
		uGanglinientyp					= 178,
		uBilddatei						= 179,
		uTonnen							= 200,
		uKilometer						= 201,
		uMeter							= 202,
		uDezimeter						= 203,
		uZentimeter						= 204,
		uMillimeter						= 205,
		uQuadratmeter					= 206,
		uQuadratmillimeter				= 207,
		uKubikmeter						= 208,
		uKubikzentimeter				= 209,
		uGrad_Celsius					= 210,
		uLux							= 211,
		uKilowatt						= 212,
		uKilogramm						= 213,
		uStundenkilometer				= 214,
		uHektopascal					= 215,
		uHektar							= 216,
		uNewton							= 219,
		uKilonewton						= 220,
		uNewton_pro_Quadratmillimeter	= 221,
		uKilogramm_pro_Quadratmeter		= 222,
		uKilogramm_pro_Kubikmeter		= 223,
		ucd_pro_Quadratmeter			= 224,
		uKilonewton_pro_Meter			= 225,
		uGramm_pro_Quadratmeter			= 226,
		uLiter_pro_Sekunde_und_Meter	= 227,
		uMeter_pro_Sekunde				= 228,
		uMillimeter_pro_Stunde			= 229,
		uKilonewton_pro_Quadratmeter	= 230,
		uMikrometer						= 231,
		uMeter_ueber_NN					= 232,
		uRichtungswinkel				= 233,
		uStunden_pro_Woche				= 234,
		uNetzknotennummer				= 235,
		uNullpunktnummer				= 236,
		uAOA_Kennung					= 237,
		uWaehrung						= 300,
		uBetrag							= 301,
		uEURO							= 302,
		uDM								= 303,
		uEins_zu_N						= 350,
		uObjektverweis					= 500,
		uKoordinate						= 501,
		uGeometrie						= 502,
		uLONGINT						= 503,
		uSINGLE							= 504,
		uPoint							= 550,
		uCurve							= 551,
		uSurface						= 552,
		uSolid							= 553
	};

	// Geometrieformat
	OKLABI_DECL_ENUM eGeoFormat
	{
		OKSTRA		= 0,
		Kompakt		= 1
	};

	// Geometrietyp
	OKLABI_DECL_ENUM eGeoTyp
	{
		Ohne		= 0,
		Punkt		= 1,
		Linie		= 2,
		Flaeche		= 3,
		Rechteck	= 4,
		Volumen		= 5,
		Zeichen     = 6
	};

	// Linientyp
	OKLABI_DECL_ENUM eLinientyp
	{
		keine		= 0,
		Gerade		= 1,
		Kreisbogen	= 2,
		Klothoide	= 3,
		Spline		= 4
	};

	// Bundesland (benötigt in Fachbedeutungsliste)
	OKLABI_DECL_ENUM eBundesland
	{
		bl_alle		= 0,
		SH			= 1,
		HH			= 2,
		NI			= 3,
		HB			= 4,
		NW			= 5,
		HE			= 6,
		RP			= 7,
		BW			= 8,
		BY			= 9,
		SL			= 10,
		BE			= 11,
		BB			= 12,
		MV			= 13,
		SN			= 14,
		ST			= 15,
		TH			= 16,
		bl_ohne		= 17
	};

	// Benötigt für Fortschrittsanzeige
	OKLABI_DECL_ENUM eFortTyp
	{
		start       = 0,
		schritt     = 1,
		ende        = 2
	};

	// Benötigt für Protokolle
	OKLABI_DECL_ENUM eProtokollTyp
	{
		meldungen    = 0,
		aufrufe      = 1,
		statistiken  = 2,
		statuszeilen = 3,
		ungenutzt    = 4
	};

	// Benötigt zur Klassifizierung von Ausnahmesituationen
	OKLABI_DECL_ENUM eMeldTyp
	{
		abbruch		= -1,
		fehler		= 0,
		warnung		= 2,
		info		= 4,
		debug		= 5,
		logging		= 6,
		statistik	= 7
	};

	// Benötigt zur Klassifizierung von Metadaten bei Im- und Export
	OKLABI_DECL_ENUM eMetadaten
	{
		description			 = 0,
		author				 = 1,
		organization		 = 2,
		originating_system	 = 4,
		authorization		 = 5,
		schema_identifiers   = 6,
		preprocessor_version = 7,
		time_stamp           = 8
	};

	// Benötigt zur Angabe des Root-Tags bei XML-Im/Export
	OKLABI_DECL_ENUM eRootTag
	{
		okstra	= 0,
		feature = 1
	};

	// Von Version und Fachmodell abhängige Eigenschaften
	OKLABI_DECL_ENUM eModelleigenschaft
	{
		eXmlNamespace            = 0,
		eXmlNamespacePrefix      = 1,
		eXmlUri                  = 2,
		eXmlMetadataElementName  = 3,
		eXmlLocalSchemaLocation  = 4,
		eXmlPublicSchemaLocation = 5
	};

	// Zählt die Aufzählungstypen auf
	OKLABI_DECL_ENUM eAufzaehlungen
	{
		tAufzaehlungen   =  0,
		tGeoFormat       =  1,
		tGeoTyp          =  2,
		tLinientyp       =  3,
		tKoordRefSys     =  4,
		tMeldTyp         =  5,
		tAusnTyp         =  6,
		tFortTyp         =  7,
		tProtokollTyp    =  8,
		tBundesland      =  9,
		tEinheitTyp      = 10,
		tMetadaten       = 11,
		tRootTag         = 12,
		tImplizit        = 13,
		tErweiterung     = 14,
		tLocObjState     = 15,
		tFbGeoTyp        = 16,
		tAktion          = 17,
		tModellierung    = 18,
		tTypKategorie    = 19,
		tElementtyp      = 20,
		tEnumeratorTyp   = 21,
		tKodierung       = 22,
		tTypkennzeichner = 23,
		tEinstellung     = 24,
		tTyp             = 25,
		tSort            = 26,
		tXmlEigenschaft  = 27
	};

	// Zählt die Typkennzeichner auf
	OKLABI_DECL_ENUM eTypkennzeichner
	{
		qBasistyp       =  0,
		qDezimalstellen =  1,
		qMaxLaenge      =  2,
		qHatFesteLaenge =  3,
		qMasseinheit    =  4,
		qTypkategorie   =  5
	};

	// Zählt die Konfigurationseigenschaften auf
	OKLABI_DECL_ENUM eEinstellung
	{
		pXMLSchema                       =  0,
		pXMLSchemavalidierung            =  1,
		pSchluesseltabelleneinbettung    =  2,
		pCTEZeilenlaenge                 =  3,
		pSymbolverschmelzung             =  4,
		pKennungskorrektur               =  5,
		pReferenzpraefix                 =  6,
		pSRSPraefix                      =  7,
		pFachbedeutungen                 =  8,
		pFbFehlerbehandlung              =  9,
		pFbListenpruefung                = 10,
		pSchluesseltabellenpruefung      = 11,
		pRessourcen                      = 12,
		pGeometrieformat                 = 13,
		pNebenlaeufigkeit                = 14,
		pErweiterungen                   = 15,
		pStackTrace                      = 16,
		pAufrufprotokoll                 = 17,
		pAufrufprotokollEbene            = 18,
		pSpeicherverbrauch               = 19,
		pSpeicherverbrauchEbene          = 20,
		pVergleichsgenauigkeit           = 21,
		pKoordinatengenauigkeit          = 22,
		pReleaseDatum                    = 23,
		pReleaseVersion                  = 24,
		pSchemaDBVersion                 = 25,
		pSchemaDBName                    = 26,
		pProfile                         = 27,
		pTextformat                      = 28,
		pExpressGeometrie                = 29,
		pEntwickler                      = 30,
		pProtokoll                       = 31,
		pGdalData                        = 32
	};

	// Element-Typen in XML
	OKLABI_DECL_ENUM eElementtyp
	{
		objectElement        = 1,
		keyValueElement      = 2,
		collectionElement    = 3,
		metaDataElement      = 4,
		svcExcRepElement     = 5,
		svcExcElement        = 6,
		svcExcCodeElement    = 7,
		wfsFeatureCollection = 8,
		gmlFeatureMember     = 9
	};

	// Ausnahme-Typen
	OKLABI_DECL_ENUM eAusnTyp
	{
		AusnUnbekannt     = OKLABI_CAST(0xA0490000),
		FatalerFehler     = OKLABI_CAST(0xA0490001),
		ObjGeloescht      = OKLABI_CAST(0xA0490002),
		ObjGesichert      = OKLABI_CAST(0xA0490003),
		RefUeberlauf      = OKLABI_CAST(0xA0490004),
		RefUnterlauf      = OKLABI_CAST(0xA0490005),
		NichtImpl         = OKLABI_CAST(0xA0490006),
		OeffnenVerboten   = OKLABI_CAST(0xA0490007),
		SchreibenVerboten = OKLABI_CAST(0xA0490008),
		LesenVerboten     = OKLABI_CAST(0xA0490009),
		DatumFalsch       = OKLABI_CAST(0xA0490101),
		SRSUnbekannt      = OKLABI_CAST(0xA0490102),
		ObjektartInit     = OKLABI_CAST(0xA0492000),
		ObjektartVersch   = OKLABI_CAST(0xA0492001),
		NichtKonfig       = OKLABI_CAST(0xA0492002),
		NichtGefunden     = OKLABI_CAST(0xA0492003),
		SchluesselGanz    = OKLABI_CAST(0xA0492004),
		SchluesselText    = OKLABI_CAST(0xA0492005),
		KeinSchluessel    = OKLABI_CAST(0xA0492006),
		NichtSchreiben    = OKLABI_CAST(0xA0492007),
		VersionFalsch     = OKLABI_CAST(0xA0492010),
		TypUnbekannt      = OKLABI_CAST(0xA0493000),
		TypIstLeer        = OKLABI_CAST(0xA0493001),
		AmEnde            = OKLABI_CAST(0xA0493002),
		TypUnpassend      = OKLABI_CAST(0xA0493003),
		ProfilUnpassend   = OKLABI_CAST(0xA0493004),
		IndexFalsch       = OKLABI_CAST(0xA0494002),
		FachobjektErz     = OKLABI_CAST(0xA0494010),
		FehlerInit        = OKLABI_CAST(0xA0499001),
		ObjektFehlt       = OKLABI_CAST(0xA0499002),
		IdUnbekannt       = OKLABI_CAST(0xA0499003),
		ObjektAnlegen     = OKLABI_CAST(0xA0499005),
		NichtBekannt      = OKLABI_CAST(0xA0499009),
		FehlerInhalt      = OKLABI_CAST(0xA0499010),
		FehlerAufbau      = OKLABI_CAST(0xA0499011),
		MultipleID        = OKLABI_CAST(0xA0499020),
		FehlerTransaktion = OKLABI_CAST(0xA0499021),
		SrvcExcReport     = OKLABI_CAST(0xA0499022)
	};
#endif // !defined(DEFOklabiEnum) || defined(OKLABI_MANAGED) || defined(OKLABI_C)

#if !defined(DEFOklabiEnum) && !defined(OKLABI_MANAGED) && !defined(OKLABI_C)
}// End of namespace Oklabi
#define DEFOklabiEnum
#endif
