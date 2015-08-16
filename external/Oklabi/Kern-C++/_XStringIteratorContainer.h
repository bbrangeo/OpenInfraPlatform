#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XStringIteratorContainer
#define DEF_XStringIteratorContainer

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiBucketStore.h"
#include "Text.h"
#include "_XString.h"

namespace Oklabi
{

class OKLABI_API _XStringIteratorContainer: public _XContainer
{
public:
	typedef _XString value_type;
	typedef const _XString const_value_type;
	typedef _XString& reference_type;
	typedef const _XString& const_reference_type;

	class iterator;
	class const_iterator;

	class OKLABI_API iterator 
	{
	public:
		iterator();
		iterator( _XStringIteratorContainer*, void*, size_t );
		reference_type operator*() const /*throw (OutOfBounds)*/;
		value_type* operator->() const { return &(operator*()); }
		iterator& operator++();		// ++iterator
		iterator operator++(int);	// iterator++
		bool operator==( const iterator& it2 ) const;
		bool operator!=( const iterator& it2 ) const { return !operator==(it2); };

	protected:
		_XStringIteratorContainer*	m_pItCont;		// Pointer to Container being iterated
		void*						m_pBucket;		// Pointer to current Bucket
		size_t						m_Index;		// Index of Element in current Bucket

	
	private:
		size_t			maxIndex() const;
		bool			atEndOfContainer() const;

		friend class _XStringIteratorContainer;
		friend class _XStringSet;
		friend class _XStringList;
		friend class const_iterator;
	};

	class OKLABI_API const_iterator
	{
	public:
		const_iterator() {}
		const_iterator( const const_iterator& src );
		const_iterator( _XStringIteratorContainer*, void*, size_t );
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
		_XStringIteratorContainer*	m_pItCont;		// Pointer to Container being iterated
		void*						m_pBucket;		// Pointer to current Bucket
		size_t						m_Index;		// Index of Element in current Bucket

	
	private:
		size_t			maxIndex() const;
		bool			atEndOfContainer() const;

		friend class _XStringIteratorContainer;
		friend class _XStringSet;
		friend class _XStringList;
	};

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	iterator find( const value_type& pE );
	const_iterator find( const value_type& pE ) const;
	iterator find( iterator first, iterator last, const value_type& pE );
	iterator find( const _XString::value_type* pE );
	const_iterator find( const _XString::value_type* pE ) const;

	size_t size() const;
	bool empty() const;
	void clear();

protected:
	_XStringIteratorContainer();
	_XStringIteratorContainer( const _XStringIteratorContainer& src );
	~_XStringIteratorContainer();

	static const size_t Next;
#if defined(WIN32) && !defined(CYGWIN)
	typedef
#endif
	enum repType {emptyContainer, singleton, ordinary};
	repType getRepType() const;
	void* getLastBucket() const;

	void* StringToBucketString(const _XString::value_type* str);

	void* m_pBuckets;

	friend class iterator;
	friend class const_iterator;
	friend class _XStringSet;
	friend class _XStringList;
};
};

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
