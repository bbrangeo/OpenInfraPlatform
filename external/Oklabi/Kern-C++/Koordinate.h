/*****************************************************************************
* $Id: Koordinate.h 2015-01-29 15:00:00 vogelsang $
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
* 2010-10-29 Prüfung Koordinatenreferenzsystem
* 2011-01-20 Ausgabe bei kompakter Geometriespeicherung
* 2012-04-27 Abstand zwischen zwei Punkten
* 2012-09-18 Koordinatenreferenzsysteme bearbeitet
* 2013-02-04 Übernahme Koordinatenreferenzsystem
* 2013-02-04 Profile
* 2013-10-21 Speicheroptimierungen bei Koordinaten
* 2013-11-18 Transformierer eingeführt
* 2013-12-17 Instanzen für Wert-Objekte zulassen
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-06-18 Initialisierung Koordinatenreferenzsystem wenn unbelegt
* 2014-07-10 SQL-Anbindung vorbereiten
* 2014-07-30 Geometrie in Gml wandeln
* 2014-08-12 Geometrie in 2D wandeln
* 2015-01-29 Koordinatenreferenzsystem nicht transportiert
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFKoordinate
#define DEFKoordinate

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiKern.h"

namespace Oklabi
{
	class OKLABI_API Koordinate : public OklabiObjekt
	{
		friend class CTEEingabeKonverter;
		friend class CTEAusgabeKonverter;
		friend class XMLEingabeKonverter;
		friend class XMLAusgabeKonverter;
		friend class XMLAdapter;
		friend class AnyType;
		friend class AnyEnumerator;
		friend class SchemaGeo;
		friend class Fachobjekt;
		friend class Profil;
		friend class Umgebung;
		friend class GeoPunkt;
		friend class GeoLinie;
		friend class GeoKreisbogen;
		friend class GeoFlaeche;
		friend class OGRTransformierer;
#if defined(OKLABI_MEMOPT_2)
		friend class PasIdentifizierer;
#endif
#if defined(OKLABI_SQL)
		friend class SQLVerbindung;
#endif
	private:
		struct StatusType
		{
			unsigned char m_eConnCode;
			unsigned char m_eStatus;
			mutable unsigned short m_eSRS;
		};
		class KoordPool;
		class KoordType : public OklabiRoot
		{
			friend class Koordinate;
			friend class KoordPool;
			friend class AnyType;
			friend class SchemaGeo;
			friend class Umgebung;
			friend class Fachobjekt;
			friend class OGRTransformierer;
#if defined(OKLABI_MEMOPT_2)
			friend class PasIdentifizierer;
#endif
		private:
			union
			{
				double	   m_X;
				KoordType* m_pNext;
			} m_uChain;
			double	m_Y;
			float	m_Z;
			union
			{
				StatusType   m_Zustand;
				unsigned int m_nStatus;
			} m_uStatus;
			KoordType();
			~KoordType();
			KoordType(const KoordType&);
			KoordType&        operator=(const KoordType&);
			KoordType&        operator=(const Koordinate&);
			bool              operator==(const Koordinate&) const;
			double X()        const;
			double Y()        const;
			float Z()         const;
			eKoordRefSys      GibKoordRefSys() const;
			void              SetzeKoordRefSys(eKoordRefSys);
			void              init();
			static KoordType* get();
			static void       cleanup();
			void              release();
			static KoordPool* m_KoordPool;
		} m_Koord;

		class KoordPool : public OklabiRoot
		{
			friend class KoordType;
			friend class Koordinate;
		private:
			KoordPool();
			~KoordPool();
			KoordType*  get();
			KoordType*  getChunk();
			void        release(KoordType*);
			KoordType*  m_pPool;
			KoordType*  m_pFreeList;
			size_t      m_nPoolSize;
		};

	public:
		static Koordinate* Erzeuge(double nx, double ny, float nz = f_undef, eKoordRefSys = Undefiniert);
		static Koordinate  Gib(double nx, double ny, float nz = f_undef, eKoordRefSys = Undefiniert);
		Koordinate*        Kopiere() const;
		eKoordRefSys       GibKoordRefSys() const;
		size_t             GibDimension() const;
		Text               GibText() const;
		WKT                GibWKT() const;
		Text               GibGML(const Text&) const;
		bool               IstGleich(const Koordinate*) const;
		double             X() const;
		void               X(const double&);
		double             Y() const;
		void               Y(const double&);
		float              Z() const;
		void               Z(const float&);
		Text               GibKlassenname() const;
		void               Transformiere(eKoordRefSys);

		// Wegen Verwendung in templates
		Koordinate();
		Koordinate(const Koordinate&);
		Koordinate&        operator=(const Koordinate&);
		bool               operator<(const Koordinate&) const;
		bool               operator==(const Koordinate&) const;
		~Koordinate();

	private:
#ifdef OKLABI_KERN
		Koordinate(double nx, double ny, float nz = f_undef, eKoordRefSys = Undefiniert);
		Koordinate(const KoordType&);

		Koordinate&        operator=(const KoordType&);
		bool               operator!=(const Koordinate& ko) const;

		Text               E_in_pos_ref_system();
		void               S_in_pos_ref_system(const Text&) const;
		bool               Pruefe_pos_ref_system(const Text&, bool=false) const;

		Text               E_in_coordinate_system();
		void               S_in_coordinate_system(const Text&) const;
		bool               Pruefe_coordinate_system(const Text&, bool=false) const;

		void               SetzeKoordRefSys(eKoordRefSys);

		int                E_ConnectionCode() const;
		void               S_ConnectionCode(int);

		double             GibDistanz(const Koordinate&) const;
#endif
		bool               KannVernichten() const;
	};

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFKoordinate
