/*****************************************************************************
* $Id: Version.h 2014-07-10 15:00:00 vogelsang $
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
* 2010-07-20 Vorbereitungen für Nutzung der Schema-Datenbank
* 2010-08-24 Interface GibDokumentation() ergänzt
* 2010-08-24 SchemaEnumerator ergänzt
* 2011-08-12 template-Defintionen überarbeitet
* 2012-05-14 Inkrementelles Entladen
* 2012-09-18 Koordinatenreferenzsysteme bearbeitet
* 2013-02-04 Profile
* 2013-04-18 Zugriff auf das konzeptionelle Fachdatenmodell
* 2013-06-06 Namenskollision bei impliziten Eigenschaften
* 2014-05-20 Fachmodell bei Textwandlung berückichtigen
* 2014-05-20 Fachbedeutungen nur im OKSTRA-Datenmodell
* 2014-07-10 SQL-Anbindung vorbereiten
* 
****************************************************************************/
#ifndef DEFVersion
#define DEFVersion

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "Enumerator.h"
#include "Fachmodell.h"
#ifdef OKLABI_SCHEMADB
#include "SchemaDBAdapter.h"
#endif

namespace Oklabi
{

typedef struct VersionId : public OklabiRoot
{
	unsigned char m_nMajor;
	unsigned char m_nMinor;
	unsigned char m_nRelease;
	unsigned char m_nIndex;
} VersionIdType;

typedef struct XmlProperty : public OklabiRoot
{
	Text          m_strXmlNs;
	Text          m_strXmlUri;
	Text          m_strMetadata;
	XmlProperty();
	XmlProperty(const Text&, const Text&, const Text&);
	XmlProperty(const XmlProperty&);
	XmlProperty& operator=(const XmlProperty&);
	~XmlProperty();
} XmlPropertyType;

class OKLABI_API Version : public OklabiObjekt
{
	friend class Objektart;
	friend class Objektartfilter;
	friend class Eigenschaft;
	friend class Fachobjekt;
	friend class Reflection;
	friend class AusgabeKonverter;
	friend class EingabeKonverter;
	friend class CTEAusgabeKonverter;
	friend class CTEEingabeKonverter;
	friend class Datenbestand;
	friend class XMLAdapter;
	friend class XMLAusgabeKonverter;
	friend class XMLAusgabeGenerator;
	friend class XMLEingabeKonverter;
	friend class Umgebung;
	friend class VersionEnumerator;
	friend class Schema;
	friend class Schema1;
	friend class Schema2;
	friend class Schema3;
	friend class SchemaGeo;
	friend class Koordinate;
#ifdef OKLABI_SCHEMADB
	friend class SchemaDBAdapter;
#endif
#if defined(OKLABI_SQL)
	friend class SQLVerbindung;
#endif
	friend class Profil;

private:
	union
	{
		VersionIdType m_sVersion;	// enthält die Versionsinformation
		unsigned int  m_nVsn;		// Version als ganze Zahl
	};
#ifdef OKLABI_SCHEMADB
	eModellierung            m_eModell;
	Fachmodell*              m_pModell;
#endif
#ifdef CYGWIN
public:
#endif
	Version();
	~Version();
	Version& operator=(const Version&);

#ifdef CYGWIN
private:
#endif
	Version(size_t, const Fachmodell*);
	Version(int major, int minor, int release);
	Version(int major, int minor, int release, const Fachmodell*);
	Version(const Version&);
	operator int();
	bool                       operator==(const Version&) const;
	bool                       operator!=(const Version&) const;
	bool                       operator<=(const Version&) const;
	bool                       operator>=(const Version&) const;
	bool                       operator>(const Version&) const;
	bool                       operator<(const Version&) const;
	bool                       KannVernichten() const;
	unsigned char              check();
	void                       clear();
	void                       init(int major, int minor, int release, const Fachmodell*);
	size_t                     GibIndex() const;
	static bool                Zerlege(const Text& version, int& major, int& minor, int& release, int& internal_vnr);
	static bool                Pruefe(const int& major, const int& minor, const int& release, int& internal_vnr);
	static bool                Pruefe(const Text& vsn, int& vnr);
	int ToInt()                const;
	bool                       IstOKSTRAFachmodell() const;
#ifdef OKLABI_SCHEMADB
	static void                LazyInit();
	static void                Finalisiere();
#endif

public:

	static Version*            Erzeuge(int major, int minor, int release = 0, const Fachmodell* = 0);
	Text                       GibKlassenname() const;
	Text                       GibDokumentation() const;
	const Fachmodell*          GibFachdatenmodell() const;
	eModellierung              GibModellierung() const;
	bool                       HatFachbedeutung() const;

	Version*                   GibVorlaeuferversion() const;
	Version*                   GibNachfolgerversion() const;
	int                        GibHauptversion() const;
	int                        GibUnterversion() const;
	int                        GibEntwicklungsversion() const;
	bool                       IstKleiner(const Version*) const;
	bool                       IstGroesser(const Version*) const;
	bool                       IstGleich(const Version*) const;
	Text                       GibText(bool = false) const;
	Version*                   Kopiere() const;
	int                        GibOID() const;

	static                     size_t GibAnzahl(const Fachmodell* = 0);

	class OKLABI_API VersionEnumerator : public Enumerator
	{
		friend class Version;
	public:
		Text                   GibKlassenname() const;
		template<class T> T    GibObjekt();
		void                   Weiter();
		bool                   IstBeendet() const;
		void                   ZumAnfang();
	protected:
		bool                   KannVernichten() const;
		eEnumeratorTyp         GibEnumeratorTyp() const;
	private:
		VersionEnumerator();
		VersionEnumerator(const Fachmodell*);
		~VersionEnumerator();
		VersionEnumerator(const VersionEnumerator& iter);
		VersionEnumerator& operator=(const VersionEnumerator& iter);
		mutable size_t            m_nIndex;
		mutable const Fachmodell* m_pModell;
		void                      Next() const;
	};
	static Enumerator*         GibEnumerator(const Fachmodell* = 0);

	class OKLABI_API SchemaEnumerator : public Enumerator
	{
		friend class Version;
	public:
		SchemaEnumerator(const Version* vsn);
		~SchemaEnumerator();
		SchemaEnumerator(const SchemaEnumerator& iter);
		SchemaEnumerator& operator=(const SchemaEnumerator& iter);
		Text                        GibKlassenname() const;
		template<class T> T         GibObjekt();
		void                        Weiter();
		bool                        IstBeendet() const;
		void                        ZumAnfang();
	protected:
		bool                        KannVernichten() const;
		eEnumeratorTyp              GibEnumeratorTyp() const;
	private:
		mutable TextListe           m_ListSchema;
		mutable const Version*      m_pVersion;
		mutable TextListe::iterator m_Iter;
		mutable bool				m_bThis;
	};
	Enumerator*                GibSchemaEnumerator();
	Text                       GibDokumentation(const Text&) const;
};

// Spezialisierungen
template<> OKLABI_API Version* Version::VersionEnumerator::GibObjekt<Version*>();
template<> OKLABI_API const Version* Version::VersionEnumerator::GibObjekt<const Version*>();
template<> OKLABI_API Text Version::SchemaEnumerator::GibObjekt<Text>();

}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFVersion
