/*****************************************************************************
* $Id: Eingabe.h 2013-01-24 15:00:00 vogelsang $
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
* 2012-07-27 Interface umbenannt
* 2012-10-18 Formale Verbesserungen
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFEingabe
#define DEFEingabe

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiObjekt.h"

namespace Oklabi
{
	class Eingabe : public OklabiObjekt
	{
		friend class Textpuffer;
		friend class Binaerdaten;
	public:
		virtual void    Oeffne() = 0;
		virtual void    Schliesse() = 0;
		virtual int     LiesZeichen() = 0;
		virtual size_t  GibAnzahl() = 0;
		virtual size_t  GibZeilen() = 0;
		virtual bool    IstBeendet() = 0;
		virtual Text    GibBeschreibung() const = 0;
		virtual bool    IstGueltig() = 0;
		virtual void    ZumAnfang() = 0;
	protected:
		OKLABI_API Eingabe();
		OKLABI_API ~Eingabe();
		bool            OKLABI_API KannVernichten() const;
		void            OKLABI_API Beschreibe(TextListe&) const;
		void            OKLABI_API Austragen(OklabiObjekt*);
		virtual void    OKLABI_API SetzeKodierung(eKodierung);
		OklabiObjekt*   m_pUsedBy;
		eKodierung      m_eEncoding;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFEingabe
