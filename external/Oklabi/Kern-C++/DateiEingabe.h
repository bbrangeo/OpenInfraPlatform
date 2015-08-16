/*****************************************************************************
* $Id: DateiEingabe.h 2013-01-24 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt f�r Stra�enwesen
*
* Erstellt durch interactive instruments GmbH, Bonn
*
* Die Nutzungsbestimmungen f�r die Software und die zugeh�rigen Bestandteile
* sind unter folgender Adresse einsehbar:
*    http://www.okstra.de/oklabi/Lizenz/Nutzung.txt
* 
* Der Hinweis auf das Copyright und die Lizenzbestimmungen ist in allen
* Kopien der Software oder wesentlichen Bestandteilen daraus aufzunehmen.
*
* Die Erkl�rungen zum Gew�hrleistungsausschlu� und zur Haftungsbegrenzung 
* befinden sich bei den Nutzungsbestimmungen.
* 
* 2010-11-23 Komprimierte Ein- und Ausgabe
* 2012-07-27 Interface umbenannt
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFEingabeDatei
#define DEFEingabeDatei

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "Eingabe.h"
#ifdef OKLABI_KERN
#include "zlib.h"
#else
#define gzFile void*
#endif

namespace Oklabi
{
	class OKLABI_API DateiEingabe : public Eingabe
	{
		friend class CTEEingabeKonverter;
		friend class XMLEingabeKonverter;
	private:
#ifdef OKLABI_KERN
		DateiEingabe();
		~DateiEingabe();
		void    SetzePfadname(const Text&);
		Text    m_strFileName;
		FILE*   m_pFile;
		gzFile  m_pZipFile;
		size_t  m_nLines;
		size_t  m_nChars;
		mutable bool m_bSilent;
#endif

	public:
		static  Eingabe* Erzeuge(const Text& pf="oklabi.txt");
		Text    GibPfadname() const;
		size_t  GibZeilen();

		void    Oeffne();
		void    Schliesse();
		int     LiesZeichen();
		size_t  GibAnzahl();
		bool    IstBeendet();
		void    SetzeKodierung(eKodierung);
		Text    GibBeschreibung() const;
		Text	GibKlassenname() const;
		bool    IstGueltig();
		void    ZumAnfang();
	};
}	// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFEingabeDatei
