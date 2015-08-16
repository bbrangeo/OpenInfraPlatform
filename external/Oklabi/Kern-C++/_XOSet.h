/* Change-Log: 
* 
* 
*/ 
#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XOSet
#define DEF_XOSet

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiBucketStore.h"
#include "_XContainer.h"

namespace Oklabi
{

class OKLABI_API _XOSet:_XContainer
{
public:
	typedef size_t value_type;
	class iterator;
	class const_iterator;

	_XOSet();
	_XOSet( const _XOSet& src );
	~_XOSet();
	
	std::pair<iterator,bool> insert( const fobjType& pX );
	size_t erase( const fobjType& pE );
	iterator erase( iterator& it);

	std::pair<iterator,bool> insertVal( const value_type& pX );
	size_t eraseVal( const value_type& pE );

	_XOSet& operator=( const _XOSet& );


	class OKLABI_API iterator 
	{
	public:
		iterator();
		fobjType operator*() const /*throw (OutOfBounds)*/;
		value_type getValue() const /*throw (OutOfBounds)*/;
		iterator& operator++();		// ++iterator
		iterator operator++(int);	// iterator++
		bool operator==( const iterator& it2 ) const;
		bool operator!=( const iterator& it2 ) const;

	protected:
		iterator( _XOSet*, void*, size_t, size_t = 0 );

		_XOSet*         m_pSet;    // Pointer to _XOSet being iterated
		mutable size_t        m_Slot;    // When hashing, this is the Slot of the SeqSet being iterated
		mutable void*         m_pBucket; // Pointer to current Bucket
		mutable size_t        m_Index;   // Index of Element in current Bucket

	private:
		size_t			      maxIndex() const;
		bool			      atEndOfContainer() const;
		const iterator&	      advanceToNextElement() const;

		friend class const_iterator;
		friend class _XOSet;
	};

	class OKLABI_API const_iterator
	{
	public:
		const_iterator();
		const_iterator( const const_iterator& src );
		explicit const_iterator( const iterator& src );
		const fobjType operator*() const /*throw (OutOfBounds)*/; // *const_iterator
		const value_type getValue() const /*throw (OutOfBounds)*/; // *const_iterator
		const_iterator& operator++();	// ++const_iterator
		const_iterator operator++(int);	// const_iterator++
		const_iterator operator=( const iterator& it );
		bool operator==( const const_iterator& it2 ) const;
		bool operator!=( const const_iterator& it2 ) const;
		bool operator==( const iterator& it2 ) const;
		bool operator!=( const iterator& it2 ) const;
	
	protected:
		_XOSet*               m_pSet;    // Pointer to Container being iterated
		mutable size_t        m_Slot;    // When hashing, this is the Slot of the SeqSet being iterated
		mutable void*         m_pBucket; // Pointer to current Bucket
		mutable size_t        m_Index;   // Index of Element in current Bucket

		const_iterator( _XOSet*, void*, size_t, size_t = 0 );

	private:
		size_t                maxIndex() const;
		bool                  atEndOfContainer() const;
		const const_iterator& advanceToNextElement() const;

		friend class _XOList;
		friend class _XOSet;
	};

	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	iterator findVal( const value_type& pE );
	const_iterator findVal( const value_type& pE ) const;
	iterator find( const fobjType& pE );
	const_iterator find( const fobjType& pE ) const;

	size_t size() const;
	bool empty() const;
	void clear();

protected:
	static const size_t Next;
#if defined(WIN32) && !defined(CYGWIN)
	typedef
#endif
	enum repType {emptySet, singleton, sequentially, hashing, none};
	iterator begin(repType typ);
	iterator end(repType typ);

	repType getRepType() const;
	void* getLastBucket(repType typ = none) const;

	void* m_pBucketTable;

private:
	static const size_t hashSize;
	static const size_t slotSize;
	static const size_t offsSize;
	static const size_t offsNoSlots;
	static const size_t offsMinSlot;
	static const size_t offsSlots;

	void clearBucketqueue(void** ppBucketqueue, repType typ = none);
	size_t nextPrime(size_t);
	iterator hash(void* pHashTable, value_type pXO, size_t& slotNo);
	size_t hashVal(void*, value_type) const;
	void* getSeqSet(size_t no) const;

	friend class iterator;
	friend class const_iterator;
};
}; // End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
