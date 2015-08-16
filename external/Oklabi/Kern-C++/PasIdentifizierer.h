/*****************************************************************************
* $Id: PasIdentifizierer.h 2014-05-09 15:00:00 vogelsang $
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
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-05-05 Steuerung Meldungsausgabe
* 2014-05-09 Iteration über Datenbestand beschleunigen
* 
****************************************************************************/
#ifndef DEFPasIdentifizierer
#define DEFPasIdentifizierer

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <set>
#include <string>
#ifndef LITTLEENDIAN
#define LITTLEENDIAN 0x0001
#endif

#include "OklabiKern.h"
#include "Identifizierer.h"

namespace Oklabi
{
#if !defined(WIN64) && !defined(LINUX64) && !defined(CYGWIN64)
#ifndef OKLABI_PAS_ACTIVE
#define OKLABI_PAS_ACTIVE
#define OKLABI_PAS_DEBUG
#endif
#else
#ifdef OKLABI_PAS_ACTIVE
#undef OKLABI_PAS_ACTIVE
#endif
#ifdef OKLABI_PAS_DEBUG
#undef OKLABI_PAS_DEBUG
#endif
#endif

#ifdef OKLABI_PAS_ACTIVE
extern "C" {
	void ReUseExit(void* ptr);
	void LogExit(char*);
	void PasCleanup(void*);
}
#endif

	// Aufpassen: Unterschiede zwischen little endian und big endian
	typedef struct PasId : public OklabiRoot
	{
#if (LITTLEENDIAN==0x001)
		unsigned long  m_nRef;
		unsigned short m_sOffset;
		unsigned char  m_cNummer;
		unsigned char  m_cStatus;
#else
		unsigned char  m_cStatus;
		unsigned char  m_cNummer;
		unsigned short m_sOffset;
		unsigned long  m_nRef;
#endif
	} PasIdType;

	typedef union
	{
		UINT64         m_Identity;
		PasIdType      m_PasId;
	} IdentityType;

	typedef struct PasEntry : public OklabiRoot
	{
		IdentityType   m_Id;
		union
		{
			Fachobjekt*    m_pObjekt;
			unsigned long  m_nRef;
		}             m_Ref;
	} PasEntryType;

	class Fachobjekt;
	class WertType;
	class OKLABI_API PasIdentifizierer : public Identifizierer
	{
		friend class Umgebung;
		friend class Datenbestand;
		friend class Fachobjekt;
		friend class AnyType;
		friend class SchemaGeo;
		friend class XMLAdapter;
		friend class XMLAusgabeKonverter;
		friend class CTEAusgabeKonverter;
#if defined(OKLABI_MEMOPT_2)
		friend class OklabiObjekt;
		friend class ObjektVertreter;
#endif
#ifdef OKLABI_PAS_ACTIVE
		friend void ReUseExit(void*);
		friend void LogExit(char*);
		friend void PasCleanup(void*);
#endif
	public:
		operator Fachobjekt*() const;
		Fachobjekt* operator->() const;
		bool operator==(Fachobjekt*) const;
		void Halte(bool) const;
		bool operator==(const PasIdentifizierer&) const;
		inline bool operator!=(const PasIdentifizierer& p) const { return !this->operator==(p); };
		bool operator<(const PasIdentifizierer&) const;
		PasIdentifizierer();
		~PasIdentifizierer();
		PasIdentifizierer(const PasIdentifizierer&);
		PasIdentifizierer(const Fachobjekt*);
		PasIdentifizierer& operator=(const PasIdentifizierer&);
		PasIdentifizierer& operator=(const Fachobjekt*);
	private:
		PasIdentifizierer(UINT64);
#ifdef OKLABI_PAS_ACTIVE
		Fachobjekt* Referenziere(Fachobjekt* = NULL, bool = true) const;
		void Dereferenziere() const;
		void Entferne(const Fachobjekt* = NULL, bool = true) const;
		bool IstLoeschend() const;
		bool SetzeLoeschend(bool) const;
		Fachobjekt* Lade(UINT64) const;
		PasEntryType* GibSeite() const;
		void InitialisiereSeite(PasEntryType*) const;
		static void Entlade(void*);
		UINT64 Entlade(Fachobjekt*, unsigned short, PasEntryType*);
		void SchreibeWert(Fachobjekt*, WertType*, FILE*);
		void LiesWerte(Fachobjekt*, size_t, FILE*) const;
		template<class T> void Schreibe(const T&, size_t, FILE*);
		template<class T> size_t Lies(size_t, FILE*, T&) const;
		void LazyInit(size_t, int);
		static void Cleanup();
		static void GibStatistik(double&, unsigned int&);
#ifdef OKLABI_PAS_DEBUG
		enum PasState { fFore, fBack, fLock, fMake, fKill, fMiss };
		static PasState Protokolliere(PasState, const void*);
		static PasState GibStatus(const void*);
		typedef std::map<const void*, PasState> StateMapType;
		static StateMapType  m_mapState;
#endif
		static unsigned long m_nHead;
		static unsigned long m_nFree;
		typedef std::set<unsigned long> PageSetType;
		static PageSetType   m_setPage;
		static FILE*         m_pFileOut;
		static FILE*         m_pFileIn;
		static std::string   m_strFileName;
		static std::string   GibDateiname();
#endif
		mutable IdentityType m_uIdentity;
		static bool m_bActive;
	};
#define BitsPerByte 8
#ifdef OKLABI_PAS_ACTIVE
#define PASOBJECTID(x) (((UINT64)((x).m_uIdentity.m_PasId.m_nRef)) << BitsPerByte*sizeof(unsigned short) | ((UINT64)(x).m_uIdentity.m_PasId.m_sOffset))
#else
#define PASOBJECTID(x) ((x).m_uIdentity.m_Identity)
#endif
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFPasIdentifizierer
