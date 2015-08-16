/*****************************************************************************
* $Id: AnyType.h 2014-01-17 15:00:00 vogelsang $
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
* 2011-08-12 template-Defintionen überarbeitet
* 2011-11-14 Private Definitionen verbergen
* 2011-11-14 Erweiterung Geometrie-Schnittstelle
* 2012-02-27 Zugriff auf erstes Datenelement
* 2013-02-04 Profile
* 2013-10-18 Layout Datum optimiert
* 2013-10-21 Speicheroptimierungen bei Koordinaten
* 2013-10-31 Speicheroptimierungen bei Strings und Collections
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFAnyType
#define DEFAnyType

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <string>
#include <set>
#include <list>

#include "Datum.h"
#include "Koordinate.h"
#include "Enumerator.h"
#include "Umgebung.h"
#include "Speicherverbrauch.h"
#include "Geometrie.h"
#ifdef OKLABI_MEMOPT_2
#include "PasIdentifizierer.h"
#endif
#ifdef OKLABI_MEMOPT_1
#include "_XString.h"
#include "_XOSet.h"
#include "_XOList.h"
#endif

namespace Oklabi
{
	class Fachobjekt;
	typedef Fachobjekt*                    FachobjektPtr;
	template<class T> class Liste;
	template<class T> class Menge;
	typedef const Fachobjekt*              FachobjektConstPtr;
	typedef Menge< Fachobjekt* >           FachobjektMenge;
	typedef Liste< Fachobjekt* >           FachobjektListe;
	typedef Liste< FachobjektConstPtr >    FachobjektSetConst;

#ifdef OKLABI_MEMOPT_2
#define FachobjektReferenz   PasIdentifizierer
#define FachobjektListeView  IdentifiziererListe
#define FachobjektMengeView  IdentifiziererMenge
#else
#define FachobjektReferenz   Fachobjekt*
#define FachobjektListeView  FachobjektListe
#define FachobjektMengeView  FachobjektMenge
#endif

#if !defined(OKLABI_MEMOPT_1) && !defined(OKLABI_MEMOPT_2)
	typedef FachobjektMenge                FachobjektMengeImpl;
	typedef FachobjektListe                FachobjektListeImpl;
	typedef Text                           TextImpl;
#endif
#if defined(OKLABI_MEMOPT_2)
	typedef Menge< PasIdentifizierer >     IdentifiziererMenge;
	typedef Liste< PasIdentifizierer >     IdentifiziererListe;
	typedef FachobjektMengeView            FachobjektMengeImpl;
	typedef FachobjektListeView            FachobjektListeImpl;
	typedef Text                           TextImpl;
#endif
#if defined(OKLABI_MEMOPT_1)
#ifdef OKLABI_INTERN
	typedef _XOSet                         FachobjektMengeImpl;
	typedef _XOList                        FachobjektListeImpl;
	typedef _XString                       TextImpl;
#endif
#endif

	template<class T, class U> class IteratorWrapper : public OklabiRoot
	{
	public:
		IteratorWrapper();
		IteratorWrapper(const U&);
		~IteratorWrapper();
		IteratorWrapper(const IteratorWrapper&);
		IteratorWrapper& operator=(const IteratorWrapper&);
		typename U::const_iterator& Iterator();
	private:
		typename U::const_iterator m_Iter;
	};

	class OKLABI_API AnyType : public OklabiObjekt
	{
		friend class Fachobjekt;
		friend class Datenbestand;
		friend class Objektart;
		friend class Eigenschaft;
		friend class WertType;
		friend class EingabeKonverter;
		friend class CTEEingabeKonverter;
		friend class CTEAusgabeKonverter;
		friend class XMLAusgabeKonverter;
		friend class XMLAdapter;
		friend class Umgebung;
		friend class Transaktion;
		friend class DBImporteur;
		friend class Operation;
		friend class Schema;
		friend class SchemaGeo;
		friend class Profil;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif

	private:
		AnyType();
		AnyType(const AnyType& any);
		~AnyType();
		bool KannVernichten() const;
		size_t size() const;
		eAggreg GibAggregation() const;
		void Beschreibe(TextListe&) const;

	public:
		static AnyType* Erzeuge();
		static AnyType* Erzeuge(bool);
		template<class T> static AnyType* Erzeuge(const T&);
		template<class T> static AnyType* Erzeuge(const T&, bool);
		AnyType* Kopiere() const;
		eTyp GibTyp() const;
		Text GibKlassenname() const;
		Enumerator* GibEnumerator() const;
		Text GibText() const;
		size_t GibAnzahl() const;

		// Tests
		bool IstUnbelegt() const;
		bool IstMehrwertig() const;
		bool IstGeordnet() const;
		template<class T> bool IstEnthalten(const T& val) const;
		bool IstGleich(const AnyType*) const;

		// Löschen von Werten
		void Loesche();
		template<class T> void Loesche(const T& val);
		void LoescheBei(size_t);
		
		// Abfragen von Werten
		template<class T> T Gib() const;
		template<class T> T GibBei(size_t) const;
		template<class T> void GibAlle(T []) const;
		template<class T> T GibAnfangswert() const;

		// Setzen von Werten
		template<class T> void Setze(const T& val);
		template<class T> void Setze(const T [], size_t pos);
#if defined(OKLABI_MEMOPT_2) || (defined(OKLABI_MEMOPT_1) && defined(OKLABI_INTERN))
	private:
#if defined(OKLABI_MEMOPT_2)
		void SetzeId(const FachobjektReferenz& val);
#endif
		void Setze(const FachobjektMengeImpl& val);
		void Setze(const FachobjektListeImpl& val);
	public:
#endif
		// Hinzufügen von Werten
		template<class T> void FuegeHinzu(const T& val);
		template<class T> void FuegeHinzuBei(const T& val, size_t pos);

		template<class T> int Vergleiche(const T&, const T&) const;

		template<class T> class AnyEnumerator : public Enumerator
		{
		protected:
			friend class AnyType;
#if defined(OKLABI_MEMOPT_2)
			friend class PasIdentifizierer;
#endif

			size_t	m_nCnt;
			eTyp	m_eType;
			eAggreg	m_eAggreg;
			AnyType	*m_Any;

			union
			{
				bool			b;
				int				i;
				UINT64			l;
				float			f;
				double			d;
#ifdef OKLABI_MEMOPT_2
				unsigned char	pid[sizeof(PasIdentifizierer)];
#else
				void*			p;
#endif
				void*			v;
				unsigned char	ip[sizeof(T)];
				unsigned char   wis[sizeof(IteratorWrapper<int, IntMenge>)];
				unsigned char   wil[sizeof(IteratorWrapper<int, IntListe>)];
				unsigned char   wls[sizeof(IteratorWrapper<UINT64, LongIntMenge>)];
				unsigned char   wll[sizeof(IteratorWrapper<UINT64, LongIntListe>)];
				unsigned char   wfs[sizeof(IteratorWrapper<float, FloatMenge>)];
				unsigned char   wfl[sizeof(IteratorWrapper<float, FloatListe>)];
				unsigned char   wds[sizeof(IteratorWrapper<double, DoubleMenge>)];
				unsigned char   wdl[sizeof(IteratorWrapper<double, DoubleListe>)];
				unsigned char   wbs[sizeof(IteratorWrapper<bool, BoolMenge>)];
				unsigned char   wbl[sizeof(IteratorWrapper<bool, BoolListe>)];
				unsigned char   wss[sizeof(IteratorWrapper<Text, TextMenge>)];
				unsigned char   wsl[sizeof(IteratorWrapper<Text, TextListe>)];
				unsigned char   wts[sizeof(IteratorWrapper<Datum, DatumMenge>)];
				unsigned char   wtl[sizeof(IteratorWrapper<Datum, DatumListe>)];
#ifdef OKLABI_INTERN
				unsigned char   wos[sizeof(IteratorWrapper<FachobjektPtr, FachobjektMengeImpl>)];
				unsigned char   wol[sizeof(IteratorWrapper<FachobjektPtr, FachobjektListeImpl>)];
#endif
				unsigned char   wks[sizeof(IteratorWrapper<Koordinate, KoordinatenMenge>)];
				unsigned char   wkl[sizeof(IteratorWrapper<Koordinate, KoordinatenListe>)];
				unsigned char   wgs[sizeof(IteratorWrapper<GeometriePtr, GeometrieMenge>)];
				unsigned char   wgl[sizeof(IteratorWrapper<GeometriePtr, GeometrieListe>)];
				unsigned char   w1s[sizeof(IteratorWrapper<GeoPunktPtr, GeometrieMenge>)];
				unsigned char   w1l[sizeof(IteratorWrapper<GeoPunktPtr, GeometrieListe>)];
				unsigned char   wxs[sizeof(IteratorWrapper<Binaerdaten, BinaerMenge>)];
				unsigned char   wxl[sizeof(IteratorWrapper<Binaerdaten, BinaerListe>)];
			}	m_uIter;

			AnyEnumerator<T>();
			~AnyEnumerator<T>();
			Text ZustandAlsText() const;
			size_t GibSekundaerSpeicherplatz() const;

		public:
			AnyEnumerator<T>& operator++();
			AnyEnumerator<T>& operator++( int i );

			T operator*() const { return AnyType::Dereferenziere<T>(*this); };
			T operator*() { return AnyType::Dereferenziere<T>(*this); };
			T GibObjekt() const { return AnyType::Dereferenziere<T>(*this); };
			T GibObjekt() { return AnyType::Dereferenziere<T>(*this); };
		};

		template<class T, class U> class AnyIterator : public AnyEnumerator<T>
		{
		public:
			AnyIterator<T, U>();
			~AnyIterator<T, U>();
			AnyIterator<T, U>(const AnyIterator<T, U>& iter);
			AnyIterator<T, U>& operator=(const AnyIterator<T, U>& iter);

			AnyIterator<T, U>& operator++();
			AnyIterator<T, U>& operator++( int i );

			void Weiter();
			bool IstBeendet() const;
			void ZumAnfang();
			Text GibKlassenname() const;
		protected:
			bool KannVernichten() const;
			eEnumeratorTyp GibEnumeratorTyp() const;
		};

		// Enumerator auf den Inhalt, sofern der AnyType welchen enthält.
		template<class T> AnyEnumerator<T>* GibEnumerator() const;

	private:
		struct StatusType
		{
			unsigned char m_eType;
			unsigned char m_eAggreg;
			unsigned char m_eStatus;
			unsigned char m_eReserve;
		};
		union
		{
			StatusType   m_Zustand;
			unsigned int m_nStatus;
		} m_uStatus;

		union
		{
			int		i;
			unsigned char	is[sizeof(IntMenge)];
			unsigned char	il[sizeof(IntListe)];
			UINT64	l;
			unsigned char	ls[sizeof(LongIntMenge)];
			unsigned char	ll[sizeof(LongIntListe)];
			double	d;
			unsigned char	ds[sizeof(DoubleMenge)];
			unsigned char	dl[sizeof(DoubleListe)];
			float	f;
			unsigned char	fs[sizeof(FloatMenge)];
			unsigned char	fl[sizeof(FloatListe)];
			bool	b;
			unsigned char	bs[sizeof(BoolMenge)];
			unsigned char	bl[sizeof(BoolListe)];
#ifdef OKLABI_INTERN
			unsigned char	da[sizeof(Datum::DateVal)];
#endif
			unsigned char	das[sizeof(DatumMenge)];
			unsigned char	dal[sizeof(DatumListe)];
#ifdef OKLABI_INTERN
			Koordinate::KoordType* k;
#endif
			unsigned char	kos[sizeof(KoordinatenMenge)];
			unsigned char	kol[sizeof(KoordinatenListe)];
#ifdef OKLABI_INTERN
			unsigned char	xs[sizeof(TextImpl)];
#endif
			unsigned char	ss[sizeof(TextMenge)];
			unsigned char	sl[sizeof(TextListe)];
#if defined(OKLABI_MEMOPT_2)
			UINT64	pid;
#else
			Fachobjekt*	p;
#endif
#ifdef OKLABI_INTERN
			unsigned char	xps[sizeof(FachobjektMengeImpl)];
			unsigned char	xpl[sizeof(FachobjektListeImpl)];
#endif
			Geometrie*	g;
			unsigned char	gs[sizeof(GeometrieMenge)];
			unsigned char	gl[sizeof(GeometrieListe)];
			Binaerdaten*	bin;
			unsigned char	bis[sizeof(BinaerMenge)];
			unsigned char	bil[sizeof(BinaerListe)];
		}	m_uVal;

	private:
		Text ZustandAlsText() const;
		void SetzeTypUndAggregation(eTyp t, eAggreg a);
		bool BesitztInhalt() const;
		void UebernimmInhalt(bool bPosess);
		bool IstLeer() const;
		void SetzeLeer(bool bEmpty);
		bool IstLoeschend() const;
		void SetzeLoeschend(bool bCleanup);
		template<class T, class U> void InitObjekt(AnyIterator<T, U>&) const;
		template<class T> static T Dereferenziere(const AnyEnumerator<T>&);
		template<class T> bool Pruefe() const;
		template<class T> eTyp WandleTyp() const;
		template<class T> eAggreg WandleAggregation() const;
		template<class T> Text WandleText() const;
		template<class T> void GibAlle(bool, T []) const;
		void FuegeHinzu(const GeometriePtr&, eTyp);

		AnyType& operator=(const AnyType& any);
		bool operator==( const AnyType& val ) const;

		size_t GibSekundaerSpeicherplatz() const;
		void clear(bool = false);
	};

	// Spezialisierungen
#if defined(OKLABI_MEMOPT_1) || defined(OKLABI_MEMOPT_2)
	template<> OKLABI_API AnyType::AnyEnumerator<Fachobjekt*>* AnyType::GibEnumerator<Fachobjekt*>() const;

	template<> OKLABI_API AnyType::AnyEnumerator<Fachobjekt*>& AnyType::AnyEnumerator<Fachobjekt*>::operator++();
#endif
	template<> OKLABI_API AnyType::AnyEnumerator<GeoPunkt*>& AnyType::AnyEnumerator<GeoPunkt*>::operator++();
	template<> OKLABI_API AnyType::AnyEnumerator<GeoPfad*>& AnyType::AnyEnumerator<GeoPfad*>::operator++();
	template<> OKLABI_API AnyType::AnyEnumerator<GeoLinie*>& AnyType::AnyEnumerator<GeoLinie*>::operator++();
	template<> OKLABI_API AnyType::AnyEnumerator<GeoSpline*>& AnyType::AnyEnumerator<GeoSpline*>::operator++();
	template<> OKLABI_API AnyType::AnyEnumerator<GeoKreisbogen*>& AnyType::AnyEnumerator<GeoKreisbogen*>::operator++();
	template<> OKLABI_API AnyType::AnyEnumerator<GeoFlaeche*>& AnyType::AnyEnumerator<GeoFlaeche*>::operator++();
	template<> OKLABI_API AnyType::AnyEnumerator<GeoVolumen*>& AnyType::AnyEnumerator<GeoVolumen*>::operator++();

#if defined(OKLABI_MEMOPT_1) || defined(OKLABI_MEMOPT_2)
	template<> OKLABI_API Fachobjekt* AnyType::Dereferenziere(const Oklabi::AnyType::AnyEnumerator<Fachobjekt*>& iter);
#endif
	template<> OKLABI_API GeoPunkt* AnyType::Dereferenziere(const Oklabi::AnyType::AnyEnumerator<GeoPunkt*>& iter);
	template<> OKLABI_API GeoPfad* AnyType::Dereferenziere(const Oklabi::AnyType::AnyEnumerator<GeoPfad*>& iter);
	template<> OKLABI_API GeoLinie* AnyType::Dereferenziere(const Oklabi::AnyType::AnyEnumerator<GeoLinie*>& iter);
	template<> OKLABI_API GeoSpline* AnyType::Dereferenziere(const Oklabi::AnyType::AnyEnumerator<GeoSpline*>& iter);
	template<> OKLABI_API GeoKreisbogen* AnyType::Dereferenziere(const Oklabi::AnyType::AnyEnumerator<GeoKreisbogen*>& iter);
	template<> OKLABI_API GeoFlaeche* AnyType::Dereferenziere(const Oklabi::AnyType::AnyEnumerator<GeoFlaeche*>& iter);
	template<> OKLABI_API GeoVolumen* AnyType::Dereferenziere(const Oklabi::AnyType::AnyEnumerator<GeoVolumen*>& iter);

	template<> OKLABI_API int AnyType::Vergleiche<float>(const float&, const float&) const;
	template<> OKLABI_API int AnyType::Vergleiche<double>(const double&, const double&) const;

	template<> OKLABI_API void AnyType::Loesche<bool>(const bool&);
	template<> OKLABI_API void AnyType::Loesche<int>(const int&);
	template<> OKLABI_API void AnyType::Loesche<UINT64>(const UINT64&);
	template<> OKLABI_API void AnyType::Loesche<float>(const float&);
	template<> OKLABI_API void AnyType::Loesche<double>(const double&);
	template<> OKLABI_API void AnyType::Loesche<Text>(const Text&);
	template<> OKLABI_API void AnyType::Loesche<Datum>(const Datum&);
	template<> OKLABI_API void AnyType::Loesche<Koordinate>(const Koordinate&);
	template<> OKLABI_API void AnyType::Loesche<Fachobjekt*>(const FachobjektPtr&);
	template<> OKLABI_API void AnyType::Loesche<Geometrie*>(const GeometriePtr&);
	template<> OKLABI_API void AnyType::Loesche<GeoPunkt*>(const GeoPunktPtr&);
	template<> OKLABI_API void AnyType::Loesche<GeoPfad*>(const GeoPfadPtr&);
	template<> OKLABI_API void AnyType::Loesche<GeoLinie*>(const GeoLiniePtr&);
	template<> OKLABI_API void AnyType::Loesche<GeoSpline*>(const GeoSplinePtr&);
	template<> OKLABI_API void AnyType::Loesche<GeoKreisbogen*>(const GeoKreisbogenPtr&);
	template<> OKLABI_API void AnyType::Loesche<GeoFlaeche*>(const GeoFlaechePtr&);
	template<> OKLABI_API void AnyType::Loesche<GeoVolumen*>(const GeoVolumenPtr&);
	template<> OKLABI_API void AnyType::Loesche<Binaerdaten*>(const BinaerdatenPtr&);

	template<> OKLABI_API bool AnyType::Gib<bool>() const;
	template<> OKLABI_API BoolMenge AnyType::Gib<BoolMenge>() const;
	template<> OKLABI_API BoolListe AnyType::Gib<BoolListe>() const;
	template<> OKLABI_API int AnyType::Gib<int>() const;
	template<> OKLABI_API IntMenge AnyType::Gib<IntMenge>() const;
	template<> OKLABI_API IntListe AnyType::Gib<IntListe>() const;
	template<> OKLABI_API UINT64 AnyType::Gib<UINT64>() const;
	template<> OKLABI_API LongIntMenge AnyType::Gib<LongIntMenge>() const;
	template<> OKLABI_API LongIntListe AnyType::Gib<LongIntListe>() const;
	template<> OKLABI_API float AnyType::Gib<float>() const;
	template<> OKLABI_API FloatMenge AnyType::Gib<FloatMenge>() const;
	template<> OKLABI_API FloatListe AnyType::Gib<FloatListe>() const;
	template<> OKLABI_API double AnyType::Gib<double>() const;
	template<> OKLABI_API DoubleMenge AnyType::Gib<DoubleMenge>() const;
	template<> OKLABI_API DoubleListe AnyType::Gib<DoubleListe>() const;
	template<> OKLABI_API Text AnyType::Gib<Text>() const;
	template<> OKLABI_API TextMenge AnyType::Gib<TextMenge>() const;
	template<> OKLABI_API TextListe AnyType::Gib<TextListe>() const;
	template<> OKLABI_API Datum AnyType::Gib<Datum>() const;
	template<> OKLABI_API DatumMenge AnyType::Gib<DatumMenge>() const;
	template<> OKLABI_API DatumListe AnyType::Gib<DatumListe>() const;
	template<> OKLABI_API Koordinate AnyType::Gib<Koordinate>() const;
	template<> OKLABI_API KoordinatenMenge AnyType::Gib<KoordinatenMenge>() const;
	template<> OKLABI_API KoordinatenListe AnyType::Gib<KoordinatenListe>() const;
	template<> OKLABI_API Fachobjekt* AnyType::Gib<Fachobjekt*>() const;
	template<> OKLABI_API FachobjektMenge AnyType::Gib<FachobjektMenge>() const;
	template<> OKLABI_API FachobjektListe AnyType::Gib<FachobjektListe>() const;
#if defined(OKLABI_MEMOPT_2)
	template<> OKLABI_API FachobjektReferenz AnyType::Gib<FachobjektReferenz>() const;
	template<> OKLABI_API FachobjektMengeImpl AnyType::Gib<FachobjektMengeImpl>() const;
	template<> OKLABI_API FachobjektListeImpl AnyType::Gib<FachobjektListeImpl>() const;
#endif
	template<> OKLABI_API Geometrie* AnyType::Gib<Geometrie*>() const;
	template<> OKLABI_API GeoPunkt* AnyType::Gib<GeoPunkt*>() const;
	template<> OKLABI_API GeoPfad* AnyType::Gib<GeoPfad*>() const;
	template<> OKLABI_API GeoLinie* AnyType::Gib<GeoLinie*>() const;
	template<> OKLABI_API GeoSpline* AnyType::Gib<GeoSpline*>() const;
	template<> OKLABI_API GeoKreisbogen* AnyType::Gib<GeoKreisbogen*>() const;
	template<> OKLABI_API GeoFlaeche* AnyType::Gib<GeoFlaeche*>() const;
	template<> OKLABI_API GeoVolumen* AnyType::Gib<GeoVolumen*>() const;
	template<> OKLABI_API GeometrieMenge AnyType::Gib<GeometrieMenge>() const;
	template<> OKLABI_API GeometrieListe AnyType::Gib<GeometrieListe>() const;
	template<> OKLABI_API Binaerdaten* AnyType::Gib<Binaerdaten*>() const;
	template<> OKLABI_API BinaerMenge AnyType::Gib<BinaerMenge>() const;
	template<> OKLABI_API BinaerListe AnyType::Gib<BinaerListe>() const;

	template<> OKLABI_API bool AnyType::GibAnfangswert<bool>() const;
	template<> OKLABI_API int AnyType::GibAnfangswert<int>() const;
	template<> OKLABI_API UINT64 AnyType::GibAnfangswert<UINT64>() const;
	template<> OKLABI_API float AnyType::GibAnfangswert<float>() const;
	template<> OKLABI_API double AnyType::GibAnfangswert<double>() const;
	template<> OKLABI_API Text AnyType::GibAnfangswert<Text>() const;
	template<> OKLABI_API Datum AnyType::GibAnfangswert<Datum>() const;
	template<> OKLABI_API Koordinate AnyType::GibAnfangswert<Koordinate>() const;
	template<> OKLABI_API Fachobjekt* AnyType::GibAnfangswert<Fachobjekt*>() const;
	template<> OKLABI_API Geometrie* AnyType::GibAnfangswert<Geometrie*>() const;
	template<> OKLABI_API GeoPunkt* AnyType::GibAnfangswert<GeoPunkt*>() const;
	template<> OKLABI_API GeoPfad* AnyType::GibAnfangswert<GeoPfad*>() const;
	template<> OKLABI_API GeoLinie* AnyType::GibAnfangswert<GeoLinie*>() const;
	template<> OKLABI_API GeoSpline* AnyType::GibAnfangswert<GeoSpline*>() const;
	template<> OKLABI_API GeoKreisbogen* AnyType::GibAnfangswert<GeoKreisbogen*>() const;
	template<> OKLABI_API GeoFlaeche* AnyType::GibAnfangswert<GeoFlaeche*>() const;
	template<> OKLABI_API GeoVolumen* AnyType::GibAnfangswert<GeoVolumen*>() const;
	template<> OKLABI_API Binaerdaten* AnyType::GibAnfangswert<Binaerdaten*>() const;

	template<> OKLABI_API void AnyType::Setze<FachobjektPtr>(const FachobjektPtr& val);
	template<>            void AnyType::Setze<FachobjektMenge>(const FachobjektMenge& val);
	template<>            void AnyType::Setze<FachobjektListe>(const FachobjektListe& val);
	template<> OKLABI_API void AnyType::Setze<GeometriePtr>(const GeometriePtr& val);
	template<>            void AnyType::Setze<GeometrieMenge>(const GeometrieMenge& val);
	template<>            void AnyType::Setze<GeometrieListe>(const GeometrieListe& val);
	template<> OKLABI_API void AnyType::Setze<bool>(const bool& val);
	template<>            void AnyType::Setze<BoolMenge>(const BoolMenge& val);
	template<>            void AnyType::Setze<BoolListe>(const BoolListe& val);
	template<> OKLABI_API void AnyType::Setze<int>(const int& val);
	template<>            void AnyType::Setze<IntMenge>(const IntMenge& val);
	template<>            void AnyType::Setze<IntListe>(const IntListe& val);
	template<> OKLABI_API void AnyType::Setze<UINT64>(const UINT64& val);
	template<>            void AnyType::Setze<LongIntMenge>(const LongIntMenge& val);
	template<>            void AnyType::Setze<LongIntListe>(const LongIntListe& val);
	template<> OKLABI_API void AnyType::Setze<float>(const float& val);
	template<>            void AnyType::Setze<FloatMenge>(const FloatMenge& val);
	template<>            void AnyType::Setze<FloatListe>(const FloatListe& val);
	template<> OKLABI_API void AnyType::Setze<double>(const double& val);
	template<>            void AnyType::Setze<DoubleMenge>(const DoubleMenge& val);
	template<>            void AnyType::Setze<DoubleListe>(const DoubleListe& val);
	template<> OKLABI_API void AnyType::Setze<Text>(const Text& val);
	template<>            void AnyType::Setze<TextMenge>(const TextMenge& val);
	template<>            void AnyType::Setze<TextListe>(const TextListe& val);
	template<> OKLABI_API void AnyType::Setze<Datum>(const Datum& val);
	template<>            void AnyType::Setze<DatumMenge>(const DatumMenge& val);
	template<>            void AnyType::Setze<DatumListe>(const DatumListe& val);
	template<> OKLABI_API void AnyType::Setze<Koordinate>(const Koordinate& val);
	template<>            void AnyType::Setze<KoordinatenMenge>(const KoordinatenMenge& val);
	template<>            void AnyType::Setze<KoordinatenListe>(const KoordinatenListe& val);
	template<> OKLABI_API void AnyType::Setze<BinaerdatenPtr>(const BinaerdatenPtr& val);
	template<>            void AnyType::Setze<BinaerMenge>(const BinaerMenge& val);
	template<>            void AnyType::Setze<BinaerListe>(const BinaerListe& val);

	template<> OKLABI_API void AnyType::FuegeHinzu<FachobjektPtr>(const FachobjektPtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<GeometriePtr>(const GeometriePtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<GeoPunktPtr>(const GeoPunktPtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<GeoPfadPtr>(const GeoPfadPtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<GeoLiniePtr>(const GeoLiniePtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<GeoSplinePtr>(const GeoSplinePtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<GeoKreisbogenPtr>(const GeoKreisbogenPtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<GeoFlaechePtr>(const GeoFlaechePtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<GeoVolumenPtr>(const GeoVolumenPtr& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<bool>(const bool& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<int>(const int& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<UINT64>(const UINT64& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<float>(const float& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<double>(const double& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<Text>(const Text& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<Datum>(const Datum& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<Koordinate>(const Koordinate& val);
	template<> OKLABI_API void AnyType::FuegeHinzu<BinaerdatenPtr>(const BinaerdatenPtr& val);

	template<> OKLABI_API void AnyType::FuegeHinzuBei<FachobjektPtr>(const FachobjektPtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<GeometriePtr>(const GeometriePtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<GeoPunktPtr>(const GeoPunktPtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<GeoPfadPtr>(const GeoPfadPtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<GeoLiniePtr>(const GeoLiniePtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<GeoSplinePtr>(const GeoSplinePtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<GeoKreisbogenPtr>(const GeoKreisbogenPtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<GeoFlaechePtr>(const GeoFlaechePtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<GeoVolumenPtr>(const GeoVolumenPtr& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<bool>(const bool& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<int>(const int& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<UINT64>(const UINT64& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<float>(const float& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<double>(const double& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<Text>(const Text& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<Datum>(const Datum& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<Koordinate>(const Koordinate& val, size_t);
	template<> OKLABI_API void AnyType::FuegeHinzuBei<BinaerdatenPtr>(const BinaerdatenPtr& val, size_t);

	template<> OKLABI_API bool AnyType::IstEnthalten<GeoPunktPtr>(const GeoPunktPtr&) const;
	template<> OKLABI_API bool AnyType::IstEnthalten<GeoPfadPtr>(const GeoPfadPtr&) const;
	template<> OKLABI_API bool AnyType::IstEnthalten<GeoLiniePtr>(const GeoLiniePtr&) const;
	template<> OKLABI_API bool AnyType::IstEnthalten<GeoSplinePtr>(const GeoSplinePtr&) const;
	template<> OKLABI_API bool AnyType::IstEnthalten<GeoKreisbogenPtr>(const GeoKreisbogenPtr&) const;
	template<> OKLABI_API bool AnyType::IstEnthalten<GeoFlaechePtr>(const GeoFlaechePtr&) const;
	template<> OKLABI_API bool AnyType::IstEnthalten<GeoVolumenPtr>(const GeoVolumenPtr&) const;

	template<> OKLABI_API GeoPunktPtr AnyType::GibBei<GeoPunktPtr>(size_t) const;
	template<> OKLABI_API GeoPfadPtr AnyType::GibBei<GeoPfadPtr>(size_t) const;
	template<> OKLABI_API GeoLiniePtr AnyType::GibBei<GeoLiniePtr>(size_t) const;
	template<> OKLABI_API GeoSplinePtr AnyType::GibBei<GeoSplinePtr>(size_t) const;
	template<> OKLABI_API GeoKreisbogenPtr AnyType::GibBei<GeoKreisbogenPtr>(size_t) const;
	template<> OKLABI_API GeoFlaechePtr AnyType::GibBei<GeoFlaechePtr>(size_t) const;
	template<> OKLABI_API GeoVolumenPtr AnyType::GibBei<GeoVolumenPtr>(size_t) const;
	
	template<> OKLABI_API void AnyType::GibAlle<GeoPunktPtr>(GeoPunktPtr []) const;
	template<> OKLABI_API void AnyType::GibAlle<GeoPfadPtr>(GeoPfadPtr []) const;
	template<> OKLABI_API void AnyType::GibAlle<GeoLiniePtr>(GeoLiniePtr []) const;
	template<> OKLABI_API void AnyType::GibAlle<GeoSplinePtr>(GeoSplinePtr []) const;
	template<> OKLABI_API void AnyType::GibAlle<GeoKreisbogenPtr>(GeoKreisbogenPtr []) const;
	template<> OKLABI_API void AnyType::GibAlle<GeoFlaechePtr>(GeoFlaechePtr []) const;
	template<> OKLABI_API void AnyType::GibAlle<GeoVolumenPtr>(GeoVolumenPtr []) const;

	template<> Text AnyType::WandleText<bool>() const;
	template<> Text AnyType::WandleText<BoolMenge>() const;
	template<> Text AnyType::WandleText<BoolListe>() const;
	template<> Text AnyType::WandleText<int>() const;
	template<> Text AnyType::WandleText<IntMenge>() const;
	template<> Text AnyType::WandleText<IntListe>() const;
	template<> Text AnyType::WandleText<UINT64>() const;
	template<> Text AnyType::WandleText<LongIntMenge>() const;
	template<> Text AnyType::WandleText<LongIntListe>() const;
	template<> Text AnyType::WandleText<float>() const;
	template<> Text AnyType::WandleText<FloatMenge>() const;
	template<> Text AnyType::WandleText<FloatListe>() const;
	template<> Text AnyType::WandleText<double>() const;
	template<> Text AnyType::WandleText<DoubleMenge>() const;
	template<> Text AnyType::WandleText<DoubleListe>() const;
	template<> Text AnyType::WandleText<Text>() const;
	template<> Text AnyType::WandleText<TextMenge>() const;
	template<> Text AnyType::WandleText<TextListe>() const;
	template<> Text AnyType::WandleText<Datum>() const;
	template<> Text AnyType::WandleText<DatumMenge>() const;
	template<> Text AnyType::WandleText<DatumListe>() const;
	template<> Text AnyType::WandleText<Koordinate>() const;
	template<> Text AnyType::WandleText<KoordinatenMenge>() const;
	template<> Text AnyType::WandleText<KoordinatenListe>() const;
	template<> Text AnyType::WandleText<Fachobjekt*>() const;
	template<> Text AnyType::WandleText<FachobjektMenge>() const;
	template<> Text AnyType::WandleText<FachobjektListe>() const;
	template<> Text AnyType::WandleText<Geometrie*>() const;
	template<> Text AnyType::WandleText<GeoPunkt*>() const;
	template<> Text AnyType::WandleText<GeoPfad*>() const;
	template<> Text AnyType::WandleText<GeoLinie*>() const;
	template<> Text AnyType::WandleText<GeoSpline*>() const;
	template<> Text AnyType::WandleText<GeoKreisbogen*>() const;
	template<> Text AnyType::WandleText<GeoFlaeche*>() const;
	template<> Text AnyType::WandleText<GeoVolumen*>() const;
	template<> Text AnyType::WandleText<GeometrieMenge>() const;
	template<> Text AnyType::WandleText<GeometrieListe>() const;
	template<> Text AnyType::WandleText<Binaerdaten*>() const;
	template<> Text AnyType::WandleText<BinaerMenge>() const;
	template<> Text AnyType::WandleText<BinaerListe>() const;

	template<> eTyp AnyType::WandleTyp<bool>() const;
	template<> eTyp AnyType::WandleTyp<BoolMenge>() const;
	template<> eTyp AnyType::WandleTyp<BoolListe>() const;
	template<> eTyp AnyType::WandleTyp<int>() const;
	template<> eTyp AnyType::WandleTyp<IntMenge>() const;
	template<> eTyp AnyType::WandleTyp<IntListe>() const;
	template<> eTyp AnyType::WandleTyp<UINT64>() const;
	template<> eTyp AnyType::WandleTyp<LongIntMenge>() const;
	template<> eTyp AnyType::WandleTyp<LongIntListe>() const;
	template<> eTyp AnyType::WandleTyp<float>() const;
	template<> eTyp AnyType::WandleTyp<FloatMenge>() const;
	template<> eTyp AnyType::WandleTyp<FloatListe>() const;
	template<> eTyp AnyType::WandleTyp<double>() const;
	template<> eTyp AnyType::WandleTyp<DoubleMenge>() const;
	template<> eTyp AnyType::WandleTyp<DoubleListe>() const;
	template<> eTyp AnyType::WandleTyp<Text>() const;
	template<> eTyp AnyType::WandleTyp<TextMenge>() const;
	template<> eTyp AnyType::WandleTyp<TextListe>() const;
	template<> eTyp AnyType::WandleTyp<Datum>() const;
	template<> eTyp AnyType::WandleTyp<DatumMenge>() const;
	template<> eTyp AnyType::WandleTyp<DatumListe>() const;
	template<> eTyp AnyType::WandleTyp<Koordinate>() const;
	template<> eTyp AnyType::WandleTyp<KoordinatenMenge>() const;
	template<> eTyp AnyType::WandleTyp<KoordinatenListe>() const;
	template<> eTyp AnyType::WandleTyp<Fachobjekt*>() const;
	template<> eTyp AnyType::WandleTyp<FachobjektMenge>() const;
	template<> eTyp AnyType::WandleTyp<FachobjektListe>() const;
	template<> eTyp AnyType::WandleTyp<Geometrie*>() const;
	template<> eTyp AnyType::WandleTyp<GeoPunkt*>() const;
	template<> eTyp AnyType::WandleTyp<GeoPfad*>() const;
	template<> eTyp AnyType::WandleTyp<GeoLinie*>() const;
	template<> eTyp AnyType::WandleTyp<GeoSpline*>() const;
	template<> eTyp AnyType::WandleTyp<GeoKreisbogen*>() const;
	template<> eTyp AnyType::WandleTyp<GeoFlaeche*>() const;
	template<> eTyp AnyType::WandleTyp<GeoVolumen*>() const;
	template<> eTyp AnyType::WandleTyp<GeometrieMenge>() const;
	template<> eTyp AnyType::WandleTyp<GeometrieListe>() const;
	template<> eTyp AnyType::WandleTyp<Binaerdaten*>() const;
	template<> eTyp AnyType::WandleTyp<BinaerMenge>() const;
	template<> eTyp AnyType::WandleTyp<BinaerListe>() const;

	template<> eAggreg AnyType::WandleAggregation<bool>() const;
	template<> eAggreg AnyType::WandleAggregation<BoolMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<BoolListe>() const;
	template<> eAggreg AnyType::WandleAggregation<int>() const;
	template<> eAggreg AnyType::WandleAggregation<IntMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<IntListe>() const;
	template<> eAggreg AnyType::WandleAggregation<UINT64>() const;
	template<> eAggreg AnyType::WandleAggregation<LongIntMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<LongIntListe>() const;
	template<> eAggreg AnyType::WandleAggregation<float>() const;
	template<> eAggreg AnyType::WandleAggregation<FloatMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<FloatListe>() const;
	template<> eAggreg AnyType::WandleAggregation<double>() const;
	template<> eAggreg AnyType::WandleAggregation<DoubleMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<DoubleListe>() const;
	template<> eAggreg AnyType::WandleAggregation<Text>() const;
	template<> eAggreg AnyType::WandleAggregation<TextMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<TextListe>() const;
	template<> eAggreg AnyType::WandleAggregation<Datum>() const;
	template<> eAggreg AnyType::WandleAggregation<DatumMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<DatumListe>() const;
	template<> eAggreg AnyType::WandleAggregation<Koordinate>() const;
	template<> eAggreg AnyType::WandleAggregation<KoordinatenMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<KoordinatenListe>() const;
	template<> eAggreg AnyType::WandleAggregation<Fachobjekt*>() const;
	template<> eAggreg AnyType::WandleAggregation<FachobjektMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<FachobjektListe>() const;
	template<> eAggreg AnyType::WandleAggregation<Geometrie*>() const;
	template<> eAggreg AnyType::WandleAggregation<GeoPunkt*>() const;
	template<> eAggreg AnyType::WandleAggregation<GeoPfad*>() const;
	template<> eAggreg AnyType::WandleAggregation<GeoLinie*>() const;
	template<> eAggreg AnyType::WandleAggregation<GeoSpline*>() const;
	template<> eAggreg AnyType::WandleAggregation<GeoKreisbogen*>() const;
	template<> eAggreg AnyType::WandleAggregation<GeoFlaeche*>() const;
	template<> eAggreg AnyType::WandleAggregation<GeoVolumen*>() const;
	template<> eAggreg AnyType::WandleAggregation<GeometrieMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<GeometrieListe>() const;
	template<> eAggreg AnyType::WandleAggregation<Binaerdaten*>() const;
	template<> eAggreg AnyType::WandleAggregation<BinaerMenge>() const;
	template<> eAggreg AnyType::WandleAggregation<BinaerListe>() const;

}	// namespace Oklabi

#ifdef OKLABI_KERN
// Nachfolgende Definitionen werden benutzt für den getypten Durchgriff
// in das AnyType-Objekt. Die Makros führen keine Prüfung durch, bei
// mismatch ist das Resultat undefiniert. Der Verwender ist selbst
// verantwortlich für die Typprüfung.
//
// Die Nutzung dieser Makros ausserhalb der Oklabi-Kernschnittstellen
// wird nicht empfohlen. Bitte benutzen Sie die entsprechenden Gib-
// Schnittstellen am AnyType-Objekt.
//
#ifdef OKLABI_MEMOPT_2
#define FachobjektPtrRef(x) ((FachobjektPtr)(PasIdentifizierer((x)->m_uVal.pid)))
#else
#define FachobjektPtrRef(x) ((FachobjektPtr)((x)->m_uVal.p))
#endif
#ifdef OKLABI_INTERN
#define FachobjektMengeRef(x) ((FachobjektMengeImpl*)(&((x)->m_uVal.xps)))
#define FachobjektListeRef(x) ((FachobjektListeImpl*)(&((x)->m_uVal.xpl)))
#endif

#define KoordTypeRef(x) ((Koordinate::KoordType*)((x)->m_uVal.k))
#define KoordinatenMengeRef(x) ((KoordinatenMenge*)(&((x)->m_uVal.kos)))
#define KoordinatenListeRef(x) ((KoordinatenListe*)(&((x)->m_uVal.kol)))

#define GeometriePtrRef(x) ((GeometriePtr)((x)->m_uVal.g))
#define GeometrieMengeRef(x) ((GeometrieMenge*)(&((x)->m_uVal.gs)))
#define GeometrieListeRef(x) ((GeometrieListe*)(&((x)->m_uVal.gl)))

#define BinaerdatenPtrRef(x) ((BinaerdatenPtr)((x)->m_uVal.bin))
#define BinaerMengeRef(x) ((BinaerMenge*)(&((x)->m_uVal.bis)))
#define BinaerListeRef(x) ((BinaerListe*)(&((x)->m_uVal.bil)))

#define IntMengeRef(x) ((IntMenge*)(&((x)->m_uVal.is)))
#define IntListeRef(x) ((IntListe*)(&((x)->m_uVal.il)))

#define LongIntMengeRef(x) ((LongIntMenge*)(&((x)->m_uVal.ls)))
#define LongIntListeRef(x) ((LongIntListe*)(&((x)->m_uVal.ll)))

#define FloatMengeRef(x) ((FloatMenge*)(&((x)->m_uVal.fs)))
#define FloatListeRef(x) ((FloatListe*)(&((x)->m_uVal.fl)))

#define DoubleMengeRef(x) ((DoubleMenge*)(&((x)->m_uVal.ds)))
#define DoubleListeRef(x) ((DoubleListe*)(&((x)->m_uVal.dl)))

#define BoolMengeRef(x) ((BoolMenge*)(&((x)->m_uVal.bs)))
#define BoolListeRef(x) ((BoolListe*)(&((x)->m_uVal.bl)))

#define DatumMengeRef(x) ((DatumMenge*)(&((x)->m_uVal.das)))
#define DatumListeRef(x) ((DatumListe*)(&((x)->m_uVal.dal)))

#define TextMengeRef(x) ((TextMenge*)(&((x)->m_uVal.ss)))
#define TextListeRef(x) ((TextListe*)(&((x)->m_uVal.sl)))
#endif

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFAnyType
