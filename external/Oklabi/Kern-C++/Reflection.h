/*****************************************************************************
* $Id: Reflection.h 2014-01-17 15:00:00 vogelsang $
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
* 2010-07-20 Vorbereitungen für Nutzung der Schema-Datenbank
* 2010-10-25 Version Schema-Datenbank eingeführt
* 2010-11-10 Kompakte Speicherung von Geometrie
* 2011-03-18 Schlüsseltabellen sind GML-Feature ab Version 1.015
* 2011-10-17 Erweitertes Format Schemadatenbank
* 2012-09-27 Automatisches Verschmelzen von symbolischen Objekten
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2013-06-06 Namenskollision bei impliziten Eigenschaften
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#ifndef DEFOklabiReflection
#define DEFOklabiReflection

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <map>
#include <list>
#include <string>

#include "OklabiPackaging.h"
#include "OklabiKern.h"
#include "Version.h"
#include "SyncClasses.h"

namespace Oklabi
{
	struct KeyValueType
	{
		const char* m_pKey;
		const char* m_pValue;
		const char* m_pValue2;
		const char* m_pValue3;
		KeyValueType(const char* pK, const char* pV, const char* pV2 = 0, const char* pV3 = 0)
			: m_pKey(pK), m_pValue(pV), m_pValue2(pV2), m_pValue3(pV3) {};
	};
//	typedef std::map< const char*, KeyValueType, ccmp > KeyValueMapType;
	typedef std::list< KeyValueType > KeyValueMapType;
	typedef void (*KeyValueIniPtr)( Sync::CriticalRegion&,KeyValueMapType*& );

#ifdef LINUX
	class Eigenschaft;
	class Objektart;
#endif
	typedef void (*GetPropNamesPtr)( TextListe* sl, const Version& version, bool bClear );
	typedef void (*GetVirtNamesPtr)( TextListe* sl, const Version& version, bool bClear );
	typedef void (*GetFriendNamPtr)( TextListe* sl, const Version& version, bool bClear );
	typedef void (*GetPseudoPtr)( TextListe* sl, const Version& version, bool bClear );
	typedef bool (*GetPropInfoPtr)( const Text& strNam, Eigenschaft& pInfo, const Version& version );
	typedef void (*GetClassInfoPtr)( const Objektart& pInfo, const Version& version );
	typedef bool (*CheckClassPtr)( const Objektart& pInfo, const Version& version );
	typedef const Objektart*(*GetXMLReference)( const Version& vsn );

	struct InitFunctionType
	{
		GetPropNamesPtr m_pPropNames;
		GetVirtNamesPtr m_pVirtNames;
		GetFriendNamPtr m_pFriendNames;
		GetPseudoPtr    m_pPseudo;
		GetPropInfoPtr  m_pPropInfo;
		GetClassInfoPtr m_pClassInfo;
		CheckClassPtr   m_pCheckClass;
		GetXMLReference m_pXMLRef;
		const char*		m_pNameSchema;
		bool			m_bNameOwned;
		InitFunctionType(GetPropNamesPtr pPN, GetVirtNamesPtr pVN, GetFriendNamPtr pFN, GetPropInfoPtr pPI, GetClassInfoPtr pCI, CheckClassPtr pCK, GetPseudoPtr pPS, GetXMLReference pXR, bool owned, const char* pName)
			: m_pPropNames(pPN), m_pVirtNames(pVN), m_pFriendNames(pFN), m_pPropInfo(pPI), m_pClassInfo(pCI), m_pCheckClass(pCK), m_pPseudo(pPS), m_pXMLRef(pXR), m_bNameOwned(owned), m_pNameSchema(pName) {};
	};

	typedef void (*GetIntKeyListPtr)(const Version& vsn, IntListe* keyList);
	typedef void (*GetStrKeyListPtr)(const Version& vsn, TextListe* keyList);
	typedef void (*GetValueListPtr)(const Version& vsn, TextListe* valList, const int& nVal);
	typedef bool (*GetValuePtr)(const Version& vsn, const Text& key, Text& value, const int& nVal);
	typedef bool (*HasIntegerKeyPtr)(const Version& vsn);

	struct KeyValueFunctionType
	{
		GetIntKeyListPtr m_pIntKeyList;
		GetStrKeyListPtr m_pStrKeyList;
		GetValueListPtr  m_pValueList;
		GetValuePtr      m_pValue;
		HasIntegerKeyPtr m_pHasIntKey;
		KeyValueFunctionType(GetIntKeyListPtr pIK, GetStrKeyListPtr pSK, GetValueListPtr pVL, GetValuePtr pV, HasIntegerKeyPtr pHIK)
			: m_pIntKeyList(pIK), m_pStrKeyList(pSK), m_pValueList(pVL), m_pValue(pV), m_pHasIntKey(pHIK) {};
	};

	typedef void (*GetBoundingBoxPtr)(Fachobjekt*, BoundingBox&, const Datum&, FachobjektMengeImpl*);
	typedef const Geometrie* (*GetGeometryPtr)(Fachobjekt*, const Datum&);
	typedef Text (*GetSignaturePtr)(Fachobjekt*, const Datum&);
	typedef Text (*GetInternalIdPtr)(Fachobjekt*);
	typedef Text (*GetObjectNrPtr)(Fachobjekt*);
	typedef Text (*GetIdentifierPtr)(Fachobjekt*, const Datum&, unsigned);

	struct DerivedFunctionType
	{
		GetBoundingBoxPtr m_pBBOX;
		GetGeometryPtr    m_pGeometryPoint;
		GetGeometryPtr    m_pGeometryLine;
		GetGeometryPtr    m_pGeometryRegion;
		GetGeometryPtr    m_pGeometryVolume;
		GetSignaturePtr   m_pSignature;
		GetInternalIdPtr  m_pInternalId;
		GetObjectNrPtr    m_pObjectNr;
		GetIdentifierPtr  m_pIdentifier;
		DerivedFunctionType(GetBoundingBoxPtr pBB, GetGeometryPtr pGP, GetGeometryPtr pGL, GetGeometryPtr pGR, GetGeometryPtr pGV, GetSignaturePtr pS, GetInternalIdPtr pI, GetObjectNrPtr pO, GetIdentifierPtr pId)
			: m_pBBOX(pBB), m_pGeometryPoint(pGP), m_pGeometryLine(pGL), m_pGeometryRegion(pGR), m_pGeometryVolume(pGV), m_pSignature(pS), m_pInternalId(pI), m_pObjectNr(pO), m_pIdentifier(pId) {};
	};

	class Reflection : public OklabiRoot
	{
		friend class Objektart;
		friend class Objektartfilter;
		friend class ObjektartEnumerator;
		friend class Eigenschaft;
		friend class Fachobjekt;
		friend class Version;
		friend class XMLAdapter;
		friend class Umgebung;
		friend class CTEEingabeKonverter;
		friend class XMLEingabeKonverter;
		friend class XMLAusgabeKonverter;
		friend class Datenbestand;
#ifdef OKLABI_SCHEMADB
		friend class SchemaDBAdapter;
#endif

	protected:
		static void Registriere(const char*, GetPropNamesPtr, GetVirtNamesPtr, GetFriendNamPtr, GetPropInfoPtr, GetClassInfoPtr, CheckClassPtr, GetPseudoPtr, GetXMLReference);
		static void Registriere(const char*, GetIntKeyListPtr, GetStrKeyListPtr, GetValueListPtr, GetValuePtr, HasIntegerKeyPtr);
		static void Registriere(const char*, GetBoundingBoxPtr, GetGeometryPtr, GetGeometryPtr, GetGeometryPtr, GetGeometryPtr, GetSignaturePtr, GetInternalIdPtr, GetObjectNrPtr, GetIdentifierPtr = 0);
		static void Registriere(const char*, GetBoundingBoxPtr);
		static void Registriere(const char*, GetIdentifierPtr);
		static void Registriere(const char*, GetGeometryPtr, GetGeometryPtr, GetGeometryPtr, GetGeometryPtr);
		static bool PruefeName(const Text&, const Version&, Text&);
		static bool Initialisiere(const Objektart*);
		static bool HatTyp(const Objektart&, const Objektart&, const Version&);
		static void Gib_Schluesselwerte_Tab(KeyValueIniPtr, KeyValueMapType*&, IntListe*);
		static void Gib_Schluesselwerte_Tab(KeyValueIniPtr, KeyValueMapType*&, TextListe*);
		static void Gib_Langtexte_Tab(KeyValueIniPtr, KeyValueMapType*&, TextListe*, const int&);
		static bool Gib_Langtext_Tab(KeyValueIniPtr, KeyValueMapType*&, const Text&, Text&, const int&);
		static void Setze_Langtext_Tab(KeyValueMapType*&, const char*, const char*, const char*, const char*);

		static void E_Eigenschaftsnamen( const char* klasse, TextListe* sl, const Version& version, bool bClear, int = 0 );
		static void E_VirtuelleRelationen( const char* klasse, TextListe* sl, const Version& version, bool bClear, int = 0 );
		static void E_Freunde( const char* klasse, TextListe* sl, const Version& version, bool bClear, int = 0 );
		static void E_Pseudoinverse( const char* klasse, TextListe* sl, const Version& version, bool bClear, int = 0 );
		static bool E_Eigenschaftsinfo( const char* klasse, const Text& strNam, Eigenschaft& pInfo, const Version& version, int = 0, bool = false );
		static void E_Klasseninfo( const char* klasse, const Objektart& pInfo, const Version& version, int = 0 );
		static bool KlassePruefen( const char* klasse, const Objektart& oa, const Version& version );
		static Text FiltereLangtextname( const char* name, const Version& version );
		static Text GibKonkretenObjektartnamen( const Text& name, const Version& version );
#ifdef OKLABI_SCHEMADB
		static const Eigenschaft* SucheEigenschaft( const Text& propName, const Objektart* pOA );
		static void Sonderfall(const Text& name, const Objektart& oa, const Version& von, const Version& bis, const Text& namPart, const Text& namInv);
#endif
		static bool GibSubklassen( const char* klasse, const Version&, ObjektartListType& );
		static bool SucheKlasseInFachschema( const Version&, const char*, const char* );
#ifdef CYGWIN
        public:
#endif
		static const Objektart* GibNaechsteObjektart(const Text&, const Version&);
#ifdef CYGWIN
        protected:
#endif
//		static size_t GibAnzahl();
		static void BereinigeIntListe(IntListe*);
		static void BereinigeTextListe(TextListe*);
		static void S_TextInListe(TextListe*, const char*);

		static Text GibSignatur(Fachobjekt* pFO, const Datum& datum);
		static Text GibInternId(Fachobjekt* pFO);
		static Text GibObjektnummer(Fachobjekt* pFO);
		static GetBoundingBoxPtr GibBoundingBoxPtr(const Objektart& oa);
		static bool GibFunctionPtr(const Objektart& oa, DerivedFunctionType* pDerivFct);
		static bool GibNetzbezug(const Objektart& oa);
		static bool GibSchluesselfunktionen(const Objektart& oa);

		static Text GibExpressVersion();
		static bool LiesSchemaDBVersion(int&, int&, int&, Text&, Text&, Text&, Text&, Text&);
		static Text GibSchemaDBVersion();
		static Text GibModell();
		static Text GibXmlNs();
		static Text GibXmlUri();
		static Text GibMetadaten();

		static Text XMLInput_gDay( const char*, bool& );
		static Text XMLOutput_gDay( void*, const char*, bool& );
		static Text XMLInput_gMonth( const char*, bool& );
		static Text XMLOutput_gMonth( void*, const char*, bool& );
		static Text XMLInput_gYear( const char*, bool& );
		static Text XMLOutput_gYear( void*, const char*, bool& );
		static Text XMLInput_date( const char*, bool& );
		static Text XMLOutput_date( void*, const char*, bool& );
		static Text XMLInput_time( const char*, bool& );
		static Text XMLOutput_time( void*, const char*, bool& );

		static bool Validierung_Tag( void*, Objektart* );
		static bool Validierung_Monat( void*, Objektart* );
		static bool Validierung_Jahr( void*, Objektart* );
		static bool Validierung_Datum( void*, Objektart* );
		static bool Validierung_Uhrzeit( void*, Objektart* );
	private:
		static void LazyInit();
		static bool Initialisiere(const Objektart&, const Version& vsn);
		static bool Finalisiere();
		static bool TesteKompakteGeometrie(bool, const Text&);
	};
}// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFOklabiReflection
