#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XDoubleIteratorContainer
#define DEF_XDoubleIteratorContainer

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiBucketStore.h"
#include "_XContainer.h"

namespace Oklabi
{

class OKLABI_API _XDoubleIteratorContainer : public _XContainer
{
public:
	typedef double value_type;
	typedef const double const_value_type;
	typedef double& reference_type;
	typedef const double& const_reference_type;

	class iterator;
	class const_iterator;

	_XDoubleIteratorContainer& operator=( const _XDoubleIteratorContainer& );

	class OKLABI_API iterator 
	{

		friend class _XDoubleIteratorContainer;
		friend class _doubleSet;
		friend class _doubleList;
		friend class const_iterator;
	public:
		iterator();
		iterator( _XDoubleIteratorContainer*, void*, size_t );
		reference_type operator*() const /*throw (OutOfBounds)*/;
		value_type* operator->() const { return &(operator*()); }
		iterator& operator++();		// ++iterator
		iterator operator++(int);	// iterator++
		bool operator==( const iterator& it2 ) const;
		bool operator!=( const iterator& it2 ) const { return !operator==(it2); };

	protected:
		_XDoubleIteratorContainer*	m_pItCont;		// Pointer to Container being iterated
		void*						m_pBucket;		// Pointer to current Bucket
		size_t						m_Index;		// Index of Element in current Bucket

	
	private:
		size_t maxIndex() const;
	};

	class OKLABI_API const_iterator
	{
	public:
		const_iterator() {}
		const_iterator( const const_iterator& src );
		const_iterator( _XDoubleIteratorContainer*, void*, size_t );
		explicit const_iterator( const iterator& src );
		const_reference_type operator*() const /*throw (OutOfBounds)*/; // *const_iterator
		const_value_type* operator->() const{ return &(operator*()); }
		const_iterator& operator++();	// ++const_iterator
		const_iterator operator++(int);	// const_iterator++
		const_iterator operator=( const iterator& it );
		bool operator==( const const_iterator& it2 ) const;
		bool operator!=( const const_iterator& it2 ) const { return !operator==(it2); };
		bool operator==( const iterator& it2 ) const;
		bool operator!=( const iterator& it2 ) const { return !operator==(it2); };

	protected:
		_XDoubleIteratorContainer*	m_pItCont;		// Pointer to Container being iterated
		void*						m_pBucket;		// Pointer to current Bucket
		size_t						m_Index;		// Index of Element in current Bucket

	
	private:
		size_t maxIndex() const;

		friend class _XDoubleIteratorContainer;
		friend class _doubleSet;
		friend class _doubleList;
	};

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	iterator find( const value_type& pE );
	iterator find( iterator first, iterator last, const value_type& pE );
	const_iterator find( const value_type& pE ) const;
	iterator find( const value_type* pE );
	const_iterator find( const value_type* pE ) const;

	size_t size() const;
	bool empty() const;
	void clear();

protected:
	_XDoubleIteratorContainer();
	_XDoubleIteratorContainer( const _XDoubleIteratorContainer& src );
	~_XDoubleIteratorContainer();

	iterator insert( iterator& it, const value_type& pE = value_type());
	void push_back( const value_type& pE );
	iterator erase( iterator& it );
	int erase( value_type v );

	static const size_t Next;
#if defined(WIN32) && !defined(CYGWIN)
	typedef
#endif
	enum repType {emptyContainer, ordinary};
	repType getRepType() const;

	void* m_pBuckets;

	friend class iterator;
	friend class const_iterator;
	friend class _doubleSet;
	friend class _doubleList;
};
};

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
