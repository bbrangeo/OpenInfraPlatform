/*****************************************************************************
* $Id: IsybauObjekt.h 2013-12-12 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2013-2013, Bundesanstalt für Straßenwesen
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
* 2013-12-12 Fremdobjekt für Nachbarstandards eingeführt
* 
****************************************************************************/
#ifndef DEFIsybauObjekt
#define DEFIsybauObjekt

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "Fremdobjekt.h"

#ifdef OKLABI_KERN
#include "SAXReader.h"
#include "XercesXML.h"
#include "XercesXMLErrorHandler.h"
#endif

namespace Oklabi
{
#ifdef OKLABI_KERN
	class IsybauObjekt;
	class XMLEingabeKonverter;
	class IsybauImporteur
	{
		friend class IsybauObjekt;
		friend class Geometrie;
		friend class Umgebung;
		friend class XMLEingabeKonverter;
	private:
		IsybauImporteur();
		~IsybauImporteur();
		bool                                Importiere(FremdobjektModus, Eingabe*, Fremddatenbestand&);
		bool                                LiesObjekte(FremdobjektModus, Eingabe*, Fremddatenbestand&);
		bool                                LiesDatenkollektive(FremdobjektModus, const XercesXML::DOMNode&, Fremddatenbestand&);
		bool                                LiesStammdatenkollektiv(FremdobjektModus, const XercesXML::DOMNode&, Fremddatenbestand&);
		bool                                LiesAbwassertechnischeAnlage(FremdobjektModus, const XercesXML::DOMNode&);
		bool                                LiesGeometrie(FremdobjektModus, const XercesXML::DOMNode&, eGeoTyp);
		bool                                LiesGeometriedaten(FremdobjektModus, const XercesXML::DOMNode&, eGeoTyp);
		bool                                LiesPunkt(FremdobjektModus, const XercesXML::DOMNode&, Koordinate&);
		XMLEingabeKonverter*                m_pXMLInputCv;
		IsybauObjekt*                       m_pKontext;
		TextListe                           m_strTagList;
		Text                                m_strVersion;
		Text                                m_strTag;
		Text                                m_strKollektiv;
		bool                                m_bValidate;
		bool                                m_bValidateSuccess;
		bool                                m_bInit;
		bool                                m_bError;
	};
#endif

	class IsybauObjekt : public Fremdobjekt
	{
		friend class Geometrie;
		friend class Umgebung;
		friend class XMLEingabeKonverter;
#ifdef OKLABI_KERN
		friend class IsybauImporteur;
#endif
	private:
		IsybauObjekt();
		~IsybauObjekt();
		static Fremdobjekt*                  Erzeuge();
		Text                                 m_strID;
		Text                                 m_strObjektartname;
		Text                                 m_strVersion;
		Geometrie*                           m_pGeometrie;

	public:
		OKLABI_API Text                      GibID() const;
		OKLABI_API Text                      GibObjektartname() const;
		OKLABI_API Text                      GibVersion() const;
		OKLABI_API Geometrie*                GibGeometrie() const;
		OKLABI_API static Fremddatenbestand* Importiere(Eingabe*);
		OKLABI_API void                      SetzeKennung(const Text&);
		OKLABI_API void                      SetzeObjektartname(const Text&);
		OKLABI_API void                      SetzeVersion(const Text&);
		OKLABI_API Text						 GibKlassenname() const;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// IsybauObjekt
