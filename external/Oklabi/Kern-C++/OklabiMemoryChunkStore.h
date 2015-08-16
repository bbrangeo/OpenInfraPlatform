#include "OklabiPackaging.h"

#ifdef OKLABI_KERN

#ifndef DEFOklabiMemoryChunkStore
#define DEFOklabiMemoryChunkStore

#ifdef OKLABI_PACK
#pragma pack(push,4)
#endif

#include <set>
#if defined(WIN32) || defined(CYGWIN)
#include <windows.h>
#endif
#ifdef GENERIC_LINUX
#include "Services.h"
#if !defined(UINT64)
#define UINT64 unsigned long long
#endif
#endif
#include "OklabiMemoryChunk.h"
#include "OklabiRoot.h"

namespace Oklabi{

class OklabiMemoryChunk;

class OklabiMemoryChunkStore : OklabiRoot
{
	friend class OklabiMemoryChunk;
public:
	static OklabiMemoryChunk* createChunk(size_t minSiz = 0) /*throw( CannotCreate )*/;
	static void releaseChunk( OklabiMemoryChunk* pChunk ) /*throw( NotPresent )*/;
	static void releaseAllChunks();
private:
	static void forgetChunk( OklabiMemoryChunk* pChunk ) /*throw( NotPresent )*/;
private:
	static std::set<OklabiMemoryChunk*> m_setChunks;
	static bool	m_fInPageFile;
	static long m_nExitFlag;
	static void Finalize();
};

class NotPresent
{
public: NotPresent() {};
		~NotPresent() {};
};
};

#ifdef OKLABI_PACK
#pragma pack(pop)
#endif

#endif
#endif
