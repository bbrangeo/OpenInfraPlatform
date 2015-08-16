/*****************************************************************************
* $Id: Fremdobjekt.h 2013-12-12 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2013-2013, Bundesanstalt f�r Stra�enwesen
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
* 2013-12-12 Fremdobjekt f�r Nachbarstandards eingef�hrt
* 
****************************************************************************/
#ifndef DEFFremdobjekt
#define DEFFremdobjekt

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiObjekt.h"
#include "Fachobjekt.h"
#include "Geometrie.h"
#include "Eingabe.h"

namespace Oklabi
{
	class Fremddatenbestand;
	class Fremdobjekt : public OklabiObjekt
	{
		friend class Umgebung;
		friend class Fremddatenbestand;
	public:
		virtual Text                         GibID() const = 0;
		virtual Text                         GibObjektartname() const = 0;
		virtual Text                         GibVersion() const = 0;
		virtual Geometrie*                   GibGeometrie() const = 0;
		OKLABI_API bool                      Verknuepfe(Fachobjekt*);
		OKLABI_API bool                      Loese(Fachobjekt*);
		OKLABI_API FachobjektMengeImpl       GibFachobjekte() const;
	protected:
		OKLABI_API Fremdobjekt();
		OKLABI_API ~Fremdobjekt();
		OKLABI_API bool                      KannVernichten() const;
	private:
		FachobjektMengeImpl                  m_SetObjekte;
		Fremddatenbestand*                   m_pBestand;
		bool                                 m_bLoeschend;
	};

	class OKLABI_API Fremddatenbestand : public OklabiObjekt
	{
		friend class Fremdobjekt;
	public:
		static Fremddatenbestand*            Erzeuge();
		void                                 FuegeHinzu(Fremdobjekt*);
		size_t                               GibAnzahl() const;
		FremdobjektListe                     GibObjekte() const;
		Fremdobjekt*                         GibObjekt(size_t) const;
		Fremdobjekt*					     Suche(const Text&) const;
		Text                                 GibKlassenname() const;
		bool                                 KannVernichten() const;
	private:
		Fremddatenbestand();
		~Fremddatenbestand();
		bool                                 Entferne(Fremdobjekt*);
		size_t                               m_nSize;
		std::vector<Fremdobjekt*>*           m_pVectObjekte;
		bool                                 m_bLoeschend;
	};
#ifdef OKLABI_KERN
	enum FremdobjektModus { foModeRead, foModeText, foModeSearch, foModeUnknown };
#endif
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFFremdobjekt
