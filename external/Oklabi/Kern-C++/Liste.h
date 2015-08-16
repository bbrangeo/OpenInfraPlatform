/*****************************************************************************
* $Id: Liste.h 2013-03-11 15:00:00 vogelsang $
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

#ifndef DEFListe
#define DEFListe

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "Aggregat.h"

namespace Oklabi
{

template<class T> class Liste : public AggregatListe
{
private:
	std::list<T>*	m_pList;

public:
	typedef T value_type;

	class iterator;
	class const_iterator;

	Liste()
	{
		m_pList = AggregatListeTempl<T>::get()->create((value_type*)0);
	};
	Liste(size_t l)
	{
		m_pList = AggregatListeTempl<T>::get()->create((value_type*)0, l);
	};
	Liste( const Liste& List )
	{
		m_pList = AggregatListeTempl<T>::get()->assign(List.m_pList);
	};
	~Liste()
	{
		AggregatListeTempl<T>::get()->dispose(m_pList);
	};

	Liste& operator=( const Liste& List )
	{
		if (List.m_pList != m_pList)
		{
			AggregatListeTempl<T>::get()->dispose(m_pList);
			m_pList = AggregatListeTempl<T>::get()->assign(List.m_pList);
		}
		return *this;
	};
	bool operator==( const Liste& List ) const { return  AggregatListeTempl<T>::get()->equal(*m_pList, *List.m_pList); };
	bool operator!=( const Liste& List ) const { return !AggregatListeTempl<T>::get()->equal(*m_pList, *List.m_pList); };
	iterator begin() { return iterator( AggregatListeTempl<T>::get()->begin(*m_pList) ); };
	const_iterator begin() const { return const_iterator( AggregatListeTempl<T>::get()->begin(*m_pList) ); };
	iterator end() { return iterator( AggregatListeTempl<T>::get()->end(*m_pList) ); };
	const_iterator end() const { return const_iterator( AggregatListeTempl<T>::get()->end(*m_pList) ); };
	iterator find(iterator first, iterator& last, const value_type& val)
	{
		while ( (first != last) && ( !Aggregat::equal(*first, val)) )
			{ ++first; }
		return first;
	};
	const_iterator find(const_iterator first, const_iterator& last, const value_type& val)
	{
		while ( (first != last) && ( !Aggregat::equal(*first, val)) )
			{ ++first; }
		return first;
	};
	iterator insert( iterator it, const value_type& pElmt )
		{ return iterator( AggregatListeTempl<T>::get()->insert(*m_pList, *it.m_pIt, pElmt) ); };
	iterator erase( iterator& ipElmt )
		{ return iterator( AggregatListeTempl<T>::get()->erase(*m_pList, *ipElmt.m_pIt ) ); };
	void remove( const value_type& pElmt ) { AggregatListeTempl<T>::get()->remove( *m_pList, pElmt ); };
	void push_front( value_type& pElmt ) { AggregatListeTempl<T>::get()->push_front( *m_pList, pElmt ); };
	void push_front( value_type pElmt ) { AggregatListeTempl<T>::get()->push_front( *m_pList, pElmt ); };
	void push_back( value_type pElmt ) { AggregatListeTempl<T>::get()->push_back( *m_pList, pElmt ); };
	void pop_front() { AggregatListeTempl<T>::get()->pop_front( *m_pList ); };
	void pop_back() { AggregatListeTempl<T>::get()->pop_back( *m_pList ); };
	value_type& front() { return AggregatListeTempl<T>::get()->front( *m_pList ); };
	const value_type& front() const { return AggregatListeTempl<T>::get()->front( *m_pList ); };
	value_type& back() { return AggregatListeTempl<T>::get()->back( *m_pList ); };
	const value_type& back() const { return AggregatListeTempl<T>::get()->back( *m_pList ); };
	bool empty() const { return AggregatListeTempl<T>::get()->empty( *m_pList ); };
	size_t size() const { return AggregatListeTempl<T>::get()->size( *m_pList ); };
	void clear() { AggregatListeTempl<T>::get()->clear( *m_pList ); };

	class iterator : public AggregatListe
	{
	private:
		friend class Liste<T>;
		friend class const_iterator;
		typename std::list<T>::iterator* m_pIt;

		explicit iterator(typename std::list<T>::iterator* aufz)
		{
			m_pIt = aufz;
		};

	public:
		iterator() : m_pIt(0) {};
		iterator( const iterator& ipElmt )
		{
			m_pIt = AggregatListeTempl<T>::getI()->assign(ipElmt.m_pIt);
		};
		~iterator() { AggregatListeTempl<T>::getI()->dispose(m_pIt); };
		iterator& operator=( const iterator& ipElmt )
		{
			if (ipElmt.m_pIt != m_pIt)
			{
				AggregatListeTempl<T>::getI()->dispose(m_pIt);
				m_pIt = AggregatListeTempl<T>::getI()->assign(ipElmt.m_pIt);
			}
			return *this;
		};
		iterator& operator++()
		{ 
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			AggregatListeTempl<T>::getI()->preIncrement(m_pIt);
			return *this;
		};
		iterator operator++( int i )
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			iterator tmp = *this;
			AggregatListeTempl<T>::getI()->postIncrement(m_pIt);
			return tmp;
		};
		iterator& operator--()
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			AggregatListeTempl<T>::getI()->preDecrement(m_pIt);
			return *this;
		};
		iterator operator--( int i )
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			iterator tmp = *this;
			AggregatListeTempl<T>::getI()->postDecrement(m_pIt);
			return tmp;
		};
		value_type operator*() const
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			return AggregatListeTempl<T>::getI()->element(*m_pIt);
		};
		value_type* operator->() const
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			return AggregatListeTempl<T>::getI()->element(m_pIt);
		};
		bool operator==( const iterator& ipElmt ) const
		{
			return AggregatListeTempl<T>::getI()->equal(m_pIt, ipElmt.m_pIt);
		};
		bool operator!=( const iterator& ipElmt ) const
		{
			return !AggregatListeTempl<T>::getI()->equal(m_pIt, ipElmt.m_pIt);
		};
	};
	
	class const_iterator : public AggregatListe
	{
	private:
		friend class Liste<T>;
		typename std::list<T>::const_iterator* m_pIt;

		explicit const_iterator(typename std::list<T>::const_iterator* aufz)
		{
			m_pIt = AggregatListeTempl<T>::getCI()->assign(aufz);
			AggregatListeTempl<T>::getCI()->dispose(aufz);
		};
		explicit const_iterator(typename std::list<T>::iterator* aufz)
		{
			m_pIt = AggregatListeTempl<T>::getCI()->assign(aufz);
			AggregatListeTempl<T>::getCI()->dispose(aufz);
		}

	public:
		const_iterator() : m_pIt(0) {};
		const_iterator( const const_iterator& ipElmt )
		{
			m_pIt = AggregatListeTempl<T>::getCI()->assign(ipElmt.m_pIt);
		}
		explicit const_iterator( const iterator& ipElmt )
		{
			m_pIt = AggregatListeTempl<T>::getCI()->assign(ipElmt.m_pIt);
		}
		~const_iterator() { AggregatListeTempl<T>::getCI()->dispose(m_pIt); };
		const_iterator& operator=( const const_iterator& ipElmt )
		{
			if (ipElmt.m_pIt != m_pIt)
			{
				AggregatListeTempl<T>::getCI()->dispose(m_pIt);
				m_pIt = AggregatListeTempl<T>::getCI()->assign(ipElmt.m_pIt);
			}
			return *this;
		};
		const_iterator& operator=( const iterator& ipElmt )
		{
#if !defined(LINUX) && !defined(CYGWIN)
			if (ipElmt.m_pIt != m_pIt)
			{
#endif
				AggregatListeTempl<T>::getCI()->dispose(m_pIt);
				m_pIt = AggregatListeTempl<T>::getCI()->assign(ipElmt.m_pIt);
#if !defined(LINUX) && !defined(CYGWIN)
			}
#endif
			return *this;
		};
		const_iterator& operator++()
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			AggregatListeTempl<T>::getCI()->preIncrement(m_pIt);
			return *this;
		};
		const_iterator operator++( int i )
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			const_iterator tmp = *this;
			AggregatListeTempl<T>::getCI()->postIncrement(m_pIt);
			return tmp;
		};
		const_iterator& operator--()
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			AggregatListeTempl<T>::getCI()->preDecrement(m_pIt);
			return *this;
		};
		const_iterator operator--( int i )
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			const_iterator tmp = *this;
			AggregatListeTempl<T>::getCI()->postDecrement(m_pIt);
			return tmp;
		};
		const value_type operator*() const
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			return (const value_type)AggregatListeTempl<T>::getCI()->element(*m_pIt);
		};
		const value_type* operator->() const
		{
			if (!m_pIt)
				throw AusnahmeBehaelter("AbbruchFehler", "Iterator ist unbelegt.", ObjektFehlt, fehler, (OklabiObjekt*)0);
			return (const value_type*)AggregatListeTempl<T>::getCI()->element(m_pIt);
		};
		bool operator==( const const_iterator& ipElmt ) const
		{
			return AggregatListeTempl<T>::getCI()->equal(m_pIt, ipElmt.m_pIt);
		};
		bool operator==( const iterator& ipElmt ) const
		{
			return AggregatListeTempl<T>::getCI()->equal(m_pIt, ipElmt.m_pIt);
		};
		bool operator!=( const const_iterator& ipElmt ) const
		{
			return !AggregatListeTempl<T>::getCI()->equal(m_pIt, ipElmt.m_pIt);
		};
		bool operator!=( const iterator& ipElmt ) const
		{
			return !AggregatListeTempl<T>::getCI()->equal(m_pIt, ipElmt.m_pIt);
		};
	};
};
}// End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif	// DEFListe
