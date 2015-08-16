/*****************************************************************************
* $Id: AusgabeKonverter.h 2013-02-04 15:00:00 vogelsang $
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
* 2010-11-10 Kompakte Speicherung von Geometrie
* 2010-11-23 Komprimierte Ein- und Ausgabe
* 2011-05-10 Normierte Ausgabe
* 2013-02-04 Profile
* 
****************************************************************************/
#ifndef DEFOutputCv
#define DEFOutputCv

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "Datenbestand.h"
#include "FblVersion.h"

namespace Oklabi
{
class OKLABI_API AusgabeKonverter : public OklabiObjekt
{
	friend class Binaerdaten;
public:
	virtual void                Entlade(Datenbestand*) = 0;
	virtual void                SetzeSortierung(eSort = ohne) = 0;
	virtual void                TransportiereErweiterungen(bool = false) = 0;
	virtual void                SetzeMetadaten(eMetadaten, const Text&) = 0;
	virtual void                SetzeFblVersion(const FblVersion*) = 0;
	virtual void                Komprimiere(bool) = 0;
	virtual void                SetzeKonkordanz(Ausgabe* pDatei, const Text& fieldDelimit = ";",
		                                        const Text& stringDelimit = "\"", const Text& idPrefix = "#");
	virtual void                SetzeProfilerkennung(bool = true) = 0;

protected:
	AusgabeKonverter();
	~AusgabeKonverter();
	Ausgabe*                    m_pDatei;
	Ausgabe*                    m_pKonkordanz;
	Text                        m_strFieldDelimiter;
	Text                        m_strStringDelimiter;
	Text                        m_strIdPrefix;

	Version                     m_Version;
	FblVersion                  m_FblVersion;
	eSort                       m_eSort;
	int                         m_nProgress;
	bool                        m_bExtension;
	bool                        m_bZipped;
	bool                        m_bUseProfile;
	bool                        KannVernichten() const;
	void                        Nachbehandlung();
	bool                        Vorbehandlung(Datenbestand*);
	static bool                 Enkodiere(const Text&, const unsigned char*, size_t, Text&);
	virtual void                KonkordanzSetzen(Oklabi::Ausgabe* pDatei, const char* pFieldDelimit,
		                                         const char* pStringDelimit, const char* pIdPrefix) = 0;
};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFOutputCv
