/*****************************************************************************
* $Id: Menge.h 2013-03-11 15:00:00 vogelsang $
* $Paket: Oklabi-Kern $
*
* Projekt:     OKSTRA Klassenbibliothek
* Realisiert:  C++ API zum "Objektkatalog für das Straßen- und Verkehrswesen"
* Autor:       Arnold Vogelsang, vogelsang@interactive-instruments.de
*
******************************************************************************
* Copyright (c) 2010-2013, Bundesanstalt für Straßenwesen
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
* 2011-11-10 Isolation verschiedene run-time Umgebungen
* 2013-03-11 Harmonisierung der Schnittstelle
* 
****************************************************************************/
#include "OklabiPackaging.h"

#ifndef DEFMenge
#define DEFMenge

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "Aggregat.h"
#include "Ausnahme.h"

namespace Oklabi
{

template<class T> class Menge : public AggregatMenge
{
public:
	typedef T value_type;

private:
	std::set<T, valcmp<T> >* m_pSet;

public:
	class iterator;
	class const_iterator;

	Menge()
	{
		m_pSet = AggregatMengeTempl<T>::get()->create((value_type*)0);
	};
	Menge( const Menge& Set )
	{
		m_pSet = AggregatMengeTempl<T>::get()->assign(Set.m_pSet);
	};
	~Menge()
	{
		AggregatMengeTempl<T>::get()->dispose(m_pSet);
	};
	Menge& operator=( const Menge& Set )
	{
		if (Set.m_pSet != m_pSet)
		{
			AggregatMengeTempl<T>::get()->dispose(m_pSet);
			m_pSet = AggregatMengeTempl<T>::get()->assign(Set.m_pSet);
		}
		return *this;
	};

	iterator begin() { return iterator( AggregatMengeTempl<T>::get()->begin(*m_pSet) ); };
	const_iterator begin() const { return const_iterator( AggregatMengeTempl<T>::get()->begin(*m_pSet) ); };

	iterator end() { return iterator( AggregatMengeTempl<T>::get()->end(*m_pSet) ); };
	const_iterator end() const { return const_iterator( AggregatMengeTempl<T>::get()->end(*m_pSet) ); };

	iterator find( const value_type& val )
	{
		return iterator( AggregatMengeTempl<T>::get()->find(*m_pSet, val) );
	};
	const_iterator find( const value_type& val ) const
	{
		return const_iterator( AggregatMengeTempl<T>::get()->find(*m_pSet, val) );
	};

	void insert( iterator& first, iterator& last )
	{
		while ( first != last )
			{ AggregatMengeTempl<T>::get()->insert(*m_pSet, *first); ++first; }
	};

	void insert( const_iterator& first, const_iterator& last )
	{
		while ( first != last )
			{ AggregatMengeTempl<T>::get()->insert(*m_pSet, *first); ++first; }
	};

	iterator insert( iterator& it, const value_type& pElmt )
	{
		std::pair<typename std::set<T, valcmp<T> >::iterator*, bool > res = AggregatMengeTempl<T>::get()->insert(*m_pSet, *it);
		return iterator( res.first );
	};

	iterator insert( const_iterator& it, const value_type& pElmt )
	{
		std::pair<typename std::set<T, valcmp<T> >::iterator*, bool > res = AggregatMengeTempl<T>::get()->insert(*m_pSet, *it);
		return iterator( res.first );
	};

	std::pair<iterator,bool> insert( const value_type& pElmt )
	{
		std::pair<typename std::set<T, valcmp<T> >::iterator*, bool > res = AggregatMengeTempl<T>::get()->insert(*m_pSet, pElmt);
		return std::pair<iterator,bool>( iterator( res.first ), res.second );
	};

	size_t erase( value_type pElmt ) { return AggregatMengeTempl<T>::get()->erase(*m_pSet, pElmt ); };
	iterator erase( iterator& ipElmt ) { return iterator( AggregatMengeTempl<T>::get()->erase(*m_pSet, *ipElmt.m_pIt) ); };

	bool empty() const { return AggregatMengeTempl<T>::get()->empty(*m_pSet); };

	size_t size() const { return AggregatMengeTempl<T>::get()->size(*m_pSet); };

	void clear() { AggregatMengeTempl<T>::get()->clear(*m_pSet); };

	class iterator : public AggregatMenge
	{
	private:
		friend class Menge<T>;
		friend class const_iterator;
		typename std::set<T, valcmp<T> >::iterator* m_pIt;

		explicit iterator(typename std::set<T, valcmp<T> >::iterator* aufz)
		{
			m_pIt = aufz;
		};

	public:
		iterator() : m_pIt(0) {};
		iterator( const iterator& ipElmt )
		{
			m_pIt = AggregatMengeTempl<T>::getI()->assign(ipElmt.m_pIt);
		};
		~iterator()
		{
			AggregatMengeTempl<T>::getI()->dispose(m_pIt);
		};

		iterator& operator=( const iterator& ipElmt )
		{
			if (ipElmt.m_pIt != m_pIt)
			{
				AggregatMengeTempl<T>::getI()->dispose(m_pIt);
				m_pIt = AggregatMengeTempl<T>::getI()->assign(ipElmt.m_pIt);
			}
			return *this;
		};

		iterator& operator++()
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			AggregatMengeTempl<T>::getI()->preIncrement(m_pIt);
			return *this;
		};
		iterator operator++( int i )
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			iterator tmp = *this;
			AggregatMengeTempl<T>::getI()->postIncrement(m_pIt);
			return tmp;
		};

		iterator& operator--()
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			AggregatMengeTempl<T>::getI()->preDecrement(m_pIt);
			return *this;
		};
		iterator operator--( int i )
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			iterator tmp = *this;
			AggregatMengeTempl<T>::getI()->postDecrement(m_pIt);
			return tmp;
		};

		value_type operator*() const
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			return AggregatMengeTempl<T>::getI()->element(*m_pIt);
		};

		const value_type* operator->() const
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			return AggregatMengeTempl<T>::getI()->element(m_pIt);
		};

		bool operator==( const iterator& ipElmt ) const
		{
			return AggregatMengeTempl<T>::getI()->equal(m_pIt, ipElmt.m_pIt);
		};
		bool operator!=( const iterator& ipElmt ) const
		{
			return !AggregatMengeTempl<T>::getI()->equal(m_pIt, ipElmt.m_pIt);
		};
	};
	
	class const_iterator : public AggregatMenge
	{
	private:
		friend class Menge<T>;
		typename std::set<T, valcmp<T> >::const_iterator* m_pIt;

		explicit const_iterator( typename std::set<T, valcmp<T> >::const_iterator* aufz)
		{
			m_pIt = AggregatMengeTempl<T>::getCI()->assign(aufz);
			AggregatMengeTempl<T>::getCI()->dispose(aufz);
		};
#if !defined(LINUX) && !defined(CYGWIN) && !defined(MSVC100)
		explicit const_iterator( typename std::set<T, valcmp<T> >::iterator* aufz)
		{
			m_pIt = AggregatMengeTempl<T>::getCI()->assign(aufz);
			AggregatMengeTempl<T>::getCI()->dispose(aufz);
		};
#endif
	public:
		const_iterator() : m_pIt(0) {};
		const_iterator( const const_iterator& ipElmt )
		{
			m_pIt = AggregatMengeTempl<T>::getCI()->assign(ipElmt.m_pIt); 
		};
		explicit const_iterator( const iterator& ipElmt )
		{
			m_pIt = AggregatMengeTempl<T>::getCI()->assign(ipElmt.m_pIt); 
		};
		~const_iterator()
		{
			AggregatMengeTempl<T>::getCI()->dispose(m_pIt);
		};

		const_iterator& operator=( const const_iterator& ipElmt )
		{
			if (ipElmt.m_pIt != m_pIt)
			{
				AggregatMengeTempl<T>::getCI()->dispose(m_pIt);
				m_pIt = AggregatMengeTempl<T>::getCI()->assign(ipElmt.m_pIt);
			}
			return *this;
		};
		const_iterator& operator=( const iterator& ipElmt )
		{
			if (ipElmt.m_pIt != m_pIt)
			{
				AggregatMengeTempl<T>::getCI()->dispose(m_pIt);
				m_pIt = AggregatMengeTempl<T>::getCI()->assign(ipElmt.m_pIt);
			}
			return *this;
		};

		const_iterator& operator++()
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			AggregatMengeTempl<T>::getCI()->preIncrement(m_pIt);
			return *this;
		};
		const_iterator operator++( int i )
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			const_iterator tmp = *this;
			AggregatMengeTempl<T>::getCI()->postIncrement(m_pIt);
			return tmp;
		};

		const_iterator& operator--()
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			AggregatMengeTempl<T>::getCI()->preDecrement(m_pIt);
			return *this;
		};
		const_iterator operator--( int i )
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			const_iterator tmp = *this;
			AggregatMengeTempl<T>::getCI()->postDecrement(m_pIt);
			return tmp;
		};

		const value_type operator*() const
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			return (const value_type)AggregatMengeTempl<T>::getCI()->element(*m_pIt);
		};
		const value_type* operator->() const
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			return (const value_type*)AggregatMengeTempl<T>::getCI()->element(m_pIt);
		};

		bool operator==( const const_iterator& ipElmt ) const
		{
			return AggregatMengeTempl<T>::getCI()->equal(m_pIt, ipElmt.m_pIt);
		};
		bool operator==( const iterator& ipElmt ) const
		{
			return AggregatMengeTempl<T>::getCI()->equal(m_pIt, ipElmt.m_pIt);
		};
		bool operator!=( const const_iterator& ipElmt ) const
		{
			return !AggregatMengeTempl<T>::getCI()->equal(m_pIt, ipElmt.m_pIt);
		};
		bool operator!=( const iterator& ipElmt ) const
		{
			return !AggregatMengeTempl<T>::getCI()->equal(m_pIt, ipElmt.m_pIt);
		};
	};
};

}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFMenge
