/*****************************************************************************
* $Id: OklabiIntern.h 2014-01-17 15:00:00 vogelsang $
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
* 2010-07-08 Aufzaehlungstyp eAufzaehlungen ergänzt
* 2011-07-05 Elementnamen konfigurierbar machen
* 2011-07-07 Prüfung von Schlüsseltabellen erweitert
* 2011-07-14 Lesen von WFS Response
* 2011-08-12 template-Defintionen überarbeitet
* 2012-06-11 Hilfsfunktionen
* 2012-10-18 Formale Verbesserungen
* 2013-03-05 Genauigkeit bei der Ausgabe von Koordinaten
* 2013-03-11 Harmonisierung der Schnittstelle
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#ifndef DEFOklabiIntern
#define DEFOklabiIntern

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
#include <limits>
#ifdef WIN32
#include <windows.h>
#endif

namespace Oklabi
{
#include "OklabiEnumIntern.h"
	OKLABI_API Text AlsText(eImplizit);
	OKLABI_API Text AlsText(eErweiterung);
	OKLABI_API Text AlsText(eLocObjState);
	OKLABI_API Text AlsText(eFbGeoTyp);
	OKLABI_API Text AlsText(eAktion);
	OKLABI_API Text AlsText(eFbVersion);
	OKLABI_API Text AlsText(eAggreg);
	OKLABI_API Text AlsText(eTyp, eAggreg);
	OKLABI_API Text AlsText(eEnumeratorTyp);

	// Genauigkeitsgrenze für Vergleiche auf double
	extern double m_dPrecision;
	extern int m_nDigits;
	// Genauigkeitsgrenze für Koordinaten
	extern double m_dPrecCoord;
	extern int m_nDigitsCoord;
	// _gcvt liefert ab 16 digits ungenaue Werte
	#define DEFAULT_GCVT_DIGITS 15

	typedef unsigned char PropState;
	const PropState                  unbestimmt	= '0';
	const PropState                  geaendert	= '1';
	const PropState                  leer		= '2';
	const PropState                  gelesen	= '3';

	typedef	int	kt_ergebnis;
	const kt_ergebnis                kt_ok = 0;
	const kt_ergebnis                kt_kennung_fehlt = 1;
	const kt_ergebnis                kt_langtext_fehlt = 2;
	const kt_ergebnis                kt_falsche_version = 4;
	const kt_ergebnis                kt_nicht_definiert = 8;
	const kt_ergebnis                kt_falscher_wert = 16;
	const kt_ergebnis                kt_multipler_wert = 32;
	const kt_ergebnis                kt_nicht_in_profil = 64;

#undef max
	const int beliebig_viele = std::numeric_limits<int>::max();
	const unsigned offiziell = 0;
	const unsigned angepasst = 1;

	std::string _upper(const std::string&);
	std::wstring _upper(const std::wstring&);
	std::string _lower(const std::string&);
	std::wstring _lower(const std::wstring&);
	std::string _trim_left(const std::string&, char);
	std::wstring _trim_left(const std::wstring&, wchar_t);
	std::string _trim_right(const std::string&, char);
	std::wstring _trim_right(const std::wstring&, wchar_t);
	std::string _trim(const std::string&, char);
	std::wstring _trim(const std::wstring&, wchar_t);
	std::string _replace( const std::string&, const std::string&, const std::string& );
	std::wstring _replace( const std::wstring&, const std::wstring&, const std::wstring& );
	bool _ends_with(const std::string&, const std::string&, std::string::size_type&);
	bool _ends_with(const std::wstring&, const std::wstring&, std::wstring::size_type&);
	bool _starts_with(const std::string&, const std::string&);
	bool _starts_with(const std::wstring&, const std::wstring&);
	std::string _transscript( const std::string& str, bool bToISO );
	std::wstring _transscript( const std::wstring& str, bool bToISO );
	bool _file_exists( const std::string& );
	bool _is_directory( const std::string& );
	std::string _basename();
	std::string _getTempFileName(const std::string& name);
	bool _readUTF8(const char* str, size_t at, char[8], size_t&, int&);
	bool _readUTF8(const wchar_t* str, size_t at, wchar_t[8], size_t&, int&);

///////////////////////////////////////////////////////////////////////
// Absicherung von Werten bei Ausnahmen
//
// Beim Verlassen des Codeblocks, in dem dieses Objekt auf dem Stack
// angelegt wurde, wird das Objekt befreit und setzt den Wert zurück,
// dessen Addresse bei der Konstruktion mitgegeben wurde.
// Das garantiert einen definierten Wert der abgesicherten Variablen
// auch im Falle von Ausnahmen.
// Bei der Konstruktion des Objektes wird der Startwert mit angegeben.
//
	template<class T> class Sicherung
	{
	public:
		Sicherung<T>(T* pVar, const T& initialValue, const T& finalValue) : m_pValue(pVar), m_Value(finalValue)
		{
			if (pVar)
				(*pVar) = initialValue;
		};
		~Sicherung<T>()
		{
			if (m_pValue)
				(*m_pValue) = m_Value;
		};
	private:
		T* m_pValue;
		T  m_Value;
	};

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFOklabiIntern
