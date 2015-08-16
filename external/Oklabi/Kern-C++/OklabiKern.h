/*****************************************************************************
* $Id: OklabiKern.h 2014-07-17 15:00:00 vogelsang $
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
* 2010-07-13 Aufzaehlungstyp eEinheitTyp erweitert
* 2010-10-28 Java-Integration Prüfprogramm
* 2011-04-07 Umrechnung bei Einheitenwandlung
* 2011-07-05 Elementnamen konfigurierbar machen
* 2011-07-19 Interfaces exportieren
* 2011-08-04 Neue Enum-Werte für UML-Modellierung
* 2011-08-17 Hilfsfunktionen
* 2011-10-21 Chronologische Ausgabe
* 2011-11-14 Erweiterung Geometrie-Schnittstelle
* 2011-12-01 Neue AlsText-Methode
* 2012-03-12 Metadaten
* 2012-06-11 Hilfsfunktionen
* 2012-06-19 Genauigkeitsschranke exportieren
* 2012-09-18 Koordinatenreferenzsysteme bearbeitet
* 2012-10-18 Formale Verbesserungen
* 2013-03-05 Genauigkeit bei der Ausgabe von Koordinaten
* 2013-03-07 Typkennzeichner eingeführt
* 2013-03-11 Harmonisierung der Schnittstelle
* 2013-04-18 Zugriff auf das konzeptionelle Fachdatenmodell
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-07-17 Umwandlung von Enum eKoordRefSys in Schlüsseltabellenwert
* 
****************************************************************************/
#ifndef DEFOklabiKern
#define DEFOklabiKern

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <string>
#include <set>
#include <list>
#include <map>
#ifdef CYGWIN
#undef max
#undef min
#endif
#include <vector>
#if defined(WIN32) || defined(CYGWIN)
#include <windows.h>
#endif

#include "oklabidll.h"
#include "OklabiEnum.h"
#include "OklabiBasis.h"
#include "Binaerdaten.h"
#include "Datum.h"
#include "Koordinate.h"

namespace Oklabi
{
	class FblVersion;
	template<class T> class Liste;
	template<class T> class Menge;
	typedef Menge< int >          IntMenge;
	typedef Menge< UINT64 >       LongIntMenge;
	typedef Menge< bool >         BoolMenge;
	typedef Menge< float >        FloatMenge;
	typedef Menge< double >       DoubleMenge;
	typedef Menge< Datum >        DatumMenge;
	typedef Menge< Binaerdaten* > BinaerMenge;
	typedef Menge< Koordinate >   KoordinatenMenge;
	typedef Menge< eKoordRefSys > KoordRefSysMenge;
	typedef Menge< FblVersion* >  FblVersionMenge;

	typedef Liste< int >          IntListe;
	typedef Liste< UINT64 >       LongIntListe;
	typedef Liste< bool >         BoolListe;
	typedef Liste< float >        FloatListe;
	typedef Liste< double >       DoubleListe;
	typedef Liste< Datum >        DatumListe;
	typedef Liste< Binaerdaten* > BinaerListe;
	typedef Liste< Koordinate >   KoordinatenListe;
	typedef Liste< eKoordRefSys > KoordRefSysListe;
	typedef Liste< FblVersion* >  FblVersionListe;

	class Version;
	class Eigenschaft;
	class Objektart;
	class Objektartfilter;
	typedef Version*                      VersionPtr;
	typedef const Version*                VersionConstPtr;
	typedef const Objektart*              ObjektartConstPtr;
	typedef const Eigenschaft*            EigenschaftConstPtr;
	typedef std::vector<Eigenschaft*>     EigenschaftVektorType;
	typedef Liste< EigenschaftConstPtr>   EigenschaftListType;
	typedef Liste< ObjektartConstPtr>     ObjektartListType;

	OKLABI_API Text AlsText(eKoordRefSys);
	OKLABI_API Text AlsText(eModellierung);
	OKLABI_API Text AlsText(eKodierung);
	OKLABI_API Text AlsText(eSort);
	OKLABI_API Text AlsText(eTyp);
	OKLABI_API Text AlsText(eTypKategorie);
	OKLABI_API Text AlsText(eEinheitTyp);
	OKLABI_API double Umrechnungsfaktor(eEinheitTyp, eEinheitTyp);
	OKLABI_API Text AlsText(eGeoFormat);
	OKLABI_API Text AlsText(eGeoTyp);
	OKLABI_API Text AlsText(eLinientyp);

	// Schlüssel und Langtext für Schlüsseltabelle Koordinatenreferenzsystem
	OKLABI_API Text WandleSRS(eKoordRefSys, Text&);

	// Genauigkeitsgrenze für Vergleiche auf double
	OKLABI_API double ErfrageGenauigkeitsschranke();
	OKLABI_API double SetzeGenauigkeitsschranke(const double& prec);

	// Genauigkeitsgrenze für Koordinaten
	OKLABI_API double ErfrageGenauigkeitKoordinaten();
	OKLABI_API double SetzeGenauigkeitKoordinaten(const double& prec);

	OKLABI_API Text AlsText(eBundesland);
	OKLABI_API Text AlsText(eFortTyp);
	OKLABI_API Text AlsText(eProtokollTyp);
	OKLABI_API Text AlsText(eMeldTyp);
	OKLABI_API Text AlsText(eMetadaten);
	OKLABI_API Text AlsText(eRootTag);
	OKLABI_API Text AlsText(eModelleigenschaft);
	OKLABI_API Text AlsText(eAufzaehlungen);
	OKLABI_API Text AlsText(eElementtyp);
	OKLABI_API Text AlsText(eTypkennzeichner);
	OKLABI_API Text AlsText(eEinstellung);

	OKLABI_API Text AlsText(const Text&);
	OKLABI_API Text AlsText(const Koordinate&);
	class Geometrie;
	OKLABI_API Text AlsText(const Geometrie*);
	class Fachobjekt;
	OKLABI_API Text AlsText(const Fachobjekt*);
	OKLABI_API Text AlsText(const Binaerdaten*);
	OKLABI_API Text AlsText(unsigned int, bool = false);
	OKLABI_API Text AlsText(int);
	OKLABI_API Text AlsText(int, int, char, bool);
	OKLABI_API Text AlsText(long);
	OKLABI_API Text AlsText(unsigned long);
	OKLABI_API Text AlsText(UINT64);
	OKLABI_API Text AlsText(UINT64, int, char, bool);
	OKLABI_API Text AlsText(double, size_t = 0, size_t = -1, bool = true, bool = false);
	OKLABI_API Text AlsText(float);
	OKLABI_API Text AlsText(void*);

	OKLABI_API Text upper(const Text&);
	OKLABI_API Text lower(const Text&);
	OKLABI_API Text trim_left(const Text&, char);
	OKLABI_API Text trim_right(const Text&, char);
	OKLABI_API Text trim(const Text&, char);
	OKLABI_API void append(Text&, double d, bool upper);
	OKLABI_API void append(Text&, float d, bool upper);
	OKLABI_API Text replace( const Text&, const Text&, const Text& );
	OKLABI_API bool ends_with(const Text&, const Text&, Text::size_type&);
	OKLABI_API bool starts_with(const Text&, const Text&);
	OKLABI_API Text transscript( const Text& str, bool bToISO );
	OKLABI_API bool file_exists( const Text& );
	OKLABI_API bool is_directory( const Text& );
	OKLABI_API Text basename();
	OKLABI_API Text getTempFileName(const Text& name);

	template<class T> typename std::list<T>::iterator find(std::list<T>& dl, const T& d)
	{
		typename std::list<T>::iterator it;
		for (it = dl.begin(); it != dl.end(); ++it)
		{
			if ((*it) == d)
				return it;
		}
		return dl.end();
	};

	template<class T> typename std::list<T>::const_iterator find(const std::list<T>& dl, const T& d)
	{
		typename std::list<T>::const_iterator it;
		for (it = dl.begin(); it != dl.end(); ++it)
		{
			if ((*it) == d)
				return it;
		}
		return dl.end();
	};

	template<class Text> typename std::list<Text>::iterator find(std::list<Text>& dl, const Text& d, bool cs)
	{
		typename std::list<Text>::iterator it;
		if (cs)
		{
			for (it = dl.begin(); it != dl.end(); ++it)
			{
				if ((*it) == d)
					return it;
			}
		}
		else
		{
			for (it = dl.begin(); it != dl.end(); ++it)
			{
				if ((*it).stricmp(d)==0)
					return it;
			}
		}
		return dl.end();
	};

	template<class Text> typename std::list<Text>::const_iterator find(const std::list<Text>& dl, const Text& d, bool cs)
	{
		typename std::list<Text>::const_iterator it;
		if (cs)
		{
			for (it = dl.begin(); it != dl.end(); ++it)
			{
				if ((*it) == d)
					return it;
			}
		}
		else
		{
			for (it = dl.begin(); it != dl.end(); ++it)
			{
				if ((*it).strimp(d)==0)
					return it;
			}
		}
		return dl.end();
	};

}// End of namespace Oklabi

#include "Ausnahme.h"
#include "Aggregat.h"
#include "Liste.h"
#include "Menge.h"

namespace Oklabi
{
	// find-Methode für Menge<T>
	template<class T> typename Menge<T>::iterator find(Menge<T>& c, const T& d)
	{
		return c.find(d);
	};

	// find-Methode für Menge<T>
	template<class T> typename Menge<T>::const_iterator find(const Menge<T>& c, const T& d)
	{
		return c.find(d);
	};

	// find-Methode für Liste<T>
	template<class T> typename Liste<T>::iterator find(Liste<T>& c, const T& d)
	{
		typename Liste<T>::iterator it;
		for (it = c.begin(); it != c.end(); ++it)
		{
			if ((*it) == d)
				return it;
		}
		return c.end();
	};

	// find-Methode für Liste<T>
	template<class T> typename Liste<T>::const_iterator find(const Liste<T>& c, const T& d)
	{
		typename Liste<T>::const_iterator it;
		for (it = c.begin(); it != c.end(); ++it)
		{
			if ((*it) == d)
				return it;
		}
		return c.end();
	};

	// find-Methode für TextListe ohne Beachtung von Gross- und Kleinschreibung
	template<class Text> typename Liste<Text>::iterator find(Liste<Text>& c, const Text& d, bool cs)
	{
		TextListe::iterator it;
		if (cs)
		{
			for (it = c.begin(); it != c.end(); ++it)
			{
				if ((*it) == d)
					return it;
			}
		}
		else
		{
			for (it = c.begin(); it != c.end(); ++it)
			{
				if ((*it).stricmp(d)==0)
					return it;
			}
		}
		return c.end();
	};

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFOklabiKern
