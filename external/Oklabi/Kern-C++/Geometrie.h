/*****************************************************************************
* $Id: Geometrie.h 2015-03-24 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2015, Bundesanstalt für Straßenwesen
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
* 2010-11-18 Verbesserungen am Laufzeitverhalten
* 2010-12-16 Unterscheidung Begrenzung von Flächen
* 2011-07-05 Umgestaltung bei Komponentenstruktur
* 2011-08-12 template-Defintionen überarbeitet
* 2011-11-14 Erweiterung Geometrie-Schnittstelle
* 2011-11-17 Formale Verbesserungen
* 2012-06-18 Interpolation von Kreisbogen und Spline
* 2013-02-04 Übernahme Koordinatenreferenzsystem
* 2013-02-04 Profile
* 2013-03-11 Harmonisierung der Schnittstelle
* 2013-11-18 Transformierer eingeführt
* 2013-12-12 Fremdobjekt für Nachbarstandards eingeführt
* 2013-01-10 OGR-Transformierer eingebaut
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-01-23 Koordinatenreihenfolge Transformierer
* 2014-05-21 GeoRechteck im Interface verpacken
* 2014-07-30 Geometrie in Gml wandeln
* 2014-08-12 Geometrie in 2D wandeln
* 2015-01-29 Koordinatenreferenzsystem nicht transportiert
* 2015-02-18 Referenzielles Geometrieformat
* 2015-02-24 Referenzielles Geometrieformat(2)
* 2015-03-24 Unnötige virtual-Deklarationen beseitigt
* 
****************************************************************************/
#ifndef DEFGeometrie
#define DEFGeometrie

#include "OklabiPackaging.h"

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <set>
#include <list>

#include "OklabiObjekt.h"
#include "OklabiKern.h"
#include "Enumerator.h"
#include "Transformierer.h"

#ifdef OKLABI_KERN
#include "ogr_geometry.h"
#else
#define OGRGeometry void
#define OGRGeometryCollection void
#define OGRCoordinateTransformation void
#define OGRSpatialReference void
#endif

namespace Oklabi
{
	class GeoPunkt;
	class Geometrie;
	template<class T> class Liste;
	template<class T> class Menge;
	typedef Menge< Geometrie* > GeometrieMenge;
	typedef Liste< Geometrie* > GeometrieListe;

	class OGRTransformierer : public Transformierer
	{
		friend class Umgebung;
		friend class Geometrie;
	public:
		class lessEPSG : public OklabiRoot
		{
			friend class OGRTRansformierer;
		public:
			bool operator() ( const std::pair<int,int> p, const std::pair<int,int> q ) const;
		};
		friend class lessEPSG;
		typedef	std::map<std::pair<int,int>,OGRCoordinateTransformation*,lessEPSG> EPSGtoTRANSmapType;
		typedef std::map<int,OGRSpatialReference*>                                 EPSGtoSRSmapType;

	private:
		OGRTransformierer();
		~OGRTransformierer();
		static void                       Finalisiere();
		static EPSGtoTRANSmapType         m_mapTransformationen;
		static EPSGtoSRSmapType           m_mapSRS;

	public:
		OKLABI_API bool                   Transformiere(Koordinate&, eKoordRefSys) const;
		OKLABI_API bool                   IstUnterstuetzt(eKoordRefSys) const;
		OKLABI_API Text                   GibKlassenname() const;
	private:
		OKLABI_API bool                   IstLatLong(eKoordRefSys) const;
		OKLABI_API bool                   IstEastingNorthing(eKoordRefSys) const;
		static OKLABI_API bool            KannSRS(eKoordRefSys);
		static OGRSpatialReference*       GibSRS(eKoordRefSys, bool=true);
	};

	typedef const Geometrie*           GeometrieConstPtr;
	typedef std::map<const Geometrie*, Geometrie*> MapRefGeoType;
	typedef Menge< GeometrieConstPtr > GeometrieMengeConst;
	typedef Liste< GeometrieConstPtr > GeometrieListeConst;
	class OKLABI_API Geometrie : public OklabiObjekt
	{
#ifdef OKLABI_KERN
		// Typ der Operation
		enum eOperation
		{
			Interpolation          = 0,
			Laengenberechnung      = 1,
			PunktZuBogenlaenge     = 2,
			LotvektorZuBogenlaenge = 3,
			BogenlaengeZuPunkt     = 4,
			Segmentierung          = 5,
			Parallele              = 6,
			TangenteZuBogenlaenge  = 7
		};
#endif

		class Segment
		{
			friend class Geometrie;
			friend class GeoLinie;
			friend class GeoKreisbogen;
			friend class GeoSpline;
		public:
			Segment();
			Segment(const Segment&);
			Segment& operator=(const Segment&);
			Segment(eLinientyp, double[2][5]);
			~Segment();
		private:
			double m_gc[2][5];
			eLinientyp m_eTyp;
		};

#ifdef OKLABI_KERN
		typedef std::list<Geometrie::Segment> segmentListType;
#endif

		friend class AnyType;
		friend class Fachobjekt;
		friend class GeometrieEnumerator;
		friend class SchemaGeo;
		friend class GeoPunkt;
		friend class GeoLinie;
		friend class GeoKreisbogen;
		friend class GeoSpline;
		friend class GeoFlaeche;
		friend class GeoVolumen;
		friend class GeoRechteck;
		friend class Umgebung;
		friend class Profil;
		friend class Transformierer;
		friend class OGRTransformierer;
		friend class XMLAusgabeKonverter;
		friend class XMLEingabeKonverter;
#ifdef OKLABI_KERN
		friend class IsybauImporteur;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
#endif
	public:
		static Geometrie*  Erzeuge(eGeoTyp, eKoordRefSys, const WKT& = "", eLinientyp = keine);
		virtual Geometrie* Kopiere(MapRefGeoType* = NULL) const = 0;
		virtual Geometrie* Interpoliere(double) const;
		virtual Geometrie* Transformiere(eKoordRefSys);
		virtual Geometrie* Wandle2D() const = 0;
		virtual eGeoTyp    GibGeometrietyp() const = 0;
		eKoordRefSys       GibKoordRefSys() const;
		virtual WKT        GibWKT() const = 0;
		virtual Text       GibGML(const Text&) const = 0;
		virtual void       SetzeWKT(const WKT&) = 0;
		virtual Text       GibText() const = 0;
		virtual bool       IstLeer() const;
		virtual bool       IstVerbunden() const;
		Enumerator*        GibEnumerator() const;
		virtual eLinientyp GibLinientyp() const;
		void               Vernichte() const;

	public:
		virtual void       BoundingBox(GeoPunkt&, GeoPunkt&) const;
		virtual void       Loesche() const;
		virtual size_t     GibAnzahlKomponenten() const;
		virtual void       GibKomponenten(Geometrie* arr[], size_t, size_t&) const;
		virtual size_t     GibAnzahlPunkte() const = 0;
		virtual double     GibLaenge() const = 0;

	protected:
		virtual bool       operator==(const Geometrie&) const;
		virtual GeoPunkt   GibAnfangsPunkt() const = 0;
		virtual GeoPunkt   GibEndPunkt() const = 0;
		virtual size_t     GibSpeicherplatz() const = 0;
		Geometrie();
		virtual ~Geometrie();
		Geometrie(const Geometrie&);
		Geometrie& operator=(const Geometrie&);
		Geometrie(const Geometrie&, MapRefGeoType*);
		virtual void       HaengeAn(const Geometrie&, bool, bool) = 0;
		bool               KannVernichten() const;
		bool               IstEnthalten(const Geometrie&, GeometrieMengeConst&) const;
		bool               IstGebunden() const;
		void               BindeEin(const Geometrie&);
		void               SetzeKoordRefSys(eKoordRefSys);
		WKT                WandleWKT() const;
		Text               WandleGML(const Text&) const;
		Text               GibGMLId(const char* = "") const;
		Geometrie*         GibReferenz() const;
		OGRGeometry*       GibKomponente(eGeoTyp, eLinientyp, bool, bool, bool = false) const;
#ifdef OKLABI_KERN
		virtual void       Verteile(eKoordRefSys, eOperation, const GeoPunkt*, double&, Geometrie*&, segmentListType*) const;
		virtual void       Segmentiere(segmentListType&) const;
#endif
		virtual size_t     GibSekundaerSpeicherplatz() const;
		size_t             GibGeometrieSpeicherplatz(OGRGeometry*) const;
		static Geometrie*  Interpoliere(eKoordRefSys, eLinientyp, double[2][5], double, Geometrie* = NULL);
		static void        Initialisiere();
	private:
		void               copyOrAssign(bool, const Geometrie&, MapRefGeoType*);

	protected:
		mutable OGRGeometry*           m_pGeometry;
		mutable GeometrieListe*        m_pListGeo;
		mutable GeometrieListe*        m_pListOwn;
//		mutable UINT64                 m_nRef;
		mutable eKoordRefSys           m_eCRS;
		mutable bool                   m_bConnected;
		mutable bool                   m_bExterior;
	public:
		static const double            PI;
	};

	class GeoLinie;
	class OKLABI_API GeoPunkt : public Geometrie
	{
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Geometrie;
		friend class Koordinate;
		friend class BoundingBox;
		friend class BoundCond;
		friend class GeoLinie;
		friend class GeometrieEnumerator;
		friend class GeoRechteck;
		friend class Transformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
	public:
		static GeoPunkt*  Erzeuge();
		static GeoPunkt*  Erzeuge(const Koordinate&);
		static GeoPunkt*  Erzeuge(const double& x, const double& y, const float& z = f_undef, const eKoordRefSys& = Undefiniert);
		void              Setze(const Koordinate&);
		void              FuegeHinzu(const GeoPunkt&);
		void              SetzeEin(const GeoPunkt&);
		Geometrie*        Kopiere(MapRefGeoType* = NULL) const;
		Geometrie*        Transformiere(eKoordRefSys);
		Geometrie*        Wandle2D() const;
		eGeoTyp           GibGeometrietyp() const;
		WKT               GibWKT() const;
		Text              GibGML(const Text&) const;
		void              SetzeWKT(const WKT&);
		Text              GibKlassenname() const;
		Text              GibText() const;
		double            X() const;
		double            Y() const;
		float             Z() const;
		size_t            GibAnzahlPunkte() const;
		double            GibLaenge() const;
		GeoPunkt          GibAnfangsPunkt() const;
		GeoPunkt          GibEndPunkt() const;
		GeoPunkt();
		~GeoPunkt();
		GeoPunkt(const GeoPunkt&);
		GeoPunkt& operator=(const GeoPunkt&);
		GeoPunkt(const double&, const double&, const float& = f_undef, const eKoordRefSys& = Undefiniert);
	private:
		GeoPunkt(const GeoPunkt&, MapRefGeoType*);
		void              SetzeLage(const double&, const double&, const float& = f_undef, const eKoordRefSys& = Undefiniert);
		void              HaengeAn(const Geometrie&, bool, bool);
		size_t            GibSpeicherplatz() const;
		bool operator==(const GeoPunkt&) const;
		bool operator!=(const GeoPunkt& p) const;

	public:
		static double     Abstand(const GeoPunkt&, const GeoPunkt&, bool = false);
		static double     Abstand(const double&, const double&, const double&, const double&);
		static double     Abstand(const double&, const double&, const double&, const double&, const double&, const double&);
	};

	class OKLABI_API GeoPfad : public Geometrie
	{
	public:
		virtual bool     IstGeschlossen() const;
		virtual void     Schliesse();
		virtual void     Wandele();
		void             FuegeHinzu(const GeoPfad&, bool = true);
		void             SetzeEin(const GeoPfad&, bool = true);
	protected:
		GeoPfad();
		~GeoPfad();
		GeoPfad(const GeoPfad&);
		GeoPfad(const GeoPfad&, MapRefGeoType*);
		GeoPfad& operator=(const GeoPfad&);
		bool             m_bGeschlossen;
	};

	class OKLABI_API GeoLinie : public GeoPfad
	{
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Geometrie;
		friend class GeoPunkt;
		friend class GeoFlaeche;
		friend class GeoKreisbogen;
		friend class GeoSpline;
		friend class GeometrieEnumerator;
		friend class Transformierer;
#ifdef OKLABI_KERN
		friend class IsybauImporteur;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
#endif
	public:
		static GeoLinie* Erzeuge();
		static GeoLinie* Erzeuge(const GeoPunkt&, bool = false);
		static GeoLinie* Erzeuge(const AnyType&);
		void             Setze(const GeoPunkt&);
		void             Setze(const AnyType&);
		void             FuegeHinzu(const GeoPunkt&, bool = false);
		void             FuegeHinzu(const AnyType&, bool = false);
		void             SetzeEin(const GeoPunkt&, bool = false);
		Geometrie*       Kopiere(MapRefGeoType* = NULL) const;
		Geometrie*       Transformiere(eKoordRefSys);
		Geometrie*       Interpoliere(double) const;
		Geometrie*       Wandle2D() const;
		eGeoTyp          GibGeometrietyp() const;
		WKT              GibWKT() const;
		Text             GibGML(const Text&) const;
		void             SetzeWKT(const WKT&);
		Text             GibKlassenname() const;
		Text             GibText() const;
		eLinientyp       GibLinientyp() const;
		size_t           GibAnzahlPunkte() const;
		GeoPunkt         GibAnfangsPunkt() const;
		GeoPunkt         GibEndPunkt() const;
		double           GibLaenge() const;
		        GeoPunkt GibPunktPerBogenlaenge(double) const;
		        double   GibBogenlaengePerPunkt(const GeoPunkt&, double) const;
		        GeoPunkt GibLotvektorPerBogenlaenge(const double&, bool = false) const;
		        GeoPunkt GibTangentePerBogenlaenge(const double&, bool = false) const;
		virtual GeoLinie GibTeilgeometrieZwischen(double, double) const;
		        GeoPunkt GibSchnittpunkt(const GeoLinie&) const;
		virtual GeoLinie GibParallele(bool, double) const;
		        GeoLinie DreheUm() const;
		GeoLinie();
		~GeoLinie();
		GeoLinie(const GeoLinie&);
		GeoLinie& operator=(const GeoLinie&);

	private:
		GeoLinie(const GeoLinie&, MapRefGeoType*);
		void             HaengeAn(const Geometrie&, bool, bool);
		void             HaengeAn(const AnyType&, const Text&, bool, bool);
		const Geometrie* Enumeriere(bool&, GeometrieListe::const_iterator*&) const;
#ifdef OKLABI_KERN
		void             Verteile(eKoordRefSys, eOperation, const GeoPunkt*, double&, Geometrie*&, segmentListType*) const;
		void             Segmentiere(segmentListType&) const;
#endif
		size_t           GibSpeicherplatz() const;
		void             Reserviere(size_t, size_t = 0) const;
		bool             IstPolygonzug() const;
		virtual void     Uebernimm(const GeoLinie*);
	};

	// Typ der Randbedingungen für Kreis
	enum eKreisTyp
	{
		Arc = 0,			// Start-, End-, Zwischenpunkt
		Center = 1,			// Start-, End-, Mittelpunkt
		Radius = 2			// Start-, Endpunkt, Radius
	};

	class OKLABI_API GeoKreisbogen : public GeoLinie
	{
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Geometrie;
		friend class GeoPunkt;
		friend class GeoLinie;
		friend class GeoFlaeche;
		friend class GeometrieEnumerator;
		friend class Transformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
	public:
		static GeoKreisbogen* Erzeuge();
		static GeoKreisbogen* Erzeuge(const AnyType&, bool = false);
		void                  Setze(const AnyType&);
		Geometrie*            Kopiere(MapRefGeoType* = NULL) const;
		Geometrie*            Interpoliere(double) const;
		Geometrie*            Transformiere(eKoordRefSys);
		Geometrie*            Wandle2D() const;
		eLinientyp            GibLinientyp() const;
		Text                  GibKlassenname() const;
		GeoPunkt              GibZentrum() const;
		double                GibRadius() const;
		bool                  GibRichtung() const;
		eKreisTyp             GibTyp() const;
		double                GibLaenge() const;
		GeoLinie              GibTeilgeometrieZwischen(double, double) const;
		GeoLinie              GibParallele(bool, double) const;
		GeoKreisbogen();
		~GeoKreisbogen();
		GeoKreisbogen(const GeoKreisbogen&);
		GeoKreisbogen& operator=(const GeoKreisbogen&);

	private:
		GeoKreisbogen(const GeoKreisbogen&, MapRefGeoType*);
		void                  SetzeZentrum(const GeoPunkt&);
		void                  SetzeRadius(const double&);
		void                  SetzeRichtung(const bool&);
		void                  SetzeTyp(const eKreisTyp&);
		void                  Uebernimm(const GeoLinie*);
#ifdef OKLABI_KERN
		void                  Verteile(eKoordRefSys, eOperation, const GeoPunkt*, double&, Geometrie*&, segmentListType*) const;
#endif
		double                m_dRadius;
		GeoPunkt              m_Zentrum;
		bool                  m_bRichtung;
		eKreisTyp             m_eTyp;
	};

	// Typ der Randbedingungen für Spline
	enum eRandbedingung
	{
		Natural = 0,		// Natürliche Randbedingungen
		Tangent = 1,		// Tangentenvektor ist gegeben
		AppPoint = 3,		// Vor- oder Nachlaufpunkte
		TangAndCrv = 4		// Tangentenrichtung und Krümmung
	};

	// Randbedingungen für Spline
	class OKLABI_API RandbedingungSpline
	{
		friend class SchemaGeo;
		friend class GeoSpline;
		eRandbedingung	bci;	// Typ der Randbedingung
		GeoPunkt		vorp;	// Tangentenvektor des Punktes
		double			val;	// Krümmung
	public:
		GeoPunkt        GibVektor() const;
		double          GibParameter() const;
		eRandbedingung  GibTyp() const;
		RandbedingungSpline();
		~RandbedingungSpline();
		RandbedingungSpline(const RandbedingungSpline&);
		RandbedingungSpline& operator=(const RandbedingungSpline&);
	};

	class OKLABI_API GeoSpline : public GeoLinie
	{
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Geometrie;
		friend class GeoPunkt;
		friend class GeoLinie;
		friend class GeoFlaeche;
		friend class GeometrieEnumerator;
		friend class Transformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
	public:
		static GeoSpline*   Erzeuge();
		static GeoSpline*   Erzeuge(const GeoPunkt&, bool = false);
		static GeoSpline*   Erzeuge(const AnyType&);
		void                Setze(const GeoPunkt&);
		void                Setze(const AnyType&);
		void                FuegeHinzu(const GeoPunkt&);
		void                FuegeHinzu(const AnyType&);
		void                SetzeEin(const GeoPunkt&);
		Geometrie*          Kopiere(MapRefGeoType* = NULL) const;
		Geometrie*          Interpoliere(double) const;
		Geometrie*          Wandle2D() const;
		eLinientyp          GibLinientyp() const;
		Text                GibKlassenname() const;
		RandbedingungSpline GibStartbedingung() const;
		RandbedingungSpline GibEndebedingung() const;
		void                SetzeStartbedingung(const RandbedingungSpline&);
		void                SetzeEndebedingung(const RandbedingungSpline&);
		double              GibLaenge() const;
		GeoLinie            GibTeilgeometrieZwischen(double, double) const;
		GeoLinie            GibParallele(bool, double) const;
		GeoSpline();
		~GeoSpline();
		GeoSpline(const GeoSpline&);
		GeoSpline& operator=(const GeoSpline&);

	private:
		GeoSpline(const GeoSpline&, MapRefGeoType*);
		void                Uebernimm(const GeoLinie*);
#ifdef OKLABI_KERN
		void                Verteile(eKoordRefSys, eOperation, const GeoPunkt*, double&, Geometrie*&, segmentListType*) const;
#endif
		RandbedingungSpline m_Start;
		RandbedingungSpline m_Ende;
	};

	class OKLABI_API GeoFlaeche : public Geometrie
	{
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Geometrie;
		friend class GeometrieEnumerator;
		friend class Transformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
	public:
		static GeoFlaeche*  Erzeuge();
		static GeoFlaeche*  Erzeuge(const GeoPfad&, bool = false);
		void                FuegeHinzu(const GeoPfad&);
		void                SetzeEin(const GeoPfad&);
		Geometrie*          Kopiere(MapRefGeoType* = NULL) const;
		Geometrie*          Transformiere(eKoordRefSys);
		Geometrie*          Wandle2D() const;
		eGeoTyp             GibGeometrietyp() const;
		WKT                 GibWKT() const;
		Text                GibGML(const Text&) const;
		void                SetzeWKT(const WKT&);
		Text                GibKlassenname() const;
		Text                GibText() const;
		size_t              GibAnzahlPunkte() const;
		double              GibLaenge() const;
	private:
		void                HaengeAn(const Geometrie&, bool, bool);
		bool                IstAussenrand() const;
		void                IstAussenrand(bool);
		GeoPunkt            GibAnfangsPunkt() const;
		GeoPunkt            GibEndPunkt() const;
		size_t              GibSpeicherplatz() const;
		GeoFlaeche();
		~GeoFlaeche();
		GeoFlaeche(const GeoFlaeche&);
		GeoFlaeche(const GeoFlaeche&, MapRefGeoType*);
		GeoFlaeche& operator=(const GeoFlaeche&);
	};

	class OKLABI_API GeoVolumen : public Geometrie
	{
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Geometrie;
		friend class GeometrieEnumerator;
		friend class Transformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
	public:
		static GeoVolumen*  Erzeuge();
		static GeoVolumen*  Erzeuge(const GeoFlaeche&, bool = false);
		static GeoVolumen*  Erzeuge(const AnyType&);
		void                Setze(const GeoFlaeche&);
		void                Setze(const AnyType&);
		void                FuegeHinzu(const GeoFlaeche&);
		void                FuegeHinzu(const AnyType&);
		void                SetzeEin(const GeoFlaeche&);
		Geometrie*          Kopiere(MapRefGeoType* = NULL) const;
		Geometrie*          Wandle2D() const;
		eGeoTyp             GibGeometrietyp() const;
		WKT                 GibWKT() const;
		Text                GibGML(const Text&) const;
		void                SetzeWKT(const WKT&);
		Text                GibKlassenname() const;
		Text                GibText() const;
		size_t              GibAnzahlPunkte() const;
		double              GibLaenge() const;
	private:
		void                HaengeAn(const Geometrie&, bool, bool);
		void                HaengeAn(const AnyType&, const Text&, bool);
		GeoPunkt            GibAnfangsPunkt() const;
		GeoPunkt            GibEndPunkt() const;
		size_t              GibSpeicherplatz() const;
		GeoVolumen();
		~GeoVolumen();
		GeoVolumen(const GeoVolumen&);
		GeoVolumen(const GeoVolumen&, MapRefGeoType*);
		GeoVolumen& operator=(const GeoVolumen&);
	};

	class OKLABI_API GeoRechteck : public Geometrie
	{
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Geometrie;
		friend class GeoPunkt;
		friend class Transformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
	public:
		static GeoRechteck* Erzeuge();
		static GeoRechteck* Erzeuge(const GeoPunkt&, const GeoPunkt&);
		void                FuegeHinzu(const GeoPunkt&);
		Geometrie*          Kopiere(MapRefGeoType* = NULL) const;
		Geometrie*          Wandle2D() const;
		eGeoTyp             GibGeometrietyp() const;
		WKT                 GibWKT() const;
		Text                GibGML(const Text&) const;
		void                SetzeWKT(const WKT&);
		Text                GibKlassenname() const;
		Text                GibText() const;
		void                BoundingBox(GeoPunkt&, GeoPunkt&) const;
		size_t              GibAnzahlPunkte() const;
		double              GibLaenge() const;
	private:
		size_t              GibAnzahlKomponenten() const;
		void                HaengeAn(const Geometrie&, bool, bool);
	public:
		GeoPunkt            GibAnfangsPunkt() const;
		GeoPunkt            GibEndPunkt() const;
		GeoPunkt            GibLinksUnten() const;
		GeoPunkt            GibRechtsOben() const;
	private:
		size_t              GibSpeicherplatz() const;
		void                Loesche() const;
		void                GibKomponenten(Geometrie* arr[], size_t, size_t&) const;
		GeoRechteck();
		~GeoRechteck();
		GeoRechteck(const GeoRechteck&);
		GeoRechteck(const GeoRechteck&, MapRefGeoType*);
		GeoRechteck& operator=(const GeoRechteck&);
		void                Erweitere(double x, double y);
#ifdef OKLABI_KERN
		mutable OGREnvelope m_Envelope;
#endif
	};

	class OKLABI_API GeometrieEnumerator : public Enumerator
	{
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Geometrie;
		friend class GeoLinie;
		friend class GeoPunkt;
		friend class GeoFlaeche;
		friend class GeoVolumen;
		friend class GeoRechteck;
		friend class Transformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
	public:
		GeometrieEnumerator();
		~GeometrieEnumerator();
		GeometrieEnumerator(const GeometrieEnumerator&);
		GeometrieEnumerator& operator=(const GeometrieEnumerator&);
		GeometrieEnumerator(const Geometrie&);
		Text                GibKlassenname() const;
		template<class T> T GibObjekt();
		void                Weiter();
		bool                IstBeendet() const;
		void                ZumAnfang();
	protected:
		bool                KannVernichten() const;
		eEnumeratorTyp      GibEnumeratorTyp() const;
	private:
		GeoPunkt*           Punkt();
		GeoLinie*           Linie();
		GeoFlaeche*         Flaeche();
		Geometrie*          m_Kontext;
		size_t              m_nRing;
		size_t              m_nKomp;
		mutable size_t      m_nPunkt;
		mutable size_t      m_nPunktInKomp;
		size_t              m_nAnzahl;
		mutable bool        m_bStart;
	};

	typedef Geometrie*          GeometriePtr;
	typedef Menge< Geometrie* > GeometrieMenge;
	typedef Liste< Geometrie* > GeometrieListe;
	typedef GeoPunkt*           GeoPunktPtr;
	typedef GeoPfad*            GeoPfadPtr;
	typedef GeoLinie*           GeoLiniePtr;
	typedef GeoSpline*          GeoSplinePtr;
	typedef GeoKreisbogen*      GeoKreisbogenPtr;
	typedef GeoFlaeche*         GeoFlaechePtr;
	typedef GeoVolumen*         GeoVolumenPtr;

	// Spezialisierungen
	template<> OKLABI_API Geometrie* GeometrieEnumerator::GibObjekt<Geometrie*>();
	template<> OKLABI_API GeoPunkt* GeometrieEnumerator::GibObjekt<GeoPunkt*>();
	template<> OKLABI_API GeoPfad* GeometrieEnumerator::GibObjekt<GeoPfad*>();
	template<> OKLABI_API GeoLinie* GeometrieEnumerator::GibObjekt<GeoLinie*>();
	template<> OKLABI_API GeoSpline* GeometrieEnumerator::GibObjekt<GeoSpline*>();
	template<> OKLABI_API GeoKreisbogen* GeometrieEnumerator::GibObjekt<GeoKreisbogen*>();
	template<> OKLABI_API GeoFlaeche* GeometrieEnumerator::GibObjekt<GeoFlaeche*>();
	template<> OKLABI_API GeoVolumen* GeometrieEnumerator::GibObjekt<GeoVolumen*>();
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif // DEFGeometrie
