/*****************************************************************************
* $Id: Aggregat.h 2015-02-24 15:00:00 vogelsang $
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
* 2011-11-09 Vergleich von Fachobjekten über Objektnummer
* 2012-10-08 Gemeinsame Oberklasse für alle Objekte der Oklabi
* 2013-02-04 Profile
* 2013-03-11 Harmonisierung der Schnittstelle
* 2013-12-12 Fremdobjekt für Nachbarstandards eingeführt
* 2014-01-17 Speicheroptimierungen bei Fachobjekt und Datenbestand
* 2014-03-27 XMLMultiEingabeKonverter eingeführt
* 2014-07-24 Formale Verbesserungen
* 2015-02-24 Referenzielles Geometrieformat(2)
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFAggregat
#define DEFAggregat

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "oklabidll.h"

#include <list>
#include <set>

#include "OklabiKern.h"
#ifdef OKLABI_MEMOPT_2
#include "PasIdentifizierer.h"
#endif

namespace Oklabi
{
	// Gemeinsame Oberklassen für Aggregate
	class Objektart;
	class Eigenschaft;
	class Datenbestand;
	class Fachobjekt;
	class Geometrie;
	class Binaerdaten;
	class AnyType;
	class FblVersion;
	class Profil;
	class Fremdobjekt;
#ifdef OKLABI_MEMOPT_2
	class PasIdentifizierer;
#endif
	typedef const Objektart*               ObjektartConstPtr;
	typedef const Eigenschaft*             EigenschaftConstPtr;
	typedef const Fachobjekt*              FachobjektConstPtr;
	typedef const AnyType*                 AnyTypeConstPtr;
	typedef const FblVersion*              FblVersionConstPtr;
	typedef FblVersion*                    FblVersionPtr;
	class OKLABI_API Aggregat : public OklabiRoot
	{
	public:
		static bool equal(const int&, const int&);
		static bool equal(const UINT64&, const UINT64&);
		static bool equal(const float&, const float&);
		static bool equal(const double&, const double&);
		static bool equal(const bool&, const bool&);
		static bool equal(const Text&, const Text&);
		static bool equal(const Datum&, const Datum&);
		static bool equal(const Koordinate&, const Koordinate&);
		static bool equal(const eKoordRefSys&, const eKoordRefSys&);
		static bool equal(VersionConstPtr, VersionConstPtr);
		static bool equal(FblVersionConstPtr, FblVersionConstPtr);
		static bool equal(const OklabiObjekt*, const OklabiObjekt*);
#ifdef OKLABI_MEMOPT_2
		static bool equal(const PasIdentifizierer&, const PasIdentifizierer&);
#endif

		static bool less(const int&, const int&);
		static bool less(const UINT64&, const UINT64&);
		static bool less(const float&, const float&);
		static bool less(const double&, const double&);
		static bool less(const bool&, const bool&);
		static bool less(const Text&, const Text&);
		static bool less(const Datum&, const Datum&);
		static bool less(const Koordinate&, const Koordinate&);
		static bool less(const eKoordRefSys&, const eKoordRefSys&);
		static bool less(VersionConstPtr, VersionConstPtr);
		static bool less(const OklabiObjekt*, const OklabiObjekt*);
#ifdef OKLABI_MEMOPT_2
		static bool less(const PasIdentifizierer&, const PasIdentifizierer&);
#endif
	};

	template<class T> class valcmp : public OklabiRoot
	{
	public:
		OKLABI_API bool operator()(const T& x, const T& y) const { return Aggregat::less(x, y); };
	};

	class OKLABI_API AggregatListe : public Aggregat
	{
	protected:
		static void* get(int*);
		static void* getI(int*);
		static void* getCI(int*);
		static void* get(UINT64*);
		static void* getI(UINT64*);
		static void* getCI(UINT64*);
		static void* get(float*);
		static void* getI(float*);
		static void* getCI(float*);
		static void* get(double*);
		static void* getI(double*);
		static void* getCI(double*);
		static void* get(bool*);
		static void* getI(bool*);
		static void* getCI(bool*);
		static void* get(Text*);
		static void* getI(Text*);
		static void* getCI(Text*);
		static void* get(Datum*);
		static void* getI(Datum*);
		static void* getCI(Datum*);
		static void* get(Koordinate*);
		static void* getI(Koordinate*);
		static void* getCI(Koordinate*);
		static void* get(eKoordRefSys*);
		static void* getI(eKoordRefSys*);
		static void* getCI(eKoordRefSys*);
		static void* get(Fachobjekt**);
		static void* getI(Fachobjekt**);
		static void* getCI(Fachobjekt**);
		static void* get(const Fachobjekt**);
		static void* getI(const Fachobjekt**);
		static void* getCI(const Fachobjekt**);
		static void* get(Geometrie**);
		static void* getI(Geometrie**);
		static void* getCI(Geometrie**);
		static void* get(const Geometrie**);
		static void* getI(const Geometrie**);
		static void* getCI(const Geometrie**);
		static void* get(Binaerdaten**);
		static void* getI(Binaerdaten**);
		static void* getCI(Binaerdaten**);
		static void* get(ObjektartConstPtr*);
		static void* getI(ObjektartConstPtr*);
		static void* getCI(ObjektartConstPtr*);
		static void* get(EigenschaftConstPtr*);
		static void* getI(EigenschaftConstPtr*);
		static void* getCI(EigenschaftConstPtr*);
		static void* get(AnyTypeConstPtr*);
		static void* getI(AnyTypeConstPtr*);
		static void* getCI(AnyTypeConstPtr*);
		static void* get(Version**);
		static void* getI(Version**);
		static void* getCI(Version**);
		static void* get(VersionConstPtr*);
		static void* getI(VersionConstPtr*);
		static void* getCI(VersionConstPtr*);
		static void* get(FblVersionConstPtr*);
		static void* getI(FblVersionConstPtr*);
		static void* getCI(FblVersionConstPtr*);
		static void* get(FblVersion**);
		static void* getI(FblVersion**);
		static void* getCI(FblVersion**);
		static void* get(Profil**);
		static void* getI(Profil**);
		static void* getCI(Profil**);
		static void* get(Fremdobjekt**);
		static void* getI(Fremdobjekt**);
		static void* getCI(Fremdobjekt**);
#ifdef OKLABI_MEMOPT_2
		static void* get(PasIdentifizierer*);
		static void* getI(PasIdentifizierer*);
		static void* getCI(PasIdentifizierer*);
#endif
		static void* get(Datenbestand**);
		static void* getI(Datenbestand**);
		static void* getCI(Datenbestand**);
	};

	template<class T> class OKLABI_API AggregatListeTempl : public AggregatListe
	{
	public:
		typedef T value_type;

		class OKLABI_API aufzaehler : public Aggregat
		{
		public:
			virtual typename std::list<T>::iterator* assign(const typename std::list<T>::iterator* pIter) = 0;
			virtual void dispose(typename std::list<T>::iterator* pIter) = 0;
			virtual void postIncrement(typename std::list<T>::iterator* pIter) = 0;
			virtual void preIncrement(typename std::list<T>::iterator* pIter) = 0;
			virtual void postDecrement(typename std::list<T>::iterator* pIter) = 0;
			virtual void preDecrement(typename std::list<T>::iterator* pIter) = 0;
			virtual T element(typename std::list<T>::iterator& iter) const = 0;
			virtual T* element(typename std::list<T>::iterator* pIter) const = 0;
			virtual bool equal( typename std::list<T>::iterator* const pIter1, typename std::list<T>::iterator* const pIter2 ) const = 0;
		};

		class OKLABI_API const_aufzaehler : public Aggregat
		{
		public:
			virtual typename std::list<T>::const_iterator* assign(const typename std::list<T>::iterator* pIter) = 0;
			virtual typename std::list<T>::const_iterator* assign(const typename std::list<T>::const_iterator* pIter) = 0;
			virtual void dispose(typename std::list<T>::const_iterator* pIter) = 0;
			virtual void dispose(typename std::list<T>::iterator* pIter) = 0;
			virtual void postIncrement(typename std::list<T>::const_iterator* pIter) = 0;
			virtual void preIncrement(typename std::list<T>::const_iterator* pIter) = 0;
			virtual void postDecrement(typename std::list<T>::const_iterator* pIter) = 0;
			virtual void preDecrement(typename std::list<T>::const_iterator* pIter) = 0;
			virtual const T element(typename std::list<T>::const_iterator& iter) const = 0;
			virtual const T* element(typename std::list<T>::const_iterator* pIter) const = 0;
			virtual bool equal( typename std::list<T>::const_iterator* const pIter1, typename std::list<T>::iterator* const pIter2 ) const = 0;
			virtual bool equal( typename std::list<T>::const_iterator* const pIter1, typename std::list<T>::const_iterator* const pIter2 ) const = 0;
		};
		virtual typename std::list<T>* create(T*) = 0;
		virtual typename std::list<T>* create(T*, size_t l) = 0;
		virtual typename std::list<T>* assign(typename std::list<T>* pList) = 0;
		virtual void dispose(typename std::list<T>* pList) = 0;
		virtual typename std::list<T>::iterator* insert(typename std::list<T>& list, const typename std::list<T>::iterator& iter, const T& elmt) = 0;
		virtual typename std::list<T>::iterator* erase(typename std::list<T>& list, const typename std::list<T>::iterator& iter) = 0;
		virtual void remove(typename std::list<T>& list, const T& elmt) = 0;
		virtual void push_back(typename std::list<T>& list, const T& elmt) = 0;
		virtual void push_front(typename std::list<T>& list, const T& elmt) = 0;
		virtual void pop_back(typename std::list<T>& list) = 0;
		virtual void pop_front(typename std::list<T>& list) = 0;
		virtual void clear(typename std::list<T>& list) = 0;
		virtual bool equal(const typename std::list<T>& list1, const typename std::list<T>& list2) const = 0;
		virtual typename std::list<T>::iterator* begin(typename std::list<T>& list) = 0;
		virtual typename std::list<T>::const_iterator* begin(const typename std::list<T>& list) const = 0;
		virtual typename std::list<T>::iterator* end(typename std::list<T>& list) = 0;
		virtual typename std::list<T>::const_iterator* end(const typename std::list<T>& list) const = 0;
		virtual typename std::list<T>::value_type& front(typename std::list<T>& l) = 0;
		virtual const typename std::list<T>::value_type& front(const typename std::list<T>& l) const = 0;
		virtual typename std::list<T>::value_type& back(typename std::list<T>& l) = 0;
		virtual const typename std::list<T>::value_type& back(const typename std::list<T>& l) const = 0;
		virtual bool empty(const typename std::list<T>& l) const = 0;
		virtual typename std::list<T>::size_type size(const typename std::list<T>& l) const = 0;

		static AggregatListeTempl<T>* get()
		{
			return (AggregatListeTempl<T>*)AggregatListe::get((value_type*)0);
		};
		static typename AggregatListeTempl<T>::aufzaehler* getI()
		{
			return (typename AggregatListeTempl<T>::aufzaehler*)AggregatListe::getI((value_type*)0);
		};
		static typename AggregatListeTempl<T>::const_aufzaehler* getCI()
		{
			return (typename AggregatListeTempl<T>::const_aufzaehler*)AggregatListe::getCI((value_type*)0);
		};
	};

	class OKLABI_API AggregatMenge : public Aggregat
	{
	protected:
		static void* get(int*);
		static void* getI(int*);
		static void* getCI(int*);
		static void* get(UINT64*);
		static void* getI(UINT64*);
		static void* getCI(UINT64*);
		static void* get(float*);
		static void* getI(float*);
		static void* getCI(float*);
		static void* get(double*);
		static void* getI(double*);
		static void* getCI(double*);
		static void* get(bool*);
		static void* getI(bool*);
		static void* getCI(bool*);
		static void* get(Text*);
		static void* getI(Text*);
		static void* getCI(Text*);
		static void* get(Datum*);
		static void* getI(Datum*);
		static void* getCI(Datum*);
		static void* get(Koordinate*);
		static void* getI(Koordinate*);
		static void* getCI(Koordinate*);
		static void* get(eKoordRefSys*);
		static void* getI(eKoordRefSys*);
		static void* getCI(eKoordRefSys*);
		static void* get(Fachobjekt**);
		static void* getI(Fachobjekt**);
		static void* getCI(Fachobjekt**);
		static void* get(const Fachobjekt**);
		static void* getI(const Fachobjekt**);
		static void* getCI(const Fachobjekt**);
		static void* get(Geometrie**);
		static void* getI(Geometrie**);
		static void* getCI(Geometrie**);
		static void* get(const Geometrie**);
		static void* getI(const Geometrie**);
		static void* getCI(const Geometrie**);
		static void* get(Binaerdaten**);
		static void* getI(Binaerdaten**);
		static void* getCI(Binaerdaten**);
		static void* get(ObjektartConstPtr*);
		static void* getI(ObjektartConstPtr*);
		static void* getCI(ObjektartConstPtr*);
		static void* get(EigenschaftConstPtr*);
		static void* getI(EigenschaftConstPtr*);
		static void* getCI(EigenschaftConstPtr*);
		static void* get(AnyTypeConstPtr*);
		static void* getI(AnyTypeConstPtr*);
		static void* getCI(AnyTypeConstPtr*);
		static void* get(Version**);
		static void* getI(Version**);
		static void* getCI(Version**);
		static void* get(VersionConstPtr*);
		static void* getI(VersionConstPtr*);
		static void* getCI(VersionConstPtr*);
		static void* get(FblVersionConstPtr*);
		static void* getI(FblVersionConstPtr*);
		static void* getCI(FblVersionConstPtr*);
		static void* get(FblVersion**);
		static void* getI(FblVersion**);
		static void* getCI(FblVersion**);
		static void* get(Profil**);
		static void* getI(Profil**);
		static void* getCI(Profil**);
		static void* get(Fremdobjekt**);
		static void* getI(Fremdobjekt**);
		static void* getCI(Fremdobjekt**);
#ifdef OKLABI_MEMOPT_2
		static void* get(PasIdentifizierer*);
		static void* getI(PasIdentifizierer*);
		static void* getCI(PasIdentifizierer*);
#endif
		static void* get(Datenbestand**);
		static void* getI(Datenbestand**);
		static void* getCI(Datenbestand**);
	};

	template<class T> class OKLABI_API AggregatMengeTempl : public AggregatMenge
	{
	public:
		typedef T value_type;

		class OKLABI_API aufzaehler : public Aggregat
		{
		public:
			virtual typename std::set<T, valcmp<T> >::iterator* assign(const typename std::set<T, valcmp<T> >::iterator* pIter) = 0;
			virtual void dispose(typename std::set<T, valcmp<T> >::iterator* pIter) = 0;
			virtual void preIncrement(typename std::set<T, valcmp<T> >::iterator* pIter) = 0;
			virtual void postIncrement(typename std::set<T, valcmp<T> >::iterator* pIter) = 0;
			virtual void preDecrement(typename std::set<T, valcmp<T> >::iterator* pIter) = 0;
			virtual void postDecrement(typename std::set<T, valcmp<T> >::iterator* pIter) = 0;
			virtual T element(typename std::set<T, valcmp<T> >::iterator& iter) const = 0;
#if defined(LINUX) || defined(CYGWIN) || defined(MSVC100)
			const
#endif
			virtual T* element(typename std::set<T, valcmp<T> >::iterator* pIter) const = 0;
			virtual bool equal( typename std::set<T, valcmp<T> >::iterator* const pIter1, typename std::set<T, valcmp<T> >::iterator* const pIter2 ) const = 0;
		};

		class OKLABI_API const_aufzaehler : public Aggregat
		{
		public:
			virtual typename std::set<T, valcmp<T> >::const_iterator* assign(const typename std::set<T, valcmp<T> >::iterator* pIter) = 0;
#if !defined(LINUX) && !defined(CYGWIN) && !defined(MSVC100)
			virtual typename std::set<T, valcmp<T> >::const_iterator* assign(const typename std::set<T, valcmp<T> >::const_iterator* pIter) = 0;
#endif
			virtual void dispose(typename std::set<T, valcmp<T> >::const_iterator* pIter) = 0;
			virtual void preIncrement(typename std::set<T, valcmp<T> >::const_iterator* pIter) = 0;
			virtual void postIncrement(typename std::set<T, valcmp<T> >::const_iterator* pIter) = 0;
			virtual void preDecrement(typename std::set<T, valcmp<T> >::const_iterator* pIter) = 0;
			virtual void postDecrement(typename std::set<T, valcmp<T> >::const_iterator* pIter) = 0;
			virtual const T element(typename std::set<T, valcmp<T> >::const_iterator& iter) const = 0;
			virtual const T* element(typename std::set<T, valcmp<T> >::const_iterator* pIter) const = 0;
			virtual bool equal( typename std::set<T, valcmp<T> >::const_iterator* const pIter1, typename std::set<T, valcmp<T> >::iterator* const pIter2 ) const = 0;
#if !defined(LINUX) && !defined(CYGWIN) && !defined(MSVC100)
			virtual bool equal( typename std::set<T, valcmp<T> >::const_iterator* const pIter1, typename std::set<T, valcmp<T> >::const_iterator* const pIter2 ) const = 0;
#endif
		};

		virtual typename std::set<T, valcmp<T> >* create(T*) = 0;
		virtual typename std::set<T, valcmp<T> >* assign(typename std::set<T, valcmp<T> >* pSet) = 0;
		virtual void dispose(typename std::set<T, valcmp<T> >* pSet) = 0;
		virtual std::pair< typename std::set<T, valcmp<T> >::iterator*, bool > insert(typename std::set<T, valcmp<T> >& set, const T& elmt) = 0;
		virtual typename std::set<T, valcmp<T> >::iterator* erase(typename std::set<T, valcmp<T> >& set, const typename std::set<T, valcmp<T> >::iterator& iter) = 0;
		virtual size_t erase(typename std::set<T, valcmp<T> >& set, const T& elmt) = 0;
		virtual void clear(typename std::set<T, valcmp<T> >& set) = 0;
		virtual bool equal(const typename std::set<T, valcmp<T> >& set1, const typename std::set<T, valcmp<T> >& set2) const = 0;
		virtual typename std::set<T, valcmp<T> >::iterator* begin(typename std::set<T, valcmp<T> >& set) = 0;
		virtual typename std::set<T, valcmp<T> >::const_iterator* begin(const typename std::set<T, valcmp<T> >& set) const = 0;
		virtual typename std::set<T, valcmp<T> >::iterator* end(typename std::set<T, valcmp<T> >& set) = 0;
		virtual typename std::set<T, valcmp<T> >::const_iterator* end(const typename std::set<T, valcmp<T> >& set) const = 0;
		virtual typename std::set<T, valcmp<T> >::iterator* find(typename std::set<T, valcmp<T> >& set, const T& val) = 0;
		virtual typename std::set<T, valcmp<T> >::const_iterator* find(const typename std::set<T, valcmp<T> >& set, const T& val) const = 0;
		virtual bool empty(typename std::set<T, valcmp<T> >& set) const = 0;
		virtual size_t size(typename std::set<T, valcmp<T> >& set) const = 0;

		static AggregatMengeTempl<T>* get()
		{
			return (AggregatMengeTempl<T>*)AggregatMenge::get((value_type*)0);
		};
		static typename AggregatMengeTempl<T>::aufzaehler* getI()
		{
			return (typename AggregatMengeTempl<T>::aufzaehler*)AggregatMenge::getI((value_type*)0);
		};
		static typename AggregatMengeTempl<T>::const_aufzaehler* getCI()
		{
			return (typename AggregatMengeTempl<T>::const_aufzaehler*)AggregatMenge::getCI((value_type*)0);
		};
	};
}	// namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFAggregat
