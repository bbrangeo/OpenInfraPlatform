/*****************************************************************************
* $Id: Ausnahme.h 2013-12-12 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt für Straßenwesen
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
* 2010-10-29 Gruppierung von Ausnahmen
* 2011-08-30 Verpackung von Ausnahmen
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2012-10-15 Aufräumen bei Programmende
* 2012-10-18 Formale Verbesserungen
* 2013-02-04 Profile
* 2013-03-11 Harmonisierung der Schnittstelle
* 2013-12-12 Fremdobjekt für Nachbarstandards eingeführt
* 
****************************************************************************/
#ifndef DEFAusnahme
#define DEFAusnahme

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <exception>

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "Exceptions.h"

namespace Oklabi
{
	OKLABI_API Text AlsText(eAusnTyp);
	OKLABI_API eAusnTyp VonText(const Text&);

	// Ausnahme-Kategorien
	enum eAusnKategorie
	{
		kAusnahme             = 0,
		kDatenbestandAusnahme = 1,
		kXMLAusnahme          = 2
	};

	// Prototyp für die Kontruktion von Ausnahmen
	class Ausnahme;
	typedef Ausnahme* (*pAusnahmeErzeugeFunktion)(const Text&, eAusnTyp, eMeldTyp, OklabiObjekt*);

	// Klasse für die Registrierung der Ausnahmeklassen über ihren Namen
	class AusnahmeFabrik
	{
		// Map zur Aufnahme der Ausnahme-Konstruktoren
		typedef std::map< Text, pAusnahmeErzeugeFunktion > AusnahmeErzeugeFunktionMapType;
		friend class Ausnahme;
		friend class Umgebung;
	public:
		static bool Registriere(const char*, pAusnahmeErzeugeFunktion);
		static Ausnahme* ErzeugeAusnahme(const Text&, const Text&, eAusnTyp, eMeldTyp, OklabiObjekt*);
		static OKLABI_API pAusnahmeErzeugeFunktion GibErzeugeFunktion(const char*);
	private:
		static AusnahmeErzeugeFunktionMapType* m_pmapErzFkt;
		static int finalize();
		static bool initialize();
	};

	// Ausnahme-Klassen

	// Gemeinsame Oberklassen
	class Ausgabe;
	class Ausnahme : public OklabiObjekt, public structured_exception
	{
		friend class XMLAdapter;
		friend class AusnahmeBehaelter;
		friend class Umgebung;
		friend class Profil;
#ifdef OKLABI_KERN
		friend class IsybauImporteur;
#endif
		public:
			// Ctor
			OKLABI_API Ausnahme() /*throw()*/;
#if defined(LINUX) || defined(CYGWIN)
			virtual OKLABI_API ~Ausnahme() NOTHROW;
#endif
			OKLABI_API Ausnahme( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt* pObj, bool trace = true ) /*throw()*/;
			// Message, Fehlernummer und Schwere erfragen
			virtual OKLABI_API Text              GibMeldungstext() const /*throw()*/;
			virtual OKLABI_API eMeldTyp          GibSchwere() const;
			virtual OKLABI_API eAusnTyp          GibCode() const;
			virtual OKLABI_API OklabiObjekt*     GibObjekt() const;
			virtual OKLABI_API Text              GibKlassenname() const = 0;
			OKLABI_API virtual Ausnahme*         Kopiere() const = 0;
			virtual OKLABI_API void              SchreibeReport(Ausgabe*) const;
			static OKLABI_API Ausnahme*          Erzeuge(const Oklabi::Text&, const Oklabi::Text&, Oklabi::eAusnTyp, Oklabi::eMeldTyp, Oklabi::OklabiObjekt*);
		protected:
			eAusnTyp                             m_nCode;
			eMeldTyp                             m_eTyp;
			eAusnKategorie                       m_eKategorie;
			OklabiObjekt*                        m_pObjekt;
			virtual OKLABI_API const char*       getMessage() const;
			virtual OKLABI_API const char*       message() const;
			virtual OKLABI_API bool              KannVernichten() const;
			virtual OKLABI_API eAusnKategorie    GibKategorie() const;
			OKLABI_API Ausnahme(const Ausnahme&);
			OKLABI_API Ausnahme& operator=(const Ausnahme&);
			OKLABI_API Ausnahme( eAusnKategorie eKat, bool trace = true ) /*throw()*/;
			OKLABI_API Ausnahme( eAusnKategorie eKat, const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt* pObj, bool trace = true ) /*throw()*/;
	};

	class XmlAusnahme : public Ausnahme
	{
		friend class XMLAdapter;
		public:
			OKLABI_API XmlAusnahme() /*throw()*/;
			OKLABI_API XmlAusnahme( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt* pObj, bool trace = true ) /*throw()*/;
	};

	// Verpackung für Ausnahmeobjekte ausserhalb der OklabiKern.DLL
	// Auch bei Nutzung in templates!
	class OKLABI_API AusnahmeBehaelter : public OklabiRoot
	{
		friend class XMLAdapter;
		friend class Profil;
#ifdef OKLABI_KERN
		friend class IsybauImporteur;
#endif
	public:
		AusnahmeBehaelter();
		AusnahmeBehaelter(const AusnahmeBehaelter&);
		AusnahmeBehaelter& operator=(const AusnahmeBehaelter&);
		AusnahmeBehaelter(const Oklabi::Text&, const Oklabi::Text&, Oklabi::eAusnTyp, Oklabi::eMeldTyp, Oklabi::OklabiObjekt*);
		~AusnahmeBehaelter();
		Ausnahme*         GibAusnahme() const;
		Text              GibMeldungstext() const /*throw()*/;
		eMeldTyp          GibSchwere() const;
		eAusnTyp          GibCode() const;
		OklabiObjekt*     GibObjekt() const;
		Text              GibKlassenname() const;
		void              SchreibeReport(Ausgabe*) const;
		const char*       trace() const;
		const char*       what() const;
	protected:
		const char*       getMessage() const;
		const char*       message() const;
		bool              KannVernichten() const;
		eAusnKategorie    GibKategorie() const;
	private:
		Ausnahme* m_pMember;
	};

	class OKLABI_API AbbruchFehler	: public Ausnahme
	{
		public:
			// Ctor
			AbbruchFehler() /*throw()*/;
			AbbruchFehler( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API ServiceException	: public Ausnahme
	{
		public:
			// Ctor
			ServiceException() /*throw()*/;
			ServiceException( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API NichtImplementiert	: public Ausnahme
	{
		public:
			// Ctor
			NichtImplementiert() /*throw()*/;
			NichtImplementiert( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API ObjektGeloescht	: public Ausnahme
	{
		public:
			// Ctor
			ObjektGeloescht() /*throw()*/;
			ObjektGeloescht( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API ObjektGesichert	: public Ausnahme
	{
		public:
			// Ctor
			ObjektGesichert() /*throw()*/;
			ObjektGesichert( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API FehlerEintragen		: public Ausnahme
	{
		public:
			// Ctor
			FehlerEintragen() /*throw()*/;
			FehlerEintragen( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};
	class OKLABI_API FehlerEntfernen		: public Ausnahme
	{
		public:
			// Ctor
			FehlerEntfernen() /*throw()*/;
			FehlerEntfernen( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};
	class OKLABI_API FehlerBewegen		: public Ausnahme
	{
		public:
			// Ctor
			FehlerBewegen() /*throw()*/;
			FehlerBewegen( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};
	class OKLABI_API FehlerOeffnen		: public Ausnahme
	{
		public:
			// Ctor
			FehlerOeffnen() /*throw()*/;
			FehlerOeffnen( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};
	class OKLABI_API FehlerSchreiben		: public Ausnahme
	{
		public:
			// Ctor
			FehlerSchreiben() /*throw()*/;
			FehlerSchreiben( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};
 	class OKLABI_API FehlerLesen		: public Ausnahme
	{
		public:
			// Ctor
			FehlerLesen() /*throw()*/;
			FehlerLesen( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Unerlaubter Bereich
	class OKLABI_API UnerlaubterBereich	: public Ausnahme
	{
		public:
			// Ctor
			UnerlaubterBereich() /*throw()*/;
			UnerlaubterBereich( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Profil falsch
	class OKLABI_API ProfilFehler	: public Ausnahme
	{
		public:
			// Ctor
			ProfilFehler() /*throw()*/;
			ProfilFehler( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Objekterzeugung nicht moeglich wegen OKSTRA-Version
	class OKLABI_API NichtInOKSTRAVersion	: public Ausnahme
	{
		public:
			// Ctor
			NichtInOKSTRAVersion() /*throw()*/;
			NichtInOKSTRAVersion( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Objektart konnte nicht initialisiert werden
	class OKLABI_API FehlerInitialisierung	: public Ausnahme
	{
		public:
			// Ctor
			FehlerInitialisierung() /*throw()*/;
			FehlerInitialisierung( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Eigenschaft nicht gefunden
	class OKLABI_API EigenschaftFehlt	: public Ausnahme
	{
		public:
			// Ctor
			EigenschaftFehlt() /*throw()*/;
			EigenschaftFehlt( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Eigenschaft nicht änderbar
	class OKLABI_API NurLesen	: public Ausnahme
	{
		public:
			// Ctor
			NurLesen() /*throw()*/;
			NurLesen( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Eigenschaft nicht konfiguriert
	class OKLABI_API EigenschaftNichtKonfiguriert	: public Ausnahme
	{
		public:
			// Ctor
			EigenschaftNichtKonfiguriert() /*throw()*/;
			EigenschaftNichtKonfiguriert( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Schlüsseltabelle erforderlich
	class OKLABI_API SchluesseltabelleErforderlich	: public Ausnahme
	{
		public:
			// Ctor
			SchluesseltabelleErforderlich() /*throw()*/;
			SchluesseltabelleErforderlich( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Schlüsseltabelle ist nicht ganzzahlig
	class OKLABI_API SchluesseltabelleGanzErforderlich	: public Ausnahme
	{
		public:
			// Ctor
			SchluesseltabelleGanzErforderlich() /*throw()*/;
			SchluesseltabelleGanzErforderlich( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	// Schlüsseltabelle ist nicht textwertig
	class OKLABI_API SchluesseltabelleTextErforderlich	: public Ausnahme
	{
		public:
			// Ctor
			SchluesseltabelleTextErforderlich() /*throw()*/;
			SchluesseltabelleTextErforderlich( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API DatumUngueltig : public Ausnahme
	{
		public:
			// Ctor
			DatumUngueltig() /*throw()*/;
			DatumUngueltig( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API KoordinatensystemUngueltig : public Ausnahme
	{
		public:
			// Ctor
			KoordinatensystemUngueltig() /*throw()*/;
			KoordinatensystemUngueltig( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API TypUngueltig : public Ausnahme
	{
		public:
			// Ctor
			TypUngueltig() /*throw()*/;
			TypUngueltig( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API EndeErreicht : public Ausnahme
	{
		public:
			// Ctor
			EndeErreicht() /*throw()*/;
			EndeErreicht( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API VersionUngueltig : public Ausnahme
	{
		public:
			// Ctor
			VersionUngueltig() /*throw()*/;
			VersionUngueltig( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API ObjektartVerschieden : public Ausnahme
	{
		public:
			// Ctor
			ObjektartVerschieden() /*throw()*/;
			ObjektartVerschieden( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API VersionVerschieden : public Ausnahme
	{
		public:
			// Ctor
			VersionVerschieden() /*throw()*/;
			VersionVerschieden( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API PropertyNotAvailable : public XmlAusnahme
	{
		public:
			// Ctor
			PropertyNotAvailable() /*throw()*/;
			PropertyNotAvailable( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API InitializationError : public XmlAusnahme
	{
		public:
			// Ctor
			InitializationError() /*throw()*/;
			InitializationError( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API ObjectToUriNotAvailable : public XmlAusnahme
	{
		public:
			// Ctor
			ObjectToUriNotAvailable() /*throw()*/;
			ObjectToUriNotAvailable( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API UriNotResolved : public XmlAusnahme
	{
		public:
			// Ctor
			UriNotResolved() /*throw()*/;
			UriNotResolved( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API IdNotResolved : public XmlAusnahme
	{
		public:
			// Ctor
			IdNotResolved() /*throw()*/;
			IdNotResolved( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API MultipleLocalXmlId : public XmlAusnahme
	{
		public:
			// Ctor
			MultipleLocalXmlId() /*throw()*/;
			MultipleLocalXmlId( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

	class OKLABI_API DateConversionError : public XmlAusnahme
	{
		public:
			// Ctor
			DateConversionError() /*throw()*/;
			DateConversionError( const Text& msg, eAusnTyp cod, eMeldTyp sev, OklabiObjekt*  pObj ) /*throw()*/;
			Text GibKlassenname() const;
			Ausnahme* Kopiere() const;
	};

}	// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFAusnahme
