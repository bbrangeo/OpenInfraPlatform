/*****************************************************************************
* $Id: XMLMultiEingabeKonverter.h 2014-03-27 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2014-2014, Bundesanstalt für Straßenwesen
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
* 2014-03-27 XMLMultiEingabeKonverter eingeführt 
* 
****************************************************************************/

#include "OklabiPackaging.h"

#ifndef DEFXMLMultiEingabeKonverter
#define DEFXMLMultiEingabeKonverter

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"
#include "EingabeKonverter.h"
#include "XMLEingabeKonverter.h"
#include "Datenbestand.h"

namespace Oklabi
{
class OKLABI_API XMLMultiEingabeKonverter : public XMLEingabeKonverter
{
	friend class XMLAdapter;
	friend class XMLAusgabeKonverter;
	friend class XMLEingabeKonverter;
public:
	static XMLMultiEingabeKonverter* Erzeuge(Eingabe*);
	Text                             GibKlassenname() const;

	DatenbestandListe                LadeDaten(Objektartfilter* pFilt = 0, Objektartfilter* pSymb = 0);

private:
	XMLMultiEingabeKonverter(XMLAdapter*);
	~XMLMultiEingabeKonverter();
};

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFXMLMultiEingabeKonverter
