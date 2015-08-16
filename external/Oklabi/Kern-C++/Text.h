/*****************************************************************************
* $Id: Text.h 2014-07-10 15:00:00 vogelsang $
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
* 2010-10-26 Anpassungen für Linux
* 2011-08-18 Text einkapseln
* 2011-10-14 Schnittstelle überarbeitet
* 2011-11-18 gz-File schreiben ohne Kopieren
* 2012-02-21 Laufzeitoptimierungen
* 2012-05-14 Inkrementelles Entladen
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2012-11-14 Objektartnamen vergleichen ohne Fallunterscheidung
* 2013-02-06 Formale Verbesserungen
* 2013-03-07 Typkennzeichner eingeführt
* 2013-12-12 Fremdobjekt für Nachbarstandards eingeführt
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-06-27 Zugriff auf GDAL-Ressourcen für Tansformierer
* 2014-07-10 SQL-Anbindung vorbereiten
* 
****************************************************************************/
#ifndef DEFText
#define DEFText

#include "OklabiPackaging.h"
#include "oklabidll.h"
#include "OklabiRoot.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <string>
#if defined(WIN32) || defined(CYGWIN)
#include <windows.h>
#endif

#ifdef OKLABI_KERN
#include "zlib.h"
#else
#define gzFile void*
#endif

namespace Oklabi
{
	class Text;
	OKLABI_API Text operator+(const Oklabi::Text&, const Oklabi::Text&);
	OKLABI_API Text operator+(const std::string::value_type, const Text&);
	OKLABI_API Text operator+(const std::string::value_type*, const Text&);
	OKLABI_API Text operator+(const std::wstring::value_type, const Text&);
	OKLABI_API Text operator+(const std::wstring::value_type*, const Text&);
	OKLABI_API bool operator==(const std::string::value_type s, const Text& t);
	OKLABI_API bool operator==(const std::string::value_type* s, const Text& t);
	OKLABI_API bool operator==(const std::wstring::value_type s, const Text& t);
	OKLABI_API bool operator==(const std::wstring::value_type* s, const Text& t);
	template<class _E, class _T>
		std::basic_ostream<_E, _T>& operator<<(
			std::basic_ostream<_E, _T>&, const Text&);
#if defined(LINUX) || defined(CYGWIN)
	template<>
		std::basic_ostream<char, std::char_traits<char> >& operator<< <char, std::char_traits<char> >(
		  std::basic_ostream<char, std::char_traits<char> >&, const Text&);
#endif
	template<class _E, class _T>
		OKLABI_API std::basic_istream<_E, _T>& operator>>(
			std::basic_istream<_E, _T>&, Text&);
#if defined(LINUX) || defined(CYGWIN)
	template<>
		std::basic_istream<char, std::char_traits<char> >& operator>> <char, std::char_traits<char> >(
			std::basic_istream<char, std::char_traits<char> >&, Text&);
#endif

	class cicmp : public OklabiRoot
	{
	public:
		OKLABI_API bool operator()(const Text& x, const Text& y) const;
	};

	class ptrcmp : public OklabiRoot
	{
	public:
		OKLABI_API bool operator()(const Text* x, const Text* y) const;
	};

	class Text : public OklabiRoot
	{
#ifdef OKLABI_INTERN
		friend class cicmp;
		friend class ptrcmp;
		friend class Ausnahme;
		friend class Binaerdaten;
		friend class Umgebung;
		friend class Reflection;
		friend class Fachobjekt;
		friend class Objektart;
		friend class Ausgabe;
		friend class DateiEingabe;
		friend class DateiAusgabe;
		friend class EingabeKonverter;
		friend class AusgabeKonverter;
		friend class XMLEingabeKonverter;
		friend class XMLAusgabeKonverter;
		friend class XMLAusgabeGenerator;
		friend class XMLAdapter;
		friend class Profil;
		friend class CTEEingabeKonverter;
		friend class CTEAusgabeKonverter;
		friend class TextpufferEingabe;
		friend class TextpufferAusgabe;
		friend class Textpuffer;
		friend class Version;
		friend class Datum;
		friend class HttpEingabe;
		friend class OklabiObjekt;
		friend class SchemaDBAdapter;
		friend class Schema;
		friend class Schema1;
		friend class Schema2;
		friend class Schema3;
		friend class SchemaGeo;
		friend class GeoPunkt;
		friend class GeoLinie;
		friend class GeoFlaeche;
		friend class GeoVolumen;
		friend class GeoRechteck;
		friend class Fachbedeutungsliste;
		friend class Datenbestand;
		friend class _XString;
		friend class IsybauImporteur;
		friend class OGRTransformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
#if defined(OKLABI_SPATIALITE)
		friend class SpatialiteDatenleser;
		friend class SpatialiteVerbindung;
#endif
#endif
		friend OKLABI_API Text Oklabi::operator+(const Text&, const Text&);
		friend OKLABI_API Text operator+(const std::string::value_type, const Text&);
		friend OKLABI_API Text operator+(const std::string::value_type*, const Text&);
		friend OKLABI_API Text operator+(const std::wstring::value_type, const Text&);
		friend OKLABI_API Text operator+(const std::wstring::value_type*, const Text&);
		friend OKLABI_API bool operator==(const std::string::value_type s, const Text& t);
		friend OKLABI_API bool operator==(const std::string::value_type* s, const Text& t);
		friend OKLABI_API bool operator==(const std::wstring::value_type s, const Text& t);
		friend OKLABI_API bool operator==(const std::wstring::value_type* s, const Text& t);
		public:
			typedef std::string::size_type size_type;
			typedef std::string::value_type value_type;
			typedef std::string::reference reference;
			typedef std::string::const_reference const_reference;
			static OKLABI_API const std::string::size_type npos;

			// Art des enthaltenen String
			enum eStringType
			{
				_string  = 0,
				_wstring = 1,
				_bstring = 2
			};

			OKLABI_API Text();
			OKLABI_API ~Text();
			OKLABI_API Text(const Text&);
			OKLABI_API Text(const std::string::value_type);
			OKLABI_API Text(const std::wstring::value_type);
			OKLABI_API Text(const std::basic_string<unsigned char>::value_type);
			OKLABI_API Text(const std::string::value_type*);
			OKLABI_API Text(const std::wstring::value_type*);
			OKLABI_API Text(const std::basic_string<unsigned char>::value_type*);
			inline Text(const std::string& s) { set(s.c_str()); };
			inline Text(const std::wstring& s) { set(s.c_str()); };
			inline Text(const std::basic_string<unsigned char>& s) { set(s.c_str()); };
			explicit OKLABI_API Text(int);
			OKLABI_API Text(size_type, const std::string::value_type);
			OKLABI_API Text(size_type, const std::wstring::value_type);
			OKLABI_API Text(size_type, const std::basic_string<unsigned char>::value_type);
			OKLABI_API Text& operator=(const Text&);

			OKLABI_API eStringType TextTyp() const;

			inline operator std::string() { return this->c_str(); };
			inline operator std::string() const { return this->c_str(); };
			inline operator std::wstring() { return this->w_str(); };
			inline operator std::wstring() const { return this->w_str(); };

			OKLABI_API size_type size() const;
			OKLABI_API size_type length() const;
			OKLABI_API void clear();
			OKLABI_API Text::size_type find(const Text& t, Text::size_type p = 0) const;
			OKLABI_API Text::size_type find(const std::string::value_type* pT, Text::size_type p = 0) const;
			OKLABI_API Text::size_type find(const std::wstring::value_type* pT, Text::size_type p = 0) const;
			OKLABI_API Text::size_type find_first_of(const Text& t, Text::size_type p = 0) const;
			OKLABI_API Text::size_type find_first_not_of(const Text& t, Text::size_type p = 0) const;
			OKLABI_API Text::size_type find_last_of(const Text& t, Text::size_type p = npos) const;
			OKLABI_API Text::size_type find_last_not_of(const Text& t, Text::size_type p = npos) const;
			OKLABI_API Text substr(Text::size_type p1, Text::size_type p2 = npos) const;
			OKLABI_API bool operator==(const Text& t) const;
			OKLABI_API bool operator!=(const Text& t) const;
			OKLABI_API bool operator<(const Text& t) const;
			OKLABI_API bool operator>(const Text& t) const;
			OKLABI_API bool operator<=(const Text& t) const;
			OKLABI_API bool operator>=(const Text& t) const;
			OKLABI_API Text& operator+=(const Text& t);
			OKLABI_API Text& erase(Text::size_type p1 = 0, Text::size_type p2 = npos);
			OKLABI_API Text& insert(Text::size_type p1, const Text& t);
			OKLABI_API void reserve(Text::size_type r = 0);
			OKLABI_API int compare(Text::size_type p, Text::size_type n, const Text& t, Text::size_type o, Text::size_type c) const;
			OKLABI_API int compare(const Text& t) const;
			OKLABI_API int stricmp(const Text& t) const;

			// Convenience Functions
			OKLABI_API Text trim(std::string::value_type) const;
			OKLABI_API Text trim(std::wstring::value_type) const;
			OKLABI_API Text trim_left(std::string::value_type) const;
			OKLABI_API Text trim_left(std::wstring::value_type) const;
			OKLABI_API Text trim_right(std::string::value_type) const;
			OKLABI_API Text trim_right(std::wstring::value_type) const;
			OKLABI_API bool ends_with(const Text&, Text::size_type&) const;
			OKLABI_API bool starts_with(const Text&) const;
			OKLABI_API Text replace( const Text&, const Text& ) const;
			OKLABI_API Text transscript( bool bToISO ) const;
			OKLABI_API Text upper() const;
			OKLABI_API Text lower() const;
		private:
			// Following methods are unsafe with different runtime libraries
			OKLABI_API std::string& operator*();
			OKLABI_API const std::string& operator*() const;
			OKLABI_API std::string* operator->();
			OKLABI_API const std::string* operator->() const;
			OKLABI_API const std::string::value_type* c_str() const;
			OKLABI_API const std::string::value_type* data() const;
			OKLABI_API const std::wstring::value_type* w_str() const;
			OKLABI_API Text::const_reference at(Text::size_type p) const;
			OKLABI_API Text::reference at(Text::size_type p);
			OKLABI_API Text::const_reference operator[](Text::size_type p) const;
			OKLABI_API Text::reference operator[](Text::size_type p);

			// Data...
			mutable union
			{
				std::string*                      m_pString;
				std::wstring*                     m_pWString;
				std::basic_string<unsigned char>* m_pBString;
				void*                             m_pVoid;
			}           m_uData;
			mutable eStringType m_eType;
			OKLABI_API static bool init();
			OKLABI_API void set(const std::string::value_type*);
			OKLABI_API void set(const std::wstring::value_type*);
			OKLABI_API void set(const std::basic_string<unsigned char>::value_type*);
			void cleanup(bool = false) const;
			static OKLABI_API std::string toString(const std::wstring::value_type*, size_t siz); 
			static OKLABI_API std::wstring toWstring(const std::string::value_type*, size_t siz);
		public:
			static inline std::string toString(const std::wstring& s) { return toString(s.c_str(), s.size()); }; 
			static inline std::wstring toWstring(const std::string& s) { return toWstring(s.c_str(), s.size()); };
			OKLABI_API int writeGZ(gzFile);
	};
	inline Text operator+(const std::string& s, const Oklabi::Text& t) { return operator+(s.c_str(), t); };
	inline Text operator+(const std::wstring& s, const Oklabi::Text& t) { return operator+(s.c_str(), t); };
	inline bool operator==(const std::string& s, const Oklabi::Text& t) { return operator==(s.c_str(), t); };
	inline bool operator==(const std::wstring& s, const Oklabi::Text& t) { return operator==(s.c_str(), t); };

	typedef std::set< Text*, ptrcmp > TextPtrMenge;
	typedef std::set< const Text*, ptrcmp > TextConstPtrMenge;
	typedef std::list< Text*, ptrcmp > TextPtrListe;
	typedef std::list< const Text*, ptrcmp > TextConstPtrListe;
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFText
