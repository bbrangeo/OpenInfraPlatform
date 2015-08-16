#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XOList
#define DEF_XOList

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiBucketStore.h"
#include "_XIteratorContainer.h"

namespace Oklabi
{

class OKLABI_API _XOList: public _XIteratorContainer
{
public:

	_XOList();
	~_XOList();

	iterator insertVal( iterator& it, const value_type& pX = value_type());
	iterator insert( iterator& it, const fobjType& pE = fobjType());
	void push_backVal( const value_type& pX );
	void push_back( const fobjType& pE );
	iterator erase( iterator& it);
};
class Datum;
_XOList::iterator findVal(_XOList::iterator first, _XOList::iterator last, const _XOList::value_type& val);
_XOList::iterator find(_XOList::iterator first, _XOList::iterator last, const fobjType& val);
_XOList::iterator find(_XOList::iterator first, _XOList::iterator last, const Datum& val);
_XOList::iterator find(_XOList::iterator first, _XOList::iterator last, const bool& val);
_XOList::const_iterator findVal(_XOList::const_iterator first, _XOList::const_iterator last, const _XOList::value_type& val);
_XOList::const_iterator find(_XOList::const_iterator first, _XOList::const_iterator last, const fobjType& val);
}; // End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
