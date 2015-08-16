/*****************************************************************************
* $Id: Fachmodell.h 2014-04-15 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2014, Bundesanstalt für Straßenwesen
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
* 2013-04-18 Zugriff auf das konzeptionelle Fachdatenmodell
* 2013-06-06 Namenskollision bei impliziten Eigenschaften
* 2014-01-23 Zugriff auf das konzeptionelle Fachdatenmodell(2)
* 2014-04-15 Fachkennung nur im OKSTRA-Datenmodell
* 2014-05-20 Fachbedeutungen nur im OKSTRA-Datenmodell
* 
****************************************************************************/
#ifndef DEFFachmodell
#define DEFFachmodell

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "OklabiObjekt.h"

namespace Oklabi
{
	class Fachmodell : public OklabiObjekt
	{
		friend class Version;
		friend class XMLAusgabeKonverter;
		friend class XMLEingabeKonverter;
		friend class Reflection;
		friend class Fachobjekt;
		friend class Objektart;
		friend class Schema1;
		friend class Schema2;
		friend class Schema3;
		friend class SchemaGeo;
	public:
		static OKLABI_API Fachmodell* Gib(const Text& = "OKSTRA");
		OKLABI_API Text GibKlassenname() const;
		OKLABI_API Text GibName() const;
		OKLABI_API Text GibEigenschaft(eModelleigenschaft, const Version*) const;
		OKLABI_API bool HatFachbedeutung() const;
	protected:
		OKLABI_API Fachmodell();
		OKLABI_API Fachmodell(const Text&);
		OKLABI_API Fachmodell(const Fachmodell&);
		OKLABI_API Fachmodell& operator=(const Fachmodell&);
		OKLABI_API ~Fachmodell();
		OKLABI_API bool operator==(const Fachmodell&) const;
		inline bool operator!=(const Fachmodell& m) const { return !operator==(m); };
		OKLABI_API bool KannVernichten() const;
		OKLABI_API void Beschreibe(TextListe&) const;
		OKLABI_API Text Formatiere(const Version*) const;
		static void     Finalisiere();
	private:
		Text            m_strModell;
		Text            m_strXmlNs;
		Text            m_strXmlUri;
		Text            m_strMetadata;
		typedef std::map< Text, Fachmodell* > mapModelToXmlType;
		static mapModelToXmlType m_mapModelToXml;
	};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFFachmodell
