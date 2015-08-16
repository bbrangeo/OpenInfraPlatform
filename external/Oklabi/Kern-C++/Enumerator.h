/*****************************************************************************
* $Id: Enumerator.h 2011-11-14 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2011, Bundesanstalt für Straßenwesen
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
* 2011-08-12 template-Defintionen überarbeitet
* 2011-11-14 Erweiterung Geometrie-Schnittstelle
* 
****************************************************************************/
#ifndef DEFEnumerator
#define DEFEnumerator

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "OklabiIntern.h"

namespace Oklabi
{
	class OKLABI_API Enumerator : public OklabiObjekt
	{
	public:
		virtual bool                      IstBeendet() const = 0;
		virtual void                      Weiter() = 0;
		virtual void                      ZumAnfang() = 0;
		template<class T> T               GibObjekt();
	protected:
		Enumerator();
		~Enumerator();
		virtual eEnumeratorTyp            GibEnumeratorTyp() const = 0;
	};

	class OKLABI_API TextEnumerator : public Enumerator
	{
		friend class OklabiObjekt;
		friend class Enumerator;
	public:
		Text                              GibKlassenname() const;
		template<class T> T               GibObjekt();
		void                              Weiter();
		bool                              IstBeendet() const;
		void                              ZumAnfang();
	protected:
		bool                              KannVernichten() const;
		eEnumeratorTyp                    GibEnumeratorTyp() const;
	private:
		TextEnumerator();
		~TextEnumerator();
		void                              Initialisiere() const;
		mutable bool                      m_bStart;
		OklabiObjekt*                     m_pObjekt;
		mutable TextListe                 m_Deskr;
		mutable TextListe::const_iterator m_Iter;
	};

	// Spezialisierungen
	template<> OKLABI_API Text TextEnumerator::GibObjekt<Text>();
}	// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFEnumerator
