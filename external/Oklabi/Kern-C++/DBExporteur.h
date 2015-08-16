/*****************************************************************************
* $Id: DBExporteur.h 2011-08-12 15:00:00 vogelsang $
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
* 
****************************************************************************/
#ifndef DEFDBExporteur
#define DEFDBExporteur

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "AnyType.h"
#include "Datenbestand.h"

namespace Oklabi
{
class OKLABI_API DBExporteur : public OklabiObjekt
{
	friend class Datenbestand;
	friend class Fachobjekt;
public:
	static DBExporteur*       Erzeuge(Datenbestand*, bool ks = true);
	Text                      GibKlassenname() const;

	class OKLABI_API ExportEnumerator : public Enumerator
	{
		friend class DBExporteur;
	public:
		Text                      GibKlassenname() const;
		template<class T> T       GibObjekt();
		void                      Weiter();
		bool                      IstBeendet() const;
		void                      ZumAnfang();
	protected:
		bool                      KannVernichten() const;
		eEnumeratorTyp            GibEnumeratorTyp() const;
	private:
		ExportEnumerator();
		~ExportEnumerator();
		ObjektartListType                   m_listOA;
		ObjektartListType::iterator*        m_pOAiter;
		Datenbestand::FachobjektEnumerator* m_pFOiter;
		Datenbestand*                       m_pBestand;
		bool                                m_bStart;
	};
	Enumerator* GibEnumerator(ObjektartListType* = 0);

private:
	DBExporteur();
	~DBExporteur();
	bool                      KannVernichten() const;

	Datenbestand*             m_pBestand;
	bool                      m_bNoKeyTable;
};

// Spezialisierungen
template<> OKLABI_API Fachobjekt* DBExporteur::ExportEnumerator::GibObjekt<Fachobjekt*>();
template<> OKLABI_API const Fachobjekt* DBExporteur::ExportEnumerator::GibObjekt<const Fachobjekt*>();

}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFDBExporteur
