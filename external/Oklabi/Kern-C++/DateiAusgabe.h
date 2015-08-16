/*****************************************************************************
* $Id: DateiAusgabe.h 2013-01-24 11:11:11 vogelsang $
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
* 2010-11-23 Komprimierte Ein- und Ausgabe
* 2011-11-11 Anpassungen für CYGWIN
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFAusgabeDatei
#define DEFAusgabeDatei

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "Ausgabe.h"
#ifdef OKLABI_KERN
#ifdef CYGWIN
#include <stdio.h>
#endif
#include "zlib.h"
#else
#define gzFile void*
#endif

namespace Oklabi
{
	class OKLABI_API DateiAusgabe : public Ausgabe
	{
	private:
#ifdef OKLABI_KERN
		Text    m_strFileName;
		FILE*   m_pFile;
		gzFile  m_pZipFile;
		DateiAusgabe();	
		~DateiAusgabe();
		void    SetzeDateiname(const Text&);
#endif

	public:
		static  Ausgabe* Erzeuge(Text pf="oklabi.txt");
		Text    GibPfadname() const;

		void    Oeffne();
		void    SchreibeZeichen(const int&);
		void    SchreibeZeile(const Text&);
		void    SetzeKodierung(eKodierung);
		void	Leere();
		void    Schliesse();
		Text    GibBeschreibung() const;
		Text	GibKlassenname() const;
	};
}	// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFAusgabeDatei
