/*****************************************************************************
* $Id: OklabiObjekt.h 2014-01-17 15:00:00 vogelsang $
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
* 2010-08-24 Interface GibDokumentation() ergänzt
* 2010-10-28 Löschung Datenbestand beschleunigen
* 2011-11-09 Vergleich von Fachobjekten über Objektnummer
* 2012-10-01 Protokollant nutzt Ausgabe
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2013-03-11 Harmonisierung der Schnittstelle
* 2013-12-17 Instanzen für Wert-Objekte zulassen
* 2014-01-13 Speicheroptimierungen beim Laden von OKSTRA-Daten
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-09-18 Speicherprobleme unter 32 Bit bei grossen Dateien
* 
****************************************************************************/
#ifndef DEFOklabiObjekt
#define DEFOklabiObjekt

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "oklabidll.h"
#include "OklabiBasis.h"
#include "OklabiRoot.h"
#include "SyncClasses.h"

namespace Oklabi
{

class Enumerator;

class OklabiObjekt : public OklabiRoot
{
	friend class Aggregat;
	friend class Umgebung;
	friend class Eingabe;
	friend class Ausgabe;
	friend class Transaktion;
	friend class TextEnumerator;
	friend class Profil;
	friend class ObjektFreigabe;
	friend class SchemaDBAdapter;
#if defined(OKLABI_MEMOPT_2)
	friend class PasIdentifizierer;
	friend class ObjektVertreter;
	friend class Fachobjekt;
#endif
	friend class OklabiSynchronisierer;
public:
	virtual void OKLABI_API Vernichte() const;
	virtual Text OKLABI_API GibDokumentation() const;
	virtual Text OKLABI_API GibKlassenname() const = 0;
	void OKLABI_API Referenziere() const;
	void OKLABI_API Dereferenziere() const;
	UINT64 OKLABI_API GibIdentifizierer() const;
	static OKLABI_API OklabiObjekt* SucheIdentifizierer(UINT64);
	static OKLABI_API Enumerator* GibEnumerator(OklabiObjekt*);
#if defined(OKLABI_MEMOPT_2)
	// Bestimmt, ob Objekt über Stellverterter verwaltet werden kann oder nicht
	virtual bool OKLABI_API HatStellvertreter() const;
#endif

	static const char*           pStrOklabiDate;
	static const char*           pStrOklabiVersion;
	static const char*           pStrOklabiVersionURL;
	static const char*           pStrCompilerVersion;
	static const char*           pStrPlatformVersion;

protected:
	// Versteckter Konstruktor/Destruktor
	OKLABI_API OklabiObjekt();
	virtual OKLABI_API ~OklabiObjekt();
#if defined(OKLABI_MEMOPT_2)
	OklabiObjekt(UINT64);
#endif

	// Bestimmt, ob Objekt vernichtet werden darf oder nicht
	virtual bool OKLABI_API KannVernichten() const = 0;

	// Löst wechselseitige Abhängigkeiten auf, z.B. zwischen Eingabe und Textpuffer
	virtual void OKLABI_API Austragen(OklabiObjekt*);

	// Liefert Text(e) für TextEnumerator
	virtual void OKLABI_API Beschreibe(TextListe&) const;

	// Hilfsfunktionen
#ifdef OKLABI_STATISTIK
	static bool OKLABI_API GibStatistik();
#endif

	// Lebensdauerverwaltung, Objektzustand
	mutable OklabiObjekt*        m_pObjQueue;					// pointer to successor in queue
	mutable size_t               m_ObjStatus;					// object status information, reference counter
	UINT64                       m_nObjNr;						// unique object identifier
	bool OKLABI_API IstGeschuetzt(const OklabiObjekt*) const;	// is object protected?
	bool OKLABI_API Schuetze(bool) const;						// (un)protect object
	bool OKLABI_API IstGeloescht(const OklabiObjekt*) const;	// is object deleted?
	bool OKLABI_API SetzeGeloescht(bool) const;					// (un)delete object
	bool OKLABI_API IstImplizit(const OklabiObjekt*) const;		// flagged implicit state?
	bool OKLABI_API SetzeImplizit(bool) const;					// (un)flag implicit state
	bool OKLABI_API IstVernichtbar(const OklabiObjekt*) const;	// flagged destroyable state?
	bool OKLABI_API SetzeVernichtbar(bool) const;				// (un)flag destroyable state

private:
	static UINT64                m_nObjCount;					// total object count
	static Sync::CriticalRegion  OklabiObjektExclusive;			// threading
	static UINT64				 m_nObjTableSize;				// hash table size
	static UINT64				 m_nObjTableCount;				// number of object in table
	static OklabiObjekt**		 m_pObjTable;					// object table
	static bool					 ObjektEintragen(OklabiObjekt*);// enter object
	static bool					 ObjektAustragen(OklabiObjekt*);// remove object
	static void					 Finalisiere();					// cleanup
	typedef std::multimap<UINT64, OklabiObjekt*> OIDMapType;
	static OIDMapType*           m_pObjIDMap;
	void                         Registriere(int);
	void                         InitObjekt(UINT64);
public:
	static void OKLABI_API       Report(size_t, bool = true);
};

// Diese Klasse dient dazu, die Synchronisierung für OklabiObjekte
// bei der (De-)Referenzierung von aussen sicher zu stellen. Beim
// Verlassen des Code-Blockes, in dem das Objekt angelegt wurde,
// erfolgt die automatische Freigabe auch wenn der auslösende Anlass
// eine Ausnahme ist.
// Die Benutzung erfolgt durch simples Anlegen eines Objektes dieser
// Klasse auf dem Stack (nicht per new!).
class OKLABI_API OklabiSynchronisierer : public OklabiRoot
{
public:
	OklabiSynchronisierer();
	~OklabiSynchronisierer();
private:
#ifdef OKLABI_KERN
	Sync::CriticalRegionOwnership*
#else
	void*
#endif
		 m_pSection;
};

// Diese Klasse dient dazu, OklabiObjekte am Ende eines Codeblockes
// freizugeben, sobald der Block verlassen wird (auch im Falle von
// Ausnahmen). Es werden nur Objekte vernichtet, die nicht geschützt
// sind und vernichtet werden dürfen.
// Bitte nur benutzen falls das Objekt wirklich nicht mehr gebraucht
// wird, wenn der Codeblock verlassen wird!
// Die Benutzung erfolgt durch simples Anlegen eines Objektes dieser
// Klasse auf dem Stack (nicht per new!).
class OKLABI_API ObjektFreigabe : public OklabiRoot
{
public:
	ObjektFreigabe(OklabiObjekt* pObj);
	~ObjektFreigabe();
private:
	OklabiObjekt* m_pObjekt;
};

#ifdef OKLABI_MEMOPT_2
#if defined(CYGWIN) || defined(LINUX)
class Fachobjekt;
#endif
class OKLABI_API ObjektVertreter : public OklabiObjekt
{
	friend class OklabiObjekt;
	friend class Fachobjekt;
	friend class CTEEingabeKonverter;
	friend class CTEAusgabeKonverter;
	friend class XMLEingabeKonverter;
	friend class XMLAusgabeKonverter;
public:
	operator const Fachobjekt*() const;
	const Fachobjekt* operator->() const;
	operator Fachobjekt*();
	Fachobjekt* operator->();
	Fachobjekt* IstGeladen() const;
protected:
	ObjektVertreter();
	ObjektVertreter(Fachobjekt*);
	~ObjektVertreter();
	bool Vergleiche(Fachobjekt*) const;
	bool KannVernichten() const;
	Text GibKlassenname() const;
private:
	UINT64 m_Ident;
};
#endif
}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFOklabiObjekt
