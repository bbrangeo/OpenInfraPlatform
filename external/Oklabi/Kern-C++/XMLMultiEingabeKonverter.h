/*****************************************************************************
* $Id: XMLMultiEingabeKonverter.h 2014-03-27 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog f�r das Stra�en- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2014-2014, Bundesanstalt f�r Stra�enwesen
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
* 2014-03-27 XMLMultiEingabeKonverter eingef�hrt 
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
