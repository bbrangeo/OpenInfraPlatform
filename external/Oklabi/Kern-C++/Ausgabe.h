/*****************************************************************************
* $Id: Ausgabe.h 2013-01-24 15:00:00 vogelsang $
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
* 2011-11-23 Automatisch flushen
* 2012-10-01 Protokollant nutzt Ausgabe
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFAusgabe
#define DEFAusgabe

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiObjekt.h"

namespace Oklabi
{
	class Ausgabe : public OklabiObjekt
	{
		friend class CTEAusgabeKonverter;
		friend class XMLAusgabeKonverter;
		friend class DateiProtokollant;
		friend class TextpufferProtokollant;
		friend class Protokollant;
		friend class Textpuffer;
		friend class Binaerdaten;
#ifdef OKLABI_SQL
		friend class SQLVerbindung;
#endif
#ifdef OKLABI_SPATIALITE
		friend class SpatialiteVerbindung;
#endif
	public:
		virtual void            Oeffne() = 0;
		virtual void            Schliesse() = 0;
		virtual void            SchreibeZeichen(const int&) = 0;
		virtual void            Leere() = 0;
		virtual Text            GibBeschreibung() const = 0;
	protected:
		OKLABI_API Ausgabe();
		OKLABI_API ~Ausgabe();
		bool OKLABI_API         KannVernichten() const;
		void OKLABI_API         Beschreibe(TextListe&) const;
		virtual void OKLABI_API SetzeKodierung(eKodierung);
		virtual void OKLABI_API SchreibeZeile(const Text&);
		virtual void OKLABI_API Komprimiere(bool);
		void OKLABI_API         Austragen(OklabiObjekt*);
		void OKLABI_API         Eintragen(OklabiObjekt*);
		const char*             Transkodiere(int, eKodierung);
		OklabiObjekt*           m_pUsedBy;
		bool                    m_bZipped;
		size_t                  m_nCharsOut;
		eKodierung              m_eEncoding;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFAusgabe
