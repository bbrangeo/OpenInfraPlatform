#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XIteratorContainer
#define DEF_XIteratorContainer

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

//===================================================================================
// - empty Container is indicated by m_pBuckets == NULL
// - if there is just one Elment ('singleton'), it is stored direcly in m_pBuckets.
//   To indicate the difference to Buckets, the last Bit is turned on.
//
// - Bucket-Layout
//   - if only one Bucket is used (up to BUCKETSIZE-1 Elements): first Bucketelement
//     contains the size; all others the Elements
//   - otherwise: first Bucket contains size (first Bucket Element), last Bucket 
//     Adress (second Element) and the Next-Pointer (last Bucket Element)
//===================================================================================

#include "OklabiBucketStore.h"
#include "_XContainer.h"
#include "_XOSet.h"

namespace Oklabi
{
class _XOSeqSet;
class _XOList;

class OKLABI_API _XIteratorContainer : public _XContainer
{
public:
	typedef size_t value_type;
	class iterator;
	class const_iterator;

	class OKLABI_API iterator 
	{
	public:
		iterator();
		iterator( _XIteratorContainer*, void*, size_t );
		fobjType operator*() const /*throw (OutOfBounds)*/;
		value_type getValue() const /*throw (OutOfBounds)*/;
		iterator& operator++();		// ++iterator
		iterator operator++(int);	// iterator++
		iterator& operator--();		// --iterator
		iterator operator--(int);	// iterator--
		bool operator==( iterator& it2 ) const;
		bool operator!=( iterator& it2 ) const;
		bool operator==( const iterator& it2 ) const;
		bool operator!=( const iterator& it2 ) const;
		bool operator==( const const_iterator& it2 ) const;
		bool operator!=( const const_iterator& it2 ) const;

	protected:
		_XIteratorContainer*	m_pItCont;		// Pointer to Container being iterated
		void*					m_pBucket;		// Pointer to current Bucket
		size_t					m_Index;		// Index of Element in current Bucket

	
	private:
		size_t			maxIndex() const;
		bool			atEndOfContainer() const;

		friend class _XIteratorContainer;
		friend class const_iterator;
		friend class _XOSeqSet;
		friend class _XOList;
		friend class _XOSet;
		friend class _XOSet::iterator;
		friend class _XOSet::const_iterator;
	};

	class OKLABI_API const_iterator
	{
	public:
		const_iterator();
		const_iterator( const const_iterator& src );
		const_iterator( _XIteratorContainer*, void*, size_t );
		explicit const_iterator( const iterator& src );
		const fobjType operator*() const /*throw (OutOfBounds)*/; // *const_iterator
		const value_type getValue() const /*throw (OutOfBounds)*/; // *const_iterator
		const_iterator& operator++();	// ++const_iterator
		const_iterator operator++(int);	// const_iterator++
		const_iterator& operator--();	// --const_iterator
		const_iterator operator--(int);	// const_iterator--
		const_iterator operator=( const iterator& it );
		bool operator==( const const_iterator& it2 ) const;
		bool operator!=( const const_iterator& it2 ) const;
		bool operator==( const iterator& it2 ) const;
		bool operator!=( const iterator& it2 ) const;

	protected:
		_XIteratorContainer*	m_pItCont;		// Pointer to Container being iterated
		void*					m_pBucket;		// Pointer to current Bucket
		size_t					m_Index;		// Index of Element in current Bucket

	
	private:
		size_t			maxIndex() const;
		bool			atEndOfContainer() const;

		friend class _XIteratorContainer;
		friend class iterator;
		friend class _XOList;
		friend class _XOSet::iterator;
		friend class _XOSet::const_iterator;
	};

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	iterator find( const value_type& pE );
	const_iterator find( const value_type& pE ) const;
	iterator find( iterator first, iterator last, const fobjType& val );
	const_iterator find( const_iterator first, const_iterator last, const fobjType& val ) const;

	size_t size() const;
	bool empty() const;
	void clear();

protected:
	_XIteratorContainer();
	_XIteratorContainer( const _XIteratorContainer& src );

	static const size_t Next;
#if defined(WIN32) && !defined(CYGWIN)
	typedef
#endif
	enum repType {emptyContainer, singleton, ordinary};
	repType getRepType() const;
	void* getLastBucket() const;

	void* m_pBuckets;

	friend class iterator;
	friend class const_iterator;
	friend class _XOSeqSet;
	friend class _XOList;
	friend class _XOSet;
	friend class _XOSet::iterator;
};
};

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
