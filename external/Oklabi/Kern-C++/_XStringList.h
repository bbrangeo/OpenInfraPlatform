#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XStringList
#define DEF_XStringList

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "_XStringIteratorContainer.h"

namespace Oklabi
{

class OKLABI_API _XStringList: public _XStringIteratorContainer
{
public:
	void push_back( const _XString::value_type* pE );

	// Insert Element before Position indicated by ElemIt
	iterator insert(iterator ElemIt, const _XString::value_type* pE);

	iterator erase( const iterator& it );
	int erase( const _XString::value_type* pE );

private:
	void push_back( void* pElem );
};
}; // End of namespace Oklabi

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
