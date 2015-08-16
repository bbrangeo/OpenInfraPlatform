/*****************************************************************************
* $Id: DBImporteur.h 2012-10-08 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2018, Bundesanstalt für Straßenwesen
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
* 2011-12-05 Abschlussbehandlung für DBImporteur
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 
****************************************************************************/
#ifndef DEFDBImporteur
#define DEFDBImporteur

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "AnyType.h"

namespace Oklabi
{
class Collector : public OklabiRoot
{
	friend class DBImporteur;
public:
	Collector();
	Collector(const Text& z, const Text& p, const Oklabi::Objektart* pO);
	Collector(const Collector& c);
	Collector& operator=(const Collector& c);
	~Collector();
private:
	Text zid;
	Text prop;
	const Objektart* pOA;
};
typedef std::multimap<Text, Collector> MapPendingType;

class OKLABI_API DBImporteur : public OklabiObjekt
{
	friend class Datenbestand;
	friend class Fachobjekt;
public:
	static DBImporteur*       Erzeuge(Datenbestand*);
	Text                      GibKlassenname() const;
	void                      Uebernimm(const Text& ns, const AnyType* id, const Text& oan, const Text& en, const AnyType* w, bool sw = true, bool hz = true);
	void                      Verknuepfe(const Text& qns, const AnyType* qid, const Text& qoan, const Text& en, const Text& zns, const AnyType* zid, const Text& zoan, bool hz = true);
	size_t                    Verflechte();

private:
	DBImporteur();
	~DBImporteur();
	bool                      KannVernichten() const;

	Datenbestand*             m_pBestand;
	MapPendingType            m_mapPending;
};
}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFDBImporteur
