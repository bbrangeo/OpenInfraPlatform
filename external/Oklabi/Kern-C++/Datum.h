/*****************************************************************************
* $Id: Datum.h 2014-07-10 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2014, Bundesanstalt für Straßenwesen
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
* 2011-08-08 Umstieg UML-Modellierung, Datentyp Uhrzeit
* 2011-08-31 Datum aus ISO-Textformat erzeugen
* 2012-05-14 Inkrementelles Entladen
* 2013-10-18 Layout Datum optimiert
* 2013-12-17 Instanzen für Wert-Objekte zulassen
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-07-10 SQL-Anbindung vorbereiten
* 
****************************************************************************/
#ifndef DEFDatum
#define DEFDatum

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "OklabiKern.h"

namespace Oklabi
{
	class OKLABI_API Datum : public OklabiObjekt
	{
		friend class AnyType;
		friend class AnyEnumerator;
		friend class Fachobjekt;
		friend class Datenbestand;
		friend class Reflection;
		friend class valCTEType;
		friend class CTEEingabeKonverter;
		friend class CTEAusgabeKonverter;
		friend class XMLEingabeKonverter;
		friend class XMLAusgabeKonverter;
		friend class XMLAusgabeGenerator;
		friend class XMLAdapter;
		friend class Umgebung;
		friend class Logging;
#ifdef OKLABI_SCHEMADB
		friend class SchemaDBAdapter;
#endif
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
#if defined(OKLABI_SQL)
		friend class SQLVerbindung;
#endif

	private:
		struct DateVal
		{
			int dat;
			int tim;
			DateVal();
			~DateVal();
			DateVal(int, int);
			DateVal(const DateVal&);
			DateVal(const Datum&);
			DateVal& operator=(const DateVal&);
			DateVal& operator=(const Datum&);
			bool operator==(const DateVal&) const;
			bool operator==(const Datum&) const;
		} m_Date;

		Datum(int);
		Datum(int, int);
		Datum(const Text&);
		Datum(const DateVal&);
		Datum&         operator=(const Datum::DateVal&);
		bool           operator<=(const Datum& datv) const;
		bool           operator>(const Datum& datv) const;
		bool           operator>=(const Datum& datv) const;
		bool           operator!=(const Datum& ndatum) const;
		Text           Wandlung(const bool& bSort = false) const;
		Datum          Gestern() const;
		Datum          Morgen() const;
		static int     AnzahlTage(int nY, int nM);
		static Text    Zeitstempel();
		static Datum   today();
		static Datum   now();
		static Datum   DatumAusIso( const Text& );
		bool           KannVernichten() const;
		void           SetzeUnbekannt();
		void           SetzeOffen();

	public:
		static Datum*  Erzeuge(int j, int m, int d);
		static Datum*  Erzeuge(int j, int m, int d, int h, int mi, int s, int ms = 0);
		static Datum*  Erzeuge(const Text&);
		static Datum   Gib(int j, int m, int d);
		static Datum   Gib(int j, int m, int d, int h, int mi, int s, int ms = 0);
		static Datum   Gib(const Text&);
		Datum*         Kopiere() const;
		static Datum*  Heute();
		static Datum*  Jetzt();
		Datum*         Plus(int);
		int            Minus(const Datum*);
		Text           GibText() const;
		Text           GibDatum() const;
		Text           GibUhrzeit() const;
		bool           IstGleich(const Datum*) const;
		bool           IstGroesser(const Datum*) const;
		bool           IstKleiner(const Datum*) const;
		int            Jahr() const;
		int            Monat() const;
		int            Tag() const;
		int            Stunde() const;
		int            Minute() const;
		int            Sekunde() const;
		int            Millisekunde() const;
		void           Jahr(int);
		void           Monat(int);
		void           Tag(int);
		void           Stunde(int);
		void           Minute(int);
		void           Sekunde(int);
		void           Millisekunde(int);
		Text           GibKlassenname() const;
		bool           IstUnbekannt() const;
		bool           IstOffen() const;

		// public wegen Verwendung in templates
		Datum();
		~Datum();
		Datum(const Datum& d);
		Datum&         operator=(const Datum&);
		bool           operator==(const Datum&) const;
		bool           operator<(const Datum& datv) const;
		operator int() const;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFDatum
