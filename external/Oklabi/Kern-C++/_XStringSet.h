#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XStringSet
#define DEF_XStringSet

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

//===================================================================================
// strings are stored as their m_pBuckets-Pointer is stored
// - empty Set is indicated by m_pBuckets == NULL
//
// - Bucket-Layout
//   - if only one Bucket is used (up to BUCKETSIZE-1 Elements): first Bucketelement
//     contains the size; all others the Elements
//   - otherwise: first Bucket contains size (first Bucket Element), last Bucket 
//     Adress (second Element) and the Next-Pointer (last Bucket Element)
//===================================================================================

#include "_XStringIteratorContainer.h"

namespace Oklabi
{

class OKLABI_API _XStringSet: public _XStringIteratorContainer
{
public:
	std::pair<_XStringIteratorContainer::iterator,bool> insert( const _XString::value_type* pX );
	size_t erase( const _XString::value_type* pE );
};
}; // End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
