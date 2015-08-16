#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XOSeqSet
#define DEF_XOSeqSet

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiBucketStore.h"
#include "_XIteratorContainer.h"

namespace Oklabi
{

class _XOSeqSet: public _XIteratorContainer
{
public:
	_XOSeqSet();
	~_XOSeqSet();

	std::pair<iterator,bool> insert( const value_type& pX );
	size_t erase( const value_type& pE );
	iterator erase( iterator& it);

protected:
	_XOSeqSet(const _XOSeqSet&);
	_XOSeqSet(void* pBuckets);
	_XOSeqSet& operator=(const _XOSeqSet&);

	friend class _XOSet;
	friend class _XOSet::iterator;
	friend class _XOSet::const_iterator;

};
}; // End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
