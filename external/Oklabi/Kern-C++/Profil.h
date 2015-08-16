/*****************************************************************************
* $Id: Profil.h 2013-12-05 15:00:00 vogelsang $
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
* 2013-02-04 Profile
* 2013-05-17 Löschung verhindern wenn Profil benutzt wird
* 2013-12-05 Standardprofil braucht Version
* 
****************************************************************************/
#ifndef DEFProfil
#define DEFProfil

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <list>
#include <map>
#include <set>

#include "OklabiKern.h"
#include "OklabiObjekt.h"
#include "Datenbestand.h"
#include "Objektart.h"
#include "Enumerator.h"
#include "AnyType.h"
#include "Fachobjekt.h"

#ifdef OKLABI_KERN
#include "XercesXML.h"
#endif

namespace Oklabi
{
	class ProfileFileType : public OklabiRoot
	{
		friend class Profil;
	private:
		Text                  m_strFilename;
		TextListe             m_listProfile;
		bool                  m_bValid;
	public:
		ProfileFileType();
		ProfileFileType(const ProfileFileType&);
		ProfileFileType& operator=(const ProfileFileType&);
		~ProfileFileType();
	};
	typedef std::map< const Text, Fachobjekt* > KeyMapType;
	typedef std::map< const Objektart*, std::pair< bool, KeyMapType > > KeytableMapType;
	class PackageType : public OklabiRoot
	{
		friend class Profil;
	private:
		Objektartfilter*      m_filtPositive;
		Objektartfilter*      m_filtNegative;
		KeytableMapType       m_mapKeytPositive;
		KeytableMapType       m_mapKeytNegative;
		bool                  m_bOaSelector;
	public:
		PackageType(bool);
		PackageType(const PackageType&);
		PackageType& operator=(const PackageType&);
		~PackageType();
	};
	enum ProfilFachid { fIdOnly, fObjectOnly, fBoth };
	class PropertyType : public OklabiRoot
	{
		friend class Profil;
	private:
		int                   m_nMin;
		int                   m_nMax;
		ProfilFachid          m_eFachid;
		ObjektartListType     m_listOaPositive;
		ObjektartListType     m_listOaNegative;
		KeytableMapType       m_mapKeytPositive;
		KeytableMapType       m_mapKeytNegative;
		bool                  m_bOaSelector;
	public:
		PropertyType(int, int, ProfilFachid, bool);
		PropertyType(const PropertyType&);
		PropertyType& operator=(const PropertyType&);
		~PropertyType();
	};

	enum ProfilModus { profileModeRead, profileModeText, profileModeSearch, profileModeUnknown };
	typedef std::map< Text, ProfileFileType >            ProfilMapType;
	typedef std::map< Text, PackageType >                PackageMapType;
	typedef std::map< const Eigenschaft*, PropertyType > PropertyMapType;
	typedef std::map< const Eigenschaft*, size_t >       AnzahlMapType;
	typedef std::set< Datenbestand* >                    DomainSetType;
	class Profil : public OklabiObjekt
	{
		friend class AnyType;
		friend class Datenbestand;
		friend class Eigenschaft;
		friend class Enumerator;
		friend class Fachobjekt;
		friend class Fachbedeutungsliste;
		friend class Geometrie;
		friend class Koordinate;
		friend class Objektart;
		friend class Objektart::ObjektartEnumerator;
		friend class Umgebung;
		friend class Version;
		friend class ObjektartEnumerator;
		friend class ProfilEnumerator;
	public:
		static OKLABI_API Profil*                Erzeuge(const Text&, const Version*);
		static OKLABI_API Enumerator*            GibProfile();
		static OKLABI_API Profil*                GibStandardprofil();
		static OKLABI_API AnyType*               GibProfilpfad();
		void                                     Vernichte() const;
		OKLABI_API Text                          GibName() const;
		OKLABI_API Text                          GibDateiname() const;
		OKLABI_API const Version*                GibVersion() const;
		OKLABI_API Enumerator*                   GibObjektarten(const Eigenschaft* = NULL) const;
		OKLABI_API size_t                        GibAnzahlObjektarten(const Eigenschaft* = NULL) const;
		OKLABI_API FblVersionListe               GibFblVersionen() const;
		OKLABI_API KoordRefSysListe              GibKoordRefSys() const;
		template<class T> OKLABI_API Fachobjekt* GibEintrag(const Objektart*, const T&) const;
		OKLABI_API AnyType*                      GibEintraege(const Objektart*, const Eigenschaft* = NULL) const;
		OKLABI_API size_t                        GibAnzahlEintraege(const Objektart*, const Eigenschaft* = NULL) const;
		OKLABI_API AnyType*                      GibKennungen(const Objektart*, const Eigenschaft* = NULL) const;
		OKLABI_API KardinalitaetType             GibKardinalitaet(const Eigenschaft*) const;
		template <class T> OKLABI_API bool       IstZugelassen(T) const;
		OKLABI_API bool                          IstZugelassen(const Fachobjekt*, const Eigenschaft*) const;
		OKLABI_API bool                          IstZugelassen(const Objektart*, const Eigenschaft*) const;
		OKLABI_API bool                          IstStandardprofil() const;
		OKLABI_API bool                          IstGueltig() const;
		OKLABI_API void                          SetzeVersion(const Version*);

	protected:
		OKLABI_API Profil();
		OKLABI_API ~Profil();
		OKLABI_API bool                          KannVernichten() const;
		OKLABI_API void                          Beschreibe(TextListe&) const;
		OKLABI_API Text                          GibKlassenname() const;
		void OKLABI_API                          Austragen(OklabiObjekt*);

	private:
#ifdef OKLABI_KERN
		static void                        ProfilpfadGeaendert();
		static TextListe                   LiesProfilpfad();
		static Profil*                     Traversiere(const Text&, const Version*);
		bool                               Initialisiere(const Text&, const Text&, const Version*) const;
		bool                               LazyInit() const;
		bool                               PruefeKennung(const Objektart*, const Text&, const KeytableMapType*, const KeytableMapType*) const;
		bool                               LiesProfil(ProfilModus, const Text&, Eingabe*, const Version*) const;
		bool                               LiesElementText(ProfilModus, const XercesXML::DOMNode&, const Text&, const Text&, const Objektart*, int, const Eigenschaft*&, AnyType&) const;
		bool                               LiesElementWert(ProfilModus, const XercesXML::DOMNode&, const Text&, const Text&, const Objektart*, const Eigenschaft*, bool, int) const;
		bool                               LiesElementWerte(ProfilModus, const XercesXML::DOMNode&, const Text&, const Text&, const Objektart*, const Eigenschaft*, int) const;
		bool                               LiesElementTabelle(ProfilModus, const XercesXML::DOMNode&, const Text&) const;
		bool                               LiesElementEigenschaft(ProfilModus, const XercesXML::DOMNode&, const Text&, const Text&, const Objektart*, int) const;
		bool                               LiesElementObjektart(ProfilModus, const XercesXML::DOMNode&, const Text&, const Text&, const Eigenschaft*, bool, int) const;
		bool                               LiesElementObjektarten(ProfilModus, const XercesXML::DOMNode&, const Text&, const Text&, const Eigenschaft*, int) const;
		bool                               LiesElementPaket(ProfilModus, const XercesXML::DOMNode&, const Text&) const;
		bool                               LiesElementFbliste(ProfilModus, const XercesXML::DOMNode&, const Text&) const;
		bool                               LiesElementKoordrefsys(ProfilModus, const XercesXML::DOMNode&, const Text&) const;
		bool                               LiesElementProfil(ProfilModus, const XercesXML::DOMNode&, const Text&) const;
#endif
		bool                               LiesProfile(ProfilModus, const Text&, Eingabe*, const Version*) const;
		mutable OklabiObjekt*              m_pUsedBy;
		mutable XMLEingabeKonverter*       m_pXMLInputCv;
		mutable bool                       m_bValidate;
		mutable bool                       m_bValidateSuccess;
		mutable bool                       m_bFound;
		mutable bool                       m_bInit;
		mutable bool                       m_bError;
		mutable bool                       m_bStdProfile;
		mutable int                        m_nGeneration;
		mutable Text                       m_strSource;
		mutable Text                       m_strName;
		mutable Version                    m_Version;
		mutable Datenbestand*              m_pDomain;
		mutable FblVersionListe            m_listFblVersion;
		mutable KoordRefSysListe           m_listKoordRefSys;
		mutable PackageMapType             m_mapPackage;
		mutable PropertyMapType            m_mapProperty;
		mutable AnzahlMapType              m_mapAnzahlOa;
		mutable DomainSetType              m_setDomain;
		static ProfilMapType               m_mapProfile;
		static int                         m_nGenerationCount;
		static std::string
			m_stl_profile, m_stl_profil, m_stl_koordrefsys, m_stl_fbliste,
			m_stl_paket, m_stl_objektarten, m_stl_objektart, m_stl_eigenschaft,
			m_stl_wert, m_stl_werte, m_stl_tabelle, m_stl_name, n_stl_text,
			m_stl_kennung, m_stl_modellversion, m_stl_modell, m_stl_alle, m_stl_einige,
			m_stl_weg, m_stl_auswahl, m_stl_min, m_stl_max, m_stl_fachid, m_stl_beides,
			m_stl_nur_Fachkennungen, m_stl_nur_Objektinstanzen;

	class OKLABI_API ObjektartEnumerator : public Enumerator
	{
		friend class Profil;
	private:
		ObjektartEnumerator(const Profil*, const Eigenschaft* = NULL);
		~ObjektartEnumerator();
	public:
		ObjektartEnumerator(const ObjektartEnumerator& iter);
		ObjektartEnumerator& operator=(const ObjektartEnumerator& iter);
		Text                               GibKlassenname() const;
		template<class T> T                GibObjekt();
		void                               Weiter();
		bool                               IstBeendet() const;
		void                               ZumAnfang();
	protected:
		bool                               KannVernichten() const;
		eEnumeratorTyp                     GibEnumeratorTyp() const;
	private:
		void                               Initialisiere();
		const Profil*                      m_pProfil;
		Objektart::ObjektartEnumerator     m_EnumerOa;
		const Eigenschaft*                 m_pProp;
		ObjektartListType                  m_listOa;
		ObjektartListType::const_iterator  m_listIter;
	};

	class OKLABI_API ProfilEnumerator : public Enumerator
	{
		friend class Profil;
	private:
		ProfilEnumerator();
		~ProfilEnumerator();
	public:
		ProfilEnumerator(const ProfilEnumerator& iter);
		ProfilEnumerator& operator=(const ProfilEnumerator& iter);
		Text                               GibKlassenname() const;
		template<class T> T                GibObjekt();
		void                               Weiter();
		bool                               IstBeendet() const;
		void                               ZumAnfang();
	protected:
		bool                               KannVernichten() const;
		eEnumeratorTyp                     GibEnumeratorTyp() const;
	private:
		mutable ProfilMapType::iterator    m_mapIter;
		mutable TextListe::iterator        m_listIter;
		int                                m_nGeneration;
	};
};

// Spezialisierungen
template<> OKLABI_API const Objektart* Profil::ObjektartEnumerator::GibObjekt<const Objektart*>();
template<> OKLABI_API Profil* Profil::ProfilEnumerator::GibObjekt<Profil*>();

template<> OKLABI_API Fachobjekt* Profil::GibEintrag<int>(const Objektart*, const int&) const;
template<> OKLABI_API Fachobjekt* Profil::GibEintrag<Text>(const Objektart*, const Text&) const;

template<> OKLABI_API bool Profil::IstZugelassen<Datenbestand*>(Datenbestand*) const;
template<> OKLABI_API bool Profil::IstZugelassen<Fachobjekt*>(Fachobjekt*) const;
template<> OKLABI_API bool Profil::IstZugelassen<const Fachobjekt*>(const Fachobjekt*) const;
template<> OKLABI_API bool Profil::IstZugelassen<const Objektart*>(const Objektart*) const;
template<> OKLABI_API bool Profil::IstZugelassen<const Eigenschaft*>(const Eigenschaft*) const;
template<> OKLABI_API bool Profil::IstZugelassen<Geometrie*>(Geometrie*) const;
template<> OKLABI_API bool Profil::IstZugelassen<Koordinate*>(Koordinate*) const;
template<> OKLABI_API bool Profil::IstZugelassen<eKoordRefSys>(eKoordRefSys) const;
template<> OKLABI_API bool Profil::IstZugelassen<FblVersion*>(FblVersion*) const;
template<> OKLABI_API bool Profil::IstZugelassen<AnyType*>(AnyType*) const;

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFProfil
