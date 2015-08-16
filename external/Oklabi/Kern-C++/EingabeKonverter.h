/*****************************************************************************
* $Id: EingabeKonverter.h 2014-01-17 15:00:00 vogelsang $
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
* 2010-11-10 Kompakte Speicherung von Geometrie
* 2010-11-23 Komprimierte Ein- und Ausgabe
* 2010-12-14 Vorschau auf Eingabedaten
* 2012-04-03 Referenziell gebundene Objekte in XML mitnehmen
* 2012-04-24 Fehler bei Analyse der Version der FB-Liste
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2013-02-04 Profile
* 2013-11-18 Transformierer eingeführt
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#ifndef DEFInputCv
#define DEFInputCv

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiIntern.h"
#include "Objektart.h"
#include "Datenbestand.h"
#include "FblVersion.h"

namespace Oklabi
{
class OKLABI_API EingabeKonverter : public OklabiObjekt
{
	friend class XMLAdapter;
public:
	virtual Datenbestand*       Lade(Objektartfilter* = 0, Objektartfilter* = 0) = 0;
	virtual void                TransportiereErweiterungen(bool = false) = 0;
	virtual void                VerschmelzeSymbolischeObjekte(bool = true) = 0;
	virtual Version*            GibVersion() = 0;
	virtual FblVersion*         GibFblVersion() = 0;
	virtual TextListe           GibMetadaten(eMetadaten) = 0;
	virtual TextListe           GibObjektarten() = 0;
	virtual size_t              GibAnzahlObjekte(const Text&) = 0;
	virtual void                SetzeProfilerkennung(bool = true) = 0;
	virtual void                Transformiere(eKoordRefSys) = 0;

protected:
	EingabeKonverter();
	~EingabeKonverter();
	bool                        GetVersion( int& nHaupt, int& nUnter, int& nRelease, int& nVersion, Text& strFS );
	void                        SetVersion( int nHaupt, int nUnter, int nRelease, const char* pszSchema, bool bVers, int nSpec = 0 );
	virtual bool                E_FSSchemaIdentifiers(TextListe&) = 0;
	int                         SetFblVersion(bool);
	bool                        SetProfil(bool);
	void                        Fehler( const Text& err, eMeldTyp nLevel = fehler );
	bool                        KannVernichten() const;
	Text                        NachbehandlungLaden(OklabiObjekt*, Datenbestand*, Objektartfilter*, bool&, bool = false);
	bool                        Aufraeumen(Datenbestand*, Objektartfilter*);
	bool                        PruefeProfil(Datenbestand*);
	void                        VerschmelzeFachobjekte(Datenbestand*);
	virtual void                Identitaetswechsel(FachobjektPtr, FachobjektPtr, const Text&) = 0;

	static bool                 Dekodiere(const Text&, const char*, size_t, BinaerdatenType&, Text&);

	Version                     m_Version;
	FblVersion                  m_FblVersion;
	eFbVersion                  m_eFbVersion;
	eBundesland                 m_eBundesland;
	eKoordRefSys                m_eTargetSRS;
	Text                        m_strEntNo;
	Text                        m_strCurCls;
	int                         m_nProgress;
	ClassToSymbolMapType        m_mapClassToSymbol;
	FachobjektListeImpl         m_listSymbol;
	int                         m_nFblTest;
	int                         m_nFblStatus;
	int                         m_nProfilTest;
	int                         m_nProfilStatus;
	Text                        m_strProfilName;
	bool                        m_bStatistik;
	bool                        m_bReference;
	bool                        m_bMerge;
	bool                        m_bUseProfile;
	bool                        m_bTransform;

	typedef                     std::map<Text, FachobjektPtr> mapSymbolObjectType;
	mapSymbolObjectType         m_mapSymbol;
};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFInputCv
