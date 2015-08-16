/*****************************************************************************
* $Id: SQLVerbindung.h 2014-07-10 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2014-2014, Bundesanstalt für Straßenwesen
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
* 2014-07-10 SQL-Anbindung vorbereiten
* 
****************************************************************************/
#ifndef DEFSQLVerbindung
#define DEFSQLVerbindung

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#ifdef OKLABI_SQL

#include <map>

#include "OklabiKern.h"
#include "OklabiObjekt.h"
#include "Ausgabe.h"
#include "XMLEingabeKonverter.h"
#include "Datenbestand.h"
#include "Datenleser.h"

namespace Oklabi
{
	typedef std::map<Text, Text> TextMapType;
	typedef std::map<Text, const Objektart*> ObjektartMapType;
	typedef std::map<Text, EigenschaftListType> EigenschaftMapType;
	typedef std::map<eKoordRefSys, std::pair<Text, Text> > SrsMapType;
	class SQLVerbindung : public OklabiObjekt
	{
	public:
		virtual void             Oeffne() = 0;
		virtual void             Schliesse() = 0;
		virtual bool             Teste() = 0;
		virtual void             BeginneTransaktion() = 0;
		virtual void             Uebernimm() = 0;
		virtual void             FuehreZurueck() = 0;
		virtual int              Aendere(const Text&, bool = true) = 0;
		virtual int              Loesche(const Text&, bool = true) = 0;
		virtual Datenleser*      Lies(const Text&) = 0;
		virtual void             GibVersionen(VersionListe& res) = 0;
		virtual void             GibObjektarten(const Version*, bool) = 0;
		virtual Text             GibBeschreibung() const = 0;
		bool                     Schreibe(Datenbestand*, Fortschrittswaechter* = 0, Abbruchsignal* = 0);
		static Text              Zwischentabelle();
		static void              WandleSRS(eKoordRefSys, Text&, Text&);
	protected:
		OKLABI_API SQLVerbindung();
		OKLABI_API ~SQLVerbindung();
		virtual Text             GibBoolean(bool) const = 0;
		virtual Text             GibIndexDefinition(const Text&, const Text&, const Text&) const = 0;
		virtual Text             GibZwTabIndexDefinition(const Text&, const Text&) const = 0;
		virtual Text             GibGeometrieDefinition(const Text&, const Text&, int, const Text&, int) const = 0;
		bool OKLABI_API          KannVernichten() const;
        void OKLABI_API          Beschreibe(TextListe& deskr) const;
        bool OKLABI_API          Verbose() const;
        void OKLABI_API          Verbose(bool);
        size_t OKLABI_API        Timeout() const;
        void OKLABI_API          Timeout(size_t);
        void OKLABI_API          SetzeProtokoll(Ausgabe*);
		bool OKLABI_API          PruefeObjektartTabelle(const Objektart* oa);
		static Text OKLABI_API   GibTabellenname(const Objektart*);
		static Text OKLABI_API   GibTabellensuffix(const Version*);
		       Text OKLABI_API   ErzeugeZwischentabellendefinition(const Version*, const Text&);
		static Text OKLABI_API   GibSpaltenname(const Eigenschaft* eig);
		static void OKLABI_API   GibSpalten(const Objektart* oa, const EigenschaftListType& properties, EigenschaftListType& res);
		Text OKLABI_API          IstVorhanden(Fachobjekt* fObj, const Objektart* oa, const Text& objId, const EigenschaftListType& spalten, Text& key);
		UINT64 OKLABI_API        GibAnzahl(const Objektart* oa);
		Text OKLABI_API          SchreibeRelation(Fachobjekt* src, const Eigenschaft* eig, const AnyType* any);
		Text OKLABI_API          SchreibeRelation(const Text& zwTab, const Text& sid, Fachobjekt* src, const Eigenschaft* eig, Fachobjekt* trg, int zaehl, bool bSingle);
		UINT64 OKLABI_API        IstRelationVorhanden(const Text& zwTab, const Text& sid, const Text& tid, Fachobjekt* src, const Eigenschaft* eig, const Fachobjekt* trg);
		Text OKLABI_API          ErzeugeTabellendefinition(const Objektart* oa);
		void OKLABI_API          GibVersionen(const Text&, const Text&, VersionListe& res);
		void OKLABI_API          GibObjektarten(const Version*, bool, const Text&, const Text&, bool);
		bool OKLABI_API          BereinigeTabellen(const Version*, Fortschrittswaechter*, bool);
		bool OKLABI_API          UebertrageFachobjekt(bool bCheck, Fachobjekt* fObj, const Objektart* oa, const Text& objId);

		bool                     m_bVerbose;
		bool                     m_bOpen;
		bool                     m_bStrict;
		bool                     m_bGeometry;
		bool                     m_bReset;
        size_t                   m_nTimeout;
		Text                     m_strPrefix;
		Text                     m_strGeoPrefix;
        Ausgabe*                 m_pProtokoll;
		eKoordRefSys             m_eSRS;
		TextMapType              m_mapEnumEntries;
		ObjektartMapType         m_mapObjektart;
		ObjektartMapType         m_mapIndex;
		EigenschaftMapType       m_mapEigenschaft;
		EigenschaftMapType       m_mapKtEigenschaft;
	};
}// End of namespace Oklabi

#endif	// OKLABI_SQL

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFSQLVerbindung
