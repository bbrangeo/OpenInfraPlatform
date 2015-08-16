/*****************************************************************************
* $Id: TextpufferAusgabe.h 2013-01-24 15:00:00 vogelsang $
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
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFTextpufferAusgabe
#define DEFTextpufferAusgabe

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "Ausgabe.h"
#include "Binaerdaten.h"

namespace Oklabi
{
	class Textpuffer;
	class OKLABI_API TextpufferAusgabe : public Ausgabe
	{
		friend class Textpuffer;
		friend class Binaerdaten;
	private:
		TextpufferAusgabe();	
		~TextpufferAusgabe();
		static Ausgabe*      Erzeuge(Textpuffer*);
		static Ausgabe*      Erzeuge(Binaerdaten*);
		void	             SetzePuffer(const Text&);
		Textpuffer*          m_pBuffer;
		Binaerdaten*         m_pBinary;

	public:
		Text                 GibPuffer();
		const unsigned char* GibZeiger();

		void                 Oeffne();
		void                 SchreibeZeichen(const int&);
		void                 SchreibeZeile(const Text&);
		void                 SetzeKodierung(eKodierung);
		void                 Schliesse();
		void	             Leere();
		Text                 GibBeschreibung() const;
		Text	             GibKlassenname() const;
	};
}	// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// TextpufferAusgabe
