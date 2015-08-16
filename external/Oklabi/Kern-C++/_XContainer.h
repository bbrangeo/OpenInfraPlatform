#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEF_XContainer
#define DEF_XContainer

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include "OklabiBucketStore.h"

namespace Oklabi
{
class Fachobjekt;
typedef Fachobjekt* fobjType;

class _XContainer
{
protected:
	static const size_t BUCKETSIZE;
	static OklabiBucketStore* pXBS;
};
};

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
