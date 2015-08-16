/*****************************************************************************
* $Id: Transaktion.h 2010-04-30 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010, Bundesanstalt für Straßenwesen
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
* 
****************************************************************************/
#ifndef DEFTransaktion
#define DEFTransaktion

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "AnyType.h"

namespace Oklabi
{
	class Datenbestand;
	class Fachobjekt;
#if defined(LINUX) || defined(CYGWIN)
	class XMLAdapter;
#endif
struct Operation
{
	Fachobjekt*     m_pxoObj;
	eAktion         m_eAktion;
	Text            m_strEig;
	AnyType         m_aVal;
	XMLAdapter*     m_pXmlAdapter;

	Operation( FachobjektPtr pxoObj, eAktion aktion, const Text& strEig, const AnyType& aVal, XMLAdapter* pXmlAdapter );
};

class OKLABI_API Transaktion : public OklabiObjekt
{
	friend class Datenbestand;
	friend class Fachobjekt;
public:
	static Transaktion*       Beginne(Datenbestand*);
	static void               Aktiviere();
	static void               Deaktiviere();
	static bool               IstAktiv();
	Text                      GibKlassenname() const;
	void                      Uebernimm(bool = true);
	void                      Verwirf(bool = true);

private:
	Transaktion();
	~Transaktion();
	bool                      KannVernichten() const;

	typedef std::vector<Operation>              OperationVectorType;
	typedef std::vector<Operation>::size_type   markType;

	Datenbestand*             m_pBestand;
	bool                      m_bUebernehmend;
	static bool               m_bAktiv;
	OperationVectorType       m_vectorOp;

	void                      OperationAnfuegen( FachobjektPtr pxoObj, eAktion aktion, const Text& strNam, const AnyType& aVal, XMLAdapter* pXmlAdapter = 0 );
	void                      OperationAnfuegenS( FachobjektPtr pxoObj, const Text& strNam, XMLAdapter* pXmlAdapter = 0 );
	void                      OperationAnfuegenH( FachobjektPtr pxoObj, const Text& strNam, const AnyType& aVal, XMLAdapter* pXmlAdapter = 0 );
	void                      OperationAnfuegenL( FachobjektPtr pxoObj, const Text& strNam, const AnyType& aVal, XMLAdapter* pXmlAdapter = 0 );
	bool                      CheckVernichten( FachobjektPtr pxoObj );
	markType                  Mark() const;
	void                      Rollback( markType nPos = 0 );
};
}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFTransaktion
