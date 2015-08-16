/*****************************************************************************
* $Id: Objektartfilter.h 2012-09-27 15:00:00 vogelsang $
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
* 2011-08-04 Neue Interfaces für Objetartfilter
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 
****************************************************************************/
#ifndef DEFOklabiObjektartfilter
#define DEFOklabiObjektartfilter

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "Objektart.h"

namespace Oklabi
{
	typedef std::map<Text, std::pair<const Objektart*, int> >	ClsConfMapType;
	class OKLABI_API Objektartfilter : public OklabiObjekt
	{
		friend class Datenbestand;
	#define OBJEKTARTLISTE_SIZE 15
	private:
		Objektartfilter();
		~Objektartfilter() /*throw()*/;
		Objektartfilter(const Objektartfilter& oaf);
		Objektartfilter& operator=(const Objektartfilter& oaf);
		bool KannVernichten() const;
		bool operator==(const Objektartfilter&) const;
		bool operator!=(const Objektartfilter& oaf) const;
		bool Check(const Objektart*, const bool& add = true, const bool& typ = false) const;
		void Reset();
	private:
		mutable size_t m_nBelegt;
		mutable size_t m_nSize;
		mutable const Objektart**  m_Status;
		mutable bool m_bInvers;

	public:
		static Objektartfilter* Erzeuge(const ObjektartListType* = NULL);
		Text GibKlassenname() const;
		Objektartfilter* Kopiere();
		void Entferne(const Objektart*);
		void FuegeHinzu(const Objektart*);
		void Setze(const ObjektartListType*);
		void Invertiere(bool);
		bool IstEnthalten(const Objektart*) const;
		bool IstInvertiert() const;
		bool PrueftObjektart(const Objektart*) const;
		bool PrueftTyp(const Objektart*) const;
		size_t GibAnzahl() const;
		bool IstLeer() const;
	};
}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFOklabiObjektartfilter
