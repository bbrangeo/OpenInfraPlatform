/*****************************************************************************
* $Id: TextpufferEingabe.h 2013-01-24 15:00:00 vogelsang $
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
* 2012-07-27 Interface umbenannt
* 2013-01-24 Zeichenkodierung
* 
****************************************************************************/
#ifndef DEFTextpufferEingabe
#define DEFTextpufferEingabe

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "Eingabe.h"
#include "Binaerdaten.h"

namespace Oklabi
{
	class Textpuffer;
	class OKLABI_API TextpufferEingabe : public Eingabe
	{
		friend class Binaerdaten;
		friend class XMLEingabeKonverter;
	private:
		TextpufferEingabe();	
		~TextpufferEingabe();	
		size_t               m_nCurPos;
		Textpuffer*          m_pBuffer;
		Binaerdaten*         m_pBinary;
		static               Eingabe* Erzeuge(Binaerdaten* pPuf);

	public:
		static               Eingabe* Erzeuge(Textpuffer* pPuf);
		Text                 GibPuffer();
		const unsigned char* GibZeiger();
		size_t               GibZeilen();
		bool                 IstBeendet();
		void                 SetzeKodierung(eKodierung);

		void                 Oeffne();
		void                 Schliesse();
		int                  LiesZeichen();
		size_t               GibAnzahl();
		Text                 GibBeschreibung() const;
		Text	             GibKlassenname() const;
		bool                 IstGueltig();
		void                 ZumAnfang();
	};
}	// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFTextpufferEingabe
