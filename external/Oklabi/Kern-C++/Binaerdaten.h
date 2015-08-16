/*****************************************************************************
* $Id: Binaerdaten.h 2014-01-17 15:00:00 vogelsang $
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
* 2012-10-18 Formale Verbesserungen
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFBinaerdaten
#define DEFBinaerdaten

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiObjekt.h"
#include "Ausgabe.h"
#include "Eingabe.h"

namespace Oklabi
{
	class Ausgabe;
	class Eingabe;
	class OKLABI_API Binaerdaten : public OklabiObjekt
	{
		friend class AnyType;
		friend class CTEAusgabeKonverter;
		friend class CTEEingabeKonverter;
		friend class TextpufferAusgabe;
		friend class TextpufferEingabe;
		friend class XMLAdapter;
		friend class XMLAusgabeKonverter;
		friend class XMLEingabeKonverter;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
	public:
		static Binaerdaten*     Erzeuge();
		Binaerdaten*            Kopiere() const;
		Ausgabe*                GibAusgabe();
		Eingabe*                GibEingabe(bool enc = false);
		Text                    GibText() const;
		Text                    GibKlassenname() const;
		size_t                  GibAnzahl() const;
		const unsigned char*    GibPuffer() const;
	private:
		Binaerdaten();
		~Binaerdaten();
		Binaerdaten(const Binaerdaten& binData);
		Binaerdaten(const BinaerdatenType& binData);
		Binaerdaten& operator=(const Binaerdaten& binData);
		bool operator==(const Binaerdaten&) const;
		bool operator!=(const Binaerdaten& binData) const;
		bool operator<(const Binaerdaten& binData) const;

		bool                    KannVernichten() const;
		size_t                  GibZeilen(OklabiObjekt*);

		void                    Austragen(OklabiObjekt*);
		void                    Oeffne(Eingabe*);
		void                    Oeffne(Ausgabe*);
		void                    Schliesse(Eingabe*);
		void                    Schliesse(Ausgabe*);
		void	                Leere(Ausgabe*);
		int					    LiesZeichen(Eingabe*, size_t&);
		void                    SchreibeZeichen(Ausgabe*, const int&);
		bool                    IstGueltig();
		bool                    IstBeendet(Eingabe*, size_t);

		mutable BinaerdatenType m_BinData;
		Ausgabe*                m_pAusgabe;
		std::set<Eingabe*>      m_setEingabe;
		std::set<Eingabe*>      m_setEingabeAktiv;
		std::set<Ausgabe*>      m_setAusgabe;
	};
	typedef Binaerdaten* BinaerdatenPtr;
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFBinaerdaten
