/*****************************************************************************
* $Id: XMLAusgabeGenerator.h 2013-02-04 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2012-2013, Bundesanstalt für Straßenwesen
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
* 2012-05-14 Inkrementelles Entladen
* 2012-09-10 BoundingBox beim Entladen von Beständen
* 2013-02-04 Profile
* 
****************************************************************************/

#include "OklabiPackaging.h"

#ifndef DEFXMLAusgabeGenerator
#define DEFXMLAusgabeGenerator

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "AusgabeKonverter.h"
#include "XMLAusgabeKonverter.h"

namespace Oklabi
{
class OKLABI_API XMLAusgabeGenerator : public AusgabeKonverter
{
	friend class XMLAdapter;
	friend class XMLAusgabeKonverter;
public:
	static XMLAusgabeGenerator*	Erzeuge(Ausgabe*);
	void                        SetzeSortierung( eSort = ohne );
	void                        TransportiereErweiterungen( bool = false );
	void                        SetzeMetadaten(eMetadaten, const Text&);
	void                        SetzeRootTag(eRootTag, const Text&);
	void                        SetzeSchemaLocation(const Text& strSL);
	bool                        SetzeZeichensatz(const Text& strCode);
	void                        Entlade( Datenbestand* pDB );
	void                        SetzeFblVersion(const FblVersion*);
	void                        Komprimiere(bool);
	void                        SetzeProfilerkennung(bool = true);
	Text						GibKlassenname() const;

	void                        Oeffne( const Version* );
	void                        Oeffne( const Version*, double topritex, double topritey, double botleftx, double botlefty );
	void                        Entlade( Datenbestand* pDB, bool bDelete );
	void                        Entlade( Fachobjekt* pFO, bool bDelete = true );
	void                        Schliesse();
	bool                        IstGeoeffnet() const;
	bool                        IstGeschlossen() const;

private:
	XMLAusgabeGenerator();
	~XMLAusgabeGenerator();

	bool                        m_bOpened;
	bool                        m_bClosed;
	bool                        m_bOwned;

	Datenbestand*               m_pDomain;
	XMLAusgabeKonverter*        m_pXMLOutputCv;

	void                        Oeffne( const Version*, const BoundingBox&, Datenbestand* = NULL );
	void                        KonkordanzSetzen(Ausgabe* pDatei, const char* pFieldDelimit,
												 const char* pStringDelimit, const char* pIdPrefix);
};

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFXMLAusgabeGenerator
