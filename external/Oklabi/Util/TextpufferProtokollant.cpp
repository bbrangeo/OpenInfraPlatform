/*****************************************************************************
* $Id: TextpufferProtokollant.cpp 2012-10-01 15:00:00 vogelsang $
* $Paket: Oklabi-Util $
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
* 2012-10-01 Protokollant nutzt Ausgabe
* 
****************************************************************************/
#include "TextpufferProtokollant.h"
#include "Umgebung.h"

#include <sstream>
#include <iomanip>

using namespace Oklabi;
using namespace std;

TextpufferProtokollant::TextpufferProtokollant() : m_pOut(NULL), m_bOpen(false)
{
}

TextpufferProtokollant::~TextpufferProtokollant()
{
	if (m_pOut)
	{
		if (m_bOpen)
			m_pOut->Schliesse();
		m_pOut->Austragen((OklabiObjekt*)this);
		m_pOut = 0;
	}
}

void TextpufferProtokollant::Austragen(OklabiObjekt* pObj)
{
	if (m_pOut == pObj)
		m_pOut = (Ausgabe*)0;
}

Text TextpufferProtokollant::GibKlassenname() const
{
	return "TextpufferProtokollant";
}

Protokollant* TextpufferProtokollant::Erzeuge(Ausgabe* pOut)
{
	TextpufferProtokollant* pPr = new TextpufferProtokollant();
	pPr->m_pOut = pOut;
	if (pOut)
		pOut->m_pUsedBy = pPr;
	return pPr;
}

void TextpufferProtokollant::Melde( int nr, const Text& str, eMeldTyp m )
{
	if (m_pOut)
	{
		if (!m_bOpen)
		{
			m_pOut->Oeffne();
			m_bOpen = true;
		}
		ostringstream ost;
		if (m != info && m != statistik)
			ost << AlsText(m) << ": ";
		if (nr != -1)
			ost << "(" << nr << ") ";
		ost << str;
		std::string aus = (std::string)ost.str();
		const char* pCh = aus.c_str();
		while (pCh && *pCh)
		{
			m_pOut->SchreibeZeichen(*pCh);
			++pCh;
		}
		m_pOut->SchreibeZeichen('\n');
	}
}
