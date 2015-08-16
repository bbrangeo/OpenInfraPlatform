/*****************************************************************************
* $Id: OklabiEnumIntern.h 2014-01-29 15:00:00 vogelsang $
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
* 2013-02-04 Profile
* 2013-12-12 Fremdobjekt für Nachbarstandards eingeführt
* 2014-01-29 Enum für FB-Listen-Version erweitert
* 2014-06-06 Benutzerattribut am Fachobjekt
* 
****************************************************************************/
	// Berechnete Eigenschaften
	enum eImplizit 
	{
		oklabiSchema     =  0,
		oklabiGeometrie	 =  1,
		oklabiGeoPunkt   =  2,
		oklabiGeoLinie   =  3,
		oklabiGeoFlaeche =  4,
		oklabiGeoVolumen =  5,
		oklabiBBox       =  6,
		oklabiSignatur   =  7,
		oklabiInternId   =  8,
		oklabiObjektNr   =  9,
		oklabiGeoAeste   = 10,
		oklabiKennung    = 11,
		oklabiFremdRef   = 12,
		oklabiUserAttr   = 13
	};

	// Erweiterungen am OKSTRA
	enum eErweiterung 
	{
		erweiterung_OKSTRA					= 0,
		erweiterung_dynamisches_Querprofil	= 1,
		erweiterung_Bauabrechnung			= 2,
		erweiterung_CentroMap				= 3,
		erweiterung_GDF						= 4,
		// Anzahl
		erweiterung_Gesamt					= 5
	};

	enum eLocObjState
	{
		original			= 0,
		veraendert			= 1,
		gueltig				= 2,
		markiert			= 3,
		zombie				= 4
	};

	// Geometrietyp aus Fachbedeutungsliste
	enum eFbGeoTyp
	{
		fb_Typ_ohne			= 0,
		fb_Typ_alle			= 1,
		fb_Typ_Punkt		= 2,
		fb_Typ_Linie		= 3,
		fb_Typ_Flaeche		= 4,
		fb_Typ_Text			= 6
	};

	// Für Transaktionen
	enum eAktion
	{
		Erzeugen     = 0,
		Vernichten   = 1,
		Setzen       = 2,
		Hinzufuegen  = 3,
		Loeschen     = 4
	};

	// Version der Fachbedeutungsliste
	enum eFbVersion
	{
		fb_ohne				= 0,
		fb_alle				= 1,
		fb_1_3				= 2,
		fb_1_4				= 3,
		fb_1_5				= 4,
		fb_1_6				= 5,
		fb_2				= 6,
		fb_3				= 7,
		fb_4				= 8,
		fb_5				= 9
	};

	// Benötigt in Eigenschaft
	enum eAggreg
	{
		nilAggreg  = 0,
		setAggreg  = 1,
		listAggreg = 2
	};

	enum eEnumeratorTyp
	{
		textEnumerator       =  1,
		versionEnumerator    =  2,
		schemaEnumerator     =  3,
		exportEnumerator     =  4,
		fachobjektEnumerator =  5,
		anyEnumerator        =  6,
		objektartEnumerator  =  7,
		geometrieEnumerator  =  8,
		anyGeoEnumerator     =  9,
		profilOartEnumerator = 10,
		profilEnumerator     = 11
	};
