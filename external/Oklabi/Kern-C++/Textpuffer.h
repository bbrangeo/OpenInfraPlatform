/*****************************************************************************
* $Id: Textpuffer.h 2012-10-18 15:57:11 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2012, Bundesanstalt für Straßenwesen
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
* 2012-07-27 Interface umbenannt
* 2012-10-18 Formale Verbesserungen
* 
****************************************************************************/
#ifndef DEFTextpuffer
#define DEFTextpuffer

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "Ausgabe.h"
#include "Eingabe.h"

namespace Oklabi
{
	class OKLABI_API Textpuffer : public OklabiObjekt
	{
		friend class TextpufferAusgabe;
		friend class TextpufferEingabe;
		friend class XMLEingabeKonverter;
	private:
		Text                 m_strText;
		Textpuffer();	
		~Textpuffer();
		void                 Austragen(OklabiObjekt*);
		bool                 IstGueltig();
		bool                 IstBeendet(Eingabe*, size_t);
		int                  LiesZeichen(Eingabe*, size_t&);
		size_t               GibZeilen(OklabiObjekt*);
		size_t               GibAnzahl(OklabiObjekt*);
		Ausgabe*             m_pAusgabe;
		std::set<Eingabe*>   m_setEingabe;
		std::set<Eingabe*>   m_setEingabeAktiv;
		std::set<Ausgabe*>   m_setAusgabe;
		void                 Oeffne(Eingabe*);
		void                 Oeffne(Ausgabe*);
		void	             SetzePuffer(const Text&);
		void                 SchreibeZeichen(Ausgabe*, const int&);
		void                 Schliesse(Eingabe*);
		void                 Schliesse(Ausgabe*);
		void	             Leere(Ausgabe*);
		bool                 KannVernichten() const;

	public:
		static Textpuffer*   Erzeuge(const Text& = "");
		static Textpuffer*   Erzeuge(Eingabe*);
		Eingabe*             GibEingabe();
		Ausgabe*             GibAusgabe();
		Text                 GibPuffer();
		const unsigned char* Gibzeiger();
		Text	             GibKlassenname() const;
	};
}	// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFTextpuffer
